
// Generated from bell.g4 by ANTLR 4.10.1


#include "bellVisitor.h"

#include "bellParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct BellParserStaticData final {
  BellParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  BellParserStaticData(const BellParserStaticData&) = delete;
  BellParserStaticData(BellParserStaticData&&) = delete;
  BellParserStaticData& operator=(const BellParserStaticData&) = delete;
  BellParserStaticData& operator=(BellParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag bellParserOnceFlag;
BellParserStaticData *bellParserStaticData = nullptr;

void bellParserInitialize() {
  assert(bellParserStaticData == nullptr);
  auto staticData = std::make_unique<BellParserStaticData>(
    std::vector<std::string>{
      "program", "sequence", "nullified", "funcall", "item", "var", "lvalueSpecs", 
      "lvalue", "fakeLvalue", "expr", "eexpr", "assignment", "conditional", 
      "listEnd", "list"
    },
    std::vector<std::string>{
      "", "", "'if'", "'then'", "'else'", "'for'", "'do'", "", "", "'['", 
      "']'", "')'", "':'", "'.'", "';'", "'='", "'\\n'", "", "'**'", "'*'", 
      "'//'", "'/'", "", "'+'", "", "'-'"
    },
    std::vector<std::string>{
      "", "NUMBER", "IF", "THEN", "ELSE", "FOR", "DO", "FUNCTION", "VAR", 
      "PUSH", "POP", "CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", "EOL", 
      "WHITESPACE", "POW", "TIMES", "DIVDIV", "DIV", "PLUS", "UPLUS", "MINUS", 
      "UMINUS", "OPEN", "PARAMS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,27,235,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,1,0,1,0,1,0,1,1,1,1,4,1,36,8,1,11,1,12,1,37,1,1,3,1,41,8,1,3,1,43,
  	8,1,1,2,1,2,4,2,47,8,2,11,2,12,2,48,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,66,8,4,1,5,1,5,1,6,1,6,1,6,1,6,3,6,74,8,
  	6,4,6,76,8,6,11,6,12,6,77,1,6,1,6,1,6,1,6,3,6,84,8,6,5,6,86,8,6,10,6,
  	12,6,89,9,6,1,6,1,6,3,6,93,8,6,1,7,1,7,3,7,97,8,7,1,8,1,8,1,8,1,9,1,9,
  	5,9,104,8,9,10,9,12,9,107,9,9,1,9,1,9,5,9,111,8,9,10,9,12,9,114,9,9,1,
  	9,1,9,1,9,5,9,119,8,9,10,9,12,9,122,9,9,1,9,1,9,1,9,5,9,127,8,9,10,9,
  	12,9,130,9,9,1,9,3,9,133,8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,
  	144,8,9,10,9,12,9,147,9,9,1,10,1,10,1,10,1,10,1,10,5,10,154,8,10,10,10,
  	12,10,157,9,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	5,10,170,8,10,10,10,12,10,173,9,10,1,10,1,10,1,10,5,10,178,8,10,10,10,
  	12,10,181,9,10,1,10,3,10,184,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,3,11,194,8,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,3,12,208,8,12,1,13,1,13,3,13,212,8,13,1,14,4,14,215,8,14,11,
  	14,12,14,216,1,14,5,14,220,8,14,10,14,12,14,223,9,14,1,14,1,14,5,14,227,
  	8,14,10,14,12,14,230,9,14,1,14,3,14,233,8,14,1,14,0,1,18,15,0,2,4,6,8,
  	10,12,14,16,18,20,22,24,26,28,0,3,2,0,23,23,25,25,1,0,19,21,2,0,22,22,
  	24,24,258,0,30,1,0,0,0,2,42,1,0,0,0,4,44,1,0,0,0,6,50,1,0,0,0,8,65,1,
  	0,0,0,10,67,1,0,0,0,12,92,1,0,0,0,14,94,1,0,0,0,16,98,1,0,0,0,18,132,
  	1,0,0,0,20,183,1,0,0,0,22,193,1,0,0,0,24,207,1,0,0,0,26,211,1,0,0,0,28,
  	232,1,0,0,0,30,31,3,2,1,0,31,32,5,0,0,1,32,1,1,0,0,0,33,43,3,28,14,0,
  	34,36,3,4,2,0,35,34,1,0,0,0,36,37,1,0,0,0,37,35,1,0,0,0,37,38,1,0,0,0,
  	38,40,1,0,0,0,39,41,3,28,14,0,40,39,1,0,0,0,40,41,1,0,0,0,41,43,1,0,0,
  	0,42,33,1,0,0,0,42,35,1,0,0,0,43,3,1,0,0,0,44,46,3,28,14,0,45,47,5,14,
  	0,0,46,45,1,0,0,0,47,48,1,0,0,0,48,46,1,0,0,0,48,49,1,0,0,0,49,5,1,0,
  	0,0,50,51,5,7,0,0,51,52,5,27,0,0,52,53,3,2,1,0,53,54,5,11,0,0,54,7,1,
  	0,0,0,55,66,5,1,0,0,56,57,5,26,0,0,57,58,3,2,1,0,58,59,5,11,0,0,59,66,
  	1,0,0,0,60,61,5,9,0,0,61,62,3,2,1,0,62,63,5,10,0,0,63,66,1,0,0,0,64,66,
  	3,6,3,0,65,55,1,0,0,0,65,56,1,0,0,0,65,60,1,0,0,0,65,64,1,0,0,0,66,9,
  	1,0,0,0,67,68,5,8,0,0,68,11,1,0,0,0,69,75,6,6,-1,0,70,73,5,12,0,0,71,
  	74,3,8,4,0,72,74,3,10,5,0,73,71,1,0,0,0,73,72,1,0,0,0,74,76,1,0,0,0,75,
  	70,1,0,0,0,76,77,1,0,0,0,77,75,1,0,0,0,77,78,1,0,0,0,78,93,1,0,0,0,79,
  	87,6,6,-1,0,80,83,5,12,0,0,81,84,3,8,4,0,82,84,3,10,5,0,83,81,1,0,0,0,
  	83,82,1,0,0,0,84,86,1,0,0,0,85,80,1,0,0,0,86,89,1,0,0,0,87,85,1,0,0,0,
  	87,88,1,0,0,0,88,90,1,0,0,0,89,87,1,0,0,0,90,91,5,12,0,0,91,93,3,24,12,
  	0,92,69,1,0,0,0,92,79,1,0,0,0,93,13,1,0,0,0,94,96,3,10,5,0,95,97,3,12,
  	6,0,96,95,1,0,0,0,96,97,1,0,0,0,97,15,1,0,0,0,98,99,3,8,4,0,99,100,3,
  	12,6,0,100,17,1,0,0,0,101,105,6,9,-1,0,102,104,7,0,0,0,103,102,1,0,0,
  	0,104,107,1,0,0,0,105,103,1,0,0,0,105,106,1,0,0,0,106,108,1,0,0,0,107,
  	105,1,0,0,0,108,133,3,8,4,0,109,111,7,0,0,0,110,109,1,0,0,0,111,114,1,
  	0,0,0,112,110,1,0,0,0,112,113,1,0,0,0,113,115,1,0,0,0,114,112,1,0,0,0,
  	115,133,3,10,5,0,116,120,4,9,0,0,117,119,7,0,0,0,118,117,1,0,0,0,119,
  	122,1,0,0,0,120,118,1,0,0,0,120,121,1,0,0,0,121,123,1,0,0,0,122,120,1,
  	0,0,0,123,133,3,14,7,0,124,128,4,9,1,0,125,127,7,0,0,0,126,125,1,0,0,
  	0,127,130,1,0,0,0,128,126,1,0,0,0,128,129,1,0,0,0,129,131,1,0,0,0,130,
  	128,1,0,0,0,131,133,3,16,8,0,132,101,1,0,0,0,132,112,1,0,0,0,132,116,
  	1,0,0,0,132,124,1,0,0,0,133,145,1,0,0,0,134,135,10,7,0,0,135,136,5,18,
  	0,0,136,144,3,18,9,8,137,138,10,4,0,0,138,139,7,1,0,0,139,144,3,18,9,
  	5,140,141,10,3,0,0,141,142,7,2,0,0,142,144,3,18,9,4,143,134,1,0,0,0,143,
  	137,1,0,0,0,143,140,1,0,0,0,144,147,1,0,0,0,145,143,1,0,0,0,145,146,1,
  	0,0,0,146,19,1,0,0,0,147,145,1,0,0,0,148,149,3,18,9,0,149,150,5,18,0,
  	0,150,151,3,26,13,0,151,184,1,0,0,0,152,154,7,0,0,0,153,152,1,0,0,0,154,
  	157,1,0,0,0,155,153,1,0,0,0,155,156,1,0,0,0,156,158,1,0,0,0,157,155,1,
  	0,0,0,158,184,3,26,13,0,159,160,3,18,9,0,160,161,7,1,0,0,161,162,3,26,
  	13,0,162,184,1,0,0,0,163,164,3,18,9,0,164,165,7,2,0,0,165,166,3,26,13,
  	0,166,184,1,0,0,0,167,171,4,10,5,0,168,170,7,0,0,0,169,168,1,0,0,0,170,
  	173,1,0,0,0,171,169,1,0,0,0,171,172,1,0,0,0,172,174,1,0,0,0,173,171,1,
  	0,0,0,174,184,3,14,7,0,175,179,4,10,6,0,176,178,7,0,0,0,177,176,1,0,0,
  	0,178,181,1,0,0,0,179,177,1,0,0,0,179,180,1,0,0,0,180,182,1,0,0,0,181,
  	179,1,0,0,0,182,184,3,16,8,0,183,148,1,0,0,0,183,155,1,0,0,0,183,159,
  	1,0,0,0,183,163,1,0,0,0,183,167,1,0,0,0,183,175,1,0,0,0,184,21,1,0,0,
  	0,185,186,3,14,7,0,186,187,5,15,0,0,187,188,3,28,14,0,188,194,1,0,0,0,
  	189,190,3,16,8,0,190,191,5,15,0,0,191,192,3,28,14,0,192,194,1,0,0,0,193,
  	185,1,0,0,0,193,189,1,0,0,0,194,23,1,0,0,0,195,196,5,2,0,0,196,197,3,
  	2,1,0,197,198,5,3,0,0,198,199,3,28,14,0,199,208,1,0,0,0,200,201,5,2,0,
  	0,201,202,3,2,1,0,202,203,5,3,0,0,203,204,3,2,1,0,204,205,5,4,0,0,205,
  	206,3,28,14,0,206,208,1,0,0,0,207,195,1,0,0,0,207,200,1,0,0,0,208,25,
  	1,0,0,0,209,212,3,24,12,0,210,212,3,22,11,0,211,209,1,0,0,0,211,210,1,
  	0,0,0,212,27,1,0,0,0,213,215,3,18,9,0,214,213,1,0,0,0,215,216,1,0,0,0,
  	216,214,1,0,0,0,216,217,1,0,0,0,217,233,1,0,0,0,218,220,3,18,9,0,219,
  	218,1,0,0,0,220,223,1,0,0,0,221,219,1,0,0,0,221,222,1,0,0,0,222,224,1,
  	0,0,0,223,221,1,0,0,0,224,233,3,20,10,0,225,227,3,18,9,0,226,225,1,0,
  	0,0,227,230,1,0,0,0,228,226,1,0,0,0,228,229,1,0,0,0,229,231,1,0,0,0,230,
  	228,1,0,0,0,231,233,3,26,13,0,232,214,1,0,0,0,232,221,1,0,0,0,232,228,
  	1,0,0,0,233,29,1,0,0,0,29,37,40,42,48,65,73,77,83,87,92,96,105,112,120,
  	128,132,143,145,155,171,179,183,193,207,211,216,221,228,232
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  bellParserStaticData = staticData.release();
}

}

bellParser::bellParser(TokenStream *input) : bellParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

bellParser::bellParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  bellParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *bellParserStaticData->atn, bellParserStaticData->decisionToDFA, bellParserStaticData->sharedContextCache, options);
}

