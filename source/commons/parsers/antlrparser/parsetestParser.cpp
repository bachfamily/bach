
// Generated from parsetest.g4 by ANTLR 4.10.1


#include "parsetestVisitor.h"

#include "parsetestParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ParsetestParserStaticData final {
  ParsetestParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ParsetestParserStaticData(const ParsetestParserStaticData&) = delete;
  ParsetestParserStaticData(ParsetestParserStaticData&&) = delete;
  ParsetestParserStaticData& operator=(const ParsetestParserStaticData&) = delete;
  ParsetestParserStaticData& operator=(ParsetestParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag parsetestParserOnceFlag;
ParsetestParserStaticData *parsetestParserStaticData = nullptr;

void parsetestParserInitialize() {
  assert(parsetestParserStaticData == nullptr);
  auto staticData = std::make_unique<ParsetestParserStaticData>(
    std::vector<std::string>{
      "program", "sequence", "item", "var", "lvalueSpecs", "lvalue", "fakeLvalue", 
      "assignment", "reference", "term", "expression", "list", "funcall", 
      "conditional", "nullify"
    },
    std::vector<std::string>{
      "", "", "'if'", "'then'", "'else'", "", "", "')'", "':'", "'*'", "';'", 
      "'='", "'\\n'", "", "", "'+'", "", "'-'"
    },
    std::vector<std::string>{
      "", "NUMBER", "IF", "THEN", "ELSE", "FUNCTION", "VAR", "CLOSED", "NTH", 
      "TIMES", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", "PLUS", "UPLUS", 
      "MINUS", "UMINUS", "OPEN", "PARAMS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,19,176,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,1,0,1,0,1,0,1,1,1,1,3,1,36,8,1,4,1,38,8,1,11,1,12,1,39,1,2,1,2,1,2,
  	1,2,1,2,1,2,3,2,48,8,2,1,3,1,3,1,4,3,4,53,8,4,1,4,1,4,1,4,1,4,3,4,59,
  	8,4,4,4,61,8,4,11,4,12,4,62,1,5,1,5,3,5,67,8,5,1,6,1,6,1,6,1,7,5,7,73,
  	8,7,10,7,12,7,76,9,7,1,7,1,7,3,7,80,8,7,1,7,1,7,1,7,1,8,1,8,3,8,87,8,
  	8,1,9,5,9,90,8,9,10,9,12,9,93,9,9,1,9,1,9,5,9,97,8,9,10,9,12,9,100,9,
  	9,1,9,3,9,103,8,9,1,10,1,10,3,10,107,8,10,1,10,1,10,5,10,111,8,10,10,
  	10,12,10,114,9,10,1,10,3,10,117,8,10,1,10,1,10,3,10,121,8,10,1,11,1,11,
  	4,11,125,8,11,11,11,12,11,126,1,11,1,11,3,11,131,8,11,1,11,1,11,3,11,
  	135,8,11,1,12,5,12,138,8,12,10,12,12,12,141,9,12,1,12,1,12,1,12,1,12,
  	1,12,1,13,5,13,149,8,13,10,13,12,13,152,9,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,5,13,160,8,13,10,13,12,13,163,9,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,3,13,172,8,13,1,14,1,14,1,14,0,0,15,0,2,4,6,8,10,12,14,16,18,20,
  	22,24,26,28,0,2,2,0,15,15,17,17,2,0,14,14,16,16,189,0,30,1,0,0,0,2,37,
  	1,0,0,0,4,47,1,0,0,0,6,49,1,0,0,0,8,60,1,0,0,0,10,64,1,0,0,0,12,68,1,
  	0,0,0,14,74,1,0,0,0,16,86,1,0,0,0,18,102,1,0,0,0,20,104,1,0,0,0,22,134,
  	1,0,0,0,24,139,1,0,0,0,26,171,1,0,0,0,28,173,1,0,0,0,30,31,3,2,1,0,31,
  	32,5,0,0,1,32,1,1,0,0,0,33,35,3,22,11,0,34,36,3,28,14,0,35,34,1,0,0,0,
  	35,36,1,0,0,0,36,38,1,0,0,0,37,33,1,0,0,0,38,39,1,0,0,0,39,37,1,0,0,0,
  	39,40,1,0,0,0,40,3,1,0,0,0,41,48,5,1,0,0,42,43,5,18,0,0,43,44,3,2,1,0,
  	44,45,5,7,0,0,45,48,1,0,0,0,46,48,3,24,12,0,47,41,1,0,0,0,47,42,1,0,0,
  	0,47,46,1,0,0,0,48,5,1,0,0,0,49,50,5,6,0,0,50,7,1,0,0,0,51,53,3,28,14,
  	0,52,51,1,0,0,0,52,53,1,0,0,0,53,54,1,0,0,0,54,58,5,8,0,0,55,59,3,4,2,
  	0,56,59,3,6,3,0,57,59,3,26,13,0,58,55,1,0,0,0,58,56,1,0,0,0,58,57,1,0,
  	0,0,59,61,1,0,0,0,60,52,1,0,0,0,61,62,1,0,0,0,62,60,1,0,0,0,62,63,1,0,
  	0,0,63,9,1,0,0,0,64,66,3,6,3,0,65,67,3,8,4,0,66,65,1,0,0,0,66,67,1,0,
  	0,0,67,11,1,0,0,0,68,69,3,4,2,0,69,70,3,8,4,0,70,13,1,0,0,0,71,73,7,0,
  	0,0,72,71,1,0,0,0,73,76,1,0,0,0,74,72,1,0,0,0,74,75,1,0,0,0,75,79,1,0,
  	0,0,76,74,1,0,0,0,77,80,3,10,5,0,78,80,3,12,6,0,79,77,1,0,0,0,79,78,1,
  	0,0,0,80,81,1,0,0,0,81,82,5,11,0,0,82,83,3,22,11,0,83,15,1,0,0,0,84,87,
  	3,10,5,0,85,87,3,12,6,0,86,84,1,0,0,0,86,85,1,0,0,0,87,17,1,0,0,0,88,
  	90,7,0,0,0,89,88,1,0,0,0,90,93,1,0,0,0,91,89,1,0,0,0,91,92,1,0,0,0,92,
  	94,1,0,0,0,93,91,1,0,0,0,94,103,3,4,2,0,95,97,7,0,0,0,96,95,1,0,0,0,97,
  	100,1,0,0,0,98,96,1,0,0,0,98,99,1,0,0,0,99,101,1,0,0,0,100,98,1,0,0,0,
  	101,103,3,16,8,0,102,91,1,0,0,0,102,98,1,0,0,0,103,19,1,0,0,0,104,112,
  	3,18,9,0,105,107,3,28,14,0,106,105,1,0,0,0,106,107,1,0,0,0,107,108,1,
  	0,0,0,108,109,7,1,0,0,109,111,3,18,9,0,110,106,1,0,0,0,111,114,1,0,0,
  	0,112,110,1,0,0,0,112,113,1,0,0,0,113,120,1,0,0,0,114,112,1,0,0,0,115,
  	117,3,28,14,0,116,115,1,0,0,0,116,117,1,0,0,0,117,118,1,0,0,0,118,119,
  	7,1,0,0,119,121,3,14,7,0,120,116,1,0,0,0,120,121,1,0,0,0,121,21,1,0,0,
  	0,122,125,3,20,10,0,123,125,3,10,5,0,124,122,1,0,0,0,124,123,1,0,0,0,
  	125,126,1,0,0,0,126,124,1,0,0,0,126,127,1,0,0,0,127,130,1,0,0,0,128,131,
  	3,14,7,0,129,131,3,26,13,0,130,128,1,0,0,0,130,129,1,0,0,0,130,131,1,
  	0,0,0,131,135,1,0,0,0,132,135,3,14,7,0,133,135,3,26,13,0,134,124,1,0,
  	0,0,134,132,1,0,0,0,134,133,1,0,0,0,135,23,1,0,0,0,136,138,7,0,0,0,137,
  	136,1,0,0,0,138,141,1,0,0,0,139,137,1,0,0,0,139,140,1,0,0,0,140,142,1,
  	0,0,0,141,139,1,0,0,0,142,143,5,5,0,0,143,144,5,19,0,0,144,145,3,22,11,
  	0,145,146,5,7,0,0,146,25,1,0,0,0,147,149,7,0,0,0,148,147,1,0,0,0,149,
  	152,1,0,0,0,150,148,1,0,0,0,150,151,1,0,0,0,151,153,1,0,0,0,152,150,1,
  	0,0,0,153,154,5,2,0,0,154,155,3,2,1,0,155,156,5,3,0,0,156,157,3,22,11,
  	0,157,172,1,0,0,0,158,160,7,0,0,0,159,158,1,0,0,0,160,163,1,0,0,0,161,
  	159,1,0,0,0,161,162,1,0,0,0,162,164,1,0,0,0,163,161,1,0,0,0,164,165,5,
  	2,0,0,165,166,3,2,1,0,166,167,5,3,0,0,167,168,3,2,1,0,168,169,5,4,0,0,
  	169,170,3,22,11,0,170,172,1,0,0,0,171,150,1,0,0,0,171,161,1,0,0,0,172,
  	27,1,0,0,0,173,174,5,10,0,0,174,29,1,0,0,0,25,35,39,47,52,58,62,66,74,
  	79,86,91,98,102,106,112,116,120,124,126,130,134,139,150,161,171
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  parsetestParserStaticData = staticData.release();
}

}

parsetestParser::parsetestParser(TokenStream *input) : parsetestParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

parsetestParser::parsetestParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  parsetestParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *parsetestParserStaticData->atn, parsetestParserStaticData->decisionToDFA, parsetestParserStaticData->sharedContextCache, options);
}

