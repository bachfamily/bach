
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
      "fundef", "sequence", "nullified", "whileloop", "forarg", "forargList", 
      "forloop", "argsByNameList", "argsByPositionList", "simpleFuncall", 
      "dataFlowItem", "funcall", "item", "var", "lvalueSpecs", "lvalue", 
      "fakeLvalue", "listEnd", "expr", "assignment", "conditional", "list"
    },
    std::vector<std::string>{
      "", "','", "'...'", "", "", "", "", "", "", "'null'", "'nil'", "'if'", 
      "'then'", "'else'", "'while'", "'for'", "'in'", "'as'", "'with'", 
      "'do'", "'collect'", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "'keep'", "'unkeep'", "'init'", "'$argcount'", "'['", "']'", 
      "')'", "':'", "'::'", "'.'", "':='", "'::='", "';'", "'='", "", "", 
      "'**'", "'**='", "'*'", "'*='", "'//'", "'//='", "'/'", "'/='", "", 
      "", "", "'+='", "'+'", "", "'-='", "'-'", "'=='", "'!='", "'!'", "'~'", 
      "'<'", "'>'", "'<='", "'>='", "'&'", "'&='", "'^'", "'^='", "'|'", 
      "'|='", "'&&'", "'&&&'", "'&&='", "'&&&='", "'^^'", "'^^='", "'||'", 
      "'||='", "'|||'", "'|||='", "'<<'", "'<<='", "'>>'", "'>>='", "':*'", 
      "':*='", "'.='", "'_='", "'!_='", "", "", "'->'", "'-^'", "'<...>'"
    },
    std::vector<std::string>{
      "", "", "RANGE", "UINT", "UFLOAT", "UPITCH", "BTSYMBOL", "DQSYMBOL", 
      "SQSYMBOL", "BACHNULL", "BACHNIL", "IF", "THEN", "ELSE", "WHILE", 
      "FOR", "IN", "AS", "WITH", "DO", "COLLECT", "INLET", "INTINLET", "RATINLET", 
      "FLOATINLET", "PITCHINLET", "OUTLET", "DIRINLET", "DIROUTLET", "BIF", 
      "OF", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "NAMEDPARAM", "KEEP", 
      "UNKEEP", "INIT", "ARGCOUNT", "PUSH", "POP", "CLOSED", "NTH", "PICK", 
      "KEY", "ANTH", "APICK", "NULLIFY", "ASSIGN", "WHITESPACE", "NEWATOM", 
      "POW", "APOW", "TIMES", "ATIMES", "DIVDIV", "ADIVDIV", "DIV", "ADIV", 
      "REM", "AREM", "PLUS", "APLUS", "UPLUS", "MINUS", "AMINUS", "UMINUS", 
      "EQUAL", "NEQ", "LOGNOT", "BITNOT", "LT", "GT", "LEQ", "GEQ", "BITAND", 
      "ABITAND", "BITXOR", "ABITXOR", "BITOR", "ABITOR", "LOGAND", "LOGANDEXT", 
      "ALOGAND", "ALOGANDEXT", "LOGXOR", "ALOGXOR", "LOGOR", "ALOGOR", "LOGOREXT", 
      "ALOGOREXT", "LSHIFT", "ALSHIFT", "RSHIFT", "ARSHIFT", "REPEAT", "AREPEAT", 
      "AAPPLY", "ACONCAT", "ARCONCAT", "OPEN", "PARAMS", "FUNDEF", "LIFT", 
      "ELLIPSIS", "ANYTHING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,105,443,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,1,0,1,0,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,3,1,65,8,1,1,2,1,2,1,2,3,2,70,8,2,1,2,3,2,73,
  	8,2,1,3,1,3,1,3,5,3,78,8,3,10,3,12,3,81,9,3,1,4,1,4,1,4,5,4,86,8,4,10,
  	4,12,4,89,9,4,1,4,1,4,1,5,1,5,3,5,95,8,5,1,5,1,5,1,5,1,6,1,6,4,6,102,
  	8,6,11,6,12,6,103,1,6,3,6,107,8,6,3,6,109,8,6,1,7,1,7,4,7,113,8,7,11,
  	7,12,7,114,1,8,1,8,1,8,1,8,1,8,1,9,1,9,3,9,124,8,9,1,9,1,9,1,9,1,10,1,
  	10,1,10,5,10,132,8,10,10,10,12,10,135,9,10,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,3,11,148,8,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,3,11,159,8,11,1,11,1,11,1,11,3,11,164,8,11,1,12,1,12,
  	1,12,3,12,169,8,12,1,12,1,12,5,12,173,8,12,10,12,12,12,176,9,12,1,13,
  	1,13,1,13,5,13,181,8,13,10,13,12,13,184,9,13,1,14,1,14,1,14,3,14,189,
  	8,14,1,14,1,14,1,14,1,14,1,14,3,14,196,8,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,3,14,204,8,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,212,8,14,1,14,1,
  	14,1,14,3,14,217,8,14,1,14,1,14,1,14,3,14,222,8,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,
  	241,8,14,1,14,1,14,1,14,5,14,246,8,14,10,14,12,14,249,9,14,1,15,1,15,
  	1,15,3,15,254,8,15,1,16,1,16,1,16,1,16,4,16,260,8,16,11,16,12,16,261,
  	3,16,264,8,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,
  	1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,3,17,286,8,17,1,18,3,18,
  	289,8,18,1,18,1,18,1,18,3,18,294,8,18,1,19,1,19,1,19,1,19,3,19,300,8,
  	19,4,19,302,8,19,11,19,12,19,303,1,19,1,19,1,19,1,19,3,19,310,8,19,5,
  	19,312,8,19,10,19,12,19,315,9,19,1,19,1,19,3,19,319,8,19,1,20,1,20,3,
  	20,323,8,20,1,21,1,21,1,21,1,22,1,22,1,22,1,22,1,22,3,22,333,8,22,1,23,
  	1,23,1,23,1,23,1,23,3,23,340,8,23,1,23,1,23,1,23,4,23,345,8,23,11,23,
  	12,23,346,1,23,1,23,1,23,3,23,352,8,23,1,23,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,5,23,399,8,23,
  	10,23,12,23,402,9,23,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,
  	1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,3,24,422,8,24,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,3,25,436,8,25,1,26,4,26,
  	439,8,26,11,26,12,26,440,1,26,0,2,28,46,27,0,2,4,6,8,10,12,14,16,18,20,
  	22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,0,16,1,0,19,20,1,0,7,
  	8,1,0,21,25,1,0,35,36,2,0,42,42,44,44,2,0,63,63,66,66,1,0,69,70,4,0,53,
  	53,55,55,57,57,59,59,2,0,61,61,64,64,2,0,91,91,93,93,1,0,67,68,1,0,71,
  	74,1,0,81,82,2,0,87,87,89,89,19,0,45,45,48,48,52,52,54,54,56,56,58,58,
  	60,60,62,62,65,65,76,76,78,78,80,80,83,84,86,86,88,88,90,90,92,92,94,
  	94,98,99,18,0,48,48,52,52,54,54,56,56,58,58,60,60,62,62,65,65,76,76,78,
  	78,80,80,83,84,86,86,88,88,90,90,92,92,94,94,98,99,508,0,54,1,0,0,0,2,
  	64,1,0,0,0,4,72,1,0,0,0,6,74,1,0,0,0,8,82,1,0,0,0,10,92,1,0,0,0,12,108,
  	1,0,0,0,14,110,1,0,0,0,16,116,1,0,0,0,18,121,1,0,0,0,20,128,1,0,0,0,22,
  	163,1,0,0,0,24,165,1,0,0,0,26,177,1,0,0,0,28,221,1,0,0,0,30,253,1,0,0,
  	0,32,263,1,0,0,0,34,285,1,0,0,0,36,293,1,0,0,0,38,318,1,0,0,0,40,320,
  	1,0,0,0,42,324,1,0,0,0,44,332,1,0,0,0,46,351,1,0,0,0,48,421,1,0,0,0,50,
  	435,1,0,0,0,52,438,1,0,0,0,54,55,3,2,1,0,55,1,1,0,0,0,56,65,5,0,0,1,57,
  	58,3,12,6,0,58,59,5,0,0,1,59,65,1,0,0,0,60,61,3,12,6,0,61,62,5,34,0,0,
  	62,65,1,0,0,0,63,65,5,34,0,0,64,56,1,0,0,0,64,57,1,0,0,0,64,60,1,0,0,
  	0,64,63,1,0,0,0,65,3,1,0,0,0,66,69,5,33,0,0,67,68,5,48,0,0,68,70,3,52,
  	26,0,69,67,1,0,0,0,69,70,1,0,0,0,70,73,1,0,0,0,71,73,5,104,0,0,72,66,
  	1,0,0,0,72,71,1,0,0,0,73,5,1,0,0,0,74,79,3,4,2,0,75,76,5,1,0,0,76,78,
  	3,4,2,0,77,75,1,0,0,0,78,81,1,0,0,0,79,77,1,0,0,0,79,80,1,0,0,0,80,7,
  	1,0,0,0,81,79,1,0,0,0,82,87,5,103,0,0,83,84,5,33,0,0,84,86,5,1,0,0,85,
  	83,1,0,0,0,86,89,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,90,1,0,0,0,89,
  	87,1,0,0,0,90,91,5,33,0,0,91,9,1,0,0,0,92,94,3,6,3,0,93,95,3,8,4,0,94,
  	93,1,0,0,0,94,95,1,0,0,0,95,96,1,0,0,0,96,97,5,102,0,0,97,98,3,52,26,
  	0,98,11,1,0,0,0,99,109,3,52,26,0,100,102,3,14,7,0,101,100,1,0,0,0,102,
  	103,1,0,0,0,103,101,1,0,0,0,103,104,1,0,0,0,104,106,1,0,0,0,105,107,3,
  	52,26,0,106,105,1,0,0,0,106,107,1,0,0,0,107,109,1,0,0,0,108,99,1,0,0,
  	0,108,101,1,0,0,0,109,13,1,0,0,0,110,112,3,52,26,0,111,113,5,47,0,0,112,
  	111,1,0,0,0,113,114,1,0,0,0,114,112,1,0,0,0,114,115,1,0,0,0,115,15,1,
  	0,0,0,116,117,5,14,0,0,117,118,3,12,6,0,118,119,7,0,0,0,119,120,3,52,
  	26,0,120,17,1,0,0,0,121,123,5,33,0,0,122,124,5,33,0,0,123,122,1,0,0,0,
  	123,124,1,0,0,0,124,125,1,0,0,0,125,126,5,16,0,0,126,127,3,12,6,0,127,
  	19,1,0,0,0,128,133,3,18,9,0,129,130,5,1,0,0,130,132,3,18,9,0,131,129,
  	1,0,0,0,132,135,1,0,0,0,133,131,1,0,0,0,133,134,1,0,0,0,134,21,1,0,0,
  	0,135,133,1,0,0,0,136,137,5,15,0,0,137,138,3,20,10,0,138,139,7,0,0,0,
  	139,140,3,52,26,0,140,164,1,0,0,0,141,142,5,15,0,0,142,143,3,20,10,0,
  	143,144,5,17,0,0,144,147,3,12,6,0,145,146,5,18,0,0,146,148,3,24,12,0,
  	147,145,1,0,0,0,147,148,1,0,0,0,148,149,1,0,0,0,149,150,7,0,0,0,150,151,
  	3,52,26,0,151,164,1,0,0,0,152,153,5,15,0,0,153,154,3,20,10,0,154,155,
  	5,18,0,0,155,158,3,24,12,0,156,157,5,17,0,0,157,159,3,12,6,0,158,156,
  	1,0,0,0,158,159,1,0,0,0,159,160,1,0,0,0,160,161,7,0,0,0,161,162,3,52,
  	26,0,162,164,1,0,0,0,163,136,1,0,0,0,163,141,1,0,0,0,163,152,1,0,0,0,
  	164,23,1,0,0,0,165,166,5,34,0,0,166,174,3,12,6,0,167,169,5,1,0,0,168,
  	167,1,0,0,0,168,169,1,0,0,0,169,170,1,0,0,0,170,171,5,34,0,0,171,173,
  	3,12,6,0,172,168,1,0,0,0,173,176,1,0,0,0,174,172,1,0,0,0,174,175,1,0,
  	0,0,175,25,1,0,0,0,176,174,1,0,0,0,177,182,3,12,6,0,178,179,5,1,0,0,179,
  	181,3,12,6,0,180,178,1,0,0,0,181,184,1,0,0,0,182,180,1,0,0,0,182,183,
  	1,0,0,0,183,27,1,0,0,0,184,182,1,0,0,0,185,188,6,14,-1,0,186,189,3,34,
  	17,0,187,189,3,36,18,0,188,186,1,0,0,0,188,187,1,0,0,0,189,190,1,0,0,
  	0,190,191,5,101,0,0,191,192,5,41,0,0,192,222,1,0,0,0,193,196,3,34,17,
  	0,194,196,3,36,18,0,195,193,1,0,0,0,195,194,1,0,0,0,196,197,1,0,0,0,197,
  	198,5,101,0,0,198,199,3,26,13,0,199,200,5,41,0,0,200,222,1,0,0,0,201,
  	204,3,34,17,0,202,204,3,36,18,0,203,201,1,0,0,0,203,202,1,0,0,0,204,205,
  	1,0,0,0,205,206,5,101,0,0,206,207,3,24,12,0,207,208,5,41,0,0,208,222,
  	1,0,0,0,209,212,3,34,17,0,210,212,3,36,18,0,211,209,1,0,0,0,211,210,1,
  	0,0,0,212,213,1,0,0,0,213,214,5,101,0,0,214,216,3,26,13,0,215,217,5,1,
  	0,0,216,215,1,0,0,0,216,217,1,0,0,0,217,218,1,0,0,0,218,219,3,24,12,0,
  	219,220,5,41,0,0,220,222,1,0,0,0,221,185,1,0,0,0,221,195,1,0,0,0,221,
  	203,1,0,0,0,221,211,1,0,0,0,222,247,1,0,0,0,223,224,10,4,0,0,224,225,
  	5,101,0,0,225,246,5,41,0,0,226,227,10,3,0,0,227,228,5,101,0,0,228,229,
  	3,26,13,0,229,230,5,41,0,0,230,246,1,0,0,0,231,232,10,2,0,0,232,233,5,
  	101,0,0,233,234,3,24,12,0,234,235,5,41,0,0,235,246,1,0,0,0,236,237,10,
  	1,0,0,237,238,5,101,0,0,238,240,3,26,13,0,239,241,5,1,0,0,240,239,1,0,
  	0,0,240,241,1,0,0,0,241,242,1,0,0,0,242,243,3,24,12,0,243,244,5,41,0,
  	0,244,246,1,0,0,0,245,223,1,0,0,0,245,226,1,0,0,0,245,231,1,0,0,0,245,
  	236,1,0,0,0,246,249,1,0,0,0,247,245,1,0,0,0,247,248,1,0,0,0,248,29,1,
  	0,0,0,249,247,1,0,0,0,250,254,3,34,17,0,251,254,3,36,18,0,252,254,3,28,
  	14,0,253,250,1,0,0,0,253,251,1,0,0,0,253,252,1,0,0,0,254,31,1,0,0,0,255,
  	264,3,28,14,0,256,259,3,30,15,0,257,258,5,44,0,0,258,260,3,28,14,0,259,
  	257,1,0,0,0,260,261,1,0,0,0,261,259,1,0,0,0,261,262,1,0,0,0,262,264,1,
  	0,0,0,263,255,1,0,0,0,263,256,1,0,0,0,264,33,1,0,0,0,265,286,5,3,0,0,
  	266,286,5,4,0,0,267,286,5,5,0,0,268,286,5,6,0,0,269,286,7,1,0,0,270,286,
  	5,29,0,0,271,286,5,30,0,0,272,286,7,2,0,0,273,286,5,27,0,0,274,286,5,
  	38,0,0,275,286,5,9,0,0,276,286,5,10,0,0,277,278,5,100,0,0,278,279,3,12,
  	6,0,279,280,5,41,0,0,280,286,1,0,0,0,281,282,5,39,0,0,282,283,3,12,6,
  	0,283,284,5,40,0,0,284,286,1,0,0,0,285,265,1,0,0,0,285,266,1,0,0,0,285,
  	267,1,0,0,0,285,268,1,0,0,0,285,269,1,0,0,0,285,270,1,0,0,0,285,271,1,
  	0,0,0,285,272,1,0,0,0,285,273,1,0,0,0,285,274,1,0,0,0,285,275,1,0,0,0,
  	285,276,1,0,0,0,285,277,1,0,0,0,285,281,1,0,0,0,286,35,1,0,0,0,287,289,
  	7,3,0,0,288,287,1,0,0,0,288,289,1,0,0,0,289,290,1,0,0,0,290,294,5,33,
  	0,0,291,294,5,32,0,0,292,294,5,31,0,0,293,288,1,0,0,0,293,291,1,0,0,0,
  	293,292,1,0,0,0,294,37,1,0,0,0,295,301,6,19,-1,0,296,299,7,4,0,0,297,
  	300,3,34,17,0,298,300,3,36,18,0,299,297,1,0,0,0,299,298,1,0,0,0,300,302,
  	1,0,0,0,301,296,1,0,0,0,302,303,1,0,0,0,303,301,1,0,0,0,303,304,1,0,0,
  	0,304,319,1,0,0,0,305,313,6,19,-1,0,306,309,7,4,0,0,307,310,3,34,17,0,
  	308,310,3,36,18,0,309,307,1,0,0,0,309,308,1,0,0,0,310,312,1,0,0,0,311,
  	306,1,0,0,0,312,315,1,0,0,0,313,311,1,0,0,0,313,314,1,0,0,0,314,316,1,
  	0,0,0,315,313,1,0,0,0,316,317,7,4,0,0,317,319,3,50,25,0,318,295,1,0,0,
  	0,318,305,1,0,0,0,319,39,1,0,0,0,320,322,3,36,18,0,321,323,3,38,19,0,
  	322,321,1,0,0,0,322,323,1,0,0,0,323,41,1,0,0,0,324,325,3,34,17,0,325,
  	326,3,38,19,0,326,43,1,0,0,0,327,333,3,50,25,0,328,333,3,48,24,0,329,
  	333,3,16,8,0,330,333,3,22,11,0,331,333,3,10,5,0,332,327,1,0,0,0,332,328,
  	1,0,0,0,332,329,1,0,0,0,332,330,1,0,0,0,332,331,1,0,0,0,333,45,1,0,0,
  	0,334,339,6,23,-1,0,335,340,3,34,17,0,336,340,3,36,18,0,337,340,3,32,
  	16,0,338,340,3,44,22,0,339,335,1,0,0,0,339,336,1,0,0,0,339,337,1,0,0,
  	0,339,338,1,0,0,0,340,352,1,0,0,0,341,352,3,40,20,0,342,352,3,42,21,0,
  	343,345,7,5,0,0,344,343,1,0,0,0,345,346,1,0,0,0,346,344,1,0,0,0,346,347,
  	1,0,0,0,347,348,1,0,0,0,348,352,3,46,23,15,349,350,7,6,0,0,350,352,3,
  	46,23,1,351,334,1,0,0,0,351,341,1,0,0,0,351,342,1,0,0,0,351,344,1,0,0,
  	0,351,349,1,0,0,0,352,400,1,0,0,0,353,354,10,17,0,0,354,355,5,43,0,0,
  	355,399,3,46,23,18,356,357,10,16,0,0,357,358,5,51,0,0,358,399,3,46,23,
  	16,359,360,10,14,0,0,360,361,7,7,0,0,361,399,3,46,23,15,362,363,10,13,
  	0,0,363,364,7,8,0,0,364,399,3,46,23,14,365,366,10,12,0,0,366,367,7,9,
  	0,0,367,399,3,46,23,13,368,369,10,11,0,0,369,370,5,2,0,0,370,399,3,46,
  	23,12,371,372,10,10,0,0,372,373,5,95,0,0,373,399,3,46,23,11,374,375,10,
  	9,0,0,375,376,7,10,0,0,376,399,3,46,23,10,377,378,10,8,0,0,378,379,7,
  	11,0,0,379,399,3,46,23,9,380,381,10,7,0,0,381,382,5,75,0,0,382,399,3,
  	46,23,8,383,384,10,6,0,0,384,385,5,77,0,0,385,399,3,46,23,7,386,387,10,
  	5,0,0,387,388,5,79,0,0,388,399,3,46,23,6,389,390,10,4,0,0,390,391,7,12,
  	0,0,391,399,3,46,23,5,392,393,10,3,0,0,393,394,5,85,0,0,394,399,3,46,
  	23,4,395,396,10,2,0,0,396,397,7,13,0,0,397,399,3,46,23,3,398,353,1,0,
  	0,0,398,356,1,0,0,0,398,359,1,0,0,0,398,362,1,0,0,0,398,365,1,0,0,0,398,
  	368,1,0,0,0,398,371,1,0,0,0,398,374,1,0,0,0,398,377,1,0,0,0,398,380,1,
  	0,0,0,398,383,1,0,0,0,398,386,1,0,0,0,398,389,1,0,0,0,398,392,1,0,0,0,
  	398,395,1,0,0,0,399,402,1,0,0,0,400,398,1,0,0,0,400,401,1,0,0,0,401,47,
  	1,0,0,0,402,400,1,0,0,0,403,404,5,37,0,0,404,405,5,33,0,0,405,406,5,48,
  	0,0,406,422,3,52,26,0,407,408,3,40,20,0,408,409,7,14,0,0,409,410,3,52,
  	26,0,410,422,1,0,0,0,411,412,3,42,21,0,412,413,7,15,0,0,413,414,3,52,
  	26,0,414,422,1,0,0,0,415,416,5,26,0,0,416,417,5,48,0,0,417,422,3,52,26,
  	0,418,419,5,28,0,0,419,420,5,48,0,0,420,422,3,52,26,0,421,403,1,0,0,0,
  	421,407,1,0,0,0,421,411,1,0,0,0,421,415,1,0,0,0,421,418,1,0,0,0,422,49,
  	1,0,0,0,423,424,5,11,0,0,424,425,3,12,6,0,425,426,5,12,0,0,426,427,3,
  	52,26,0,427,436,1,0,0,0,428,429,5,11,0,0,429,430,3,12,6,0,430,431,5,12,
  	0,0,431,432,3,12,6,0,432,433,5,13,0,0,433,434,3,52,26,0,434,436,1,0,0,
  	0,435,423,1,0,0,0,435,428,1,0,0,0,436,51,1,0,0,0,437,439,3,46,23,0,438,
  	437,1,0,0,0,439,440,1,0,0,0,440,438,1,0,0,0,440,441,1,0,0,0,441,53,1,
  	0,0,0,48,64,69,72,79,87,94,103,106,108,114,123,133,147,158,163,168,174,
  	182,188,195,203,211,216,221,240,245,247,253,261,263,285,288,293,299,303,
  	309,313,318,322,332,339,346,351,398,400,421,435,440
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
    setState(54);
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
    setState(64);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::ProgramEOFContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(56);
      match(bellParser::EOF);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::ProgramSequenceContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(57);
      sequence();
      setState(58);
      match(bellParser::EOF);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<bellParser::ProgramSequenceNamedparamContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(60);
      sequence();
      setState(61);
      match(bellParser::NAMEDPARAM);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<bellParser::ProgramNamedparamContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(63);
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
    setState(72);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::LOCALVAR: {
        _localctx = _tracker.createInstance<bellParser::FunargVarContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(66);
        match(bellParser::LOCALVAR);
        setState(69);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bellParser::ASSIGN) {
          setState(67);
          match(bellParser::ASSIGN);
          setState(68);
          list();
        }
        break;
      }

      case bellParser::ELLIPSIS: {
        _localctx = _tracker.createInstance<bellParser::FunargEllipsisContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(71);
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
    setState(74);
    funarg();
    setState(79);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::T__0) {
      setState(75);
      match(bellParser::T__0);
      setState(76);
      funarg();
      setState(81);
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
    setState(82);
    match(bellParser::LIFT);
    setState(87);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(83);
        match(bellParser::LOCALVAR);
        setState(84);
        match(bellParser::T__0); 
      }
      setState(89);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(90);
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
    setState(92);
    funargList();
    setState(94);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == bellParser::LIFT) {
      setState(93);
      liftedargList();
    }
    setState(96);
    match(bellParser::FUNDEF);
    setState(97);
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
    setState(108);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(99);
      list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(101); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(100);
                nullified();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(103); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(106);
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
        | (1ULL << bellParser::FOR)
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
        | (1ULL << bellParser::UPLUS))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 66)) & ((1ULL << (bellParser::UMINUS - 66))
        | (1ULL << (bellParser::LOGNOT - 66))
        | (1ULL << (bellParser::BITNOT - 66))
        | (1ULL << (bellParser::OPEN - 66))
        | (1ULL << (bellParser::ELLIPSIS - 66)))) != 0)) {
        setState(105);
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
    setState(110);
    list();
    setState(112); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(111);
      match(bellParser::NULLIFY);
      setState(114); 
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
    setState(116);
    match(bellParser::WHILE);
    setState(117);
    sequence();
    setState(118);
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
    setState(119);
    list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForargContext ------------------------------------------------------------------

bellParser::ForargContext::ForargContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> bellParser::ForargContext::LOCALVAR() {
  return getTokens(bellParser::LOCALVAR);
}

tree::TerminalNode* bellParser::ForargContext::LOCALVAR(size_t i) {
  return getToken(bellParser::LOCALVAR, i);
}

tree::TerminalNode* bellParser::ForargContext::IN() {
  return getToken(bellParser::IN, 0);
}

bellParser::SequenceContext* bellParser::ForargContext::sequence() {
  return getRuleContext<bellParser::SequenceContext>(0);
}


size_t bellParser::ForargContext::getRuleIndex() const {
  return bellParser::RuleForarg;
}


std::any bellParser::ForargContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitForarg(this);
  else
    return visitor->visitChildren(this);
}

