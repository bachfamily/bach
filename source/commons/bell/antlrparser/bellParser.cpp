
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
      "lvalueSpecsUItem", "lvalueSpecsItem", "dataflowHead", "funcall", 
      "var", "lvalueSpecsUFinal", "lvalueSpecsFinal", "lvalue", "fakeLvalue", 
      "lvalueSpecs", "listEnd", "expr", "item", "assignment", "conditional", 
      "list"
    },
    std::vector<std::string>{
      "", "','", "'...'", "", "", "", "", "", "'t'", "'r'", "'pi'", "", 
      "", "", "", "'null'", "'nil'", "'if'", "'then'", "'else'", "'while'", 
      "'for'", "'in'", "'as'", "'with'", "'do'", "'collect'", "", "", "", 
      "", "", "", "", "", "", "", "'$argcount'", "'keep'", "'unkeep'", "'init'", 
      "", "", "", "", "'['", "']'", "')'", "':'", "'::'", "'.'", "':='", 
      "'::='", "';'", "'='", "", "", "'**'", "'**='", "'*'", "'*='", "'//'", 
      "'//='", "'/'", "'/='", "'%'", "'%='", "", "'+='", "'+'", "", "'-='", 
      "'-'", "'=='", "'!='", "'!'", "'~'", "'<'", "'>'", "'<='", "'>='", 
      "'&'", "'&='", "'^'", "'^='", "'|'", "'|='", "'&&'", "'&&&'", "'&&='", 
      "'&&&='", "'^^'", "'^^='", "'||'", "'||='", "'|||'", "'|||='", "'<<'", 
      "'<<='", "'>>'", "'>>='", "':*'", "':*='", "'.='", "'_='", "'!_='", 
      "", "", "'->'", "'-^'", "'<...>'"
    },
    std::vector<std::string>{
      "", "", "RANGE", "UINT", "UFLOAT", "ETPITCHBASE", "JIPITCHBASE", "JIPITCHCOMMAS", 
      "T", "R", "K_PI", "BTSYMBOL", "DQSYMBOL", "SQSYMBOL", "EMPTYSYMBOL", 
      "BACHNULL", "BACHNIL", "IF", "THEN", "ELSE", "WHILE", "FOR", "IN", 
      "AS", "WITH", "DO", "COLLECT", "INLET", "INTINLET", "RATINLET", "FLOATINLET", 
      "PITCHINLET", "OUTLET", "DIRINLET", "DIROUTLET", "BIF", "OF", "ARGCOUNT", 
      "KEEP", "UNKEEP", "INIT", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "NAMEDPARAM", 
      "PUSH", "POP", "CLOSED", "NTH", "PICK", "KEY", "ANTH", "APICK", "NULLIFY", 
      "ASSIGN", "WHITESPACE", "NEWATOM", "POW", "APOW", "TIMES", "ATIMES", 
      "DIVDIV", "ADIVDIV", "DIV", "ADIV", "REM", "AREM", "PLUS", "APLUS", 
      "UPLUS", "MINUS", "AMINUS", "UMINUS", "EQUAL", "NEQ", "LOGNOT", "BITNOT", 
      "LT", "GT", "LEQ", "GEQ", "BITAND", "ABITAND", "BITXOR", "ABITXOR", 
      "BITOR", "ABITOR", "LOGAND", "LOGANDEXT", "ALOGAND", "ALOGANDEXT", 
      "LOGXOR", "ALOGXOR", "LOGOR", "ALOGOR", "LOGOREXT", "ALOGOREXT", "LSHIFT", 
      "ALSHIFT", "RSHIFT", "ARSHIFT", "REPEAT", "AREPEAT", "AAPPLY", "ACONCAT", 
      "ARCONCAT", "OPEN", "PARAMS", "FUNDEF", "LIFT", "ELLIPSIS", "BLOCKCOMMENT", 
      "LINECOMMENT", "ANYTHING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,113,497,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,73,
  	8,1,1,2,1,2,1,2,3,2,78,8,2,1,2,3,2,81,8,2,1,3,1,3,1,3,5,3,86,8,3,10,3,
  	12,3,89,9,3,1,4,1,4,1,4,5,4,94,8,4,10,4,12,4,97,9,4,1,4,1,4,1,5,1,5,3,
  	5,103,8,5,1,5,1,5,1,5,1,6,1,6,4,6,110,8,6,11,6,12,6,111,1,6,3,6,115,8,
  	6,3,6,117,8,6,1,7,1,7,4,7,121,8,7,11,7,12,7,122,1,8,1,8,1,8,1,8,1,8,1,
  	9,1,9,3,9,132,8,9,1,9,1,9,1,9,1,10,1,10,1,10,5,10,140,8,10,10,10,12,10,
  	143,9,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,
  	156,8,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,167,8,11,1,
  	11,1,11,1,11,3,11,172,8,11,1,12,1,12,1,12,3,12,177,8,12,1,12,1,12,5,12,
  	181,8,12,10,12,12,12,184,9,12,1,13,1,13,1,13,5,13,189,8,13,10,13,12,13,
  	192,9,13,1,14,1,14,1,14,3,14,197,8,14,1,14,1,14,1,14,1,14,1,14,3,14,204,
  	8,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,212,8,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,3,14,220,8,14,1,14,1,14,1,14,3,14,225,8,14,1,14,1,14,1,14,3,
  	14,230,8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,3,14,249,8,14,1,14,1,14,1,14,5,14,254,8,14,
  	10,14,12,14,257,9,14,1,15,1,15,3,15,261,8,15,1,16,5,16,264,8,16,10,16,
  	12,16,267,9,16,1,16,1,16,1,17,1,17,3,17,273,8,17,1,17,3,17,276,8,17,1,
  	18,1,18,1,18,1,18,4,18,282,8,18,11,18,12,18,283,3,18,286,8,18,1,19,3,
  	19,289,8,19,1,19,1,19,1,19,3,19,294,8,19,1,20,1,20,1,20,1,20,3,20,300,
  	8,20,1,21,5,21,303,8,21,10,21,12,21,306,9,21,1,21,1,21,1,22,1,22,3,22,
  	312,8,22,1,23,1,23,3,23,316,8,23,1,23,1,23,1,24,1,24,1,24,4,24,323,8,
  	24,11,24,12,24,324,1,24,1,24,1,24,5,24,330,8,24,10,24,12,24,333,9,24,
  	1,24,1,24,3,24,337,8,24,1,25,1,25,1,25,1,25,1,25,3,25,344,8,25,1,26,1,
  	26,1,26,1,26,1,26,3,26,351,8,26,1,26,1,26,1,26,4,26,356,8,26,11,26,12,
  	26,357,1,26,1,26,1,26,3,26,363,8,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,
  	1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,
  	1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,
  	1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,5,26,412,
  	8,26,10,26,12,26,415,9,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,
  	1,27,1,27,1,27,1,27,1,27,1,27,1,27,3,27,433,8,27,1,27,1,27,1,27,3,27,
  	438,8,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,3,27,448,8,27,1,28,1,
  	28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,
  	28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,3,28,476,8,28,1,
  	29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,3,29,490,8,
  	29,1,30,4,30,493,8,30,11,30,12,30,494,1,30,0,2,28,52,31,0,2,4,6,8,10,
  	12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,
  	58,60,0,18,1,0,25,26,2,0,69,69,72,72,1,0,38,39,2,0,48,48,50,50,1,0,75,
  	76,4,0,59,59,61,61,63,63,65,65,2,0,67,67,70,70,2,0,97,97,99,99,1,0,73,
  	74,1,0,77,80,1,0,87,88,2,0,93,93,95,95,1,0,8,9,1,0,6,7,1,0,12,13,1,0,
  	27,31,19,0,51,51,54,54,58,58,60,60,62,62,64,64,66,66,68,68,71,71,82,82,
  	84,84,86,86,89,90,92,92,94,94,96,96,98,98,100,100,104,105,18,0,54,54,
  	58,58,60,60,62,62,64,64,66,66,68,68,71,71,82,82,84,84,86,86,89,90,92,
  	92,94,94,96,96,98,98,100,100,104,105,571,0,62,1,0,0,0,2,72,1,0,0,0,4,
  	80,1,0,0,0,6,82,1,0,0,0,8,90,1,0,0,0,10,100,1,0,0,0,12,116,1,0,0,0,14,
  	118,1,0,0,0,16,124,1,0,0,0,18,129,1,0,0,0,20,136,1,0,0,0,22,171,1,0,0,
  	0,24,173,1,0,0,0,26,185,1,0,0,0,28,229,1,0,0,0,30,260,1,0,0,0,32,265,
  	1,0,0,0,34,275,1,0,0,0,36,285,1,0,0,0,38,293,1,0,0,0,40,299,1,0,0,0,42,
  	304,1,0,0,0,44,309,1,0,0,0,46,315,1,0,0,0,48,336,1,0,0,0,50,343,1,0,0,
  	0,52,362,1,0,0,0,54,447,1,0,0,0,56,475,1,0,0,0,58,489,1,0,0,0,60,492,
  	1,0,0,0,62,63,3,2,1,0,63,1,1,0,0,0,64,73,5,0,0,1,65,66,3,12,6,0,66,67,
  	5,0,0,1,67,73,1,0,0,0,68,69,3,12,6,0,69,70,5,44,0,0,70,73,1,0,0,0,71,
  	73,5,44,0,0,72,64,1,0,0,0,72,65,1,0,0,0,72,68,1,0,0,0,72,71,1,0,0,0,73,
  	3,1,0,0,0,74,77,5,43,0,0,75,76,5,54,0,0,76,78,3,60,30,0,77,75,1,0,0,0,
  	77,78,1,0,0,0,78,81,1,0,0,0,79,81,5,110,0,0,80,74,1,0,0,0,80,79,1,0,0,
  	0,81,5,1,0,0,0,82,87,3,4,2,0,83,84,5,1,0,0,84,86,3,4,2,0,85,83,1,0,0,
  	0,86,89,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,7,1,0,0,0,89,87,1,0,0,
  	0,90,95,5,109,0,0,91,92,5,43,0,0,92,94,5,1,0,0,93,91,1,0,0,0,94,97,1,
  	0,0,0,95,93,1,0,0,0,95,96,1,0,0,0,96,98,1,0,0,0,97,95,1,0,0,0,98,99,5,
  	43,0,0,99,9,1,0,0,0,100,102,3,6,3,0,101,103,3,8,4,0,102,101,1,0,0,0,102,
  	103,1,0,0,0,103,104,1,0,0,0,104,105,5,108,0,0,105,106,3,60,30,0,106,11,
  	1,0,0,0,107,117,3,60,30,0,108,110,3,14,7,0,109,108,1,0,0,0,110,111,1,
  	0,0,0,111,109,1,0,0,0,111,112,1,0,0,0,112,114,1,0,0,0,113,115,3,60,30,
  	0,114,113,1,0,0,0,114,115,1,0,0,0,115,117,1,0,0,0,116,107,1,0,0,0,116,
  	109,1,0,0,0,117,13,1,0,0,0,118,120,3,60,30,0,119,121,5,53,0,0,120,119,
  	1,0,0,0,121,122,1,0,0,0,122,120,1,0,0,0,122,123,1,0,0,0,123,15,1,0,0,
  	0,124,125,5,20,0,0,125,126,3,12,6,0,126,127,7,0,0,0,127,128,3,60,30,0,
  	128,17,1,0,0,0,129,131,5,43,0,0,130,132,5,43,0,0,131,130,1,0,0,0,131,
  	132,1,0,0,0,132,133,1,0,0,0,133,134,5,22,0,0,134,135,3,12,6,0,135,19,
  	1,0,0,0,136,141,3,18,9,0,137,138,5,1,0,0,138,140,3,18,9,0,139,137,1,0,
  	0,0,140,143,1,0,0,0,141,139,1,0,0,0,141,142,1,0,0,0,142,21,1,0,0,0,143,
  	141,1,0,0,0,144,145,5,21,0,0,145,146,3,20,10,0,146,147,7,0,0,0,147,148,
  	3,60,30,0,148,172,1,0,0,0,149,150,5,21,0,0,150,151,3,20,10,0,151,152,
  	5,23,0,0,152,155,3,12,6,0,153,154,5,24,0,0,154,156,3,24,12,0,155,153,
  	1,0,0,0,155,156,1,0,0,0,156,157,1,0,0,0,157,158,7,0,0,0,158,159,3,60,
  	30,0,159,172,1,0,0,0,160,161,5,21,0,0,161,162,3,20,10,0,162,163,5,24,
  	0,0,163,166,3,24,12,0,164,165,5,23,0,0,165,167,3,12,6,0,166,164,1,0,0,
  	0,166,167,1,0,0,0,167,168,1,0,0,0,168,169,7,0,0,0,169,170,3,60,30,0,170,
  	172,1,0,0,0,171,144,1,0,0,0,171,149,1,0,0,0,171,160,1,0,0,0,172,23,1,
  	0,0,0,173,174,5,44,0,0,174,182,3,12,6,0,175,177,5,1,0,0,176,175,1,0,0,
  	0,176,177,1,0,0,0,177,178,1,0,0,0,178,179,5,44,0,0,179,181,3,12,6,0,180,
  	176,1,0,0,0,181,184,1,0,0,0,182,180,1,0,0,0,182,183,1,0,0,0,183,25,1,
  	0,0,0,184,182,1,0,0,0,185,190,3,12,6,0,186,187,5,1,0,0,187,189,3,12,6,
  	0,188,186,1,0,0,0,189,192,1,0,0,0,190,188,1,0,0,0,190,191,1,0,0,0,191,
  	27,1,0,0,0,192,190,1,0,0,0,193,196,6,14,-1,0,194,197,3,54,27,0,195,197,
  	3,38,19,0,196,194,1,0,0,0,196,195,1,0,0,0,197,198,1,0,0,0,198,199,5,107,
  	0,0,199,200,5,47,0,0,200,230,1,0,0,0,201,204,3,54,27,0,202,204,3,38,19,
  	0,203,201,1,0,0,0,203,202,1,0,0,0,204,205,1,0,0,0,205,206,5,107,0,0,206,
  	207,3,26,13,0,207,208,5,47,0,0,208,230,1,0,0,0,209,212,3,54,27,0,210,
  	212,3,38,19,0,211,209,1,0,0,0,211,210,1,0,0,0,212,213,1,0,0,0,213,214,
  	5,107,0,0,214,215,3,24,12,0,215,216,5,47,0,0,216,230,1,0,0,0,217,220,
  	3,54,27,0,218,220,3,38,19,0,219,217,1,0,0,0,219,218,1,0,0,0,220,221,1,
  	0,0,0,221,222,5,107,0,0,222,224,3,26,13,0,223,225,5,1,0,0,224,223,1,0,
  	0,0,224,225,1,0,0,0,225,226,1,0,0,0,226,227,3,24,12,0,227,228,5,47,0,
  	0,228,230,1,0,0,0,229,193,1,0,0,0,229,203,1,0,0,0,229,211,1,0,0,0,229,
  	219,1,0,0,0,230,255,1,0,0,0,231,232,10,4,0,0,232,233,5,107,0,0,233,254,
  	5,47,0,0,234,235,10,3,0,0,235,236,5,107,0,0,236,237,3,26,13,0,237,238,
  	5,47,0,0,238,254,1,0,0,0,239,240,10,2,0,0,240,241,5,107,0,0,241,242,3,
  	24,12,0,242,243,5,47,0,0,243,254,1,0,0,0,244,245,10,1,0,0,245,246,5,107,
  	0,0,246,248,3,26,13,0,247,249,5,1,0,0,248,247,1,0,0,0,248,249,1,0,0,0,
  	249,250,1,0,0,0,250,251,3,24,12,0,251,252,5,47,0,0,252,254,1,0,0,0,253,
  	231,1,0,0,0,253,234,1,0,0,0,253,239,1,0,0,0,253,244,1,0,0,0,254,257,1,
  	0,0,0,255,253,1,0,0,0,255,256,1,0,0,0,256,29,1,0,0,0,257,255,1,0,0,0,
  	258,261,3,54,27,0,259,261,3,38,19,0,260,258,1,0,0,0,260,259,1,0,0,0,261,
  	31,1,0,0,0,262,264,7,1,0,0,263,262,1,0,0,0,264,267,1,0,0,0,265,263,1,
  	0,0,0,265,266,1,0,0,0,266,268,1,0,0,0,267,265,1,0,0,0,268,269,3,30,15,
  	0,269,33,1,0,0,0,270,273,3,54,27,0,271,273,3,28,14,0,272,270,1,0,0,0,
  	272,271,1,0,0,0,273,276,1,0,0,0,274,276,3,44,22,0,275,272,1,0,0,0,275,
  	274,1,0,0,0,276,35,1,0,0,0,277,286,3,28,14,0,278,281,3,34,17,0,279,280,
  	5,50,0,0,280,282,3,28,14,0,281,279,1,0,0,0,282,283,1,0,0,0,283,281,1,
  	0,0,0,283,284,1,0,0,0,284,286,1,0,0,0,285,277,1,0,0,0,285,278,1,0,0,0,
  	286,37,1,0,0,0,287,289,7,2,0,0,288,287,1,0,0,0,288,289,1,0,0,0,289,290,
  	1,0,0,0,290,294,5,43,0,0,291,294,5,42,0,0,292,294,5,41,0,0,293,288,1,
  	0,0,0,293,291,1,0,0,0,293,292,1,0,0,0,294,39,1,0,0,0,295,300,3,58,29,
  	0,296,300,3,16,8,0,297,300,3,22,11,0,298,300,3,10,5,0,299,295,1,0,0,0,
  	299,296,1,0,0,0,299,297,1,0,0,0,299,298,1,0,0,0,300,41,1,0,0,0,301,303,
  	7,1,0,0,302,301,1,0,0,0,303,306,1,0,0,0,304,302,1,0,0,0,304,305,1,0,0,
  	0,305,307,1,0,0,0,306,304,1,0,0,0,307,308,3,40,20,0,308,43,1,0,0,0,309,
  	311,3,38,19,0,310,312,3,48,24,0,311,310,1,0,0,0,311,312,1,0,0,0,312,45,
  	1,0,0,0,313,316,3,54,27,0,314,316,3,36,18,0,315,313,1,0,0,0,315,314,1,
  	0,0,0,316,317,1,0,0,0,317,318,3,48,24,0,318,47,1,0,0,0,319,322,6,24,-1,
  	0,320,321,7,3,0,0,321,323,3,32,16,0,322,320,1,0,0,0,323,324,1,0,0,0,324,
  	322,1,0,0,0,324,325,1,0,0,0,325,337,1,0,0,0,326,331,6,24,-1,0,327,328,
  	7,3,0,0,328,330,3,32,16,0,329,327,1,0,0,0,330,333,1,0,0,0,331,329,1,0,
  	0,0,331,332,1,0,0,0,332,334,1,0,0,0,333,331,1,0,0,0,334,335,7,3,0,0,335,
  	337,3,42,21,0,336,319,1,0,0,0,336,326,1,0,0,0,337,49,1,0,0,0,338,344,
  	3,58,29,0,339,344,3,56,28,0,340,344,3,16,8,0,341,344,3,22,11,0,342,344,
  	3,10,5,0,343,338,1,0,0,0,343,339,1,0,0,0,343,340,1,0,0,0,343,341,1,0,
  	0,0,343,342,1,0,0,0,344,51,1,0,0,0,345,350,6,26,-1,0,346,351,3,54,27,
  	0,347,351,3,38,19,0,348,351,3,36,18,0,349,351,3,50,25,0,350,346,1,0,0,
  	0,350,347,1,0,0,0,350,348,1,0,0,0,350,349,1,0,0,0,351,363,1,0,0,0,352,
  	363,3,44,22,0,353,363,3,46,23,0,354,356,7,1,0,0,355,354,1,0,0,0,356,357,
  	1,0,0,0,357,355,1,0,0,0,357,358,1,0,0,0,358,359,1,0,0,0,359,363,3,52,
  	26,16,360,361,7,4,0,0,361,363,3,52,26,1,362,345,1,0,0,0,362,352,1,0,0,
  	0,362,353,1,0,0,0,362,355,1,0,0,0,362,360,1,0,0,0,363,413,1,0,0,0,364,
  	365,10,18,0,0,365,366,5,49,0,0,366,412,3,52,26,19,367,368,10,17,0,0,368,
  	369,5,57,0,0,369,412,3,52,26,17,370,371,10,15,0,0,371,372,7,5,0,0,372,
  	412,3,52,26,16,373,374,10,13,0,0,374,375,7,6,0,0,375,412,3,52,26,14,376,
  	377,10,12,0,0,377,378,7,7,0,0,378,412,3,52,26,13,379,380,10,11,0,0,380,
  	381,5,2,0,0,381,412,3,52,26,12,382,383,10,10,0,0,383,384,5,101,0,0,384,
  	412,3,52,26,11,385,386,10,9,0,0,386,387,7,8,0,0,387,412,3,52,26,10,388,
  	389,10,8,0,0,389,390,7,9,0,0,390,412,3,52,26,9,391,392,10,7,0,0,392,393,
  	5,81,0,0,393,412,3,52,26,8,394,395,10,6,0,0,395,396,5,83,0,0,396,412,
  	3,52,26,7,397,398,10,5,0,0,398,399,5,85,0,0,399,412,3,52,26,6,400,401,
  	10,4,0,0,401,402,7,10,0,0,402,412,3,52,26,5,403,404,10,3,0,0,404,405,
  	5,91,0,0,405,412,3,52,26,4,406,407,10,2,0,0,407,408,7,11,0,0,408,412,
  	3,52,26,3,409,410,10,14,0,0,410,412,7,12,0,0,411,364,1,0,0,0,411,367,
  	1,0,0,0,411,370,1,0,0,0,411,373,1,0,0,0,411,376,1,0,0,0,411,379,1,0,0,
  	0,411,382,1,0,0,0,411,385,1,0,0,0,411,388,1,0,0,0,411,391,1,0,0,0,411,
  	394,1,0,0,0,411,397,1,0,0,0,411,400,1,0,0,0,411,403,1,0,0,0,411,406,1,
  	0,0,0,411,409,1,0,0,0,412,415,1,0,0,0,413,411,1,0,0,0,413,414,1,0,0,0,
  	414,53,1,0,0,0,415,413,1,0,0,0,416,448,5,3,0,0,417,448,5,4,0,0,418,448,
  	5,5,0,0,419,448,7,13,0,0,420,448,5,10,0,0,421,448,5,11,0,0,422,448,7,
  	14,0,0,423,448,5,14,0,0,424,448,5,35,0,0,425,448,5,36,0,0,426,448,7,15,
  	0,0,427,448,5,33,0,0,428,448,5,37,0,0,429,433,5,15,0,0,430,431,5,106,
  	0,0,431,433,5,47,0,0,432,429,1,0,0,0,432,430,1,0,0,0,433,448,1,0,0,0,
  	434,438,5,16,0,0,435,436,5,45,0,0,436,438,5,46,0,0,437,434,1,0,0,0,437,
  	435,1,0,0,0,438,448,1,0,0,0,439,440,5,106,0,0,440,441,3,12,6,0,441,442,
  	5,47,0,0,442,448,1,0,0,0,443,444,5,45,0,0,444,445,3,12,6,0,445,446,5,
  	46,0,0,446,448,1,0,0,0,447,416,1,0,0,0,447,417,1,0,0,0,447,418,1,0,0,
  	0,447,419,1,0,0,0,447,420,1,0,0,0,447,421,1,0,0,0,447,422,1,0,0,0,447,
  	423,1,0,0,0,447,424,1,0,0,0,447,425,1,0,0,0,447,426,1,0,0,0,447,427,1,
  	0,0,0,447,428,1,0,0,0,447,432,1,0,0,0,447,437,1,0,0,0,447,439,1,0,0,0,
  	447,443,1,0,0,0,448,55,1,0,0,0,449,450,5,40,0,0,450,451,5,43,0,0,451,
  	452,5,54,0,0,452,476,3,60,30,0,453,454,3,44,22,0,454,455,7,16,0,0,455,
  	456,3,60,30,0,456,476,1,0,0,0,457,458,3,46,23,0,458,459,7,17,0,0,459,
  	460,3,60,30,0,460,476,1,0,0,0,461,462,3,44,22,0,462,463,5,103,0,0,463,
  	464,3,36,18,0,464,476,1,0,0,0,465,466,3,46,23,0,466,467,5,103,0,0,467,
  	468,3,36,18,0,468,476,1,0,0,0,469,470,5,32,0,0,470,471,5,54,0,0,471,476,
  	3,60,30,0,472,473,5,34,0,0,473,474,5,54,0,0,474,476,3,60,30,0,475,449,
  	1,0,0,0,475,453,1,0,0,0,475,457,1,0,0,0,475,461,1,0,0,0,475,465,1,0,0,
  	0,475,469,1,0,0,0,475,472,1,0,0,0,476,57,1,0,0,0,477,478,5,17,0,0,478,
  	479,3,12,6,0,479,480,5,18,0,0,480,481,3,60,30,0,481,490,1,0,0,0,482,483,
  	5,17,0,0,483,484,3,12,6,0,484,485,5,18,0,0,485,486,3,12,6,0,486,487,5,
  	19,0,0,487,488,3,60,30,0,488,490,1,0,0,0,489,477,1,0,0,0,489,482,1,0,
  	0,0,490,59,1,0,0,0,491,493,3,52,26,0,492,491,1,0,0,0,493,494,1,0,0,0,
  	494,492,1,0,0,0,494,495,1,0,0,0,495,61,1,0,0,0,54,72,77,80,87,95,102,
  	111,114,116,122,131,141,155,166,171,176,182,190,196,203,211,219,224,229,
  	248,253,255,260,265,272,275,283,285,288,293,299,304,311,315,324,331,336,
  	343,350,357,362,411,413,432,437,447,475,489,494
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
    setState(62);
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
    setState(72);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::ProgramEOFContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(64);
      match(bellParser::EOF);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::ProgramSequenceContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(65);
      sequence();
      setState(66);
      match(bellParser::EOF);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<bellParser::ProgramSequenceNamedparamContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(68);
      sequence();
      setState(69);
      match(bellParser::NAMEDPARAM);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<bellParser::ProgramNamedparamContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(71);
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
    setState(80);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::LOCALVAR: {
        _localctx = _tracker.createInstance<bellParser::FunargVarContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(74);
        match(bellParser::LOCALVAR);
        setState(77);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == bellParser::ASSIGN) {
          setState(75);
          match(bellParser::ASSIGN);
          setState(76);
          list();
        }
        break;
      }

      case bellParser::ELLIPSIS: {
        _localctx = _tracker.createInstance<bellParser::FunargEllipsisContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(79);
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
    setState(82);
    funarg();
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::T__0) {
      setState(83);
      match(bellParser::T__0);
      setState(84);
      funarg();
      setState(89);
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
    setState(90);
    match(bellParser::LIFT);
    setState(95);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(91);
        match(bellParser::LOCALVAR);
        setState(92);
        match(bellParser::T__0); 
      }
      setState(97);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(98);
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
    setState(100);
    funargList();
    setState(102);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == bellParser::LIFT) {
      setState(101);
      liftedargList();
    }
    setState(104);
    match(bellParser::FUNDEF);
    setState(105);
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
    setState(116);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(107);
      list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(109); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(108);
                nullified();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(111); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(114);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << bellParser::UINT)
        | (1ULL << bellParser::UFLOAT)
        | (1ULL << bellParser::ETPITCHBASE)
        | (1ULL << bellParser::JIPITCHBASE)
        | (1ULL << bellParser::JIPITCHCOMMAS)
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
        | (1ULL << bellParser::PUSH))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 69)) & ((1ULL << (bellParser::UPLUS - 69))
        | (1ULL << (bellParser::UMINUS - 69))
        | (1ULL << (bellParser::LOGNOT - 69))
        | (1ULL << (bellParser::BITNOT - 69))
        | (1ULL << (bellParser::OPEN - 69))
        | (1ULL << (bellParser::ELLIPSIS - 69)))) != 0)) {
        setState(113);
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
    setState(118);
    list();
    setState(120); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(119);
      match(bellParser::NULLIFY);
      setState(122); 
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
    setState(124);
    match(bellParser::WHILE);
    setState(125);
    sequence();
    setState(126);
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
    setState(127);
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
    setState(129);
    match(bellParser::LOCALVAR);

    setState(131);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == bellParser::LOCALVAR) {
      setState(130);
      match(bellParser::LOCALVAR);
    }
    setState(133);
    match(bellParser::IN);
    setState(134);
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
    setState(136);
    forarg();
    setState(141);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::T__0) {
      setState(137);
      match(bellParser::T__0);
      setState(138);
      forarg();
      setState(143);
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
    setState(171);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(144);
      match(bellParser::FOR);
      setState(145);
      forargList();
      setState(146);
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
      setState(147);
      list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(149);
      match(bellParser::FOR);
      setState(150);
      forargList();
      setState(151);
      match(bellParser::AS);
      setState(152);
      sequence();
      setState(155);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::WITH) {
        setState(153);
        match(bellParser::WITH);
        setState(154);
        argsByNameList();
      }
      setState(157);
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
      setState(158);
      list();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(160);
      match(bellParser::FOR);
      setState(161);
      forargList();
      setState(162);
      match(bellParser::WITH);
      setState(163);
      argsByNameList();
      setState(166);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::AS) {
        setState(164);
        match(bellParser::AS);
        setState(165);
        sequence();
      }
      setState(168);
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
      setState(169);
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
    setState(173);
    match(bellParser::NAMEDPARAM);
    setState(174);
    sequence();
    setState(182);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::T__0

    || _la == bellParser::NAMEDPARAM) {
      setState(176);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::T__0) {
        setState(175);
        match(bellParser::T__0);
      }
      setState(178);
      match(bellParser::NAMEDPARAM);
      setState(179);
      sequence();
      setState(184);
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
    setState(185);
    sequence();
    setState(190);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(186);
        match(bellParser::T__0);
        setState(187);
        sequence(); 
      }
      setState(192);
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
    setState(229);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(196);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case bellParser::UINT:
        case bellParser::UFLOAT:
        case bellParser::ETPITCHBASE:
        case bellParser::JIPITCHBASE:
        case bellParser::JIPITCHCOMMAS:
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
        case bellParser::OPEN: {
          setState(194);
          item();
          break;
        }

        case bellParser::KEEP:
        case bellParser::UNKEEP:
        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR: {
          setState(195);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(198);
      match(bellParser::PARAMS);
      setState(199);
      match(bellParser::CLOSED);
      break;
    }

    case 2: {
      setState(203);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case bellParser::UINT:
        case bellParser::UFLOAT:
        case bellParser::ETPITCHBASE:
        case bellParser::JIPITCHBASE:
        case bellParser::JIPITCHCOMMAS:
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
        case bellParser::OPEN: {
          setState(201);
          item();
          break;
        }

        case bellParser::KEEP:
        case bellParser::UNKEEP:
        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR: {
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
      argsByPositionList();
      setState(207);
      match(bellParser::CLOSED);
      break;
    }

    case 3: {
      setState(211);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case bellParser::UINT:
        case bellParser::UFLOAT:
        case bellParser::ETPITCHBASE:
        case bellParser::JIPITCHBASE:
        case bellParser::JIPITCHCOMMAS:
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
        case bellParser::OPEN: {
          setState(209);
          item();
          break;
        }

        case bellParser::KEEP:
        case bellParser::UNKEEP:
        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR: {
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
      argsByNameList();
      setState(215);
      match(bellParser::CLOSED);
      break;
    }

    case 4: {
      setState(219);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case bellParser::UINT:
        case bellParser::UFLOAT:
        case bellParser::ETPITCHBASE:
        case bellParser::JIPITCHBASE:
        case bellParser::JIPITCHCOMMAS:
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
        case bellParser::OPEN: {
          setState(217);
          item();
          break;
        }

        case bellParser::KEEP:
        case bellParser::UNKEEP:
        case bellParser::GLOBALVAR:
        case bellParser::PATCHERVAR:
        case bellParser::LOCALVAR: {
          setState(218);
          var();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(221);
      match(bellParser::PARAMS);
      setState(222);
      argsByPositionList();
      setState(224);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bellParser::T__0) {
        setState(223);
        match(bellParser::T__0);
      }
      setState(226);
      argsByNameList();
      setState(227);
      match(bellParser::CLOSED);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(255);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(253);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(231);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(232);
          match(bellParser::PARAMS);
          setState(233);
          match(bellParser::CLOSED);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(234);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(235);
          match(bellParser::PARAMS);
          setState(236);
          argsByPositionList();
          setState(237);
          match(bellParser::CLOSED);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(239);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(240);
          match(bellParser::PARAMS);
          setState(241);
          argsByNameList();
          setState(242);
          match(bellParser::CLOSED);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<SimpleFuncallContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleSimpleFuncall);
          setState(244);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(245);
          match(bellParser::PARAMS);
          setState(246);
          argsByPositionList();
          setState(248);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == bellParser::T__0) {
            setState(247);
            match(bellParser::T__0);
          }
          setState(250);
          argsByNameList();
          setState(251);
          match(bellParser::CLOSED);
          break;
        }

        default:
          break;
        } 
      }
      setState(257);
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

