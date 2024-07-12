
// Generated from pitch.g4 by ANTLR 4.10.1


#include "pitchLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct PitchLexerStaticData final {
  PitchLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PitchLexerStaticData(const PitchLexerStaticData&) = delete;
  PitchLexerStaticData(PitchLexerStaticData&&) = delete;
  PitchLexerStaticData& operator=(const PitchLexerStaticData&) = delete;
  PitchLexerStaticData& operator=(PitchLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag pitchlexerLexerOnceFlag;
PitchLexerStaticData *pitchlexerLexerStaticData = nullptr;

void pitchlexerLexerInitialize() {
  assert(pitchlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<PitchLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "UINT", "NOTENAME", "ACCIDENTAL", "UPLUS", "UMINUS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'t'", "'/'", "", "", "", "'+'", "'-'"
    },
    std::vector<std::string>{
      "", "", "", "UINT", "NOTENAME", "ACCIDENTAL", "UPLUS", "UMINUS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,7,36,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	1,0,1,0,1,1,1,1,1,2,4,2,21,8,2,11,2,12,2,22,1,3,3,3,26,8,3,1,4,4,4,29,
  	8,4,11,4,12,4,30,1,5,1,5,1,6,1,6,0,0,7,1,1,3,2,5,3,7,4,9,5,11,6,13,7,
  	1,0,3,1,0,48,57,2,0,65,71,97,103,7,0,35,35,94,94,98,98,100,100,113,113,
  	118,118,120,120,37,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,
  	9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,1,15,1,0,0,0,3,17,1,0,0,0,5,20,1,
  	0,0,0,7,25,1,0,0,0,9,28,1,0,0,0,11,32,1,0,0,0,13,34,1,0,0,0,15,16,5,116,
  	0,0,16,2,1,0,0,0,17,18,5,47,0,0,18,4,1,0,0,0,19,21,7,0,0,0,20,19,1,0,
  	0,0,21,22,1,0,0,0,22,20,1,0,0,0,22,23,1,0,0,0,23,6,1,0,0,0,24,26,7,1,
  	0,0,25,24,1,0,0,0,26,8,1,0,0,0,27,29,7,2,0,0,28,27,1,0,0,0,29,30,1,0,
  	0,0,30,28,1,0,0,0,30,31,1,0,0,0,31,10,1,0,0,0,32,33,5,43,0,0,33,12,1,
  	0,0,0,34,35,5,45,0,0,35,14,1,0,0,0,4,0,22,25,30,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  pitchlexerLexerStaticData = staticData.release();
}

}

pitchLexer::pitchLexer(CharStream *input) : Lexer(input) {
  pitchLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *pitchlexerLexerStaticData->atn, pitchlexerLexerStaticData->decisionToDFA, pitchlexerLexerStaticData->sharedContextCache);
}

pitchLexer::~pitchLexer() {
  delete _interpreter;
}

std::string pitchLexer::getGrammarFileName() const {
  return "pitch.g4";
}

const std::vector<std::string>& pitchLexer::getRuleNames() const {
  return pitchlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& pitchLexer::getChannelNames() const {
  return pitchlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& pitchLexer::getModeNames() const {
  return pitchlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& pitchLexer::getVocabulary() const {
  return pitchlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView pitchLexer::getSerializedATN() const {
  return pitchlexerLexerStaticData->serializedATN;
}

const atn::ATN& pitchLexer::getATN() const {
  return *pitchlexerLexerStaticData->atn;
}




void pitchLexer::initialize() {
  std::call_once(pitchlexerLexerOnceFlag, pitchlexerLexerInitialize);
}
