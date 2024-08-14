
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
      "dataFlowAndLvalueSpecsUItem", "dataFlowAndLvalueSpecsItem", "funcall", 
      "var", "lvalueSpecsUFinal", "lvalueSpecsFinal", "lvalueSpecs", "lvalue", 
      "fakeLvalue", "listEnd", "expr", "literal", "llll", "item", "assignment", 
      "conditional", "list"
    },
    std::vector<std::string>{
      "", "','", "'...'", "", "", "", "'pi'", "", "", "", "", "'null'", 
      "'nil'", "'if'", "'then'", "'else'", "'while'", "'for'", "'in'", "'as'", 
      "'with'", "'do'", "'collect'", "", "", "", "", "", "", "", "", "", 
      "", "'$argcount'", "'keep'", "'unkeep'", "'init'", "", "", "", "", 
      "'['", "']'", "')'", "':'", "'::'", "'.'", "':='", "'::='", "';'", 
      "'='", "", "", "'**'", "'**='", "'*'", "'*='", "'//'", "'//='", "'/'", 
      "'/='", "'%'", "'%='", "", "'+='", "'+'", "", "'-='", "'-'", "'=='", 
      "'!='", "'!'", "'~'", "'<'", "'>'", "'<='", "'>='", "'&'", "'&='", 
      "'^'", "'^='", "'|'", "'|='", "'&&'", "'&&&'", "'&&='", "'&&&='", 
      "'^^'", "'^^='", "'||'", "'||='", "'|||'", "'|||='", "'<<'", "'<<='", 
      "'>>'", "'>>='", "':*'", "':*='", "'.='", "'_='", "'!_='", "", "", 
      "", "'->'", "'-^'", "'<...>'"
    },
    std::vector<std::string>{
      "", "", "RANGE", "UINT", "UFLOAT", "UPITCH", "K_PI", "BTSYMBOL", "DQSYMBOL", 
      "SQSYMBOL", "EMPTYSYMBOL", "BACHNULL", "BACHNIL", "IF", "THEN", "ELSE", 
      "WHILE", "FOR", "IN", "AS", "WITH", "DO", "COLLECT", "INLET", "INTINLET", 
      "RATINLET", "FLOATINLET", "PITCHINLET", "OUTLET", "DIRINLET", "DIROUTLET", 
      "BIF", "OF", "ARGCOUNT", "KEEP", "UNKEEP", "INIT", "GLOBALVAR", "PATCHERVAR", 
      "LOCALVAR", "NAMEDPARAM", "PUSH", "POP", "CLOSED", "NTH", "PICK", 
      "KEY", "ANTH", "APICK", "NULLIFY", "ASSIGN", "WHITESPACE", "NEWATOM", 
      "POW", "APOW", "TIMES", "ATIMES", "DIVDIV", "ADIVDIV", "DIV", "ADIV", 
      "REM", "AREM", "PLUS", "APLUS", "UPLUS", "MINUS", "AMINUS", "UMINUS", 
      "EQUAL", "NEQ", "LOGNOT", "BITNOT", "LT", "GT", "LEQ", "GEQ", "BITAND", 
      "ABITAND", "BITXOR", "ABITXOR", "BITOR", "ABITOR", "LOGAND", "LOGANDEXT", 
      "ALOGAND", "ALOGANDEXT", "LOGXOR", "ALOGXOR", "LOGOR", "ALOGOR", "LOGOREXT", 
      "ALOGOREXT", "LSHIFT", "ALSHIFT", "RSHIFT", "ARSHIFT", "REPEAT", "AREPEAT", 
      "AAPPLY", "ACONCAT", "ARCONCAT", "OPEN", "PARAMS", "MAXFUNCTION", 
      "FUNDEF", "LIFT", "ELLIPSIS", "BLOCKCOMMENT", "LINECOMMENT", "ANYTHING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,110,498,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,3,1,75,8,1,1,2,1,2,1,2,3,2,80,8,2,1,2,3,2,83,8,2,1,3,1,3,1,3,5,3,
  	88,8,3,10,3,12,3,91,9,3,1,4,1,4,1,4,5,4,96,8,4,10,4,12,4,99,9,4,1,4,1,
  	4,1,5,1,5,3,5,105,8,5,1,5,1,5,1,5,1,6,1,6,4,6,112,8,6,11,6,12,6,113,1,
  	6,3,6,117,8,6,3,6,119,8,6,1,7,1,7,4,7,123,8,7,11,7,12,7,124,1,8,1,8,1,
  	8,1,8,1,8,1,9,1,9,3,9,134,8,9,1,9,1,9,1,9,1,10,1,10,1,10,5,10,142,8,10,
  	10,10,12,10,145,9,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,3,11,158,8,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,
  	169,8,11,1,11,1,11,1,11,3,11,174,8,11,1,12,1,12,1,12,3,12,179,8,12,1,
  	12,1,12,5,12,183,8,12,10,12,12,12,186,9,12,1,13,1,13,1,13,5,13,191,8,
  	13,10,13,12,13,194,9,13,1,14,1,14,1,14,3,14,199,8,14,1,14,1,14,1,14,1,
  	14,1,14,3,14,206,8,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,214,8,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,3,14,222,8,14,1,14,1,14,1,14,3,14,227,8,14,1,
  	14,1,14,1,14,3,14,232,8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,251,8,14,1,14,1,14,1,
  	14,5,14,256,8,14,10,14,12,14,259,9,14,1,15,1,15,1,15,3,15,264,8,15,1,
  	16,5,16,267,8,16,10,16,12,16,270,9,16,1,16,1,16,1,17,1,17,1,17,1,17,4,
  	17,278,8,17,11,17,12,17,279,3,17,282,8,17,1,18,3,18,285,8,18,1,18,1,18,
  	1,18,3,18,290,8,18,1,19,1,19,1,19,1,19,3,19,296,8,19,1,20,5,20,299,8,
  	20,10,20,12,20,302,9,20,1,20,1,20,1,21,1,21,1,21,4,21,309,8,21,11,21,
  	12,21,310,1,21,1,21,1,21,5,21,316,8,21,10,21,12,21,319,9,21,1,21,1,21,
  	3,21,323,8,21,1,22,1,22,3,22,327,8,22,1,23,1,23,1,23,1,24,1,24,1,24,1,
  	24,1,24,3,24,337,8,24,1,25,1,25,1,25,1,25,1,25,3,25,344,8,25,1,25,1,25,
  	1,25,4,25,349,8,25,11,25,12,25,350,1,25,1,25,1,25,3,25,356,8,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,
  	1,25,1,25,5,25,403,8,25,10,25,12,25,406,9,25,1,26,1,26,1,26,1,26,1,26,
  	1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,3,26,421,8,26,1,26,1,26,1,26,
  	3,26,426,8,26,3,26,428,8,26,1,27,1,27,4,27,432,8,27,11,27,12,27,433,1,
  	28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,3,28,448,8,
  	28,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,
  	29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,3,29,476,
  	8,29,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,3,30,
  	490,8,30,1,31,1,31,4,31,494,8,31,11,31,12,31,495,1,31,0,2,28,50,32,0,
  	2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,
  	52,54,56,58,60,62,0,16,1,0,21,22,2,0,65,65,68,68,1,0,34,35,2,0,44,44,
  	46,46,1,0,71,72,4,0,55,55,57,57,59,59,61,61,2,0,63,63,66,66,2,0,93,93,
  	95,95,1,0,69,70,1,0,73,76,1,0,83,84,2,0,89,89,91,91,1,0,8,9,1,0,23,27,
  	19,0,47,47,50,50,54,54,56,56,58,58,60,60,62,62,64,64,67,67,78,78,80,80,
  	82,82,85,86,88,88,90,90,92,92,94,94,96,96,100,101,18,0,50,50,54,54,56,
  	56,58,58,60,60,62,62,64,64,67,67,78,78,80,80,82,82,85,86,88,88,90,90,
  	92,92,94,94,96,96,100,101,570,0,64,1,0,0,0,2,74,1,0,0,0,4,82,1,0,0,0,
  	6,84,1,0,0,0,8,92,1,0,0,0,10,102,1,0,0,0,12,118,1,0,0,0,14,120,1,0,0,
  	0,16,126,1,0,0,0,18,131,1,0,0,0,20,138,1,0,0,0,22,173,1,0,0,0,24,175,
  	1,0,0,0,26,187,1,0,0,0,28,231,1,0,0,0,30,263,1,0,0,0,32,268,1,0,0,0,34,
  	281,1,0,0,0,36,289,1,0,0,0,38,295,1,0,0,0,40,300,1,0,0,0,42,322,1,0,0,
  	0,44,324,1,0,0,0,46,328,1,0,0,0,48,336,1,0,0,0,50,355,1,0,0,0,52,427,
  	1,0,0,0,54,429,1,0,0,0,56,447,1,0,0,0,58,475,1,0,0,0,60,489,1,0,0,0,62,
  	493,1,0,0,0,64,65,3,2,1,0,65,1,1,0,0,0,66,75,5,0,0,1,67,68,3,12,6,0,68,
  	69,5,0,0,1,69,75,1,0,0,0,70,71,3,12,6,0,71,72,5,40,0,0,72,75,1,0,0,0,
  	73,75,5,40,0,0,74,66,1,0,0,0,74,67,1,0,0,0,74,70,1,0,0,0,74,73,1,0,0,
  	0,75,3,1,0,0,0,76,79,5,39,0,0,77,78,5,50,0,0,78,80,3,62,31,0,79,77,1,
  	0,0,0,79,80,1,0,0,0,80,83,1,0,0,0,81,83,5,107,0,0,82,76,1,0,0,0,82,81,
  	1,0,0,0,83,5,1,0,0,0,84,89,3,4,2,0,85,86,5,1,0,0,86,88,3,4,2,0,87,85,
  	1,0,0,0,88,91,1,0,0,0,89,87,1,0,0,0,89,90,1,0,0,0,90,7,1,0,0,0,91,89,
  	1,0,0,0,92,97,5,106,0,0,93,94,5,39,0,0,94,96,5,1,0,0,95,93,1,0,0,0,96,
  	99,1,0,0,0,97,95,1,0,0,0,97,98,1,0,0,0,98,100,1,0,0,0,99,97,1,0,0,0,100,
  	101,5,39,0,0,101,9,1,0,0,0,102,104,3,6,3,0,103,105,3,8,4,0,104,103,1,
  	0,0,0,104,105,1,0,0,0,105,106,1,0,0,0,106,107,5,105,0,0,107,108,3,62,
  	31,0,108,11,1,0,0,0,109,119,3,62,31,0,110,112,3,14,7,0,111,110,1,0,0,
  	0,112,113,1,0,0,0,113,111,1,0,0,0,113,114,1,0,0,0,114,116,1,0,0,0,115,
  	117,3,62,31,0,116,115,1,0,0,0,116,117,1,0,0,0,117,119,1,0,0,0,118,109,
  	1,0,0,0,118,111,1,0,0,0,119,13,1,0,0,0,120,122,3,62,31,0,121,123,5,49,
  	0,0,122,121,1,0,0,0,123,124,1,0,0,0,124,122,1,0,0,0,124,125,1,0,0,0,125,
  	15,1,0,0,0,126,127,5,16,0,0,127,128,3,12,6,0,128,129,7,0,0,0,129,130,
  	3,62,31,0,130,17,1,0,0,0,131,133,5,39,0,0,132,134,5,39,0,0,133,132,1,
  	0,0,0,133,134,1,0,0,0,134,135,1,0,0,0,135,136,5,18,0,0,136,137,3,12,6,
  	0,137,19,1,0,0,0,138,143,3,18,9,0,139,140,5,1,0,0,140,142,3,18,9,0,141,
  	139,1,0,0,0,142,145,1,0,0,0,143,141,1,0,0,0,143,144,1,0,0,0,144,21,1,
  	0,0,0,145,143,1,0,0,0,146,147,5,17,0,0,147,148,3,20,10,0,148,149,7,0,
  	0,0,149,150,3,62,31,0,150,174,1,0,0,0,151,152,5,17,0,0,152,153,3,20,10,
  	0,153,154,5,19,0,0,154,157,3,12,6,0,155,156,5,20,0,0,156,158,3,24,12,
  	0,157,155,1,0,0,0,157,158,1,0,0,0,158,159,1,0,0,0,159,160,7,0,0,0,160,
  	161,3,62,31,0,161,174,1,0,0,0,162,163,5,17,0,0,163,164,3,20,10,0,164,
  	165,5,20,0,0,165,168,3,24,12,0,166,167,5,19,0,0,167,169,3,12,6,0,168,
  	166,1,0,0,0,168,169,1,0,0,0,169,170,1,0,0,0,170,171,7,0,0,0,171,172,3,
  	62,31,0,172,174,1,0,0,0,173,146,1,0,0,0,173,151,1,0,0,0,173,162,1,0,0,
  	0,174,23,1,0,0,0,175,176,5,40,0,0,176,184,3,12,6,0,177,179,5,1,0,0,178,
  	177,1,0,0,0,178,179,1,0,0,0,179,180,1,0,0,0,180,181,5,40,0,0,181,183,
  	3,12,6,0,182,178,1,0,0,0,183,186,1,0,0,0,184,182,1,0,0,0,184,185,1,0,
  	0,0,185,25,1,0,0,0,186,184,1,0,0,0,187,192,3,12,6,0,188,189,5,1,0,0,189,
  	191,3,12,6,0,190,188,1,0,0,0,191,194,1,0,0,0,192,190,1,0,0,0,192,193,
  	1,0,0,0,193,27,1,0,0,0,194,192,1,0,0,0,195,198,6,14,-1,0,196,199,3,56,
  	28,0,197,199,3,36,18,0,198,196,1,0,0,0,198,197,1,0,0,0,199,200,1,0,0,
  	0,200,201,5,103,0,0,201,202,5,43,0,0,202,232,1,0,0,0,203,206,3,56,28,
  	0,204,206,3,36,18,0,205,203,1,0,0,0,205,204,1,0,0,0,206,207,1,0,0,0,207,
  	208,5,103,0,0,208,209,3,26,13,0,209,210,5,43,0,0,210,232,1,0,0,0,211,
  	214,3,56,28,0,212,214,3,36,18,0,213,211,1,0,0,0,213,212,1,0,0,0,214,215,
  	1,0,0,0,215,216,5,103,0,0,216,217,3,24,12,0,217,218,5,43,0,0,218,232,
  	1,0,0,0,219,222,3,56,28,0,220,222,3,36,18,0,221,219,1,0,0,0,221,220,1,
  	0,0,0,222,223,1,0,0,0,223,224,5,103,0,0,224,226,3,26,13,0,225,227,5,1,
  	0,0,226,225,1,0,0,0,226,227,1,0,0,0,227,228,1,0,0,0,228,229,3,24,12,0,
  	229,230,5,43,0,0,230,232,1,0,0,0,231,195,1,0,0,0,231,205,1,0,0,0,231,
  	213,1,0,0,0,231,221,1,0,0,0,232,257,1,0,0,0,233,234,10,4,0,0,234,235,
  	5,103,0,0,235,256,5,43,0,0,236,237,10,3,0,0,237,238,5,103,0,0,238,239,
  	3,26,13,0,239,240,5,43,0,0,240,256,1,0,0,0,241,242,10,2,0,0,242,243,5,
  	103,0,0,243,244,3,24,12,0,244,245,5,43,0,0,245,256,1,0,0,0,246,247,10,
  	1,0,0,247,248,5,103,0,0,248,250,3,26,13,0,249,251,5,1,0,0,250,249,1,0,
  	0,0,250,251,1,0,0,0,251,252,1,0,0,0,252,253,3,24,12,0,253,254,5,43,0,
  	0,254,256,1,0,0,0,255,233,1,0,0,0,255,236,1,0,0,0,255,241,1,0,0,0,255,
  	246,1,0,0,0,256,259,1,0,0,0,257,255,1,0,0,0,257,258,1,0,0,0,258,29,1,
  	0,0,0,259,257,1,0,0,0,260,264,3,56,28,0,261,264,3,36,18,0,262,264,3,28,
  	14,0,263,260,1,0,0,0,263,261,1,0,0,0,263,262,1,0,0,0,264,31,1,0,0,0,265,
  	267,7,1,0,0,266,265,1,0,0,0,267,270,1,0,0,0,268,266,1,0,0,0,268,269,1,
  	0,0,0,269,271,1,0,0,0,270,268,1,0,0,0,271,272,3,30,15,0,272,33,1,0,0,
  	0,273,282,3,28,14,0,274,277,3,32,16,0,275,276,5,46,0,0,276,278,3,28,14,
  	0,277,275,1,0,0,0,278,279,1,0,0,0,279,277,1,0,0,0,279,280,1,0,0,0,280,
  	282,1,0,0,0,281,273,1,0,0,0,281,274,1,0,0,0,282,35,1,0,0,0,283,285,7,
  	2,0,0,284,283,1,0,0,0,284,285,1,0,0,0,285,286,1,0,0,0,286,290,5,39,0,
  	0,287,290,5,38,0,0,288,290,5,37,0,0,289,284,1,0,0,0,289,287,1,0,0,0,289,
  	288,1,0,0,0,290,37,1,0,0,0,291,296,3,60,30,0,292,296,3,16,8,0,293,296,
  	3,22,11,0,294,296,3,10,5,0,295,291,1,0,0,0,295,292,1,0,0,0,295,293,1,
  	0,0,0,295,294,1,0,0,0,296,39,1,0,0,0,297,299,7,1,0,0,298,297,1,0,0,0,
  	299,302,1,0,0,0,300,298,1,0,0,0,300,301,1,0,0,0,301,303,1,0,0,0,302,300,
  	1,0,0,0,303,304,3,38,19,0,304,41,1,0,0,0,305,308,6,21,-1,0,306,307,7,
  	3,0,0,307,309,3,32,16,0,308,306,1,0,0,0,309,310,1,0,0,0,310,308,1,0,0,
  	0,310,311,1,0,0,0,311,323,1,0,0,0,312,317,6,21,-1,0,313,314,7,3,0,0,314,
  	316,3,32,16,0,315,313,1,0,0,0,316,319,1,0,0,0,317,315,1,0,0,0,317,318,
  	1,0,0,0,318,320,1,0,0,0,319,317,1,0,0,0,320,321,7,3,0,0,321,323,3,40,
  	20,0,322,305,1,0,0,0,322,312,1,0,0,0,323,43,1,0,0,0,324,326,3,36,18,0,
  	325,327,3,42,21,0,326,325,1,0,0,0,326,327,1,0,0,0,327,45,1,0,0,0,328,
  	329,3,56,28,0,329,330,3,42,21,0,330,47,1,0,0,0,331,337,3,60,30,0,332,
  	337,3,58,29,0,333,337,3,16,8,0,334,337,3,22,11,0,335,337,3,10,5,0,336,
  	331,1,0,0,0,336,332,1,0,0,0,336,333,1,0,0,0,336,334,1,0,0,0,336,335,1,
  	0,0,0,337,49,1,0,0,0,338,343,6,25,-1,0,339,344,3,56,28,0,340,344,3,36,
  	18,0,341,344,3,34,17,0,342,344,3,48,24,0,343,339,1,0,0,0,343,340,1,0,
  	0,0,343,341,1,0,0,0,343,342,1,0,0,0,344,356,1,0,0,0,345,356,3,44,22,0,
  	346,356,3,46,23,0,347,349,7,1,0,0,348,347,1,0,0,0,349,350,1,0,0,0,350,
  	348,1,0,0,0,350,351,1,0,0,0,351,352,1,0,0,0,352,356,3,50,25,15,353,354,
  	7,4,0,0,354,356,3,50,25,1,355,338,1,0,0,0,355,345,1,0,0,0,355,346,1,0,
  	0,0,355,348,1,0,0,0,355,353,1,0,0,0,356,404,1,0,0,0,357,358,10,17,0,0,
  	358,359,5,45,0,0,359,403,3,50,25,18,360,361,10,16,0,0,361,362,5,53,0,
  	0,362,403,3,50,25,16,363,364,10,14,0,0,364,365,7,5,0,0,365,403,3,50,25,
  	15,366,367,10,13,0,0,367,368,7,6,0,0,368,403,3,50,25,14,369,370,10,12,
  	0,0,370,371,7,7,0,0,371,403,3,50,25,13,372,373,10,11,0,0,373,374,5,2,
  	0,0,374,403,3,50,25,12,375,376,10,10,0,0,376,377,5,97,0,0,377,403,3,50,
  	25,11,378,379,10,9,0,0,379,380,7,8,0,0,380,403,3,50,25,10,381,382,10,
  	8,0,0,382,383,7,9,0,0,383,403,3,50,25,9,384,385,10,7,0,0,385,386,5,77,
  	0,0,386,403,3,50,25,8,387,388,10,6,0,0,388,389,5,79,0,0,389,403,3,50,
  	25,7,390,391,10,5,0,0,391,392,5,81,0,0,392,403,3,50,25,6,393,394,10,4,
  	0,0,394,395,7,10,0,0,395,403,3,50,25,5,396,397,10,3,0,0,397,398,5,87,
  	0,0,398,403,3,50,25,4,399,400,10,2,0,0,400,401,7,11,0,0,401,403,3,50,
  	25,3,402,357,1,0,0,0,402,360,1,0,0,0,402,363,1,0,0,0,402,366,1,0,0,0,
  	402,369,1,0,0,0,402,372,1,0,0,0,402,375,1,0,0,0,402,378,1,0,0,0,402,381,
  	1,0,0,0,402,384,1,0,0,0,402,387,1,0,0,0,402,390,1,0,0,0,402,393,1,0,0,
  	0,402,396,1,0,0,0,402,399,1,0,0,0,403,406,1,0,0,0,404,402,1,0,0,0,404,
  	405,1,0,0,0,405,51,1,0,0,0,406,404,1,0,0,0,407,428,5,3,0,0,408,428,5,
  	4,0,0,409,428,5,5,0,0,410,428,5,6,0,0,411,428,5,7,0,0,412,428,7,12,0,
  	0,413,428,5,10,0,0,414,428,5,31,0,0,415,428,5,32,0,0,416,428,5,104,0,
  	0,417,421,5,11,0,0,418,419,5,102,0,0,419,421,5,43,0,0,420,417,1,0,0,0,
  	420,418,1,0,0,0,421,428,1,0,0,0,422,426,5,12,0,0,423,424,5,41,0,0,424,
  	426,5,42,0,0,425,422,1,0,0,0,425,423,1,0,0,0,426,428,1,0,0,0,427,407,
  	1,0,0,0,427,408,1,0,0,0,427,409,1,0,0,0,427,410,1,0,0,0,427,411,1,0,0,
  	0,427,412,1,0,0,0,427,413,1,0,0,0,427,414,1,0,0,0,427,415,1,0,0,0,427,
  	416,1,0,0,0,427,420,1,0,0,0,427,425,1,0,0,0,428,53,1,0,0,0,429,431,3,
  	52,26,0,430,432,3,52,26,0,431,430,1,0,0,0,432,433,1,0,0,0,433,431,1,0,
  	0,0,433,434,1,0,0,0,434,55,1,0,0,0,435,448,3,52,26,0,436,448,7,13,0,0,
  	437,448,5,29,0,0,438,448,5,33,0,0,439,440,5,102,0,0,440,441,3,12,6,0,
  	441,442,5,43,0,0,442,448,1,0,0,0,443,444,5,41,0,0,444,445,3,12,6,0,445,
  	446,5,42,0,0,446,448,1,0,0,0,447,435,1,0,0,0,447,436,1,0,0,0,447,437,
  	1,0,0,0,447,438,1,0,0,0,447,439,1,0,0,0,447,443,1,0,0,0,448,57,1,0,0,
  	0,449,450,5,36,0,0,450,451,5,39,0,0,451,452,5,50,0,0,452,476,3,62,31,
  	0,453,454,3,44,22,0,454,455,7,14,0,0,455,456,3,62,31,0,456,476,1,0,0,
  	0,457,458,3,46,23,0,458,459,7,15,0,0,459,460,3,62,31,0,460,476,1,0,0,
  	0,461,462,3,44,22,0,462,463,5,99,0,0,463,464,3,34,17,0,464,476,1,0,0,
  	0,465,466,3,46,23,0,466,467,5,99,0,0,467,468,3,34,17,0,468,476,1,0,0,
  	0,469,470,5,28,0,0,470,471,5,50,0,0,471,476,3,62,31,0,472,473,5,30,0,
  	0,473,474,5,50,0,0,474,476,3,62,31,0,475,449,1,0,0,0,475,453,1,0,0,0,
  	475,457,1,0,0,0,475,461,1,0,0,0,475,465,1,0,0,0,475,469,1,0,0,0,475,472,
  	1,0,0,0,476,59,1,0,0,0,477,478,5,13,0,0,478,479,3,12,6,0,479,480,5,14,
  	0,0,480,481,3,62,31,0,481,490,1,0,0,0,482,483,5,13,0,0,483,484,3,12,6,
  	0,484,485,5,14,0,0,485,486,3,12,6,0,486,487,5,15,0,0,487,488,3,62,31,
  	0,488,490,1,0,0,0,489,477,1,0,0,0,489,482,1,0,0,0,490,61,1,0,0,0,491,
  	494,3,54,27,0,492,494,3,50,25,0,493,491,1,0,0,0,493,492,1,0,0,0,494,495,
  	1,0,0,0,495,493,1,0,0,0,495,496,1,0,0,0,496,63,1,0,0,0,54,74,79,82,89,
  	97,104,113,116,118,124,133,143,157,168,173,178,184,192,198,205,213,221,
  	226,231,250,255,257,263,268,279,281,284,289,295,300,310,317,322,326,336,
  	343,350,355,402,404,420,425,427,433,447,475,489,493,495
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
    setState(64);
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
    setState(74);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::ProgramEOFContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(66);
      match(bellParser::EOF);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::ProgramSequenceContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(67);
      sequence();
      setState(68);
      match(bellParser::EOF);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<bellParser::ProgramSequenceNamedparamContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(70);
      sequence();
      setState(71);
      match(bellParser::NAMEDPARAM);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<bellParser::ProgramNamedparamContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(73);
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
    setState(82);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::LOCALVAR: {
        _localctx = _tracker.createInstance<bellParser::FunargVarContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(76);
        match(bellParser::LOCALVAR);
        setState(79);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bellParser::ASSIGN) {
          setState(77);
          match(bellParser::ASSIGN);
          setState(78);
          list();
        }
        break;
      }

      case bellParser::ELLIPSIS: {
        _localctx = _tracker.createInstance<bellParser::FunargEllipsisContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(81);
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
    setState(84);
    funarg();
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::T__0) {
      setState(85);
      match(bellParser::T__0);
      setState(86);
      funarg();
      setState(91);
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
    setState(92);
    match(bellParser::LIFT);
    setState(97);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(93);
        match(bellParser::LOCALVAR);
        setState(94);
        match(bellParser::T__0); 
      }
      setState(99);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(100);
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
    setState(102);
    funargList();
    setState(104);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == bellParser::LIFT) {
      setState(103);
      liftedargList();
    }
    setState(106);
    match(bellParser::FUNDEF);
    setState(107);
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
    setState(118);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(109);
      list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(111); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(110);
                nullified();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(113); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(116);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << bellParser::UINT)
        | (1ULL << bellParser::UFLOAT)
        | (1ULL << bellParser::UPITCH)
        | (1ULL << bellParser::K_PI)
        | (1ULL << bellParser::BTSYMBOL)
        | (1ULL << bellParser::DQSYMBOL)
        | (1ULL << bellParser::SQSYMBOL)
        | (1ULL << bellParser::EMPTYSYMBOL)
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
        | (1ULL << bellParser::ARGCOUNT)
        | (1ULL << bellParser::KEEP)
        | (1ULL << bellParser::UNKEEP)
        | (1ULL << bellParser::INIT)
        | (1ULL << bellParser::GLOBALVAR)
        | (1ULL << bellParser::PATCHERVAR)
        | (1ULL << bellParser::LOCALVAR)
        | (1ULL << bellParser::PUSH))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & ((1ULL << (bellParser::UPLUS - 65))
        | (1ULL << (bellParser::UMINUS - 65))
        | (1ULL << (bellParser::LOGNOT - 65))
        | (1ULL << (bellParser::BITNOT - 65))
        | (1ULL << (bellParser::OPEN - 65))
        | (1ULL << (bellParser::MAXFUNCTION - 65))
        | (1ULL << (bellParser::ELLIPSIS - 65)))) != 0)) {
        setState(115);
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
    setState(120);
    list();
    setState(122); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(121);
      match(bellParser::NULLIFY);
      setState(124); 
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
    setState(126);
    match(bellParser::WHILE);
    setState(127);
    sequence();
    setState(128);
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
    setState(129);
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
    setState(131);
    match(bellParser::LOCALVAR);

    setState(133);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == bellParser::LOCALVAR) {
      setState(132);
      match(bellParser::LOCALVAR);
    }
    setState(135);
    match(bellParser::IN);
    setState(136);
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
    setState(138);
    forarg();
    setState(143);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::T__0) {
      setState(139);
      match(bellParser::T__0);
      setState(140);
      forarg();
      setState(145);
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
    setState(173);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(146);
      match(bellParser::FOR);
      setState(147);
      forargList();
      setState(148);
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
      setState(149);
      list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(151);
      match(bellParser::FOR);
      setState(152);
      forargList();
      setState(153);
      match(bellParser::AS);
      setState(154);
      sequence();
      setState(157);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::WITH) {
        setState(155);
        match(bellParser::WITH);
        setState(156);
        argsByNameList();
      }
      setState(159);
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
      setState(160);
      list();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(162);
      match(bellParser::FOR);
      setState(163);
      forargList();
      setState(164);
      match(bellParser::WITH);
      setState(165);
      argsByNameList();
      setState(168);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::AS) {
        setState(166);
        match(bellParser::AS);
        setState(167);
        sequence();
      }
      setState(170);
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
      setState(171);
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
    setState(175);
    match(bellParser::NAMEDPARAM);
    setState(176);
    sequence();
    setState(184);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::T__0

    || _la == bellParser::NAMEDPARAM) {
      setState(178);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::T__0) {
        setState(177);
        match(bellParser::T__0);
      }
      setState(180);
      match(bellParser::NAMEDPARAM);
      setState(181);
      sequence();
      setState(186);
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
    setState(187);
    sequence();
    setState(192);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(188);
        match(bellParser::T__0);
        setState(189);
        sequence(); 
      }
      setState(194);
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
    setState(231);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(198);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case bellParser::UINT:
        case bellParser::UFLOAT:
        case bellParser::UPITCH:
        case bellParser::K_PI:
        case bellParser::BTSYMBOL:
        case bellParser::DQSYMBOL:
        case bellParser::SQSYMBOL:
        case bellParser::EMPTYSYMBOL:
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
        case bellParser::OPEN:
        case bellParser::MAXFUNCTION: {
          setState(196);
          item();
          break;
        }

        case bellParser::KEEP:
        case bellParser::UNKEEP:
        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR: {
          setState(197);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(200);
      match(bellParser::PARAMS);
      setState(201);
      match(bellParser::CLOSED);
      break;
    }

    case 2: {
      setState(205);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case bellParser::UINT:
        case bellParser::UFLOAT:
        case bellParser::UPITCH:
        case bellParser::K_PI:
        case bellParser::BTSYMBOL:
        case bellParser::DQSYMBOL:
        case bellParser::SQSYMBOL:
        case bellParser::EMPTYSYMBOL:
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
        case bellParser::OPEN:
        case bellParser::MAXFUNCTION: {
          setState(203);
          item();
          break;
        }

        case bellParser::KEEP:
        case bellParser::UNKEEP:
        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR: {
          setState(204);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(207);
      match(bellParser::PARAMS);
      setState(208);
      argsByPositionList();
      setState(209);
      match(bellParser::CLOSED);
      break;
    }

    case 3: {
      setState(213);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case bellParser::UINT:
        case bellParser::UFLOAT:
        case bellParser::UPITCH:
        case bellParser::K_PI:
        case bellParser::BTSYMBOL:
        case bellParser::DQSYMBOL:
        case bellParser::SQSYMBOL:
        case bellParser::EMPTYSYMBOL:
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
        case bellParser::OPEN:
        case bellParser::MAXFUNCTION: {
          setState(211);
          item();
          break;
        }

        case bellParser::KEEP:
        case bellParser::UNKEEP:
        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR: {
          setState(212);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(215);
      match(bellParser::PARAMS);
      setState(216);
      argsByNameList();
      setState(217);
      match(bellParser::CLOSED);
      break;
    }

    case 4: {
      setState(221);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case bellParser::UINT:
        case bellParser::UFLOAT:
        case bellParser::UPITCH:
        case bellParser::K_PI:
        case bellParser::BTSYMBOL:
        case bellParser::DQSYMBOL:
        case bellParser::SQSYMBOL:
        case bellParser::EMPTYSYMBOL:
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
        case bellParser::OPEN:
        case bellParser::MAXFUNCTION: {
          setState(219);
          item();
          break;
        }

        case bellParser::KEEP:
        case bellParser::UNKEEP:
        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR: {
          setState(220);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(223);
      match(bellParser::PARAMS);
      setState(224);
      argsByPositionList();
      setState(226);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::T__0) {
        setState(225);
        match(bellParser::T__0);
      }
      setState(228);
      argsByNameList();
      setState(229);
      match(bellParser::CLOSED);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(257);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(255);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(233);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(234);
          match(bellParser::PARAMS);
          setState(235);
          match(bellParser::CLOSED);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(236);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(237);
          match(bellParser::PARAMS);
          setState(238);
          argsByPositionList();
          setState(239);
          match(bellParser::CLOSED);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(241);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(242);
          match(bellParser::PARAMS);
          setState(243);
          argsByNameList();
          setState(244);
          match(bellParser::CLOSED);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(246);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(247);
          match(bellParser::PARAMS);
          setState(248);
          argsByPositionList();
          setState(250);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == bellParser::T__0) {
            setState(249);
            match(bellParser::T__0);
          }
          setState(252);
          argsByNameList();
          setState(253);
          match(bellParser::CLOSED);
          break;
        }

        default:
          break;
        } 
      }
      setState(259);
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