//----------------- LvalueSpecsUItemContext ------------------------------------------------------------------

bellParser::LvalueSpecsUItemContext::LvalueSpecsUItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bellParser::ItemContext* bellParser::LvalueSpecsUItemContext::item() {
  return getRuleContext<bellParser::ItemContext>(0);
}

bellParser::VarContext* bellParser::LvalueSpecsUItemContext::var() {
  return getRuleContext<bellParser::VarContext>(0);
}


size_t bellParser::LvalueSpecsUItemContext::getRuleIndex() const {
  return bellParser::RuleLvalueSpecsUItem;
}


std::any bellParser::LvalueSpecsUItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLvalueSpecsUItem(this);
  else
    return visitor->visitChildren(this);
}

bellParser::LvalueSpecsUItemContext* bellParser::lvalueSpecsUItem() {
  LvalueSpecsUItemContext *_localctx = _tracker.createInstance<LvalueSpecsUItemContext>(_ctx, getState());
  enterRule(_localctx, 30, bellParser::RuleLvalueSpecsUItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(260);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::UINT:
      case bellParser::UFLOAT:
      case bellParser::ETPITCHBASE:
      case bellParser::JIPITCHBASE:
      case bellParser::JIPITCHCOMMAS:
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
      case bellParser::OPEN: {
        enterOuterAlt(_localctx, 1);
        setState(258);
        item();
        break;
      }

      case bellParser::KEEP:
      case bellParser::UNKEEP:
      case bellParser::GLOBALVAR:
      case bellParser::PATCHERVAR:
      case bellParser::LOCALVAR: {
        enterOuterAlt(_localctx, 2);
        setState(259);
        var();
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

//----------------- LvalueSpecsItemContext ------------------------------------------------------------------

bellParser::LvalueSpecsItemContext::LvalueSpecsItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bellParser::LvalueSpecsUItemContext* bellParser::LvalueSpecsItemContext::lvalueSpecsUItem() {
  return getRuleContext<bellParser::LvalueSpecsUItemContext>(0);
}

std::vector<tree::TerminalNode *> bellParser::LvalueSpecsItemContext::UPLUS() {
  return getTokens(bellParser::UPLUS);
}

tree::TerminalNode* bellParser::LvalueSpecsItemContext::UPLUS(size_t i) {
  return getToken(bellParser::UPLUS, i);
}

std::vector<tree::TerminalNode *> bellParser::LvalueSpecsItemContext::UMINUS() {
  return getTokens(bellParser::UMINUS);
}

tree::TerminalNode* bellParser::LvalueSpecsItemContext::UMINUS(size_t i) {
  return getToken(bellParser::UMINUS, i);
}


size_t bellParser::LvalueSpecsItemContext::getRuleIndex() const {
  return bellParser::RuleLvalueSpecsItem;
}


std::any bellParser::LvalueSpecsItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitLvalueSpecsItem(this);
  else
    return visitor->visitChildren(this);
}

bellParser::LvalueSpecsItemContext* bellParser::lvalueSpecsItem() {
  LvalueSpecsItemContext *_localctx = _tracker.createInstance<LvalueSpecsItemContext>(_ctx, getState());
  enterRule(_localctx, 32, bellParser::RuleLvalueSpecsItem);
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
    setState(265);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::UPLUS

    || _la == bellParser::UMINUS) {
      setState(262);
      _la = _input->LA(1);
      if (!(_la == bellParser::UPLUS

      || _la == bellParser::UMINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(267);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(268);
    lvalueSpecsUItem();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DataflowHeadContext ------------------------------------------------------------------

bellParser::DataflowHeadContext::DataflowHeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bellParser::DataflowHeadContext::getRuleIndex() const {
  return bellParser::RuleDataflowHead;
}

void bellParser::DataflowHeadContext::copyFrom(DataflowHeadContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DataflowHeadLvalueContext ------------------------------------------------------------------

bellParser::LvalueContext* bellParser::DataflowHeadLvalueContext::lvalue() {
  return getRuleContext<bellParser::LvalueContext>(0);
}

bellParser::DataflowHeadLvalueContext::DataflowHeadLvalueContext(DataflowHeadContext *ctx) { copyFrom(ctx); }


std::any bellParser::DataflowHeadLvalueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitDataflowHeadLvalue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DataflowHeadSimpleContext ------------------------------------------------------------------

bellParser::ItemContext* bellParser::DataflowHeadSimpleContext::item() {
  return getRuleContext<bellParser::ItemContext>(0);
}

bellParser::SimpleFuncallContext* bellParser::DataflowHeadSimpleContext::simpleFuncall() {
  return getRuleContext<bellParser::SimpleFuncallContext>(0);
}

bellParser::DataflowHeadSimpleContext::DataflowHeadSimpleContext(DataflowHeadContext *ctx) { copyFrom(ctx); }


std::any bellParser::DataflowHeadSimpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitDataflowHeadSimple(this);
  else
    return visitor->visitChildren(this);
}
bellParser::DataflowHeadContext* bellParser::dataflowHead() {
  DataflowHeadContext *_localctx = _tracker.createInstance<DataflowHeadContext>(_ctx, getState());
  enterRule(_localctx, 34, bellParser::RuleDataflowHead);

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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::DataflowHeadSimpleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(272);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
      case 1: {
        setState(270);
        item();
        break;
      }

      case 2: {
        setState(271);
        simpleFuncall(0);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::DataflowHeadLvalueContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(274);
      lvalue();
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


size_t bellParser::FuncallContext::getRuleIndex() const {
  return bellParser::RuleFuncall;
}

void bellParser::FuncallContext::copyFrom(FuncallContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FuncallSimpleContext ------------------------------------------------------------------

bellParser::SimpleFuncallContext* bellParser::FuncallSimpleContext::simpleFuncall() {
  return getRuleContext<bellParser::SimpleFuncallContext>(0);
}

bellParser::FuncallSimpleContext::FuncallSimpleContext(FuncallContext *ctx) { copyFrom(ctx); }


std::any bellParser::FuncallSimpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitFuncallSimple(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncallDataflowContext ------------------------------------------------------------------

bellParser::DataflowHeadContext* bellParser::FuncallDataflowContext::dataflowHead() {
  return getRuleContext<bellParser::DataflowHeadContext>(0);
}

std::vector<tree::TerminalNode *> bellParser::FuncallDataflowContext::KEY() {
  return getTokens(bellParser::KEY);
}

tree::TerminalNode* bellParser::FuncallDataflowContext::KEY(size_t i) {
  return getToken(bellParser::KEY, i);
}

std::vector<bellParser::SimpleFuncallContext *> bellParser::FuncallDataflowContext::simpleFuncall() {
  return getRuleContexts<bellParser::SimpleFuncallContext>();
}

bellParser::SimpleFuncallContext* bellParser::FuncallDataflowContext::simpleFuncall(size_t i) {
  return getRuleContext<bellParser::SimpleFuncallContext>(i);
}

bellParser::FuncallDataflowContext::FuncallDataflowContext(FuncallContext *ctx) { copyFrom(ctx); }


std::any bellParser::FuncallDataflowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitFuncallDataflow(this);
  else
    return visitor->visitChildren(this);
}
bellParser::FuncallContext* bellParser::funcall() {
  FuncallContext *_localctx = _tracker.createInstance<FuncallContext>(_ctx, getState());
  enterRule(_localctx, 36, bellParser::RuleFuncall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(285);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::FuncallSimpleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(277);
      simpleFuncall(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::FuncallDataflowContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(278);
      dataflowHead();
      setState(281); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(279);
                match(bellParser::KEY);
                setState(280);
                simpleFuncall(0);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(283); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
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
  enterRule(_localctx, 38, bellParser::RuleVar);
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
      case bellParser::KEEP:
      case bellParser::UNKEEP:
      case bellParser::LOCALVAR: {
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
  enterRule(_localctx, 40, bellParser::RuleLvalueSpecsUFinal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(299);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bellParser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(295);
        conditional();
        break;
      }

      case bellParser::WHILE: {
        enterOuterAlt(_localctx, 2);
        setState(296);
        whileloop();
        break;
      }

      case bellParser::FOR: {
        enterOuterAlt(_localctx, 3);
        setState(297);
        forloop();
        break;
      }

      case bellParser::LOCALVAR:
      case bellParser::ELLIPSIS: {
        enterOuterAlt(_localctx, 4);
        setState(298);
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
  enterRule(_localctx, 42, bellParser::RuleLvalueSpecsFinal);
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
    setState(304);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bellParser::UPLUS

    || _la == bellParser::UMINUS) {
      setState(301);
      _la = _input->LA(1);
      if (!(_la == bellParser::UPLUS

      || _la == bellParser::UMINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(306);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(307);
    lvalueSpecsUFinal();
   
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
    setState(309);
    var();
    setState(311);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      setState(310);
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

bellParser::LvalueSpecsContext* bellParser::FakeLvalueContext::lvalueSpecs() {
  return getRuleContext<bellParser::LvalueSpecsContext>(0);
}

bellParser::ItemContext* bellParser::FakeLvalueContext::item() {
  return getRuleContext<bellParser::ItemContext>(0);
}

bellParser::FuncallContext* bellParser::FakeLvalueContext::funcall() {
  return getRuleContext<bellParser::FuncallContext>(0);
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
    setState(315);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(313);
      item();
      break;
    }

    case 2: {
      setState(314);
      funcall();
      break;
    }

    default:
      break;
    }
    setState(317);
    lvalueSpecs();
   
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

std::vector<bellParser::LvalueSpecsItemContext *> bellParser::LvalueSpecsContext::lvalueSpecsItem() {
  return getRuleContexts<bellParser::LvalueSpecsItemContext>();
}

bellParser::LvalueSpecsItemContext* bellParser::LvalueSpecsContext::lvalueSpecsItem(size_t i) {
  return getRuleContext<bellParser::LvalueSpecsItemContext>(i);
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
  enterRule(_localctx, 48, bellParser::RuleLvalueSpecs);
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
    setState(336);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      ending = false;
      setState(322); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
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
                lvalueSpecsItem();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(324); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      ending = true;
      setState(331);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(327);
          _la = _input->LA(1);
          if (!(_la == bellParser::NTH

          || _la == bellParser::KEY)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(328);
          lvalueSpecsItem(); 
        }
        setState(333);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
      }

      setState(334);
      _la = _input->LA(1);
      if (!(_la == bellParser::NTH

      || _la == bellParser::KEY)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(335);
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
  enterRule(_localctx, 50, bellParser::RuleListEnd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(343);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(338);
      conditional();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(339);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(340);
      whileloop();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(341);
      forloop();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(342);
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
//----------------- ExprTRContext ------------------------------------------------------------------

bellParser::ExprContext* bellParser::ExprTRContext::expr() {
  return getRuleContext<bellParser::ExprContext>(0);
}

tree::TerminalNode* bellParser::ExprTRContext::T() {
  return getToken(bellParser::T, 0);
}

tree::TerminalNode* bellParser::ExprTRContext::R() {
  return getToken(bellParser::R, 0);
}

bellParser::ExprTRContext::ExprTRContext(ExprContext *ctx) { copyFrom(ctx); }


std::any bellParser::ExprTRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitExprTR(this);
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
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, bellParser::RuleExpr, precedence);

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
    setState(362);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprSimpleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(350);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
      case 1: {
        setState(346);
        item();
        break;
      }

      case 2: {
        setState(347);
        var();
        break;
      }

      case 3: {
        setState(348);
        funcall();
        break;
      }

      case 4: {
        setState(349);
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
      setState(352);
      lvalue();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ExprFakeLvalueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(353);
      fakeLvalue();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprUPlusMinusContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(355); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(354);
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
        setState(357); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(359);
      expr(16);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ExprNotContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(360);
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
      setState(361);
      expr(1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(413);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(411);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(364);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(365);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::PICK);
          setState(366);
          expr(19);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(367);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(368);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::POW);
          setState(369);
          expr(17);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(370);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(371);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 59) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 59)) & ((1ULL << (bellParser::TIMES - 59))
            | (1ULL << (bellParser::DIVDIV - 59))
            | (1ULL << (bellParser::DIV - 59))
            | (1ULL << (bellParser::REM - 59)))) != 0))) {
            antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(372);
          expr(16);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(373);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(374);
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
          setState(375);
          expr(14);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(376);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(377);
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
          setState(378);
          expr(13);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(379);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(380);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::RANGE);
          setState(381);
          expr(12);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(382);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(383);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::REPEAT);
          setState(384);
          expr(11);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(385);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(386);
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
          setState(387);
          expr(10);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(388);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(389);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 77) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 77)) & ((1ULL << (bellParser::LT - 77))
            | (1ULL << (bellParser::GT - 77))
            | (1ULL << (bellParser::LEQ - 77))
            | (1ULL << (bellParser::GEQ - 77)))) != 0))) {
            antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(390);
          expr(9);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(391);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(392);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::BITAND);
          setState(393);
          expr(8);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(394);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(395);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::BITXOR);
          setState(396);
          expr(7);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(397);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(398);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::BITOR);
          setState(399);
          expr(6);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(400);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(401);
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
          setState(402);
          expr(5);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(403);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(404);
          antlrcpp::downCast<ExprBinaryContext *>(_localctx)->op = match(bellParser::LOGXOR);
          setState(405);
          expr(4);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<ExprBinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(406);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(407);
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
          setState(408);
          expr(3);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<ExprTRContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(409);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(410);
          antlrcpp::downCast<ExprTRContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == bellParser::T

          || _la == bellParser::R)) {
            antlrcpp::downCast<ExprTRContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        default:
          break;
        } 
      }
      setState(415);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
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
//----------------- ItemJIPitchContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemJIPitchContext::JIPITCHBASE() {
  return getToken(bellParser::JIPITCHBASE, 0);
}

