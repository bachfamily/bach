
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
      "everything", "program", "funarg", "funargList", "liftedargList", 
      "fundef", "sequence", "nullified", "whileloop", "argsByNameList", 
      "argsByPositionList", "simpleFuncall", "dataFlowItem", "funcall", 
      "item", "var", "lvalueSpecs", "lvalue", "fakeLvalue", "listEnd", "expr", 
      "assignment", "conditional", "list"
    },
    std::vector<std::string>{
      "", "','", "'...'", "", "", "", "", "", "", "'null'", "'nil'", "'if'", 
      "'then'", "'else'", "'while'", "'for'", "'do'", "'collect'", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "'keep'", "'unkeep'", 
      "'init'", "'$argcount'", "'['", "']'", "')'", "':'", "'::'", "'.'", 
      "':='", "'::='", "';'", "'='", "", "", "'**'", "'**='", "'*'", "'*='", 
      "'//'", "'//='", "'/'", "'/='", "", "", "", "'+='", "'+'", "", "'-='", 
      "'-'", "'=='", "'!='", "'!'", "'~'", "'<'", "'>'", "'<='", "'>='", 
      "'&'", "'&='", "'^'", "'^='", "'|'", "'|='", "'&&'", "'&&&'", "'&&='", 
      "'&&&='", "'^^'", "'^^='", "'||'", "'||='", "'|||'", "'|||='", "'<<'", 
      "'<<='", "'>>'", "'>>='", "':*'", "':*='", "'.='", "'_='", "'!_='", 
      "", "", "'->'", "'-^'", "'<...>'"
    },
    std::vector<std::string>{
      "", "", "RANGE", "UINT", "UFLOAT", "UPITCH", "BTSYMBOL", "DQSYMBOL", 
      "SQSYMBOL", "BACHNULL", "BACHNIL", "IF", "THEN", "ELSE", "WHILE", 
      "FOR", "DO", "COLLECT", "INLET", "INTINLET", "RATINLET", "FLOATINLET", 
      "PITCHINLET", "OUTLET", "DIRINLET", "DIROUTLET", "BIF", "OF", "GLOBALVAR", 
      "PATCHERVAR", "LOCALVAR", "NAMEDPARAM", "KEEP", "UNKEEP", "INIT", 
      "ARGCOUNT", "PUSH", "POP", "CLOSED", "NTH", "PICK", "KEY", "ANTH", 
      "APICK", "NULLIFY", "ASSIGN", "WHITESPACE", "NEWATOM", "POW", "APOW", 
      "TIMES", "ATIMES", "DIVDIV", "ADIVDIV", "DIV", "ADIV", "REM", "AREM", 
      "PLUS", "APLUS", "UPLUS", "MINUS", "AMINUS", "UMINUS", "EQUAL", "NEQ", 
      "LOGNOT", "BITNOT", "LT", "GT", "LEQ", "GEQ", "BITAND", "ABITAND", 
      "BITXOR", "ABITXOR", "BITOR", "ABITOR", "LOGAND", "LOGANDEXT", "ALOGAND", 
      "ALOGANDEXT", "LOGXOR", "ALOGXOR", "LOGOR", "ALOGOR", "LOGOREXT", 
      "ALOGOREXT", "LSHIFT", "ALSHIFT", "RSHIFT", "ARSHIFT", "REPEAT", "AREPEAT", 
      "AAPPLY", "ACONCAT", "ARCONCAT", "OPEN", "PARAMS", "FUNDEF", "LIFT", 
      "ELLIPSIS", "ANYTHING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,102,392,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,59,
  	8,1,1,2,1,2,1,2,3,2,64,8,2,1,2,3,2,67,8,2,1,3,1,3,1,3,5,3,72,8,3,10,3,
  	12,3,75,9,3,1,4,1,4,1,4,5,4,80,8,4,10,4,12,4,83,9,4,1,4,1,4,1,5,1,5,3,
  	5,89,8,5,1,5,1,5,1,5,1,6,1,6,4,6,96,8,6,11,6,12,6,97,1,6,3,6,101,8,6,
  	3,6,103,8,6,1,7,1,7,4,7,107,8,7,11,7,12,7,108,1,8,1,8,1,8,1,8,1,8,1,9,
  	1,9,1,9,3,9,119,8,9,1,9,1,9,5,9,123,8,9,10,9,12,9,126,9,9,1,10,1,10,1,
  	10,5,10,131,8,10,10,10,12,10,134,9,10,1,11,1,11,1,11,3,11,139,8,11,1,
  	11,1,11,1,11,1,11,1,11,3,11,146,8,11,1,11,1,11,1,11,1,11,1,11,1,11,3,
  	11,154,8,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,162,8,11,1,11,1,11,1,11,
  	3,11,167,8,11,1,11,1,11,1,11,3,11,172,8,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,191,8,
  	11,1,11,1,11,1,11,5,11,196,8,11,10,11,12,11,199,9,11,1,12,1,12,1,12,3,
  	12,204,8,12,1,13,1,13,1,13,1,13,4,13,210,8,13,11,13,12,13,211,3,13,214,
  	8,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,236,8,14,1,15,3,15,239,8,15,1,
  	15,1,15,1,15,3,15,244,8,15,1,16,1,16,1,16,1,16,3,16,250,8,16,4,16,252,
  	8,16,11,16,12,16,253,1,16,1,16,1,16,1,16,3,16,260,8,16,5,16,262,8,16,
  	10,16,12,16,265,9,16,1,16,1,16,3,16,269,8,16,1,17,1,17,3,17,273,8,17,
  	1,18,1,18,1,18,1,19,1,19,1,19,1,19,3,19,282,8,19,1,20,1,20,1,20,1,20,
  	1,20,3,20,289,8,20,1,20,1,20,1,20,4,20,294,8,20,11,20,12,20,295,1,20,
  	1,20,1,20,3,20,301,8,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,5,20,348,8,20,10,20,12,20,351,
  	9,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,
  	1,21,1,21,1,21,1,21,1,21,3,21,371,8,21,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,3,22,385,8,22,1,23,4,23,388,8,23,11,23,
  	12,23,389,1,23,0,2,22,40,24,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,
  	32,34,36,38,40,42,44,46,0,16,1,0,16,17,1,0,7,8,1,0,18,22,1,0,32,33,2,
  	0,39,39,41,41,2,0,60,60,63,63,1,0,66,67,4,0,50,50,52,52,54,54,56,56,2,
  	0,58,58,61,61,2,0,88,88,90,90,1,0,64,65,1,0,68,71,1,0,78,79,2,0,84,84,
  	86,86,19,0,42,42,45,45,49,49,51,51,53,53,55,55,57,57,59,59,62,62,73,73,
  	75,75,77,77,80,81,83,83,85,85,87,87,89,89,91,91,95,96,18,0,45,45,49,49,
  	51,51,53,53,55,55,57,57,59,59,62,62,73,73,75,75,77,77,80,81,83,83,85,
  	85,87,87,89,89,91,91,95,96,453,0,48,1,0,0,0,2,58,1,0,0,0,4,66,1,0,0,0,
  	6,68,1,0,0,0,8,76,1,0,0,0,10,86,1,0,0,0,12,102,1,0,0,0,14,104,1,0,0,0,
  	16,110,1,0,0,0,18,115,1,0,0,0,20,127,1,0,0,0,22,171,1,0,0,0,24,203,1,
  	0,0,0,26,213,1,0,0,0,28,235,1,0,0,0,30,243,1,0,0,0,32,268,1,0,0,0,34,
  	270,1,0,0,0,36,274,1,0,0,0,38,281,1,0,0,0,40,300,1,0,0,0,42,370,1,0,0,
  	0,44,384,1,0,0,0,46,387,1,0,0,0,48,49,3,2,1,0,49,1,1,0,0,0,50,59,5,0,
  	0,1,51,52,3,12,6,0,52,53,5,0,0,1,53,59,1,0,0,0,54,55,3,12,6,0,55,56,5,
  	31,0,0,56,59,1,0,0,0,57,59,5,31,0,0,58,50,1,0,0,0,58,51,1,0,0,0,58,54,
  	1,0,0,0,58,57,1,0,0,0,59,3,1,0,0,0,60,63,5,30,0,0,61,62,5,45,0,0,62,64,
  	3,46,23,0,63,61,1,0,0,0,63,64,1,0,0,0,64,67,1,0,0,0,65,67,5,101,0,0,66,
  	60,1,0,0,0,66,65,1,0,0,0,67,5,1,0,0,0,68,73,3,4,2,0,69,70,5,1,0,0,70,
  	72,3,4,2,0,71,69,1,0,0,0,72,75,1,0,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,
  	7,1,0,0,0,75,73,1,0,0,0,76,81,5,100,0,0,77,78,5,30,0,0,78,80,5,1,0,0,
  	79,77,1,0,0,0,80,83,1,0,0,0,81,79,1,0,0,0,81,82,1,0,0,0,82,84,1,0,0,0,
  	83,81,1,0,0,0,84,85,5,30,0,0,85,9,1,0,0,0,86,88,3,6,3,0,87,89,3,8,4,0,
  	88,87,1,0,0,0,88,89,1,0,0,0,89,90,1,0,0,0,90,91,5,99,0,0,91,92,3,46,23,
  	0,92,11,1,0,0,0,93,103,3,46,23,0,94,96,3,14,7,0,95,94,1,0,0,0,96,97,1,
  	0,0,0,97,95,1,0,0,0,97,98,1,0,0,0,98,100,1,0,0,0,99,101,3,46,23,0,100,
  	99,1,0,0,0,100,101,1,0,0,0,101,103,1,0,0,0,102,93,1,0,0,0,102,95,1,0,
  	0,0,103,13,1,0,0,0,104,106,3,46,23,0,105,107,5,44,0,0,106,105,1,0,0,0,
  	107,108,1,0,0,0,108,106,1,0,0,0,108,109,1,0,0,0,109,15,1,0,0,0,110,111,
  	5,14,0,0,111,112,3,12,6,0,112,113,7,0,0,0,113,114,3,46,23,0,114,17,1,
  	0,0,0,115,116,5,31,0,0,116,124,3,12,6,0,117,119,5,1,0,0,118,117,1,0,0,
  	0,118,119,1,0,0,0,119,120,1,0,0,0,120,121,5,31,0,0,121,123,3,12,6,0,122,
  	118,1,0,0,0,123,126,1,0,0,0,124,122,1,0,0,0,124,125,1,0,0,0,125,19,1,
  	0,0,0,126,124,1,0,0,0,127,132,3,12,6,0,128,129,5,1,0,0,129,131,3,12,6,
  	0,130,128,1,0,0,0,131,134,1,0,0,0,132,130,1,0,0,0,132,133,1,0,0,0,133,
  	21,1,0,0,0,134,132,1,0,0,0,135,138,6,11,-1,0,136,139,3,28,14,0,137,139,
  	3,30,15,0,138,136,1,0,0,0,138,137,1,0,0,0,139,140,1,0,0,0,140,141,5,98,
  	0,0,141,142,5,38,0,0,142,172,1,0,0,0,143,146,3,28,14,0,144,146,3,30,15,
  	0,145,143,1,0,0,0,145,144,1,0,0,0,146,147,1,0,0,0,147,148,5,98,0,0,148,
  	149,3,20,10,0,149,150,5,38,0,0,150,172,1,0,0,0,151,154,3,28,14,0,152,
  	154,3,30,15,0,153,151,1,0,0,0,153,152,1,0,0,0,154,155,1,0,0,0,155,156,
  	5,98,0,0,156,157,3,18,9,0,157,158,5,38,0,0,158,172,1,0,0,0,159,162,3,
  	28,14,0,160,162,3,30,15,0,161,159,1,0,0,0,161,160,1,0,0,0,162,163,1,0,
  	0,0,163,164,5,98,0,0,164,166,3,20,10,0,165,167,5,1,0,0,166,165,1,0,0,
  	0,166,167,1,0,0,0,167,168,1,0,0,0,168,169,3,18,9,0,169,170,5,38,0,0,170,
  	172,1,0,0,0,171,135,1,0,0,0,171,145,1,0,0,0,171,153,1,0,0,0,171,161,1,
  	0,0,0,172,197,1,0,0,0,173,174,10,4,0,0,174,175,5,98,0,0,175,196,5,38,
  	0,0,176,177,10,3,0,0,177,178,5,98,0,0,178,179,3,20,10,0,179,180,5,38,
  	0,0,180,196,1,0,0,0,181,182,10,2,0,0,182,183,5,98,0,0,183,184,3,18,9,
  	0,184,185,5,38,0,0,185,196,1,0,0,0,186,187,10,1,0,0,187,188,5,98,0,0,
  	188,190,3,20,10,0,189,191,5,1,0,0,190,189,1,0,0,0,190,191,1,0,0,0,191,
  	192,1,0,0,0,192,193,3,18,9,0,193,194,5,38,0,0,194,196,1,0,0,0,195,173,
  	1,0,0,0,195,176,1,0,0,0,195,181,1,0,0,0,195,186,1,0,0,0,196,199,1,0,0,
  	0,197,195,1,0,0,0,197,198,1,0,0,0,198,23,1,0,0,0,199,197,1,0,0,0,200,
  	204,3,28,14,0,201,204,3,30,15,0,202,204,3,22,11,0,203,200,1,0,0,0,203,
  	201,1,0,0,0,203,202,1,0,0,0,204,25,1,0,0,0,205,214,3,22,11,0,206,209,
  	3,24,12,0,207,208,5,41,0,0,208,210,3,22,11,0,209,207,1,0,0,0,210,211,
  	1,0,0,0,211,209,1,0,0,0,211,212,1,0,0,0,212,214,1,0,0,0,213,205,1,0,0,
  	0,213,206,1,0,0,0,214,27,1,0,0,0,215,236,5,3,0,0,216,236,5,4,0,0,217,
  	236,5,5,0,0,218,236,5,6,0,0,219,236,7,1,0,0,220,236,5,26,0,0,221,236,
  	5,27,0,0,222,236,7,2,0,0,223,236,5,24,0,0,224,236,5,35,0,0,225,236,5,
  	9,0,0,226,236,5,10,0,0,227,228,5,97,0,0,228,229,3,12,6,0,229,230,5,38,
  	0,0,230,236,1,0,0,0,231,232,5,36,0,0,232,233,3,12,6,0,233,234,5,37,0,
  	0,234,236,1,0,0,0,235,215,1,0,0,0,235,216,1,0,0,0,235,217,1,0,0,0,235,
  	218,1,0,0,0,235,219,1,0,0,0,235,220,1,0,0,0,235,221,1,0,0,0,235,222,1,
  	0,0,0,235,223,1,0,0,0,235,224,1,0,0,0,235,225,1,0,0,0,235,226,1,0,0,0,
  	235,227,1,0,0,0,235,231,1,0,0,0,236,29,1,0,0,0,237,239,7,3,0,0,238,237,
  	1,0,0,0,238,239,1,0,0,0,239,240,1,0,0,0,240,244,5,30,0,0,241,244,5,29,
  	0,0,242,244,5,28,0,0,243,238,1,0,0,0,243,241,1,0,0,0,243,242,1,0,0,0,
  	244,31,1,0,0,0,245,251,6,16,-1,0,246,249,7,4,0,0,247,250,3,28,14,0,248,
  	250,3,30,15,0,249,247,1,0,0,0,249,248,1,0,0,0,250,252,1,0,0,0,251,246,
  	1,0,0,0,252,253,1,0,0,0,253,251,1,0,0,0,253,254,1,0,0,0,254,269,1,0,0,
  	0,255,263,6,16,-1,0,256,259,7,4,0,0,257,260,3,28,14,0,258,260,3,30,15,
  	0,259,257,1,0,0,0,259,258,1,0,0,0,260,262,1,0,0,0,261,256,1,0,0,0,262,
  	265,1,0,0,0,263,261,1,0,0,0,263,264,1,0,0,0,264,266,1,0,0,0,265,263,1,
  	0,0,0,266,267,7,4,0,0,267,269,3,44,22,0,268,245,1,0,0,0,268,255,1,0,0,
  	0,269,33,1,0,0,0,270,272,3,30,15,0,271,273,3,32,16,0,272,271,1,0,0,0,
  	272,273,1,0,0,0,273,35,1,0,0,0,274,275,3,28,14,0,275,276,3,32,16,0,276,
  	37,1,0,0,0,277,282,3,44,22,0,278,282,3,42,21,0,279,282,3,16,8,0,280,282,
  	3,10,5,0,281,277,1,0,0,0,281,278,1,0,0,0,281,279,1,0,0,0,281,280,1,0,
  	0,0,282,39,1,0,0,0,283,288,6,20,-1,0,284,289,3,28,14,0,285,289,3,30,15,
  	0,286,289,3,26,13,0,287,289,3,38,19,0,288,284,1,0,0,0,288,285,1,0,0,0,
  	288,286,1,0,0,0,288,287,1,0,0,0,289,301,1,0,0,0,290,301,3,34,17,0,291,
  	301,3,36,18,0,292,294,7,5,0,0,293,292,1,0,0,0,294,295,1,0,0,0,295,293,
  	1,0,0,0,295,296,1,0,0,0,296,297,1,0,0,0,297,301,3,40,20,15,298,299,7,
  	6,0,0,299,301,3,40,20,1,300,283,1,0,0,0,300,290,1,0,0,0,300,291,1,0,0,
  	0,300,293,1,0,0,0,300,298,1,0,0,0,301,349,1,0,0,0,302,303,10,17,0,0,303,
  	304,5,40,0,0,304,348,3,40,20,18,305,306,10,16,0,0,306,307,5,48,0,0,307,
  	348,3,40,20,16,308,309,10,14,0,0,309,310,7,7,0,0,310,348,3,40,20,15,311,
  	312,10,13,0,0,312,313,7,8,0,0,313,348,3,40,20,14,314,315,10,12,0,0,315,
  	316,7,9,0,0,316,348,3,40,20,13,317,318,10,11,0,0,318,319,5,2,0,0,319,
  	348,3,40,20,12,320,321,10,10,0,0,321,322,5,92,0,0,322,348,3,40,20,11,
  	323,324,10,9,0,0,324,325,7,10,0,0,325,348,3,40,20,10,326,327,10,8,0,0,
  	327,328,7,11,0,0,328,348,3,40,20,9,329,330,10,7,0,0,330,331,5,72,0,0,
  	331,348,3,40,20,8,332,333,10,6,0,0,333,334,5,74,0,0,334,348,3,40,20,7,
  	335,336,10,5,0,0,336,337,5,76,0,0,337,348,3,40,20,6,338,339,10,4,0,0,
  	339,340,7,12,0,0,340,348,3,40,20,5,341,342,10,3,0,0,342,343,5,82,0,0,
  	343,348,3,40,20,4,344,345,10,2,0,0,345,346,7,13,0,0,346,348,3,40,20,3,
  	347,302,1,0,0,0,347,305,1,0,0,0,347,308,1,0,0,0,347,311,1,0,0,0,347,314,
  	1,0,0,0,347,317,1,0,0,0,347,320,1,0,0,0,347,323,1,0,0,0,347,326,1,0,0,
  	0,347,329,1,0,0,0,347,332,1,0,0,0,347,335,1,0,0,0,347,338,1,0,0,0,347,
  	341,1,0,0,0,347,344,1,0,0,0,348,351,1,0,0,0,349,347,1,0,0,0,349,350,1,
  	0,0,0,350,41,1,0,0,0,351,349,1,0,0,0,352,353,5,34,0,0,353,354,5,30,0,
  	0,354,355,5,45,0,0,355,371,3,46,23,0,356,357,3,34,17,0,357,358,7,14,0,
  	0,358,359,3,46,23,0,359,371,1,0,0,0,360,361,3,36,18,0,361,362,7,15,0,
  	0,362,363,3,46,23,0,363,371,1,0,0,0,364,365,5,23,0,0,365,366,5,45,0,0,
  	366,371,3,46,23,0,367,368,5,25,0,0,368,369,5,45,0,0,369,371,3,46,23,0,
  	370,352,1,0,0,0,370,356,1,0,0,0,370,360,1,0,0,0,370,364,1,0,0,0,370,367,
  	1,0,0,0,371,43,1,0,0,0,372,373,5,11,0,0,373,374,3,12,6,0,374,375,5,12,
  	0,0,375,376,3,46,23,0,376,385,1,0,0,0,377,378,5,11,0,0,378,379,3,12,6,
  	0,379,380,5,12,0,0,380,381,3,12,6,0,381,382,5,13,0,0,382,383,3,46,23,
  	0,383,385,1,0,0,0,384,372,1,0,0,0,384,377,1,0,0,0,385,45,1,0,0,0,386,
  	388,3,40,20,0,387,386,1,0,0,0,388,389,1,0,0,0,389,387,1,0,0,0,389,390,
  	1,0,0,0,390,47,1,0,0,0,43,58,63,66,73,81,88,97,100,102,108,118,124,132,
  	138,145,153,161,166,171,190,195,197,203,211,213,235,238,243,249,253,259,
  	263,268,272,281,288,295,300,347,349,370,384,389
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
    setState(48);
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
    setState(58);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::ProgramEOFContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(50);
      match(bellParser::EOF);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::ProgramSequenceContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(51);
      sequence();
      setState(52);
      match(bellParser::EOF);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<bellParser::ProgramSequenceNamedparamContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(54);
      sequence();
      setState(55);
      match(bellParser::NAMEDPARAM);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<bellParser::ProgramNamedparamContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(57);
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

//----------------- FunargContext ------------------------------------------------------------------

bellParser::FunargContext::FunargContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bellParser::FunargContext::getRuleIndex() const {
  return bellParser::RuleFunarg;
}

void bellParser::FunargContext::copyFrom(FunargContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FunargVarContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::FunargVarContext::LOCALVAR() {
  return getToken(bellParser::LOCALVAR, 0);
}

tree::TerminalNode* bellParser::FunargVarContext::ASSIGN() {
  return getToken(bellParser::ASSIGN, 0);
}

bellParser::ListContext* bellParser::FunargVarContext::list() {
  return getRuleContext<bellParser::ListContext>(0);
}

bellParser::FunargVarContext::FunargVarContext(FunargContext *ctx) { copyFrom(ctx); }


std::any bellParser::FunargVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitFunargVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunargEllipsisContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::FunargEllipsisContext::ELLIPSIS() {
  return getToken(bellParser::ELLIPSIS, 0);
}

bellParser::FunargEllipsisContext::FunargEllipsisContext(FunargContext *ctx) { copyFrom(ctx); }


std::any bellParser::FunargEllipsisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitFunargEllipsis(this);
  else
    return visitor->visitChildren(this);
}
bellParser::FunargContext* bellParser::funarg() {
  FunargContext *_localctx = _tracker.createInstance<FunargContext>(_ctx, getState());
  enterRule(_localctx, 4, bellParser::RuleFunarg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(66);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::LOCALVAR: {
        _localctx = _tracker.createInstance<bellParser::FunargVarContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(60);
        match(bellParser::LOCALVAR);
        setState(63);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bellParser::ASSIGN) {
          setState(61);
          match(bellParser::ASSIGN);
          setState(62);
          list();
        }
        break;
      }

      case bellParser::ELLIPSIS: {
        _localctx = _tracker.createInstance<bellParser::FunargEllipsisContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(65);
        match(bellParser::ELLIPSIS);
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

//----------------- FunargListContext ------------------------------------------------------------------

bellParser::FunargListContext::FunargListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<bellParser::FunargContext *> bellParser::FunargListContext::funarg() {
  return getRuleContexts<bellParser::FunargContext>();
}

bellParser::FunargContext* bellParser::FunargListContext::funarg(size_t i) {
  return getRuleContext<bellParser::FunargContext>(i);
}


size_t bellParser::FunargListContext::getRuleIndex() const {
  return bellParser::RuleFunargList;
}


std::any bellParser::FunargListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitFunargList(this);
  else
    return visitor->visitChildren(this);
}

bellParser::FunargListContext* bellParser::funargList() {
  FunargListContext *_localctx = _tracker.createInstance<FunargListContext>(_ctx, getState());
  enterRule(_localctx, 6, bellParser::RuleFunargList);
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
    setState(68);
    funarg();
    setState(73);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::T__0) {
      setState(69);
      match(bellParser::T__0);
      setState(70);
      funarg();
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiftedargListContext ------------------------------------------------------------------

bellParser::LiftedargListContext::LiftedargListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bellParser::LiftedargListContext::LIFT() {
  return getToken(bellParser::LIFT, 0);
}

std::vector<tree::TerminalNode *> bellParser::LiftedargListContext::LOCALVAR() {
  return getTokens(bellParser::LOCALVAR);
}

tree::TerminalNode* bellParser::LiftedargListContext::LOCALVAR(size_t i) {
  return getToken(bellParser::LOCALVAR, i);
}


size_t bellParser::LiftedargListContext::getRuleIndex() const {
  return bellParser::RuleLiftedargList;
}


std::any bellParser::LiftedargListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLiftedargList(this);
  else
    return visitor->visitChildren(this);
}

bellParser::LiftedargListContext* bellParser::liftedargList() {
  LiftedargListContext *_localctx = _tracker.createInstance<LiftedargListContext>(_ctx, getState());
  enterRule(_localctx, 8, bellParser::RuleLiftedargList);

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
    setState(76);
    match(bellParser::LIFT);
    setState(81);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(77);
        match(bellParser::LOCALVAR);
        setState(78);
        match(bellParser::T__0); 
      }
      setState(83);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(84);
    match(bellParser::LOCALVAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FundefContext ------------------------------------------------------------------

bellParser::FundefContext::FundefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bellParser::FunargListContext* bellParser::FundefContext::funargList() {
  return getRuleContext<bellParser::FunargListContext>(0);
}

tree::TerminalNode* bellParser::FundefContext::FUNDEF() {
  return getToken(bellParser::FUNDEF, 0);
}

bellParser::ListContext* bellParser::FundefContext::list() {
  return getRuleContext<bellParser::ListContext>(0);
}

bellParser::LiftedargListContext* bellParser::FundefContext::liftedargList() {
  return getRuleContext<bellParser::LiftedargListContext>(0);
}


size_t bellParser::FundefContext::getRuleIndex() const {
  return bellParser::RuleFundef;
}


std::any bellParser::FundefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitFundef(this);
  else
    return visitor->visitChildren(this);
}

bellParser::FundefContext* bellParser::fundef() {
  FundefContext *_localctx = _tracker.createInstance<FundefContext>(_ctx, getState());
  enterRule(_localctx, 10, bellParser::RuleFundef);
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
    setState(86);
    funargList();
    setState(88);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == bellParser::LIFT) {
      setState(87);
      liftedargList();
    }
    setState(90);
    match(bellParser::FUNDEF);
    setState(91);
    list();
   
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
  enterRule(_localctx, 12, bellParser::RuleSequence);
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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(93);
      list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(95); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(94);
                nullified();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(97); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(100);
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
        | (1ULL << bellParser::INLET)
        | (1ULL << bellParser::INTINLET)
        | (1ULL << bellParser::RATINLET)
        | (1ULL << bellParser::FLOATINLET)
        | (1ULL << bellParser::PITCHINLET)
        | (1ULL << bellParser::OUTLET)
        | (1ULL << bellParser::DIRINLET)
        | (1ULL << bellParser::DIROUTLET)
        | (1ULL << bellParser::BIF)
        | (1ULL << bellParser::OF)
        | (1ULL << bellParser::GLOBALVAR)
        | (1ULL << bellParser::PATCHERVAR)
        | (1ULL << bellParser::LOCALVAR)
        | (1ULL << bellParser::KEEP)
        | (1ULL << bellParser::UNKEEP)
        | (1ULL << bellParser::INIT)
        | (1ULL << bellParser::ARGCOUNT)
        | (1ULL << bellParser::PUSH)
        | (1ULL << bellParser::UPLUS)
        | (1ULL << bellParser::UMINUS))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 66)) & ((1ULL << (bellParser::LOGNOT - 66))
        | (1ULL << (bellParser::BITNOT - 66))
        | (1ULL << (bellParser::OPEN - 66))
        | (1ULL << (bellParser::ELLIPSIS - 66)))) != 0)) {
        setState(99);
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
  enterRule(_localctx, 14, bellParser::RuleNullified);
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
    setState(104);
    list();
    setState(106); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(105);
      match(bellParser::NULLIFY);
      setState(108); 
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
  enterRule(_localctx, 16, bellParser::RuleWhileloop);
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
    setState(110);
    match(bellParser::WHILE);
    setState(111);
    sequence();
    setState(112);
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
    setState(113);
    list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgsByNameListContext ------------------------------------------------------------------

bellParser::ArgsByNameListContext::ArgsByNameListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> bellParser::ArgsByNameListContext::NAMEDPARAM() {
  return getTokens(bellParser::NAMEDPARAM);
}

tree::TerminalNode* bellParser::ArgsByNameListContext::NAMEDPARAM(size_t i) {
  return getToken(bellParser::NAMEDPARAM, i);
}

std::vector<bellParser::SequenceContext *> bellParser::ArgsByNameListContext::sequence() {
  return getRuleContexts<bellParser::SequenceContext>();
}

bellParser::SequenceContext* bellParser::ArgsByNameListContext::sequence(size_t i) {
  return getRuleContext<bellParser::SequenceContext>(i);
}


size_t bellParser::ArgsByNameListContext::getRuleIndex() const {
  return bellParser::RuleArgsByNameList;
}


std::any bellParser::ArgsByNameListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitArgsByNameList(this);
  else
    return visitor->visitChildren(this);
}

