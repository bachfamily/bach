 
#include "ext.h" 


// Generated from bell.g4 by ANTLR 4.10.1


#include "bellLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct BellLexerStaticData final {
  BellLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  BellLexerStaticData(const BellLexerStaticData&) = delete;
  BellLexerStaticData(BellLexerStaticData&&) = delete;
  BellLexerStaticData& operator=(const BellLexerStaticData&) = delete;
  BellLexerStaticData& operator=(BellLexerStaticData&&) = delete;

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

std::once_flag belllexerLexerOnceFlag;
BellLexerStaticData *belllexerLexerStaticData = nullptr;

void belllexerLexerInitialize() {
  assert(belllexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<BellLexerStaticData>(
    std::vector<std::string>{
      "UINT", "UFLOAT", "IF", "THEN", "ELSE", "FOR", "DO", "FUNCTION", "INLET", 
      "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "PUSH", "POP", "CLOSED", "NTH", 
      "KEY", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", "POW", "TIMES", "DIVDIV", 
      "DIV", "PLUS", "UPLUS", "MINUS", "UMINUS", "OPEN", "PARAMS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "", "'if'", "'then'", "'else'", "'for'", "'do'", "", "", "", 
      "", "", "'['", "']'", "')'", "':'", "'.'", "';'", "'='", "'\\n'", 
      "", "'**'", "'*'", "'//'", "'/'", "", "'+'", "", "'-'"
    },
    std::vector<std::string>{
      "", "UINT", "UFLOAT", "IF", "THEN", "ELSE", "FOR", "DO", "FUNCTION", 
      "INLET", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "PUSH", "POP", "CLOSED", 
      "NTH", "KEY", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", "POW", "TIMES", 
      "DIVDIV", "DIV", "PLUS", "UPLUS", "MINUS", "UMINUS", "OPEN", "PARAMS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,31,277,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,1,0,4,0,65,8,0,11,0,12,0,66,1,0,1,0,1,1,5,1,
  	72,8,1,10,1,12,1,75,9,1,1,1,1,1,4,1,79,8,1,11,1,12,1,80,1,1,4,1,84,8,
  	1,11,1,12,1,85,1,1,3,1,89,8,1,1,1,1,1,3,1,93,8,1,1,1,4,1,96,8,1,11,1,
  	12,1,97,3,1,100,8,1,1,1,4,1,103,8,1,11,1,12,1,104,1,1,1,1,3,1,109,8,1,
  	1,1,4,1,112,8,1,11,1,12,1,113,3,1,116,8,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,3,7,162,8,7,1,8,1,8,1,8,4,8,167,8,8,11,8,12,8,168,1,8,1,8,1,9,
  	1,9,5,9,175,8,9,10,9,12,9,178,9,9,1,9,3,9,181,8,9,1,9,1,9,1,10,1,10,1,
  	10,5,10,188,8,10,10,10,12,10,191,9,10,1,10,3,10,194,8,10,1,10,1,10,1,
  	11,1,11,1,11,5,11,201,8,11,10,11,12,11,204,9,11,1,11,3,11,207,8,11,1,
  	11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,14,1,15,1,15,1,15,1,
  	16,1,16,1,16,1,17,1,17,1,17,1,18,1,18,1,18,1,19,1,19,1,19,1,20,1,20,1,
  	20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,23,1,23,1,23,1,
  	23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,26,1,26,1,26,1,27,1,27,1,
  	27,1,27,1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,30,1,30,1,30,1,30,0,0,31,
  	1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,
  	29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,
  	26,53,27,55,28,57,29,59,30,61,31,1,0,8,1,0,48,57,2,0,69,69,101,101,2,
  	0,43,43,45,45,2,0,108,108,120,120,2,0,65,90,97,122,4,0,48,57,65,90,95,
  	95,97,122,3,0,48,57,65,90,97,122,3,0,1,1,9,9,32,32,297,0,1,1,0,0,0,0,
  	3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,
  	0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,
  	25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,
  	0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,
  	0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,
  	57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,1,64,1,0,0,0,3,115,1,0,0,0,5,119,
  	1,0,0,0,7,124,1,0,0,0,9,131,1,0,0,0,11,138,1,0,0,0,13,144,1,0,0,0,15,
  	161,1,0,0,0,17,163,1,0,0,0,19,172,1,0,0,0,21,184,1,0,0,0,23,197,1,0,0,
  	0,25,210,1,0,0,0,27,213,1,0,0,0,29,216,1,0,0,0,31,219,1,0,0,0,33,222,
  	1,0,0,0,35,225,1,0,0,0,37,228,1,0,0,0,39,231,1,0,0,0,41,234,1,0,0,0,43,
  	239,1,0,0,0,45,244,1,0,0,0,47,247,1,0,0,0,49,252,1,0,0,0,51,255,1,0,0,
  	0,53,259,1,0,0,0,55,262,1,0,0,0,57,266,1,0,0,0,59,269,1,0,0,0,61,273,
  	1,0,0,0,63,65,7,0,0,0,64,63,1,0,0,0,65,66,1,0,0,0,66,64,1,0,0,0,66,67,
  	1,0,0,0,67,68,1,0,0,0,68,69,6,0,0,0,69,2,1,0,0,0,70,72,7,0,0,0,71,70,
  	1,0,0,0,72,75,1,0,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,76,1,0,0,0,75,73,
  	1,0,0,0,76,78,5,46,0,0,77,79,7,0,0,0,78,77,1,0,0,0,79,80,1,0,0,0,80,78,
  	1,0,0,0,80,81,1,0,0,0,81,89,1,0,0,0,82,84,7,0,0,0,83,82,1,0,0,0,84,85,
  	1,0,0,0,85,83,1,0,0,0,85,86,1,0,0,0,86,87,1,0,0,0,87,89,5,46,0,0,88,73,
  	1,0,0,0,88,83,1,0,0,0,89,99,1,0,0,0,90,92,7,1,0,0,91,93,7,2,0,0,92,91,
  	1,0,0,0,92,93,1,0,0,0,93,95,1,0,0,0,94,96,7,0,0,0,95,94,1,0,0,0,96,97,
  	1,0,0,0,97,95,1,0,0,0,97,98,1,0,0,0,98,100,1,0,0,0,99,90,1,0,0,0,99,100,
  	1,0,0,0,100,116,1,0,0,0,101,103,7,0,0,0,102,101,1,0,0,0,103,104,1,0,0,
  	0,104,102,1,0,0,0,104,105,1,0,0,0,105,106,1,0,0,0,106,108,7,1,0,0,107,
  	109,7,2,0,0,108,107,1,0,0,0,108,109,1,0,0,0,109,111,1,0,0,0,110,112,7,
  	0,0,0,111,110,1,0,0,0,112,113,1,0,0,0,113,111,1,0,0,0,113,114,1,0,0,0,
  	114,116,1,0,0,0,115,88,1,0,0,0,115,102,1,0,0,0,116,117,1,0,0,0,117,118,
  	6,1,1,0,118,4,1,0,0,0,119,120,5,105,0,0,120,121,5,102,0,0,121,122,1,0,
  	0,0,122,123,6,2,2,0,123,6,1,0,0,0,124,125,5,116,0,0,125,126,5,104,0,0,
  	126,127,5,101,0,0,127,128,5,110,0,0,128,129,1,0,0,0,129,130,6,3,3,0,130,
  	8,1,0,0,0,131,132,5,101,0,0,132,133,5,108,0,0,133,134,5,115,0,0,134,135,
  	5,101,0,0,135,136,1,0,0,0,136,137,6,4,4,0,137,10,1,0,0,0,138,139,5,102,
  	0,0,139,140,5,111,0,0,140,141,5,114,0,0,141,142,1,0,0,0,142,143,6,5,5,
  	0,143,12,1,0,0,0,144,145,5,100,0,0,145,146,5,111,0,0,146,147,1,0,0,0,
  	147,148,6,6,6,0,148,14,1,0,0,0,149,150,5,115,0,0,150,151,5,105,0,0,151,
  	162,5,110,0,0,152,153,5,99,0,0,153,154,5,111,0,0,154,162,5,115,0,0,155,
  	156,5,115,0,0,156,157,5,113,0,0,157,158,5,114,0,0,158,159,5,116,0,0,159,
  	160,1,0,0,0,160,162,6,7,7,0,161,149,1,0,0,0,161,152,1,0,0,0,161,155,1,
  	0,0,0,162,16,1,0,0,0,163,164,5,36,0,0,164,166,7,3,0,0,165,167,7,0,0,0,
  	166,165,1,0,0,0,167,168,1,0,0,0,168,166,1,0,0,0,168,169,1,0,0,0,169,170,
  	1,0,0,0,170,171,6,8,8,0,171,18,1,0,0,0,172,180,7,4,0,0,173,175,7,5,0,
  	0,174,173,1,0,0,0,175,178,1,0,0,0,176,174,1,0,0,0,176,177,1,0,0,0,177,
  	179,1,0,0,0,178,176,1,0,0,0,179,181,7,6,0,0,180,176,1,0,0,0,180,181,1,
  	0,0,0,181,182,1,0,0,0,182,183,6,9,9,0,183,20,1,0,0,0,184,185,5,35,0,0,
  	185,193,7,4,0,0,186,188,7,5,0,0,187,186,1,0,0,0,188,191,1,0,0,0,189,187,
  	1,0,0,0,189,190,1,0,0,0,190,192,1,0,0,0,191,189,1,0,0,0,192,194,7,6,0,
  	0,193,189,1,0,0,0,193,194,1,0,0,0,194,195,1,0,0,0,195,196,6,10,10,0,196,
  	22,1,0,0,0,197,198,5,36,0,0,198,206,7,4,0,0,199,201,7,5,0,0,200,199,1,
  	0,0,0,201,204,1,0,0,0,202,200,1,0,0,0,202,203,1,0,0,0,203,205,1,0,0,0,
  	204,202,1,0,0,0,205,207,7,6,0,0,206,202,1,0,0,0,206,207,1,0,0,0,207,208,
  	1,0,0,0,208,209,6,11,11,0,209,24,1,0,0,0,210,211,5,91,0,0,211,212,6,12,
  	12,0,212,26,1,0,0,0,213,214,5,93,0,0,214,215,6,13,13,0,215,28,1,0,0,0,
  	216,217,5,41,0,0,217,218,6,14,14,0,218,30,1,0,0,0,219,220,5,58,0,0,220,
  	221,6,15,15,0,221,32,1,0,0,0,222,223,5,46,0,0,223,224,6,16,16,0,224,34,
  	1,0,0,0,225,226,5,59,0,0,226,227,6,17,17,0,227,36,1,0,0,0,228,229,5,61,
  	0,0,229,230,6,18,18,0,230,38,1,0,0,0,231,232,5,10,0,0,232,233,6,19,19,
  	0,233,40,1,0,0,0,234,235,7,7,0,0,235,236,6,20,20,0,236,237,1,0,0,0,237,
  	238,6,20,21,0,238,42,1,0,0,0,239,240,5,42,0,0,240,241,5,42,0,0,241,242,
  	1,0,0,0,242,243,6,21,22,0,243,44,1,0,0,0,244,245,5,42,0,0,245,246,6,22,
  	23,0,246,46,1,0,0,0,247,248,5,47,0,0,248,249,5,47,0,0,249,250,1,0,0,0,
  	250,251,6,23,24,0,251,48,1,0,0,0,252,253,5,47,0,0,253,254,6,24,25,0,254,
  	50,1,0,0,0,255,256,4,25,0,0,256,257,5,43,0,0,257,258,6,25,26,0,258,52,
  	1,0,0,0,259,260,5,43,0,0,260,261,6,26,27,0,261,54,1,0,0,0,262,263,4,27,
  	1,0,263,264,5,45,0,0,264,265,6,27,28,0,265,56,1,0,0,0,266,267,5,45,0,
  	0,267,268,6,28,29,0,268,58,1,0,0,0,269,270,4,29,2,0,270,271,5,40,0,0,
  	271,272,6,29,30,0,272,60,1,0,0,0,273,274,4,30,3,0,274,275,5,40,0,0,275,
  	276,6,30,31,0,276,62,1,0,0,0,21,0,66,73,80,85,88,92,97,99,104,108,113,
  	115,161,168,176,180,189,193,202,206,32,1,0,0,1,1,1,1,2,2,1,3,3,1,4,4,
  	1,5,5,1,6,6,1,7,7,1,8,8,1,9,9,1,10,10,1,11,11,1,12,12,1,13,13,1,14,14,
  	1,15,15,1,16,16,1,17,17,1,18,18,1,19,19,1,20,20,0,1,0,1,21,21,1,22,22,
  	1,23,23,1,24,24,1,25,25,1,26,26,1,27,27,1,28,28,1,29,29,1,30,30
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  belllexerLexerStaticData = staticData.release();
}

}

bellLexer::bellLexer(CharStream *input) : Lexer(input) {
  bellLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *belllexerLexerStaticData->atn, belllexerLexerStaticData->decisionToDFA, belllexerLexerStaticData->sharedContextCache);
}

bellLexer::~bellLexer() {
  delete _interpreter;
}

std::string bellLexer::getGrammarFileName() const {
  return "bell.g4";
}

const std::vector<std::string>& bellLexer::getRuleNames() const {
  return belllexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& bellLexer::getChannelNames() const {
  return belllexerLexerStaticData->channelNames;
}

const std::vector<std::string>& bellLexer::getModeNames() const {
  return belllexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& bellLexer::getVocabulary() const {
  return belllexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView bellLexer::getSerializedATN() const {
  return belllexerLexerStaticData->serializedATN;
}

const atn::ATN& bellLexer::getATN() const {
  return *belllexerLexerStaticData->atn;
}


void bellLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 0: UINTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 1: UFLOATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 2: IFAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 3: THENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 4: ELSEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 5: FORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 6: DOAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 7: FUNCTIONAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 8: INLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 9: GLOBALVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 10: PATCHERVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 11: LOCALVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: PUSHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: POPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: CLOSEDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: NTHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: KEYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 17: NULLIFYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 18: ASSIGNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 19: EOLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 20: WHITESPACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 21: POWAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 22: TIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 23: DIVDIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 24: DIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 25: PLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 26: UPLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 27: MINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 28: UMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 29: OPENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 30: PARAMSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool bellLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 25: return PLUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 27: return MINUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 29: return OPENSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 30: return PARAMSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

void bellLexer::UINTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0:  std::cout << "UINT\n"; noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::UFLOATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1:  std::cout << "UFLOAT\n"; noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::IFAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::THENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ELSEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::FORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DOAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::FUNCTIONAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 7:  noParams = noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::INLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 8:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::GLOBALVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 9:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PATCHERVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 10:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::LOCALVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 11:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PUSHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 12:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::POPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 13:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::CLOSEDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 14:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::NTHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 15:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::KEYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 16:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NULLIFYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 17:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ASSIGNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 18:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::EOLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 19:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::WHITESPACEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 20:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::POWAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 21:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::TIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVDIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 25:  post("plus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UPLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 26:  post("uplus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::MINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 27:  post("minus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 28:  post("uminus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::OPENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 29:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PARAMSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 30:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}


bool bellLexer::PLUSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return  notUnary() ;

  default:
    break;
  }
  return true;
}

bool bellLexer::MINUSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return  notUnary() ;

  default:
    break;
  }
  return true;
}

bool bellLexer::OPENSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return  noParams ;

  default:
    break;
  }
  return true;
}

bool bellLexer::PARAMSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return  !noParams ;

  default:
    break;
  }
  return true;
}


void bellLexer::initialize() {
  std::call_once(belllexerLexerOnceFlag, belllexerLexerInitialize);
}