//----------------- DataFlowAndLvalueSpecsUItemContext ------------------------------------------------------------------

bellParser::DataFlowAndLvalueSpecsUItemContext::DataFlowAndLvalueSpecsUItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bellParser::ItemContext* bellParser::DataFlowAndLvalueSpecsUItemContext::item() {
  return getRuleContext<bellParser::ItemContext>(0);
}

bellParser::VarContext* bellParser::DataFlowAndLvalueSpecsUItemContext::var() {
  return getRuleContext<bellParser::VarContext>(0);
}

bellParser::SimpleFuncallContext* bellParser::DataFlowAndLvalueSpecsUItemContext::simpleFuncall() {
  return getRuleContext<bellParser::SimpleFuncallContext>(0);
}


size_t bellParser::DataFlowAndLvalueSpecsUItemContext::getRuleIndex() const {
  return bellParser::RuleDataFlowAndLvalueSpecsUItem;
}


std::any bellParser::DataFlowAndLvalueSpecsUItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitDataFlowAndLvalueSpecsUItem(this);
  else
    return visitor->visitChildren(this);
}

bellParser::DataFlowAndLvalueSpecsUItemContext* bellParser::dataFlowAndLvalueSpecsUItem() {
  DataFlowAndLvalueSpecsUItemContext *_localctx = _tracker.createInstance<DataFlowAndLvalueSpecsUItemContext>(_ctx, getState());
  enterRule(_localctx, 30, bellParser::RuleDataFlowAndLvalueSpecsUItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(263);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(260);
      item();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(261);
      var();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(262);
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

//----------------- DataFlowAndLvalueSpecsItemContext ------------------------------------------------------------------

bellParser::DataFlowAndLvalueSpecsItemContext::DataFlowAndLvalueSpecsItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bellParser::DataFlowAndLvalueSpecsUItemContext* bellParser::DataFlowAndLvalueSpecsItemContext::dataFlowAndLvalueSpecsUItem() {
  return getRuleContext<bellParser::DataFlowAndLvalueSpecsUItemContext>(0);
}

std::vector<tree::TerminalNode *> bellParser::DataFlowAndLvalueSpecsItemContext::UPLUS() {
  return getTokens(bellParser::UPLUS);
}

tree::TerminalNode* bellParser::DataFlowAndLvalueSpecsItemContext::UPLUS(size_t i) {
  return getToken(bellParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> bellParser::DataFlowAndLvalueSpecsItemContext::UMINUS() {
  return getTokens(bellParser::UMINUS);
}

tree::TerminalNode* bellParser::DataFlowAndLvalueSpecsItemContext::UMINUS(size_t i) {
  return getToken(bellParser::UMINUS, i);
}


size_t bellParser::DataFlowAndLvalueSpecsItemContext::getRuleIndex() const {
  return bellParser::RuleDataFlowAndLvalueSpecsItem;
}


std::any bellParser::DataFlowAndLvalueSpecsItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitDataFlowAndLvalueSpecsItem(this);
  else
    return visitor->visitChildren(this);
}

bellParser::DataFlowAndLvalueSpecsItemContext* bellParser::dataFlowAndLvalueSpecsItem() {
  DataFlowAndLvalueSpecsItemContext *_localctx = _tracker.createInstance<DataFlowAndLvalueSpecsItemContext>(_ctx, getState());
  enterRule(_localctx, 32, bellParser::RuleDataFlowAndLvalueSpecsItem);
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
    setState(268);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::UPLUS

    || _la == bellParser::UMINUS) {
      setState(265);
      _la = _input->LA(1);
      if (!(_la == bellParser::UPLUS

      || _la == bellParser::UMINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(270);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(271);
    dataFlowAndLvalueSpecsUItem();
   
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

bellParser::DataFlowAndLvalueSpecsItemContext* bellParser::FuncallContext::dataFlowAndLvalueSpecsItem() {
  return getRuleContext<bellParser::DataFlowAndLvalueSpecsItemContext>(0);
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
  enterRule(_localctx, 34, bellParser::RuleFuncall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(281);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(273);
      simpleFuncall(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(274);
      dataFlowAndLvalueSpecsItem();
      setState(277); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(275);
                match(bellParser::KEY);
                setState(276);
                simpleFuncall(0);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(279); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
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
    setState(289);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::KEEP:
      case bellParser::UNKEEP:
      case bellParser::LOCALVAR: {
        _localctx = _tracker.createInstance<bellParser::VarLocalContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(284);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bellParser::KEEP

        || _la == bellParser::UNKEEP) {
          setState(283);
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
        setState(286);
        match(bellParser::LOCALVAR);
        break;
      }

      case bellParser::PATCHERVAR: {
        _localctx = _tracker.createInstance<bellParser::VarPatcherContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(287);
        match(bellParser::PATCHERVAR);
        break;
      }

      case bellParser::GLOBALVAR: {
        _localctx = _tracker.createInstance<bellParser::VarGlobalContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(288);
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

//----------------- LvalueSpecsUFinalContext ------------------------------------------------------------------

bellParser::LvalueSpecsUFinalContext::LvalueSpecsUFinalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bellParser::ConditionalContext* bellParser::LvalueSpecsUFinalContext::conditional() {
  return getRuleContext<bellParser::ConditionalContext>(0);
}

bellParser::WhileloopContext* bellParser::LvalueSpecsUFinalContext::whileloop() {
  return getRuleContext<bellParser::WhileloopContext>(0);
}

bellParser::ForloopContext* bellParser::LvalueSpecsUFinalContext::forloop() {
  return getRuleContext<bellParser::ForloopContext>(0);
}

bellParser::FundefContext* bellParser::LvalueSpecsUFinalContext::fundef() {
  return getRuleContext<bellParser::FundefContext>(0);
}


size_t bellParser::LvalueSpecsUFinalContext::getRuleIndex() const {
  return bellParser::RuleLvalueSpecsUFinal;
}


std::any bellParser::LvalueSpecsUFinalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLvalueSpecsUFinal(this);
  else
    return visitor->visitChildren(this);
}

bellParser::LvalueSpecsUFinalContext* bellParser::lvalueSpecsUFinal() {
  LvalueSpecsUFinalContext *_localctx = _tracker.createInstance<LvalueSpecsUFinalContext>(_ctx, getState());
  enterRule(_localctx, 38, bellParser::RuleLvalueSpecsUFinal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(295);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(291);
        conditional();
        break;
      }

      case bellParser::WHILE: {
        enterOuterAlt(_localctx, 2);
        setState(292);
        whileloop();
        break;
      }

      case bellParser::FOR: {
        enterOuterAlt(_localctx, 3);
        setState(293);
        forloop();
        break;
      }

      case bellParser::LOCALVAR:
      case bellParser::ELLIPSIS: {
        enterOuterAlt(_localctx, 4);
        setState(294);
        fundef();
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

//----------------- LvalueSpecsFinalContext ------------------------------------------------------------------

bellParser::LvalueSpecsFinalContext::LvalueSpecsFinalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bellParser::LvalueSpecsUFinalContext* bellParser::LvalueSpecsFinalContext::lvalueSpecsUFinal() {
  return getRuleContext<bellParser::LvalueSpecsUFinalContext>(0);
}

std::vector<tree::TerminalNode *> bellParser::LvalueSpecsFinalContext::UPLUS() {
  return getTokens(bellParser::UPLUS);
}

tree::TerminalNode* bellParser::LvalueSpecsFinalContext::UPLUS(size_t i) {
  return getToken(bellParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> bellParser::LvalueSpecsFinalContext::UMINUS() {
  return getTokens(bellParser::UMINUS);
}

tree::TerminalNode* bellParser::LvalueSpecsFinalContext::UMINUS(size_t i) {
  return getToken(bellParser::UMINUS, i);
}


size_t bellParser::LvalueSpecsFinalContext::getRuleIndex() const {
  return bellParser::RuleLvalueSpecsFinal;
}


std::any bellParser::LvalueSpecsFinalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLvalueSpecsFinal(this);
  else
    return visitor->visitChildren(this);
}

bellParser::LvalueSpecsFinalContext* bellParser::lvalueSpecsFinal() {
  LvalueSpecsFinalContext *_localctx = _tracker.createInstance<LvalueSpecsFinalContext>(_ctx, getState());
  enterRule(_localctx, 40, bellParser::RuleLvalueSpecsFinal);
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
    setState(300);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::UPLUS

    || _la == bellParser::UMINUS) {
      setState(297);
      _la = _input->LA(1);
      if (!(_la == bellParser::UPLUS

      || _la == bellParser::UMINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(302);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(303);
    lvalueSpecsUFinal();
   
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

std::vector<bellParser::DataFlowAndLvalueSpecsItemContext *> bellParser::LvalueSpecsContext::dataFlowAndLvalueSpecsItem() {
  return getRuleContexts<bellParser::DataFlowAndLvalueSpecsItemContext>();
}

bellParser::DataFlowAndLvalueSpecsItemContext* bellParser::LvalueSpecsContext::dataFlowAndLvalueSpecsItem(size_t i) {
  return getRuleContext<bellParser::DataFlowAndLvalueSpecsItemContext>(i);
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

bellParser::LvalueSpecsFinalContext* bellParser::LvalueSpecsContext::lvalueSpecsFinal() {
  return getRuleContext<bellParser::LvalueSpecsFinalContext>(0);
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
  enterRule(_localctx, 42, bellParser::RuleLvalueSpecs);
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
    setState(322);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      ending = false;
      setState(308); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
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
                setState(307);
                dataFlowAndLvalueSpecsItem();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(310); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      ending = true;
      setState(317);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(313);
          _la = _input->LA(1);
          if (!(_la == bellParser::NTH

          || _la == bellParser::KEY)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(314);
          dataFlowAndLvalueSpecsItem(); 
        }
        setState(319);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
      }

      setState(320);
      _la = _input->LA(1);
      if (!(_la == bellParser::NTH

      || _la == bellParser::KEY)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(321);
      lvalueSpecsFinal();
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
  enterRule(_localctx, 44, bellParser::RuleLvalue);

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
    var();
    setState(326);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(325);
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
  enterRule(_localctx, 46, bellParser::RuleFakeLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(328);
    item();
    setState(329);
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
  enterRule(_localctx, 48, bellParser::RuleListEnd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(336);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(331);
      conditional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(332);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(333);
      whileloop();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(334);
      forloop();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(335);
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
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, bellParser::RuleExpr, precedence);

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
    setState(355);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprSimpleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(343);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
      case 1: {
        setState(339);
        item();
        break;
      }

      case 2: {
        setState(340);
        var();
        break;
      }

      case 3: {
        setState(341);
        funcall();
        break;
      }

      case 4: {
        setState(342);
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
      setState(345);
      lvalue();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ExprFakeLvalueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(346);
      fakeLvalue();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprUPlusMinusContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(348); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(347);
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
        setState(350); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(352);
      expr(15);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ExprNotContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(353);
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
      setState(354);
      expr(1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(404);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(402);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(357);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(358);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::PICK);
          setState(359);
          expr(18);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(360);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(361);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::POW);
          setState(362);
          expr(16);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(363);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(364);
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
          setState(365);
          expr(15);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(366);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(367);
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
          setState(368);
          expr(14);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(369);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(370);
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
          setState(371);
          expr(13);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(372);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(373);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::RANGE);
          setState(374);
          expr(12);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(375);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(376);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::REPEAT);
          setState(377);
          expr(11);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(378);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(379);
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
          setState(380);
          expr(10);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(381);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(382);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 73) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 73)) & ((1ULL << (bellParser::LT - 73))
            | (1ULL << (bellParser::GT - 73))
            | (1ULL << (bellParser::LEQ - 73))
            | (1ULL << (bellParser::GEQ - 73)))) != 0))) {
            antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(383);
          expr(9);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(384);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(385);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::BITAND);
          setState(386);
          expr(8);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(387);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(388);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::BITXOR);
          setState(389);
          expr(7);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(390);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(391);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::BITOR);
          setState(392);
          expr(6);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(393);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(394);
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
          setState(395);
          expr(5);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(396);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(397);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::LOGXOR);
          setState(398);
          expr(4);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(399);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(400);
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
          setState(401);
          expr(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(406);
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

//----------------- LiteralContext ------------------------------------------------------------------

bellParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bellParser::LiteralContext::getRuleIndex() const {
  return bellParser::RuleLiteral;
}

void bellParser::LiteralContext::copyFrom(LiteralContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LiteralUfloatContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::LiteralUfloatContext::UFLOAT() {
  return getToken(bellParser::UFLOAT, 0);
}

bellParser::LiteralUfloatContext::LiteralUfloatContext(LiteralContext *ctx) { copyFrom(ctx); }


std::any bellParser::LiteralUfloatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLiteralUfloat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralNullContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::LiteralNullContext::BACHNULL() {
  return getToken(bellParser::BACHNULL, 0);
}

tree::TerminalNode* bellParser::LiteralNullContext::OPEN() {
  return getToken(bellParser::OPEN, 0);
}

tree::TerminalNode* bellParser::LiteralNullContext::CLOSED() {
  return getToken(bellParser::CLOSED, 0);
}

bellParser::LiteralNullContext::LiteralNullContext(LiteralContext *ctx) { copyFrom(ctx); }


std::any bellParser::LiteralNullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLiteralNull(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralPiContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::LiteralPiContext::K_PI() {
  return getToken(bellParser::K_PI, 0);
}

bellParser::LiteralPiContext::LiteralPiContext(LiteralContext *ctx) { copyFrom(ctx); }


std::any bellParser::LiteralPiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLiteralPi(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralUintContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::LiteralUintContext::UINT() {
  return getToken(bellParser::UINT, 0);
}

bellParser::LiteralUintContext::LiteralUintContext(LiteralContext *ctx) { copyFrom(ctx); }


std::any bellParser::LiteralUintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLiteralUint(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralUpitchContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::LiteralUpitchContext::UPITCH() {
  return getToken(bellParser::UPITCH, 0);
}

bellParser::LiteralUpitchContext::LiteralUpitchContext(LiteralContext *ctx) { copyFrom(ctx); }


std::any bellParser::LiteralUpitchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLiteralUpitch(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralEmptySymbolContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::LiteralEmptySymbolContext::EMPTYSYMBOL() {
  return getToken(bellParser::EMPTYSYMBOL, 0);
}

bellParser::LiteralEmptySymbolContext::LiteralEmptySymbolContext(LiteralContext *ctx) { copyFrom(ctx); }


std::any bellParser::LiteralEmptySymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLiteralEmptySymbol(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralQSymbolContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::LiteralQSymbolContext::DQSYMBOL() {
  return getToken(bellParser::DQSYMBOL, 0);
}

tree::TerminalNode* bellParser::LiteralQSymbolContext::SQSYMBOL() {
  return getToken(bellParser::SQSYMBOL, 0);
}

bellParser::LiteralQSymbolContext::LiteralQSymbolContext(LiteralContext *ctx) { copyFrom(ctx); }


std::any bellParser::LiteralQSymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLiteralQSymbol(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralMaxFunctionContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::LiteralMaxFunctionContext::MAXFUNCTION() {
  return getToken(bellParser::MAXFUNCTION, 0);
}

bellParser::LiteralMaxFunctionContext::LiteralMaxFunctionContext(LiteralContext *ctx) { copyFrom(ctx); }


std::any bellParser::LiteralMaxFunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLiteralMaxFunction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralBIFContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::LiteralBIFContext::BIF() {
  return getToken(bellParser::BIF, 0);
}

bellParser::LiteralBIFContext::LiteralBIFContext(LiteralContext *ctx) { copyFrom(ctx); }


std::any bellParser::LiteralBIFContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLiteralBIF(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralOFContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::LiteralOFContext::OF() {
  return getToken(bellParser::OF, 0);
}

bellParser::LiteralOFContext::LiteralOFContext(LiteralContext *ctx) { copyFrom(ctx); }


std::any bellParser::LiteralOFContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLiteralOF(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralNilContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::LiteralNilContext::BACHNIL() {
  return getToken(bellParser::BACHNIL, 0);
}

tree::TerminalNode* bellParser::LiteralNilContext::PUSH() {
  return getToken(bellParser::PUSH, 0);
}

tree::TerminalNode* bellParser::LiteralNilContext::POP() {
  return getToken(bellParser::POP, 0);
}

bellParser::LiteralNilContext::LiteralNilContext(LiteralContext *ctx) { copyFrom(ctx); }


std::any bellParser::LiteralNilContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLiteralNil(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralBtSymbolContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::LiteralBtSymbolContext::BTSYMBOL() {
  return getToken(bellParser::BTSYMBOL, 0);
}

bellParser::LiteralBtSymbolContext::LiteralBtSymbolContext(LiteralContext *ctx) { copyFrom(ctx); }


std::any bellParser::LiteralBtSymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLiteralBtSymbol(this);
  else
    return visitor->visitChildren(this);
}
bellParser::LiteralContext* bellParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 52, bellParser::RuleLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(427);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::UINT: {
        _localctx = _tracker.createInstance<bellParser::LiteralUintContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(407);
        match(bellParser::UINT);
        break;
      }

      case bellParser::UFLOAT: {
        _localctx = _tracker.createInstance<bellParser::LiteralUfloatContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(408);
        match(bellParser::UFLOAT);
        break;
      }

      case bellParser::UPITCH: {
        _localctx = _tracker.createInstance<bellParser::LiteralUpitchContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(409);
        match(bellParser::UPITCH);
        break;
      }

      case bellParser::K_PI: {
        _localctx = _tracker.createInstance<bellParser::LiteralPiContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(410);
        match(bellParser::K_PI);
        break;
      }

      case bellParser::BTSYMBOL: {
        _localctx = _tracker.createInstance<bellParser::LiteralBtSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(411);
        match(bellParser::BTSYMBOL);
        break;
      }

      case bellParser::DQSYMBOL:
      case bellParser::SQSYMBOL: {
        _localctx = _tracker.createInstance<bellParser::LiteralQSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(412);
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

      case bellParser::EMPTYSYMBOL: {
        _localctx = _tracker.createInstance<bellParser::LiteralEmptySymbolContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(413);
        match(bellParser::EMPTYSYMBOL);
        break;
      }

      case bellParser::BIF: {
        _localctx = _tracker.createInstance<bellParser::LiteralBIFContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(414);
        match(bellParser::BIF);
        break;
      }

      case bellParser::OF: {
        _localctx = _tracker.createInstance<bellParser::LiteralOFContext>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(415);
        match(bellParser::OF);
        break;
      }

      case bellParser::MAXFUNCTION: {
        _localctx = _tracker.createInstance<bellParser::LiteralMaxFunctionContext>(_localctx);
        enterOuterAlt(_localctx, 10);
        setState(416);
        match(bellParser::MAXFUNCTION);
        break;
      }

      case bellParser::BACHNULL:
      case bellParser::OPEN: {
        _localctx = _tracker.createInstance<bellParser::LiteralNullContext>(_localctx);
        enterOuterAlt(_localctx, 11);
        setState(420);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case bellParser::BACHNULL: {
            setState(417);
            match(bellParser::BACHNULL);
            break;
          }

          case bellParser::OPEN: {
            setState(418);
            match(bellParser::OPEN);
            setState(419);
            match(bellParser::CLOSED);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case bellParser::BACHNIL:
      case bellParser::PUSH: {
        _localctx = _tracker.createInstance<bellParser::LiteralNilContext>(_localctx);
        enterOuterAlt(_localctx, 12);
        setState(425);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case bellParser::BACHNIL: {
            setState(422);
            match(bellParser::BACHNIL);
            break;
          }

          case bellParser::PUSH: {
            setState(423);
            match(bellParser::PUSH);
            setState(424);
            match(bellParser::POP);
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
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LlllContext ------------------------------------------------------------------

bellParser::LlllContext::LlllContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<bellParser::LiteralContext *> bellParser::LlllContext::literal() {
  return getRuleContexts<bellParser::LiteralContext>();
}

bellParser::LiteralContext* bellParser::LlllContext::literal(size_t i) {
  return getRuleContext<bellParser::LiteralContext>(i);
}


size_t bellParser::LlllContext::getRuleIndex() const {
  return bellParser::RuleLlll;
}


std::any bellParser::LlllContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLlll(this);
  else
    return visitor->visitChildren(this);
}

bellParser::LlllContext* bellParser::llll() {
  LlllContext *_localctx = _tracker.createInstance<LlllContext>(_ctx, getState());
  enterRule(_localctx, 54, bellParser::RuleLlll);

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
    setState(429);
    literal();
    setState(431); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(430);
              literal();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(433); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
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

//----------------- ItemLiteralContext ------------------------------------------------------------------

bellParser::LiteralContext* bellParser::ItemLiteralContext::literal() {
  return getRuleContext<bellParser::LiteralContext>(0);
}

bellParser::ItemLiteralContext::ItemLiteralContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemLiteral(this);
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
bellParser::ItemContext* bellParser::item() {
  ItemContext *_localctx = _tracker.createInstance<ItemContext>(_ctx, getState());
  enterRule(_localctx, 56, bellParser::RuleItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(447);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::ItemLiteralContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(435);
      literal();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::ItemInletContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(436);
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

    case 3: {
      _localctx = _tracker.createInstance<bellParser::ItemDirInletContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(437);
      match(bellParser::DIRINLET);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<bellParser::ItemArgcountContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(438);
      match(bellParser::ARGCOUNT);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<bellParser::ItemSequenceContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(439);
      match(bellParser::OPEN);
      setState(440);
      sequence();
      setState(441);
      match(bellParser::CLOSED);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<bellParser::ItemSublistContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(443);
      match(bellParser::PUSH);
      setState(444);
      sequence();
      setState(445);
      match(bellParser::POP);
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
//----------------- FakeAApplyContext ------------------------------------------------------------------

bellParser::FakeLvalueContext* bellParser::FakeAApplyContext::fakeLvalue() {
  return getRuleContext<bellParser::FakeLvalueContext>(0);
}

tree::TerminalNode* bellParser::FakeAApplyContext::AAPPLY() {
  return getToken(bellParser::AAPPLY, 0);
}

bellParser::FuncallContext* bellParser::FakeAApplyContext::funcall() {
  return getRuleContext<bellParser::FuncallContext>(0);
}

bellParser::FakeAApplyContext::FakeAApplyContext(AssignmentContext *ctx) { copyFrom(ctx); }


std::any bellParser::FakeAApplyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitFakeAApply(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TrueAApplyContext ------------------------------------------------------------------

bellParser::LvalueContext* bellParser::TrueAApplyContext::lvalue() {
  return getRuleContext<bellParser::LvalueContext>(0);
}

tree::TerminalNode* bellParser::TrueAApplyContext::AAPPLY() {
  return getToken(bellParser::AAPPLY, 0);
}

bellParser::FuncallContext* bellParser::TrueAApplyContext::funcall() {
  return getRuleContext<bellParser::FuncallContext>(0);
}

bellParser::TrueAApplyContext::TrueAApplyContext(AssignmentContext *ctx) { copyFrom(ctx); }


std::any bellParser::TrueAApplyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitTrueAApply(this);
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
  enterRule(_localctx, 58, bellParser::RuleAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(475);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::InitAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(449);
      match(bellParser::INIT);
      setState(450);
      match(bellParser::LOCALVAR);
      setState(451);
      match(bellParser::ASSIGN);
      setState(452);
      list();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::TrueAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(453);
      lvalue();
      setState(454);
      antlrcpp::downCast<TrueAssignmentContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(((((_la - 47) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 47)) & ((1ULL << (bellParser::ANTH - 47))
        | (1ULL << (bellParser::ASSIGN - 47))
        | (1ULL << (bellParser::APOW - 47))
        | (1ULL << (bellParser::ATIMES - 47))
        | (1ULL << (bellParser::ADIVDIV - 47))
        | (1ULL << (bellParser::ADIV - 47))
        | (1ULL << (bellParser::AREM - 47))
        | (1ULL << (bellParser::APLUS - 47))
        | (1ULL << (bellParser::AMINUS - 47))
        | (1ULL << (bellParser::ABITAND - 47))
        | (1ULL << (bellParser::ABITXOR - 47))
        | (1ULL << (bellParser::ABITOR - 47))
        | (1ULL << (bellParser::ALOGAND - 47))
        | (1ULL << (bellParser::ALOGANDEXT - 47))
        | (1ULL << (bellParser::ALOGXOR - 47))
        | (1ULL << (bellParser::ALOGOR - 47))
        | (1ULL << (bellParser::ALOGOREXT - 47))
        | (1ULL << (bellParser::ALSHIFT - 47))
        | (1ULL << (bellParser::ARSHIFT - 47))
        | (1ULL << (bellParser::ACONCAT - 47))
        | (1ULL << (bellParser::ARCONCAT - 47)))) != 0))) {
        antlrcpp::downCast<TrueAssignmentContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(455);
      list();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<bellParser::FakeAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(457);
      fakeLvalue();
      setState(458);
      antlrcpp::downCast<FakeAssignmentContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(((((_la - 50) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 50)) & ((1ULL << (bellParser::ASSIGN - 50))
        | (1ULL << (bellParser::APOW - 50))
        | (1ULL << (bellParser::ATIMES - 50))
        | (1ULL << (bellParser::ADIVDIV - 50))
        | (1ULL << (bellParser::ADIV - 50))
        | (1ULL << (bellParser::AREM - 50))
        | (1ULL << (bellParser::APLUS - 50))
        | (1ULL << (bellParser::AMINUS - 50))
        | (1ULL << (bellParser::ABITAND - 50))
        | (1ULL << (bellParser::ABITXOR - 50))
        | (1ULL << (bellParser::ABITOR - 50))
        | (1ULL << (bellParser::ALOGAND - 50))
        | (1ULL << (bellParser::ALOGANDEXT - 50))
        | (1ULL << (bellParser::ALOGXOR - 50))
        | (1ULL << (bellParser::ALOGOR - 50))
        | (1ULL << (bellParser::ALOGOREXT - 50))
        | (1ULL << (bellParser::ALSHIFT - 50))
        | (1ULL << (bellParser::ARSHIFT - 50))
        | (1ULL << (bellParser::ACONCAT - 50))
        | (1ULL << (bellParser::ARCONCAT - 50)))) != 0))) {
        antlrcpp::downCast<FakeAssignmentContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(459);
      list();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<bellParser::TrueAApplyContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(461);
      lvalue();
      setState(462);
      match(bellParser::AAPPLY);
      setState(463);
      funcall();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<bellParser::FakeAApplyContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(465);
      fakeLvalue();
      setState(466);
      match(bellParser::AAPPLY);
      setState(467);
      funcall();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<bellParser::OutletAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(469);
      match(bellParser::OUTLET);
      setState(470);
      match(bellParser::ASSIGN);
      setState(471);
      list();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<bellParser::DirOutletAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(472);
      match(bellParser::DIROUTLET);
      setState(473);
      match(bellParser::ASSIGN);
      setState(474);
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
  enterRule(_localctx, 60, bellParser::RuleConditional);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(489);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::IfthenContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(477);
      match(bellParser::IF);
      setState(478);
      sequence();
      setState(479);
      match(bellParser::THEN);
      setState(480);
      list();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::IfthenelseContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(482);
      match(bellParser::IF);
      setState(483);
      sequence();
      setState(484);
      match(bellParser::THEN);
      setState(485);
      sequence();
      setState(486);
      match(bellParser::ELSE);
      setState(487);
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

std::vector<bellParser::LlllContext *> bellParser::ListContext::llll() {
  return getRuleContexts<bellParser::LlllContext>();
}

bellParser::LlllContext* bellParser::ListContext::llll(size_t i) {
  return getRuleContext<bellParser::LlllContext>(i);
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
  enterRule(_localctx, 62, bellParser::RuleList);

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
    setState(493); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(493);
              _errHandler->sync(this);
              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
              case 1: {
                setState(491);
                llll();
                break;
              }

              case 2: {
                setState(492);
                expr(0);
                break;
              }

              default:
                break;
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(495); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
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
    case 25: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

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
