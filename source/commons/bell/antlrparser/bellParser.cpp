
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
      "everything", "program", "sequence", "nullified", "whileloop", "funcall", 
      "item", "var", "lvalueSpecs", "lvalue", "fakeLvalue", "expr", "assignment", 
      "conditional", "listEnd", "list"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "'null'", "'nil'", "'if'", "'then'", "'else'", 
      "'while'", "'for'", "'do'", "'collect'", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "'['", "']'", "')'", "':'", "'::'", "'.'", 
      "':='", "'::='", "';'", "'='", "", "", "'**'", "'**='", "'*'", "'*='", 
      "'//'", "'//='", "'/'", "'/='", "", "", "", "'+='", "'+'", "", "'-='", 
      "'-'", "'=='", "'!='", "'!'", "'~'", "'<'", "'>'", "'<='", "'>='", 
      "'&'", "'&='", "'^'", "'^='", "'|'", "'|='", "'&&'", "'&&&'", "'&&='", 
      "'&&&='", "'^^'", "'^^='", "'||'", "'||='", "'|||'", "'|||='", "'<<'", 
      "'<<='", "'>>'", "'>>='", "'...'", "':*'", "':*='", "'.='", "'_='", 
      "'!_='"
    },
    std::vector<std::string>{
      "", "UINT", "UFLOAT", "UPITCH", "BTSYMBOL", "DQSYMBOL", "SQSYMBOL", 
      "BACHNULL", "BACHNIL", "IF", "THEN", "ELSE", "WHILE", "FOR", "DO", 
      "COLLECT", "FUNCTION", "INLET", "INTINLET", "RATINLET", "FLOATINLET", 
      "PITCHINLET", "OUTLET", "DIRINLET", "DIROUTLET", "GLOBALVAR", "PATCHERVAR", 
      "LOCALVAR", "NAMEDPARAM", "PUSH", "POP", "CLOSED", "NTH", "PICK", 
      "KEY", "ANTH", "APICK", "NULLIFY", "ASSIGN", "WHITESPACE", "NEWATOM", 
      "POW", "APOW", "TIMES", "ATIMES", "DIVDIV", "ADIVDIV", "DIV", "ADIV", 
      "REM", "AREM", "PLUS", "APLUS", "UPLUS", "MINUS", "AMINUS", "UMINUS", 
      "EQUAL", "NEQ", "LOGNOT", "BITNOT", "LT", "GT", "LEQ", "GEQ", "BITAND", 
      "ABITAND", "BITXOR", "ABITXOR", "BITOR", "ABITOR", "LOGAND", "LOGANDEXT", 
      "ALOGAND", "ALOGANDEXT", "LOGXOR", "ALOGXOR", "LOGOR", "ALOGOR", "LOGOREXT", 
      "ALOGOREXT", "LSHIFT", "ALSHIFT", "RSHIFT", "ARSHIFT", "RANGE", "REPEAT", 
      "AREPEAT", "AAPPLY", "ACONCAT", "ARCONCAT", "OPEN", "PARAMS", "ANYTHING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,93,288,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,43,8,1,1,2,1,
  	2,4,2,47,8,2,11,2,12,2,48,1,2,3,2,52,8,2,3,2,54,8,2,1,3,1,3,4,3,58,8,
  	3,11,3,12,3,59,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,90,8,6,
  	1,7,1,7,1,7,3,7,95,8,7,1,8,1,8,1,8,1,8,3,8,101,8,8,4,8,103,8,8,11,8,12,
  	8,104,1,8,1,8,1,8,1,8,3,8,111,8,8,5,8,113,8,8,10,8,12,8,116,9,8,1,8,1,
  	8,3,8,120,8,8,1,9,1,9,3,9,124,8,9,1,10,1,10,1,10,1,11,1,11,1,11,1,11,
  	3,11,133,8,11,1,11,1,11,1,11,4,11,138,8,11,11,11,12,11,139,1,11,1,11,
  	3,11,144,8,11,1,11,1,11,1,11,3,11,149,8,11,3,11,151,8,11,1,11,1,11,1,
  	11,1,11,3,11,157,8,11,1,11,1,11,1,11,1,11,3,11,163,8,11,1,11,1,11,1,11,
  	1,11,3,11,169,8,11,1,11,1,11,1,11,1,11,3,11,175,8,11,1,11,1,11,1,11,1,
  	11,3,11,181,8,11,1,11,1,11,1,11,1,11,3,11,187,8,11,1,11,1,11,1,11,1,11,
  	3,11,193,8,11,1,11,1,11,1,11,1,11,3,11,199,8,11,1,11,1,11,1,11,1,11,3,
  	11,205,8,11,1,11,1,11,1,11,1,11,3,11,211,8,11,1,11,1,11,1,11,1,11,3,11,
  	217,8,11,1,11,1,11,1,11,1,11,3,11,223,8,11,1,11,1,11,1,11,1,11,3,11,229,
  	8,11,1,11,1,11,1,11,1,11,3,11,235,8,11,1,11,1,11,1,11,1,11,3,11,241,8,
  	11,5,11,243,8,11,10,11,12,11,246,9,11,1,12,1,12,1,12,1,12,1,12,1,12,1,
  	12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,262,8,12,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,276,8,13,1,14,1,14,1,
  	14,3,14,281,8,14,1,15,4,15,284,8,15,11,15,12,15,285,1,15,0,1,22,16,0,
  	2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,0,14,1,0,14,15,1,0,5,6,1,0,17,
  	21,2,0,53,53,56,56,1,0,59,60,4,0,43,43,45,45,47,47,49,49,2,0,51,51,54,
  	54,2,0,81,81,83,83,1,0,57,58,1,0,61,64,1,0,71,72,2,0,77,77,79,79,19,0,
  	35,35,38,38,42,42,44,44,46,46,48,48,50,50,52,52,55,55,66,66,68,68,70,
  	70,73,74,76,76,78,78,80,80,82,82,84,84,89,90,18,0,38,38,42,42,44,44,46,
  	46,48,48,50,50,52,52,55,55,66,66,68,68,70,70,73,74,76,76,78,78,80,80,
  	82,82,84,84,89,90,343,0,32,1,0,0,0,2,42,1,0,0,0,4,53,1,0,0,0,6,55,1,0,
  	0,0,8,61,1,0,0,0,10,66,1,0,0,0,12,89,1,0,0,0,14,94,1,0,0,0,16,119,1,0,
  	0,0,18,121,1,0,0,0,20,125,1,0,0,0,22,150,1,0,0,0,24,261,1,0,0,0,26,275,
  	1,0,0,0,28,280,1,0,0,0,30,283,1,0,0,0,32,33,3,2,1,0,33,1,1,0,0,0,34,43,
  	5,0,0,1,35,36,3,4,2,0,36,37,5,0,0,1,37,43,1,0,0,0,38,39,3,4,2,0,39,40,
  	5,28,0,0,40,43,1,0,0,0,41,43,5,28,0,0,42,34,1,0,0,0,42,35,1,0,0,0,42,
  	38,1,0,0,0,42,41,1,0,0,0,43,3,1,0,0,0,44,54,3,30,15,0,45,47,3,6,3,0,46,
  	45,1,0,0,0,47,48,1,0,0,0,48,46,1,0,0,0,48,49,1,0,0,0,49,51,1,0,0,0,50,
  	52,3,30,15,0,51,50,1,0,0,0,51,52,1,0,0,0,52,54,1,0,0,0,53,44,1,0,0,0,
  	53,46,1,0,0,0,54,5,1,0,0,0,55,57,3,30,15,0,56,58,5,37,0,0,57,56,1,0,0,
  	0,58,59,1,0,0,0,59,57,1,0,0,0,59,60,1,0,0,0,60,7,1,0,0,0,61,62,5,12,0,
  	0,62,63,3,4,2,0,63,64,7,0,0,0,64,65,3,30,15,0,65,9,1,0,0,0,66,67,5,16,
  	0,0,67,68,5,92,0,0,68,69,3,4,2,0,69,70,5,31,0,0,70,11,1,0,0,0,71,90,5,
  	1,0,0,72,90,5,2,0,0,73,90,5,3,0,0,74,90,5,4,0,0,75,90,7,1,0,0,76,90,7,
  	2,0,0,77,90,5,23,0,0,78,90,5,7,0,0,79,90,5,8,0,0,80,81,5,91,0,0,81,82,
  	3,4,2,0,82,83,5,31,0,0,83,90,1,0,0,0,84,85,5,29,0,0,85,86,3,4,2,0,86,
  	87,5,30,0,0,87,90,1,0,0,0,88,90,3,10,5,0,89,71,1,0,0,0,89,72,1,0,0,0,
  	89,73,1,0,0,0,89,74,1,0,0,0,89,75,1,0,0,0,89,76,1,0,0,0,89,77,1,0,0,0,
  	89,78,1,0,0,0,89,79,1,0,0,0,89,80,1,0,0,0,89,84,1,0,0,0,89,88,1,0,0,0,
  	90,13,1,0,0,0,91,95,5,27,0,0,92,95,5,26,0,0,93,95,5,25,0,0,94,91,1,0,
  	0,0,94,92,1,0,0,0,94,93,1,0,0,0,95,15,1,0,0,0,96,102,6,8,-1,0,97,100,
  	5,32,0,0,98,101,3,12,6,0,99,101,3,14,7,0,100,98,1,0,0,0,100,99,1,0,0,
  	0,101,103,1,0,0,0,102,97,1,0,0,0,103,104,1,0,0,0,104,102,1,0,0,0,104,
  	105,1,0,0,0,105,120,1,0,0,0,106,114,6,8,-1,0,107,110,5,32,0,0,108,111,
  	3,12,6,0,109,111,3,14,7,0,110,108,1,0,0,0,110,109,1,0,0,0,111,113,1,0,
  	0,0,112,107,1,0,0,0,113,116,1,0,0,0,114,112,1,0,0,0,114,115,1,0,0,0,115,
  	117,1,0,0,0,116,114,1,0,0,0,117,118,5,32,0,0,118,120,3,26,13,0,119,96,
  	1,0,0,0,119,106,1,0,0,0,120,17,1,0,0,0,121,123,3,14,7,0,122,124,3,16,
  	8,0,123,122,1,0,0,0,123,124,1,0,0,0,124,19,1,0,0,0,125,126,3,12,6,0,126,
  	127,3,16,8,0,127,21,1,0,0,0,128,132,6,11,-1,0,129,133,3,12,6,0,130,133,
  	3,14,7,0,131,133,3,28,14,0,132,129,1,0,0,0,132,130,1,0,0,0,132,131,1,
  	0,0,0,133,151,1,0,0,0,134,151,3,18,9,0,135,151,3,20,10,0,136,138,7,3,
  	0,0,137,136,1,0,0,0,138,139,1,0,0,0,139,137,1,0,0,0,139,140,1,0,0,0,140,
  	143,1,0,0,0,141,144,3,22,11,0,142,144,3,28,14,0,143,141,1,0,0,0,143,142,
  	1,0,0,0,144,151,1,0,0,0,145,148,7,4,0,0,146,149,3,22,11,0,147,149,3,28,
  	14,0,148,146,1,0,0,0,148,147,1,0,0,0,149,151,1,0,0,0,150,128,1,0,0,0,
  	150,134,1,0,0,0,150,135,1,0,0,0,150,137,1,0,0,0,150,145,1,0,0,0,151,244,
  	1,0,0,0,152,153,10,17,0,0,153,156,5,33,0,0,154,157,3,22,11,0,155,157,
  	3,28,14,0,156,154,1,0,0,0,156,155,1,0,0,0,157,243,1,0,0,0,158,159,10,
  	16,0,0,159,162,5,41,0,0,160,163,3,22,11,0,161,163,3,28,14,0,162,160,1,
  	0,0,0,162,161,1,0,0,0,163,243,1,0,0,0,164,165,10,14,0,0,165,168,7,5,0,
  	0,166,169,3,22,11,0,167,169,3,28,14,0,168,166,1,0,0,0,168,167,1,0,0,0,
  	169,243,1,0,0,0,170,171,10,13,0,0,171,174,7,6,0,0,172,175,3,22,11,0,173,
  	175,3,28,14,0,174,172,1,0,0,0,174,173,1,0,0,0,175,243,1,0,0,0,176,177,
  	10,12,0,0,177,180,7,7,0,0,178,181,3,22,11,0,179,181,3,28,14,0,180,178,
  	1,0,0,0,180,179,1,0,0,0,181,243,1,0,0,0,182,183,10,11,0,0,183,186,5,85,
  	0,0,184,187,3,22,11,0,185,187,3,28,14,0,186,184,1,0,0,0,186,185,1,0,0,
  	0,187,243,1,0,0,0,188,189,10,10,0,0,189,192,5,86,0,0,190,193,3,22,11,
  	0,191,193,3,28,14,0,192,190,1,0,0,0,192,191,1,0,0,0,193,243,1,0,0,0,194,
  	195,10,9,0,0,195,198,7,8,0,0,196,199,3,22,11,0,197,199,3,28,14,0,198,
  	196,1,0,0,0,198,197,1,0,0,0,199,243,1,0,0,0,200,201,10,8,0,0,201,204,
  	7,9,0,0,202,205,3,22,11,0,203,205,3,28,14,0,204,202,1,0,0,0,204,203,1,
  	0,0,0,205,243,1,0,0,0,206,207,10,7,0,0,207,210,5,65,0,0,208,211,3,22,
  	11,0,209,211,3,28,14,0,210,208,1,0,0,0,210,209,1,0,0,0,211,243,1,0,0,
  	0,212,213,10,6,0,0,213,216,5,67,0,0,214,217,3,22,11,0,215,217,3,28,14,
  	0,216,214,1,0,0,0,216,215,1,0,0,0,217,243,1,0,0,0,218,219,10,5,0,0,219,
  	222,5,69,0,0,220,223,3,22,11,0,221,223,3,28,14,0,222,220,1,0,0,0,222,
  	221,1,0,0,0,223,243,1,0,0,0,224,225,10,4,0,0,225,228,7,10,0,0,226,229,
  	3,22,11,0,227,229,3,28,14,0,228,226,1,0,0,0,228,227,1,0,0,0,229,243,1,
  	0,0,0,230,231,10,3,0,0,231,234,5,75,0,0,232,235,3,22,11,0,233,235,3,28,
  	14,0,234,232,1,0,0,0,234,233,1,0,0,0,235,243,1,0,0,0,236,237,10,2,0,0,
  	237,240,7,11,0,0,238,241,3,22,11,0,239,241,3,28,14,0,240,238,1,0,0,0,
  	240,239,1,0,0,0,241,243,1,0,0,0,242,152,1,0,0,0,242,158,1,0,0,0,242,164,
  	1,0,0,0,242,170,1,0,0,0,242,176,1,0,0,0,242,182,1,0,0,0,242,188,1,0,0,
  	0,242,194,1,0,0,0,242,200,1,0,0,0,242,206,1,0,0,0,242,212,1,0,0,0,242,
  	218,1,0,0,0,242,224,1,0,0,0,242,230,1,0,0,0,242,236,1,0,0,0,243,246,1,
  	0,0,0,244,242,1,0,0,0,244,245,1,0,0,0,245,23,1,0,0,0,246,244,1,0,0,0,
  	247,248,3,18,9,0,248,249,7,12,0,0,249,250,3,30,15,0,250,262,1,0,0,0,251,
  	252,3,20,10,0,252,253,7,13,0,0,253,254,3,30,15,0,254,262,1,0,0,0,255,
  	256,5,22,0,0,256,257,5,38,0,0,257,262,3,30,15,0,258,259,5,24,0,0,259,
  	260,5,38,0,0,260,262,3,30,15,0,261,247,1,0,0,0,261,251,1,0,0,0,261,255,
  	1,0,0,0,261,258,1,0,0,0,262,25,1,0,0,0,263,264,5,9,0,0,264,265,3,4,2,
  	0,265,266,5,10,0,0,266,267,3,30,15,0,267,276,1,0,0,0,268,269,5,9,0,0,
  	269,270,3,4,2,0,270,271,5,10,0,0,271,272,3,4,2,0,272,273,5,11,0,0,273,
  	274,3,30,15,0,274,276,1,0,0,0,275,263,1,0,0,0,275,268,1,0,0,0,276,27,
  	1,0,0,0,277,281,3,26,13,0,278,281,3,24,12,0,279,281,3,8,4,0,280,277,1,
  	0,0,0,280,278,1,0,0,0,280,279,1,0,0,0,281,29,1,0,0,0,282,284,3,22,11,
  	0,283,282,1,0,0,0,284,285,1,0,0,0,285,283,1,0,0,0,285,286,1,0,0,0,286,
  	31,1,0,0,0,39,42,48,51,53,59,89,94,100,104,110,114,119,123,132,139,143,
  	148,150,156,162,168,174,180,186,192,198,204,210,216,222,228,234,240,242,
  	244,261,275,280,285
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

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << bellParser::UINT)
        | (1ULL << bellParser::UFLOAT)
        | (1ULL << bellParser::UPITCH)
        | (1ULL << bellParser::BTSYMBOL)
        | (1ULL << bellParser::DQSYMBOL)
        | (1ULL << bellParser::SQSYMBOL)
        | (1ULL << bellParser::BACHNULL)
        | (1ULL << bellParser::BACHNIL)
        | (1ULL << bellParser::IF)
        | (1ULL << bellParser::WHILE)
        | (1ULL << bellParser::FUNCTION)
        | (1ULL << bellParser::INLET)
        | (1ULL << bellParser::INTINLET)
        | (1ULL << bellParser::RATINLET)
        | (1ULL << bellParser::FLOATINLET)
        | (1ULL << bellParser::PITCHINLET)
        | (1ULL << bellParser::OUTLET)
        | (1ULL << bellParser::DIRINLET)
        | (1ULL << bellParser::DIROUTLET)
        | (1ULL << bellParser::GLOBALVAR)
        | (1ULL << bellParser::PATCHERVAR)
        | (1ULL << bellParser::LOCALVAR)
        | (1ULL << bellParser::PUSH)
        | (1ULL << bellParser::UPLUS)
        | (1ULL << bellParser::UMINUS)
        | (1ULL << bellParser::LOGNOT)
        | (1ULL << bellParser::BITNOT))) != 0) || _la == bellParser::OPEN) {
        setState(50);
        list();
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
    setState(55);
    list();
    setState(57); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(56);
      match(bellParser::NULLIFY);
      setState(59); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == bellParser::NULLIFY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileloopContext ------------------------------------------------------------------

bellParser::WhileloopContext::WhileloopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bellParser::WhileloopContext::WHILE() {
  return getToken(bellParser::WHILE, 0);
}

bellParser::SequenceContext* bellParser::WhileloopContext::sequence() {
  return getRuleContext<bellParser::SequenceContext>(0);
}

bellParser::ListContext* bellParser::WhileloopContext::list() {
  return getRuleContext<bellParser::ListContext>(0);
}

tree::TerminalNode* bellParser::WhileloopContext::DO() {
  return getToken(bellParser::DO, 0);
}

tree::TerminalNode* bellParser::WhileloopContext::COLLECT() {
  return getToken(bellParser::COLLECT, 0);
}


size_t bellParser::WhileloopContext::getRuleIndex() const {
  return bellParser::RuleWhileloop;
}


std::any bellParser::WhileloopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitWhileloop(this);
  else
    return visitor->visitChildren(this);
}