bellParser::ArgsByNameListContext* bellParser::argsByNameList() {
  ArgsByNameListContext *_localctx = _tracker.createInstance<ArgsByNameListContext>(_ctx, getState());
  enterRule(_localctx, 18, bellParser::RuleArgsByNameList);
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
    setState(115);
    match(bellParser::NAMEDPARAM);
    setState(116);
    sequence();
    setState(124);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::T__0

    || _la == bellParser::NAMEDPARAM) {
      setState(118);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::T__0) {
        setState(117);
        match(bellParser::T__0);
      }
      setState(120);
      match(bellParser::NAMEDPARAM);
      setState(121);
      sequence();
      setState(126);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgsByPositionListContext ------------------------------------------------------------------

bellParser::ArgsByPositionListContext::ArgsByPositionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<bellParser::SequenceContext *> bellParser::ArgsByPositionListContext::sequence() {
  return getRuleContexts<bellParser::SequenceContext>();
}

bellParser::SequenceContext* bellParser::ArgsByPositionListContext::sequence(size_t i) {
  return getRuleContext<bellParser::SequenceContext>(i);
}


size_t bellParser::ArgsByPositionListContext::getRuleIndex() const {
  return bellParser::RuleArgsByPositionList;
}


std::any bellParser::ArgsByPositionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitArgsByPositionList(this);
  else
    return visitor->visitChildren(this);
}

