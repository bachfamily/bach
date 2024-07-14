 
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
      "LOCALVAR", "NAMEDPARAM", "ID", "PUSH", "POP", "CLOSED", "NTH", "KEY", 
      "NULLIFY", "ASSIGN", "WHITESPACE", "NEWATOM", "POW", "TIMES", "DIVDIV", 
      "DIV", "PLUS", "UPLUS", "MINUS", "UMINUS", "OPEN", "PARAMS", "ANYTHING"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,34,330,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,1,0,4,0,79,8,0,11,0,12,0,80,1,0,1,0,1,1,5,1,
  	86,8,1,10,1,12,1,89,9,1,1,1,1,1,4,1,93,8,1,11,1,12,1,94,1,1,4,1,98,8,
  	1,11,1,12,1,99,1,1,3,1,103,8,1,1,1,1,1,3,1,107,8,1,1,1,4,1,110,8,1,11,
  	1,12,1,111,3,1,114,8,1,1,1,4,1,117,8,1,11,1,12,1,118,1,1,1,1,3,1,123,
  	8,1,1,1,4,1,126,8,1,11,1,12,1,127,3,1,130,8,1,1,1,1,1,1,2,1,2,3,2,136,
  	8,2,1,2,5,2,139,8,2,10,2,12,2,142,9,2,1,2,1,2,5,2,146,8,2,10,2,12,2,149,
  	9,2,1,2,1,2,3,2,153,8,2,1,2,1,2,3,2,157,8,2,1,2,1,2,1,3,3,3,162,8,3,1,
  	4,4,4,165,8,4,11,4,12,4,166,1,5,1,5,1,5,5,5,172,8,5,10,5,12,5,175,9,5,
  	1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,
  	8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,221,8,11,1,
  	12,1,12,1,12,4,12,226,8,12,11,12,12,12,227,1,12,1,12,1,13,1,13,1,13,1,
  	14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,17,1,17,5,
  	17,249,8,17,10,17,12,17,252,9,17,1,17,3,17,255,8,17,1,18,1,18,1,18,1,
  	19,1,19,1,19,1,20,1,20,1,20,1,21,1,21,1,21,1,22,1,22,1,22,1,23,1,23,1,
  	23,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,26,1,26,1,26,1,26,1,26,1,
  	27,1,27,1,27,1,27,1,27,1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,30,1,
  	30,1,30,1,31,1,31,1,31,1,31,1,32,1,32,1,32,1,33,1,33,1,33,1,33,1,34,1,
  	34,1,34,1,35,1,35,1,35,1,35,1,36,1,36,1,36,1,36,1,37,4,37,327,8,37,11,
  	37,12,37,328,1,328,0,38,1,1,3,2,5,3,7,0,9,0,11,0,13,4,15,5,17,6,19,7,
  	21,8,23,9,25,10,27,11,29,12,31,13,33,14,35,0,37,15,39,16,41,17,43,18,
  	45,19,47,20,49,21,51,22,53,23,55,24,57,25,59,26,61,27,63,28,65,29,67,
  	30,69,31,71,32,73,33,75,34,1,0,11,1,0,48,57,2,0,69,69,101,101,2,0,43,
  	43,45,45,2,0,65,71,97,103,7,0,35,35,94,94,98,98,100,100,113,113,118,118,
  	120,120,2,0,108,108,120,120,2,0,65,90,97,122,4,0,48,57,65,90,95,95,97,
  	122,3,0,48,57,65,90,97,122,3,0,9,10,13,13,32,32,1,0,1,1,350,0,1,1,0,0,
  	0,0,3,1,0,0,0,0,5,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,
  	1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,
  	0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,
  	0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,
  	1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,
  	0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,
  	0,75,1,0,0,0,1,78,1,0,0,0,3,129,1,0,0,0,5,133,1,0,0,0,7,161,1,0,0,0,9,
  	164,1,0,0,0,11,168,1,0,0,0,13,178,1,0,0,0,15,183,1,0,0,0,17,190,1,0,0,
  	0,19,197,1,0,0,0,21,203,1,0,0,0,23,220,1,0,0,0,25,222,1,0,0,0,27,231,
  	1,0,0,0,29,234,1,0,0,0,31,238,1,0,0,0,33,242,1,0,0,0,35,246,1,0,0,0,37,
  	256,1,0,0,0,39,259,1,0,0,0,41,262,1,0,0,0,43,265,1,0,0,0,45,268,1,0,0,
  	0,47,271,1,0,0,0,49,274,1,0,0,0,51,277,1,0,0,0,53,282,1,0,0,0,55,287,
  	1,0,0,0,57,292,1,0,0,0,59,295,1,0,0,0,61,300,1,0,0,0,63,303,1,0,0,0,65,
  	307,1,0,0,0,67,310,1,0,0,0,69,314,1,0,0,0,71,317,1,0,0,0,73,321,1,0,0,
  	0,75,326,1,0,0,0,77,79,7,0,0,0,78,77,1,0,0,0,79,80,1,0,0,0,80,78,1,0,
  	0,0,80,81,1,0,0,0,81,82,1,0,0,0,82,83,6,0,0,0,83,2,1,0,0,0,84,86,7,0,
  	0,0,85,84,1,0,0,0,86,89,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,90,1,0,
  	0,0,89,87,1,0,0,0,90,92,5,46,0,0,91,93,7,0,0,0,92,91,1,0,0,0,93,94,1,
  	0,0,0,94,92,1,0,0,0,94,95,1,0,0,0,95,103,1,0,0,0,96,98,7,0,0,0,97,96,
  	1,0,0,0,98,99,1,0,0,0,99,97,1,0,0,0,99,100,1,0,0,0,100,101,1,0,0,0,101,
  	103,5,46,0,0,102,87,1,0,0,0,102,97,1,0,0,0,103,113,1,0,0,0,104,106,7,
  	1,0,0,105,107,7,2,0,0,106,105,1,0,0,0,106,107,1,0,0,0,107,109,1,0,0,0,
  	108,110,7,0,0,0,109,108,1,0,0,0,110,111,1,0,0,0,111,109,1,0,0,0,111,112,
  	1,0,0,0,112,114,1,0,0,0,113,104,1,0,0,0,113,114,1,0,0,0,114,130,1,0,0,
  	0,115,117,7,0,0,0,116,115,1,0,0,0,117,118,1,0,0,0,118,116,1,0,0,0,118,
  	119,1,0,0,0,119,120,1,0,0,0,120,122,7,1,0,0,121,123,7,2,0,0,122,121,1,
  	0,0,0,122,123,1,0,0,0,123,125,1,0,0,0,124,126,7,0,0,0,125,124,1,0,0,0,
  	126,127,1,0,0,0,127,125,1,0,0,0,127,128,1,0,0,0,128,130,1,0,0,0,129,102,
  	1,0,0,0,129,116,1,0,0,0,130,131,1,0,0,0,131,132,6,1,1,0,132,4,1,0,0,0,
  	133,135,3,7,3,0,134,136,3,9,4,0,135,134,1,0,0,0,135,136,1,0,0,0,136,140,
  	1,0,0,0,137,139,7,2,0,0,138,137,1,0,0,0,139,142,1,0,0,0,140,138,1,0,0,
  	0,140,141,1,0,0,0,141,143,1,0,0,0,142,140,1,0,0,0,143,156,3,1,0,0,144,
  	146,7,2,0,0,145,144,1,0,0,0,146,149,1,0,0,0,147,145,1,0,0,0,147,148,1,
  	0,0,0,148,152,1,0,0,0,149,147,1,0,0,0,150,153,3,1,0,0,151,153,3,11,5,
  	0,152,150,1,0,0,0,152,151,1,0,0,0,153,154,1,0,0,0,154,155,5,116,0,0,155,
  	157,1,0,0,0,156,147,1,0,0,0,156,157,1,0,0,0,157,158,1,0,0,0,158,159,6,
  	2,2,0,159,6,1,0,0,0,160,162,7,3,0,0,161,160,1,0,0,0,162,8,1,0,0,0,163,
  	165,7,4,0,0,164,163,1,0,0,0,165,166,1,0,0,0,166,164,1,0,0,0,166,167,1,
  	0,0,0,167,10,1,0,0,0,168,169,3,1,0,0,169,173,5,47,0,0,170,172,7,2,0,0,
  	171,170,1,0,0,0,172,175,1,0,0,0,173,171,1,0,0,0,173,174,1,0,0,0,174,176,
  	1,0,0,0,175,173,1,0,0,0,176,177,3,1,0,0,177,12,1,0,0,0,178,179,5,105,
  	0,0,179,180,5,102,0,0,180,181,1,0,0,0,181,182,6,6,3,0,182,14,1,0,0,0,
  	183,184,5,116,0,0,184,185,5,104,0,0,185,186,5,101,0,0,186,187,5,110,0,
  	0,187,188,1,0,0,0,188,189,6,7,4,0,189,16,1,0,0,0,190,191,5,101,0,0,191,
  	192,5,108,0,0,192,193,5,115,0,0,193,194,5,101,0,0,194,195,1,0,0,0,195,
  	196,6,8,5,0,196,18,1,0,0,0,197,198,5,102,0,0,198,199,5,111,0,0,199,200,
  	5,114,0,0,200,201,1,0,0,0,201,202,6,9,6,0,202,20,1,0,0,0,203,204,5,100,
  	0,0,204,205,5,111,0,0,205,206,1,0,0,0,206,207,6,10,7,0,207,22,1,0,0,0,
  	208,209,5,115,0,0,209,210,5,105,0,0,210,221,5,110,0,0,211,212,5,99,0,
  	0,212,213,5,111,0,0,213,221,5,115,0,0,214,215,5,115,0,0,215,216,5,113,
  	0,0,216,217,5,114,0,0,217,218,5,116,0,0,218,219,1,0,0,0,219,221,6,11,
  	8,0,220,208,1,0,0,0,220,211,1,0,0,0,220,214,1,0,0,0,221,24,1,0,0,0,222,
  	223,5,36,0,0,223,225,7,5,0,0,224,226,7,0,0,0,225,224,1,0,0,0,226,227,
  	1,0,0,0,227,225,1,0,0,0,227,228,1,0,0,0,228,229,1,0,0,0,229,230,6,12,
  	9,0,230,26,1,0,0,0,231,232,3,35,17,0,232,233,6,13,10,0,233,28,1,0,0,0,
  	234,235,5,35,0,0,235,236,3,35,17,0,236,237,6,14,11,0,237,30,1,0,0,0,238,
  	239,5,36,0,0,239,240,3,35,17,0,240,241,6,15,12,0,241,32,1,0,0,0,242,243,
  	5,64,0,0,243,244,3,35,17,0,244,245,6,16,13,0,245,34,1,0,0,0,246,254,7,
  	6,0,0,247,249,7,7,0,0,248,247,1,0,0,0,249,252,1,0,0,0,250,248,1,0,0,0,
  	250,251,1,0,0,0,251,253,1,0,0,0,252,250,1,0,0,0,253,255,7,8,0,0,254,250,
  	1,0,0,0,254,255,1,0,0,0,255,36,1,0,0,0,256,257,5,91,0,0,257,258,6,18,
  	14,0,258,38,1,0,0,0,259,260,5,93,0,0,260,261,6,19,15,0,261,40,1,0,0,0,
  	262,263,5,41,0,0,263,264,6,20,16,0,264,42,1,0,0,0,265,266,5,58,0,0,266,
  	267,6,21,17,0,267,44,1,0,0,0,268,269,5,46,0,0,269,270,6,22,18,0,270,46,
  	1,0,0,0,271,272,5,59,0,0,272,273,6,23,19,0,273,48,1,0,0,0,274,275,5,61,
  	0,0,275,276,6,24,20,0,276,50,1,0,0,0,277,278,7,9,0,0,278,279,6,25,21,
  	0,279,280,1,0,0,0,280,281,6,25,22,0,281,52,1,0,0,0,282,283,7,10,0,0,283,
  	284,6,26,23,0,284,285,1,0,0,0,285,286,6,26,22,0,286,54,1,0,0,0,287,288,
  	5,42,0,0,288,289,5,42,0,0,289,290,1,0,0,0,290,291,6,27,24,0,291,56,1,
  	0,0,0,292,293,5,42,0,0,293,294,6,28,25,0,294,58,1,0,0,0,295,296,5,47,
  	0,0,296,297,5,47,0,0,297,298,1,0,0,0,298,299,6,29,26,0,299,60,1,0,0,0,
  	300,301,5,47,0,0,301,302,6,30,27,0,302,62,1,0,0,0,303,304,4,31,0,0,304,
  	305,5,43,0,0,305,306,6,31,28,0,306,64,1,0,0,0,307,308,5,43,0,0,308,309,
  	6,32,29,0,309,66,1,0,0,0,310,311,4,33,1,0,311,312,5,45,0,0,312,313,6,
  	33,30,0,313,68,1,0,0,0,314,315,5,45,0,0,315,316,6,34,31,0,316,70,1,0,
  	0,0,317,318,4,35,2,0,318,319,5,40,0,0,319,320,6,35,32,0,320,72,1,0,0,
  	0,321,322,4,36,3,0,322,323,5,40,0,0,323,324,6,36,33,0,324,74,1,0,0,0,
  	325,327,9,0,0,0,326,325,1,0,0,0,327,328,1,0,0,0,328,329,1,0,0,0,328,326,
  	1,0,0,0,329,76,1,0,0,0,26,0,80,87,94,99,102,106,111,113,118,122,127,129,
  	135,140,147,152,156,161,166,173,220,227,250,254,328,34,1,0,0,1,1,1,1,
  	2,2,1,6,3,1,7,4,1,8,5,1,9,6,1,10,7,1,11,8,1,12,9,1,13,10,1,14,11,1,15,
  	12,1,16,13,1,18,14,1,19,15,1,20,16,1,21,17,1,22,18,1,23,19,1,24,20,1,
  	25,21,0,1,0,1,26,22,1,27,23,1,28,24,1,29,25,1,30,26,1,31,27,1,32,28,1,
  	33,29,1,34,30,1,35,31,1,36,32
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
    case 16: NAMEDPARAMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 18: PUSHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 19: POPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 20: CLOSEDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 21: NTHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 22: KEYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 23: NULLIFYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 24: ASSIGNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 25: WHITESPACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 26: NEWATOMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 27: POWAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 28: TIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 29: DIVDIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 30: DIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 31: PLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 32: UPLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 33: MINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 34: UMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 35: OPENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 36: PARAMSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool bellLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 31: return PLUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 33: return MINUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 35: return OPENSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 36: return PARAMSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

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

void bellLexer::NAMEDPARAMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 13:  noParams = true; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PUSHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 14:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::POPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 15:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::CLOSEDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 16:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::NTHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 17:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::KEYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 18:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NULLIFYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 19:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ASSIGNAction(antlr4::RuleContext *context, size_t actionIndex) {
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

void bellLexer::NEWATOMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  noParams = true; noUnary = false; (*codeac)++;  break;

  default:
    break;
  }
}

void bellLexer::POWAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::TIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVDIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 25:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 26:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 27:  post("plus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UPLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 28:  post("uplus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::MINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 29:  post("minus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 30:  post("uminus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::OPENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 31:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PARAMSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 32:  noParams = true; noUnary = false;  break;

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
