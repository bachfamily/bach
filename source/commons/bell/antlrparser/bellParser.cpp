
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
      "everything", "program", "sequence", "nullified", "funcall", "item", 
      "var", "lvalueSpecs", "lvalue", "fakeLvalue", "expr", "eexpr", "assignment", 
      "conditional", "listEnd", "list"
    },
    std::vector<std::string>{
      "", "", "", "", "'if'", "'then'", "'else'", "'for'", "'do'", "", "", 
      "", "", "", "", "'['", "']'", "')'", "':'", "'.'", "';'", "'='", "", 
      "", "'**'", "'*'", "'//'", "'/'", "", "'+'", "", "'-'"
    },
    std::vector<std::string>{
      "", "UINT", "UFLOAT", "UPITCH", "IF", "THEN", "ELSE", "FOR", "DO", 
      "FUNCTION", "INLET", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "NAMEDPARAM", 
      "PUSH", "POP", "CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", "WHITESPACE", 
      "NEWATOM", "POW", "TIMES", "DIVDIV", "DIV", "PLUS", "UPLUS", "MINUS", 
      "UMINUS", "OPEN", "PARAMS", "ANYTHING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,34,252,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,43,8,1,1,2,1,
  	2,4,2,47,8,2,11,2,12,2,48,1,2,3,2,52,8,2,3,2,54,8,2,1,3,1,3,4,3,58,8,
  	3,11,3,12,3,59,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,3,5,80,8,5,1,6,1,6,1,6,3,6,85,8,6,1,7,1,7,1,7,1,7,3,
  	7,91,8,7,4,7,93,8,7,11,7,12,7,94,1,7,1,7,1,7,1,7,3,7,101,8,7,5,7,103,
  	8,7,10,7,12,7,106,9,7,1,7,1,7,3,7,110,8,7,1,8,1,8,3,8,114,8,8,1,9,1,9,
  	1,9,1,10,1,10,5,10,121,8,10,10,10,12,10,124,9,10,1,10,1,10,5,10,128,8,
  	10,10,10,12,10,131,9,10,1,10,1,10,1,10,5,10,136,8,10,10,10,12,10,139,
  	9,10,1,10,1,10,1,10,5,10,144,8,10,10,10,12,10,147,9,10,1,10,3,10,150,
  	8,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,5,10,161,8,10,10,10,
  	12,10,164,9,10,1,11,1,11,1,11,1,11,1,11,5,11,171,8,11,10,11,12,11,174,
  	9,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,187,
  	8,11,10,11,12,11,190,9,11,1,11,1,11,1,11,5,11,195,8,11,10,11,12,11,198,
  	9,11,1,11,3,11,201,8,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,
  	211,8,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	3,13,225,8,13,1,14,1,14,3,14,229,8,14,1,15,4,15,232,8,15,11,15,12,15,
  	233,1,15,5,15,237,8,15,10,15,12,15,240,9,15,1,15,1,15,5,15,244,8,15,10,
  	15,12,15,247,9,15,1,15,3,15,250,8,15,1,15,0,1,20,16,0,2,4,6,8,10,12,14,
  	16,18,20,22,24,26,28,30,0,3,2,0,29,29,31,31,1,0,25,27,2,0,28,28,30,30,
  	282,0,32,1,0,0,0,2,42,1,0,0,0,4,53,1,0,0,0,6,55,1,0,0,0,8,61,1,0,0,0,
  	10,79,1,0,0,0,12,84,1,0,0,0,14,109,1,0,0,0,16,111,1,0,0,0,18,115,1,0,
  	0,0,20,149,1,0,0,0,22,200,1,0,0,0,24,210,1,0,0,0,26,224,1,0,0,0,28,228,
  	1,0,0,0,30,249,1,0,0,0,32,33,3,2,1,0,33,1,1,0,0,0,34,43,5,0,0,1,35,36,
  	3,4,2,0,36,37,5,0,0,1,37,43,1,0,0,0,38,39,3,4,2,0,39,40,5,14,0,0,40,43,
  	1,0,0,0,41,43,5,14,0,0,42,34,1,0,0,0,42,35,1,0,0,0,42,38,1,0,0,0,42,41,
  	1,0,0,0,43,3,1,0,0,0,44,54,3,30,15,0,45,47,3,6,3,0,46,45,1,0,0,0,47,48,
  	1,0,0,0,48,46,1,0,0,0,48,49,1,0,0,0,49,51,1,0,0,0,50,52,3,30,15,0,51,
  	50,1,0,0,0,51,52,1,0,0,0,52,54,1,0,0,0,53,44,1,0,0,0,53,46,1,0,0,0,54,
  	5,1,0,0,0,55,57,3,30,15,0,56,58,5,20,0,0,57,56,1,0,0,0,58,59,1,0,0,0,
  	59,57,1,0,0,0,59,60,1,0,0,0,60,7,1,0,0,0,61,62,5,9,0,0,62,63,5,33,0,0,
  	63,64,3,4,2,0,64,65,5,17,0,0,65,9,1,0,0,0,66,80,5,1,0,0,67,80,5,2,0,0,
  	68,80,5,3,0,0,69,80,5,10,0,0,70,71,5,32,0,0,71,72,3,4,2,0,72,73,5,17,
  	0,0,73,80,1,0,0,0,74,75,5,15,0,0,75,76,3,4,2,0,76,77,5,16,0,0,77,80,1,
  	0,0,0,78,80,3,8,4,0,79,66,1,0,0,0,79,67,1,0,0,0,79,68,1,0,0,0,79,69,1,
  	0,0,0,79,70,1,0,0,0,79,74,1,0,0,0,79,78,1,0,0,0,80,11,1,0,0,0,81,85,5,
  	13,0,0,82,85,5,12,0,0,83,85,5,11,0,0,84,81,1,0,0,0,84,82,1,0,0,0,84,83,
  	1,0,0,0,85,13,1,0,0,0,86,92,6,7,-1,0,87,90,5,18,0,0,88,91,3,10,5,0,89,
  	91,3,12,6,0,90,88,1,0,0,0,90,89,1,0,0,0,91,93,1,0,0,0,92,87,1,0,0,0,93,
  	94,1,0,0,0,94,92,1,0,0,0,94,95,1,0,0,0,95,110,1,0,0,0,96,104,6,7,-1,0,
  	97,100,5,18,0,0,98,101,3,10,5,0,99,101,3,12,6,0,100,98,1,0,0,0,100,99,
  	1,0,0,0,101,103,1,0,0,0,102,97,1,0,0,0,103,106,1,0,0,0,104,102,1,0,0,
  	0,104,105,1,0,0,0,105,107,1,0,0,0,106,104,1,0,0,0,107,108,5,18,0,0,108,
  	110,3,26,13,0,109,86,1,0,0,0,109,96,1,0,0,0,110,15,1,0,0,0,111,113,3,
  	12,6,0,112,114,3,14,7,0,113,112,1,0,0,0,113,114,1,0,0,0,114,17,1,0,0,
  	0,115,116,3,10,5,0,116,117,3,14,7,0,117,19,1,0,0,0,118,122,6,10,-1,0,
  	119,121,7,0,0,0,120,119,1,0,0,0,121,124,1,0,0,0,122,120,1,0,0,0,122,123,
  	1,0,0,0,123,125,1,0,0,0,124,122,1,0,0,0,125,150,3,10,5,0,126,128,7,0,
  	0,0,127,126,1,0,0,0,128,131,1,0,0,0,129,127,1,0,0,0,129,130,1,0,0,0,130,
  	132,1,0,0,0,131,129,1,0,0,0,132,150,3,12,6,0,133,137,4,10,0,0,134,136,
  	7,0,0,0,135,134,1,0,0,0,136,139,1,0,0,0,137,135,1,0,0,0,137,138,1,0,0,
  	0,138,140,1,0,0,0,139,137,1,0,0,0,140,150,3,16,8,0,141,145,4,10,1,0,142,
  	144,7,0,0,0,143,142,1,0,0,0,144,147,1,0,0,0,145,143,1,0,0,0,145,146,1,
  	0,0,0,146,148,1,0,0,0,147,145,1,0,0,0,148,150,3,18,9,0,149,118,1,0,0,
  	0,149,129,1,0,0,0,149,133,1,0,0,0,149,141,1,0,0,0,150,162,1,0,0,0,151,
  	152,10,7,0,0,152,153,5,24,0,0,153,161,3,20,10,8,154,155,10,4,0,0,155,
  	156,7,1,0,0,156,161,3,20,10,5,157,158,10,3,0,0,158,159,7,2,0,0,159,161,
  	3,20,10,4,160,151,1,0,0,0,160,154,1,0,0,0,160,157,1,0,0,0,161,164,1,0,
  	0,0,162,160,1,0,0,0,162,163,1,0,0,0,163,21,1,0,0,0,164,162,1,0,0,0,165,
  	166,3,20,10,0,166,167,5,24,0,0,167,168,3,28,14,0,168,201,1,0,0,0,169,
  	171,7,0,0,0,170,169,1,0,0,0,171,174,1,0,0,0,172,170,1,0,0,0,172,173,1,
  	0,0,0,173,175,1,0,0,0,174,172,1,0,0,0,175,201,3,28,14,0,176,177,3,20,
  	10,0,177,178,7,1,0,0,178,179,3,28,14,0,179,201,1,0,0,0,180,181,3,20,10,
  	0,181,182,7,2,0,0,182,183,3,28,14,0,183,201,1,0,0,0,184,188,4,11,5,0,
  	185,187,7,0,0,0,186,185,1,0,0,0,187,190,1,0,0,0,188,186,1,0,0,0,188,189,
  	1,0,0,0,189,191,1,0,0,0,190,188,1,0,0,0,191,201,3,16,8,0,192,196,4,11,
  	6,0,193,195,7,0,0,0,194,193,1,0,0,0,195,198,1,0,0,0,196,194,1,0,0,0,196,
  	197,1,0,0,0,197,199,1,0,0,0,198,196,1,0,0,0,199,201,3,18,9,0,200,165,
  	1,0,0,0,200,172,1,0,0,0,200,176,1,0,0,0,200,180,1,0,0,0,200,184,1,0,0,
  	0,200,192,1,0,0,0,201,23,1,0,0,0,202,203,3,16,8,0,203,204,5,21,0,0,204,
  	205,3,30,15,0,205,211,1,0,0,0,206,207,3,18,9,0,207,208,5,21,0,0,208,209,
  	3,30,15,0,209,211,1,0,0,0,210,202,1,0,0,0,210,206,1,0,0,0,211,25,1,0,
  	0,0,212,213,5,4,0,0,213,214,3,4,2,0,214,215,5,5,0,0,215,216,3,30,15,0,
  	216,225,1,0,0,0,217,218,5,4,0,0,218,219,3,4,2,0,219,220,5,5,0,0,220,221,
  	3,4,2,0,221,222,5,6,0,0,222,223,3,30,15,0,223,225,1,0,0,0,224,212,1,0,
  	0,0,224,217,1,0,0,0,225,27,1,0,0,0,226,229,3,26,13,0,227,229,3,24,12,
  	0,228,226,1,0,0,0,228,227,1,0,0,0,229,29,1,0,0,0,230,232,3,20,10,0,231,
  	230,1,0,0,0,232,233,1,0,0,0,233,231,1,0,0,0,233,234,1,0,0,0,234,250,1,
  	0,0,0,235,237,3,20,10,0,236,235,1,0,0,0,237,240,1,0,0,0,238,236,1,0,0,
  	0,238,239,1,0,0,0,239,241,1,0,0,0,240,238,1,0,0,0,241,250,3,22,11,0,242,
  	244,3,20,10,0,243,242,1,0,0,0,244,247,1,0,0,0,245,243,1,0,0,0,245,246,
  	1,0,0,0,246,248,1,0,0,0,247,245,1,0,0,0,248,250,3,28,14,0,249,231,1,0,
  	0,0,249,238,1,0,0,0,249,245,1,0,0,0,250,31,1,0,0,0,31,42,48,51,53,59,
  	79,84,90,94,100,104,109,113,122,129,137,145,149,160,162,172,188,196,200,
  	210,224,228,233,238,245,249
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


//----------------- EverythingContext ------------------------------------------------------------------

bellParser::EverythingContext::EverythingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bellParser::ProgramContext* bellParser::EverythingContext::program() {
  return getRuleContext<bellParser::ProgramContext>(0);
}


size_t bellParser::EverythingContext::getRuleIndex() const {
  return bellParser::RuleEverything;
}


std::any bellParser::EverythingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitEverything(this);
  else
    return visitor->visitChildren(this);
}