bellParser::ForargContext* bellParser::forarg() {
  ForargContext *_localctx = _tracker.createInstance<ForargContext>(_ctx, getState());
  enterRule(_localctx, 18, bellParser::RuleForarg);
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
    setState(121);
    match(bellParser::LOCALVAR);

    setState(123);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == bellParser::LOCALVAR) {
      setState(122);
      match(bellParser::LOCALVAR);
    }
    setState(125);
    match(bellParser::IN);
    setState(126);
    sequence();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForargListContext ------------------------------------------------------------------

bellParser::ForargListContext::ForargListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<bellParser::ForargContext *> bellParser::ForargListContext::forarg() {
  return getRuleContexts<bellParser::ForargContext>();
}

bellParser::ForargContext* bellParser::ForargListContext::forarg(size_t i) {
  return getRuleContext<bellParser::ForargContext>(i);
}


size_t bellParser::ForargListContext::getRuleIndex() const {
  return bellParser::RuleForargList;
}


std::any bellParser::ForargListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitForargList(this);
  else
    return visitor->visitChildren(this);
}

bellParser::ForargListContext* bellParser::forargList() {
  ForargListContext *_localctx = _tracker.createInstance<ForargListContext>(_ctx, getState());
  enterRule(_localctx, 20, bellParser::RuleForargList);
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
    setState(128);
    forarg();
    setState(133);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::T__0) {
      setState(129);
      match(bellParser::T__0);
      setState(130);
      forarg();
      setState(135);
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

//----------------- ForloopContext ------------------------------------------------------------------

bellParser::ForloopContext::ForloopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bellParser::ForloopContext::FOR() {
  return getToken(bellParser::FOR, 0);
}

bellParser::ForargListContext* bellParser::ForloopContext::forargList() {
  return getRuleContext<bellParser::ForargListContext>(0);
}

bellParser::ListContext* bellParser::ForloopContext::list() {
  return getRuleContext<bellParser::ListContext>(0);
}

tree::TerminalNode* bellParser::ForloopContext::DO() {
  return getToken(bellParser::DO, 0);
}

tree::TerminalNode* bellParser::ForloopContext::COLLECT() {
  return getToken(bellParser::COLLECT, 0);
}

tree::TerminalNode* bellParser::ForloopContext::AS() {
  return getToken(bellParser::AS, 0);
}

bellParser::SequenceContext* bellParser::ForloopContext::sequence() {
  return getRuleContext<bellParser::SequenceContext>(0);
}

tree::TerminalNode* bellParser::ForloopContext::WITH() {
  return getToken(bellParser::WITH, 0);
}

bellParser::ArgsByNameListContext* bellParser::ForloopContext::argsByNameList() {
  return getRuleContext<bellParser::ArgsByNameListContext>(0);
}


size_t bellParser::ForloopContext::getRuleIndex() const {
  return bellParser::RuleForloop;
}


std::any bellParser::ForloopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitForloop(this);
  else
    return visitor->visitChildren(this);
}