bellParser::ArgsByPositionListContext* bellParser::argsByPositionList() {
  ArgsByPositionListContext *_localctx = _tracker.createInstance<ArgsByPositionListContext>(_ctx, getState());
  enterRule(_localctx, 20, bellParser::RuleArgsByPositionList);

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
    setState(127);
    sequence();
    setState(132);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(128);
        match(bellParser::T__0);
        setState(129);
        sequence(); 
      }
      setState(134);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleFuncallContext ------------------------------------------------------------------

bellParser::SimpleFuncallContext::SimpleFuncallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bellParser::SimpleFuncallContext::PARAMS() {
  return getToken(bellParser::PARAMS, 0);
}

tree::TerminalNode* bellParser::SimpleFuncallContext::CLOSED() {
  return getToken(bellParser::CLOSED, 0);
}

bellParser::ItemContext* bellParser::SimpleFuncallContext::item() {
  return getRuleContext<bellParser::ItemContext>(0);
}

bellParser::VarContext* bellParser::SimpleFuncallContext::var() {
  return getRuleContext<bellParser::VarContext>(0);
}

bellParser::ArgsByPositionListContext* bellParser::SimpleFuncallContext::argsByPositionList() {
  return getRuleContext<bellParser::ArgsByPositionListContext>(0);
}