parsetestParser::~parsetestParser() {
  delete _interpreter;
}

const atn::ATN& parsetestParser::getATN() const {
  return *parsetestParserStaticData->atn;
}

std::string parsetestParser::getGrammarFileName() const {
  return "parsetest.g4";
}

const std::vector<std::string>& parsetestParser::getRuleNames() const {
  return parsetestParserStaticData->ruleNames;
}

const dfa::Vocabulary& parsetestParser::getVocabulary() const {
  return parsetestParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView parsetestParser::getSerializedATN() const {
  return parsetestParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

parsetestParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parsetestParser::SequenceContext* parsetestParser::ProgramContext::sequence() {
  return getRuleContext<parsetestParser::SequenceContext>(0);
}

tree::TerminalNode* parsetestParser::ProgramContext::EOF() {
  return getToken(parsetestParser::EOF, 0);
}


size_t parsetestParser::ProgramContext::getRuleIndex() const {
  return parsetestParser::RuleProgram;
}


std::any parsetestParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

parsetestParser::ProgramContext* parsetestParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, parsetestParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    sequence();
    setState(31);
    match(parsetestParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SequenceContext ------------------------------------------------------------------

parsetestParser::SequenceContext::SequenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<parsetestParser::ListContext *> parsetestParser::SequenceContext::list() {
  return getRuleContexts<parsetestParser::ListContext>();
}

parsetestParser::ListContext* parsetestParser::SequenceContext::list(size_t i) {
  return getRuleContext<parsetestParser::ListContext>(i);
}

std::vector<parsetestParser::NullifyContext *> parsetestParser::SequenceContext::nullify() {
  return getRuleContexts<parsetestParser::NullifyContext>();
}

parsetestParser::NullifyContext* parsetestParser::SequenceContext::nullify(size_t i) {
  return getRuleContext<parsetestParser::NullifyContext>(i);
}


size_t parsetestParser::SequenceContext::getRuleIndex() const {
  return parsetestParser::RuleSequence;
}


std::any parsetestParser::SequenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitSequence(this);
  else
    return visitor->visitChildren(this);
}

parsetestParser::SequenceContext* parsetestParser::sequence() {
  SequenceContext *_localctx = _tracker.createInstance<SequenceContext>(_ctx, getState());
  enterRule(_localctx, 2, parsetestParser::RuleSequence);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(37); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(33);
      list();
      setState(35);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == parsetestParser::NULLIFY) {
        setState(34);
        nullify();
      }
      setState(39); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << parsetestParser::NUMBER)
      | (1ULL << parsetestParser::IF)
      | (1ULL << parsetestParser::FUNCTION)
      | (1ULL << parsetestParser::VAR)
      | (1ULL << parsetestParser::UPLUS)
      | (1ULL << parsetestParser::UMINUS)
      | (1ULL << parsetestParser::OPEN))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ItemContext ------------------------------------------------------------------

