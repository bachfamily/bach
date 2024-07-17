 
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
      "RANGE", "UINT", "UFLOAT", "UPITCH", "NOTENAME", "ACCIDENTAL", "RAT", 
      "BTSYMBOL", "DQSYMBOL", "SQSYMBOL", "BACHNULL", "BACHNIL", "IF", "THEN", 
      "ELSE", "WHILE", "FOR", "DO", "COLLECT", "FUNCTION", "INLET", "INTINLET", 
      "RATINLET", "FLOATINLET", "PITCHINLET", "OUTLET", "DIRINLET", "DIROUTLET", 
      "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "NAMEDPARAM", "ID", "PUSH", 
      "POP", "CLOSED", "NTH", "PICK", "KEY", "ANTH", "APICK", "NULLIFY", 
      "ASSIGN", "WHITESPACE", "NEWATOM", "POW", "APOW", "TIMES", "ATIMES", 
      "DIVDIV", "ADIVDIV", "DIV", "ADIV", "REM", "AREM", "PLUS", "APLUS", 
      "UPLUS", "MINUS", "AMINUS", "UMINUS", "EQUAL", "NEQ", "LOGNOT", "BITNOT", 
      "LT", "GT", "LEQ", "GEQ", "BITAND", "ABITAND", "BITXOR", "ABITXOR", 
      "BITOR", "ABITOR", "LOGAND", "LOGANDEXT", "ALOGAND", "ALOGANDEXT", 
      "LOGXOR", "ALOGXOR", "LOGOR", "ALOGOR", "LOGOREXT", "ALOGOREXT", "LSHIFT", 
      "ALSHIFT", "RSHIFT", "ARSHIFT", "REPEAT", "AREPEAT", "AAPPLY", "ACONCAT", 
      "ARCONCAT", "OPEN", "PARAMS", "ANYTHING"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'...'", "", "", "", "", "", "", "'null'", "'nil'", "'if'", "'then'", 
      "'else'", "'while'", "'for'", "'do'", "'collect'", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "'['", "']'", "')'", "':'", "'::'", 
      "'.'", "':='", "'::='", "';'", "'='", "", "", "'**'", "'**='", "'*'", 
      "'*='", "'//'", "'//='", "'/'", "'/='", "", "", "", "'+='", "'+'", 
      "", "'-='", "'-'", "'=='", "'!='", "'!'", "'~'", "'<'", "'>'", "'<='", 
      "'>='", "'&'", "'&='", "'^'", "'^='", "'|'", "'|='", "'&&'", "'&&&'", 
      "'&&='", "'&&&='", "'^^'", "'^^='", "'||'", "'||='", "'|||'", "'|||='", 
      "'<<'", "'<<='", "'>>'", "'>>='", "':*'", "':*='", "'.='", "'_='", 
      "'!_='"
    },
    std::vector<std::string>{
      "", "RANGE", "UINT", "UFLOAT", "UPITCH", "BTSYMBOL", "DQSYMBOL", "SQSYMBOL", 
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
      "ALOGOREXT", "LSHIFT", "ALSHIFT", "RSHIFT", "ARSHIFT", "REPEAT", "AREPEAT", 
      "AAPPLY", "ACONCAT", "ARCONCAT", "OPEN", "PARAMS", "ANYTHING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,93,839,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,
  	7,63,2,64,7,64,2,65,7,65,2,66,7,66,2,67,7,67,2,68,7,68,2,69,7,69,2,70,
  	7,70,2,71,7,71,2,72,7,72,2,73,7,73,2,74,7,74,2,75,7,75,2,76,7,76,2,77,
  	7,77,2,78,7,78,2,79,7,79,2,80,7,80,2,81,7,81,2,82,7,82,2,83,7,83,2,84,
  	7,84,2,85,7,85,2,86,7,86,2,87,7,87,2,88,7,88,2,89,7,89,2,90,7,90,2,91,
  	7,91,2,92,7,92,2,93,7,93,2,94,7,94,2,95,7,95,2,96,7,96,1,0,1,0,1,0,1,
  	0,1,0,1,0,1,1,4,1,203,8,1,11,1,12,1,204,1,1,1,1,1,2,5,2,210,8,2,10,2,
  	12,2,213,9,2,1,2,1,2,4,2,217,8,2,11,2,12,2,218,1,2,4,2,222,8,2,11,2,12,
  	2,223,1,2,3,2,227,8,2,1,2,1,2,3,2,231,8,2,1,2,4,2,234,8,2,11,2,12,2,235,
  	3,2,238,8,2,1,2,4,2,241,8,2,11,2,12,2,242,1,2,1,2,3,2,247,8,2,1,2,4,2,
  	250,8,2,11,2,12,2,251,3,2,254,8,2,1,2,1,2,1,3,1,3,3,3,260,8,3,1,3,5,3,
  	263,8,3,10,3,12,3,266,9,3,1,3,1,3,5,3,270,8,3,10,3,12,3,273,9,3,1,3,1,
  	3,3,3,277,8,3,1,3,1,3,3,3,281,8,3,1,3,1,3,1,4,3,4,286,8,4,1,5,4,5,289,
  	8,5,11,5,12,5,290,1,6,1,6,1,6,5,6,296,8,6,10,6,12,6,299,9,6,1,6,1,6,1,
  	7,1,7,4,7,305,8,7,11,7,12,7,306,1,7,1,7,1,8,1,8,1,8,1,8,5,8,315,8,8,10,
  	8,12,8,318,9,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,5,9,328,8,9,10,9,12,9,
  	331,9,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,
  	1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,410,8,19,1,20,3,20,413,8,
  	20,1,20,1,20,1,20,4,20,418,8,20,11,20,12,20,419,1,20,1,20,1,21,3,21,425,
  	8,21,1,21,1,21,1,21,1,21,4,21,431,8,21,11,21,12,21,432,1,21,1,21,1,22,
  	3,22,438,8,22,1,22,1,22,1,22,1,22,4,22,444,8,22,11,22,12,22,445,1,22,
  	1,22,1,23,3,23,451,8,23,1,23,1,23,1,23,1,23,4,23,457,8,23,11,23,12,23,
  	458,1,23,1,23,1,24,3,24,464,8,24,1,24,1,24,1,24,1,24,4,24,470,8,24,11,
  	24,12,24,471,1,24,1,24,1,25,3,25,477,8,25,1,25,1,25,1,25,1,25,4,25,483,
  	8,25,11,25,12,25,484,1,25,1,25,1,26,3,26,490,8,26,1,26,1,26,1,26,1,26,
  	1,26,4,26,497,8,26,11,26,12,26,498,1,26,1,26,1,27,3,27,504,8,27,1,27,
  	1,27,1,27,1,27,1,27,4,27,511,8,27,11,27,12,27,512,1,27,1,27,1,28,1,28,
  	1,28,1,29,1,29,1,29,1,29,1,30,3,30,525,8,30,1,30,1,30,1,30,1,30,1,31,
  	3,31,532,8,31,1,31,1,31,1,31,1,31,1,32,1,32,5,32,540,8,32,10,32,12,32,
  	543,9,32,1,32,3,32,546,8,32,1,33,1,33,1,33,1,34,1,34,1,34,1,35,1,35,1,
  	35,1,36,1,36,1,36,1,37,1,37,1,37,1,37,1,37,1,38,1,38,1,38,1,39,1,39,1,
  	39,1,39,1,39,1,40,1,40,1,40,1,40,1,40,1,40,1,41,1,41,1,41,1,42,1,42,1,
  	42,1,43,1,43,1,43,1,43,1,43,1,44,1,44,1,44,1,44,1,44,1,45,1,45,1,45,1,
  	45,1,45,1,46,1,46,1,46,1,46,1,46,1,46,1,47,1,47,1,47,1,48,1,48,1,48,1,
  	48,1,48,1,49,1,49,1,49,1,49,1,49,1,50,1,50,1,50,1,50,1,50,1,50,1,51,1,
  	51,1,51,1,52,1,52,1,52,1,52,1,52,1,53,1,53,1,53,1,54,1,54,1,54,1,55,1,
  	55,1,55,1,55,1,56,1,56,1,56,1,56,1,56,1,57,1,57,1,57,1,58,1,58,1,58,1,
  	58,1,59,1,59,1,59,1,59,1,59,1,60,1,60,1,60,1,61,1,61,1,61,1,61,1,61,1,
  	62,1,62,1,62,1,62,1,62,1,63,1,63,1,63,1,64,1,64,1,64,1,65,1,65,1,65,1,
  	66,1,66,1,66,1,67,1,67,1,67,1,67,1,67,1,68,1,68,1,68,1,68,1,68,1,69,1,
  	69,1,69,1,70,1,70,1,70,1,70,1,70,1,71,1,71,1,71,1,72,1,72,1,72,1,72,1,
  	72,1,73,1,73,1,73,1,74,1,74,1,74,1,74,1,74,1,75,1,75,1,75,1,75,1,75,1,
  	76,1,76,1,76,1,76,1,76,1,76,1,77,1,77,1,77,1,77,1,77,1,77,1,78,1,78,1,
  	78,1,78,1,78,1,78,1,78,1,79,1,79,1,79,1,79,1,79,1,80,1,80,1,80,1,80,1,
  	80,1,80,1,81,1,81,1,81,1,81,1,81,1,82,1,82,1,82,1,82,1,82,1,82,1,83,1,
  	83,1,83,1,83,1,83,1,83,1,84,1,84,1,84,1,84,1,84,1,84,1,84,1,85,1,85,1,
  	85,1,85,1,85,1,86,1,86,1,86,1,86,1,86,1,86,1,87,1,87,1,87,1,87,1,87,1,
  	88,1,88,1,88,1,88,1,88,1,88,1,89,1,89,1,89,1,89,1,89,1,90,1,90,1,90,1,
  	90,1,90,1,90,1,91,1,91,1,91,1,91,1,91,1,92,1,92,1,92,1,92,1,92,1,93,1,
  	93,1,93,1,93,1,93,1,93,1,94,1,94,1,94,1,94,1,95,1,95,1,95,1,95,1,96,4,
  	96,836,8,96,11,96,12,96,837,1,837,0,97,1,1,3,2,5,3,7,4,9,0,11,0,13,0,
  	15,5,17,6,19,7,21,8,23,9,25,10,27,11,29,12,31,13,33,14,35,15,37,16,39,
  	17,41,18,43,19,45,20,47,21,49,22,51,23,53,24,55,25,57,26,59,27,61,28,
  	63,29,65,0,67,30,69,31,71,32,73,33,75,34,77,35,79,36,81,37,83,38,85,39,
  	87,40,89,41,91,42,93,43,95,44,97,45,99,46,101,47,103,48,105,49,107,50,
  	109,51,111,52,113,53,115,54,117,55,119,56,121,57,123,58,125,59,127,60,
  	129,61,131,62,133,63,135,64,137,65,139,66,141,67,143,68,145,69,147,70,
  	149,71,151,72,153,73,155,74,157,75,159,76,161,77,163,78,165,79,167,80,
  	169,81,171,82,173,83,175,84,177,85,179,86,181,87,183,88,185,89,187,90,
  	189,91,191,92,193,93,1,0,14,1,0,48,57,2,0,69,69,101,101,2,0,43,43,45,
  	45,2,0,65,71,97,103,7,0,35,35,94,94,98,98,100,100,113,113,118,118,120,
  	120,3,0,9,10,13,13,32,32,1,0,34,34,1,0,92,92,1,0,39,39,2,0,108,108,120,
  	120,2,0,65,90,97,122,4,0,48,57,65,90,95,95,97,122,3,0,48,57,65,90,97,
  	122,1,0,1,1,881,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,15,
  	1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,
  	0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,
  	0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,
  	1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,
  	0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,
  	0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,
  	1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,
  	0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,0,
  	0,103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,0,111,1,0,0,0,
  	0,113,1,0,0,0,0,115,1,0,0,0,0,117,1,0,0,0,0,119,1,0,0,0,0,121,1,0,0,0,
  	0,123,1,0,0,0,0,125,1,0,0,0,0,127,1,0,0,0,0,129,1,0,0,0,0,131,1,0,0,0,
  	0,133,1,0,0,0,0,135,1,0,0,0,0,137,1,0,0,0,0,139,1,0,0,0,0,141,1,0,0,0,
  	0,143,1,0,0,0,0,145,1,0,0,0,0,147,1,0,0,0,0,149,1,0,0,0,0,151,1,0,0,0,
  	0,153,1,0,0,0,0,155,1,0,0,0,0,157,1,0,0,0,0,159,1,0,0,0,0,161,1,0,0,0,
  	0,163,1,0,0,0,0,165,1,0,0,0,0,167,1,0,0,0,0,169,1,0,0,0,0,171,1,0,0,0,
  	0,173,1,0,0,0,0,175,1,0,0,0,0,177,1,0,0,0,0,179,1,0,0,0,0,181,1,0,0,0,
  	0,183,1,0,0,0,0,185,1,0,0,0,0,187,1,0,0,0,0,189,1,0,0,0,0,191,1,0,0,0,
  	0,193,1,0,0,0,1,195,1,0,0,0,3,202,1,0,0,0,5,253,1,0,0,0,7,257,1,0,0,0,
  	9,285,1,0,0,0,11,288,1,0,0,0,13,292,1,0,0,0,15,302,1,0,0,0,17,310,1,0,
  	0,0,19,323,1,0,0,0,21,336,1,0,0,0,23,343,1,0,0,0,25,349,1,0,0,0,27,354,
  	1,0,0,0,29,361,1,0,0,0,31,368,1,0,0,0,33,376,1,0,0,0,35,382,1,0,0,0,37,
  	387,1,0,0,0,39,409,1,0,0,0,41,412,1,0,0,0,43,424,1,0,0,0,45,437,1,0,0,
  	0,47,450,1,0,0,0,49,463,1,0,0,0,51,476,1,0,0,0,53,489,1,0,0,0,55,503,
  	1,0,0,0,57,516,1,0,0,0,59,519,1,0,0,0,61,524,1,0,0,0,63,531,1,0,0,0,65,
  	537,1,0,0,0,67,547,1,0,0,0,69,550,1,0,0,0,71,553,1,0,0,0,73,556,1,0,0,
  	0,75,559,1,0,0,0,77,564,1,0,0,0,79,567,1,0,0,0,81,572,1,0,0,0,83,578,
  	1,0,0,0,85,581,1,0,0,0,87,584,1,0,0,0,89,589,1,0,0,0,91,594,1,0,0,0,93,
  	599,1,0,0,0,95,605,1,0,0,0,97,608,1,0,0,0,99,613,1,0,0,0,101,618,1,0,
  	0,0,103,624,1,0,0,0,105,627,1,0,0,0,107,632,1,0,0,0,109,635,1,0,0,0,111,
  	638,1,0,0,0,113,642,1,0,0,0,115,647,1,0,0,0,117,650,1,0,0,0,119,654,1,
  	0,0,0,121,659,1,0,0,0,123,662,1,0,0,0,125,667,1,0,0,0,127,672,1,0,0,0,
  	129,675,1,0,0,0,131,678,1,0,0,0,133,681,1,0,0,0,135,684,1,0,0,0,137,689,
  	1,0,0,0,139,694,1,0,0,0,141,697,1,0,0,0,143,702,1,0,0,0,145,705,1,0,0,
  	0,147,710,1,0,0,0,149,713,1,0,0,0,151,718,1,0,0,0,153,723,1,0,0,0,155,
  	729,1,0,0,0,157,735,1,0,0,0,159,742,1,0,0,0,161,747,1,0,0,0,163,753,1,
  	0,0,0,165,758,1,0,0,0,167,764,1,0,0,0,169,770,1,0,0,0,171,777,1,0,0,0,
  	173,782,1,0,0,0,175,788,1,0,0,0,177,793,1,0,0,0,179,799,1,0,0,0,181,804,
  	1,0,0,0,183,810,1,0,0,0,185,815,1,0,0,0,187,820,1,0,0,0,189,826,1,0,0,
  	0,191,830,1,0,0,0,193,835,1,0,0,0,195,196,5,46,0,0,196,197,5,46,0,0,197,
  	198,5,46,0,0,198,199,1,0,0,0,199,200,6,0,0,0,200,2,1,0,0,0,201,203,7,
  	0,0,0,202,201,1,0,0,0,203,204,1,0,0,0,204,202,1,0,0,0,204,205,1,0,0,0,
  	205,206,1,0,0,0,206,207,6,1,1,0,207,4,1,0,0,0,208,210,7,0,0,0,209,208,
  	1,0,0,0,210,213,1,0,0,0,211,209,1,0,0,0,211,212,1,0,0,0,212,214,1,0,0,
  	0,213,211,1,0,0,0,214,216,5,46,0,0,215,217,7,0,0,0,216,215,1,0,0,0,217,
  	218,1,0,0,0,218,216,1,0,0,0,218,219,1,0,0,0,219,227,1,0,0,0,220,222,7,
  	0,0,0,221,220,1,0,0,0,222,223,1,0,0,0,223,221,1,0,0,0,223,224,1,0,0,0,
  	224,225,1,0,0,0,225,227,5,46,0,0,226,211,1,0,0,0,226,221,1,0,0,0,227,
  	237,1,0,0,0,228,230,7,1,0,0,229,231,7,2,0,0,230,229,1,0,0,0,230,231,1,
  	0,0,0,231,233,1,0,0,0,232,234,7,0,0,0,233,232,1,0,0,0,234,235,1,0,0,0,
  	235,233,1,0,0,0,235,236,1,0,0,0,236,238,1,0,0,0,237,228,1,0,0,0,237,238,
  	1,0,0,0,238,254,1,0,0,0,239,241,7,0,0,0,240,239,1,0,0,0,241,242,1,0,0,
  	0,242,240,1,0,0,0,242,243,1,0,0,0,243,244,1,0,0,0,244,246,7,1,0,0,245,
  	247,7,2,0,0,246,245,1,0,0,0,246,247,1,0,0,0,247,249,1,0,0,0,248,250,7,
  	0,0,0,249,248,1,0,0,0,250,251,1,0,0,0,251,249,1,0,0,0,251,252,1,0,0,0,
  	252,254,1,0,0,0,253,226,1,0,0,0,253,240,1,0,0,0,254,255,1,0,0,0,255,256,
  	6,2,2,0,256,6,1,0,0,0,257,259,3,9,4,0,258,260,3,11,5,0,259,258,1,0,0,
  	0,259,260,1,0,0,0,260,264,1,0,0,0,261,263,7,2,0,0,262,261,1,0,0,0,263,
  	266,1,0,0,0,264,262,1,0,0,0,264,265,1,0,0,0,265,267,1,0,0,0,266,264,1,
  	0,0,0,267,280,3,3,1,0,268,270,7,2,0,0,269,268,1,0,0,0,270,273,1,0,0,0,
  	271,269,1,0,0,0,271,272,1,0,0,0,272,276,1,0,0,0,273,271,1,0,0,0,274,277,
  	3,3,1,0,275,277,3,13,6,0,276,274,1,0,0,0,276,275,1,0,0,0,277,278,1,0,
  	0,0,278,279,5,116,0,0,279,281,1,0,0,0,280,271,1,0,0,0,280,281,1,0,0,0,
  	281,282,1,0,0,0,282,283,6,3,3,0,283,8,1,0,0,0,284,286,7,3,0,0,285,284,
  	1,0,0,0,286,10,1,0,0,0,287,289,7,4,0,0,288,287,1,0,0,0,289,290,1,0,0,
  	0,290,288,1,0,0,0,290,291,1,0,0,0,291,12,1,0,0,0,292,293,3,3,1,0,293,
  	297,5,47,0,0,294,296,7,2,0,0,295,294,1,0,0,0,296,299,1,0,0,0,297,295,
  	1,0,0,0,297,298,1,0,0,0,298,300,1,0,0,0,299,297,1,0,0,0,300,301,3,3,1,
  	0,301,14,1,0,0,0,302,304,5,96,0,0,303,305,8,5,0,0,304,303,1,0,0,0,305,
  	306,1,0,0,0,306,304,1,0,0,0,306,307,1,0,0,0,307,308,1,0,0,0,308,309,6,
  	7,4,0,309,16,1,0,0,0,310,316,5,34,0,0,311,312,5,92,0,0,312,315,5,34,0,
  	0,313,315,8,6,0,0,314,311,1,0,0,0,314,313,1,0,0,0,315,318,1,0,0,0,316,
  	314,1,0,0,0,316,317,1,0,0,0,317,319,1,0,0,0,318,316,1,0,0,0,319,320,8,
  	7,0,0,320,321,5,34,0,0,321,322,6,8,5,0,322,18,1,0,0,0,323,329,5,39,0,
  	0,324,325,5,92,0,0,325,328,5,39,0,0,326,328,8,8,0,0,327,324,1,0,0,0,327,
  	326,1,0,0,0,328,331,1,0,0,0,329,327,1,0,0,0,329,330,1,0,0,0,330,332,1,
  	0,0,0,331,329,1,0,0,0,332,333,8,7,0,0,333,334,5,39,0,0,334,335,6,9,6,
  	0,335,20,1,0,0,0,336,337,5,110,0,0,337,338,5,117,0,0,338,339,5,108,0,
  	0,339,340,5,108,0,0,340,341,1,0,0,0,341,342,6,10,7,0,342,22,1,0,0,0,343,
  	344,5,110,0,0,344,345,5,105,0,0,345,346,5,108,0,0,346,347,1,0,0,0,347,
  	348,6,11,8,0,348,24,1,0,0,0,349,350,5,105,0,0,350,351,5,102,0,0,351,352,
  	1,0,0,0,352,353,6,12,9,0,353,26,1,0,0,0,354,355,5,116,0,0,355,356,5,104,
  	0,0,356,357,5,101,0,0,357,358,5,110,0,0,358,359,1,0,0,0,359,360,6,13,
  	10,0,360,28,1,0,0,0,361,362,5,101,0,0,362,363,5,108,0,0,363,364,5,115,
  	0,0,364,365,5,101,0,0,365,366,1,0,0,0,366,367,6,14,11,0,367,30,1,0,0,
  	0,368,369,5,119,0,0,369,370,5,104,0,0,370,371,5,105,0,0,371,372,5,108,
  	0,0,372,373,5,101,0,0,373,374,1,0,0,0,374,375,6,15,12,0,375,32,1,0,0,
  	0,376,377,5,102,0,0,377,378,5,111,0,0,378,379,5,114,0,0,379,380,1,0,0,
  	0,380,381,6,16,13,0,381,34,1,0,0,0,382,383,5,100,0,0,383,384,5,111,0,
  	0,384,385,1,0,0,0,385,386,6,17,14,0,386,36,1,0,0,0,387,388,5,99,0,0,388,
  	389,5,111,0,0,389,390,5,108,0,0,390,391,5,108,0,0,391,392,5,101,0,0,392,
  	393,5,99,0,0,393,394,5,116,0,0,394,395,1,0,0,0,395,396,6,18,15,0,396,
  	38,1,0,0,0,397,398,5,115,0,0,398,399,5,105,0,0,399,410,5,110,0,0,400,
  	401,5,99,0,0,401,402,5,111,0,0,402,410,5,115,0,0,403,404,5,115,0,0,404,
  	405,5,113,0,0,405,406,5,114,0,0,406,407,5,116,0,0,407,408,1,0,0,0,408,
  	410,6,19,16,0,409,397,1,0,0,0,409,400,1,0,0,0,409,403,1,0,0,0,410,40,
  	1,0,0,0,411,413,5,92,0,0,412,411,1,0,0,0,412,413,1,0,0,0,413,414,1,0,
  	0,0,414,415,5,36,0,0,415,417,7,9,0,0,416,418,7,0,0,0,417,416,1,0,0,0,
  	418,419,1,0,0,0,419,417,1,0,0,0,419,420,1,0,0,0,420,421,1,0,0,0,421,422,
  	6,20,17,0,422,42,1,0,0,0,423,425,5,92,0,0,424,423,1,0,0,0,424,425,1,0,
  	0,0,425,426,1,0,0,0,426,427,5,36,0,0,427,428,5,105,0,0,428,430,1,0,0,
  	0,429,431,7,0,0,0,430,429,1,0,0,0,431,432,1,0,0,0,432,430,1,0,0,0,432,
  	433,1,0,0,0,433,434,1,0,0,0,434,435,6,21,18,0,435,44,1,0,0,0,436,438,
  	5,92,0,0,437,436,1,0,0,0,437,438,1,0,0,0,438,439,1,0,0,0,439,440,5,36,
  	0,0,440,441,5,114,0,0,441,443,1,0,0,0,442,444,7,0,0,0,443,442,1,0,0,0,
  	444,445,1,0,0,0,445,443,1,0,0,0,445,446,1,0,0,0,446,447,1,0,0,0,447,448,
  	6,22,19,0,448,46,1,0,0,0,449,451,5,92,0,0,450,449,1,0,0,0,450,451,1,0,
  	0,0,451,452,1,0,0,0,452,453,5,36,0,0,453,454,5,102,0,0,454,456,1,0,0,
  	0,455,457,7,0,0,0,456,455,1,0,0,0,457,458,1,0,0,0,458,456,1,0,0,0,458,
  	459,1,0,0,0,459,460,1,0,0,0,460,461,6,23,20,0,461,48,1,0,0,0,462,464,
  	5,92,0,0,463,462,1,0,0,0,463,464,1,0,0,0,464,465,1,0,0,0,465,466,5,36,
  	0,0,466,467,5,112,0,0,467,469,1,0,0,0,468,470,7,0,0,0,469,468,1,0,0,0,
  	470,471,1,0,0,0,471,469,1,0,0,0,471,472,1,0,0,0,472,473,1,0,0,0,473,474,
  	6,24,21,0,474,50,1,0,0,0,475,477,5,92,0,0,476,475,1,0,0,0,476,477,1,0,
  	0,0,477,478,1,0,0,0,478,479,5,36,0,0,479,480,5,111,0,0,480,482,1,0,0,
  	0,481,483,7,0,0,0,482,481,1,0,0,0,483,484,1,0,0,0,484,482,1,0,0,0,484,
  	485,1,0,0,0,485,486,1,0,0,0,486,487,6,25,22,0,487,52,1,0,0,0,488,490,
  	5,92,0,0,489,488,1,0,0,0,489,490,1,0,0,0,490,491,1,0,0,0,491,492,5,36,
  	0,0,492,493,5,100,0,0,493,494,5,120,0,0,494,496,1,0,0,0,495,497,7,0,0,
  	0,496,495,1,0,0,0,497,498,1,0,0,0,498,496,1,0,0,0,498,499,1,0,0,0,499,
  	500,1,0,0,0,500,501,6,26,23,0,501,54,1,0,0,0,502,504,5,92,0,0,503,502,
  	1,0,0,0,503,504,1,0,0,0,504,505,1,0,0,0,505,506,5,36,0,0,506,507,5,100,
  	0,0,507,508,5,111,0,0,508,510,1,0,0,0,509,511,7,0,0,0,510,509,1,0,0,0,
  	511,512,1,0,0,0,512,510,1,0,0,0,512,513,1,0,0,0,513,514,1,0,0,0,514,515,
  	6,27,24,0,515,56,1,0,0,0,516,517,3,65,32,0,517,518,6,28,25,0,518,58,1,
  	0,0,0,519,520,5,35,0,0,520,521,3,65,32,0,521,522,6,29,26,0,522,60,1,0,
  	0,0,523,525,5,92,0,0,524,523,1,0,0,0,524,525,1,0,0,0,525,526,1,0,0,0,
  	526,527,5,36,0,0,527,528,3,65,32,0,528,529,6,30,27,0,529,62,1,0,0,0,530,
  	532,5,92,0,0,531,530,1,0,0,0,531,532,1,0,0,0,532,533,1,0,0,0,533,534,
  	5,64,0,0,534,535,3,65,32,0,535,536,6,31,28,0,536,64,1,0,0,0,537,545,7,
  	10,0,0,538,540,7,11,0,0,539,538,1,0,0,0,540,543,1,0,0,0,541,539,1,0,0,
  	0,541,542,1,0,0,0,542,544,1,0,0,0,543,541,1,0,0,0,544,546,7,12,0,0,545,
  	541,1,0,0,0,545,546,1,0,0,0,546,66,1,0,0,0,547,548,5,91,0,0,548,549,6,
  	33,29,0,549,68,1,0,0,0,550,551,5,93,0,0,551,552,6,34,30,0,552,70,1,0,
  	0,0,553,554,5,41,0,0,554,555,6,35,31,0,555,72,1,0,0,0,556,557,5,58,0,
  	0,557,558,6,36,32,0,558,74,1,0,0,0,559,560,5,58,0,0,560,561,5,58,0,0,
  	561,562,1,0,0,0,562,563,6,37,33,0,563,76,1,0,0,0,564,565,5,46,0,0,565,
  	566,6,38,34,0,566,78,1,0,0,0,567,568,5,58,0,0,568,569,5,61,0,0,569,570,
  	1,0,0,0,570,571,6,39,35,0,571,80,1,0,0,0,572,573,5,58,0,0,573,574,5,58,
  	0,0,574,575,5,61,0,0,575,576,1,0,0,0,576,577,6,40,36,0,577,82,1,0,0,0,
  	578,579,5,59,0,0,579,580,6,41,37,0,580,84,1,0,0,0,581,582,5,61,0,0,582,
  	583,6,42,38,0,583,86,1,0,0,0,584,585,7,5,0,0,585,586,6,43,39,0,586,587,
  	1,0,0,0,587,588,6,43,40,0,588,88,1,0,0,0,589,590,7,13,0,0,590,591,6,44,
  	41,0,591,592,1,0,0,0,592,593,6,44,40,0,593,90,1,0,0,0,594,595,5,42,0,
  	0,595,596,5,42,0,0,596,597,1,0,0,0,597,598,6,45,42,0,598,92,1,0,0,0,599,
  	600,5,42,0,0,600,601,5,42,0,0,601,602,5,61,0,0,602,603,1,0,0,0,603,604,
  	6,46,43,0,604,94,1,0,0,0,605,606,5,42,0,0,606,607,6,47,44,0,607,96,1,
  	0,0,0,608,609,5,42,0,0,609,610,5,61,0,0,610,611,1,0,0,0,611,612,6,48,
  	45,0,612,98,1,0,0,0,613,614,5,47,0,0,614,615,5,47,0,0,615,616,1,0,0,0,
  	616,617,6,49,46,0,617,100,1,0,0,0,618,619,5,47,0,0,619,620,5,47,0,0,620,
  	621,5,61,0,0,621,622,1,0,0,0,622,623,6,50,47,0,623,102,1,0,0,0,624,625,
  	5,47,0,0,625,626,6,51,48,0,626,104,1,0,0,0,627,628,5,47,0,0,628,629,5,
  	61,0,0,629,630,1,0,0,0,630,631,6,52,49,0,631,106,1,0,0,0,632,633,5,37,
  	0,0,633,634,6,53,50,0,634,108,1,0,0,0,635,636,5,37,0,0,636,637,6,54,51,
  	0,637,110,1,0,0,0,638,639,4,55,0,0,639,640,5,43,0,0,640,641,6,55,52,0,
  	641,112,1,0,0,0,642,643,5,43,0,0,643,644,5,61,0,0,644,645,1,0,0,0,645,
  	646,6,56,53,0,646,114,1,0,0,0,647,648,5,43,0,0,648,649,6,57,54,0,649,
  	116,1,0,0,0,650,651,4,58,1,0,651,652,5,45,0,0,652,653,6,58,55,0,653,118,
  	1,0,0,0,654,655,5,45,0,0,655,656,5,61,0,0,656,657,1,0,0,0,657,658,6,59,
  	56,0,658,120,1,0,0,0,659,660,5,45,0,0,660,661,6,60,57,0,661,122,1,0,0,
  	0,662,663,5,61,0,0,663,664,5,61,0,0,664,665,1,0,0,0,665,666,6,61,58,0,
  	666,124,1,0,0,0,667,668,5,33,0,0,668,669,5,61,0,0,669,670,1,0,0,0,670,
  	671,6,62,59,0,671,126,1,0,0,0,672,673,5,33,0,0,673,674,6,63,60,0,674,
  	128,1,0,0,0,675,676,5,126,0,0,676,677,6,64,61,0,677,130,1,0,0,0,678,679,
  	5,60,0,0,679,680,6,65,62,0,680,132,1,0,0,0,681,682,5,62,0,0,682,683,6,
  	66,63,0,683,134,1,0,0,0,684,685,5,60,0,0,685,686,5,61,0,0,686,687,1,0,
  	0,0,687,688,6,67,64,0,688,136,1,0,0,0,689,690,5,62,0,0,690,691,5,61,0,
  	0,691,692,1,0,0,0,692,693,6,68,65,0,693,138,1,0,0,0,694,695,5,38,0,0,
  	695,696,6,69,66,0,696,140,1,0,0,0,697,698,5,38,0,0,698,699,5,61,0,0,699,
  	700,1,0,0,0,700,701,6,70,67,0,701,142,1,0,0,0,702,703,5,94,0,0,703,704,
  	6,71,68,0,704,144,1,0,0,0,705,706,5,94,0,0,706,707,5,61,0,0,707,708,1,
  	0,0,0,708,709,6,72,69,0,709,146,1,0,0,0,710,711,5,124,0,0,711,712,6,73,
  	70,0,712,148,1,0,0,0,713,714,5,124,0,0,714,715,5,61,0,0,715,716,1,0,0,
  	0,716,717,6,74,71,0,717,150,1,0,0,0,718,719,5,38,0,0,719,720,5,38,0,0,
  	720,721,1,0,0,0,721,722,6,75,72,0,722,152,1,0,0,0,723,724,5,38,0,0,724,
  	725,5,38,0,0,725,726,5,38,0,0,726,727,1,0,0,0,727,728,6,76,73,0,728,154,
  	1,0,0,0,729,730,5,38,0,0,730,731,5,38,0,0,731,732,5,61,0,0,732,733,1,
  	0,0,0,733,734,6,77,74,0,734,156,1,0,0,0,735,736,5,38,0,0,736,737,5,38,
  	0,0,737,738,5,38,0,0,738,739,5,61,0,0,739,740,1,0,0,0,740,741,6,78,75,
  	0,741,158,1,0,0,0,742,743,5,94,0,0,743,744,5,94,0,0,744,745,1,0,0,0,745,
  	746,6,79,76,0,746,160,1,0,0,0,747,748,5,94,0,0,748,749,5,94,0,0,749,750,
  	5,61,0,0,750,751,1,0,0,0,751,752,6,80,77,0,752,162,1,0,0,0,753,754,5,
  	124,0,0,754,755,5,124,0,0,755,756,1,0,0,0,756,757,6,81,78,0,757,164,1,
  	0,0,0,758,759,5,124,0,0,759,760,5,124,0,0,760,761,5,61,0,0,761,762,1,
  	0,0,0,762,763,6,82,79,0,763,166,1,0,0,0,764,765,5,124,0,0,765,766,5,124,
  	0,0,766,767,5,124,0,0,767,768,1,0,0,0,768,769,6,83,80,0,769,168,1,0,0,
  	0,770,771,5,124,0,0,771,772,5,124,0,0,772,773,5,124,0,0,773,774,5,61,
  	0,0,774,775,1,0,0,0,775,776,6,84,81,0,776,170,1,0,0,0,777,778,5,60,0,
  	0,778,779,5,60,0,0,779,780,1,0,0,0,780,781,6,85,82,0,781,172,1,0,0,0,
  	782,783,5,60,0,0,783,784,5,60,0,0,784,785,5,61,0,0,785,786,1,0,0,0,786,
  	787,6,86,83,0,787,174,1,0,0,0,788,789,5,62,0,0,789,790,5,62,0,0,790,791,
  	1,0,0,0,791,792,6,87,84,0,792,176,1,0,0,0,793,794,5,62,0,0,794,795,5,
  	62,0,0,795,796,5,61,0,0,796,797,1,0,0,0,797,798,6,88,85,0,798,178,1,0,
  	0,0,799,800,5,58,0,0,800,801,5,42,0,0,801,802,1,0,0,0,802,803,6,89,86,
  	0,803,180,1,0,0,0,804,805,5,58,0,0,805,806,5,42,0,0,806,807,5,61,0,0,
  	807,808,1,0,0,0,808,809,6,90,87,0,809,182,1,0,0,0,810,811,5,46,0,0,811,
  	812,5,61,0,0,812,813,1,0,0,0,813,814,6,91,88,0,814,184,1,0,0,0,815,816,
  	5,95,0,0,816,817,5,61,0,0,817,818,1,0,0,0,818,819,6,92,89,0,819,186,1,
  	0,0,0,820,821,5,33,0,0,821,822,5,95,0,0,822,823,5,61,0,0,823,824,1,0,
  	0,0,824,825,6,93,90,0,825,188,1,0,0,0,826,827,4,94,2,0,827,828,5,40,0,
  	0,828,829,6,94,91,0,829,190,1,0,0,0,830,831,4,95,3,0,831,832,5,40,0,0,
  	832,833,6,95,92,0,833,192,1,0,0,0,834,836,9,0,0,0,835,834,1,0,0,0,836,
  	837,1,0,0,0,837,838,1,0,0,0,837,835,1,0,0,0,838,194,1,0,0,0,48,0,204,
  	211,218,223,226,230,235,237,242,246,251,253,259,264,271,276,280,285,290,
  	297,306,314,316,327,329,409,412,419,424,432,437,445,450,458,463,471,476,
  	484,489,498,503,512,524,531,541,545,837,93,1,0,0,1,1,1,1,2,2,1,3,3,1,
  	7,4,1,8,5,1,9,6,1,10,7,1,11,8,1,12,9,1,13,10,1,14,11,1,15,12,1,16,13,
  	1,17,14,1,18,15,1,19,16,1,20,17,1,21,18,1,22,19,1,23,20,1,24,21,1,25,
  	22,1,26,23,1,27,24,1,28,25,1,29,26,1,30,27,1,31,28,1,33,29,1,34,30,1,
  	35,31,1,36,32,1,37,33,1,38,34,1,39,35,1,40,36,1,41,37,1,42,38,1,43,39,
  	0,1,0,1,44,40,1,45,41,1,46,42,1,47,43,1,48,44,1,49,45,1,50,46,1,51,47,
  	1,52,48,1,53,49,1,54,50,1,55,51,1,56,52,1,57,53,1,58,54,1,59,55,1,60,
  	56,1,61,57,1,62,58,1,63,59,1,64,60,1,65,61,1,66,62,1,67,63,1,68,64,1,
  	69,65,1,70,66,1,71,67,1,72,68,1,73,69,1,74,70,1,75,71,1,76,72,1,77,73,
  	1,78,74,1,79,75,1,80,76,1,81,77,1,82,78,1,83,79,1,84,80,1,85,81,1,86,
  	82,1,87,83,1,88,84,1,89,85,1,90,86,1,91,87,1,92,88,1,93,89,1,94,90,1,
  	95,91
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
    case 0: RANGEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 1: UINTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 2: UFLOATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 3: UPITCHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 7: BTSYMBOLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 8: DQSYMBOLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 9: SQSYMBOLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 10: BACHNULLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 11: BACHNILAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: IFAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: THENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: ELSEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: WHILEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: FORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 17: DOAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 18: COLLECTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 19: FUNCTIONAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 20: INLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 21: INTINLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 22: RATINLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 23: FLOATINLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 24: PITCHINLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 25: OUTLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 26: DIRINLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 27: DIROUTLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 28: GLOBALVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 29: PATCHERVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 30: LOCALVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 31: NAMEDPARAMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 33: PUSHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 34: POPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 35: CLOSEDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 36: NTHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 37: PICKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 38: KEYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 39: ANTHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 40: APICKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 41: NULLIFYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 42: ASSIGNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 43: WHITESPACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 44: NEWATOMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 45: POWAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 46: APOWAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 47: TIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 48: ATIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 49: DIVDIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 50: ADIVDIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 51: DIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 52: ADIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 53: REMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 54: AREMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 55: PLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 56: APLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 57: UPLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 58: MINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 59: AMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 60: UMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 61: EQUALAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 62: NEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 63: LOGNOTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 64: BITNOTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 65: LTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 66: GTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 67: LEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 68: GEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 69: BITANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 70: ABITANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 71: BITXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 72: ABITXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 73: BITORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 74: ABITORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 75: LOGANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 76: LOGANDEXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 77: ALOGANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 78: ALOGANDEXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 79: LOGXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 80: ALOGXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 81: LOGORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 82: ALOGORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 83: LOGOREXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 84: ALOGOREXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 85: LSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 86: ALSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 87: RSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 88: ARSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 89: REPEATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 90: AREPEATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 91: AAPPLYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 92: ACONCATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 93: ARCONCATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 94: OPENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 95: PARAMSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool bellLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 55: return PLUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 58: return MINUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 94: return OPENSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 95: return PARAMSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

void bellLexer::RANGEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UINTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::UFLOATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::UPITCHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::BTSYMBOLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4:  noParams = true; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::DQSYMBOLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5:  noParams = true; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::SQSYMBOLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6:  noParams = true; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::BACHNULLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 7:  noParams = false; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BACHNILAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 8:  noParams = false; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::IFAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 9:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::THENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 10:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ELSEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 11:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::WHILEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 12:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::FORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 13:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DOAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 14:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::COLLECTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 15:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::FUNCTIONAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 16:  noParams = noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::INLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 17:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::INTINLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 18:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::RATINLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 19:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::FLOATINLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 20:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PITCHINLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 21:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::OUTLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::DIRINLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::DIROUTLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::GLOBALVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 25:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PATCHERVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 26:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::LOCALVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 27:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::NAMEDPARAMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 28:  noParams = true; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PUSHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 29:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::POPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 30:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::CLOSEDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 31:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::NTHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 32:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PICKAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 33:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::KEYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 34:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ANTHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 35:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::APICKAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 36:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NULLIFYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 37:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ASSIGNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 38:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::WHITESPACEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 39:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NEWATOMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 40:  noParams = true; noUnary = false; (*codeac)++;  break;

  default:
    break;
  }
}

void bellLexer::POWAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 41:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::APOWAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 42:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::TIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 43:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ATIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 44:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVDIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 45:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ADIVDIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 46:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 47:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ADIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 48:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::REMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 49:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::AREMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 50:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 51:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::APLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 52:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UPLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 53:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::MINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 54:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::AMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 55:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 56:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::EQUALAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 57:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 58:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGNOTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 59:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITNOTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 60:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 61:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::GTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 62:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 63:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::GEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 64:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 65:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ABITANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 66:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 67:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ABITXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 68:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 69:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ABITORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 70:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 71:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGANDEXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 72:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 73:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGANDEXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 74:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 75:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 76:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 77:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 78:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGOREXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 79:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGOREXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 80:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 81:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 82:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::RSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 83:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ARSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 84:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::REPEATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 85:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::AREPEATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 86:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::AAPPLYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 87:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ACONCATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 88:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ARCONCATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 89:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::OPENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 90:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PARAMSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 91:  noParams = true; noUnary = false;  break;

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
