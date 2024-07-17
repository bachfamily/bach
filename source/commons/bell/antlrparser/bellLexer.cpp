 
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
  	4,0,93,840,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
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
  	0,1,0,1,0,1,1,4,1,203,8,1,11,1,12,1,204,1,1,1,1,1,2,1,2,5,2,211,8,2,10,
  	2,12,2,214,9,2,1,2,1,2,4,2,218,8,2,11,2,12,2,219,1,2,4,2,223,8,2,11,2,
  	12,2,224,1,2,3,2,228,8,2,1,2,1,2,3,2,232,8,2,1,2,4,2,235,8,2,11,2,12,
  	2,236,3,2,239,8,2,1,2,4,2,242,8,2,11,2,12,2,243,1,2,1,2,3,2,248,8,2,1,
  	2,4,2,251,8,2,11,2,12,2,252,3,2,255,8,2,1,2,1,2,1,3,1,3,3,3,261,8,3,1,
  	3,5,3,264,8,3,10,3,12,3,267,9,3,1,3,1,3,5,3,271,8,3,10,3,12,3,274,9,3,
  	1,3,1,3,3,3,278,8,3,1,3,1,3,3,3,282,8,3,1,3,1,3,1,4,3,4,287,8,4,1,5,4,
  	5,290,8,5,11,5,12,5,291,1,6,1,6,1,6,5,6,297,8,6,10,6,12,6,300,9,6,1,6,
  	1,6,1,7,1,7,4,7,306,8,7,11,7,12,7,307,1,7,1,7,1,8,1,8,1,8,1,8,5,8,316,
  	8,8,10,8,12,8,319,9,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,5,9,329,8,9,10,
  	9,12,9,332,9,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,
  	1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,411,8,19,1,20,3,20,
  	414,8,20,1,20,1,20,1,20,4,20,419,8,20,11,20,12,20,420,1,20,1,20,1,21,
  	3,21,426,8,21,1,21,1,21,1,21,1,21,4,21,432,8,21,11,21,12,21,433,1,21,
  	1,21,1,22,3,22,439,8,22,1,22,1,22,1,22,1,22,4,22,445,8,22,11,22,12,22,
  	446,1,22,1,22,1,23,3,23,452,8,23,1,23,1,23,1,23,1,23,4,23,458,8,23,11,
  	23,12,23,459,1,23,1,23,1,24,3,24,465,8,24,1,24,1,24,1,24,1,24,4,24,471,
  	8,24,11,24,12,24,472,1,24,1,24,1,25,3,25,478,8,25,1,25,1,25,1,25,1,25,
  	4,25,484,8,25,11,25,12,25,485,1,25,1,25,1,26,3,26,491,8,26,1,26,1,26,
  	1,26,1,26,1,26,4,26,498,8,26,11,26,12,26,499,1,26,1,26,1,27,3,27,505,
  	8,27,1,27,1,27,1,27,1,27,1,27,4,27,512,8,27,11,27,12,27,513,1,27,1,27,
  	1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,30,3,30,526,8,30,1,30,1,30,1,30,
  	1,30,1,31,3,31,533,8,31,1,31,1,31,1,31,1,31,1,32,1,32,5,32,541,8,32,10,
  	32,12,32,544,9,32,1,32,3,32,547,8,32,1,33,1,33,1,33,1,34,1,34,1,34,1,
  	35,1,35,1,35,1,36,1,36,1,36,1,37,1,37,1,37,1,37,1,37,1,38,1,38,1,38,1,
  	39,1,39,1,39,1,39,1,39,1,40,1,40,1,40,1,40,1,40,1,40,1,41,1,41,1,41,1,
  	42,1,42,1,42,1,43,1,43,1,43,1,43,1,43,1,44,1,44,1,44,1,44,1,44,1,45,1,
  	45,1,45,1,45,1,45,1,46,1,46,1,46,1,46,1,46,1,46,1,47,1,47,1,47,1,48,1,
  	48,1,48,1,48,1,48,1,49,1,49,1,49,1,49,1,49,1,50,1,50,1,50,1,50,1,50,1,
  	50,1,51,1,51,1,51,1,52,1,52,1,52,1,52,1,52,1,53,1,53,1,53,1,54,1,54,1,
  	54,1,55,1,55,1,55,1,55,1,56,1,56,1,56,1,56,1,56,1,57,1,57,1,57,1,58,1,
  	58,1,58,1,58,1,59,1,59,1,59,1,59,1,59,1,60,1,60,1,60,1,61,1,61,1,61,1,
  	61,1,61,1,62,1,62,1,62,1,62,1,62,1,63,1,63,1,63,1,64,1,64,1,64,1,65,1,
  	65,1,65,1,66,1,66,1,66,1,67,1,67,1,67,1,67,1,67,1,68,1,68,1,68,1,68,1,
  	68,1,69,1,69,1,69,1,70,1,70,1,70,1,70,1,70,1,71,1,71,1,71,1,72,1,72,1,
  	72,1,72,1,72,1,73,1,73,1,73,1,74,1,74,1,74,1,74,1,74,1,75,1,75,1,75,1,
  	75,1,75,1,76,1,76,1,76,1,76,1,76,1,76,1,77,1,77,1,77,1,77,1,77,1,77,1,
  	78,1,78,1,78,1,78,1,78,1,78,1,78,1,79,1,79,1,79,1,79,1,79,1,80,1,80,1,
  	80,1,80,1,80,1,80,1,81,1,81,1,81,1,81,1,81,1,82,1,82,1,82,1,82,1,82,1,
  	82,1,83,1,83,1,83,1,83,1,83,1,83,1,84,1,84,1,84,1,84,1,84,1,84,1,84,1,
  	85,1,85,1,85,1,85,1,85,1,86,1,86,1,86,1,86,1,86,1,86,1,87,1,87,1,87,1,
  	87,1,87,1,88,1,88,1,88,1,88,1,88,1,88,1,89,1,89,1,89,1,89,1,89,1,90,1,
  	90,1,90,1,90,1,90,1,90,1,91,1,91,1,91,1,91,1,91,1,92,1,92,1,92,1,92,1,
  	92,1,93,1,93,1,93,1,93,1,93,1,93,1,94,1,94,1,94,1,94,1,95,1,95,1,95,1,
  	95,1,96,4,96,837,8,96,11,96,12,96,838,1,838,0,97,1,1,3,2,5,3,7,4,9,0,
  	11,0,13,0,15,5,17,6,19,7,21,8,23,9,25,10,27,11,29,12,31,13,33,14,35,15,
  	37,16,39,17,41,18,43,19,45,20,47,21,49,22,51,23,53,24,55,25,57,26,59,
  	27,61,28,63,29,65,0,67,30,69,31,71,32,73,33,75,34,77,35,79,36,81,37,83,
  	38,85,39,87,40,89,41,91,42,93,43,95,44,97,45,99,46,101,47,103,48,105,
  	49,107,50,109,51,111,52,113,53,115,54,117,55,119,56,121,57,123,58,125,
  	59,127,60,129,61,131,62,133,63,135,64,137,65,139,66,141,67,143,68,145,
  	69,147,70,149,71,151,72,153,73,155,74,157,75,159,76,161,77,163,78,165,
  	79,167,80,169,81,171,82,173,83,175,84,177,85,179,86,181,87,183,88,185,
  	89,187,90,189,91,191,92,193,93,1,0,14,1,0,48,57,2,0,69,69,101,101,2,0,
  	43,43,45,45,2,0,65,71,97,103,7,0,35,35,94,94,98,98,100,100,113,113,118,
  	118,120,120,3,0,9,10,13,13,32,32,1,0,34,34,1,0,92,92,1,0,39,39,2,0,108,
  	108,120,120,2,0,65,90,97,122,4,0,48,57,65,90,95,95,97,122,3,0,48,57,65,
  	90,97,122,1,0,1,1,882,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,
  	0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,
  	1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,
  	0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,
  	0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,
  	1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,67,1,0,0,0,0,69,1,0,
  	0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,
  	0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,
  	1,0,0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,
  	0,0,0,103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,0,111,1,0,
  	0,0,0,113,1,0,0,0,0,115,1,0,0,0,0,117,1,0,0,0,0,119,1,0,0,0,0,121,1,0,
  	0,0,0,123,1,0,0,0,0,125,1,0,0,0,0,127,1,0,0,0,0,129,1,0,0,0,0,131,1,0,
  	0,0,0,133,1,0,0,0,0,135,1,0,0,0,0,137,1,0,0,0,0,139,1,0,0,0,0,141,1,0,
  	0,0,0,143,1,0,0,0,0,145,1,0,0,0,0,147,1,0,0,0,0,149,1,0,0,0,0,151,1,0,
  	0,0,0,153,1,0,0,0,0,155,1,0,0,0,0,157,1,0,0,0,0,159,1,0,0,0,0,161,1,0,
  	0,0,0,163,1,0,0,0,0,165,1,0,0,0,0,167,1,0,0,0,0,169,1,0,0,0,0,171,1,0,
  	0,0,0,173,1,0,0,0,0,175,1,0,0,0,0,177,1,0,0,0,0,179,1,0,0,0,0,181,1,0,
  	0,0,0,183,1,0,0,0,0,185,1,0,0,0,0,187,1,0,0,0,0,189,1,0,0,0,0,191,1,0,
  	0,0,0,193,1,0,0,0,1,195,1,0,0,0,3,202,1,0,0,0,5,208,1,0,0,0,7,258,1,0,
  	0,0,9,286,1,0,0,0,11,289,1,0,0,0,13,293,1,0,0,0,15,303,1,0,0,0,17,311,
  	1,0,0,0,19,324,1,0,0,0,21,337,1,0,0,0,23,344,1,0,0,0,25,350,1,0,0,0,27,
  	355,1,0,0,0,29,362,1,0,0,0,31,369,1,0,0,0,33,377,1,0,0,0,35,383,1,0,0,
  	0,37,388,1,0,0,0,39,410,1,0,0,0,41,413,1,0,0,0,43,425,1,0,0,0,45,438,
  	1,0,0,0,47,451,1,0,0,0,49,464,1,0,0,0,51,477,1,0,0,0,53,490,1,0,0,0,55,
  	504,1,0,0,0,57,517,1,0,0,0,59,520,1,0,0,0,61,525,1,0,0,0,63,532,1,0,0,
  	0,65,538,1,0,0,0,67,548,1,0,0,0,69,551,1,0,0,0,71,554,1,0,0,0,73,557,
  	1,0,0,0,75,560,1,0,0,0,77,565,1,0,0,0,79,568,1,0,0,0,81,573,1,0,0,0,83,
  	579,1,0,0,0,85,582,1,0,0,0,87,585,1,0,0,0,89,590,1,0,0,0,91,595,1,0,0,
  	0,93,600,1,0,0,0,95,606,1,0,0,0,97,609,1,0,0,0,99,614,1,0,0,0,101,619,
  	1,0,0,0,103,625,1,0,0,0,105,628,1,0,0,0,107,633,1,0,0,0,109,636,1,0,0,
  	0,111,639,1,0,0,0,113,643,1,0,0,0,115,648,1,0,0,0,117,651,1,0,0,0,119,
  	655,1,0,0,0,121,660,1,0,0,0,123,663,1,0,0,0,125,668,1,0,0,0,127,673,1,
  	0,0,0,129,676,1,0,0,0,131,679,1,0,0,0,133,682,1,0,0,0,135,685,1,0,0,0,
  	137,690,1,0,0,0,139,695,1,0,0,0,141,698,1,0,0,0,143,703,1,0,0,0,145,706,
  	1,0,0,0,147,711,1,0,0,0,149,714,1,0,0,0,151,719,1,0,0,0,153,724,1,0,0,
  	0,155,730,1,0,0,0,157,736,1,0,0,0,159,743,1,0,0,0,161,748,1,0,0,0,163,
  	754,1,0,0,0,165,759,1,0,0,0,167,765,1,0,0,0,169,771,1,0,0,0,171,778,1,
  	0,0,0,173,783,1,0,0,0,175,789,1,0,0,0,177,794,1,0,0,0,179,800,1,0,0,0,
  	181,805,1,0,0,0,183,811,1,0,0,0,185,816,1,0,0,0,187,821,1,0,0,0,189,827,
  	1,0,0,0,191,831,1,0,0,0,193,836,1,0,0,0,195,196,5,46,0,0,196,197,5,46,
  	0,0,197,198,5,46,0,0,198,199,1,0,0,0,199,200,6,0,0,0,200,2,1,0,0,0,201,
  	203,7,0,0,0,202,201,1,0,0,0,203,204,1,0,0,0,204,202,1,0,0,0,204,205,1,
  	0,0,0,205,206,1,0,0,0,206,207,6,1,1,0,207,4,1,0,0,0,208,254,4,2,0,0,209,
  	211,7,0,0,0,210,209,1,0,0,0,211,214,1,0,0,0,212,210,1,0,0,0,212,213,1,
  	0,0,0,213,215,1,0,0,0,214,212,1,0,0,0,215,217,5,46,0,0,216,218,7,0,0,
  	0,217,216,1,0,0,0,218,219,1,0,0,0,219,217,1,0,0,0,219,220,1,0,0,0,220,
  	228,1,0,0,0,221,223,7,0,0,0,222,221,1,0,0,0,223,224,1,0,0,0,224,222,1,
  	0,0,0,224,225,1,0,0,0,225,226,1,0,0,0,226,228,5,46,0,0,227,212,1,0,0,
  	0,227,222,1,0,0,0,228,238,1,0,0,0,229,231,7,1,0,0,230,232,7,2,0,0,231,
  	230,1,0,0,0,231,232,1,0,0,0,232,234,1,0,0,0,233,235,7,0,0,0,234,233,1,
  	0,0,0,235,236,1,0,0,0,236,234,1,0,0,0,236,237,1,0,0,0,237,239,1,0,0,0,
  	238,229,1,0,0,0,238,239,1,0,0,0,239,255,1,0,0,0,240,242,7,0,0,0,241,240,
  	1,0,0,0,242,243,1,0,0,0,243,241,1,0,0,0,243,244,1,0,0,0,244,245,1,0,0,
  	0,245,247,7,1,0,0,246,248,7,2,0,0,247,246,1,0,0,0,247,248,1,0,0,0,248,
  	250,1,0,0,0,249,251,7,0,0,0,250,249,1,0,0,0,251,252,1,0,0,0,252,250,1,
  	0,0,0,252,253,1,0,0,0,253,255,1,0,0,0,254,227,1,0,0,0,254,241,1,0,0,0,
  	255,256,1,0,0,0,256,257,6,2,2,0,257,6,1,0,0,0,258,260,3,9,4,0,259,261,
  	3,11,5,0,260,259,1,0,0,0,260,261,1,0,0,0,261,265,1,0,0,0,262,264,7,2,
  	0,0,263,262,1,0,0,0,264,267,1,0,0,0,265,263,1,0,0,0,265,266,1,0,0,0,266,
  	268,1,0,0,0,267,265,1,0,0,0,268,281,3,3,1,0,269,271,7,2,0,0,270,269,1,
  	0,0,0,271,274,1,0,0,0,272,270,1,0,0,0,272,273,1,0,0,0,273,277,1,0,0,0,
  	274,272,1,0,0,0,275,278,3,3,1,0,276,278,3,13,6,0,277,275,1,0,0,0,277,
  	276,1,0,0,0,278,279,1,0,0,0,279,280,5,116,0,0,280,282,1,0,0,0,281,272,
  	1,0,0,0,281,282,1,0,0,0,282,283,1,0,0,0,283,284,6,3,3,0,284,8,1,0,0,0,
  	285,287,7,3,0,0,286,285,1,0,0,0,287,10,1,0,0,0,288,290,7,4,0,0,289,288,
  	1,0,0,0,290,291,1,0,0,0,291,289,1,0,0,0,291,292,1,0,0,0,292,12,1,0,0,
  	0,293,294,3,3,1,0,294,298,5,47,0,0,295,297,7,2,0,0,296,295,1,0,0,0,297,
  	300,1,0,0,0,298,296,1,0,0,0,298,299,1,0,0,0,299,301,1,0,0,0,300,298,1,
  	0,0,0,301,302,3,3,1,0,302,14,1,0,0,0,303,305,5,96,0,0,304,306,8,5,0,0,
  	305,304,1,0,0,0,306,307,1,0,0,0,307,305,1,0,0,0,307,308,1,0,0,0,308,309,
  	1,0,0,0,309,310,6,7,4,0,310,16,1,0,0,0,311,317,5,34,0,0,312,313,5,92,
  	0,0,313,316,5,34,0,0,314,316,8,6,0,0,315,312,1,0,0,0,315,314,1,0,0,0,
  	316,319,1,0,0,0,317,315,1,0,0,0,317,318,1,0,0,0,318,320,1,0,0,0,319,317,
  	1,0,0,0,320,321,8,7,0,0,321,322,5,34,0,0,322,323,6,8,5,0,323,18,1,0,0,
  	0,324,330,5,39,0,0,325,326,5,92,0,0,326,329,5,39,0,0,327,329,8,8,0,0,
  	328,325,1,0,0,0,328,327,1,0,0,0,329,332,1,0,0,0,330,328,1,0,0,0,330,331,
  	1,0,0,0,331,333,1,0,0,0,332,330,1,0,0,0,333,334,8,7,0,0,334,335,5,39,
  	0,0,335,336,6,9,6,0,336,20,1,0,0,0,337,338,5,110,0,0,338,339,5,117,0,
  	0,339,340,5,108,0,0,340,341,5,108,0,0,341,342,1,0,0,0,342,343,6,10,7,
  	0,343,22,1,0,0,0,344,345,5,110,0,0,345,346,5,105,0,0,346,347,5,108,0,
  	0,347,348,1,0,0,0,348,349,6,11,8,0,349,24,1,0,0,0,350,351,5,105,0,0,351,
  	352,5,102,0,0,352,353,1,0,0,0,353,354,6,12,9,0,354,26,1,0,0,0,355,356,
  	5,116,0,0,356,357,5,104,0,0,357,358,5,101,0,0,358,359,5,110,0,0,359,360,
  	1,0,0,0,360,361,6,13,10,0,361,28,1,0,0,0,362,363,5,101,0,0,363,364,5,
  	108,0,0,364,365,5,115,0,0,365,366,5,101,0,0,366,367,1,0,0,0,367,368,6,
  	14,11,0,368,30,1,0,0,0,369,370,5,119,0,0,370,371,5,104,0,0,371,372,5,
  	105,0,0,372,373,5,108,0,0,373,374,5,101,0,0,374,375,1,0,0,0,375,376,6,
  	15,12,0,376,32,1,0,0,0,377,378,5,102,0,0,378,379,5,111,0,0,379,380,5,
  	114,0,0,380,381,1,0,0,0,381,382,6,16,13,0,382,34,1,0,0,0,383,384,5,100,
  	0,0,384,385,5,111,0,0,385,386,1,0,0,0,386,387,6,17,14,0,387,36,1,0,0,
  	0,388,389,5,99,0,0,389,390,5,111,0,0,390,391,5,108,0,0,391,392,5,108,
  	0,0,392,393,5,101,0,0,393,394,5,99,0,0,394,395,5,116,0,0,395,396,1,0,
  	0,0,396,397,6,18,15,0,397,38,1,0,0,0,398,399,5,115,0,0,399,400,5,105,
  	0,0,400,411,5,110,0,0,401,402,5,99,0,0,402,403,5,111,0,0,403,411,5,115,
  	0,0,404,405,5,115,0,0,405,406,5,113,0,0,406,407,5,114,0,0,407,408,5,116,
  	0,0,408,409,1,0,0,0,409,411,6,19,16,0,410,398,1,0,0,0,410,401,1,0,0,0,
  	410,404,1,0,0,0,411,40,1,0,0,0,412,414,5,92,0,0,413,412,1,0,0,0,413,414,
  	1,0,0,0,414,415,1,0,0,0,415,416,5,36,0,0,416,418,7,9,0,0,417,419,7,0,
  	0,0,418,417,1,0,0,0,419,420,1,0,0,0,420,418,1,0,0,0,420,421,1,0,0,0,421,
  	422,1,0,0,0,422,423,6,20,17,0,423,42,1,0,0,0,424,426,5,92,0,0,425,424,
  	1,0,0,0,425,426,1,0,0,0,426,427,1,0,0,0,427,428,5,36,0,0,428,429,5,105,
  	0,0,429,431,1,0,0,0,430,432,7,0,0,0,431,430,1,0,0,0,432,433,1,0,0,0,433,
  	431,1,0,0,0,433,434,1,0,0,0,434,435,1,0,0,0,435,436,6,21,18,0,436,44,
  	1,0,0,0,437,439,5,92,0,0,438,437,1,0,0,0,438,439,1,0,0,0,439,440,1,0,
  	0,0,440,441,5,36,0,0,441,442,5,114,0,0,442,444,1,0,0,0,443,445,7,0,0,
  	0,444,443,1,0,0,0,445,446,1,0,0,0,446,444,1,0,0,0,446,447,1,0,0,0,447,
  	448,1,0,0,0,448,449,6,22,19,0,449,46,1,0,0,0,450,452,5,92,0,0,451,450,
  	1,0,0,0,451,452,1,0,0,0,452,453,1,0,0,0,453,454,5,36,0,0,454,455,5,102,
  	0,0,455,457,1,0,0,0,456,458,7,0,0,0,457,456,1,0,0,0,458,459,1,0,0,0,459,
  	457,1,0,0,0,459,460,1,0,0,0,460,461,1,0,0,0,461,462,6,23,20,0,462,48,
  	1,0,0,0,463,465,5,92,0,0,464,463,1,0,0,0,464,465,1,0,0,0,465,466,1,0,
  	0,0,466,467,5,36,0,0,467,468,5,112,0,0,468,470,1,0,0,0,469,471,7,0,0,
  	0,470,469,1,0,0,0,471,472,1,0,0,0,472,470,1,0,0,0,472,473,1,0,0,0,473,
  	474,1,0,0,0,474,475,6,24,21,0,475,50,1,0,0,0,476,478,5,92,0,0,477,476,
  	1,0,0,0,477,478,1,0,0,0,478,479,1,0,0,0,479,480,5,36,0,0,480,481,5,111,
  	0,0,481,483,1,0,0,0,482,484,7,0,0,0,483,482,1,0,0,0,484,485,1,0,0,0,485,
  	483,1,0,0,0,485,486,1,0,0,0,486,487,1,0,0,0,487,488,6,25,22,0,488,52,
  	1,0,0,0,489,491,5,92,0,0,490,489,1,0,0,0,490,491,1,0,0,0,491,492,1,0,
  	0,0,492,493,5,36,0,0,493,494,5,100,0,0,494,495,5,120,0,0,495,497,1,0,
  	0,0,496,498,7,0,0,0,497,496,1,0,0,0,498,499,1,0,0,0,499,497,1,0,0,0,499,
  	500,1,0,0,0,500,501,1,0,0,0,501,502,6,26,23,0,502,54,1,0,0,0,503,505,
  	5,92,0,0,504,503,1,0,0,0,504,505,1,0,0,0,505,506,1,0,0,0,506,507,5,36,
  	0,0,507,508,5,100,0,0,508,509,5,111,0,0,509,511,1,0,0,0,510,512,7,0,0,
  	0,511,510,1,0,0,0,512,513,1,0,0,0,513,511,1,0,0,0,513,514,1,0,0,0,514,
  	515,1,0,0,0,515,516,6,27,24,0,516,56,1,0,0,0,517,518,3,65,32,0,518,519,
  	6,28,25,0,519,58,1,0,0,0,520,521,5,35,0,0,521,522,3,65,32,0,522,523,6,
  	29,26,0,523,60,1,0,0,0,524,526,5,92,0,0,525,524,1,0,0,0,525,526,1,0,0,
  	0,526,527,1,0,0,0,527,528,5,36,0,0,528,529,3,65,32,0,529,530,6,30,27,
  	0,530,62,1,0,0,0,531,533,5,92,0,0,532,531,1,0,0,0,532,533,1,0,0,0,533,
  	534,1,0,0,0,534,535,5,64,0,0,535,536,3,65,32,0,536,537,6,31,28,0,537,
  	64,1,0,0,0,538,546,7,10,0,0,539,541,7,11,0,0,540,539,1,0,0,0,541,544,
  	1,0,0,0,542,540,1,0,0,0,542,543,1,0,0,0,543,545,1,0,0,0,544,542,1,0,0,
  	0,545,547,7,12,0,0,546,542,1,0,0,0,546,547,1,0,0,0,547,66,1,0,0,0,548,
  	549,5,91,0,0,549,550,6,33,29,0,550,68,1,0,0,0,551,552,5,93,0,0,552,553,
  	6,34,30,0,553,70,1,0,0,0,554,555,5,41,0,0,555,556,6,35,31,0,556,72,1,
  	0,0,0,557,558,5,58,0,0,558,559,6,36,32,0,559,74,1,0,0,0,560,561,5,58,
  	0,0,561,562,5,58,0,0,562,563,1,0,0,0,563,564,6,37,33,0,564,76,1,0,0,0,
  	565,566,5,46,0,0,566,567,6,38,34,0,567,78,1,0,0,0,568,569,5,58,0,0,569,
  	570,5,61,0,0,570,571,1,0,0,0,571,572,6,39,35,0,572,80,1,0,0,0,573,574,
  	5,58,0,0,574,575,5,58,0,0,575,576,5,61,0,0,576,577,1,0,0,0,577,578,6,
  	40,36,0,578,82,1,0,0,0,579,580,5,59,0,0,580,581,6,41,37,0,581,84,1,0,
  	0,0,582,583,5,61,0,0,583,584,6,42,38,0,584,86,1,0,0,0,585,586,7,5,0,0,
  	586,587,6,43,39,0,587,588,1,0,0,0,588,589,6,43,40,0,589,88,1,0,0,0,590,
  	591,7,13,0,0,591,592,6,44,41,0,592,593,1,0,0,0,593,594,6,44,40,0,594,
  	90,1,0,0,0,595,596,5,42,0,0,596,597,5,42,0,0,597,598,1,0,0,0,598,599,
  	6,45,42,0,599,92,1,0,0,0,600,601,5,42,0,0,601,602,5,42,0,0,602,603,5,
  	61,0,0,603,604,1,0,0,0,604,605,6,46,43,0,605,94,1,0,0,0,606,607,5,42,
  	0,0,607,608,6,47,44,0,608,96,1,0,0,0,609,610,5,42,0,0,610,611,5,61,0,
  	0,611,612,1,0,0,0,612,613,6,48,45,0,613,98,1,0,0,0,614,615,5,47,0,0,615,
  	616,5,47,0,0,616,617,1,0,0,0,617,618,6,49,46,0,618,100,1,0,0,0,619,620,
  	5,47,0,0,620,621,5,47,0,0,621,622,5,61,0,0,622,623,1,0,0,0,623,624,6,
  	50,47,0,624,102,1,0,0,0,625,626,5,47,0,0,626,627,6,51,48,0,627,104,1,
  	0,0,0,628,629,5,47,0,0,629,630,5,61,0,0,630,631,1,0,0,0,631,632,6,52,
  	49,0,632,106,1,0,0,0,633,634,5,37,0,0,634,635,6,53,50,0,635,108,1,0,0,
  	0,636,637,5,37,0,0,637,638,6,54,51,0,638,110,1,0,0,0,639,640,4,55,1,0,
  	640,641,5,43,0,0,641,642,6,55,52,0,642,112,1,0,0,0,643,644,5,43,0,0,644,
  	645,5,61,0,0,645,646,1,0,0,0,646,647,6,56,53,0,647,114,1,0,0,0,648,649,
  	5,43,0,0,649,650,6,57,54,0,650,116,1,0,0,0,651,652,4,58,2,0,652,653,5,
  	45,0,0,653,654,6,58,55,0,654,118,1,0,0,0,655,656,5,45,0,0,656,657,5,61,
  	0,0,657,658,1,0,0,0,658,659,6,59,56,0,659,120,1,0,0,0,660,661,5,45,0,
  	0,661,662,6,60,57,0,662,122,1,0,0,0,663,664,5,61,0,0,664,665,5,61,0,0,
  	665,666,1,0,0,0,666,667,6,61,58,0,667,124,1,0,0,0,668,669,5,33,0,0,669,
  	670,5,61,0,0,670,671,1,0,0,0,671,672,6,62,59,0,672,126,1,0,0,0,673,674,
  	5,33,0,0,674,675,6,63,60,0,675,128,1,0,0,0,676,677,5,126,0,0,677,678,
  	6,64,61,0,678,130,1,0,0,0,679,680,5,60,0,0,680,681,6,65,62,0,681,132,
  	1,0,0,0,682,683,5,62,0,0,683,684,6,66,63,0,684,134,1,0,0,0,685,686,5,
  	60,0,0,686,687,5,61,0,0,687,688,1,0,0,0,688,689,6,67,64,0,689,136,1,0,
  	0,0,690,691,5,62,0,0,691,692,5,61,0,0,692,693,1,0,0,0,693,694,6,68,65,
  	0,694,138,1,0,0,0,695,696,5,38,0,0,696,697,6,69,66,0,697,140,1,0,0,0,
  	698,699,5,38,0,0,699,700,5,61,0,0,700,701,1,0,0,0,701,702,6,70,67,0,702,
  	142,1,0,0,0,703,704,5,94,0,0,704,705,6,71,68,0,705,144,1,0,0,0,706,707,
  	5,94,0,0,707,708,5,61,0,0,708,709,1,0,0,0,709,710,6,72,69,0,710,146,1,
  	0,0,0,711,712,5,124,0,0,712,713,6,73,70,0,713,148,1,0,0,0,714,715,5,124,
  	0,0,715,716,5,61,0,0,716,717,1,0,0,0,717,718,6,74,71,0,718,150,1,0,0,
  	0,719,720,5,38,0,0,720,721,5,38,0,0,721,722,1,0,0,0,722,723,6,75,72,0,
  	723,152,1,0,0,0,724,725,5,38,0,0,725,726,5,38,0,0,726,727,5,38,0,0,727,
  	728,1,0,0,0,728,729,6,76,73,0,729,154,1,0,0,0,730,731,5,38,0,0,731,732,
  	5,38,0,0,732,733,5,61,0,0,733,734,1,0,0,0,734,735,6,77,74,0,735,156,1,
  	0,0,0,736,737,5,38,0,0,737,738,5,38,0,0,738,739,5,38,0,0,739,740,5,61,
  	0,0,740,741,1,0,0,0,741,742,6,78,75,0,742,158,1,0,0,0,743,744,5,94,0,
  	0,744,745,5,94,0,0,745,746,1,0,0,0,746,747,6,79,76,0,747,160,1,0,0,0,
  	748,749,5,94,0,0,749,750,5,94,0,0,750,751,5,61,0,0,751,752,1,0,0,0,752,
  	753,6,80,77,0,753,162,1,0,0,0,754,755,5,124,0,0,755,756,5,124,0,0,756,
  	757,1,0,0,0,757,758,6,81,78,0,758,164,1,0,0,0,759,760,5,124,0,0,760,761,
  	5,124,0,0,761,762,5,61,0,0,762,763,1,0,0,0,763,764,6,82,79,0,764,166,
  	1,0,0,0,765,766,5,124,0,0,766,767,5,124,0,0,767,768,5,124,0,0,768,769,
  	1,0,0,0,769,770,6,83,80,0,770,168,1,0,0,0,771,772,5,124,0,0,772,773,5,
  	124,0,0,773,774,5,124,0,0,774,775,5,61,0,0,775,776,1,0,0,0,776,777,6,
  	84,81,0,777,170,1,0,0,0,778,779,5,60,0,0,779,780,5,60,0,0,780,781,1,0,
  	0,0,781,782,6,85,82,0,782,172,1,0,0,0,783,784,5,60,0,0,784,785,5,60,0,
  	0,785,786,5,61,0,0,786,787,1,0,0,0,787,788,6,86,83,0,788,174,1,0,0,0,
  	789,790,5,62,0,0,790,791,5,62,0,0,791,792,1,0,0,0,792,793,6,87,84,0,793,
  	176,1,0,0,0,794,795,5,62,0,0,795,796,5,62,0,0,796,797,5,61,0,0,797,798,
  	1,0,0,0,798,799,6,88,85,0,799,178,1,0,0,0,800,801,5,58,0,0,801,802,5,
  	42,0,0,802,803,1,0,0,0,803,804,6,89,86,0,804,180,1,0,0,0,805,806,5,58,
  	0,0,806,807,5,42,0,0,807,808,5,61,0,0,808,809,1,0,0,0,809,810,6,90,87,
  	0,810,182,1,0,0,0,811,812,5,46,0,0,812,813,5,61,0,0,813,814,1,0,0,0,814,
  	815,6,91,88,0,815,184,1,0,0,0,816,817,5,95,0,0,817,818,5,61,0,0,818,819,
  	1,0,0,0,819,820,6,92,89,0,820,186,1,0,0,0,821,822,5,33,0,0,822,823,5,
  	95,0,0,823,824,5,61,0,0,824,825,1,0,0,0,825,826,6,93,90,0,826,188,1,0,
  	0,0,827,828,4,94,3,0,828,829,5,40,0,0,829,830,6,94,91,0,830,190,1,0,0,
  	0,831,832,4,95,4,0,832,833,5,40,0,0,833,834,6,95,92,0,834,192,1,0,0,0,
  	835,837,9,0,0,0,836,835,1,0,0,0,837,838,1,0,0,0,838,839,1,0,0,0,838,836,
  	1,0,0,0,839,194,1,0,0,0,48,0,204,212,219,224,227,231,236,238,243,247,
  	252,254,260,265,272,277,281,286,291,298,307,315,317,328,330,410,413,420,
  	425,433,438,446,451,459,464,472,477,485,490,499,504,513,525,532,542,546,
  	838,93,1,0,0,1,1,1,1,2,2,1,3,3,1,7,4,1,8,5,1,9,6,1,10,7,1,11,8,1,12,9,
  	1,13,10,1,14,11,1,15,12,1,16,13,1,17,14,1,18,15,1,19,16,1,20,17,1,21,
  	18,1,22,19,1,23,20,1,24,21,1,25,22,1,26,23,1,27,24,1,28,25,1,29,26,1,
  	30,27,1,31,28,1,33,29,1,34,30,1,35,31,1,36,32,1,37,33,1,38,34,1,39,35,
  	1,40,36,1,41,37,1,42,38,1,43,39,0,1,0,1,44,40,1,45,41,1,46,42,1,47,43,
  	1,48,44,1,49,45,1,50,46,1,51,47,1,52,48,1,53,49,1,54,50,1,55,51,1,56,
  	52,1,57,53,1,58,54,1,59,55,1,60,56,1,61,57,1,62,58,1,63,59,1,64,60,1,
  	65,61,1,66,62,1,67,63,1,68,64,1,69,65,1,70,66,1,71,67,1,72,68,1,73,69,
  	1,74,70,1,75,71,1,76,72,1,77,73,1,78,74,1,79,75,1,80,76,1,81,77,1,82,
  	78,1,83,79,1,84,80,1,85,81,1,86,82,1,87,83,1,88,84,1,89,85,1,90,86,1,
  	91,87,1,92,88,1,93,89,1,94,90,1,95,91
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
    case 2: return UFLOATSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
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


bool bellLexer::UFLOATSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return  notUintRange();

  default:
    break;
  }
  return true;
}

bool bellLexer::PLUSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return  notUnary() ;

  default:
    break;
  }
  return true;
}

bool bellLexer::MINUSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return  notUnary() ;

  default:
    break;
  }
  return true;
}

bool bellLexer::OPENSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return  noParams ;

  default:
    break;
  }
  return true;
}

bool bellLexer::PARAMSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return  !noParams ;

  default:
    break;
  }
  return true;
}


void bellLexer::initialize() {
  std::call_once(belllexerLexerOnceFlag, belllexerLexerInitialize);
}
