
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
      "fakeLvalue", "listEnd", "expr", "item", "assignment", "conditional", 
      "list"
    },
    std::vector<std::string>{
      "", "','", "'...'", "", "", "", "", "", "", "", "'null'", "'nil'", 
      "'if'", "'then'", "'else'", "'while'", "'for'", "'in'", "'as'", "'with'", 
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
      "SQSYMBOL", "EMPTYSYMBOL", "BACHNULL", "BACHNIL", "IF", "THEN", "ELSE", 
      "WHILE", "FOR", "IN", "AS", "WITH", "DO", "COLLECT", "INLET", "INTINLET", 
      "RATINLET", "FLOATINLET", "PITCHINLET", "OUTLET", "DIRINLET", "DIROUTLET", 
      "BIF", "OF", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "NAMEDPARAM", 
      "KEEP", "UNKEEP", "INIT", "ARGCOUNT", "PUSH", "POP", "CLOSED", "NTH", 
      "PICK", "KEY", "ANTH", "APICK", "NULLIFY", "ASSIGN", "WHITESPACE", 
      "NEWATOM", "POW", "APOW", "TIMES", "ATIMES", "DIVDIV", "ADIVDIV", 
      "DIV", "ADIV", "REM", "AREM", "PLUS", "APLUS", "UPLUS", "MINUS", "AMINUS", 
      "UMINUS", "EQUAL", "NEQ", "LOGNOT", "BITNOT", "LT", "GT", "LEQ", "GEQ", 
      "BITAND", "ABITAND", "BITXOR", "ABITXOR", "BITOR", "ABITOR", "LOGAND", 
      "LOGANDEXT", "ALOGAND", "ALOGANDEXT", "LOGXOR", "ALOGXOR", "LOGOR", 
      "ALOGOR", "LOGOREXT", "ALOGOREXT", "LSHIFT", "ALSHIFT", "RSHIFT", 
      "ARSHIFT", "REPEAT", "AREPEAT", "AAPPLY", "ACONCAT", "ARCONCAT", "OPEN", 
      "PARAMS", "FUNDEF", "LIFT", "ELLIPSIS", "BLOCKCOMMENT", "LINECOMMENT", 
      "ANYTHING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,108,466,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,71,8,1,1,2,1,
  	2,1,2,3,2,76,8,2,1,2,3,2,79,8,2,1,3,1,3,1,3,5,3,84,8,3,10,3,12,3,87,9,
  	3,1,4,1,4,1,4,5,4,92,8,4,10,4,12,4,95,9,4,1,4,1,4,1,5,1,5,3,5,101,8,5,
  	1,5,1,5,1,5,1,6,1,6,4,6,108,8,6,11,6,12,6,109,1,6,3,6,113,8,6,3,6,115,
  	8,6,1,7,1,7,4,7,119,8,7,11,7,12,7,120,1,8,1,8,1,8,1,8,1,8,1,9,1,9,3,9,
  	130,8,9,1,9,1,9,1,9,1,10,1,10,1,10,5,10,138,8,10,10,10,12,10,141,9,10,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,154,8,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,165,8,11,1,11,1,11,
  	1,11,3,11,170,8,11,1,12,1,12,1,12,3,12,175,8,12,1,12,1,12,5,12,179,8,
  	12,10,12,12,12,182,9,12,1,13,1,13,1,13,5,13,187,8,13,10,13,12,13,190,
  	9,13,1,14,1,14,1,14,3,14,195,8,14,1,14,1,14,1,14,1,14,1,14,3,14,202,8,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,210,8,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,3,14,218,8,14,1,14,1,14,1,14,3,14,223,8,14,1,14,1,14,1,14,3,14,
  	228,8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,3,14,247,8,14,1,14,1,14,1,14,5,14,252,8,14,10,
  	14,12,14,255,9,14,1,15,1,15,1,15,3,15,260,8,15,1,16,5,16,263,8,16,10,
  	16,12,16,266,9,16,1,16,1,16,1,17,1,17,1,17,1,17,4,17,274,8,17,11,17,12,
  	17,275,3,17,278,8,17,1,18,3,18,281,8,18,1,18,1,18,1,18,3,18,286,8,18,
  	1,19,1,19,1,19,1,19,3,19,292,8,19,1,20,5,20,295,8,20,10,20,12,20,298,
  	9,20,1,20,1,20,1,21,1,21,1,21,4,21,305,8,21,11,21,12,21,306,1,21,1,21,
  	1,21,5,21,312,8,21,10,21,12,21,315,9,21,1,21,1,21,3,21,319,8,21,1,22,
  	1,22,3,22,323,8,22,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,3,24,333,8,
  	24,1,25,1,25,1,25,1,25,1,25,3,25,340,8,25,1,25,1,25,1,25,4,25,345,8,25,
  	11,25,12,25,346,1,25,1,25,1,25,3,25,352,8,25,1,25,1,25,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,5,25,399,
  	8,25,10,25,12,25,402,9,25,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,
  	1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,3,26,425,
  	8,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,
  	1,27,1,27,1,27,1,27,1,27,3,27,445,8,27,1,28,1,28,1,28,1,28,1,28,1,28,
  	1,28,1,28,1,28,1,28,1,28,1,28,3,28,459,8,28,1,29,4,29,462,8,29,11,29,
  	12,29,463,1,29,0,2,28,50,30,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,
  	32,34,36,38,40,42,44,46,48,50,52,54,56,58,0,16,1,0,20,21,2,0,64,64,67,
  	67,1,0,36,37,2,0,43,43,45,45,1,0,70,71,4,0,54,54,56,56,58,58,60,60,2,
  	0,62,62,65,65,2,0,92,92,94,94,1,0,68,69,1,0,72,75,1,0,82,83,2,0,88,88,
  	90,90,1,0,7,8,1,0,22,26,19,0,46,46,49,49,53,53,55,55,57,57,59,59,61,61,
  	63,63,66,66,77,77,79,79,81,81,84,85,87,87,89,89,91,91,93,93,95,95,99,
  	100,18,0,49,49,53,53,55,55,57,57,59,59,61,61,63,63,66,66,77,77,79,79,
  	81,81,84,85,87,87,89,89,91,91,93,93,95,95,99,100,532,0,60,1,0,0,0,2,70,
  	1,0,0,0,4,78,1,0,0,0,6,80,1,0,0,0,8,88,1,0,0,0,10,98,1,0,0,0,12,114,1,
  	0,0,0,14,116,1,0,0,0,16,122,1,0,0,0,18,127,1,0,0,0,20,134,1,0,0,0,22,
  	169,1,0,0,0,24,171,1,0,0,0,26,183,1,0,0,0,28,227,1,0,0,0,30,259,1,0,0,
  	0,32,264,1,0,0,0,34,277,1,0,0,0,36,285,1,0,0,0,38,291,1,0,0,0,40,296,
  	1,0,0,0,42,318,1,0,0,0,44,320,1,0,0,0,46,324,1,0,0,0,48,332,1,0,0,0,50,
  	351,1,0,0,0,52,424,1,0,0,0,54,444,1,0,0,0,56,458,1,0,0,0,58,461,1,0,0,
  	0,60,61,3,2,1,0,61,1,1,0,0,0,62,71,5,0,0,1,63,64,3,12,6,0,64,65,5,0,0,
  	1,65,71,1,0,0,0,66,67,3,12,6,0,67,68,5,35,0,0,68,71,1,0,0,0,69,71,5,35,
  	0,0,70,62,1,0,0,0,70,63,1,0,0,0,70,66,1,0,0,0,70,69,1,0,0,0,71,3,1,0,
  	0,0,72,75,5,34,0,0,73,74,5,49,0,0,74,76,3,58,29,0,75,73,1,0,0,0,75,76,
  	1,0,0,0,76,79,1,0,0,0,77,79,5,105,0,0,78,72,1,0,0,0,78,77,1,0,0,0,79,
  	5,1,0,0,0,80,85,3,4,2,0,81,82,5,1,0,0,82,84,3,4,2,0,83,81,1,0,0,0,84,
  	87,1,0,0,0,85,83,1,0,0,0,85,86,1,0,0,0,86,7,1,0,0,0,87,85,1,0,0,0,88,
  	93,5,104,0,0,89,90,5,34,0,0,90,92,5,1,0,0,91,89,1,0,0,0,92,95,1,0,0,0,
  	93,91,1,0,0,0,93,94,1,0,0,0,94,96,1,0,0,0,95,93,1,0,0,0,96,97,5,34,0,
  	0,97,9,1,0,0,0,98,100,3,6,3,0,99,101,3,8,4,0,100,99,1,0,0,0,100,101,1,
  	0,0,0,101,102,1,0,0,0,102,103,5,103,0,0,103,104,3,58,29,0,104,11,1,0,
  	0,0,105,115,3,58,29,0,106,108,3,14,7,0,107,106,1,0,0,0,108,109,1,0,0,
  	0,109,107,1,0,0,0,109,110,1,0,0,0,110,112,1,0,0,0,111,113,3,58,29,0,112,
  	111,1,0,0,0,112,113,1,0,0,0,113,115,1,0,0,0,114,105,1,0,0,0,114,107,1,
  	0,0,0,115,13,1,0,0,0,116,118,3,58,29,0,117,119,5,48,0,0,118,117,1,0,0,
  	0,119,120,1,0,0,0,120,118,1,0,0,0,120,121,1,0,0,0,121,15,1,0,0,0,122,
  	123,5,15,0,0,123,124,3,12,6,0,124,125,7,0,0,0,125,126,3,58,29,0,126,17,
  	1,0,0,0,127,129,5,34,0,0,128,130,5,34,0,0,129,128,1,0,0,0,129,130,1,0,
  	0,0,130,131,1,0,0,0,131,132,5,17,0,0,132,133,3,12,6,0,133,19,1,0,0,0,
  	134,139,3,18,9,0,135,136,5,1,0,0,136,138,3,18,9,0,137,135,1,0,0,0,138,
  	141,1,0,0,0,139,137,1,0,0,0,139,140,1,0,0,0,140,21,1,0,0,0,141,139,1,
  	0,0,0,142,143,5,16,0,0,143,144,3,20,10,0,144,145,7,0,0,0,145,146,3,58,
  	29,0,146,170,1,0,0,0,147,148,5,16,0,0,148,149,3,20,10,0,149,150,5,18,
  	0,0,150,153,3,12,6,0,151,152,5,19,0,0,152,154,3,24,12,0,153,151,1,0,0,
  	0,153,154,1,0,0,0,154,155,1,0,0,0,155,156,7,0,0,0,156,157,3,58,29,0,157,
  	170,1,0,0,0,158,159,5,16,0,0,159,160,3,20,10,0,160,161,5,19,0,0,161,164,
  	3,24,12,0,162,163,5,18,0,0,163,165,3,12,6,0,164,162,1,0,0,0,164,165,1,
  	0,0,0,165,166,1,0,0,0,166,167,7,0,0,0,167,168,3,58,29,0,168,170,1,0,0,
  	0,169,142,1,0,0,0,169,147,1,0,0,0,169,158,1,0,0,0,170,23,1,0,0,0,171,
  	172,5,35,0,0,172,180,3,12,6,0,173,175,5,1,0,0,174,173,1,0,0,0,174,175,
  	1,0,0,0,175,176,1,0,0,0,176,177,5,35,0,0,177,179,3,12,6,0,178,174,1,0,
  	0,0,179,182,1,0,0,0,180,178,1,0,0,0,180,181,1,0,0,0,181,25,1,0,0,0,182,
  	180,1,0,0,0,183,188,3,12,6,0,184,185,5,1,0,0,185,187,3,12,6,0,186,184,
  	1,0,0,0,187,190,1,0,0,0,188,186,1,0,0,0,188,189,1,0,0,0,189,27,1,0,0,
  	0,190,188,1,0,0,0,191,194,6,14,-1,0,192,195,3,52,26,0,193,195,3,36,18,
  	0,194,192,1,0,0,0,194,193,1,0,0,0,195,196,1,0,0,0,196,197,5,102,0,0,197,
  	198,5,42,0,0,198,228,1,0,0,0,199,202,3,52,26,0,200,202,3,36,18,0,201,
  	199,1,0,0,0,201,200,1,0,0,0,202,203,1,0,0,0,203,204,5,102,0,0,204,205,
  	3,26,13,0,205,206,5,42,0,0,206,228,1,0,0,0,207,210,3,52,26,0,208,210,
  	3,36,18,0,209,207,1,0,0,0,209,208,1,0,0,0,210,211,1,0,0,0,211,212,5,102,
  	0,0,212,213,3,24,12,0,213,214,5,42,0,0,214,228,1,0,0,0,215,218,3,52,26,
  	0,216,218,3,36,18,0,217,215,1,0,0,0,217,216,1,0,0,0,218,219,1,0,0,0,219,
  	220,5,102,0,0,220,222,3,26,13,0,221,223,5,1,0,0,222,221,1,0,0,0,222,223,
  	1,0,0,0,223,224,1,0,0,0,224,225,3,24,12,0,225,226,5,42,0,0,226,228,1,
  	0,0,0,227,191,1,0,0,0,227,201,1,0,0,0,227,209,1,0,0,0,227,217,1,0,0,0,
  	228,253,1,0,0,0,229,230,10,4,0,0,230,231,5,102,0,0,231,252,5,42,0,0,232,
  	233,10,3,0,0,233,234,5,102,0,0,234,235,3,26,13,0,235,236,5,42,0,0,236,
  	252,1,0,0,0,237,238,10,2,0,0,238,239,5,102,0,0,239,240,3,24,12,0,240,
  	241,5,42,0,0,241,252,1,0,0,0,242,243,10,1,0,0,243,244,5,102,0,0,244,246,
  	3,26,13,0,245,247,5,1,0,0,246,245,1,0,0,0,246,247,1,0,0,0,247,248,1,0,
  	0,0,248,249,3,24,12,0,249,250,5,42,0,0,250,252,1,0,0,0,251,229,1,0,0,
  	0,251,232,1,0,0,0,251,237,1,0,0,0,251,242,1,0,0,0,252,255,1,0,0,0,253,
  	251,1,0,0,0,253,254,1,0,0,0,254,29,1,0,0,0,255,253,1,0,0,0,256,260,3,
  	52,26,0,257,260,3,36,18,0,258,260,3,28,14,0,259,256,1,0,0,0,259,257,1,
  	0,0,0,259,258,1,0,0,0,260,31,1,0,0,0,261,263,7,1,0,0,262,261,1,0,0,0,
  	263,266,1,0,0,0,264,262,1,0,0,0,264,265,1,0,0,0,265,267,1,0,0,0,266,264,
  	1,0,0,0,267,268,3,30,15,0,268,33,1,0,0,0,269,278,3,28,14,0,270,273,3,
  	32,16,0,271,272,5,45,0,0,272,274,3,28,14,0,273,271,1,0,0,0,274,275,1,
  	0,0,0,275,273,1,0,0,0,275,276,1,0,0,0,276,278,1,0,0,0,277,269,1,0,0,0,
  	277,270,1,0,0,0,278,35,1,0,0,0,279,281,7,2,0,0,280,279,1,0,0,0,280,281,
  	1,0,0,0,281,282,1,0,0,0,282,286,5,34,0,0,283,286,5,33,0,0,284,286,5,32,
  	0,0,285,280,1,0,0,0,285,283,1,0,0,0,285,284,1,0,0,0,286,37,1,0,0,0,287,
  	292,3,56,28,0,288,292,3,16,8,0,289,292,3,22,11,0,290,292,3,10,5,0,291,
  	287,1,0,0,0,291,288,1,0,0,0,291,289,1,0,0,0,291,290,1,0,0,0,292,39,1,
  	0,0,0,293,295,7,1,0,0,294,293,1,0,0,0,295,298,1,0,0,0,296,294,1,0,0,0,
  	296,297,1,0,0,0,297,299,1,0,0,0,298,296,1,0,0,0,299,300,3,38,19,0,300,
  	41,1,0,0,0,301,304,6,21,-1,0,302,303,7,3,0,0,303,305,3,32,16,0,304,302,
  	1,0,0,0,305,306,1,0,0,0,306,304,1,0,0,0,306,307,1,0,0,0,307,319,1,0,0,
  	0,308,313,6,21,-1,0,309,310,7,3,0,0,310,312,3,32,16,0,311,309,1,0,0,0,
  	312,315,1,0,0,0,313,311,1,0,0,0,313,314,1,0,0,0,314,316,1,0,0,0,315,313,
  	1,0,0,0,316,317,7,3,0,0,317,319,3,40,20,0,318,301,1,0,0,0,318,308,1,0,
  	0,0,319,43,1,0,0,0,320,322,3,36,18,0,321,323,3,42,21,0,322,321,1,0,0,
  	0,322,323,1,0,0,0,323,45,1,0,0,0,324,325,3,52,26,0,325,326,3,42,21,0,
  	326,47,1,0,0,0,327,333,3,56,28,0,328,333,3,54,27,0,329,333,3,16,8,0,330,
  	333,3,22,11,0,331,333,3,10,5,0,332,327,1,0,0,0,332,328,1,0,0,0,332,329,
  	1,0,0,0,332,330,1,0,0,0,332,331,1,0,0,0,333,49,1,0,0,0,334,339,6,25,-1,
  	0,335,340,3,52,26,0,336,340,3,36,18,0,337,340,3,34,17,0,338,340,3,48,
  	24,0,339,335,1,0,0,0,339,336,1,0,0,0,339,337,1,0,0,0,339,338,1,0,0,0,
  	340,352,1,0,0,0,341,352,3,44,22,0,342,352,3,46,23,0,343,345,7,1,0,0,344,
  	343,1,0,0,0,345,346,1,0,0,0,346,344,1,0,0,0,346,347,1,0,0,0,347,348,1,
  	0,0,0,348,352,3,50,25,15,349,350,7,4,0,0,350,352,3,50,25,1,351,334,1,
  	0,0,0,351,341,1,0,0,0,351,342,1,0,0,0,351,344,1,0,0,0,351,349,1,0,0,0,
  	352,400,1,0,0,0,353,354,10,17,0,0,354,355,5,44,0,0,355,399,3,50,25,18,
  	356,357,10,16,0,0,357,358,5,52,0,0,358,399,3,50,25,16,359,360,10,14,0,
  	0,360,361,7,5,0,0,361,399,3,50,25,15,362,363,10,13,0,0,363,364,7,6,0,
  	0,364,399,3,50,25,14,365,366,10,12,0,0,366,367,7,7,0,0,367,399,3,50,25,
  	13,368,369,10,11,0,0,369,370,5,2,0,0,370,399,3,50,25,12,371,372,10,10,
  	0,0,372,373,5,96,0,0,373,399,3,50,25,11,374,375,10,9,0,0,375,376,7,8,
  	0,0,376,399,3,50,25,10,377,378,10,8,0,0,378,379,7,9,0,0,379,399,3,50,
  	25,9,380,381,10,7,0,0,381,382,5,76,0,0,382,399,3,50,25,8,383,384,10,6,
  	0,0,384,385,5,78,0,0,385,399,3,50,25,7,386,387,10,5,0,0,387,388,5,80,
  	0,0,388,399,3,50,25,6,389,390,10,4,0,0,390,391,7,10,0,0,391,399,3,50,
  	25,5,392,393,10,3,0,0,393,394,5,86,0,0,394,399,3,50,25,4,395,396,10,2,
  	0,0,396,397,7,11,0,0,397,399,3,50,25,3,398,353,1,0,0,0,398,356,1,0,0,
  	0,398,359,1,0,0,0,398,362,1,0,0,0,398,365,1,0,0,0,398,368,1,0,0,0,398,
  	371,1,0,0,0,398,374,1,0,0,0,398,377,1,0,0,0,398,380,1,0,0,0,398,383,1,
  	0,0,0,398,386,1,0,0,0,398,389,1,0,0,0,398,392,1,0,0,0,398,395,1,0,0,0,
  	399,402,1,0,0,0,400,398,1,0,0,0,400,401,1,0,0,0,401,51,1,0,0,0,402,400,
  	1,0,0,0,403,425,5,3,0,0,404,425,5,4,0,0,405,425,5,5,0,0,406,425,5,6,0,
  	0,407,425,7,12,0,0,408,425,5,9,0,0,409,425,5,30,0,0,410,425,5,31,0,0,
  	411,425,7,13,0,0,412,425,5,28,0,0,413,425,5,39,0,0,414,425,5,10,0,0,415,
  	425,5,11,0,0,416,417,5,101,0,0,417,418,3,12,6,0,418,419,5,42,0,0,419,
  	425,1,0,0,0,420,421,5,40,0,0,421,422,3,12,6,0,422,423,5,41,0,0,423,425,
  	1,0,0,0,424,403,1,0,0,0,424,404,1,0,0,0,424,405,1,0,0,0,424,406,1,0,0,
  	0,424,407,1,0,0,0,424,408,1,0,0,0,424,409,1,0,0,0,424,410,1,0,0,0,424,
  	411,1,0,0,0,424,412,1,0,0,0,424,413,1,0,0,0,424,414,1,0,0,0,424,415,1,
  	0,0,0,424,416,1,0,0,0,424,420,1,0,0,0,425,53,1,0,0,0,426,427,5,38,0,0,
  	427,428,5,34,0,0,428,429,5,49,0,0,429,445,3,58,29,0,430,431,3,44,22,0,
  	431,432,7,14,0,0,432,433,3,58,29,0,433,445,1,0,0,0,434,435,3,46,23,0,
  	435,436,7,15,0,0,436,437,3,58,29,0,437,445,1,0,0,0,438,439,5,27,0,0,439,
  	440,5,49,0,0,440,445,3,58,29,0,441,442,5,29,0,0,442,443,5,49,0,0,443,
  	445,3,58,29,0,444,426,1,0,0,0,444,430,1,0,0,0,444,434,1,0,0,0,444,438,
  	1,0,0,0,444,441,1,0,0,0,445,55,1,0,0,0,446,447,5,12,0,0,447,448,3,12,
  	6,0,448,449,5,13,0,0,449,450,3,58,29,0,450,459,1,0,0,0,451,452,5,12,0,
  	0,452,453,3,12,6,0,453,454,5,13,0,0,454,455,3,12,6,0,455,456,5,14,0,0,
  	456,457,3,58,29,0,457,459,1,0,0,0,458,446,1,0,0,0,458,451,1,0,0,0,459,
  	57,1,0,0,0,460,462,3,50,25,0,461,460,1,0,0,0,462,463,1,0,0,0,463,461,
  	1,0,0,0,463,464,1,0,0,0,464,59,1,0,0,0,49,70,75,78,85,93,100,109,112,
  	114,120,129,139,153,164,169,174,180,188,194,201,209,217,222,227,246,251,
  	253,259,264,275,277,280,285,291,296,306,313,318,322,332,339,346,351,398,
  	400,424,444,458,463
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
    setState(60);
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
    setState(70);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::ProgramEOFContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(62);
      match(bellParser::EOF);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::ProgramSequenceContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(63);
      sequence();
      setState(64);
      match(bellParser::EOF);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<bellParser::ProgramSequenceNamedparamContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(66);
      sequence();
      setState(67);
      match(bellParser::NAMEDPARAM);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<bellParser::ProgramNamedparamContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(69);
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
    setState(78);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::LOCALVAR: {
        _localctx = _tracker.createInstance<bellParser::FunargVarContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(72);
        match(bellParser::LOCALVAR);
        setState(75);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bellParser::ASSIGN) {
          setState(73);
          match(bellParser::ASSIGN);
          setState(74);
          list();
        }
        break;
      }

      case bellParser::ELLIPSIS: {
        _localctx = _tracker.createInstance<bellParser::FunargEllipsisContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(77);
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
    setState(80);
    funarg();
    setState(85);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::T__0) {
      setState(81);
      match(bellParser::T__0);
      setState(82);
      funarg();
      setState(87);
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
    setState(88);
    match(bellParser::LIFT);
    setState(93);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(89);
        match(bellParser::LOCALVAR);
        setState(90);
        match(bellParser::T__0); 
      }
      setState(95);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(96);
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
    setState(98);
    funargList();
    setState(100);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == bellParser::LIFT) {
      setState(99);
      liftedargList();
    }
    setState(102);
    match(bellParser::FUNDEF);
    setState(103);
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
    setState(114);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(105);
      list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(107); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(106);
                nullified();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(109); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(112);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << bellParser::UINT)
        | (1ULL << bellParser::UFLOAT)
        | (1ULL << bellParser::UPITCH)
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
        | (1ULL << bellParser::GLOBALVAR)
        | (1ULL << bellParser::PATCHERVAR)
        | (1ULL << bellParser::LOCALVAR)
        | (1ULL << bellParser::KEEP)
        | (1ULL << bellParser::UNKEEP)
        | (1ULL << bellParser::INIT)
        | (1ULL << bellParser::ARGCOUNT)
        | (1ULL << bellParser::PUSH))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (bellParser::UPLUS - 64))
        | (1ULL << (bellParser::UMINUS - 64))
        | (1ULL << (bellParser::LOGNOT - 64))
        | (1ULL << (bellParser::BITNOT - 64))
        | (1ULL << (bellParser::OPEN - 64))
        | (1ULL << (bellParser::ELLIPSIS - 64)))) != 0)) {
        setState(111);
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
    setState(116);
    list();
    setState(118); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(117);
      match(bellParser::NULLIFY);
      setState(120); 
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
    setState(122);
    match(bellParser::WHILE);
    setState(123);
    sequence();
    setState(124);
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
    setState(125);
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
    setState(127);
    match(bellParser::LOCALVAR);

    setState(129);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == bellParser::LOCALVAR) {
      setState(128);
      match(bellParser::LOCALVAR);
    }
    setState(131);
    match(bellParser::IN);
    setState(132);
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
    setState(134);
    forarg();
    setState(139);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::T__0) {
      setState(135);
      match(bellParser::T__0);
      setState(136);
      forarg();
      setState(141);
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
    setState(169);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(142);
      match(bellParser::FOR);
      setState(143);
      forargList();
      setState(144);
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
      setState(145);
      list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(147);
      match(bellParser::FOR);
      setState(148);
      forargList();
      setState(149);
      match(bellParser::AS);
      setState(150);
      sequence();
      setState(153);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::WITH) {
        setState(151);
        match(bellParser::WITH);
        setState(152);
        argsByNameList();
      }
      setState(155);
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
      setState(156);
      list();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(158);
      match(bellParser::FOR);
      setState(159);
      forargList();
      setState(160);
      match(bellParser::WITH);
      setState(161);
      argsByNameList();
      setState(164);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::AS) {
        setState(162);
        match(bellParser::AS);
        setState(163);
        sequence();
      }
      setState(166);
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
      setState(167);
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
    setState(171);
    match(bellParser::NAMEDPARAM);
    setState(172);
    sequence();
    setState(180);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::T__0

    || _la == bellParser::NAMEDPARAM) {
      setState(174);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::T__0) {
        setState(173);
        match(bellParser::T__0);
      }
      setState(176);
      match(bellParser::NAMEDPARAM);
      setState(177);
      sequence();
      setState(182);
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
    setState(183);
    sequence();
    setState(188);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(184);
        match(bellParser::T__0);
        setState(185);
        sequence(); 
      }
      setState(190);
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
    setState(227);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(194);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case bellParser::UINT:
        case bellParser::UFLOAT:
        case bellParser::UPITCH:
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
        case bellParser::OPEN: {
          setState(192);
          item();
          break;
        }

        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR:
        case bellParser::KEEP:
        case bellParser::UNKEEP: {
          setState(193);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(196);
      match(bellParser::PARAMS);
      setState(197);
      match(bellParser::CLOSED);
      break;
    }

    case 2: {
      setState(201);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case bellParser::UINT:
        case bellParser::UFLOAT:
        case bellParser::UPITCH:
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
        case bellParser::OPEN: {
          setState(199);
          item();
          break;
        }

        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR:
        case bellParser::KEEP:
        case bellParser::UNKEEP: {
          setState(200);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(203);
      match(bellParser::PARAMS);
      setState(204);
      argsByPositionList();
      setState(205);
      match(bellParser::CLOSED);
      break;
    }

    case 3: {
      setState(209);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case bellParser::UINT:
        case bellParser::UFLOAT:
        case bellParser::UPITCH:
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
        case bellParser::OPEN: {
          setState(207);
          item();
          break;
        }

        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR:
        case bellParser::KEEP:
        case bellParser::UNKEEP: {
          setState(208);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(211);
      match(bellParser::PARAMS);
      setState(212);
      argsByNameList();
      setState(213);
      match(bellParser::CLOSED);
      break;
    }

    case 4: {
      setState(217);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case bellParser::UINT:
        case bellParser::UFLOAT:
        case bellParser::UPITCH:
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
        case bellParser::OPEN: {
          setState(215);
          item();
          break;
        }

        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR:
        case bellParser::KEEP:
        case bellParser::UNKEEP: {
          setState(216);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(219);
      match(bellParser::PARAMS);
      setState(220);
      argsByPositionList();
      setState(222);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::T__0) {
        setState(221);
        match(bellParser::T__0);
      }
      setState(224);
      argsByNameList();
      setState(225);
      match(bellParser::CLOSED);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(253);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(251);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(229);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(230);
          match(bellParser::PARAMS);
          setState(231);
          match(bellParser::CLOSED);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(232);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(233);
          match(bellParser::PARAMS);
          setState(234);
          argsByPositionList();
          setState(235);
          match(bellParser::CLOSED);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(237);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(238);
          match(bellParser::PARAMS);
          setState(239);
          argsByNameList();
          setState(240);
          match(bellParser::CLOSED);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(242);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(243);
          match(bellParser::PARAMS);
          setState(244);
          argsByPositionList();
          setState(246);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == bellParser::T__0) {
            setState(245);
            match(bellParser::T__0);
          }
          setState(248);
          argsByNameList();
          setState(249);
          match(bellParser::CLOSED);
          break;
        }

        default:
          break;
        } 
      }
      setState(255);
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
    setState(259);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(256);
      item();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(257);
      var();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(258);
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
    setState(264);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::UPLUS

    || _la == bellParser::UMINUS) {
      setState(261);
      _la = _input->LA(1);
      if (!(_la == bellParser::UPLUS

      || _la == bellParser::UMINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(266);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(267);
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
    setState(277);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(269);
      simpleFuncall(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(270);
      dataFlowAndLvalueSpecsItem();
      setState(273); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(271);
                match(bellParser::KEY);
                setState(272);
                simpleFuncall(0);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(275); 
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
    setState(285);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::LOCALVAR:
      case bellParser::KEEP:
      case bellParser::UNKEEP: {
        _localctx = _tracker.createInstance<bellParser::VarLocalContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(280);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bellParser::KEEP

        || _la == bellParser::UNKEEP) {
          setState(279);
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
        setState(282);
        match(bellParser::LOCALVAR);
        break;
      }

      case bellParser::PATCHERVAR: {
        _localctx = _tracker.createInstance<bellParser::VarPatcherContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(283);
        match(bellParser::PATCHERVAR);
        break;
      }

      case bellParser::GLOBALVAR: {
        _localctx = _tracker.createInstance<bellParser::VarGlobalContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(284);
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
    setState(291);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(287);
        conditional();
        break;
      }

      case bellParser::WHILE: {
        enterOuterAlt(_localctx, 2);
        setState(288);
        whileloop();
        break;
      }

      case bellParser::FOR: {
        enterOuterAlt(_localctx, 3);
        setState(289);
        forloop();
        break;
      }

      case bellParser::LOCALVAR:
      case bellParser::ELLIPSIS: {
        enterOuterAlt(_localctx, 4);
        setState(290);
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
    setState(296);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::UPLUS

    || _la == bellParser::UMINUS) {
      setState(293);
      _la = _input->LA(1);
      if (!(_la == bellParser::UPLUS

      || _la == bellParser::UMINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(298);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(299);
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
    setState(318);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      ending = false;
      setState(304); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(302);
                _la = _input->LA(1);
                if (!(_la == bellParser::NTH

                || _la == bellParser::KEY)) {
                _errHandler->recoverInline(this);
                }
                else {
                  _errHandler->reportMatch(this);
                  consume();
                }
                setState(303);
                dataFlowAndLvalueSpecsItem();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(306); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
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
          setState(309);
          _la = _input->LA(1);
          if (!(_la == bellParser::NTH

          || _la == bellParser::KEY)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(310);
          dataFlowAndLvalueSpecsItem(); 
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
  enterRule(_localctx, 48, bellParser::RuleListEnd);

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
          if (!(((((_la - 72) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 72)) & ((1ULL << (bellParser::LT - 72))
            | (1ULL << (bellParser::GT - 72))
            | (1ULL << (bellParser::LEQ - 72))
            | (1ULL << (bellParser::GEQ - 72)))) != 0))) {
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
//----------------- ItemEmptySymbolContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemEmptySymbolContext::EMPTYSYMBOL() {
  return getToken(bellParser::EMPTYSYMBOL, 0);
}

bellParser::ItemEmptySymbolContext::ItemEmptySymbolContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemEmptySymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemEmptySymbol(this);
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
  enterRule(_localctx, 52, bellParser::RuleItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(424);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::UINT: {
        _localctx = _tracker.createInstance<bellParser::ItemUintContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(403);
        match(bellParser::UINT);
        break;
      }

      case bellParser::UFLOAT: {
        _localctx = _tracker.createInstance<bellParser::ItemUfloatContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(404);
        match(bellParser::UFLOAT);
        break;
      }

      case bellParser::UPITCH: {
        _localctx = _tracker.createInstance<bellParser::ItemUpitchContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(405);
        match(bellParser::UPITCH);
        break;
      }

      case bellParser::BTSYMBOL: {
        _localctx = _tracker.createInstance<bellParser::ItemBtSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(406);
        match(bellParser::BTSYMBOL);
        break;
      }

      case bellParser::DQSYMBOL:
      case bellParser::SQSYMBOL: {
        _localctx = _tracker.createInstance<bellParser::ItemQSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(407);
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
        _localctx = _tracker.createInstance<bellParser::ItemEmptySymbolContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(408);
        match(bellParser::EMPTYSYMBOL);
        break;
      }

      case bellParser::BIF: {
        _localctx = _tracker.createInstance<bellParser::ItemBIFContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(409);
        match(bellParser::BIF);
        break;
      }

      case bellParser::OF: {
        _localctx = _tracker.createInstance<bellParser::ItemOFContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(410);
        match(bellParser::OF);
        break;
      }

      case bellParser::INLET:
      case bellParser::INTINLET:
      case bellParser::RATINLET:
      case bellParser::FLOATINLET:
      case bellParser::PITCHINLET: {
        _localctx = _tracker.createInstance<bellParser::ItemInletContext>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(411);
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
        enterOuterAlt(_localctx, 10);
        setState(412);
        match(bellParser::DIRINLET);
        break;
      }

      case bellParser::ARGCOUNT: {
        _localctx = _tracker.createInstance<bellParser::ItemArgcountContext>(_localctx);
        enterOuterAlt(_localctx, 11);
        setState(413);
        match(bellParser::ARGCOUNT);
        break;
      }

      case bellParser::BACHNULL: {
        _localctx = _tracker.createInstance<bellParser::ItemNullContext>(_localctx);
        enterOuterAlt(_localctx, 12);
        setState(414);
        match(bellParser::BACHNULL);
        break;
      }

      case bellParser::BACHNIL: {
        _localctx = _tracker.createInstance<bellParser::ItemNilContext>(_localctx);
        enterOuterAlt(_localctx, 13);
        setState(415);
        match(bellParser::BACHNIL);
        break;
      }

      case bellParser::OPEN: {
        _localctx = _tracker.createInstance<bellParser::ItemSequenceContext>(_localctx);
        enterOuterAlt(_localctx, 14);
        setState(416);
        match(bellParser::OPEN);
        setState(417);
        sequence();
        setState(418);
        match(bellParser::CLOSED);
        break;
      }

      case bellParser::PUSH: {
        _localctx = _tracker.createInstance<bellParser::ItemSublistContext>(_localctx);
        enterOuterAlt(_localctx, 15);
        setState(420);
        match(bellParser::PUSH);
        setState(421);
        sequence();
        setState(422);
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
  enterRule(_localctx, 54, bellParser::RuleAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(444);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::INIT: {
        _localctx = _tracker.createInstance<bellParser::InitAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(426);
        match(bellParser::INIT);
        setState(427);
        match(bellParser::LOCALVAR);
        setState(428);
        match(bellParser::ASSIGN);
        setState(429);
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
        setState(430);
        lvalue();
        setState(431);
        antlrcpp::downCast<TrueAssignmentContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 46) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 46)) & ((1ULL << (bellParser::ANTH - 46))
          | (1ULL << (bellParser::ASSIGN - 46))
          | (1ULL << (bellParser::APOW - 46))
          | (1ULL << (bellParser::ATIMES - 46))
          | (1ULL << (bellParser::ADIVDIV - 46))
          | (1ULL << (bellParser::ADIV - 46))
          | (1ULL << (bellParser::AREM - 46))
          | (1ULL << (bellParser::APLUS - 46))
          | (1ULL << (bellParser::AMINUS - 46))
          | (1ULL << (bellParser::ABITAND - 46))
          | (1ULL << (bellParser::ABITXOR - 46))
          | (1ULL << (bellParser::ABITOR - 46))
          | (1ULL << (bellParser::ALOGAND - 46))
          | (1ULL << (bellParser::ALOGANDEXT - 46))
          | (1ULL << (bellParser::ALOGXOR - 46))
          | (1ULL << (bellParser::ALOGOR - 46))
          | (1ULL << (bellParser::ALOGOREXT - 46))
          | (1ULL << (bellParser::ALSHIFT - 46))
          | (1ULL << (bellParser::ARSHIFT - 46))
          | (1ULL << (bellParser::ACONCAT - 46))
          | (1ULL << (bellParser::ARCONCAT - 46)))) != 0))) {
          antlrcpp::downCast<TrueAssignmentContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(432);
        list();
        break;
      }

      case bellParser::UINT:
      case bellParser::UFLOAT:
      case bellParser::UPITCH:
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
      case bellParser::OPEN: {
        _localctx = _tracker.createInstance<bellParser::FakeAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(434);
        fakeLvalue();
        setState(435);
        antlrcpp::downCast<FakeAssignmentContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 49) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 49)) & ((1ULL << (bellParser::ASSIGN - 49))
          | (1ULL << (bellParser::APOW - 49))
          | (1ULL << (bellParser::ATIMES - 49))
          | (1ULL << (bellParser::ADIVDIV - 49))
          | (1ULL << (bellParser::ADIV - 49))
          | (1ULL << (bellParser::AREM - 49))
          | (1ULL << (bellParser::APLUS - 49))
          | (1ULL << (bellParser::AMINUS - 49))
          | (1ULL << (bellParser::ABITAND - 49))
          | (1ULL << (bellParser::ABITXOR - 49))
          | (1ULL << (bellParser::ABITOR - 49))
          | (1ULL << (bellParser::ALOGAND - 49))
          | (1ULL << (bellParser::ALOGANDEXT - 49))
          | (1ULL << (bellParser::ALOGXOR - 49))
          | (1ULL << (bellParser::ALOGOR - 49))
          | (1ULL << (bellParser::ALOGOREXT - 49))
          | (1ULL << (bellParser::ALSHIFT - 49))
          | (1ULL << (bellParser::ARSHIFT - 49))
          | (1ULL << (bellParser::ACONCAT - 49))
          | (1ULL << (bellParser::ARCONCAT - 49)))) != 0))) {
          antlrcpp::downCast<FakeAssignmentContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(436);
        list();
        break;
      }

      case bellParser::OUTLET: {
        _localctx = _tracker.createInstance<bellParser::OutletAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(438);
        match(bellParser::OUTLET);
        setState(439);
        match(bellParser::ASSIGN);
        setState(440);
        list();
        break;
      }

      case bellParser::DIROUTLET: {
        _localctx = _tracker.createInstance<bellParser::DirOutletAssignmentContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(441);
        match(bellParser::DIROUTLET);
        setState(442);
        match(bellParser::ASSIGN);
        setState(443);
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
  enterRule(_localctx, 56, bellParser::RuleConditional);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(458);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::IfthenContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(446);
      match(bellParser::IF);
      setState(447);
      sequence();
      setState(448);
      match(bellParser::THEN);
      setState(449);
      list();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::IfthenelseContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(451);
      match(bellParser::IF);
      setState(452);
      sequence();
      setState(453);
      match(bellParser::THEN);
      setState(454);
      sequence();
      setState(455);
      match(bellParser::ELSE);
      setState(456);
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
  enterRule(_localctx, 58, bellParser::RuleList);

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
    setState(461); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(460);
              expr(0);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(463); 
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
