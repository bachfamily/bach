
// Generated from pitch.g4 by ANTLR 4.10.1


#include "pitchVisitor.h"

#include "pitchParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct PitchParserStaticData final {
  PitchParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PitchParserStaticData(const PitchParserStaticData&) = delete;
  PitchParserStaticData(PitchParserStaticData&&) = delete;
  PitchParserStaticData& operator=(const PitchParserStaticData&) = delete;
  PitchParserStaticData& operator=(PitchParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag pitchParserOnceFlag;
PitchParserStaticData *pitchParserStaticData = nullptr;

void pitchParserInitialize() {
  assert(pitchParserStaticData == nullptr);
  auto staticData = std::make_unique<PitchParserStaticData>(
    std::vector<std::string>{
      "pch", "dev", "urat"
    },
    std::vector<std::string>{
      "", "'t'", "'/'", "", "", "", "'+'", "'-'"
    },
    std::vector<std::string>{
      "", "", "", "UINT", "NOTENAME", "ACCIDENTAL", "UPLUS", "UMINUS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,7,54,2,0,7,0,2,1,7,1,2,2,7,2,1,0,1,0,3,0,9,8,0,1,0,5,0,12,8,0,10,
  	0,12,0,15,9,0,1,0,1,0,3,0,19,8,0,1,0,1,0,1,1,5,1,24,8,1,10,1,12,1,27,
  	9,1,1,1,1,1,1,1,1,1,5,1,33,8,1,10,1,12,1,36,9,1,1,1,1,1,1,1,1,1,3,1,42,
  	8,1,1,2,1,2,1,2,5,2,47,8,2,10,2,12,2,50,9,2,1,2,1,2,1,2,0,0,3,0,2,4,0,
  	1,1,0,6,7,57,0,6,1,0,0,0,2,41,1,0,0,0,4,43,1,0,0,0,6,8,5,4,0,0,7,9,5,
  	5,0,0,8,7,1,0,0,0,8,9,1,0,0,0,9,13,1,0,0,0,10,12,7,0,0,0,11,10,1,0,0,
  	0,12,15,1,0,0,0,13,11,1,0,0,0,13,14,1,0,0,0,14,16,1,0,0,0,15,13,1,0,0,
  	0,16,18,5,3,0,0,17,19,3,2,1,0,18,17,1,0,0,0,18,19,1,0,0,0,19,20,1,0,0,
  	0,20,21,5,0,0,1,21,1,1,0,0,0,22,24,7,0,0,0,23,22,1,0,0,0,24,27,1,0,0,
  	0,25,23,1,0,0,0,25,26,1,0,0,0,26,28,1,0,0,0,27,25,1,0,0,0,28,29,5,3,0,
  	0,29,30,1,0,0,0,30,42,5,1,0,0,31,33,7,0,0,0,32,31,1,0,0,0,33,36,1,0,0,
  	0,34,32,1,0,0,0,34,35,1,0,0,0,35,37,1,0,0,0,36,34,1,0,0,0,37,38,3,4,2,
  	0,38,39,1,0,0,0,39,40,5,1,0,0,40,42,1,0,0,0,41,25,1,0,0,0,41,34,1,0,0,
  	0,42,3,1,0,0,0,43,44,5,3,0,0,44,48,5,2,0,0,45,47,7,0,0,0,46,45,1,0,0,
  	0,47,50,1,0,0,0,48,46,1,0,0,0,48,49,1,0,0,0,49,51,1,0,0,0,50,48,1,0,0,
  	0,51,52,5,3,0,0,52,5,1,0,0,0,7,8,13,18,25,34,41,48
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  pitchParserStaticData = staticData.release();
}

}

pitchParser::pitchParser(TokenStream *input) : pitchParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

pitchParser::pitchParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  pitchParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *pitchParserStaticData->atn, pitchParserStaticData->decisionToDFA, pitchParserStaticData->sharedContextCache, options);
}

pitchParser::~pitchParser() {
  delete _interpreter;
}