bellParser::ArgsByNameListContext* bellParser::SimpleFuncallContext::argsByNameList() {
  return getRuleContext<bellParser::ArgsByNameListContext>(0);
}

bellParser::SimpleFuncallContext* bellParser::SimpleFuncallContext::simpleFuncall() {
  return getRuleContext<bellParser::SimpleFuncallContext>(0);
}


size_t bellParser::SimpleFuncallContext::getRuleIndex() const {
  return bellParser::RuleSimpleFuncall;
}


std::any bellParser::SimpleFuncallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitSimpleFuncall(this);
  else
    return visitor->visitChildren(this);
}


bellParser::SimpleFuncallContext* bellParser::simpleFuncall() {
   return simpleFuncall(0);
}

bellParser::SimpleFuncallContext* bellParser::simpleFuncall(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  bellParser::SimpleFuncallContext *_localctx = _tracker.createInstance<SimpleFuncallContext>(_ctx, parentState);
  bellParser::SimpleFuncallContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, bellParser::RuleSimpleFuncall, precedence);

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
    setState(171);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(138);
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
        case bellParser::INLET:
        case bellParser::INTINLET:
        case bellParser::RATINLET:
        case bellParser::FLOATINLET:
        case bellParser::PITCHINLET:
        case bellParser::DIRINLET:
        case bellParser::BIF:
        case bellParser::OF:
        case bellParser::ARGCOUNT:
        case bellParser::PUSH:
        case bellParser::OPEN: {
          setState(136);
          item();
          break;
        }

        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR:
        case bellParser::KEEP:
        case bellParser::UNKEEP: {
          setState(137);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(140);
      match(bellParser::PARAMS);
      setState(141);
      match(bellParser::CLOSED);
      break;
    }

    case 2: {
      setState(145);
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
        case bellParser::INLET:
        case bellParser::INTINLET:
        case bellParser::RATINLET:
        case bellParser::FLOATINLET:
        case bellParser::PITCHINLET:
        case bellParser::DIRINLET:
        case bellParser::BIF:
        case bellParser::OF:
        case bellParser::ARGCOUNT:
        case bellParser::PUSH:
        case bellParser::OPEN: {
          setState(143);
          item();
          break;
        }

        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR:
        case bellParser::KEEP:
        case bellParser::UNKEEP: {
          setState(144);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(147);
      match(bellParser::PARAMS);
      setState(148);
      argsByPositionList();
      setState(149);
      match(bellParser::CLOSED);
      break;
    }

    case 3: {
      setState(153);
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
        case bellParser::INLET:
        case bellParser::INTINLET:
        case bellParser::RATINLET:
        case bellParser::FLOATINLET:
        case bellParser::PITCHINLET:
        case bellParser::DIRINLET:
        case bellParser::BIF:
        case bellParser::OF:
        case bellParser::ARGCOUNT:
        case bellParser::PUSH:
        case bellParser::OPEN: {
          setState(151);
          item();
          break;
        }

        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR:
        case bellParser::KEEP:
        case bellParser::UNKEEP: {
          setState(152);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(155);
      match(bellParser::PARAMS);
      setState(156);
      argsByNameList();
      setState(157);
      match(bellParser::CLOSED);
      break;
    }

    case 4: {
      setState(161);
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
        case bellParser::INLET:
        case bellParser::INTINLET:
        case bellParser::RATINLET:
        case bellParser::FLOATINLET:
        case bellParser::PITCHINLET:
        case bellParser::DIRINLET:
        case bellParser::BIF:
        case bellParser::OF:
        case bellParser::ARGCOUNT:
        case bellParser::PUSH:
        case bellParser::OPEN: {
          setState(159);
          item();
          break;
        }

        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR:
        case bellParser::KEEP:
        case bellParser::UNKEEP: {
          setState(160);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(163);
      match(bellParser::PARAMS);
      setState(164);
      argsByPositionList();
      setState(166);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::T__0) {
        setState(165);
        match(bellParser::T__0);
      }
      setState(168);
      argsByNameList();
      setState(169);
      match(bellParser::CLOSED);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(197);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(195);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(173);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(174);
          match(bellParser::PARAMS);
          setState(175);
          match(bellParser::CLOSED);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(176);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(177);
          match(bellParser::PARAMS);
          setState(178);
          argsByPositionList();
          setState(179);
          match(bellParser::CLOSED);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(181);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(182);
          match(bellParser::PARAMS);
          setState(183);
          argsByNameList();
          setState(184);
          match(bellParser::CLOSED);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(186);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(187);
          match(bellParser::PARAMS);
          setState(188);
          argsByPositionList();
          setState(190);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == bellParser::T__0) {
            setState(189);
            match(bellParser::T__0);
          }
          setState(192);
          argsByNameList();
          setState(193);
          match(bellParser::CLOSED);
          break;
        }

        default:
          break;
        } 
      }
      setState(199);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DataFlowItemContext ------------------------------------------------------------------