bellParser::WhileloopContext* bellParser::whileloop() {
  WhileloopContext *_localctx = _tracker.createInstance<WhileloopContext>(_ctx, getState());
  enterRule(_localctx, 8, bellParser::RuleWhileloop);
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
    setState(61);
    match(bellParser::WHILE);
    setState(62);
    sequence();
    setState(63);
    antlrcpp::downCast<WhileloopContext *>(_localctx)->kind = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == bellParser::DO

    || _la == bellParser::COLLECT)) {
      antlrcpp::downCast<WhileloopContext *>(_localctx)->kind = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(64);
    list();
   
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
  enterRule(_localctx, 10, bellParser::RuleFuncall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(bellParser::FUNCTION);
    setState(67);
    match(bellParser::PARAMS);
    setState(68);
    sequence();
    setState(69);
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
//----------------- ItemBtSymbolContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemBtSymbolContext::BTSYMBOL() {
  return getToken(bellParser::BTSYMBOL, 0);
}

bellParser::ItemBtSymbolContext::ItemBtSymbolContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemBtSymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemBtSymbol(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ItemInletContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemInletContext::INLET() {
  return getToken(bellParser::INLET, 0);
}

tree::TerminalNode* bellParser::ItemInletContext::INTINLET() {
  return getToken(bellParser::INTINLET, 0);
}

tree::TerminalNode* bellParser::ItemInletContext::FLOATINLET() {
  return getToken(bellParser::FLOATINLET, 0);
}

tree::TerminalNode* bellParser::ItemInletContext::RATINLET() {
  return getToken(bellParser::RATINLET, 0);
}

tree::TerminalNode* bellParser::ItemInletContext::PITCHINLET() {
  return getToken(bellParser::PITCHINLET, 0);
}

bellParser::ItemInletContext::ItemInletContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemInletContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemInlet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ItemDirInletContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemDirInletContext::DIRINLET() {
  return getToken(bellParser::DIRINLET, 0);
}

bellParser::ItemDirInletContext::ItemDirInletContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemDirInletContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemDirInlet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ItemNullContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemNullContext::BACHNULL() {
  return getToken(bellParser::BACHNULL, 0);
}

bellParser::ItemNullContext::ItemNullContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemNullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemNull(this);
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
//----------------- ItemNilContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemNilContext::BACHNIL() {
  return getToken(bellParser::BACHNIL, 0);
}

bellParser::ItemNilContext::ItemNilContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemNilContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemNil(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ItemQSymbolContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemQSymbolContext::DQSYMBOL() {
  return getToken(bellParser::DQSYMBOL, 0);
}

tree::TerminalNode* bellParser::ItemQSymbolContext::SQSYMBOL() {
  return getToken(bellParser::SQSYMBOL, 0);
}

bellParser::ItemQSymbolContext::ItemQSymbolContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemQSymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemQSymbol(this);
  else
    return visitor->visitChildren(this);
}
bellParser::ItemContext* bellParser::item() {
  ItemContext *_localctx = _tracker.createInstance<ItemContext>(_ctx, getState());
  enterRule(_localctx, 12, bellParser::RuleItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(89);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::UINT: {
        _localctx = _tracker.createInstance<bellParser::ItemUintContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(71);
        match(bellParser::UINT);
        break;
      }

      case bellParser::UFLOAT: {
        _localctx = _tracker.createInstance<bellParser::ItemUfloatContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(72);
        match(bellParser::UFLOAT);
        break;
      }

      case bellParser::UPITCH: {
        _localctx = _tracker.createInstance<bellParser::ItemUpitchContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(73);
        match(bellParser::UPITCH);
        break;
      }

      case bellParser::BTSYMBOL: {
        _localctx = _tracker.createInstance<bellParser::ItemBtSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(74);
        match(bellParser::BTSYMBOL);
        break;
      }

      case bellParser::DQSYMBOL:
      case bellParser::SQSYMBOL: {
        _localctx = _tracker.createInstance<bellParser::ItemQSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(75);
        _la = _input->LA(1);
        if (!(_la == bellParser::DQSYMBOL

        || _la == bellParser::SQSYMBOL)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case bellParser::INLET:
      case bellParser::INTINLET:
      case bellParser::RATINLET:
      case bellParser::FLOATINLET:
      case bellParser::PITCHINLET: {
        _localctx = _tracker.createInstance<bellParser::ItemInletContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(76);
        antlrcpp::downCast<ItemInletContext *>(_localctx)->type = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << bellParser::INLET)
          | (1ULL << bellParser::INTINLET)
          | (1ULL << bellParser::RATINLET)
          | (1ULL << bellParser::FLOATINLET)
          | (1ULL << bellParser::PITCHINLET))) != 0))) {
          antlrcpp::downCast<ItemInletContext *>(_localctx)->type = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case bellParser::DIRINLET: {
        _localctx = _tracker.createInstance<bellParser::ItemDirInletContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(77);
        match(bellParser::DIRINLET);
        break;
      }

      case bellParser::BACHNULL: {
        _localctx = _tracker.createInstance<bellParser::ItemNullContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(78);
        match(bellParser::BACHNULL);
        break;
      }

      case bellParser::BACHNIL: {
        _localctx = _tracker.createInstance<bellParser::ItemNilContext>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(79);
        match(bellParser::BACHNIL);
        break;
      }

      case bellParser::OPEN: {
        _localctx = _tracker.createInstance<bellParser::ItemSequenceContext>(_localctx);
        enterOuterAlt(_localctx, 10);
        setState(80);
        match(bellParser::OPEN);
        setState(81);
        sequence();
        setState(82);
        match(bellParser::CLOSED);
        break;
      }

      case bellParser::PUSH: {
        _localctx = _tracker.createInstance<bellParser::ItemSublistContext>(_localctx);
        enterOuterAlt(_localctx, 11);
        setState(84);
        match(bellParser::PUSH);
        setState(85);
        sequence();
        setState(86);
        match(bellParser::POP);
        break;
      }

      case bellParser::FUNCTION: {
        _localctx = _tracker.createInstance<bellParser::ItemFuncallContext>(_localctx);
        enterOuterAlt(_localctx, 12);
        setState(88);
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
  enterRule(_localctx, 14, bellParser::RuleVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(94);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::LOCALVAR: {
        _localctx = _tracker.createInstance<bellParser::VarLocalContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(91);
        match(bellParser::LOCALVAR);
        break;
      }

      case bellParser::PATCHERVAR: {
        _localctx = _tracker.createInstance<bellParser::VarPatcherContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(92);
        match(bellParser::PATCHERVAR);
        break;
      }

      case bellParser::GLOBALVAR: {
        _localctx = _tracker.createInstance<bellParser::VarGlobalContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(93);
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
  enterRule(_localctx, 16, bellParser::RuleLvalueSpecs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(119);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      ending = false;
      setState(102); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(97);
                match(bellParser::NTH);
                setState(100);
                _errHandler->sync(this);
                switch (_input->LA(1)) {
                  case bellParser::UINT:
                  case bellParser::UFLOAT:
                  case bellParser::UPITCH:
                  case bellParser::BTSYMBOL:
                  case bellParser::DQSYMBOL:
                  case bellParser::SQSYMBOL:
                  case bellParser::BACHNULL:
                  case bellParser::BACHNIL:
                  case bellParser::FUNCTION:
                  case bellParser::INLET:
                  case bellParser::INTINLET:
                  case bellParser::RATINLET:
                  case bellParser::FLOATINLET:
                  case bellParser::PITCHINLET:
                  case bellParser::DIRINLET:
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
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(104); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      ending = true;
      setState(114);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(107);
          match(bellParser::NTH);
          setState(110);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case bellParser::UINT:
            case bellParser::UFLOAT:
            case bellParser::UPITCH:
            case bellParser::BTSYMBOL:
            case bellParser::DQSYMBOL:
            case bellParser::SQSYMBOL:
            case bellParser::BACHNULL:
            case bellParser::BACHNIL:
            case bellParser::FUNCTION:
            case bellParser::INLET:
            case bellParser::INTINLET:
            case bellParser::RATINLET:
            case bellParser::FLOATINLET:
            case bellParser::PITCHINLET:
            case bellParser::DIRINLET:
            case bellParser::PUSH:
            case bellParser::OPEN: {
              setState(108);
              item();
              break;
            }

            case bellParser::GLOBALVAR:
            case bellParser::PATCHERVAR:
            case bellParser::LOCALVAR: {
              setState(109);
              var();
              break;
            }

          default:
            throw NoViableAltException(this);
          } 
        }
        setState(116);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      }

      setState(117);
      match(bellParser::NTH);

      setState(118);
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
  enterRule(_localctx, 18, bellParser::RuleLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    var();
    setState(123);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(122);
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
  enterRule(_localctx, 20, bellParser::RuleFakeLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    item();
    setState(126);
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

bellParser::ExprFakeLvalueContext::ExprFakeLvalueContext(ExprContext *ctx) { copyFrom(ctx); }


std::any bellParser::ExprFakeLvalueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitExprFakeLvalue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprUPlusMinusContext ------------------------------------------------------------------

bellParser::ExprContext* bellParser::ExprUPlusMinusContext::expr() {
  return getRuleContext<bellParser::ExprContext>(0);
}

bellParser::ListEndContext* bellParser::ExprUPlusMinusContext::listEnd() {
  return getRuleContext<bellParser::ListEndContext>(0);
}

std::vector<tree::TerminalNode *> bellParser::ExprUPlusMinusContext::UPLUS() {
  return getTokens(bellParser::UPLUS);
}

tree::TerminalNode* bellParser::ExprUPlusMinusContext::UPLUS(size_t i) {
  return getToken(bellParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> bellParser::ExprUPlusMinusContext::UMINUS() {
  return getTokens(bellParser::UMINUS);
}

tree::TerminalNode* bellParser::ExprUPlusMinusContext::UMINUS(size_t i) {
  return getToken(bellParser::UMINUS, i);
}

bellParser::ExprUPlusMinusContext::ExprUPlusMinusContext(ExprContext *ctx) { copyFrom(ctx); }


std::any bellParser::ExprUPlusMinusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitExprUPlusMinus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprSimpleContext ------------------------------------------------------------------

bellParser::ItemContext* bellParser::ExprSimpleContext::item() {
  return getRuleContext<bellParser::ItemContext>(0);
}

bellParser::VarContext* bellParser::ExprSimpleContext::var() {
  return getRuleContext<bellParser::VarContext>(0);
}

bellParser::ListEndContext* bellParser::ExprSimpleContext::listEnd() {
  return getRuleContext<bellParser::ListEndContext>(0);
}

bellParser::ExprSimpleContext::ExprSimpleContext(ExprContext *ctx) { copyFrom(ctx); }


std::any bellParser::ExprSimpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitExprSimple(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprNotContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ExprNotContext::LOGNOT() {
  return getToken(bellParser::LOGNOT, 0);
}

tree::TerminalNode* bellParser::ExprNotContext::BITNOT() {
  return getToken(bellParser::BITNOT, 0);
}

bellParser::ExprContext* bellParser::ExprNotContext::expr() {
  return getRuleContext<bellParser::ExprContext>(0);
}

bellParser::ListEndContext* bellParser::ExprNotContext::listEnd() {
  return getRuleContext<bellParser::ListEndContext>(0);
}

bellParser::ExprNotContext::ExprNotContext(ExprContext *ctx) { copyFrom(ctx); }


std::any bellParser::ExprNotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitExprNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprBinaryContext ------------------------------------------------------------------

std::vector<bellParser::ExprContext *> bellParser::ExprBinaryContext::expr() {
  return getRuleContexts<bellParser::ExprContext>();
}

bellParser::ExprContext* bellParser::ExprBinaryContext::expr(size_t i) {
  return getRuleContext<bellParser::ExprContext>(i);
}

tree::TerminalNode* bellParser::ExprBinaryContext::PICK() {
  return getToken(bellParser::PICK, 0);
}

bellParser::ListEndContext* bellParser::ExprBinaryContext::listEnd() {
  return getRuleContext<bellParser::ListEndContext>(0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::POW() {
  return getToken(bellParser::POW, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::TIMES() {
  return getToken(bellParser::TIMES, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::DIV() {
  return getToken(bellParser::DIV, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::DIVDIV() {
  return getToken(bellParser::DIVDIV, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::REM() {
  return getToken(bellParser::REM, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::PLUS() {
  return getToken(bellParser::PLUS, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::MINUS() {
  return getToken(bellParser::MINUS, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::LSHIFT() {
  return getToken(bellParser::LSHIFT, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::RSHIFT() {
  return getToken(bellParser::RSHIFT, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::RANGE() {
  return getToken(bellParser::RANGE, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::REPEAT() {
  return getToken(bellParser::REPEAT, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::EQUAL() {
  return getToken(bellParser::EQUAL, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::NEQ() {
  return getToken(bellParser::NEQ, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::LT() {
  return getToken(bellParser::LT, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::GT() {
  return getToken(bellParser::GT, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::LEQ() {
  return getToken(bellParser::LEQ, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::GEQ() {
  return getToken(bellParser::GEQ, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::BITAND() {
  return getToken(bellParser::BITAND, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::BITXOR() {
  return getToken(bellParser::BITXOR, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::BITOR() {
  return getToken(bellParser::BITOR, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::LOGAND() {
  return getToken(bellParser::LOGAND, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::LOGANDEXT() {
  return getToken(bellParser::LOGANDEXT, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::LOGXOR() {
  return getToken(bellParser::LOGXOR, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::LOGOR() {
  return getToken(bellParser::LOGOR, 0);
}

tree::TerminalNode* bellParser::ExprBinaryContext::LOGOREXT() {
  return getToken(bellParser::LOGOREXT, 0);
}

bellParser::ExprBinaryContext::ExprBinaryContext(ExprContext *ctx) { copyFrom(ctx); }


std::any bellParser::ExprBinaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitExprBinary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprLvalueContext ------------------------------------------------------------------

bellParser::LvalueContext* bellParser::ExprLvalueContext::lvalue() {
  return getRuleContext<bellParser::LvalueContext>(0);
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
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, bellParser::RuleExpr, precedence);

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
    setState(150);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprSimpleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(132);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
      case 1: {
        setState(129);
        item();
        break;
      }

      case 2: {
        setState(130);
        var();
        break;
      }

      case 3: {
        setState(131);
        listEnd();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ExprLvalueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(134);
      lvalue();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ExprFakeLvalueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(135);
      fakeLvalue();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprUPlusMinusContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(137); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(136);
                _la = _input->LA(1);
                if (!(_la == bellParser::UPLUS

                || _la == bellParser::UMINUS)) {
                _errHandler->recoverInline(this);
                }
                else {
                  _errHandler->reportMatch(this);
                  consume();
                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(139); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(143);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
      case 1: {
        setState(141);
        expr(0);
        break;
      }

      case 2: {
        setState(142);
        listEnd();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ExprNotContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(145);
      antlrcpp::downCast<ExprNotContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == bellParser::LOGNOT

      || _la == bellParser::BITNOT)) {
        antlrcpp::downCast<ExprNotContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(148);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(146);
        expr(0);
        break;
      }

      case 2: {
        setState(147);
        listEnd();
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
    _ctx->stop = _input->LT(-1);
    setState(244);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(242);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(152);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(153);
          match(bellParser::PICK);
          setState(156);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
          case 1: {
            setState(154);
            expr(0);
            break;
          }

          case 2: {
            setState(155);
            listEnd();
            break;
          }

          default:
            break;
          }
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(158);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(159);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::POW);
          setState(162);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
          case 1: {
            setState(160);
            expr(0);
            break;
          }

          case 2: {
            setState(161);
            listEnd();
            break;
          }

          default:
            break;
          }
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(164);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(165);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << bellParser::TIMES)
            | (1ULL << bellParser::DIVDIV)
            | (1ULL << bellParser::DIV)
            | (1ULL << bellParser::REM))) != 0))) {
            antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(168);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
          case 1: {
            setState(166);
            expr(0);
            break;
          }

          case 2: {
            setState(167);
            listEnd();
            break;
          }

          default:
            break;
          }
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(170);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(171);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == bellParser::PLUS

          || _la == bellParser::MINUS)) {
            antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(174);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
          case 1: {
            setState(172);
            expr(0);
            break;
          }

          case 2: {
            setState(173);
            listEnd();
            break;
          }

          default:
            break;
          }
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(176);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(177);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == bellParser::LSHIFT

          || _la == bellParser::RSHIFT)) {
            antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(180);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
          case 1: {
            setState(178);
            expr(0);
            break;
          }

          case 2: {
            setState(179);
            listEnd();
            break;
          }

          default:
            break;
          }
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(182);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(183);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::RANGE);
          setState(186);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
          case 1: {
            setState(184);
            expr(0);
            break;
          }

          case 2: {
            setState(185);
            listEnd();
            break;
          }

          default:
            break;
          }
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(188);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(189);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::REPEAT);
          setState(192);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
          case 1: {
            setState(190);
            expr(0);
            break;
          }

          case 2: {
            setState(191);
            listEnd();
            break;
          }

          default:
            break;
          }
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(194);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(195);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == bellParser::EQUAL

          || _la == bellParser::NEQ)) {
            antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(198);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
          case 1: {
            setState(196);
            expr(0);
            break;
          }

          case 2: {
            setState(197);
            listEnd();
            break;
          }

          default:
            break;
          }
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(200);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(201);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 61) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 61)) & ((1ULL << (bellParser::LT - 61))
            | (1ULL << (bellParser::GT - 61))
            | (1ULL << (bellParser::LEQ - 61))
            | (1ULL << (bellParser::GEQ - 61)))) != 0))) {
            antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(204);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
          case 1: {
            setState(202);
            expr(0);
            break;
          }

          case 2: {
            setState(203);
            listEnd();
            break;
          }

          default:
            break;
          }
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(206);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(207);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::BITAND);
          setState(210);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
          case 1: {
            setState(208);
            expr(0);
            break;
          }

          case 2: {
            setState(209);
            listEnd();
            break;
          }

          default:
            break;
          }
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(212);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(213);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::BITXOR);
          setState(216);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
          case 1: {
            setState(214);
            expr(0);
            break;
          }

          case 2: {
            setState(215);
            listEnd();
            break;
          }

          default:
            break;
          }
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(218);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(219);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::BITOR);
          setState(222);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
          case 1: {
            setState(220);
            expr(0);
            break;
          }

          case 2: {
            setState(221);
            listEnd();
            break;
          }

          default:
            break;
          }
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(224);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(225);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == bellParser::LOGAND

          || _la == bellParser::LOGANDEXT)) {
            antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(228);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
          case 1: {
            setState(226);
            expr(0);
            break;
          }

          case 2: {
            setState(227);
            listEnd();
            break;
          }

          default:
            break;
          }
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(230);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(231);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::LOGXOR);
          setState(234);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
          case 1: {
            setState(232);
            expr(0);
            break;
          }

          case 2: {
            setState(233);
            listEnd();
            break;
          }

          default:
            break;
          }
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(236);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(237);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == bellParser::LOGOR

          || _la == bellParser::LOGOREXT)) {
            antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(240);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
          case 1: {
            setState(238);
            expr(0);
            break;
          }

          case 2: {
            setState(239);
            listEnd();
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
      setState(246);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
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

bellParser::ListContext* bellParser::FakeAssignmentContext::list() {
  return getRuleContext<bellParser::ListContext>(0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ASSIGN() {
  return getToken(bellParser::ASSIGN, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::APOW() {
  return getToken(bellParser::APOW, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ATIMES() {
  return getToken(bellParser::ATIMES, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ADIVDIV() {
  return getToken(bellParser::ADIVDIV, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ADIV() {
  return getToken(bellParser::ADIV, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::AREM() {
  return getToken(bellParser::AREM, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::APLUS() {
  return getToken(bellParser::APLUS, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::AMINUS() {
  return getToken(bellParser::AMINUS, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ALOGAND() {
  return getToken(bellParser::ALOGAND, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ALOGANDEXT() {
  return getToken(bellParser::ALOGANDEXT, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ALOGXOR() {
  return getToken(bellParser::ALOGXOR, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ALOGOR() {
  return getToken(bellParser::ALOGOR, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ALOGOREXT() {
  return getToken(bellParser::ALOGOREXT, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ABITAND() {
  return getToken(bellParser::ABITAND, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ABITXOR() {
  return getToken(bellParser::ABITXOR, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ABITOR() {
  return getToken(bellParser::ABITOR, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ALSHIFT() {
  return getToken(bellParser::ALSHIFT, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ACONCAT() {
  return getToken(bellParser::ACONCAT, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ARCONCAT() {
  return getToken(bellParser::ARCONCAT, 0);
}

tree::TerminalNode* bellParser::FakeAssignmentContext::ARSHIFT() {
  return getToken(bellParser::ARSHIFT, 0);
}

bellParser::FakeAssignmentContext::FakeAssignmentContext(AssignmentContext *ctx) { copyFrom(ctx); }


std::any bellParser::FakeAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitFakeAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DirOutletAssignmentContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::DirOutletAssignmentContext::DIROUTLET() {
  return getToken(bellParser::DIROUTLET, 0);
}

tree::TerminalNode* bellParser::DirOutletAssignmentContext::ASSIGN() {
  return getToken(bellParser::ASSIGN, 0);
}

bellParser::ListContext* bellParser::DirOutletAssignmentContext::list() {
  return getRuleContext<bellParser::ListContext>(0);
}

bellParser::DirOutletAssignmentContext::DirOutletAssignmentContext(AssignmentContext *ctx) { copyFrom(ctx); }


std::any bellParser::DirOutletAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitDirOutletAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TrueAssignmentContext ------------------------------------------------------------------

bellParser::LvalueContext* bellParser::TrueAssignmentContext::lvalue() {
  return getRuleContext<bellParser::LvalueContext>(0);
}

bellParser::ListContext* bellParser::TrueAssignmentContext::list() {
  return getRuleContext<bellParser::ListContext>(0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ASSIGN() {
  return getToken(bellParser::ASSIGN, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::APOW() {
  return getToken(bellParser::APOW, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ATIMES() {
  return getToken(bellParser::ATIMES, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ADIVDIV() {
  return getToken(bellParser::ADIVDIV, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ADIV() {
  return getToken(bellParser::ADIV, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::AREM() {
  return getToken(bellParser::AREM, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::APLUS() {
  return getToken(bellParser::APLUS, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::AMINUS() {
  return getToken(bellParser::AMINUS, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ALOGAND() {
  return getToken(bellParser::ALOGAND, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ALOGANDEXT() {
  return getToken(bellParser::ALOGANDEXT, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ALOGXOR() {
  return getToken(bellParser::ALOGXOR, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ALOGOR() {
  return getToken(bellParser::ALOGOR, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ALOGOREXT() {
  return getToken(bellParser::ALOGOREXT, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ABITAND() {
  return getToken(bellParser::ABITAND, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ABITXOR() {
  return getToken(bellParser::ABITXOR, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ABITOR() {
  return getToken(bellParser::ABITOR, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ALSHIFT() {
  return getToken(bellParser::ALSHIFT, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ARSHIFT() {
  return getToken(bellParser::ARSHIFT, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ACONCAT() {
  return getToken(bellParser::ACONCAT, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ARCONCAT() {
  return getToken(bellParser::ARCONCAT, 0);
}

tree::TerminalNode* bellParser::TrueAssignmentContext::ANTH() {
  return getToken(bellParser::ANTH, 0);
}

bellParser::TrueAssignmentContext::TrueAssignmentContext(AssignmentContext *ctx) { copyFrom(ctx); }


std::any bellParser::TrueAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitTrueAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OutletAssignmentContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::OutletAssignmentContext::OUTLET() {
  return getToken(bellParser::OUTLET, 0);
}

tree::TerminalNode* bellParser::OutletAssignmentContext::ASSIGN() {
  return getToken(bellParser::ASSIGN, 0);
}

bellParser::ListContext* bellParser::OutletAssignmentContext::list() {
  return getRuleContext<bellParser::ListContext>(0);
}

bellParser::OutletAssignmentContext::OutletAssignmentContext(AssignmentContext *ctx) { copyFrom(ctx); }


std::any bellParser::OutletAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitOutletAssignment(this);
  else
    return visitor->visitChildren(this);
}
bellParser::AssignmentContext* bellParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 24, bellParser::RuleAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(261);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::GLOBALVAR:
      case bellParser::PATCHERVAR:
      case bellParser::LOCALVAR: {
        _localctx = _tracker.createInstance<bellParser::TrueAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(247);
        lvalue();
        setState(248);
        antlrcpp::downCast<TrueAssignmentContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 35) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 35)) & ((1ULL << (bellParser::ANTH - 35))
          | (1ULL << (bellParser::ASSIGN - 35))
          | (1ULL << (bellParser::APOW - 35))
          | (1ULL << (bellParser::ATIMES - 35))
          | (1ULL << (bellParser::ADIVDIV - 35))
          | (1ULL << (bellParser::ADIV - 35))
          | (1ULL << (bellParser::AREM - 35))
          | (1ULL << (bellParser::APLUS - 35))
          | (1ULL << (bellParser::AMINUS - 35))
          | (1ULL << (bellParser::ABITAND - 35))
          | (1ULL << (bellParser::ABITXOR - 35))
          | (1ULL << (bellParser::ABITOR - 35))
          | (1ULL << (bellParser::ALOGAND - 35))
          | (1ULL << (bellParser::ALOGANDEXT - 35))
          | (1ULL << (bellParser::ALOGXOR - 35))
          | (1ULL << (bellParser::ALOGOR - 35))
          | (1ULL << (bellParser::ALOGOREXT - 35))
          | (1ULL << (bellParser::ALSHIFT - 35))
          | (1ULL << (bellParser::ARSHIFT - 35))
          | (1ULL << (bellParser::ACONCAT - 35))
          | (1ULL << (bellParser::ARCONCAT - 35)))) != 0))) {
          antlrcpp::downCast<TrueAssignmentContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(249);
        list();
        break;
      }

      case bellParser::UINT:
      case bellParser::UFLOAT:
      case bellParser::UPITCH:
      case bellParser::BTSYMBOL:
      case bellParser::DQSYMBOL:
      case bellParser::SQSYMBOL:
      case bellParser::BACHNULL:
      case bellParser::BACHNIL:
      case bellParser::FUNCTION:
      case bellParser::INLET:
      case bellParser::INTINLET:
      case bellParser::RATINLET:
      case bellParser::FLOATINLET:
      case bellParser::PITCHINLET:
      case bellParser::DIRINLET:
      case bellParser::PUSH:
      case bellParser::OPEN: {
        _localctx = _tracker.createInstance<bellParser::FakeAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(251);
        fakeLvalue();
        setState(252);
        antlrcpp::downCast<FakeAssignmentContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 38) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 38)) & ((1ULL << (bellParser::ASSIGN - 38))
          | (1ULL << (bellParser::APOW - 38))
          | (1ULL << (bellParser::ATIMES - 38))
          | (1ULL << (bellParser::ADIVDIV - 38))
          | (1ULL << (bellParser::ADIV - 38))
          | (1ULL << (bellParser::AREM - 38))
          | (1ULL << (bellParser::APLUS - 38))
          | (1ULL << (bellParser::AMINUS - 38))
          | (1ULL << (bellParser::ABITAND - 38))
          | (1ULL << (bellParser::ABITXOR - 38))
          | (1ULL << (bellParser::ABITOR - 38))
          | (1ULL << (bellParser::ALOGAND - 38))
          | (1ULL << (bellParser::ALOGANDEXT - 38))
          | (1ULL << (bellParser::ALOGXOR - 38))
          | (1ULL << (bellParser::ALOGOR - 38))
          | (1ULL << (bellParser::ALOGOREXT - 38))
          | (1ULL << (bellParser::ALSHIFT - 38))
          | (1ULL << (bellParser::ARSHIFT - 38))
          | (1ULL << (bellParser::ACONCAT - 38))
          | (1ULL << (bellParser::ARCONCAT - 38)))) != 0))) {
          antlrcpp::downCast<FakeAssignmentContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(253);
        list();
        break;
      }

      case bellParser::OUTLET: {
        _localctx = _tracker.createInstance<bellParser::OutletAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(255);
        match(bellParser::OUTLET);
        setState(256);
        match(bellParser::ASSIGN);
        setState(257);
        list();
        break;
      }

      case bellParser::DIROUTLET: {
        _localctx = _tracker.createInstance<bellParser::DirOutletAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(258);
        match(bellParser::DIROUTLET);
        setState(259);
        match(bellParser::ASSIGN);
        setState(260);
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
    setState(275);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::IfthenContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(263);
      match(bellParser::IF);
      setState(264);
      sequence();
      setState(265);
      match(bellParser::THEN);
      setState(266);
      list();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::IfthenelseContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(268);
      match(bellParser::IF);
      setState(269);
      sequence();
      setState(270);
      match(bellParser::THEN);
      setState(271);
      sequence();
      setState(272);
      match(bellParser::ELSE);
      setState(273);
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

bellParser::WhileloopContext* bellParser::ListEndContext::whileloop() {
  return getRuleContext<bellParser::WhileloopContext>(0);
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
    setState(280);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(277);
        conditional();
        break;
      }

      case bellParser::UINT:
      case bellParser::UFLOAT:
      case bellParser::UPITCH:
      case bellParser::BTSYMBOL:
      case bellParser::DQSYMBOL:
      case bellParser::SQSYMBOL:
      case bellParser::BACHNULL:
      case bellParser::BACHNIL:
      case bellParser::FUNCTION:
      case bellParser::INLET:
      case bellParser::INTINLET:
      case bellParser::RATINLET:
      case bellParser::FLOATINLET:
      case bellParser::PITCHINLET:
      case bellParser::OUTLET:
      case bellParser::DIRINLET:
      case bellParser::DIROUTLET:
      case bellParser::GLOBALVAR:
      case bellParser::PATCHERVAR:
      case bellParser::LOCALVAR:
      case bellParser::PUSH:
      case bellParser::OPEN: {
        enterOuterAlt(_localctx, 2);
        setState(278);
        assignment();
        break;
      }

      case bellParser::WHILE: {
        enterOuterAlt(_localctx, 3);
        setState(279);
        whileloop();
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
    enterOuterAlt(_localctx, 1);
    setState(283); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(282);
              expr(0);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(285); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
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
    case 11: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool bellParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 17);
    case 1: return precpred(_ctx, 16);
    case 2: return precpred(_ctx, 14);
    case 3: return precpred(_ctx, 13);
    case 4: return precpred(_ctx, 12);
    case 5: return precpred(_ctx, 11);
    case 6: return precpred(_ctx, 10);
    case 7: return precpred(_ctx, 9);
    case 8: return precpred(_ctx, 8);
    case 9: return precpred(_ctx, 7);
    case 10: return precpred(_ctx, 6);
    case 11: return precpred(_ctx, 5);
    case 12: return precpred(_ctx, 4);
    case 13: return precpred(_ctx, 3);
    case 14: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void bellParser::initialize() {
  std::call_once(bellParserOnceFlag, bellParserInitialize);
}