bellParser::~bellParser() {
  delete _interpreter;
}

const atn::ATN& bellParser::getATN() const {
  return *bellParserStaticData->atn;
}

std::string bellParser::getGrammarFileName() const {
  return "bell.g4";
}

const std::vector<std::string>& bellParser::getRuleNames() const {
  return bellParserStaticData->ruleNames;
}

const dfa::Vocabulary& bellParser::getVocabulary() const {
  return bellParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView bellParser::getSerializedATN() const {
  return bellParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

bellParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bellParser::SequenceContext* bellParser::ProgramContext::sequence() {
  return getRuleContext<bellParser::SequenceContext>(0);
}

tree::TerminalNode* bellParser::ProgramContext::EOF() {
  return getToken(bellParser::EOF, 0);
}


size_t bellParser::ProgramContext::getRuleIndex() const {
  return bellParser::RuleProgram;
}


std::any bellParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

bellParser::ProgramContext* bellParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, bellParser::RuleProgram);

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
    match(bellParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SequenceContext ------------------------------------------------------------------

bellParser::SequenceContext::SequenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bellParser::ListContext* bellParser::SequenceContext::list() {
  return getRuleContext<bellParser::ListContext>(0);
}

std::vector<bellParser::NullifiedContext *> bellParser::SequenceContext::nullified() {
  return getRuleContexts<bellParser::NullifiedContext>();
}

bellParser::NullifiedContext* bellParser::SequenceContext::nullified(size_t i) {
  return getRuleContext<bellParser::NullifiedContext>(i);
}


size_t bellParser::SequenceContext::getRuleIndex() const {
  return bellParser::RuleSequence;
}


std::any bellParser::SequenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitSequence(this);
  else
    return visitor->visitChildren(this);
}

bellParser::SequenceContext* bellParser::sequence() {
  SequenceContext *_localctx = _tracker.createInstance<SequenceContext>(_ctx, getState());
  enterRule(_localctx, 2, bellParser::RuleSequence);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(42);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(33);
      list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(35); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(34);
                nullified();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(37); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(40);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
      case 1: {
        setState(39);
        list();
        break;
      }

      default:
        break;
      }
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

//----------------- NullifiedContext ------------------------------------------------------------------

bellParser::NullifiedContext::NullifiedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bellParser::ListContext* bellParser::NullifiedContext::list() {
  return getRuleContext<bellParser::ListContext>(0);
}

std::vector<tree::TerminalNode *> bellParser::NullifiedContext::NULLIFY() {
  return getTokens(bellParser::NULLIFY);
}

tree::TerminalNode* bellParser::NullifiedContext::NULLIFY(size_t i) {
  return getToken(bellParser::NULLIFY, i);
}


size_t bellParser::NullifiedContext::getRuleIndex() const {
  return bellParser::RuleNullified;
}


std::any bellParser::NullifiedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitNullified(this);
  else
    return visitor->visitChildren(this);
}