bellParser::DataFlowItemContext::DataFlowItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bellParser::ItemContext* bellParser::DataFlowItemContext::item() {
  return getRuleContext<bellParser::ItemContext>(0);
}

bellParser::VarContext* bellParser::DataFlowItemContext::var() {
  return getRuleContext<bellParser::VarContext>(0);
}

bellParser::SimpleFuncallContext* bellParser::DataFlowItemContext::simpleFuncall() {
  return getRuleContext<bellParser::SimpleFuncallContext>(0);
}


size_t bellParser::DataFlowItemContext::getRuleIndex() const {
  return bellParser::RuleDataFlowItem;
}


std::any bellParser::DataFlowItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitDataFlowItem(this);
  else
    return visitor->visitChildren(this);
}

bellParser::DataFlowItemContext* bellParser::dataFlowItem() {
  DataFlowItemContext *_localctx = _tracker.createInstance<DataFlowItemContext>(_ctx, getState());
  enterRule(_localctx, 24, bellParser::RuleDataFlowItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(203);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(200);
      item();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(201);
      var();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(202);
      simpleFuncall(0);
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

bellParser::FuncallContext::FuncallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<bellParser::SimpleFuncallContext *> bellParser::FuncallContext::simpleFuncall() {
  return getRuleContexts<bellParser::SimpleFuncallContext>();
}

bellParser::SimpleFuncallContext* bellParser::FuncallContext::simpleFuncall(size_t i) {
  return getRuleContext<bellParser::SimpleFuncallContext>(i);
}

bellParser::DataFlowItemContext* bellParser::FuncallContext::dataFlowItem() {
  return getRuleContext<bellParser::DataFlowItemContext>(0);
}

std::vector<tree::TerminalNode *> bellParser::FuncallContext::KEY() {
  return getTokens(bellParser::KEY);
}

tree::TerminalNode* bellParser::FuncallContext::KEY(size_t i) {
  return getToken(bellParser::KEY, i);
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
  enterRule(_localctx, 26, bellParser::RuleFuncall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(213);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(205);
      simpleFuncall(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(206);
      dataFlowItem();
      setState(209); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(207);
                match(bellParser::KEY);
                setState(208);
                simpleFuncall(0);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(211); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
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
//----------------- ItemBIFContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemBIFContext::BIF() {
  return getToken(bellParser::BIF, 0);
}

bellParser::ItemBIFContext::ItemBIFContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemBIFContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemBIF(this);
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
//----------------- ItemOFContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemOFContext::OF() {
  return getToken(bellParser::OF, 0);
}

bellParser::ItemOFContext::ItemOFContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemOFContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemOF(this);
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
//----------------- ItemArgcountContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemArgcountContext::ARGCOUNT() {
  return getToken(bellParser::ARGCOUNT, 0);
}

bellParser::ItemArgcountContext::ItemArgcountContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemArgcountContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemArgcount(this);
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
  enterRule(_localctx, 28, bellParser::RuleItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(235);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::UINT: {
        _localctx = _tracker.createInstance<bellParser::ItemUintContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(215);
        match(bellParser::UINT);
        break;
      }

      case bellParser::UFLOAT: {
        _localctx = _tracker.createInstance<bellParser::ItemUfloatContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(216);
        match(bellParser::UFLOAT);
        break;
      }

      case bellParser::UPITCH: {
        _localctx = _tracker.createInstance<bellParser::ItemUpitchContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(217);
        match(bellParser::UPITCH);
        break;
      }

      case bellParser::BTSYMBOL: {
        _localctx = _tracker.createInstance<bellParser::ItemBtSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(218);
        match(bellParser::BTSYMBOL);
        break;
      }

      case bellParser::DQSYMBOL:
      case bellParser::SQSYMBOL: {
        _localctx = _tracker.createInstance<bellParser::ItemQSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(219);
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

      case bellParser::BIF: {
        _localctx = _tracker.createInstance<bellParser::ItemBIFContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(220);
        match(bellParser::BIF);
        break;
      }

      case bellParser::OF: {
        _localctx = _tracker.createInstance<bellParser::ItemOFContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(221);
        match(bellParser::OF);
        break;
      }

      case bellParser::INLET:
      case bellParser::INTINLET:
      case bellParser::RATINLET:
      case bellParser::FLOATINLET:
      case bellParser::PITCHINLET: {
        _localctx = _tracker.createInstance<bellParser::ItemInletContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(222);
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
        enterOuterAlt(_localctx, 9);
        setState(223);
        match(bellParser::DIRINLET);
        break;
      }

      case bellParser::ARGCOUNT: {
        _localctx = _tracker.createInstance<bellParser::ItemArgcountContext>(_localctx);
        enterOuterAlt(_localctx, 10);
        setState(224);
        match(bellParser::ARGCOUNT);
        break;
      }

      case bellParser::BACHNULL: {
        _localctx = _tracker.createInstance<bellParser::ItemNullContext>(_localctx);
        enterOuterAlt(_localctx, 11);
        setState(225);
        match(bellParser::BACHNULL);
        break;
      }

      case bellParser::BACHNIL: {
        _localctx = _tracker.createInstance<bellParser::ItemNilContext>(_localctx);
        enterOuterAlt(_localctx, 12);
        setState(226);
        match(bellParser::BACHNIL);
        break;
      }

      case bellParser::OPEN: {
        _localctx = _tracker.createInstance<bellParser::ItemSequenceContext>(_localctx);
        enterOuterAlt(_localctx, 13);
        setState(227);
        match(bellParser::OPEN);
        setState(228);
        sequence();
        setState(229);
        match(bellParser::CLOSED);
        break;
      }

      case bellParser::PUSH: {
        _localctx = _tracker.createInstance<bellParser::ItemSublistContext>(_localctx);
        enterOuterAlt(_localctx, 14);
        setState(231);
        match(bellParser::PUSH);
        setState(232);
        sequence();
        setState(233);
        match(bellParser::POP);
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

tree::TerminalNode* bellParser::VarLocalContext::KEEP() {
  return getToken(bellParser::KEEP, 0);
}

tree::TerminalNode* bellParser::VarLocalContext::UNKEEP() {
  return getToken(bellParser::UNKEEP, 0);
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
  enterRule(_localctx, 30, bellParser::RuleVar);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(243);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::LOCALVAR:
      case bellParser::KEEP:
      case bellParser::UNKEEP: {
        _localctx = _tracker.createInstance<bellParser::VarLocalContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(238);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bellParser::KEEP

        || _la == bellParser::UNKEEP) {
          setState(237);
          _la = _input->LA(1);
          if (!(_la == bellParser::KEEP

          || _la == bellParser::UNKEEP)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        setState(240);
        match(bellParser::LOCALVAR);
        break;
      }

      case bellParser::PATCHERVAR: {
        _localctx = _tracker.createInstance<bellParser::VarPatcherContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(241);
        match(bellParser::PATCHERVAR);
        break;
      }

      case bellParser::GLOBALVAR: {
        _localctx = _tracker.createInstance<bellParser::VarGlobalContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(242);
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

std::vector<tree::TerminalNode *> bellParser::LvalueSpecsContext::KEY() {
  return getTokens(bellParser::KEY);
}

tree::TerminalNode* bellParser::LvalueSpecsContext::KEY(size_t i) {
  return getToken(bellParser::KEY, i);
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
  enterRule(_localctx, 32, bellParser::RuleLvalueSpecs);
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
    setState(268);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      ending = false;
      setState(251); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(246);
                _la = _input->LA(1);
                if (!(_la == bellParser::NTH

                || _la == bellParser::KEY)) {
                _errHandler->recoverInline(this);
                }
                else {
                  _errHandler->reportMatch(this);
                  consume();
                }
                setState(249);
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
                  case bellParser::INLET:
                  case bellParser::INTINLET:
                  case bellParser::RATINLET:
                  case bellParser::FLOATINLET:
                  case bellParser::PITCHINLET:
                  case bellParser::DIRINLET:
                  case bellParser::BIF:
                  case bellParser::OF:
                  case bellParser::ARGCOUNT:
                  case bellParser::PUSH:
                  case bellParser::OPEN: {
                    setState(247);
                    item();
                    break;
                  }

                  case bellParser::GLOBALVAR:
                  case bellParser::PATCHERVAR:
                  case bellParser::LOCALVAR:
                  case bellParser::KEEP:
                  case bellParser::UNKEEP: {
                    setState(248);
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
        setState(253); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      ending = true;
      setState(263);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(256);
          _la = _input->LA(1);
          if (!(_la == bellParser::NTH

          || _la == bellParser::KEY)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(259);
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
            case bellParser::INLET:
            case bellParser::INTINLET:
            case bellParser::RATINLET:
            case bellParser::FLOATINLET:
            case bellParser::PITCHINLET:
            case bellParser::DIRINLET:
            case bellParser::BIF:
            case bellParser::OF:
            case bellParser::ARGCOUNT:
            case bellParser::PUSH:
            case bellParser::OPEN: {
              setState(257);
              item();
              break;
            }

            case bellParser::GLOBALVAR:
            case bellParser::PATCHERVAR:
            case bellParser::LOCALVAR:
            case bellParser::KEEP:
            case bellParser::UNKEEP: {
              setState(258);
              var();
              break;
            }

          default:
            throw NoViableAltException(this);
          } 
        }
        setState(265);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      }

      setState(266);
      _la = _input->LA(1);
      if (!(_la == bellParser::NTH

      || _la == bellParser::KEY)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }

      setState(267);
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
  enterRule(_localctx, 34, bellParser::RuleLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(270);
    var();
    setState(272);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      setState(271);
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
  enterRule(_localctx, 36, bellParser::RuleFakeLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(274);
    item();
    setState(275);
    lvalueSpecs();
   
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

bellParser::FundefContext* bellParser::ListEndContext::fundef() {
  return getRuleContext<bellParser::FundefContext>(0);
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
  enterRule(_localctx, 38, bellParser::RuleListEnd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(281);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(277);
      conditional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(278);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(279);
      whileloop();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(280);
      fundef();
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

bellParser::FuncallContext* bellParser::ExprSimpleContext::funcall() {
  return getRuleContext<bellParser::FuncallContext>(0);
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

bellParser::ExprContext* bellParser::ExprNotContext::expr() {
  return getRuleContext<bellParser::ExprContext>(0);
}

tree::TerminalNode* bellParser::ExprNotContext::LOGNOT() {
  return getToken(bellParser::LOGNOT, 0);
}

tree::TerminalNode* bellParser::ExprNotContext::BITNOT() {
  return getToken(bellParser::BITNOT, 0);
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
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, bellParser::RuleExpr, precedence);

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
    setState(300);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprSimpleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(288);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
      case 1: {
        setState(284);
        item();
        break;
      }

      case 2: {
        setState(285);
        var();
        break;
      }

      case 3: {
        setState(286);
        funcall();
        break;
      }

      case 4: {
        setState(287);
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
      setState(290);
      lvalue();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ExprFakeLvalueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(291);
      fakeLvalue();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprUPlusMinusContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(293); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(292);
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
        setState(295); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(297);
      expr(15);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ExprNotContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(298);
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
      setState(299);
      expr(1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(349);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(347);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(302);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(303);
          match(bellParser::PICK);
          setState(304);
          expr(18);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(305);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(306);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::POW);
          setState(307);
          expr(16);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(308);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(309);
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
          setState(310);
          expr(15);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(311);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(312);
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
          setState(313);
          expr(14);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(314);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(315);
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
          setState(316);
          expr(13);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(317);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(318);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::RANGE);
          setState(319);
          expr(12);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(320);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(321);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::REPEAT);
          setState(322);
          expr(11);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(323);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(324);
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
          setState(325);
          expr(10);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(326);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(327);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 68) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 68)) & ((1ULL << (bellParser::LT - 68))
            | (1ULL << (bellParser::GT - 68))
            | (1ULL << (bellParser::LEQ - 68))
            | (1ULL << (bellParser::GEQ - 68)))) != 0))) {
            antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(328);
          expr(9);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(329);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(330);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::BITAND);
          setState(331);
          expr(8);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(332);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(333);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::BITXOR);
          setState(334);
          expr(7);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(335);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(336);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::BITOR);
          setState(337);
          expr(6);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(338);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(339);
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
          setState(340);
          expr(5);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(341);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(342);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::LOGXOR);
          setState(343);
          expr(4);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(344);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(345);
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
          setState(346);
          expr(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(351);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
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

//----------------- InitAssignmentContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::InitAssignmentContext::INIT() {
  return getToken(bellParser::INIT, 0);
}

tree::TerminalNode* bellParser::InitAssignmentContext::LOCALVAR() {
  return getToken(bellParser::LOCALVAR, 0);
}

tree::TerminalNode* bellParser::InitAssignmentContext::ASSIGN() {
  return getToken(bellParser::ASSIGN, 0);
}

bellParser::ListContext* bellParser::InitAssignmentContext::list() {
  return getRuleContext<bellParser::ListContext>(0);
}

bellParser::InitAssignmentContext::InitAssignmentContext(AssignmentContext *ctx) { copyFrom(ctx); }


std::any bellParser::InitAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitInitAssignment(this);
  else
    return visitor->visitChildren(this);
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
  enterRule(_localctx, 42, bellParser::RuleAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(370);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::INIT: {
        _localctx = _tracker.createInstance<bellParser::InitAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(352);
        match(bellParser::INIT);
        setState(353);
        match(bellParser::LOCALVAR);
        setState(354);
        match(bellParser::ASSIGN);
        setState(355);
        list();
        break;
      }

      case bellParser::GLOBALVAR:
      case bellParser::PATCHERVAR:
      case bellParser::LOCALVAR:
      case bellParser::KEEP:
      case bellParser::UNKEEP: {
        _localctx = _tracker.createInstance<bellParser::TrueAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(356);
        lvalue();
        setState(357);
        antlrcpp::downCast<TrueAssignmentContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 42) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 42)) & ((1ULL << (bellParser::ANTH - 42))
          | (1ULL << (bellParser::ASSIGN - 42))
          | (1ULL << (bellParser::APOW - 42))
          | (1ULL << (bellParser::ATIMES - 42))
          | (1ULL << (bellParser::ADIVDIV - 42))
          | (1ULL << (bellParser::ADIV - 42))
          | (1ULL << (bellParser::AREM - 42))
          | (1ULL << (bellParser::APLUS - 42))
          | (1ULL << (bellParser::AMINUS - 42))
          | (1ULL << (bellParser::ABITAND - 42))
          | (1ULL << (bellParser::ABITXOR - 42))
          | (1ULL << (bellParser::ABITOR - 42))
          | (1ULL << (bellParser::ALOGAND - 42))
          | (1ULL << (bellParser::ALOGANDEXT - 42))
          | (1ULL << (bellParser::ALOGXOR - 42))
          | (1ULL << (bellParser::ALOGOR - 42))
          | (1ULL << (bellParser::ALOGOREXT - 42))
          | (1ULL << (bellParser::ALSHIFT - 42))
          | (1ULL << (bellParser::ARSHIFT - 42))
          | (1ULL << (bellParser::ACONCAT - 42))
          | (1ULL << (bellParser::ARCONCAT - 42)))) != 0))) {
          antlrcpp::downCast<TrueAssignmentContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(358);
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
      case bellParser::INLET:
      case bellParser::INTINLET:
      case bellParser::RATINLET:
      case bellParser::FLOATINLET:
      case bellParser::PITCHINLET:
      case bellParser::DIRINLET:
      case bellParser::BIF:
      case bellParser::OF:
      case bellParser::ARGCOUNT:
      case bellParser::PUSH:
      case bellParser::OPEN: {
        _localctx = _tracker.createInstance<bellParser::FakeAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(360);
        fakeLvalue();
        setState(361);
        antlrcpp::downCast<FakeAssignmentContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 45) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 45)) & ((1ULL << (bellParser::ASSIGN - 45))
          | (1ULL << (bellParser::APOW - 45))
          | (1ULL << (bellParser::ATIMES - 45))
          | (1ULL << (bellParser::ADIVDIV - 45))
          | (1ULL << (bellParser::ADIV - 45))
          | (1ULL << (bellParser::AREM - 45))
          | (1ULL << (bellParser::APLUS - 45))
          | (1ULL << (bellParser::AMINUS - 45))
          | (1ULL << (bellParser::ABITAND - 45))
          | (1ULL << (bellParser::ABITXOR - 45))
          | (1ULL << (bellParser::ABITOR - 45))
          | (1ULL << (bellParser::ALOGAND - 45))
          | (1ULL << (bellParser::ALOGANDEXT - 45))
          | (1ULL << (bellParser::ALOGXOR - 45))
          | (1ULL << (bellParser::ALOGOR - 45))
          | (1ULL << (bellParser::ALOGOREXT - 45))
          | (1ULL << (bellParser::ALSHIFT - 45))
          | (1ULL << (bellParser::ARSHIFT - 45))
          | (1ULL << (bellParser::ACONCAT - 45))
          | (1ULL << (bellParser::ARCONCAT - 45)))) != 0))) {
          antlrcpp::downCast<FakeAssignmentContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(362);
        list();
        break;
      }

      case bellParser::OUTLET: {
        _localctx = _tracker.createInstance<bellParser::OutletAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(364);
        match(bellParser::OUTLET);
        setState(365);
        match(bellParser::ASSIGN);
        setState(366);
        list();
        break;
      }

      case bellParser::DIROUTLET: {
        _localctx = _tracker.createInstance<bellParser::DirOutletAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(367);
        match(bellParser::DIROUTLET);
        setState(368);
        match(bellParser::ASSIGN);
        setState(369);
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
  enterRule(_localctx, 44, bellParser::RuleConditional);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(384);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::IfthenContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(372);
      match(bellParser::IF);
      setState(373);
      sequence();
      setState(374);
      match(bellParser::THEN);
      setState(375);
      list();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::IfthenelseContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(377);
      match(bellParser::IF);
      setState(378);
      sequence();
      setState(379);
      match(bellParser::THEN);
      setState(380);
      sequence();
      setState(381);
      match(bellParser::ELSE);
      setState(382);
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
  enterRule(_localctx, 46, bellParser::RuleList);

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
    setState(387); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(386);
              expr(0);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(389); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
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
    case 11: return simpleFuncallSempred(antlrcpp::downCast<SimpleFuncallContext *>(context), predicateIndex);
    case 20: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool bellParser::simpleFuncallSempred(SimpleFuncallContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);
    case 2: return precpred(_ctx, 2);
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool bellParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 17);
    case 5: return precpred(_ctx, 16);
    case 6: return precpred(_ctx, 14);
    case 7: return precpred(_ctx, 13);
    case 8: return precpred(_ctx, 12);
    case 9: return precpred(_ctx, 11);
    case 10: return precpred(_ctx, 10);
    case 11: return precpred(_ctx, 9);
    case 12: return precpred(_ctx, 8);
    case 13: return precpred(_ctx, 7);
    case 14: return precpred(_ctx, 6);
    case 15: return precpred(_ctx, 5);
    case 16: return precpred(_ctx, 4);
    case 17: return precpred(_ctx, 3);
    case 18: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void bellParser::initialize() {
  std::call_once(bellParserOnceFlag, bellParserInitialize);
}