tree::TerminalNode* bellParser::ItemJIPitchContext::JIPITCHCOMMAS() {
  return getToken(bellParser::JIPITCHCOMMAS, 0);
}

bellParser::ItemJIPitchContext::ItemJIPitchContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemJIPitchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemJIPitch(this);
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
//----------------- ItemETPitchContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemETPitchContext::ETPITCHBASE() {
  return getToken(bellParser::ETPITCHBASE, 0);
}

bellParser::ItemETPitchContext::ItemETPitchContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemETPitchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemETPitch(this);
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
//----------------- ItemPiContext ------------------------------------------------------------------

tree::TerminalNode* bellParser::ItemPiContext::K_PI() {
  return getToken(bellParser::K_PI, 0);
}

bellParser::ItemPiContext::ItemPiContext(ItemContext *ctx) { copyFrom(ctx); }


std::any bellParser::ItemPiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bellVisitor*>(visitor))
    return parserVisitor->visitItemPi(this);
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

tree::TerminalNode* bellParser::ItemNullContext::OPEN() {
  return getToken(bellParser::OPEN, 0);
}

tree::TerminalNode* bellParser::ItemNullContext::CLOSED() {
  return getToken(bellParser::CLOSED, 0);
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

tree::TerminalNode* bellParser::ItemNilContext::PUSH() {
  return getToken(bellParser::PUSH, 0);
}

tree::TerminalNode* bellParser::ItemNilContext::POP() {
  return getToken(bellParser::POP, 0);
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
  enterRule(_localctx, 54, bellParser::RuleItem);
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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<bellParser::ItemUintContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(416);
      match(bellParser::UINT);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<bellParser::ItemUfloatContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(417);
      match(bellParser::UFLOAT);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<bellParser::ItemETPitchContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(418);
      match(bellParser::ETPITCHBASE);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<bellParser::ItemJIPitchContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(419);
      _la = _input->LA(1);
      if (!(_la == bellParser::JIPITCHBASE

      || _la == bellParser::JIPITCHCOMMAS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<bellParser::ItemPiContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(420);
      match(bellParser::K_PI);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<bellParser::ItemBtSymbolContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(421);
      match(bellParser::BTSYMBOL);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<bellParser::ItemQSymbolContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(422);
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

    case 8: {
      _localctx = _tracker.createInstance<bellParser::ItemEmptySymbolContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(423);
      match(bellParser::EMPTYSYMBOL);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<bellParser::ItemBIFContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(424);
      match(bellParser::BIF);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<bellParser::ItemOFContext>(_localctx);
      enterOuterAlt(_localctx, 10);
      setState(425);
      match(bellParser::OF);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<bellParser::ItemInletContext>(_localctx);
      enterOuterAlt(_localctx, 11);
      setState(426);
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

    case 12: {
      _localctx = _tracker.createInstance<bellParser::ItemDirInletContext>(_localctx);
      enterOuterAlt(_localctx, 12);
      setState(427);
      match(bellParser::DIRINLET);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<bellParser::ItemArgcountContext>(_localctx);
      enterOuterAlt(_localctx, 13);
      setState(428);
      match(bellParser::ARGCOUNT);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<bellParser::ItemNullContext>(_localctx);
      enterOuterAlt(_localctx, 14);
      setState(432);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case bellParser::BACHNULL: {
          setState(429);
          match(bellParser::BACHNULL);
          break;
        }

        case bellParser::OPEN: {
          setState(430);
          match(bellParser::OPEN);
          setState(431);
          match(bellParser::CLOSED);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<bellParser::ItemNilContext>(_localctx);
      enterOuterAlt(_localctx, 15);
      setState(437);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case bellParser::BACHNIL: {
          setState(434);
          match(bellParser::BACHNIL);
          break;
        }

        case bellParser::PUSH: {
          setState(435);
          match(bellParser::PUSH);
          setState(436);
          match(bellParser::POP);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<bellParser::ItemSequenceContext>(_localctx);
      enterOuterAlt(_localctx, 16);
      setState(439);
      match(bellParser::OPEN);
      setState(440);
      sequence();
      setState(441);
      match(bellParser::CLOSED);
      break;
    }

    case 17: {
      _localctx = _tracker.createInstance<bellParser::ItemSublistContext>(_localctx);
      enterOuterAlt(_localctx, 17);
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
  enterRule(_localctx, 56, bellParser::RuleAssignment);
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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
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
      if (!(((((_la - 51) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 51)) & ((1ULL << (bellParser::ANTH - 51))
        | (1ULL << (bellParser::ASSIGN - 51))
        | (1ULL << (bellParser::APOW - 51))
        | (1ULL << (bellParser::ATIMES - 51))
        | (1ULL << (bellParser::ADIVDIV - 51))
        | (1ULL << (bellParser::ADIV - 51))
        | (1ULL << (bellParser::AREM - 51))
        | (1ULL << (bellParser::APLUS - 51))
        | (1ULL << (bellParser::AMINUS - 51))
        | (1ULL << (bellParser::ABITAND - 51))
        | (1ULL << (bellParser::ABITXOR - 51))
        | (1ULL << (bellParser::ABITOR - 51))
        | (1ULL << (bellParser::ALOGAND - 51))
        | (1ULL << (bellParser::ALOGANDEXT - 51))
        | (1ULL << (bellParser::ALOGXOR - 51))
        | (1ULL << (bellParser::ALOGOR - 51))
        | (1ULL << (bellParser::ALOGOREXT - 51))
        | (1ULL << (bellParser::ALSHIFT - 51))
        | (1ULL << (bellParser::ARSHIFT - 51))
        | (1ULL << (bellParser::ACONCAT - 51))
        | (1ULL << (bellParser::ARCONCAT - 51)))) != 0))) {
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
      if (!(((((_la - 54) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 54)) & ((1ULL << (bellParser::ASSIGN - 54))
        | (1ULL << (bellParser::APOW - 54))
        | (1ULL << (bellParser::ATIMES - 54))
        | (1ULL << (bellParser::ADIVDIV - 54))
        | (1ULL << (bellParser::ADIV - 54))
        | (1ULL << (bellParser::AREM - 54))
        | (1ULL << (bellParser::APLUS - 54))
        | (1ULL << (bellParser::AMINUS - 54))
        | (1ULL << (bellParser::ABITAND - 54))
        | (1ULL << (bellParser::ABITXOR - 54))
        | (1ULL << (bellParser::ABITOR - 54))
        | (1ULL << (bellParser::ALOGAND - 54))
        | (1ULL << (bellParser::ALOGANDEXT - 54))
        | (1ULL << (bellParser::ALOGXOR - 54))
        | (1ULL << (bellParser::ALOGOR - 54))
        | (1ULL << (bellParser::ALOGOREXT - 54))
        | (1ULL << (bellParser::ALSHIFT - 54))
        | (1ULL << (bellParser::ARSHIFT - 54))
        | (1ULL << (bellParser::ACONCAT - 54))
        | (1ULL << (bellParser::ARCONCAT - 54)))) != 0))) {
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
  enterRule(_localctx, 58, bellParser::RuleConditional);

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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
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
  enterRule(_localctx, 60, bellParser::RuleList);

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
    setState(492); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(491);
              expr(0);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(494); 
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
    case 26: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

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
    case 4: return precpred(_ctx, 18);
    case 5: return precpred(_ctx, 17);
    case 6: return precpred(_ctx, 15);
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
    case 19: return precpred(_ctx, 14);

  default:
    break;
  }
  return true;
}

void bellParser::initialize() {
  std::call_once(bellParserOnceFlag, bellParserInitialize);
}