const atn::ATN& pitchParser::getATN() const {
  return *pitchParserStaticData->atn;
}

std::string pitchParser::getGrammarFileName() const {
  return "pitch.g4";
}

const std::vector<std::string>& pitchParser::getRuleNames() const {
  return pitchParserStaticData->ruleNames;
}

const dfa::Vocabulary& pitchParser::getVocabulary() const {
  return pitchParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView pitchParser::getSerializedATN() const {
  return pitchParserStaticData->serializedATN;
}


//----------------- PchContext ------------------------------------------------------------------

pitchParser::PchContext::PchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pitchParser::PchContext::NOTENAME() {
  return getToken(pitchParser::NOTENAME, 0);
}

tree::TerminalNode* pitchParser::PchContext::UINT() {
  return getToken(pitchParser::UINT, 0);
}

tree::TerminalNode* pitchParser::PchContext::EOF() {
  return getToken(pitchParser::EOF, 0);
}

tree::TerminalNode* pitchParser::PchContext::ACCIDENTAL() {
  return getToken(pitchParser::ACCIDENTAL, 0);
}

pitchParser::DevContext* pitchParser::PchContext::dev() {
  return getRuleContext<pitchParser::DevContext>(0);
}

std::vector<tree::TerminalNode *> pitchParser::PchContext::UPLUS() {
  return getTokens(pitchParser::UPLUS);
}

tree::TerminalNode* pitchParser::PchContext::UPLUS(size_t i) {
  return getToken(pitchParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> pitchParser::PchContext::UMINUS() {
  return getTokens(pitchParser::UMINUS);
}

tree::TerminalNode* pitchParser::PchContext::UMINUS(size_t i) {
  return getToken(pitchParser::UMINUS, i);
}


size_t pitchParser::PchContext::getRuleIndex() const {
  return pitchParser::RulePch;
}


std::any pitchParser::PchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pitchVisitor*>(visitor))
    return parserVisitor->visitPch(this);
  else
    return visitor->visitChildren(this);
}

pitchParser::PchContext* pitchParser::pch() {
  PchContext *_localctx = _tracker.createInstance<PchContext>(_ctx, getState());
  enterRule(_localctx, 0, pitchParser::RulePch);
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
    setState(6);
    match(pitchParser::NOTENAME);
    setState(8);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pitchParser::ACCIDENTAL) {
      setState(7);
      match(pitchParser::ACCIDENTAL);
    }
    setState(13);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pitchParser::UPLUS

    || _la == pitchParser::UMINUS) {
      setState(10);
      _la = _input->LA(1);
      if (!(_la == pitchParser::UPLUS

      || _la == pitchParser::UMINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(15);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(16);
    match(pitchParser::UINT);
    setState(18);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << pitchParser::UINT)
      | (1ULL << pitchParser::UPLUS)
      | (1ULL << pitchParser::UMINUS))) != 0)) {
      setState(17);
      dev();
    }
    setState(20);
    match(pitchParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DevContext ------------------------------------------------------------------

pitchParser::DevContext::DevContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t pitchParser::DevContext::getRuleIndex() const {
  return pitchParser::RuleDev;
}

void pitchParser::DevContext::copyFrom(DevContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DevIntContext ------------------------------------------------------------------

tree::TerminalNode* pitchParser::DevIntContext::UINT() {
  return getToken(pitchParser::UINT, 0);
}

std::vector<tree::TerminalNode *> pitchParser::DevIntContext::UPLUS() {
  return getTokens(pitchParser::UPLUS);
}

tree::TerminalNode* pitchParser::DevIntContext::UPLUS(size_t i) {
  return getToken(pitchParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> pitchParser::DevIntContext::UMINUS() {
  return getTokens(pitchParser::UMINUS);
}

tree::TerminalNode* pitchParser::DevIntContext::UMINUS(size_t i) {
  return getToken(pitchParser::UMINUS, i);
}

pitchParser::DevIntContext::DevIntContext(DevContext *ctx) { copyFrom(ctx); }


std::any pitchParser::DevIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pitchVisitor*>(visitor))
    return parserVisitor->visitDevInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DevRatContext ------------------------------------------------------------------

pitchParser::UratContext* pitchParser::DevRatContext::urat() {
  return getRuleContext<pitchParser::UratContext>(0);
}

std::vector<tree::TerminalNode *> pitchParser::DevRatContext::UPLUS() {
  return getTokens(pitchParser::UPLUS);
}

tree::TerminalNode* pitchParser::DevRatContext::UPLUS(size_t i) {
  return getToken(pitchParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> pitchParser::DevRatContext::UMINUS() {
  return getTokens(pitchParser::UMINUS);
}

tree::TerminalNode* pitchParser::DevRatContext::UMINUS(size_t i) {
  return getToken(pitchParser::UMINUS, i);
}

pitchParser::DevRatContext::DevRatContext(DevContext *ctx) { copyFrom(ctx); }


std::any pitchParser::DevRatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pitchVisitor*>(visitor))
    return parserVisitor->visitDevRat(this);
  else
    return visitor->visitChildren(this);
}
pitchParser::DevContext* pitchParser::dev() {
  DevContext *_localctx = _tracker.createInstance<DevContext>(_ctx, getState());
  enterRule(_localctx, 2, pitchParser::RuleDev);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(41);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<pitchParser::DevIntContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(25);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == pitchParser::UPLUS

      || _la == pitchParser::UMINUS) {
        setState(22);
        _la = _input->LA(1);
        if (!(_la == pitchParser::UPLUS

        || _la == pitchParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(27);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(28);
      match(pitchParser::UINT);
      setState(30);
      match(pitchParser::T__0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<pitchParser::DevRatContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(34);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == pitchParser::UPLUS

      || _la == pitchParser::UMINUS) {
        setState(31);
        _la = _input->LA(1);
        if (!(_la == pitchParser::UPLUS

        || _la == pitchParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(36);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(37);
      urat();
      setState(39);
      match(pitchParser::T__0);
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

//----------------- UratContext ------------------------------------------------------------------

pitchParser::UratContext::UratContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> pitchParser::UratContext::UINT() {
  return getTokens(pitchParser::UINT);
}

tree::TerminalNode* pitchParser::UratContext::UINT(size_t i) {
  return getToken(pitchParser::UINT, i);
}

std::vector<tree::TerminalNode *> pitchParser::UratContext::UPLUS() {
  return getTokens(pitchParser::UPLUS);
}

tree::TerminalNode* pitchParser::UratContext::UPLUS(size_t i) {
  return getToken(pitchParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> pitchParser::UratContext::UMINUS() {
  return getTokens(pitchParser::UMINUS);
}

tree::TerminalNode* pitchParser::UratContext::UMINUS(size_t i) {
  return getToken(pitchParser::UMINUS, i);
}


size_t pitchParser::UratContext::getRuleIndex() const {
  return pitchParser::RuleUrat;
}


std::any pitchParser::UratContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pitchVisitor*>(visitor))
    return parserVisitor->visitUrat(this);
  else
    return visitor->visitChildren(this);
}

pitchParser::UratContext* pitchParser::urat() {
  UratContext *_localctx = _tracker.createInstance<UratContext>(_ctx, getState());
  enterRule(_localctx, 4, pitchParser::RuleUrat);
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
    setState(43);
    match(pitchParser::UINT);
    setState(44);
    match(pitchParser::T__1);
    setState(48);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pitchParser::UPLUS

    || _la == pitchParser::UMINUS) {
      setState(45);
      _la = _input->LA(1);
      if (!(_la == pitchParser::UPLUS

      || _la == pitchParser::UMINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(50);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(51);
    match(pitchParser::UINT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void pitchParser::initialize() {
  std::call_once(pitchParserOnceFlag, pitchParserInitialize);
}
