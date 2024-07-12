 
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
      "UINT", "UFLOAT", "UPITCH", "NOTENAME", "ACCIDENTAL", "RAT", "IF", 
      "THEN", "ELSE", "FOR", "DO", "FUNCTION", "INLET", "GLOBALVAR", "PATCHERVAR", 
      "LOCALVAR", "PUSH", "POP", "CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", 
      "EOL", "WHITESPACE", "POW", "TIMES", "DIVDIV", "DIV", "PLUS", "UPLUS", 
      "MINUS", "UMINUS", "OPEN", "PARAMS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "", "", "'if'", "'then'", "'else'", "'for'", "'do'", "", "", 
      "", "", "", "'['", "']'", "')'", "':'", "'.'", "';'", "'='", "'\\n'", 
      "", "'**'", "'*'", "'//'", "'/'", "", "'+'", "", "'-'"
    },
    std::vector<std::string>{
      "", "UINT", "UFLOAT", "UPITCH", "IF", "THEN", "ELSE", "FOR", "DO", 
      "FUNCTION", "INLET", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "PUSH", 
      "POP", "CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", 
      "POW", "TIMES", "DIVDIV", "DIV", "PLUS", "UPLUS", "MINUS", "UMINUS", 
      "OPEN", "PARAMS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,32,330,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,1,0,
  	4,0,73,8,0,11,0,12,0,74,1,0,1,0,1,1,5,1,80,8,1,10,1,12,1,83,9,1,1,1,1,
  	1,4,1,87,8,1,11,1,12,1,88,1,1,4,1,92,8,1,11,1,12,1,93,1,1,3,1,97,8,1,
  	1,1,1,1,3,1,101,8,1,1,1,4,1,104,8,1,11,1,12,1,105,3,1,108,8,1,1,1,4,1,
  	111,8,1,11,1,12,1,112,1,1,1,1,3,1,117,8,1,1,1,4,1,120,8,1,11,1,12,1,121,
  	3,1,124,8,1,1,1,1,1,1,2,1,2,3,2,130,8,2,1,2,5,2,133,8,2,10,2,12,2,136,
  	9,2,1,2,1,2,5,2,140,8,2,10,2,12,2,143,9,2,1,2,1,2,3,2,147,8,2,1,2,1,2,
  	3,2,151,8,2,1,2,1,2,1,3,3,3,156,8,3,1,4,4,4,159,8,4,11,4,12,4,160,1,5,
  	1,5,1,5,5,5,166,8,5,10,5,12,5,169,9,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,3,11,215,8,11,1,12,1,12,1,12,4,12,220,8,12,11,12,
  	12,12,221,1,12,1,12,1,13,1,13,5,13,228,8,13,10,13,12,13,231,9,13,1,13,
  	3,13,234,8,13,1,13,1,13,1,14,1,14,1,14,5,14,241,8,14,10,14,12,14,244,
  	9,14,1,14,3,14,247,8,14,1,14,1,14,1,15,1,15,1,15,5,15,254,8,15,10,15,
  	12,15,257,9,15,1,15,3,15,260,8,15,1,15,1,15,1,16,1,16,1,16,1,17,1,17,
  	1,17,1,18,1,18,1,18,1,19,1,19,1,19,1,20,1,20,1,20,1,21,1,21,1,21,1,22,
  	1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,25,1,25,
  	1,25,1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,28,1,28,1,28,1,29,1,29,
  	1,29,1,29,1,30,1,30,1,30,1,31,1,31,1,31,1,31,1,32,1,32,1,32,1,33,1,33,
  	1,33,1,33,1,34,1,34,1,34,1,34,0,0,35,1,1,3,2,5,3,7,0,9,0,11,0,13,4,15,
  	5,17,6,19,7,21,8,23,9,25,10,27,11,29,12,31,13,33,14,35,15,37,16,39,17,
  	41,18,43,19,45,20,47,21,49,22,51,23,53,24,55,25,57,26,59,27,61,28,63,
  	29,65,30,67,31,69,32,1,0,10,1,0,48,57,2,0,69,69,101,101,2,0,43,43,45,
  	45,2,0,65,71,97,103,7,0,35,35,94,94,98,98,100,100,113,113,118,118,120,
  	120,2,0,108,108,120,120,2,0,65,90,97,122,4,0,48,57,65,90,95,95,97,122,
  	3,0,48,57,65,90,97,122,3,0,1,1,9,9,32,32,354,0,1,1,0,0,0,0,3,1,0,0,0,
  	0,5,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,
  	1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,
  	0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,
  	0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,
  	1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,
  	0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,1,72,1,0,0,0,3,123,1,0,0,0,
  	5,127,1,0,0,0,7,155,1,0,0,0,9,158,1,0,0,0,11,162,1,0,0,0,13,172,1,0,0,
  	0,15,177,1,0,0,0,17,184,1,0,0,0,19,191,1,0,0,0,21,197,1,0,0,0,23,214,
  	1,0,0,0,25,216,1,0,0,0,27,225,1,0,0,0,29,237,1,0,0,0,31,250,1,0,0,0,33,
  	263,1,0,0,0,35,266,1,0,0,0,37,269,1,0,0,0,39,272,1,0,0,0,41,275,1,0,0,
  	0,43,278,1,0,0,0,45,281,1,0,0,0,47,284,1,0,0,0,49,287,1,0,0,0,51,292,
  	1,0,0,0,53,297,1,0,0,0,55,300,1,0,0,0,57,305,1,0,0,0,59,308,1,0,0,0,61,
  	312,1,0,0,0,63,315,1,0,0,0,65,319,1,0,0,0,67,322,1,0,0,0,69,326,1,0,0,
  	0,71,73,7,0,0,0,72,71,1,0,0,0,73,74,1,0,0,0,74,72,1,0,0,0,74,75,1,0,0,
  	0,75,76,1,0,0,0,76,77,6,0,0,0,77,2,1,0,0,0,78,80,7,0,0,0,79,78,1,0,0,
  	0,80,83,1,0,0,0,81,79,1,0,0,0,81,82,1,0,0,0,82,84,1,0,0,0,83,81,1,0,0,
  	0,84,86,5,46,0,0,85,87,7,0,0,0,86,85,1,0,0,0,87,88,1,0,0,0,88,86,1,0,
  	0,0,88,89,1,0,0,0,89,97,1,0,0,0,90,92,7,0,0,0,91,90,1,0,0,0,92,93,1,0,
  	0,0,93,91,1,0,0,0,93,94,1,0,0,0,94,95,1,0,0,0,95,97,5,46,0,0,96,81,1,
  	0,0,0,96,91,1,0,0,0,97,107,1,0,0,0,98,100,7,1,0,0,99,101,7,2,0,0,100,
  	99,1,0,0,0,100,101,1,0,0,0,101,103,1,0,0,0,102,104,7,0,0,0,103,102,1,
  	0,0,0,104,105,1,0,0,0,105,103,1,0,0,0,105,106,1,0,0,0,106,108,1,0,0,0,
  	107,98,1,0,0,0,107,108,1,0,0,0,108,124,1,0,0,0,109,111,7,0,0,0,110,109,
  	1,0,0,0,111,112,1,0,0,0,112,110,1,0,0,0,112,113,1,0,0,0,113,114,1,0,0,
  	0,114,116,7,1,0,0,115,117,7,2,0,0,116,115,1,0,0,0,116,117,1,0,0,0,117,
  	119,1,0,0,0,118,120,7,0,0,0,119,118,1,0,0,0,120,121,1,0,0,0,121,119,1,
  	0,0,0,121,122,1,0,0,0,122,124,1,0,0,0,123,96,1,0,0,0,123,110,1,0,0,0,
  	124,125,1,0,0,0,125,126,6,1,1,0,126,4,1,0,0,0,127,129,3,7,3,0,128,130,
  	3,9,4,0,129,128,1,0,0,0,129,130,1,0,0,0,130,134,1,0,0,0,131,133,7,2,0,
  	0,132,131,1,0,0,0,133,136,1,0,0,0,134,132,1,0,0,0,134,135,1,0,0,0,135,
  	137,1,0,0,0,136,134,1,0,0,0,137,150,3,1,0,0,138,140,7,2,0,0,139,138,1,
  	0,0,0,140,143,1,0,0,0,141,139,1,0,0,0,141,142,1,0,0,0,142,146,1,0,0,0,
  	143,141,1,0,0,0,144,147,3,1,0,0,145,147,3,11,5,0,146,144,1,0,0,0,146,
  	145,1,0,0,0,147,148,1,0,0,0,148,149,5,116,0,0,149,151,1,0,0,0,150,141,
  	1,0,0,0,150,151,1,0,0,0,151,152,1,0,0,0,152,153,6,2,2,0,153,6,1,0,0,0,
  	154,156,7,3,0,0,155,154,1,0,0,0,156,8,1,0,0,0,157,159,7,4,0,0,158,157,
  	1,0,0,0,159,160,1,0,0,0,160,158,1,0,0,0,160,161,1,0,0,0,161,10,1,0,0,
  	0,162,163,3,1,0,0,163,167,5,47,0,0,164,166,7,2,0,0,165,164,1,0,0,0,166,
  	169,1,0,0,0,167,165,1,0,0,0,167,168,1,0,0,0,168,170,1,0,0,0,169,167,1,
  	0,0,0,170,171,3,1,0,0,171,12,1,0,0,0,172,173,5,105,0,0,173,174,5,102,
  	0,0,174,175,1,0,0,0,175,176,6,6,3,0,176,14,1,0,0,0,177,178,5,116,0,0,
  	178,179,5,104,0,0,179,180,5,101,0,0,180,181,5,110,0,0,181,182,1,0,0,0,
  	182,183,6,7,4,0,183,16,1,0,0,0,184,185,5,101,0,0,185,186,5,108,0,0,186,
  	187,5,115,0,0,187,188,5,101,0,0,188,189,1,0,0,0,189,190,6,8,5,0,190,18,
  	1,0,0,0,191,192,5,102,0,0,192,193,5,111,0,0,193,194,5,114,0,0,194,195,
  	1,0,0,0,195,196,6,9,6,0,196,20,1,0,0,0,197,198,5,100,0,0,198,199,5,111,
  	0,0,199,200,1,0,0,0,200,201,6,10,7,0,201,22,1,0,0,0,202,203,5,115,0,0,
  	203,204,5,105,0,0,204,215,5,110,0,0,205,206,5,99,0,0,206,207,5,111,0,
  	0,207,215,5,115,0,0,208,209,5,115,0,0,209,210,5,113,0,0,210,211,5,114,
  	0,0,211,212,5,116,0,0,212,213,1,0,0,0,213,215,6,11,8,0,214,202,1,0,0,
  	0,214,205,1,0,0,0,214,208,1,0,0,0,215,24,1,0,0,0,216,217,5,36,0,0,217,
  	219,7,5,0,0,218,220,7,0,0,0,219,218,1,0,0,0,220,221,1,0,0,0,221,219,1,
  	0,0,0,221,222,1,0,0,0,222,223,1,0,0,0,223,224,6,12,9,0,224,26,1,0,0,0,
  	225,233,7,6,0,0,226,228,7,7,0,0,227,226,1,0,0,0,228,231,1,0,0,0,229,227,
  	1,0,0,0,229,230,1,0,0,0,230,232,1,0,0,0,231,229,1,0,0,0,232,234,7,8,0,
  	0,233,229,1,0,0,0,233,234,1,0,0,0,234,235,1,0,0,0,235,236,6,13,10,0,236,
  	28,1,0,0,0,237,238,5,35,0,0,238,246,7,6,0,0,239,241,7,7,0,0,240,239,1,
  	0,0,0,241,244,1,0,0,0,242,240,1,0,0,0,242,243,1,0,0,0,243,245,1,0,0,0,
  	244,242,1,0,0,0,245,247,7,8,0,0,246,242,1,0,0,0,246,247,1,0,0,0,247,248,
  	1,0,0,0,248,249,6,14,11,0,249,30,1,0,0,0,250,251,5,36,0,0,251,259,7,6,
  	0,0,252,254,7,7,0,0,253,252,1,0,0,0,254,257,1,0,0,0,255,253,1,0,0,0,255,
  	256,1,0,0,0,256,258,1,0,0,0,257,255,1,0,0,0,258,260,7,8,0,0,259,255,1,
  	0,0,0,259,260,1,0,0,0,260,261,1,0,0,0,261,262,6,15,12,0,262,32,1,0,0,
  	0,263,264,5,91,0,0,264,265,6,16,13,0,265,34,1,0,0,0,266,267,5,93,0,0,
  	267,268,6,17,14,0,268,36,1,0,0,0,269,270,5,41,0,0,270,271,6,18,15,0,271,
  	38,1,0,0,0,272,273,5,58,0,0,273,274,6,19,16,0,274,40,1,0,0,0,275,276,
  	5,46,0,0,276,277,6,20,17,0,277,42,1,0,0,0,278,279,5,59,0,0,279,280,6,
  	21,18,0,280,44,1,0,0,0,281,282,5,61,0,0,282,283,6,22,19,0,283,46,1,0,
  	0,0,284,285,5,10,0,0,285,286,6,23,20,0,286,48,1,0,0,0,287,288,7,9,0,0,
  	288,289,6,24,21,0,289,290,1,0,0,0,290,291,6,24,22,0,291,50,1,0,0,0,292,
  	293,5,42,0,0,293,294,5,42,0,0,294,295,1,0,0,0,295,296,6,25,23,0,296,52,
  	1,0,0,0,297,298,5,42,0,0,298,299,6,26,24,0,299,54,1,0,0,0,300,301,5,47,
  	0,0,301,302,5,47,0,0,302,303,1,0,0,0,303,304,6,27,25,0,304,56,1,0,0,0,
  	305,306,5,47,0,0,306,307,6,28,26,0,307,58,1,0,0,0,308,309,4,29,0,0,309,
  	310,5,43,0,0,310,311,6,29,27,0,311,60,1,0,0,0,312,313,5,43,0,0,313,314,
  	6,30,28,0,314,62,1,0,0,0,315,316,4,31,1,0,316,317,5,45,0,0,317,318,6,
  	31,29,0,318,64,1,0,0,0,319,320,5,45,0,0,320,321,6,32,30,0,321,66,1,0,
  	0,0,322,323,4,33,2,0,323,324,5,40,0,0,324,325,6,33,31,0,325,68,1,0,0,
  	0,326,327,4,34,3,0,327,328,5,40,0,0,328,329,6,34,32,0,329,70,1,0,0,0,
  	29,0,74,81,88,93,96,100,105,107,112,116,121,123,129,134,141,146,150,155,
  	160,167,214,221,229,233,242,246,255,259,33,1,0,0,1,1,1,1,2,2,1,6,3,1,
  	7,4,1,8,5,1,9,6,1,10,7,1,11,8,1,12,9,1,13,10,1,14,11,1,15,12,1,16,13,
  	1,17,14,1,18,15,1,19,16,1,20,17,1,21,18,1,22,19,1,23,20,1,24,21,0,1,0,
  	1,25,22,1,26,23,1,27,24,1,28,25,1,29,26,1,30,27,1,31,28,1,32,29,1,33,
  	30,1,34,31
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
    case 2: UPITCHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 6: IFAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 7: THENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 8: ELSEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 9: FORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 10: DOAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 11: FUNCTIONAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: INLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: GLOBALVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: PATCHERVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: LOCALVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: PUSHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 17: POPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 18: CLOSEDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 19: NTHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 20: KEYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 21: NULLIFYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 22: ASSIGNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 23: EOLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 24: WHITESPACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 25: POWAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 26: TIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 27: DIVDIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 28: DIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 29: PLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 30: UPLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 31: MINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 32: UMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 33: OPENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 34: PARAMSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool bellLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 29: return PLUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 31: return MINUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 33: return OPENSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 34: return PARAMSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

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

void bellLexer::UPITCHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2:  std::cout << "PITCH\n"; noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::IFAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::THENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ELSEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::FORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DOAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 7:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::FUNCTIONAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 8:  noParams = noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::INLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 9:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::GLOBALVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 10:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PATCHERVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 11:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::LOCALVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 12:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PUSHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 13:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::POPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 14:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::CLOSEDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 15:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::NTHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 16:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::KEYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 17:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NULLIFYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 18:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ASSIGNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 19:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::EOLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 20:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::WHITESPACEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 21:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::POWAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::TIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVDIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 25:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 26:  post("plus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UPLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 27:  post("uplus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::MINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 28:  post("minus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 29:  post("uminus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::OPENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 30:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PARAMSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 31:  noParams = true; noUnary = false;  break;

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