bellParser::NullifiedContext* bellParser::nullified() {
  NullifiedContext *_localctx = _tracker.createInstance<NullifiedContext>(_ctx, getState());
  enterRule(_localctx, 4, bellParser::RuleNullified);

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
    setState(44);
    list();
    setState(46); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(45);
              match(bellParser::NULLIFY);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(48); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncallContext ------------------------------------------------------------------

bellParser::FuncallContext::FuncallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bellParser::FuncallContext::FUNCTION() {
  return getToken(bellParser::FUNCTION, 0);
}

tree::TerminalNode* bellParser::FuncallContext::PARAMS() {
  return getToken(bellParser::PARAMS, 0);
}

bellParser::SequenceContext* bellParser::FuncallContext::sequence() {
  return getRuleContext<bellParser::SequenceContext>(0);
}

tree::TerminalNode* bellParser::FuncallContext::CLOSED() {
  return getToken(bellParser::CLOSED, 0);
}


size_t bellParser::FuncallContext::getRuleIndex() const {
  return bellParser::RuleFuncall;
}


std::any bellParser::FuncallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitFuncall(this);
  else
    return visitor->visitChildren(this);
}

bellParser::FuncallContext* bellParser::funcall() {
  FuncallContext *_localctx = _tracker.createInstance<FuncallContext>(_ctx, getState());
  enterRule(_localctx, 6, bellParser::RuleFuncall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    match(bellParser::FUNCTION);
    setState(51);
    match(bellParser::PARAMS);
    setState(52);
    sequence();
    setState(53);
    match(bellParser::CLOSED);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ItemContext ------------------------------------------------------------------

bellParser::ItemContext::ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bellParser::ItemContext::getRuleIndex() const {
  return bellParser::RuleItem;
}

void bellParser::ItemContext::copyFrom(ItemContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ItemNumberContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemNumberContext::NUMBER() {
  return getToken(bellParser::NUMBER, 0);
}

bellParser::ItemNumberContext::ItemNumberContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemNumber(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ItemSequenceContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemSequenceContext::OPEN() {
  return getToken(bellParser::OPEN, 0);
}

bellParser::SequenceContext* bellParser::ItemSequenceContext::sequence() {
  return getRuleContext<bellParser::SequenceContext>(0);
}

tree::TerminalNode* bellParser::ItemSequenceContext::CLOSED() {
  return getToken(bellParser::CLOSED, 0);
}

bellParser::ItemSequenceContext::ItemSequenceContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemSequenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemSequence(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ItemSublistContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemSublistContext::PUSH() {
  return getToken(bellParser::PUSH, 0);
}

bellParser::SequenceContext* bellParser::ItemSublistContext::sequence() {
  return getRuleContext<bellParser::SequenceContext>(0);
}

tree::TerminalNode* bellParser::ItemSublistContext::POP() {
  return getToken(bellParser::POP, 0);
}

bellParser::ItemSublistContext::ItemSublistContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemSublistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemSublist(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ItemFuncallContext ------------------------------------------------------------------

bellParser::FuncallContext* bellParser::ItemFuncallContext::funcall() {
  return getRuleContext<bellParser::FuncallContext>(0);
}

bellParser::ItemFuncallContext::ItemFuncallContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemFuncallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemFuncall(this);
  else
    return visitor->visitChildren(this);
}
bellParser::ItemContext* bellParser::item() {
  ItemContext *_localctx = _tracker.createInstance<ItemContext>(_ctx, getState());
  enterRule(_localctx, 8, bellParser::RuleItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(65);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::NUMBER: {
        _localctx = _tracker.createInstance<bellParser::ItemNumberContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(55);
        match(bellParser::NUMBER);
        break;
      }

      case bellParser::OPEN: {
        _localctx = _tracker.createInstance<bellParser::ItemSequenceContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(56);
        match(bellParser::OPEN);
        setState(57);
        sequence();
        setState(58);
        match(bellParser::CLOSED);
        break;
      }

      case bellParser::PUSH: {
        _localctx = _tracker.createInstance<bellParser::ItemSublistContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(60);
        match(bellParser::PUSH);
        setState(61);
        sequence();
        setState(62);
        match(bellParser::POP);
        break;
      }

      case bellParser::FUNCTION: {
        _localctx = _tracker.createInstance<bellParser::ItemFuncallContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(64);
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

bellParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bellParser::VarContext::VAR() {
  return getToken(bellParser::VAR, 0);
}


size_t bellParser::VarContext::getRuleIndex() const {
  return bellParser::RuleVar;
}


std::any bellParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

bellParser::VarContext* bellParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 10, bellParser::RuleVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    match(bellParser::VAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LvalueSpecsContext ------------------------------------------------------------------

bellParser::LvalueSpecsContext::LvalueSpecsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> bellParser::LvalueSpecsContext::NTH() {
  return getTokens(bellParser::NTH);
}

tree::TerminalNode* bellParser::LvalueSpecsContext::NTH(size_t i) {
  return getToken(bellParser::NTH, i);
}

std::vector<bellParser::ItemContext *> bellParser::LvalueSpecsContext::item() {
  return getRuleContexts<bellParser::ItemContext>();
}

bellParser::ItemContext* bellParser::LvalueSpecsContext::item(size_t i) {
  return getRuleContext<bellParser::ItemContext>(i);
}

std::vector<bellParser::VarContext *> bellParser::LvalueSpecsContext::var() {
  return getRuleContexts<bellParser::VarContext>();
}

bellParser::VarContext* bellParser::LvalueSpecsContext::var(size_t i) {
  return getRuleContext<bellParser::VarContext>(i);
}

bellParser::ConditionalContext* bellParser::LvalueSpecsContext::conditional() {
  return getRuleContext<bellParser::ConditionalContext>(0);
}


size_t bellParser::LvalueSpecsContext::getRuleIndex() const {
  return bellParser::RuleLvalueSpecs;
}


std::any bellParser::LvalueSpecsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLvalueSpecs(this);
  else
    return visitor->visitChildren(this);
}

bellParser::LvalueSpecsContext* bellParser::lvalueSpecs() {
  LvalueSpecsContext *_localctx = _tracker.createInstance<LvalueSpecsContext>(_ctx, getState());
  enterRule(_localctx, 12, bellParser::RuleLvalueSpecs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(92);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      ending = false;
      setState(75); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(70);
                match(bellParser::NTH);
                setState(73);
                _errHandler->sync(this);
                switch (_input->LA(1)) {
                  case bellParser::NUMBER:
                  case bellParser::FUNCTION:
                  case bellParser::PUSH:
                  case bellParser::OPEN: {
                    setState(71);
                    item();
                    break;
                  }

                  case bellParser::VAR: {
                    setState(72);
                    var();
                    break;
                  }

                default:
                  throw NoViableAltException(this);
                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(77); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      ending = true;
      setState(87);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(80);
          match(bellParser::NTH);
          setState(83);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case bellParser::NUMBER:
            case bellParser::FUNCTION:
            case bellParser::PUSH:
            case bellParser::OPEN: {
              setState(81);
              item();
              break;
            }

            case bellParser::VAR: {
              setState(82);
              var();
              break;
            }

          default:
            throw NoViableAltException(this);
          } 
        }
        setState(89);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      }

      setState(90);
      match(bellParser::NTH);

      setState(91);
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

//----------------- LvalueContext ------------------------------------------------------------------

bellParser::LvalueContext::LvalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bellParser::VarContext* bellParser::LvalueContext::var() {
  return getRuleContext<bellParser::VarContext>(0);
}

bellParser::LvalueSpecsContext* bellParser::LvalueContext::lvalueSpecs() {
  return getRuleContext<bellParser::LvalueSpecsContext>(0);
}


size_t bellParser::LvalueContext::getRuleIndex() const {
  return bellParser::RuleLvalue;
}


std::any bellParser::LvalueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLvalue(this);
  else
    return visitor->visitChildren(this);
}

bellParser::LvalueContext* bellParser::lvalue() {
  LvalueContext *_localctx = _tracker.createInstance<LvalueContext>(_ctx, getState());
  enterRule(_localctx, 14, bellParser::RuleLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    var();
    setState(96);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(95);
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

bellParser::FakeLvalueContext::FakeLvalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bellParser::ItemContext* bellParser::FakeLvalueContext::item() {
  return getRuleContext<bellParser::ItemContext>(0);
}

bellParser::LvalueSpecsContext* bellParser::FakeLvalueContext::lvalueSpecs() {
  return getRuleContext<bellParser::LvalueSpecsContext>(0);
}


size_t bellParser::FakeLvalueContext::getRuleIndex() const {
  return bellParser::RuleFakeLvalue;
}


std::any bellParser::FakeLvalueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitFakeLvalue(this);
  else
    return visitor->visitChildren(this);
}

bellParser::FakeLvalueContext* bellParser::fakeLvalue() {
  FakeLvalueContext *_localctx = _tracker.createInstance<FakeLvalueContext>(_ctx, getState());
  enterRule(_localctx, 16, bellParser::RuleFakeLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);
    item();
    setState(99);
    lvalueSpecs();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

bellParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bellParser::ExprContext::getRuleIndex() const {
  return bellParser::RuleExpr;
}

void bellParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprFakeLvalueContext ------------------------------------------------------------------

bellParser::FakeLvalueContext* bellParser::ExprFakeLvalueContext::fakeLvalue() {
  return getRuleContext<bellParser::FakeLvalueContext>(0);
}

std::vector<tree::TerminalNode *> bellParser::ExprFakeLvalueContext::UPLUS() {
  return getTokens(bellParser::UPLUS);
}

tree::TerminalNode* bellParser::ExprFakeLvalueContext::UPLUS(size_t i) {
  return getToken(bellParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> bellParser::ExprFakeLvalueContext::UMINUS() {
  return getTokens(bellParser::UMINUS);
}

tree::TerminalNode* bellParser::ExprFakeLvalueContext::UMINUS(size_t i) {
  return getToken(bellParser::UMINUS, i);
}

bellParser::ExprFakeLvalueContext::ExprFakeLvalueContext(ExprContext *ctx) { copyFrom(ctx); }


std::any bellParser::ExprFakeLvalueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitExprFakeLvalue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprPlusMinusContext ------------------------------------------------------------------

std::vector<bellParser::ExprContext *> bellParser::ExprPlusMinusContext::expr() {
  return getRuleContexts<bellParser::ExprContext>();
}

bellParser::ExprContext* bellParser::ExprPlusMinusContext::expr(size_t i) {
  return getRuleContext<bellParser::ExprContext>(i);
}

tree::TerminalNode* bellParser::ExprPlusMinusContext::PLUS() {
  return getToken(bellParser::PLUS, 0);
}

tree::TerminalNode* bellParser::ExprPlusMinusContext::MINUS() {
  return getToken(bellParser::MINUS, 0);
}

bellParser::ExprPlusMinusContext::ExprPlusMinusContext(ExprContext *ctx) { copyFrom(ctx); }


std::any bellParser::ExprPlusMinusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitExprPlusMinus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprVarContext ------------------------------------------------------------------

bellParser::VarContext* bellParser::ExprVarContext::var() {
  return getRuleContext<bellParser::VarContext>(0);
}

std::vector<tree::TerminalNode *> bellParser::ExprVarContext::UPLUS() {
  return getTokens(bellParser::UPLUS);
}

tree::TerminalNode* bellParser::ExprVarContext::UPLUS(size_t i) {
  return getToken(bellParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> bellParser::ExprVarContext::UMINUS() {
  return getTokens(bellParser::UMINUS);
}

tree::TerminalNode* bellParser::ExprVarContext::UMINUS(size_t i) {
  return getToken(bellParser::UMINUS, i);
}

bellParser::ExprVarContext::ExprVarContext(ExprContext *ctx) { copyFrom(ctx); }


std::any bellParser::ExprVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitExprVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprPowContext ------------------------------------------------------------------

std::vector<bellParser::ExprContext *> bellParser::ExprPowContext::expr() {
  return getRuleContexts<bellParser::ExprContext>();
}

bellParser::ExprContext* bellParser::ExprPowContext::expr(size_t i) {
  return getRuleContext<bellParser::ExprContext>(i);
}

tree::TerminalNode* bellParser::ExprPowContext::POW() {
  return getToken(bellParser::POW, 0);
}

bellParser::ExprPowContext::ExprPowContext(ExprContext *ctx) { copyFrom(ctx); }


std::any bellParser::ExprPowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitExprPow(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprUnaryContext ------------------------------------------------------------------

bellParser::ItemContext* bellParser::ExprUnaryContext::item() {
  return getRuleContext<bellParser::ItemContext>(0);
}

std::vector<tree::TerminalNode *> bellParser::ExprUnaryContext::UPLUS() {
  return getTokens(bellParser::UPLUS);
}

tree::TerminalNode* bellParser::ExprUnaryContext::UPLUS(size_t i) {
  return getToken(bellParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> bellParser::ExprUnaryContext::UMINUS() {
  return getTokens(bellParser::UMINUS);
}

tree::TerminalNode* bellParser::ExprUnaryContext::UMINUS(size_t i) {
  return getToken(bellParser::UMINUS, i);
}

bellParser::ExprUnaryContext::ExprUnaryContext(ExprContext *ctx) { copyFrom(ctx); }


std::any bellParser::ExprUnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitExprUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprTimesDivContext ------------------------------------------------------------------

std::vector<bellParser::ExprContext *> bellParser::ExprTimesDivContext::expr() {
  return getRuleContexts<bellParser::ExprContext>();
}

bellParser::ExprContext* bellParser::ExprTimesDivContext::expr(size_t i) {
  return getRuleContext<bellParser::ExprContext>(i);
}

tree::TerminalNode* bellParser::ExprTimesDivContext::TIMES() {
  return getToken(bellParser::TIMES, 0);
}

tree::TerminalNode* bellParser::ExprTimesDivContext::DIV() {
  return getToken(bellParser::DIV, 0);
}

tree::TerminalNode* bellParser::ExprTimesDivContext::DIVDIV() {
  return getToken(bellParser::DIVDIV, 0);
}

bellParser::ExprTimesDivContext::ExprTimesDivContext(ExprContext *ctx) { copyFrom(ctx); }


std::any bellParser::ExprTimesDivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitExprTimesDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprLvalueContext ------------------------------------------------------------------

bellParser::LvalueContext* bellParser::ExprLvalueContext::lvalue() {
  return getRuleContext<bellParser::LvalueContext>(0);
}

std::vector<tree::TerminalNode *> bellParser::ExprLvalueContext::UPLUS() {
  return getTokens(bellParser::UPLUS);
}

tree::TerminalNode* bellParser::ExprLvalueContext::UPLUS(size_t i) {
  return getToken(bellParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> bellParser::ExprLvalueContext::UMINUS() {
  return getTokens(bellParser::UMINUS);
}

tree::TerminalNode* bellParser::ExprLvalueContext::UMINUS(size_t i) {
  return getToken(bellParser::UMINUS, i);
}

bellParser::ExprLvalueContext::ExprLvalueContext(ExprContext *ctx) { copyFrom(ctx); }


std::any bellParser::ExprLvalueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitExprLvalue(this);
  else
    return visitor->visitChildren(this);
}

bellParser::ExprContext* bellParser::expr() {
   return expr(0);
}

bellParser::ExprContext* bellParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  bellParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  bellParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, bellParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(132);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprUnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(105);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == bellParser::UPLUS

      || _la == bellParser::UMINUS) {
        setState(102);
        _la = _input->LA(1);
        if (!(_la == bellParser::UPLUS

        || _la == bellParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(107);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(108);
      item();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ExprVarContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(112);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == bellParser::UPLUS

      || _la == bellParser::UMINUS) {
        setState(109);
        _la = _input->LA(1);
        if (!(_la == bellParser::UPLUS

        || _la == bellParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(114);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(115);
      var();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ExprLvalueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(116);

      if (!(!ending)) throw FailedPredicateException(this, "!ending");
      setState(120);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == bellParser::UPLUS

      || _la == bellParser::UMINUS) {
        setState(117);
        _la = _input->LA(1);
        if (!(_la == bellParser::UPLUS

        || _la == bellParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(122);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(123);
      lvalue();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprFakeLvalueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(124);

      if (!(!ending)) throw FailedPredicateException(this, "!ending");
      setState(128);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == bellParser::UPLUS

      || _la == bellParser::UMINUS) {
        setState(125);
        _la = _input->LA(1);
        if (!(_la == bellParser::UPLUS

        || _la == bellParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(130);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(131);
      fakeLvalue();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(145);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(143);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprPowContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(134);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(135);
          match(bellParser::POW);
          setState(136);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprTimesDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(137);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(138);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << bellParser::TIMES)
            | (1ULL << bellParser::DIVDIV)
            | (1ULL << bellParser::DIV))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(139);
          expr(5);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprPlusMinusContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(140);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(141);
          _la = _input->LA(1);
          if (!(_la == bellParser::PLUS

          || _la == bellParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(142);
          expr(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(147);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EexprContext ------------------------------------------------------------------

bellParser::EexprContext::EexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bellParser::EexprContext::getRuleIndex() const {
  return bellParser::RuleEexpr;
}

void bellParser::EexprContext::copyFrom(EexprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- EexprLvalueContext ------------------------------------------------------------------

bellParser::LvalueContext* bellParser::EexprLvalueContext::lvalue() {
  return getRuleContext<bellParser::LvalueContext>(0);
}

std::vector<tree::TerminalNode *> bellParser::EexprLvalueContext::UPLUS() {
  return getTokens(bellParser::UPLUS);
}

tree::TerminalNode* bellParser::EexprLvalueContext::UPLUS(size_t i) {
  return getToken(bellParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> bellParser::EexprLvalueContext::UMINUS() {
  return getTokens(bellParser::UMINUS);
}

tree::TerminalNode* bellParser::EexprLvalueContext::UMINUS(size_t i) {
  return getToken(bellParser::UMINUS, i);
}

bellParser::EexprLvalueContext::EexprLvalueContext(EexprContext *ctx) { copyFrom(ctx); }


std::any bellParser::EexprLvalueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitEexprLvalue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EexprTimesDivContext ------------------------------------------------------------------

bellParser::ExprContext* bellParser::EexprTimesDivContext::expr() {
  return getRuleContext<bellParser::ExprContext>(0);
}

bellParser::ListEndContext* bellParser::EexprTimesDivContext::listEnd() {
  return getRuleContext<bellParser::ListEndContext>(0);
}

tree::TerminalNode* bellParser::EexprTimesDivContext::TIMES() {
  return getToken(bellParser::TIMES, 0);
}

tree::TerminalNode* bellParser::EexprTimesDivContext::DIV() {
  return getToken(bellParser::DIV, 0);
}

tree::TerminalNode* bellParser::EexprTimesDivContext::DIVDIV() {
  return getToken(bellParser::DIVDIV, 0);
}

bellParser::EexprTimesDivContext::EexprTimesDivContext(EexprContext *ctx) { copyFrom(ctx); }


std::any bellParser::EexprTimesDivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitEexprTimesDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EexprFakeLvalueContext ------------------------------------------------------------------

bellParser::FakeLvalueContext* bellParser::EexprFakeLvalueContext::fakeLvalue() {
  return getRuleContext<bellParser::FakeLvalueContext>(0);
}

std::vector<tree::TerminalNode *> bellParser::EexprFakeLvalueContext::UPLUS() {
  return getTokens(bellParser::UPLUS);
}

tree::TerminalNode* bellParser::EexprFakeLvalueContext::UPLUS(size_t i) {
  return getToken(bellParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> bellParser::EexprFakeLvalueContext::UMINUS() {
  return getTokens(bellParser::UMINUS);
}

tree::TerminalNode* bellParser::EexprFakeLvalueContext::UMINUS(size_t i) {
  return getToken(bellParser::UMINUS, i);
}

bellParser::EexprFakeLvalueContext::EexprFakeLvalueContext(EexprContext *ctx) { copyFrom(ctx); }


std::any bellParser::EexprFakeLvalueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitEexprFakeLvalue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EexprPlusMinusContext ------------------------------------------------------------------

bellParser::ExprContext* bellParser::EexprPlusMinusContext::expr() {
  return getRuleContext<bellParser::ExprContext>(0);
}

bellParser::ListEndContext* bellParser::EexprPlusMinusContext::listEnd() {
  return getRuleContext<bellParser::ListEndContext>(0);
}

tree::TerminalNode* bellParser::EexprPlusMinusContext::PLUS() {
  return getToken(bellParser::PLUS, 0);
}

tree::TerminalNode* bellParser::EexprPlusMinusContext::MINUS() {
  return getToken(bellParser::MINUS, 0);
}

bellParser::EexprPlusMinusContext::EexprPlusMinusContext(EexprContext *ctx) { copyFrom(ctx); }


std::any bellParser::EexprPlusMinusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitEexprPlusMinus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EexprPowContext ------------------------------------------------------------------

bellParser::ExprContext* bellParser::EexprPowContext::expr() {
  return getRuleContext<bellParser::ExprContext>(0);
}

tree::TerminalNode* bellParser::EexprPowContext::POW() {
  return getToken(bellParser::POW, 0);
}

bellParser::ListEndContext* bellParser::EexprPowContext::listEnd() {
  return getRuleContext<bellParser::ListEndContext>(0);
}

bellParser::EexprPowContext::EexprPowContext(EexprContext *ctx) { copyFrom(ctx); }


std::any bellParser::EexprPowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitEexprPow(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EexprUnaryContext ------------------------------------------------------------------

bellParser::ListEndContext* bellParser::EexprUnaryContext::listEnd() {
  return getRuleContext<bellParser::ListEndContext>(0);
}

std::vector<tree::TerminalNode *> bellParser::EexprUnaryContext::UPLUS() {
  return getTokens(bellParser::UPLUS);
}

tree::TerminalNode* bellParser::EexprUnaryContext::UPLUS(size_t i) {
  return getToken(bellParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> bellParser::EexprUnaryContext::UMINUS() {
  return getTokens(bellParser::UMINUS);
}

tree::TerminalNode* bellParser::EexprUnaryContext::UMINUS(size_t i) {
  return getToken(bellParser::UMINUS, i);
}

bellParser::EexprUnaryContext::EexprUnaryContext(EexprContext *ctx) { copyFrom(ctx); }


std::any bellParser::EexprUnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitEexprUnary(this);
  else
    return visitor->visitChildren(this);
}
bellParser::EexprContext* bellParser::eexpr() {
  EexprContext *_localctx = _tracker.createInstance<EexprContext>(_ctx, getState());
  enterRule(_localctx, 20, bellParser::RuleEexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(183);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::EexprPowContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(148);
      expr(0);
      setState(149);
      match(bellParser::POW);
      setState(150);
      listEnd();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::EexprUnaryContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(155);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == bellParser::UPLUS

      || _la == bellParser::UMINUS) {
        setState(152);
        _la = _input->LA(1);
        if (!(_la == bellParser::UPLUS

        || _la == bellParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(157);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(158);
      listEnd();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<bellParser::EexprTimesDivContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(159);
      expr(0);
      setState(160);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << bellParser::TIMES)
        | (1ULL << bellParser::DIVDIV)
        | (1ULL << bellParser::DIV))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(161);
      listEnd();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<bellParser::EexprPlusMinusContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(163);
      expr(0);
      setState(164);
      _la = _input->LA(1);
      if (!(_la == bellParser::PLUS

      || _la == bellParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(165);
      listEnd();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<bellParser::EexprLvalueContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(167);

      if (!(ending)) throw FailedPredicateException(this, "ending");
      setState(171);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == bellParser::UPLUS

      || _la == bellParser::UMINUS) {
        setState(168);
        _la = _input->LA(1);
        if (!(_la == bellParser::UPLUS

        || _la == bellParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(173);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(174);
      lvalue();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<bellParser::EexprFakeLvalueContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(175);

      if (!(ending)) throw FailedPredicateException(this, "ending");
      setState(179);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == bellParser::UPLUS

      || _la == bellParser::UMINUS) {
        setState(176);
        _la = _input->LA(1);
        if (!(_la == bellParser::UPLUS

        || _la == bellParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(181);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(182);
      fakeLvalue();
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

//----------------- AssignmentContext ------------------------------------------------------------------

bellParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bellParser::AssignmentContext::getRuleIndex() const {
  return bellParser::RuleAssignment;
}

void bellParser::AssignmentContext::copyFrom(AssignmentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FakeAssignmentContext ------------------------------------------------------------------

bellParser::FakeLvalueContext* bellParser::FakeAssignmentContext::fakeLvalue() {
  return getRuleContext<bellParser::FakeLvalueContext>(0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ASSIGN() {
  return getToken(bellParser::ASSIGN, 0);
}

bellParser::ListContext* bellParser::FakeAssignmentContext::list() {
  return getRuleContext<bellParser::ListContext>(0);
}

bellParser::FakeAssignmentContext::FakeAssignmentContext(AssignmentContext *ctx) { copyFrom(ctx); }


std::any bellParser::FakeAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitFakeAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TrueAssignmentContext ------------------------------------------------------------------

bellParser::LvalueContext* bellParser::TrueAssignmentContext::lvalue() {
  return getRuleContext<bellParser::LvalueContext>(0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ASSIGN() {
  return getToken(bellParser::ASSIGN, 0);
}

bellParser::ListContext* bellParser::TrueAssignmentContext::list() {
  return getRuleContext<bellParser::ListContext>(0);
}

bellParser::TrueAssignmentContext::TrueAssignmentContext(AssignmentContext *ctx) { copyFrom(ctx); }


std::any bellParser::TrueAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitTrueAssignment(this);
  else
    return visitor->visitChildren(this);
}
bellParser::AssignmentContext* bellParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 22, bellParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(193);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::VAR: {
        _localctx = _tracker.createInstance<bellParser::TrueAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(185);
        lvalue();
        setState(186);
        match(bellParser::ASSIGN);
        setState(187);
        list();
        break;
      }

      case bellParser::NUMBER:
      case bellParser::FUNCTION:
      case bellParser::PUSH:
      case bellParser::OPEN: {
        _localctx = _tracker.createInstance<bellParser::FakeAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(189);
        fakeLvalue();
        setState(190);
        match(bellParser::ASSIGN);
        setState(191);
        list();
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

//----------------- ConditionalContext ------------------------------------------------------------------

bellParser::ConditionalContext::ConditionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bellParser::ConditionalContext::getRuleIndex() const {
  return bellParser::RuleConditional;
}

void bellParser::ConditionalContext::copyFrom(ConditionalContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IfthenelseContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::IfthenelseContext::IF() {
  return getToken(bellParser::IF, 0);
}

std::vector<bellParser::SequenceContext *> bellParser::IfthenelseContext::sequence() {
  return getRuleContexts<bellParser::SequenceContext>();
}

bellParser::SequenceContext* bellParser::IfthenelseContext::sequence(size_t i) {
  return getRuleContext<bellParser::SequenceContext>(i);
}

tree::TerminalNode* bellParser::IfthenelseContext::THEN() {
  return getToken(bellParser::THEN, 0);
}

tree::TerminalNode* bellParser::IfthenelseContext::ELSE() {
  return getToken(bellParser::ELSE, 0);
}

bellParser::ListContext* bellParser::IfthenelseContext::list() {
  return getRuleContext<bellParser::ListContext>(0);
}

bellParser::IfthenelseContext::IfthenelseContext(ConditionalContext *ctx) { copyFrom(ctx); }


std::any bellParser::IfthenelseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitIfthenelse(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfthenContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::IfthenContext::IF() {
  return getToken(bellParser::IF, 0);
}

bellParser::SequenceContext* bellParser::IfthenContext::sequence() {
  return getRuleContext<bellParser::SequenceContext>(0);
}

tree::TerminalNode* bellParser::IfthenContext::THEN() {
  return getToken(bellParser::THEN, 0);
}

bellParser::ListContext* bellParser::IfthenContext::list() {
  return getRuleContext<bellParser::ListContext>(0);
}

bellParser::IfthenContext::IfthenContext(ConditionalContext *ctx) { copyFrom(ctx); }


std::any bellParser::IfthenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitIfthen(this);
  else
    return visitor->visitChildren(this);
}
bellParser::ConditionalContext* bellParser::conditional() {
  ConditionalContext *_localctx = _tracker.createInstance<ConditionalContext>(_ctx, getState());
  enterRule(_localctx, 24, bellParser::RuleConditional);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(207);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::IfthenContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(195);
      match(bellParser::IF);
      setState(196);
      sequence();
      setState(197);
      match(bellParser::THEN);
      setState(198);
      list();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::IfthenelseContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(200);
      match(bellParser::IF);
      setState(201);
      sequence();
      setState(202);
      match(bellParser::THEN);
      setState(203);
      sequence();
      setState(204);
      match(bellParser::ELSE);
      setState(205);
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

//----------------- ListEndContext ------------------------------------------------------------------

bellParser::ListEndContext::ListEndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bellParser::ConditionalContext* bellParser::ListEndContext::conditional() {
  return getRuleContext<bellParser::ConditionalContext>(0);
}

bellParser::AssignmentContext* bellParser::ListEndContext::assignment() {
  return getRuleContext<bellParser::AssignmentContext>(0);
}


size_t bellParser::ListEndContext::getRuleIndex() const {
  return bellParser::RuleListEnd;
}


std::any bellParser::ListEndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitListEnd(this);
  else
    return visitor->visitChildren(this);
}

bellParser::ListEndContext* bellParser::listEnd() {
  ListEndContext *_localctx = _tracker.createInstance<ListEndContext>(_ctx, getState());
  enterRule(_localctx, 26, bellParser::RuleListEnd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(211);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(209);
        conditional();
        break;
      }

      case bellParser::NUMBER:
      case bellParser::FUNCTION:
      case bellParser::VAR:
      case bellParser::PUSH:
      case bellParser::OPEN: {
        enterOuterAlt(_localctx, 2);
        setState(210);
        assignment();
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

//----------------- ListContext ------------------------------------------------------------------

bellParser::ListContext::ListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<bellParser::ExprContext *> bellParser::ListContext::expr() {
  return getRuleContexts<bellParser::ExprContext>();
}

bellParser::ExprContext* bellParser::ListContext::expr(size_t i) {
  return getRuleContext<bellParser::ExprContext>(i);
}

bellParser::EexprContext* bellParser::ListContext::eexpr() {
  return getRuleContext<bellParser::EexprContext>(0);
}

bellParser::ListEndContext* bellParser::ListContext::listEnd() {
  return getRuleContext<bellParser::ListEndContext>(0);
}


size_t bellParser::ListContext::getRuleIndex() const {
  return bellParser::RuleList;
}


std::any bellParser::ListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitList(this);
  else
    return visitor->visitChildren(this);
}

bellParser::ListContext* bellParser::list() {
  ListContext *_localctx = _tracker.createInstance<ListContext>(_ctx, getState());
  enterRule(_localctx, 28, bellParser::RuleList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(232);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(214); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(213);
                expr(0);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(216); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(221);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(218);
          expr(0); 
        }
        setState(223);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
      }
      setState(224);
      eexpr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(228);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(225);
          expr(0); 
        }
        setState(230);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
      }
      setState(231);
      listEnd();
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

bool bellParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 9: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 10: return eexprSempred(antlrcpp::downCast<EexprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool bellParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return !ending;
    case 1: return !ending;
    case 2: return precpred(_ctx, 7);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool bellParser::eexprSempred(EexprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return ending;
    case 6: return ending;

  default:
    break;
  }
  return true;
}

void bellParser::initialize() {
  std::call_once(bellParserOnceFlag, bellParserInitialize);
}