parsetestParser::ItemContext::ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t parsetestParser::ItemContext::getRuleIndex() const {
  return parsetestParser::RuleItem;
}

void parsetestParser::ItemContext::copyFrom(ItemContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ItemNumberContext ------------------------------------------------------------------

tree::TerminalNode* parsetestParser::ItemNumberContext::NUMBER() {
  return getToken(parsetestParser::NUMBER, 0);
}

parsetestParser::ItemNumberContext::ItemNumberContext(ItemContext *ctx) { copyFrom(ctx); }


std::any parsetestParser::ItemNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitItemNumber(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ItemSequenceContext ------------------------------------------------------------------

tree::TerminalNode* parsetestParser::ItemSequenceContext::OPEN() {
  return getToken(parsetestParser::OPEN, 0);
}

parsetestParser::SequenceContext* parsetestParser::ItemSequenceContext::sequence() {
  return getRuleContext<parsetestParser::SequenceContext>(0);
}

tree::TerminalNode* parsetestParser::ItemSequenceContext::CLOSED() {
  return getToken(parsetestParser::CLOSED, 0);
}

parsetestParser::ItemSequenceContext::ItemSequenceContext(ItemContext *ctx) { copyFrom(ctx); }


std::any parsetestParser::ItemSequenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitItemSequence(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ItemFuncallContext ------------------------------------------------------------------

parsetestParser::FuncallContext* parsetestParser::ItemFuncallContext::funcall() {
  return getRuleContext<parsetestParser::FuncallContext>(0);
}

parsetestParser::ItemFuncallContext::ItemFuncallContext(ItemContext *ctx) { copyFrom(ctx); }


std::any parsetestParser::ItemFuncallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitItemFuncall(this);
  else
    return visitor->visitChildren(this);
}
parsetestParser::ItemContext* parsetestParser::item() {
  ItemContext *_localctx = _tracker.createInstance<ItemContext>(_ctx, getState());
  enterRule(_localctx, 4, parsetestParser::RuleItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(47);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parsetestParser::NUMBER: {
        _localctx = _tracker.createInstance<parsetestParser::ItemNumberContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(41);
        match(parsetestParser::NUMBER);
        break;
      }

      case parsetestParser::OPEN: {
        _localctx = _tracker.createInstance<parsetestParser::ItemSequenceContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(42);
        match(parsetestParser::OPEN);
        setState(43);
        sequence();
        setState(44);
        match(parsetestParser::CLOSED);
        break;
      }

      case parsetestParser::FUNCTION:
      case parsetestParser::UPLUS:
      case parsetestParser::UMINUS: {
        _localctx = _tracker.createInstance<parsetestParser::ItemFuncallContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(46);
        funcall();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

parsetestParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parsetestParser::VarContext::VAR() {
  return getToken(parsetestParser::VAR, 0);
}


size_t parsetestParser::VarContext::getRuleIndex() const {
  return parsetestParser::RuleVar;
}


std::any parsetestParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

parsetestParser::VarContext* parsetestParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 6, parsetestParser::RuleVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    match(parsetestParser::VAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LvalueSpecsContext ------------------------------------------------------------------

parsetestParser::LvalueSpecsContext::LvalueSpecsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> parsetestParser::LvalueSpecsContext::NTH() {
  return getTokens(parsetestParser::NTH);
}

tree::TerminalNode* parsetestParser::LvalueSpecsContext::NTH(size_t i) {
  return getToken(parsetestParser::NTH, i);
}

std::vector<parsetestParser::ItemContext *> parsetestParser::LvalueSpecsContext::item() {
  return getRuleContexts<parsetestParser::ItemContext>();
}

parsetestParser::ItemContext* parsetestParser::LvalueSpecsContext::item(size_t i) {
  return getRuleContext<parsetestParser::ItemContext>(i);
}

std::vector<parsetestParser::VarContext *> parsetestParser::LvalueSpecsContext::var() {
  return getRuleContexts<parsetestParser::VarContext>();
}

parsetestParser::VarContext* parsetestParser::LvalueSpecsContext::var(size_t i) {
  return getRuleContext<parsetestParser::VarContext>(i);
}

std::vector<parsetestParser::ConditionalContext *> parsetestParser::LvalueSpecsContext::conditional() {
  return getRuleContexts<parsetestParser::ConditionalContext>();
}

parsetestParser::ConditionalContext* parsetestParser::LvalueSpecsContext::conditional(size_t i) {
  return getRuleContext<parsetestParser::ConditionalContext>(i);
}

std::vector<parsetestParser::NullifyContext *> parsetestParser::LvalueSpecsContext::nullify() {
  return getRuleContexts<parsetestParser::NullifyContext>();
}

parsetestParser::NullifyContext* parsetestParser::LvalueSpecsContext::nullify(size_t i) {
  return getRuleContext<parsetestParser::NullifyContext>(i);
}


size_t parsetestParser::LvalueSpecsContext::getRuleIndex() const {
  return parsetestParser::RuleLvalueSpecs;
}


std::any parsetestParser::LvalueSpecsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitLvalueSpecs(this);
  else
    return visitor->visitChildren(this);
}

parsetestParser::LvalueSpecsContext* parsetestParser::lvalueSpecs() {
  LvalueSpecsContext *_localctx = _tracker.createInstance<LvalueSpecsContext>(_ctx, getState());
  enterRule(_localctx, 8, parsetestParser::RuleLvalueSpecs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(60); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(52);
              _errHandler->sync(this);

              _la = _input->LA(1);
              if (_la == parsetestParser::NULLIFY) {
                setState(51);
                nullify();
              }
              setState(54);
              match(parsetestParser::NTH);
              setState(58);
              _errHandler->sync(this);
              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
              case 1: {
                setState(55);
                item();
                break;
              }

              case 2: {
                setState(56);
                var();
                break;
              }

              case 3: {
                setState(57);
                conditional();
                break;
              }

              default:
                break;
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(62); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LvalueContext ------------------------------------------------------------------

parsetestParser::LvalueContext::LvalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parsetestParser::VarContext* parsetestParser::LvalueContext::var() {
  return getRuleContext<parsetestParser::VarContext>(0);
}

parsetestParser::LvalueSpecsContext* parsetestParser::LvalueContext::lvalueSpecs() {
  return getRuleContext<parsetestParser::LvalueSpecsContext>(0);
}


size_t parsetestParser::LvalueContext::getRuleIndex() const {
  return parsetestParser::RuleLvalue;
}


std::any parsetestParser::LvalueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitLvalue(this);
  else
    return visitor->visitChildren(this);
}

parsetestParser::LvalueContext* parsetestParser::lvalue() {
  LvalueContext *_localctx = _tracker.createInstance<LvalueContext>(_ctx, getState());
  enterRule(_localctx, 10, parsetestParser::RuleLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    var();
    setState(66);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(65);
      lvalueSpecs();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FakeLvalueContext ------------------------------------------------------------------

parsetestParser::FakeLvalueContext::FakeLvalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parsetestParser::ItemContext* parsetestParser::FakeLvalueContext::item() {
  return getRuleContext<parsetestParser::ItemContext>(0);
}

parsetestParser::LvalueSpecsContext* parsetestParser::FakeLvalueContext::lvalueSpecs() {
  return getRuleContext<parsetestParser::LvalueSpecsContext>(0);
}


size_t parsetestParser::FakeLvalueContext::getRuleIndex() const {
  return parsetestParser::RuleFakeLvalue;
}


std::any parsetestParser::FakeLvalueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitFakeLvalue(this);
  else
    return visitor->visitChildren(this);
}

parsetestParser::FakeLvalueContext* parsetestParser::fakeLvalue() {
  FakeLvalueContext *_localctx = _tracker.createInstance<FakeLvalueContext>(_ctx, getState());
  enterRule(_localctx, 12, parsetestParser::RuleFakeLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    item();
    setState(69);
    lvalueSpecs();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

parsetestParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parsetestParser::AssignmentContext::ASSIGN() {
  return getToken(parsetestParser::ASSIGN, 0);
}

parsetestParser::ListContext* parsetestParser::AssignmentContext::list() {
  return getRuleContext<parsetestParser::ListContext>(0);
}

parsetestParser::LvalueContext* parsetestParser::AssignmentContext::lvalue() {
  return getRuleContext<parsetestParser::LvalueContext>(0);
}

parsetestParser::FakeLvalueContext* parsetestParser::AssignmentContext::fakeLvalue() {
  return getRuleContext<parsetestParser::FakeLvalueContext>(0);
}

std::vector<tree::TerminalNode *> parsetestParser::AssignmentContext::UPLUS() {
  return getTokens(parsetestParser::UPLUS);
}

tree::TerminalNode* parsetestParser::AssignmentContext::UPLUS(size_t i) {
  return getToken(parsetestParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> parsetestParser::AssignmentContext::UMINUS() {
  return getTokens(parsetestParser::UMINUS);
}

tree::TerminalNode* parsetestParser::AssignmentContext::UMINUS(size_t i) {
  return getToken(parsetestParser::UMINUS, i);
}


size_t parsetestParser::AssignmentContext::getRuleIndex() const {
  return parsetestParser::RuleAssignment;
}


std::any parsetestParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

parsetestParser::AssignmentContext* parsetestParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 14, parsetestParser::RuleAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(74);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(71);
        _la = _input->LA(1);
        if (!(_la == parsetestParser::UPLUS

        || _la == parsetestParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        } 
      }
      setState(76);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
    setState(79);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parsetestParser::VAR: {
        setState(77);
        lvalue();
        break;
      }

      case parsetestParser::NUMBER:
      case parsetestParser::FUNCTION:
      case parsetestParser::UPLUS:
      case parsetestParser::UMINUS:
      case parsetestParser::OPEN: {
        setState(78);
        fakeLvalue();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(81);
    match(parsetestParser::ASSIGN);
    setState(82);
    list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReferenceContext ------------------------------------------------------------------

parsetestParser::ReferenceContext::ReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parsetestParser::LvalueContext* parsetestParser::ReferenceContext::lvalue() {
  return getRuleContext<parsetestParser::LvalueContext>(0);
}

parsetestParser::FakeLvalueContext* parsetestParser::ReferenceContext::fakeLvalue() {
  return getRuleContext<parsetestParser::FakeLvalueContext>(0);
}


size_t parsetestParser::ReferenceContext::getRuleIndex() const {
  return parsetestParser::RuleReference;
}


std::any parsetestParser::ReferenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitReference(this);
  else
    return visitor->visitChildren(this);
}

parsetestParser::ReferenceContext* parsetestParser::reference() {
  ReferenceContext *_localctx = _tracker.createInstance<ReferenceContext>(_ctx, getState());
  enterRule(_localctx, 16, parsetestParser::RuleReference);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(86);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parsetestParser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(84);
        lvalue();
        break;
      }

      case parsetestParser::NUMBER:
      case parsetestParser::FUNCTION:
      case parsetestParser::UPLUS:
      case parsetestParser::UMINUS:
      case parsetestParser::OPEN: {
        enterOuterAlt(_localctx, 2);
        setState(85);
        fakeLvalue();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

parsetestParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t parsetestParser::TermContext::getRuleIndex() const {
  return parsetestParser::RuleTerm;
}

void parsetestParser::TermContext::copyFrom(TermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ItemTermContext ------------------------------------------------------------------

parsetestParser::ItemContext* parsetestParser::ItemTermContext::item() {
  return getRuleContext<parsetestParser::ItemContext>(0);
}

std::vector<tree::TerminalNode *> parsetestParser::ItemTermContext::UPLUS() {
  return getTokens(parsetestParser::UPLUS);
}

tree::TerminalNode* parsetestParser::ItemTermContext::UPLUS(size_t i) {
  return getToken(parsetestParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> parsetestParser::ItemTermContext::UMINUS() {
  return getTokens(parsetestParser::UMINUS);
}

tree::TerminalNode* parsetestParser::ItemTermContext::UMINUS(size_t i) {
  return getToken(parsetestParser::UMINUS, i);
}

parsetestParser::ItemTermContext::ItemTermContext(TermContext *ctx) { copyFrom(ctx); }


std::any parsetestParser::ItemTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitItemTerm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReferenceTermContext ------------------------------------------------------------------

parsetestParser::ReferenceContext* parsetestParser::ReferenceTermContext::reference() {
  return getRuleContext<parsetestParser::ReferenceContext>(0);
}

std::vector<tree::TerminalNode *> parsetestParser::ReferenceTermContext::UPLUS() {
  return getTokens(parsetestParser::UPLUS);
}

tree::TerminalNode* parsetestParser::ReferenceTermContext::UPLUS(size_t i) {
  return getToken(parsetestParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> parsetestParser::ReferenceTermContext::UMINUS() {
  return getTokens(parsetestParser::UMINUS);
}

tree::TerminalNode* parsetestParser::ReferenceTermContext::UMINUS(size_t i) {
  return getToken(parsetestParser::UMINUS, i);
}

parsetestParser::ReferenceTermContext::ReferenceTermContext(TermContext *ctx) { copyFrom(ctx); }


std::any parsetestParser::ReferenceTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitReferenceTerm(this);
  else
    return visitor->visitChildren(this);
}
parsetestParser::TermContext* parsetestParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 18, parsetestParser::RuleTerm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(102);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<parsetestParser::ItemTermContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(91);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(88);
          _la = _input->LA(1);
          if (!(_la == parsetestParser::UPLUS

          || _la == parsetestParser::UMINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          } 
        }
        setState(93);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      }
      setState(94);
      item();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<parsetestParser::ReferenceTermContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(98);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(95);
          _la = _input->LA(1);
          if (!(_la == parsetestParser::UPLUS

          || _la == parsetestParser::UMINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          } 
        }
        setState(100);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
      }
      setState(101);
      reference();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

parsetestParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<parsetestParser::TermContext *> parsetestParser::ExpressionContext::term() {
  return getRuleContexts<parsetestParser::TermContext>();
}

parsetestParser::TermContext* parsetestParser::ExpressionContext::term(size_t i) {
  return getRuleContext<parsetestParser::TermContext>(i);
}

parsetestParser::AssignmentContext* parsetestParser::ExpressionContext::assignment() {
  return getRuleContext<parsetestParser::AssignmentContext>(0);
}

std::vector<tree::TerminalNode *> parsetestParser::ExpressionContext::PLUS() {
  return getTokens(parsetestParser::PLUS);
}

tree::TerminalNode* parsetestParser::ExpressionContext::PLUS(size_t i) {
  return getToken(parsetestParser::PLUS, i);
}

std::vector<tree::TerminalNode *> parsetestParser::ExpressionContext::MINUS() {
  return getTokens(parsetestParser::MINUS);
}

tree::TerminalNode* parsetestParser::ExpressionContext::MINUS(size_t i) {
  return getToken(parsetestParser::MINUS, i);
}

std::vector<parsetestParser::NullifyContext *> parsetestParser::ExpressionContext::nullify() {
  return getRuleContexts<parsetestParser::NullifyContext>();
}

parsetestParser::NullifyContext* parsetestParser::ExpressionContext::nullify(size_t i) {
  return getRuleContext<parsetestParser::NullifyContext>(i);
}


size_t parsetestParser::ExpressionContext::getRuleIndex() const {
  return parsetestParser::RuleExpression;
}


std::any parsetestParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

parsetestParser::ExpressionContext* parsetestParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 20, parsetestParser::RuleExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(104);
    term();
    setState(112);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(106);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == parsetestParser::NULLIFY) {
          setState(105);
          nullify();
        }
        setState(108);
        _la = _input->LA(1);
        if (!(_la == parsetestParser::PLUS

        || _la == parsetestParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(109);
        term(); 
      }
      setState(114);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
    setState(120);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(116);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == parsetestParser::NULLIFY) {
        setState(115);
        nullify();
      }
      setState(118);
      _la = _input->LA(1);
      if (!(_la == parsetestParser::PLUS

      || _la == parsetestParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(119);
      assignment();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListContext ------------------------------------------------------------------

parsetestParser::ListContext::ListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t parsetestParser::ListContext::getRuleIndex() const {
  return parsetestParser::RuleList;
}

void parsetestParser::ListContext::copyFrom(ListContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ListOnlyConditionalContext ------------------------------------------------------------------

parsetestParser::ConditionalContext* parsetestParser::ListOnlyConditionalContext::conditional() {
  return getRuleContext<parsetestParser::ConditionalContext>(0);
}

parsetestParser::ListOnlyConditionalContext::ListOnlyConditionalContext(ListContext *ctx) { copyFrom(ctx); }


std::any parsetestParser::ListOnlyConditionalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitListOnlyConditional(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListOnlyAssignmentContext ------------------------------------------------------------------

parsetestParser::AssignmentContext* parsetestParser::ListOnlyAssignmentContext::assignment() {
  return getRuleContext<parsetestParser::AssignmentContext>(0);
}

parsetestParser::ListOnlyAssignmentContext::ListOnlyAssignmentContext(ListContext *ctx) { copyFrom(ctx); }


std::any parsetestParser::ListOnlyAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitListOnlyAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListOtherContext ------------------------------------------------------------------

std::vector<parsetestParser::ExpressionContext *> parsetestParser::ListOtherContext::expression() {
  return getRuleContexts<parsetestParser::ExpressionContext>();
}

parsetestParser::ExpressionContext* parsetestParser::ListOtherContext::expression(size_t i) {
  return getRuleContext<parsetestParser::ExpressionContext>(i);
}

std::vector<parsetestParser::LvalueContext *> parsetestParser::ListOtherContext::lvalue() {
  return getRuleContexts<parsetestParser::LvalueContext>();
}

parsetestParser::LvalueContext* parsetestParser::ListOtherContext::lvalue(size_t i) {
  return getRuleContext<parsetestParser::LvalueContext>(i);
}

parsetestParser::AssignmentContext* parsetestParser::ListOtherContext::assignment() {
  return getRuleContext<parsetestParser::AssignmentContext>(0);
}

parsetestParser::ConditionalContext* parsetestParser::ListOtherContext::conditional() {
  return getRuleContext<parsetestParser::ConditionalContext>(0);
}

parsetestParser::ListOtherContext::ListOtherContext(ListContext *ctx) { copyFrom(ctx); }


std::any parsetestParser::ListOtherContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitListOther(this);
  else
    return visitor->visitChildren(this);
}
parsetestParser::ListContext* parsetestParser::list() {
  ListContext *_localctx = _tracker.createInstance<ListContext>(_ctx, getState());
  enterRule(_localctx, 22, parsetestParser::RuleList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(134);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<parsetestParser::ListOtherContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(124); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(124);
                _errHandler->sync(this);
                switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
                case 1: {
                  setState(122);
                  expression();
                  break;
                }

                case 2: {
                  setState(123);
                  lvalue();
                  break;
                }

                default:
                  break;
                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(126); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(130);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
      case 1: {
        setState(128);
        assignment();
        break;
      }

      case 2: {
        setState(129);
        conditional();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<parsetestParser::ListOnlyAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(132);
      assignment();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<parsetestParser::ListOnlyConditionalContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(133);
      conditional();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncallContext ------------------------------------------------------------------

parsetestParser::FuncallContext::FuncallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parsetestParser::FuncallContext::FUNCTION() {
  return getToken(parsetestParser::FUNCTION, 0);
}

tree::TerminalNode* parsetestParser::FuncallContext::PARAMS() {
  return getToken(parsetestParser::PARAMS, 0);
}

parsetestParser::ListContext* parsetestParser::FuncallContext::list() {
  return getRuleContext<parsetestParser::ListContext>(0);
}

tree::TerminalNode* parsetestParser::FuncallContext::CLOSED() {
  return getToken(parsetestParser::CLOSED, 0);
}

std::vector<tree::TerminalNode *> parsetestParser::FuncallContext::UPLUS() {
  return getTokens(parsetestParser::UPLUS);
}

tree::TerminalNode* parsetestParser::FuncallContext::UPLUS(size_t i) {
  return getToken(parsetestParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> parsetestParser::FuncallContext::UMINUS() {
  return getTokens(parsetestParser::UMINUS);
}

tree::TerminalNode* parsetestParser::FuncallContext::UMINUS(size_t i) {
  return getToken(parsetestParser::UMINUS, i);
}


size_t parsetestParser::FuncallContext::getRuleIndex() const {
  return parsetestParser::RuleFuncall;
}


std::any parsetestParser::FuncallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitFuncall(this);
  else
    return visitor->visitChildren(this);
}

parsetestParser::FuncallContext* parsetestParser::funcall() {
  FuncallContext *_localctx = _tracker.createInstance<FuncallContext>(_ctx, getState());
  enterRule(_localctx, 24, parsetestParser::RuleFuncall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == parsetestParser::UPLUS

    || _la == parsetestParser::UMINUS) {
      setState(136);
      _la = _input->LA(1);
      if (!(_la == parsetestParser::UPLUS

      || _la == parsetestParser::UMINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(141);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(142);
    match(parsetestParser::FUNCTION);
    setState(143);
    match(parsetestParser::PARAMS);
    setState(144);
    list();
    setState(145);
    match(parsetestParser::CLOSED);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalContext ------------------------------------------------------------------

parsetestParser::ConditionalContext::ConditionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t parsetestParser::ConditionalContext::getRuleIndex() const {
  return parsetestParser::RuleConditional;
}

void parsetestParser::ConditionalContext::copyFrom(ConditionalContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IfthenelseContext ------------------------------------------------------------------

tree::TerminalNode* parsetestParser::IfthenelseContext::IF() {
  return getToken(parsetestParser::IF, 0);
}

std::vector<parsetestParser::SequenceContext *> parsetestParser::IfthenelseContext::sequence() {
  return getRuleContexts<parsetestParser::SequenceContext>();
}

parsetestParser::SequenceContext* parsetestParser::IfthenelseContext::sequence(size_t i) {
  return getRuleContext<parsetestParser::SequenceContext>(i);
}

tree::TerminalNode* parsetestParser::IfthenelseContext::THEN() {
  return getToken(parsetestParser::THEN, 0);
}

tree::TerminalNode* parsetestParser::IfthenelseContext::ELSE() {
  return getToken(parsetestParser::ELSE, 0);
}

parsetestParser::ListContext* parsetestParser::IfthenelseContext::list() {
  return getRuleContext<parsetestParser::ListContext>(0);
}

std::vector<tree::TerminalNode *> parsetestParser::IfthenelseContext::UPLUS() {
  return getTokens(parsetestParser::UPLUS);
}

tree::TerminalNode* parsetestParser::IfthenelseContext::UPLUS(size_t i) {
  return getToken(parsetestParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> parsetestParser::IfthenelseContext::UMINUS() {
  return getTokens(parsetestParser::UMINUS);
}

tree::TerminalNode* parsetestParser::IfthenelseContext::UMINUS(size_t i) {
  return getToken(parsetestParser::UMINUS, i);
}

parsetestParser::IfthenelseContext::IfthenelseContext(ConditionalContext *ctx) { copyFrom(ctx); }


std::any parsetestParser::IfthenelseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitIfthenelse(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfthenContext ------------------------------------------------------------------

tree::TerminalNode* parsetestParser::IfthenContext::IF() {
  return getToken(parsetestParser::IF, 0);
}

parsetestParser::SequenceContext* parsetestParser::IfthenContext::sequence() {
  return getRuleContext<parsetestParser::SequenceContext>(0);
}

tree::TerminalNode* parsetestParser::IfthenContext::THEN() {
  return getToken(parsetestParser::THEN, 0);
}

parsetestParser::ListContext* parsetestParser::IfthenContext::list() {
  return getRuleContext<parsetestParser::ListContext>(0);
}

std::vector<tree::TerminalNode *> parsetestParser::IfthenContext::UPLUS() {
  return getTokens(parsetestParser::UPLUS);
}

tree::TerminalNode* parsetestParser::IfthenContext::UPLUS(size_t i) {
  return getToken(parsetestParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> parsetestParser::IfthenContext::UMINUS() {
  return getTokens(parsetestParser::UMINUS);
}

tree::TerminalNode* parsetestParser::IfthenContext::UMINUS(size_t i) {
  return getToken(parsetestParser::UMINUS, i);
}

parsetestParser::IfthenContext::IfthenContext(ConditionalContext *ctx) { copyFrom(ctx); }


std::any parsetestParser::IfthenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitIfthen(this);
  else
    return visitor->visitChildren(this);
}
parsetestParser::ConditionalContext* parsetestParser::conditional() {
  ConditionalContext *_localctx = _tracker.createInstance<ConditionalContext>(_ctx, getState());
  enterRule(_localctx, 26, parsetestParser::RuleConditional);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(171);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<parsetestParser::IfthenContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(150);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == parsetestParser::UPLUS

      || _la == parsetestParser::UMINUS) {
        setState(147);
        _la = _input->LA(1);
        if (!(_la == parsetestParser::UPLUS

        || _la == parsetestParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(152);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(153);
      match(parsetestParser::IF);
      setState(154);
      sequence();
      setState(155);
      match(parsetestParser::THEN);
      setState(156);
      list();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<parsetestParser::IfthenelseContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(161);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == parsetestParser::UPLUS

      || _la == parsetestParser::UMINUS) {
        setState(158);
        _la = _input->LA(1);
        if (!(_la == parsetestParser::UPLUS

        || _la == parsetestParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(163);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(164);
      match(parsetestParser::IF);
      setState(165);
      sequence();
      setState(166);
      match(parsetestParser::THEN);
      setState(167);
      sequence();
      setState(168);
      match(parsetestParser::ELSE);
      setState(169);
      list();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NullifyContext ------------------------------------------------------------------

parsetestParser::NullifyContext::NullifyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parsetestParser::NullifyContext::NULLIFY() {
  return getToken(parsetestParser::NULLIFY, 0);
}


size_t parsetestParser::NullifyContext::getRuleIndex() const {
  return parsetestParser::RuleNullify;
}


std::any parsetestParser::NullifyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parsetestVisitor*>(visitor))
    return parserVisitor->visitNullify(this);
  else
    return visitor->visitChildren(this);
}

parsetestParser::NullifyContext* parsetestParser::nullify() {
  NullifyContext *_localctx = _tracker.createInstance<NullifyContext>(_ctx, getState());
  enterRule(_localctx, 28, parsetestParser::RuleNullify);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    match(parsetestParser::NULLIFY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void parsetestParser::initialize() {
  std::call_once(parsetestParserOnceFlag, parsetestParserInitialize);
}