bellParser::ForloopContext* bellParser::forloop() {
  ForloopContext *_localctx = _tracker.createInstance<ForloopContext>(_ctx, getState());
  enterRule(_localctx, 22, bellParser::RuleForloop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(163);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(136);
      match(bellParser::FOR);
      setState(137);
      forargList();
      setState(138);
      antlrcpp::downCast<ForloopContext *>(_localctx)->kind = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == bellParser::DO

      || _la == bellParser::COLLECT)) {
        antlrcpp::downCast<ForloopContext *>(_localctx)->kind = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(139);
      list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(141);
      match(bellParser::FOR);
      setState(142);
      forargList();
      setState(143);
      match(bellParser::AS);
      setState(144);
      sequence();
      setState(147);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::WITH) {
        setState(145);
        match(bellParser::WITH);
        setState(146);
        argsByNameList();
      }
      setState(149);
      antlrcpp::downCast<ForloopContext *>(_localctx)->kind = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == bellParser::DO

      || _la == bellParser::COLLECT)) {
        antlrcpp::downCast<ForloopContext *>(_localctx)->kind = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(150);
      list();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(152);
      match(bellParser::FOR);
      setState(153);
      forargList();
      setState(154);
      match(bellParser::WITH);
      setState(155);
      argsByNameList();
      setState(158);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::AS) {
        setState(156);
        match(bellParser::AS);
        setState(157);
        sequence();
      }
      setState(160);
      antlrcpp::downCast<ForloopContext *>(_localctx)->kind = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == bellParser::DO

      || _la == bellParser::COLLECT)) {
        antlrcpp::downCast<ForloopContext *>(_localctx)->kind = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(161);
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
  enterRule(_localctx, 24, bellParser::RuleArgsByNameList);
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
    setState(165);
    match(bellParser::NAMEDPARAM);
    setState(166);
    sequence();
    setState(174);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::T__0

    || _la == bellParser::NAMEDPARAM) {
      setState(168);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::T__0) {
        setState(167);
        match(bellParser::T__0);
      }
      setState(170);
      match(bellParser::NAMEDPARAM);
      setState(171);
      sequence();
      setState(176);
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
  enterRule(_localctx, 26, bellParser::RuleArgsByPositionList);

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
    setState(177);
    sequence();
    setState(182);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(178);
        match(bellParser::T__0);
        setState(179);
        sequence(); 
      }
      setState(184);
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
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, bellParser::RuleSimpleFuncall, precedence);

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
    setState(221);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(188);
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
          setState(186);
          item();
          break;
        }

        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR:
        case bellParser::KEEP:
        case bellParser::UNKEEP: {
          setState(187);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(190);
      match(bellParser::PARAMS);
      setState(191);
      match(bellParser::CLOSED);
      break;
    }

    case 2: {
      setState(195);
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
          setState(193);
          item();
          break;
        }

        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR:
        case bellParser::KEEP:
        case bellParser::UNKEEP: {
          setState(194);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(197);
      match(bellParser::PARAMS);
      setState(198);
      argsByPositionList();
      setState(199);
      match(bellParser::CLOSED);
      break;
    }

    case 3: {
      setState(203);
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
          setState(201);
          item();
          break;
        }

        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR:
        case bellParser::KEEP:
        case bellParser::UNKEEP: {
          setState(202);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(205);
      match(bellParser::PARAMS);
      setState(206);
      argsByNameList();
      setState(207);
      match(bellParser::CLOSED);
      break;
    }

    case 4: {
      setState(211);
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
          setState(209);
          item();
          break;
        }

        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR:
        case bellParser::KEEP:
        case bellParser::UNKEEP: {
          setState(210);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(213);
      match(bellParser::PARAMS);
      setState(214);
      argsByPositionList();
      setState(216);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::T__0) {
        setState(215);
        match(bellParser::T__0);
      }
      setState(218);
      argsByNameList();
      setState(219);
      match(bellParser::CLOSED);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(247);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(245);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(223);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(224);
          match(bellParser::PARAMS);
          setState(225);
          match(bellParser::CLOSED);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(226);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(227);
          match(bellParser::PARAMS);
          setState(228);
          argsByPositionList();
          setState(229);
          match(bellParser::CLOSED);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(231);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(232);
          match(bellParser::PARAMS);
          setState(233);
          argsByNameList();
          setState(234);
          match(bellParser::CLOSED);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(236);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(237);
          match(bellParser::PARAMS);
          setState(238);
          argsByPositionList();
          setState(240);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == bellParser::T__0) {
            setState(239);
            match(bellParser::T__0);
          }
          setState(242);
          argsByNameList();
          setState(243);
          match(bellParser::CLOSED);
          break;
        }

        default:
          break;
        } 
      }
      setState(249);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
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
  enterRule(_localctx, 30, bellParser::RuleDataFlowItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(253);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(250);
      item();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(251);
      var();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(252);
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
  enterRule(_localctx, 32, bellParser::RuleFuncall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(263);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(255);
      simpleFuncall(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(256);
      dataFlowItem();
      setState(259); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(257);
                match(bellParser::KEY);
                setState(258);
                simpleFuncall(0);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(261); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
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
  enterRule(_localctx, 34, bellParser::RuleItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(285);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::UINT: {
        _localctx = _tracker.createInstance<bellParser::ItemUintContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(265);
        match(bellParser::UINT);
        break;
      }

      case bellParser::UFLOAT: {
        _localctx = _tracker.createInstance<bellParser::ItemUfloatContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(266);
        match(bellParser::UFLOAT);
        break;
      }

      case bellParser::UPITCH: {
        _localctx = _tracker.createInstance<bellParser::ItemUpitchContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(267);
        match(bellParser::UPITCH);
        break;
      }

      case bellParser::BTSYMBOL: {
        _localctx = _tracker.createInstance<bellParser::ItemBtSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(268);
        match(bellParser::BTSYMBOL);
        break;
      }

      case bellParser::DQSYMBOL:
      case bellParser::SQSYMBOL: {
        _localctx = _tracker.createInstance<bellParser::ItemQSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(269);
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
        setState(270);
        match(bellParser::BIF);
        break;
      }

      case bellParser::OF: {
        _localctx = _tracker.createInstance<bellParser::ItemOFContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(271);
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
        setState(272);
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
        setState(273);
        match(bellParser::DIRINLET);
        break;
      }

      case bellParser::ARGCOUNT: {
        _localctx = _tracker.createInstance<bellParser::ItemArgcountContext>(_localctx);
        enterOuterAlt(_localctx, 10);
        setState(274);
        match(bellParser::ARGCOUNT);
        break;
      }

      case bellParser::BACHNULL: {
        _localctx = _tracker.createInstance<bellParser::ItemNullContext>(_localctx);
        enterOuterAlt(_localctx, 11);
        setState(275);
        match(bellParser::BACHNULL);
        break;
      }

      case bellParser::BACHNIL: {
        _localctx = _tracker.createInstance<bellParser::ItemNilContext>(_localctx);
        enterOuterAlt(_localctx, 12);
        setState(276);
        match(bellParser::BACHNIL);
        break;
      }

      case bellParser::OPEN: {
        _localctx = _tracker.createInstance<bellParser::ItemSequenceContext>(_localctx);
        enterOuterAlt(_localctx, 13);
        setState(277);
        match(bellParser::OPEN);
        setState(278);
        sequence();
        setState(279);
        match(bellParser::CLOSED);
        break;
      }

      case bellParser::PUSH: {
        _localctx = _tracker.createInstance<bellParser::ItemSublistContext>(_localctx);
        enterOuterAlt(_localctx, 14);
        setState(281);
        match(bellParser::PUSH);
        setState(282);
        sequence();
        setState(283);
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
  enterRule(_localctx, 36, bellParser::RuleVar);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(293);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::LOCALVAR:
      case bellParser::KEEP:
      case bellParser::UNKEEP: {
        _localctx = _tracker.createInstance<bellParser::VarLocalContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(288);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bellParser::KEEP

        || _la == bellParser::UNKEEP) {
          setState(287);
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
        setState(290);
        match(bellParser::LOCALVAR);
        break;
      }

      case bellParser::PATCHERVAR: {
        _localctx = _tracker.createInstance<bellParser::VarPatcherContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(291);
        match(bellParser::PATCHERVAR);
        break;
      }

      case bellParser::GLOBALVAR: {
        _localctx = _tracker.createInstance<bellParser::VarGlobalContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(292);
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
  enterRule(_localctx, 38, bellParser::RuleLvalueSpecs);
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
    setState(318);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      ending = false;
      setState(301); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(296);
                _la = _input->LA(1);
                if (!(_la == bellParser::NTH

                || _la == bellParser::KEY)) {
                _errHandler->recoverInline(this);
                }
                else {
                  _errHandler->reportMatch(this);
                  consume();
                }
                setState(299);
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
                    setState(297);
                    item();
                    break;
                  }

                  case bellParser::GLOBALVAR:
                  case bellParser::PATCHERVAR:
                  case bellParser::LOCALVAR:
                  case bellParser::KEEP:
                  case bellParser::UNKEEP: {
                    setState(298);
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
        setState(303); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      ending = true;
      setState(313);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(306);
          _la = _input->LA(1);
          if (!(_la == bellParser::NTH

          || _la == bellParser::KEY)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(309);
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
              setState(307);
              item();
              break;
            }

            case bellParser::GLOBALVAR:
            case bellParser::PATCHERVAR:
            case bellParser::LOCALVAR:
            case bellParser::KEEP:
            case bellParser::UNKEEP: {
              setState(308);
              var();
              break;
            }

          default:
            throw NoViableAltException(this);
          } 
        }
        setState(315);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
      }

      setState(316);
      _la = _input->LA(1);
      if (!(_la == bellParser::NTH

      || _la == bellParser::KEY)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }

      setState(317);
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
  enterRule(_localctx, 40, bellParser::RuleLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(320);
    var();
    setState(322);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(321);
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
  enterRule(_localctx, 42, bellParser::RuleFakeLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    item();
    setState(325);
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

bellParser::ForloopContext* bellParser::ListEndContext::forloop() {
  return getRuleContext<bellParser::ForloopContext>(0);
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
  enterRule(_localctx, 44, bellParser::RuleListEnd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(332);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(327);
      conditional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(328);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(329);
      whileloop();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(330);
      forloop();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(331);
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
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, bellParser::RuleExpr, precedence);

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
    setState(351);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprSimpleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(339);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
      case 1: {
        setState(335);
        item();
        break;
      }

      case 2: {
        setState(336);
        var();
        break;
      }

      case 3: {
        setState(337);
        funcall();
        break;
      }

      case 4: {
        setState(338);
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
      setState(341);
      lvalue();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ExprFakeLvalueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(342);
      fakeLvalue();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprUPlusMinusContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(344); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(343);
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
        setState(346); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(348);
      expr(15);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ExprNotContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(349);
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
      setState(350);
      expr(1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(400);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(398);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(353);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(354);
          match(bellParser::PICK);
          setState(355);
          expr(18);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(356);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(357);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::POW);
          setState(358);
          expr(16);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(359);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(360);
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
          setState(361);
          expr(15);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(362);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(363);
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
          setState(364);
          expr(14);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(365);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(366);
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
          setState(367);
          expr(13);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(368);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(369);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::RANGE);
          setState(370);
          expr(12);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(371);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(372);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::REPEAT);
          setState(373);
          expr(11);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(374);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(375);
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
          setState(376);
          expr(10);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(377);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(378);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 71) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 71)) & ((1ULL << (bellParser::LT - 71))
            | (1ULL << (bellParser::GT - 71))
            | (1ULL << (bellParser::LEQ - 71))
            | (1ULL << (bellParser::GEQ - 71)))) != 0))) {
            antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(379);
          expr(9);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(380);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(381);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::BITAND);
          setState(382);
          expr(8);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(383);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(384);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::BITXOR);
          setState(385);
          expr(7);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(386);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(387);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::BITOR);
          setState(388);
          expr(6);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(389);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(390);
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
          setState(391);
          expr(5);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(392);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(393);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::LOGXOR);
          setState(394);
          expr(4);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(395);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(396);
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
          setState(397);
          expr(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(402);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
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
  enterRule(_localctx, 48, bellParser::RuleAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(421);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::INIT: {
        _localctx = _tracker.createInstance<bellParser::InitAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(403);
        match(bellParser::INIT);
        setState(404);
        match(bellParser::LOCALVAR);
        setState(405);
        match(bellParser::ASSIGN);
        setState(406);
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
        setState(407);
        lvalue();
        setState(408);
        antlrcpp::downCast<TrueAssignmentContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 45) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 45)) & ((1ULL << (bellParser::ANTH - 45))
          | (1ULL << (bellParser::ASSIGN - 45))
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
          antlrcpp::downCast<TrueAssignmentContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(409);
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
        setState(411);
        fakeLvalue();
        setState(412);
        antlrcpp::downCast<FakeAssignmentContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 48) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 48)) & ((1ULL << (bellParser::ASSIGN - 48))
          | (1ULL << (bellParser::APOW - 48))
          | (1ULL << (bellParser::ATIMES - 48))
          | (1ULL << (bellParser::ADIVDIV - 48))
          | (1ULL << (bellParser::ADIV - 48))
          | (1ULL << (bellParser::AREM - 48))
          | (1ULL << (bellParser::APLUS - 48))
          | (1ULL << (bellParser::AMINUS - 48))
          | (1ULL << (bellParser::ABITAND - 48))
          | (1ULL << (bellParser::ABITXOR - 48))
          | (1ULL << (bellParser::ABITOR - 48))
          | (1ULL << (bellParser::ALOGAND - 48))
          | (1ULL << (bellParser::ALOGANDEXT - 48))
          | (1ULL << (bellParser::ALOGXOR - 48))
          | (1ULL << (bellParser::ALOGOR - 48))
          | (1ULL << (bellParser::ALOGOREXT - 48))
          | (1ULL << (bellParser::ALSHIFT - 48))
          | (1ULL << (bellParser::ARSHIFT - 48))
          | (1ULL << (bellParser::ACONCAT - 48))
          | (1ULL << (bellParser::ARCONCAT - 48)))) != 0))) {
          antlrcpp::downCast<FakeAssignmentContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(413);
        list();
        break;
      }

      case bellParser::OUTLET: {
        _localctx = _tracker.createInstance<bellParser::OutletAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(415);
        match(bellParser::OUTLET);
        setState(416);
        match(bellParser::ASSIGN);
        setState(417);
        list();
        break;
      }

      case bellParser::DIROUTLET: {
        _localctx = _tracker.createInstance<bellParser::DirOutletAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(418);
        match(bellParser::DIROUTLET);
        setState(419);
        match(bellParser::ASSIGN);
        setState(420);
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
  enterRule(_localctx, 50, bellParser::RuleConditional);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(435);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::IfthenContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(423);
      match(bellParser::IF);
      setState(424);
      sequence();
      setState(425);
      match(bellParser::THEN);
      setState(426);
      list();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::IfthenelseContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(428);
      match(bellParser::IF);
      setState(429);
      sequence();
      setState(430);
      match(bellParser::THEN);
      setState(431);
      sequence();
      setState(432);
      match(bellParser::ELSE);
      setState(433);
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
  enterRule(_localctx, 52, bellParser::RuleList);

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
    setState(438); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(437);
              expr(0);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(440); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
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
    case 14: return simpleFuncallSempred(antlrcpp::downCast<SimpleFuncallContext *>(context), predicateIndex);
    case 23: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

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