bellParser::EverythingContext* bellParser::everything() {
  EverythingContext *_localctx = _tracker.createInstance<EverythingContext>(_ctx, getState());
  enterRule(_localctx, 0, bellParser::RuleEverything);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(32);
    program();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

bellParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bellParser::ProgramContext::getRuleIndex() const {
  return bellParser::RuleProgram;
}

void bellParser::ProgramContext::copyFrom(ProgramContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ProgramSequenceContext ------------------------------------------------------------------

bellParser::SequenceContext* bellParser::ProgramSequenceContext::sequence() {
  return getRuleContext<bellParser::SequenceContext>(0);
}

tree::TerminalNode* bellParser::ProgramSequenceContext::EOF() {
  return getToken(bellParser::EOF, 0);
}

bellParser::ProgramSequenceContext::ProgramSequenceContext(ProgramContext *ctx) { copyFrom(ctx); }


std::any bellParser::ProgramSequenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitProgramSequence(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ProgramNamedparamContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ProgramNamedparamContext::NAMEDPARAM() {
  return getToken(bellParser::NAMEDPARAM, 0);
}

bellParser::ProgramNamedparamContext::ProgramNamedparamContext(ProgramContext *ctx) { copyFrom(ctx); }


std::any bellParser::ProgramNamedparamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitProgramNamedparam(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ProgramEOFContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ProgramEOFContext::EOF() {
  return getToken(bellParser::EOF, 0);
}

bellParser::ProgramEOFContext::ProgramEOFContext(ProgramContext *ctx) { copyFrom(ctx); }


std::any bellParser::ProgramEOFContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitProgramEOF(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ProgramSequenceNamedparamContext ------------------------------------------------------------------

bellParser::SequenceContext* bellParser::ProgramSequenceNamedparamContext::sequence() {
  return getRuleContext<bellParser::SequenceContext>(0);
}

tree::TerminalNode* bellParser::ProgramSequenceNamedparamContext::NAMEDPARAM() {
  return getToken(bellParser::NAMEDPARAM, 0);
}

bellParser::ProgramSequenceNamedparamContext::ProgramSequenceNamedparamContext(ProgramContext *ctx) { copyFrom(ctx); }


std::any bellParser::ProgramSequenceNamedparamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitProgramSequenceNamedparam(this);
  else
    return visitor->visitChildren(this);
}
bellParser::ProgramContext* bellParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 2, bellParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(42);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::ProgramEOFContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(34);
      match(bellParser::EOF);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::ProgramSequenceContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(35);
      sequence();
      setState(36);
      match(bellParser::EOF);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<bellParser::ProgramSequenceNamedparamContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(38);
      sequence();
      setState(39);
      match(bellParser::NAMEDPARAM);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<bellParser::ProgramNamedparamContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(41);
      match(bellParser::NAMEDPARAM);
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
  enterRule(_localctx, 4, bellParser::RuleSequence);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(53);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(44);
      list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(46); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(45);
                nullified();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(48); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(51);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
        setState(50);
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
  enterRule(_localctx, 6, bellParser::RuleNullified);

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
    setState(55);
    list();
    setState(57); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(56);
              match(bellParser::NULLIFY);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(59); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
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
  enterRule(_localctx, 8, bellParser::RuleFuncall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    match(bellParser::FUNCTION);
    setState(62);
    match(bellParser::PARAMS);
    setState(63);
    sequence();
    setState(64);
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

//----------------- ItemUfloatContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemUfloatContext::UFLOAT() {
  return getToken(bellParser::UFLOAT, 0);
}

bellParser::ItemUfloatContext::ItemUfloatContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemUfloatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemUfloat(this);
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
//----------------- ItemUintContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemUintContext::UINT() {
  return getToken(bellParser::UINT, 0);
}

bellParser::ItemUintContext::ItemUintContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemUintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemUint(this);
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
//----------------- ItemInletContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemInletContext::INLET() {
  return getToken(bellParser::INLET, 0);
}

bellParser::ItemInletContext::ItemInletContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemInletContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemInlet(this);
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
//----------------- ItemUpitchContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemUpitchContext::UPITCH() {
  return getToken(bellParser::UPITCH, 0);
}

bellParser::ItemUpitchContext::ItemUpitchContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemUpitchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemUpitch(this);
  else
    return visitor->visitChildren(this);
}
bellParser::ItemContext* bellParser::item() {
  ItemContext *_localctx = _tracker.createInstance<ItemContext>(_ctx, getState());
  enterRule(_localctx, 10, bellParser::RuleItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(79);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::UINT: {
        _localctx = _tracker.createInstance<bellParser::ItemUintContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(66);
        match(bellParser::UINT);
        break;
      }

      case bellParser::UFLOAT: {
        _localctx = _tracker.createInstance<bellParser::ItemUfloatContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(67);
        match(bellParser::UFLOAT);
        break;
      }

      case bellParser::UPITCH: {
        _localctx = _tracker.createInstance<bellParser::ItemUpitchContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(68);
        match(bellParser::UPITCH);
        break;
      }

      case bellParser::INLET: {
        _localctx = _tracker.createInstance<bellParser::ItemInletContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(69);
        match(bellParser::INLET);
        break;
      }

      case bellParser::OPEN: {
        _localctx = _tracker.createInstance<bellParser::ItemSequenceContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(70);
        match(bellParser::OPEN);
        setState(71);
        sequence();
        setState(72);
        match(bellParser::CLOSED);
        break;
      }

      case bellParser::PUSH: {
        _localctx = _tracker.createInstance<bellParser::ItemSublistContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(74);
        match(bellParser::PUSH);
        setState(75);
        sequence();
        setState(76);
        match(bellParser::POP);
        break;
      }

      case bellParser::FUNCTION: {
        _localctx = _tracker.createInstance<bellParser::ItemFuncallContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(78);
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


size_t bellParser::VarContext::getRuleIndex() const {
  return bellParser::RuleVar;
}

void bellParser::VarContext::copyFrom(VarContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VarLocalContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::VarLocalContext::LOCALVAR() {
  return getToken(bellParser::LOCALVAR, 0);
}

bellParser::VarLocalContext::VarLocalContext(VarContext *ctx) { copyFrom(ctx); }


std::any bellParser::VarLocalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitVarLocal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarPatcherContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::VarPatcherContext::PATCHERVAR() {
  return getToken(bellParser::PATCHERVAR, 0);
}

bellParser::VarPatcherContext::VarPatcherContext(VarContext *ctx) { copyFrom(ctx); }


std::any bellParser::VarPatcherContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitVarPatcher(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarGlobalContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::VarGlobalContext::GLOBALVAR() {
  return getToken(bellParser::GLOBALVAR, 0);
}

bellParser::VarGlobalContext::VarGlobalContext(VarContext *ctx) { copyFrom(ctx); }


std::any bellParser::VarGlobalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitVarGlobal(this);
  else
    return visitor->visitChildren(this);
}
bellParser::VarContext* bellParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 12, bellParser::RuleVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(84);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::LOCALVAR: {
        _localctx = _tracker.createInstance<bellParser::VarLocalContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(81);
        match(bellParser::LOCALVAR);
        break;
      }

      case bellParser::PATCHERVAR: {
        _localctx = _tracker.createInstance<bellParser::VarPatcherContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(82);
        match(bellParser::PATCHERVAR);
        break;
      }

      case bellParser::GLOBALVAR: {
        _localctx = _tracker.createInstance<bellParser::VarGlobalContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(83);
        match(bellParser::GLOBALVAR);
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
  enterRule(_localctx, 14, bellParser::RuleLvalueSpecs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(109);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      ending = false;
      setState(92); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(87);
                match(bellParser::NTH);
                setState(90);
                _errHandler->sync(this);
                switch (_input->LA(1)) {
                  case bellParser::UINT:
                  case bellParser::UFLOAT:
                  case bellParser::UPITCH:
                  case bellParser::FUNCTION:
                  case bellParser::INLET:
                  case bellParser::PUSH:
                  case bellParser::OPEN: {
                    setState(88);
                    item();
                    break;
                  }

                  case bellParser::GLOBALVAR:
                  case bellParser::PATCHERVAR:
                  case bellParser::LOCALVAR: {
                    setState(89);
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
        setState(94); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      ending = true;
      setState(104);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(97);
          match(bellParser::NTH);
          setState(100);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case bellParser::UINT:
            case bellParser::UFLOAT:
            case bellParser::UPITCH:
            case bellParser::FUNCTION:
            case bellParser::INLET:
            case bellParser::PUSH:
            case bellParser::OPEN: {
              setState(98);
              item();
              break;
            }

            case bellParser::GLOBALVAR:
            case bellParser::PATCHERVAR:
            case bellParser::LOCALVAR: {
              setState(99);
              var();
              break;
            }

          default:
            throw NoViableAltException(this);
          } 
        }
        setState(106);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      }

      setState(107);
      match(bellParser::NTH);

      setState(108);
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
  enterRule(_localctx, 16, bellParser::RuleLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    var();
    setState(113);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(112);
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
  enterRule(_localctx, 18, bellParser::RuleFakeLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    item();
    setState(116);
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
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, bellParser::RuleExpr, precedence);

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
    setState(149);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprUnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(122);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == bellParser::UPLUS

      || _la == bellParser::UMINUS) {
        setState(119);
        _la = _input->LA(1);
        if (!(_la == bellParser::UPLUS

        || _la == bellParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(124);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(125);
      item();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ExprVarContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(129);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == bellParser::UPLUS

      || _la == bellParser::UMINUS) {
        setState(126);
        _la = _input->LA(1);
        if (!(_la == bellParser::UPLUS

        || _la == bellParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(131);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(132);
      var();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ExprLvalueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(133);

      if (!(!ending)) throw FailedPredicateException(this, "!ending");
      setState(137);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == bellParser::UPLUS

      || _la == bellParser::UMINUS) {
        setState(134);
        _la = _input->LA(1);
        if (!(_la == bellParser::UPLUS

        || _la == bellParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(139);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(140);
      lvalue();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprFakeLvalueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(141);

      if (!(!ending)) throw FailedPredicateException(this, "!ending");
      setState(145);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == bellParser::UPLUS

      || _la == bellParser::UMINUS) {
        setState(142);
        _la = _input->LA(1);
        if (!(_la == bellParser::UPLUS

        || _la == bellParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(147);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(148);
      fakeLvalue();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(162);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(160);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprPowContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(151);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(152);
          match(bellParser::POW);
          setState(153);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprTimesDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(154);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(155);
          antlrcpp::downCast<ExprTimesDivContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << bellParser::TIMES)
            | (1ULL << bellParser::DIVDIV)
            | (1ULL << bellParser::DIV))) != 0))) {
            antlrcpp::downCast<ExprTimesDivContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(156);
          expr(5);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprPlusMinusContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(157);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(158);
          antlrcpp::downCast<ExprPlusMinusContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == bellParser::PLUS

          || _la == bellParser::MINUS)) {
            antlrcpp::downCast<ExprPlusMinusContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(159);
          expr(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(164);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
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
  enterRule(_localctx, 22, bellParser::RuleEexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(200);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::EexprPowContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(165);
      expr(0);
      setState(166);
      match(bellParser::POW);
      setState(167);
      listEnd();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::EexprUnaryContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(172);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == bellParser::UPLUS

      || _la == bellParser::UMINUS) {
        setState(169);
        _la = _input->LA(1);
        if (!(_la == bellParser::UPLUS

        || _la == bellParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(174);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(175);
      listEnd();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<bellParser::EexprTimesDivContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(176);
      expr(0);
      setState(177);
      antlrcpp::downCast<EexprTimesDivContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << bellParser::TIMES)
        | (1ULL << bellParser::DIVDIV)
        | (1ULL << bellParser::DIV))) != 0))) {
        antlrcpp::downCast<EexprTimesDivContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(178);
      listEnd();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<bellParser::EexprPlusMinusContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(180);
      expr(0);
      setState(181);
      antlrcpp::downCast<EexprPlusMinusContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == bellParser::PLUS

      || _la == bellParser::MINUS)) {
        antlrcpp::downCast<EexprPlusMinusContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(182);
      listEnd();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<bellParser::EexprLvalueContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(184);

      if (!(ending)) throw FailedPredicateException(this, "ending");
      setState(188);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == bellParser::UPLUS

      || _la == bellParser::UMINUS) {
        setState(185);
        _la = _input->LA(1);
        if (!(_la == bellParser::UPLUS

        || _la == bellParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(190);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(191);
      lvalue();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<bellParser::EexprFakeLvalueContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(192);

      if (!(ending)) throw FailedPredicateException(this, "ending");
      setState(196);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == bellParser::UPLUS

      || _la == bellParser::UMINUS) {
        setState(193);
        _la = _input->LA(1);
        if (!(_la == bellParser::UPLUS

        || _la == bellParser::UMINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(198);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(199);
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
  enterRule(_localctx, 24, bellParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(210);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::GLOBALVAR:
      case bellParser::PATCHERVAR:
      case bellParser::LOCALVAR: {
        _localctx = _tracker.createInstance<bellParser::TrueAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(202);
        lvalue();
        setState(203);
        match(bellParser::ASSIGN);
        setState(204);
        list();
        break;
      }

      case bellParser::UINT:
      case bellParser::UFLOAT:
      case bellParser::UPITCH:
      case bellParser::FUNCTION:
      case bellParser::INLET:
      case bellParser::PUSH:
      case bellParser::OPEN: {
        _localctx = _tracker.createInstance<bellParser::FakeAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(206);
        fakeLvalue();
        setState(207);
        match(bellParser::ASSIGN);
        setState(208);
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
  enterRule(_localctx, 26, bellParser::RuleConditional);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(224);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::IfthenContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(212);
      match(bellParser::IF);
      setState(213);
      sequence();
      setState(214);
      match(bellParser::THEN);
      setState(215);
      list();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::IfthenelseContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(217);
      match(bellParser::IF);
      setState(218);
      sequence();
      setState(219);
      match(bellParser::THEN);
      setState(220);
      sequence();
      setState(221);
      match(bellParser::ELSE);
      setState(222);
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
  enterRule(_localctx, 28, bellParser::RuleListEnd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(228);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(226);
        conditional();
        break;
      }

      case bellParser::UINT:
      case bellParser::UFLOAT:
      case bellParser::UPITCH:
      case bellParser::FUNCTION:
      case bellParser::INLET:
      case bellParser::GLOBALVAR:
      case bellParser::PATCHERVAR:
      case bellParser::LOCALVAR:
      case bellParser::PUSH:
      case bellParser::OPEN: {
        enterOuterAlt(_localctx, 2);
        setState(227);
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
  enterRule(_localctx, 30, bellParser::RuleList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(249);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(231); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(230);
                expr(0);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(233); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(238);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(235);
          expr(0); 
        }
        setState(240);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      }
      setState(241);
      eexpr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(245);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(242);
          expr(0); 
        }
        setState(247);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      }
      setState(248);
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
    case 10: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 11: return eexprSempred(antlrcpp::downCast<EexprContext *>(context), predicateIndex);

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
