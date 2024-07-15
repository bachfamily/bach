 
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
      "UINT", "UFLOAT", "UPITCH", "NOTENAME", "ACCIDENTAL", "RAT", "BTSYMBOL", 
      "DQSYMBOL", "SQSYMBOL", "BACHNULL", "BACHNIL", "IF", "THEN", "ELSE", 
      "WHILE", "FOR", "DO", "COLLECT", "FUNCTION", "INLET", "INTINLET", 
      "RATINLET", "FLOATINLET", "PITCHINLET", "OUTLET", "DIRINLET", "DIROUTLET", 
      "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "NAMEDPARAM", "ID", "PUSH", 
      "POP", "CLOSED", "NTH", "PICK", "KEY", "ANTH", "APICK", "NULLIFY", 
      "ASSIGN", "WHITESPACE", "NEWATOM", "POW", "APOW", "TIMES", "ATIMES", 
      "DIVDIV", "ADIVDIV", "DIV", "ADIV", "REM", "AREM", "PLUS", "APLUS", 
      "UPLUS", "MINUS", "AMINUS", "UMINUS", "EQUAL", "NEQ", "LOGNOT", "BITNOT", 
      "LT", "GT", "LEQ", "GEQ", "BITAND", "ABITAND", "BITXOR", "ABITXOR", 
      "BITOR", "ABITOR", "LOGAND", "LOGANDEXT", "ALOGAND", "ALOGANDEXT", 
      "LOGXOR", "ALOGXOR", "LOGOR", "ALOGOR", "LOGOREXT", "ALOGOREXT", "LSHIFT", 
      "ALSHIFT", "RSHIFT", "ARSHIFT", "RANGE", "REPEAT", "AREPEAT", "AAPPLY", 
      "ACONCAT", "ARCONCAT", "OPEN", "PARAMS", "ANYTHING"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	7,91,2,92,7,92,2,93,7,93,2,94,7,94,2,95,7,95,2,96,7,96,1,0,4,0,197,8,
  	0,11,0,12,0,198,1,0,1,0,1,1,5,1,204,8,1,10,1,12,1,207,9,1,1,1,1,1,4,1,
  	211,8,1,11,1,12,1,212,1,1,4,1,216,8,1,11,1,12,1,217,1,1,3,1,221,8,1,1,
  	1,1,1,3,1,225,8,1,1,1,4,1,228,8,1,11,1,12,1,229,3,1,232,8,1,1,1,4,1,235,
  	8,1,11,1,12,1,236,1,1,1,1,3,1,241,8,1,1,1,4,1,244,8,1,11,1,12,1,245,3,
  	1,248,8,1,1,1,1,1,1,2,1,2,3,2,254,8,2,1,2,5,2,257,8,2,10,2,12,2,260,9,
  	2,1,2,1,2,5,2,264,8,2,10,2,12,2,267,9,2,1,2,1,2,3,2,271,8,2,1,2,1,2,3,
  	2,275,8,2,1,2,1,2,1,3,3,3,280,8,3,1,4,4,4,283,8,4,11,4,12,4,284,1,5,1,
  	5,1,5,5,5,290,8,5,10,5,12,5,293,9,5,1,5,1,5,1,6,1,6,4,6,299,8,6,11,6,
  	12,6,300,1,6,1,6,1,7,1,7,1,7,1,7,5,7,309,8,7,10,7,12,7,312,9,7,1,7,1,
  	7,1,7,1,7,1,8,1,8,1,8,1,8,5,8,322,8,8,10,8,12,8,325,9,8,1,8,1,8,1,8,1,
  	8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,
  	1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,
  	1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,
  	1,18,1,18,3,18,404,8,18,1,19,3,19,407,8,19,1,19,1,19,1,19,4,19,412,8,
  	19,11,19,12,19,413,1,19,1,19,1,20,3,20,419,8,20,1,20,1,20,1,20,1,20,4,
  	20,425,8,20,11,20,12,20,426,1,20,1,20,1,21,3,21,432,8,21,1,21,1,21,1,
  	21,1,21,4,21,438,8,21,11,21,12,21,439,1,21,1,21,1,22,3,22,445,8,22,1,
  	22,1,22,1,22,1,22,4,22,451,8,22,11,22,12,22,452,1,22,1,22,1,23,3,23,458,
  	8,23,1,23,1,23,1,23,1,23,4,23,464,8,23,11,23,12,23,465,1,23,1,23,1,24,
  	3,24,471,8,24,1,24,1,24,1,24,1,24,4,24,477,8,24,11,24,12,24,478,1,24,
  	1,24,1,25,3,25,484,8,25,1,25,1,25,1,25,1,25,1,25,4,25,491,8,25,11,25,
  	12,25,492,1,25,1,25,1,26,3,26,498,8,26,1,26,1,26,1,26,1,26,1,26,4,26,
  	505,8,26,11,26,12,26,506,1,26,1,26,1,27,1,27,1,27,1,28,1,28,1,28,1,28,
  	1,29,3,29,519,8,29,1,29,1,29,1,29,1,29,1,30,3,30,526,8,30,1,30,1,30,1,
  	30,1,30,1,31,1,31,5,31,534,8,31,10,31,12,31,537,9,31,1,31,3,31,540,8,
  	31,1,32,1,32,1,32,1,33,1,33,1,33,1,34,1,34,1,34,1,35,1,35,1,35,1,36,1,
  	36,1,36,1,36,1,36,1,37,1,37,1,37,1,38,1,38,1,38,1,38,1,38,1,39,1,39,1,
  	39,1,39,1,39,1,39,1,40,1,40,1,40,1,41,1,41,1,41,1,42,1,42,1,42,1,42,1,
  	42,1,43,1,43,1,43,1,43,1,43,1,44,1,44,1,44,1,44,1,44,1,45,1,45,1,45,1,
  	45,1,45,1,45,1,46,1,46,1,46,1,47,1,47,1,47,1,47,1,47,1,48,1,48,1,48,1,
  	48,1,48,1,49,1,49,1,49,1,49,1,49,1,49,1,50,1,50,1,50,1,51,1,51,1,51,1,
  	51,1,51,1,52,1,52,1,52,1,53,1,53,1,53,1,54,1,54,1,54,1,54,1,55,1,55,1,
  	55,1,55,1,55,1,56,1,56,1,56,1,57,1,57,1,57,1,57,1,58,1,58,1,58,1,58,1,
  	58,1,59,1,59,1,59,1,60,1,60,1,60,1,60,1,60,1,61,1,61,1,61,1,61,1,61,1,
  	62,1,62,1,62,1,63,1,63,1,63,1,64,1,64,1,64,1,65,1,65,1,65,1,66,1,66,1,
  	66,1,66,1,66,1,67,1,67,1,67,1,67,1,67,1,68,1,68,1,68,1,69,1,69,1,69,1,
  	69,1,69,1,70,1,70,1,70,1,71,1,71,1,71,1,71,1,71,1,72,1,72,1,72,1,73,1,
  	73,1,73,1,73,1,73,1,74,1,74,1,74,1,74,1,74,1,75,1,75,1,75,1,75,1,75,1,
  	75,1,76,1,76,1,76,1,76,1,76,1,76,1,77,1,77,1,77,1,77,1,77,1,77,1,77,1,
  	78,1,78,1,78,1,78,1,78,1,79,1,79,1,79,1,79,1,79,1,79,1,80,1,80,1,80,1,
  	80,1,80,1,81,1,81,1,81,1,81,1,81,1,81,1,82,1,82,1,82,1,82,1,82,1,82,1,
  	83,1,83,1,83,1,83,1,83,1,83,1,83,1,84,1,84,1,84,1,84,1,84,1,85,1,85,1,
  	85,1,85,1,85,1,85,1,86,1,86,1,86,1,86,1,86,1,87,1,87,1,87,1,87,1,87,1,
  	87,1,88,1,88,1,88,1,88,1,88,1,88,1,89,1,89,1,89,1,89,1,89,1,90,1,90,1,
  	90,1,90,1,90,1,90,1,91,1,91,1,91,1,91,1,91,1,92,1,92,1,92,1,92,1,92,1,
  	93,1,93,1,93,1,93,1,93,1,93,1,94,1,94,1,94,1,94,1,95,1,95,1,95,1,95,1,
  	96,4,96,836,8,96,11,96,12,96,837,1,837,0,97,1,1,3,2,5,3,7,0,9,0,11,0,
  	13,4,15,5,17,6,19,7,21,8,23,9,25,10,27,11,29,12,31,13,33,14,35,15,37,
  	16,39,17,41,18,43,19,45,20,47,21,49,22,51,23,53,24,55,25,57,26,59,27,
  	61,28,63,0,65,29,67,30,69,31,71,32,73,33,75,34,77,35,79,36,81,37,83,38,
  	85,39,87,40,89,41,91,42,93,43,95,44,97,45,99,46,101,47,103,48,105,49,
  	107,50,109,51,111,52,113,53,115,54,117,55,119,56,121,57,123,58,125,59,
  	127,60,129,61,131,62,133,63,135,64,137,65,139,66,141,67,143,68,145,69,
  	147,70,149,71,151,72,153,73,155,74,157,75,159,76,161,77,163,78,165,79,
  	167,80,169,81,171,82,173,83,175,84,177,85,179,86,181,87,183,88,185,89,
  	187,90,189,91,191,92,193,93,1,0,14,1,0,48,57,2,0,69,69,101,101,2,0,43,
  	43,45,45,2,0,65,71,97,103,7,0,35,35,94,94,98,98,100,100,113,113,118,118,
  	120,120,3,0,9,10,13,13,32,32,1,0,34,34,1,0,92,92,1,0,39,39,2,0,108,108,
  	120,120,2,0,65,90,97,122,4,0,48,57,65,90,95,95,97,122,3,0,48,57,65,90,
  	97,122,1,0,1,1,881,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,13,1,0,0,0,0,
  	15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,
  	0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,
  	0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,
  	47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,
  	0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,
  	0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,
  	81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,
  	0,0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,
  	0,0,103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,0,111,1,0,0,
  	0,0,113,1,0,0,0,0,115,1,0,0,0,0,117,1,0,0,0,0,119,1,0,0,0,0,121,1,0,0,
  	0,0,123,1,0,0,0,0,125,1,0,0,0,0,127,1,0,0,0,0,129,1,0,0,0,0,131,1,0,0,
  	0,0,133,1,0,0,0,0,135,1,0,0,0,0,137,1,0,0,0,0,139,1,0,0,0,0,141,1,0,0,
  	0,0,143,1,0,0,0,0,145,1,0,0,0,0,147,1,0,0,0,0,149,1,0,0,0,0,151,1,0,0,
  	0,0,153,1,0,0,0,0,155,1,0,0,0,0,157,1,0,0,0,0,159,1,0,0,0,0,161,1,0,0,
  	0,0,163,1,0,0,0,0,165,1,0,0,0,0,167,1,0,0,0,0,169,1,0,0,0,0,171,1,0,0,
  	0,0,173,1,0,0,0,0,175,1,0,0,0,0,177,1,0,0,0,0,179,1,0,0,0,0,181,1,0,0,
  	0,0,183,1,0,0,0,0,185,1,0,0,0,0,187,1,0,0,0,0,189,1,0,0,0,0,191,1,0,0,
  	0,0,193,1,0,0,0,1,196,1,0,0,0,3,247,1,0,0,0,5,251,1,0,0,0,7,279,1,0,0,
  	0,9,282,1,0,0,0,11,286,1,0,0,0,13,296,1,0,0,0,15,304,1,0,0,0,17,317,1,
  	0,0,0,19,330,1,0,0,0,21,337,1,0,0,0,23,343,1,0,0,0,25,348,1,0,0,0,27,
  	355,1,0,0,0,29,362,1,0,0,0,31,370,1,0,0,0,33,376,1,0,0,0,35,381,1,0,0,
  	0,37,403,1,0,0,0,39,406,1,0,0,0,41,418,1,0,0,0,43,431,1,0,0,0,45,444,
  	1,0,0,0,47,457,1,0,0,0,49,470,1,0,0,0,51,483,1,0,0,0,53,497,1,0,0,0,55,
  	510,1,0,0,0,57,513,1,0,0,0,59,518,1,0,0,0,61,525,1,0,0,0,63,531,1,0,0,
  	0,65,541,1,0,0,0,67,544,1,0,0,0,69,547,1,0,0,0,71,550,1,0,0,0,73,553,
  	1,0,0,0,75,558,1,0,0,0,77,561,1,0,0,0,79,566,1,0,0,0,81,572,1,0,0,0,83,
  	575,1,0,0,0,85,578,1,0,0,0,87,583,1,0,0,0,89,588,1,0,0,0,91,593,1,0,0,
  	0,93,599,1,0,0,0,95,602,1,0,0,0,97,607,1,0,0,0,99,612,1,0,0,0,101,618,
  	1,0,0,0,103,621,1,0,0,0,105,626,1,0,0,0,107,629,1,0,0,0,109,632,1,0,0,
  	0,111,636,1,0,0,0,113,641,1,0,0,0,115,644,1,0,0,0,117,648,1,0,0,0,119,
  	653,1,0,0,0,121,656,1,0,0,0,123,661,1,0,0,0,125,666,1,0,0,0,127,669,1,
  	0,0,0,129,672,1,0,0,0,131,675,1,0,0,0,133,678,1,0,0,0,135,683,1,0,0,0,
  	137,688,1,0,0,0,139,691,1,0,0,0,141,696,1,0,0,0,143,699,1,0,0,0,145,704,
  	1,0,0,0,147,707,1,0,0,0,149,712,1,0,0,0,151,717,1,0,0,0,153,723,1,0,0,
  	0,155,729,1,0,0,0,157,736,1,0,0,0,159,741,1,0,0,0,161,747,1,0,0,0,163,
  	752,1,0,0,0,165,758,1,0,0,0,167,764,1,0,0,0,169,771,1,0,0,0,171,776,1,
  	0,0,0,173,782,1,0,0,0,175,787,1,0,0,0,177,793,1,0,0,0,179,799,1,0,0,0,
  	181,804,1,0,0,0,183,810,1,0,0,0,185,815,1,0,0,0,187,820,1,0,0,0,189,826,
  	1,0,0,0,191,830,1,0,0,0,193,835,1,0,0,0,195,197,7,0,0,0,196,195,1,0,0,
  	0,197,198,1,0,0,0,198,196,1,0,0,0,198,199,1,0,0,0,199,200,1,0,0,0,200,
  	201,6,0,0,0,201,2,1,0,0,0,202,204,7,0,0,0,203,202,1,0,0,0,204,207,1,0,
  	0,0,205,203,1,0,0,0,205,206,1,0,0,0,206,208,1,0,0,0,207,205,1,0,0,0,208,
  	210,5,46,0,0,209,211,7,0,0,0,210,209,1,0,0,0,211,212,1,0,0,0,212,210,
  	1,0,0,0,212,213,1,0,0,0,213,221,1,0,0,0,214,216,7,0,0,0,215,214,1,0,0,
  	0,216,217,1,0,0,0,217,215,1,0,0,0,217,218,1,0,0,0,218,219,1,0,0,0,219,
  	221,5,46,0,0,220,205,1,0,0,0,220,215,1,0,0,0,221,231,1,0,0,0,222,224,
  	7,1,0,0,223,225,7,2,0,0,224,223,1,0,0,0,224,225,1,0,0,0,225,227,1,0,0,
  	0,226,228,7,0,0,0,227,226,1,0,0,0,228,229,1,0,0,0,229,227,1,0,0,0,229,
  	230,1,0,0,0,230,232,1,0,0,0,231,222,1,0,0,0,231,232,1,0,0,0,232,248,1,
  	0,0,0,233,235,7,0,0,0,234,233,1,0,0,0,235,236,1,0,0,0,236,234,1,0,0,0,
  	236,237,1,0,0,0,237,238,1,0,0,0,238,240,7,1,0,0,239,241,7,2,0,0,240,239,
  	1,0,0,0,240,241,1,0,0,0,241,243,1,0,0,0,242,244,7,0,0,0,243,242,1,0,0,
  	0,244,245,1,0,0,0,245,243,1,0,0,0,245,246,1,0,0,0,246,248,1,0,0,0,247,
  	220,1,0,0,0,247,234,1,0,0,0,248,249,1,0,0,0,249,250,6,1,1,0,250,4,1,0,
  	0,0,251,253,3,7,3,0,252,254,3,9,4,0,253,252,1,0,0,0,253,254,1,0,0,0,254,
  	258,1,0,0,0,255,257,7,2,0,0,256,255,1,0,0,0,257,260,1,0,0,0,258,256,1,
  	0,0,0,258,259,1,0,0,0,259,261,1,0,0,0,260,258,1,0,0,0,261,274,3,1,0,0,
  	262,264,7,2,0,0,263,262,1,0,0,0,264,267,1,0,0,0,265,263,1,0,0,0,265,266,
  	1,0,0,0,266,270,1,0,0,0,267,265,1,0,0,0,268,271,3,1,0,0,269,271,3,11,
  	5,0,270,268,1,0,0,0,270,269,1,0,0,0,271,272,1,0,0,0,272,273,5,116,0,0,
  	273,275,1,0,0,0,274,265,1,0,0,0,274,275,1,0,0,0,275,276,1,0,0,0,276,277,
  	6,2,2,0,277,6,1,0,0,0,278,280,7,3,0,0,279,278,1,0,0,0,280,8,1,0,0,0,281,
  	283,7,4,0,0,282,281,1,0,0,0,283,284,1,0,0,0,284,282,1,0,0,0,284,285,1,
  	0,0,0,285,10,1,0,0,0,286,287,3,1,0,0,287,291,5,47,0,0,288,290,7,2,0,0,
  	289,288,1,0,0,0,290,293,1,0,0,0,291,289,1,0,0,0,291,292,1,0,0,0,292,294,
  	1,0,0,0,293,291,1,0,0,0,294,295,3,1,0,0,295,12,1,0,0,0,296,298,5,96,0,
  	0,297,299,8,5,0,0,298,297,1,0,0,0,299,300,1,0,0,0,300,298,1,0,0,0,300,
  	301,1,0,0,0,301,302,1,0,0,0,302,303,6,6,3,0,303,14,1,0,0,0,304,310,5,
  	34,0,0,305,306,5,92,0,0,306,309,5,34,0,0,307,309,8,6,0,0,308,305,1,0,
  	0,0,308,307,1,0,0,0,309,312,1,0,0,0,310,308,1,0,0,0,310,311,1,0,0,0,311,
  	313,1,0,0,0,312,310,1,0,0,0,313,314,8,7,0,0,314,315,5,34,0,0,315,316,
  	6,7,4,0,316,16,1,0,0,0,317,323,5,39,0,0,318,319,5,92,0,0,319,322,5,39,
  	0,0,320,322,8,8,0,0,321,318,1,0,0,0,321,320,1,0,0,0,322,325,1,0,0,0,323,
  	321,1,0,0,0,323,324,1,0,0,0,324,326,1,0,0,0,325,323,1,0,0,0,326,327,8,
  	7,0,0,327,328,5,39,0,0,328,329,6,8,5,0,329,18,1,0,0,0,330,331,5,110,0,
  	0,331,332,5,117,0,0,332,333,5,108,0,0,333,334,5,108,0,0,334,335,1,0,0,
  	0,335,336,6,9,6,0,336,20,1,0,0,0,337,338,5,110,0,0,338,339,5,105,0,0,
  	339,340,5,108,0,0,340,341,1,0,0,0,341,342,6,10,7,0,342,22,1,0,0,0,343,
  	344,5,105,0,0,344,345,5,102,0,0,345,346,1,0,0,0,346,347,6,11,8,0,347,
  	24,1,0,0,0,348,349,5,116,0,0,349,350,5,104,0,0,350,351,5,101,0,0,351,
  	352,5,110,0,0,352,353,1,0,0,0,353,354,6,12,9,0,354,26,1,0,0,0,355,356,
  	5,101,0,0,356,357,5,108,0,0,357,358,5,115,0,0,358,359,5,101,0,0,359,360,
  	1,0,0,0,360,361,6,13,10,0,361,28,1,0,0,0,362,363,5,119,0,0,363,364,5,
  	104,0,0,364,365,5,105,0,0,365,366,5,108,0,0,366,367,5,101,0,0,367,368,
  	1,0,0,0,368,369,6,14,11,0,369,30,1,0,0,0,370,371,5,102,0,0,371,372,5,
  	111,0,0,372,373,5,114,0,0,373,374,1,0,0,0,374,375,6,15,12,0,375,32,1,
  	0,0,0,376,377,5,100,0,0,377,378,5,111,0,0,378,379,1,0,0,0,379,380,6,16,
  	13,0,380,34,1,0,0,0,381,382,5,99,0,0,382,383,5,111,0,0,383,384,5,108,
  	0,0,384,385,5,108,0,0,385,386,5,101,0,0,386,387,5,99,0,0,387,388,5,116,
  	0,0,388,389,1,0,0,0,389,390,6,17,14,0,390,36,1,0,0,0,391,392,5,115,0,
  	0,392,393,5,105,0,0,393,404,5,110,0,0,394,395,5,99,0,0,395,396,5,111,
  	0,0,396,404,5,115,0,0,397,398,5,115,0,0,398,399,5,113,0,0,399,400,5,114,
  	0,0,400,401,5,116,0,0,401,402,1,0,0,0,402,404,6,18,15,0,403,391,1,0,0,
  	0,403,394,1,0,0,0,403,397,1,0,0,0,404,38,1,0,0,0,405,407,5,92,0,0,406,
  	405,1,0,0,0,406,407,1,0,0,0,407,408,1,0,0,0,408,409,5,36,0,0,409,411,
  	7,9,0,0,410,412,7,0,0,0,411,410,1,0,0,0,412,413,1,0,0,0,413,411,1,0,0,
  	0,413,414,1,0,0,0,414,415,1,0,0,0,415,416,6,19,16,0,416,40,1,0,0,0,417,
  	419,5,92,0,0,418,417,1,0,0,0,418,419,1,0,0,0,419,420,1,0,0,0,420,421,
  	5,36,0,0,421,422,5,105,0,0,422,424,1,0,0,0,423,425,7,0,0,0,424,423,1,
  	0,0,0,425,426,1,0,0,0,426,424,1,0,0,0,426,427,1,0,0,0,427,428,1,0,0,0,
  	428,429,6,20,17,0,429,42,1,0,0,0,430,432,5,92,0,0,431,430,1,0,0,0,431,
  	432,1,0,0,0,432,433,1,0,0,0,433,434,5,36,0,0,434,435,5,114,0,0,435,437,
  	1,0,0,0,436,438,7,0,0,0,437,436,1,0,0,0,438,439,1,0,0,0,439,437,1,0,0,
  	0,439,440,1,0,0,0,440,441,1,0,0,0,441,442,6,21,18,0,442,44,1,0,0,0,443,
  	445,5,92,0,0,444,443,1,0,0,0,444,445,1,0,0,0,445,446,1,0,0,0,446,447,
  	5,36,0,0,447,448,5,102,0,0,448,450,1,0,0,0,449,451,7,0,0,0,450,449,1,
  	0,0,0,451,452,1,0,0,0,452,450,1,0,0,0,452,453,1,0,0,0,453,454,1,0,0,0,
  	454,455,6,22,19,0,455,46,1,0,0,0,456,458,5,92,0,0,457,456,1,0,0,0,457,
  	458,1,0,0,0,458,459,1,0,0,0,459,460,5,36,0,0,460,461,5,112,0,0,461,463,
  	1,0,0,0,462,464,7,0,0,0,463,462,1,0,0,0,464,465,1,0,0,0,465,463,1,0,0,
  	0,465,466,1,0,0,0,466,467,1,0,0,0,467,468,6,23,20,0,468,48,1,0,0,0,469,
  	471,5,92,0,0,470,469,1,0,0,0,470,471,1,0,0,0,471,472,1,0,0,0,472,473,
  	5,36,0,0,473,474,5,111,0,0,474,476,1,0,0,0,475,477,7,0,0,0,476,475,1,
  	0,0,0,477,478,1,0,0,0,478,476,1,0,0,0,478,479,1,0,0,0,479,480,1,0,0,0,
  	480,481,6,24,21,0,481,50,1,0,0,0,482,484,5,92,0,0,483,482,1,0,0,0,483,
  	484,1,0,0,0,484,485,1,0,0,0,485,486,5,36,0,0,486,487,5,100,0,0,487,488,
  	5,120,0,0,488,490,1,0,0,0,489,491,7,0,0,0,490,489,1,0,0,0,491,492,1,0,
  	0,0,492,490,1,0,0,0,492,493,1,0,0,0,493,494,1,0,0,0,494,495,6,25,22,0,
  	495,52,1,0,0,0,496,498,5,92,0,0,497,496,1,0,0,0,497,498,1,0,0,0,498,499,
  	1,0,0,0,499,500,5,36,0,0,500,501,5,100,0,0,501,502,5,111,0,0,502,504,
  	1,0,0,0,503,505,7,0,0,0,504,503,1,0,0,0,505,506,1,0,0,0,506,504,1,0,0,
  	0,506,507,1,0,0,0,507,508,1,0,0,0,508,509,6,26,23,0,509,54,1,0,0,0,510,
  	511,3,63,31,0,511,512,6,27,24,0,512,56,1,0,0,0,513,514,5,35,0,0,514,515,
  	3,63,31,0,515,516,6,28,25,0,516,58,1,0,0,0,517,519,5,92,0,0,518,517,1,
  	0,0,0,518,519,1,0,0,0,519,520,1,0,0,0,520,521,5,36,0,0,521,522,3,63,31,
  	0,522,523,6,29,26,0,523,60,1,0,0,0,524,526,5,92,0,0,525,524,1,0,0,0,525,
  	526,1,0,0,0,526,527,1,0,0,0,527,528,5,64,0,0,528,529,3,63,31,0,529,530,
  	6,30,27,0,530,62,1,0,0,0,531,539,7,10,0,0,532,534,7,11,0,0,533,532,1,
  	0,0,0,534,537,1,0,0,0,535,533,1,0,0,0,535,536,1,0,0,0,536,538,1,0,0,0,
  	537,535,1,0,0,0,538,540,7,12,0,0,539,535,1,0,0,0,539,540,1,0,0,0,540,
  	64,1,0,0,0,541,542,5,91,0,0,542,543,6,32,28,0,543,66,1,0,0,0,544,545,
  	5,93,0,0,545,546,6,33,29,0,546,68,1,0,0,0,547,548,5,41,0,0,548,549,6,
  	34,30,0,549,70,1,0,0,0,550,551,5,58,0,0,551,552,6,35,31,0,552,72,1,0,
  	0,0,553,554,5,58,0,0,554,555,5,58,0,0,555,556,1,0,0,0,556,557,6,36,32,
  	0,557,74,1,0,0,0,558,559,5,46,0,0,559,560,6,37,33,0,560,76,1,0,0,0,561,
  	562,5,58,0,0,562,563,5,61,0,0,563,564,1,0,0,0,564,565,6,38,34,0,565,78,
  	1,0,0,0,566,567,5,58,0,0,567,568,5,58,0,0,568,569,5,61,0,0,569,570,1,
  	0,0,0,570,571,6,39,35,0,571,80,1,0,0,0,572,573,5,59,0,0,573,574,6,40,
  	36,0,574,82,1,0,0,0,575,576,5,61,0,0,576,577,6,41,37,0,577,84,1,0,0,0,
  	578,579,7,5,0,0,579,580,6,42,38,0,580,581,1,0,0,0,581,582,6,42,39,0,582,
  	86,1,0,0,0,583,584,7,13,0,0,584,585,6,43,40,0,585,586,1,0,0,0,586,587,
  	6,43,39,0,587,88,1,0,0,0,588,589,5,42,0,0,589,590,5,42,0,0,590,591,1,
  	0,0,0,591,592,6,44,41,0,592,90,1,0,0,0,593,594,5,42,0,0,594,595,5,42,
  	0,0,595,596,5,61,0,0,596,597,1,0,0,0,597,598,6,45,42,0,598,92,1,0,0,0,
  	599,600,5,42,0,0,600,601,6,46,43,0,601,94,1,0,0,0,602,603,5,42,0,0,603,
  	604,5,61,0,0,604,605,1,0,0,0,605,606,6,47,44,0,606,96,1,0,0,0,607,608,
  	5,47,0,0,608,609,5,47,0,0,609,610,1,0,0,0,610,611,6,48,45,0,611,98,1,
  	0,0,0,612,613,5,47,0,0,613,614,5,47,0,0,614,615,5,61,0,0,615,616,1,0,
  	0,0,616,617,6,49,46,0,617,100,1,0,0,0,618,619,5,47,0,0,619,620,6,50,47,
  	0,620,102,1,0,0,0,621,622,5,47,0,0,622,623,5,61,0,0,623,624,1,0,0,0,624,
  	625,6,51,48,0,625,104,1,0,0,0,626,627,5,37,0,0,627,628,6,52,49,0,628,
  	106,1,0,0,0,629,630,5,37,0,0,630,631,6,53,50,0,631,108,1,0,0,0,632,633,
  	4,54,0,0,633,634,5,43,0,0,634,635,6,54,51,0,635,110,1,0,0,0,636,637,5,
  	43,0,0,637,638,5,61,0,0,638,639,1,0,0,0,639,640,6,55,52,0,640,112,1,0,
  	0,0,641,642,5,43,0,0,642,643,6,56,53,0,643,114,1,0,0,0,644,645,4,57,1,
  	0,645,646,5,45,0,0,646,647,6,57,54,0,647,116,1,0,0,0,648,649,5,45,0,0,
  	649,650,5,61,0,0,650,651,1,0,0,0,651,652,6,58,55,0,652,118,1,0,0,0,653,
  	654,5,45,0,0,654,655,6,59,56,0,655,120,1,0,0,0,656,657,5,61,0,0,657,658,
  	5,61,0,0,658,659,1,0,0,0,659,660,6,60,57,0,660,122,1,0,0,0,661,662,5,
  	33,0,0,662,663,5,61,0,0,663,664,1,0,0,0,664,665,6,61,58,0,665,124,1,0,
  	0,0,666,667,5,33,0,0,667,668,6,62,59,0,668,126,1,0,0,0,669,670,5,126,
  	0,0,670,671,6,63,60,0,671,128,1,0,0,0,672,673,5,60,0,0,673,674,6,64,61,
  	0,674,130,1,0,0,0,675,676,5,62,0,0,676,677,6,65,62,0,677,132,1,0,0,0,
  	678,679,5,60,0,0,679,680,5,61,0,0,680,681,1,0,0,0,681,682,6,66,63,0,682,
  	134,1,0,0,0,683,684,5,62,0,0,684,685,5,61,0,0,685,686,1,0,0,0,686,687,
  	6,67,64,0,687,136,1,0,0,0,688,689,5,38,0,0,689,690,6,68,65,0,690,138,
  	1,0,0,0,691,692,5,38,0,0,692,693,5,61,0,0,693,694,1,0,0,0,694,695,6,69,
  	66,0,695,140,1,0,0,0,696,697,5,94,0,0,697,698,6,70,67,0,698,142,1,0,0,
  	0,699,700,5,94,0,0,700,701,5,61,0,0,701,702,1,0,0,0,702,703,6,71,68,0,
  	703,144,1,0,0,0,704,705,5,124,0,0,705,706,6,72,69,0,706,146,1,0,0,0,707,
  	708,5,124,0,0,708,709,5,61,0,0,709,710,1,0,0,0,710,711,6,73,70,0,711,
  	148,1,0,0,0,712,713,5,38,0,0,713,714,5,38,0,0,714,715,1,0,0,0,715,716,
  	6,74,71,0,716,150,1,0,0,0,717,718,5,38,0,0,718,719,5,38,0,0,719,720,5,
  	38,0,0,720,721,1,0,0,0,721,722,6,75,72,0,722,152,1,0,0,0,723,724,5,38,
  	0,0,724,725,5,38,0,0,725,726,5,61,0,0,726,727,1,0,0,0,727,728,6,76,73,
  	0,728,154,1,0,0,0,729,730,5,38,0,0,730,731,5,38,0,0,731,732,5,38,0,0,
  	732,733,5,61,0,0,733,734,1,0,0,0,734,735,6,77,74,0,735,156,1,0,0,0,736,
  	737,5,94,0,0,737,738,5,94,0,0,738,739,1,0,0,0,739,740,6,78,75,0,740,158,
  	1,0,0,0,741,742,5,94,0,0,742,743,5,94,0,0,743,744,5,61,0,0,744,745,1,
  	0,0,0,745,746,6,79,76,0,746,160,1,0,0,0,747,748,5,124,0,0,748,749,5,124,
  	0,0,749,750,1,0,0,0,750,751,6,80,77,0,751,162,1,0,0,0,752,753,5,124,0,
  	0,753,754,5,124,0,0,754,755,5,61,0,0,755,756,1,0,0,0,756,757,6,81,78,
  	0,757,164,1,0,0,0,758,759,5,124,0,0,759,760,5,124,0,0,760,761,5,124,0,
  	0,761,762,1,0,0,0,762,763,6,82,79,0,763,166,1,0,0,0,764,765,5,124,0,0,
  	765,766,5,124,0,0,766,767,5,124,0,0,767,768,5,61,0,0,768,769,1,0,0,0,
  	769,770,6,83,80,0,770,168,1,0,0,0,771,772,5,60,0,0,772,773,5,60,0,0,773,
  	774,1,0,0,0,774,775,6,84,81,0,775,170,1,0,0,0,776,777,5,60,0,0,777,778,
  	5,60,0,0,778,779,5,61,0,0,779,780,1,0,0,0,780,781,6,85,82,0,781,172,1,
  	0,0,0,782,783,5,62,0,0,783,784,5,62,0,0,784,785,1,0,0,0,785,786,6,86,
  	83,0,786,174,1,0,0,0,787,788,5,62,0,0,788,789,5,62,0,0,789,790,5,61,0,
  	0,790,791,1,0,0,0,791,792,6,87,84,0,792,176,1,0,0,0,793,794,5,46,0,0,
  	794,795,5,46,0,0,795,796,5,46,0,0,796,797,1,0,0,0,797,798,6,88,85,0,798,
  	178,1,0,0,0,799,800,5,58,0,0,800,801,5,42,0,0,801,802,1,0,0,0,802,803,
  	6,89,86,0,803,180,1,0,0,0,804,805,5,58,0,0,805,806,5,42,0,0,806,807,5,
  	61,0,0,807,808,1,0,0,0,808,809,6,90,87,0,809,182,1,0,0,0,810,811,5,46,
  	0,0,811,812,5,61,0,0,812,813,1,0,0,0,813,814,6,91,88,0,814,184,1,0,0,
  	0,815,816,5,95,0,0,816,817,5,61,0,0,817,818,1,0,0,0,818,819,6,92,89,0,
  	819,186,1,0,0,0,820,821,5,33,0,0,821,822,5,95,0,0,822,823,5,61,0,0,823,
  	824,1,0,0,0,824,825,6,93,90,0,825,188,1,0,0,0,826,827,4,94,2,0,827,828,
  	5,40,0,0,828,829,6,94,91,0,829,190,1,0,0,0,830,831,4,95,3,0,831,832,5,
  	40,0,0,832,833,6,95,92,0,833,192,1,0,0,0,834,836,9,0,0,0,835,834,1,0,
  	0,0,836,837,1,0,0,0,837,838,1,0,0,0,837,835,1,0,0,0,838,194,1,0,0,0,48,
  	0,198,205,212,217,220,224,229,231,236,240,245,247,253,258,265,270,274,
  	279,284,291,300,308,310,321,323,403,406,413,418,426,431,439,444,452,457,
  	465,470,478,483,492,497,506,518,525,535,539,837,93,1,0,0,1,1,1,1,2,2,
  	1,6,3,1,7,4,1,8,5,1,9,6,1,10,7,1,11,8,1,12,9,1,13,10,1,14,11,1,15,12,
  	1,16,13,1,17,14,1,18,15,1,19,16,1,20,17,1,21,18,1,22,19,1,23,20,1,24,
  	21,1,25,22,1,26,23,1,27,24,1,28,25,1,29,26,1,30,27,1,32,28,1,33,29,1,
  	34,30,1,35,31,1,36,32,1,37,33,1,38,34,1,39,35,1,40,36,1,41,37,1,42,38,
  	0,1,0,1,43,39,1,44,40,1,45,41,1,46,42,1,47,43,1,48,44,1,49,45,1,50,46,
  	1,51,47,1,52,48,1,53,49,1,54,50,1,55,51,1,56,52,1,57,53,1,58,54,1,59,
  	55,1,60,56,1,61,57,1,62,58,1,63,59,1,64,60,1,65,61,1,66,62,1,67,63,1,
  	68,64,1,69,65,1,70,66,1,71,67,1,72,68,1,73,69,1,74,70,1,75,71,1,76,72,
  	1,77,73,1,78,74,1,79,75,1,80,76,1,81,77,1,82,78,1,83,79,1,84,80,1,85,
  	81,1,86,82,1,87,83,1,88,84,1,89,85,1,90,86,1,91,87,1,92,88,1,93,89,1,
  	94,90,1,95,91
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
    case 6: BTSYMBOLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 7: DQSYMBOLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 8: SQSYMBOLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 9: BACHNULLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 10: BACHNILAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 11: IFAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: THENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: ELSEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: WHILEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: FORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: DOAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 17: COLLECTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 18: FUNCTIONAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 19: INLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 20: INTINLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 21: RATINLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 22: FLOATINLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 23: PITCHINLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 24: OUTLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 25: DIRINLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 26: DIROUTLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 27: GLOBALVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 28: PATCHERVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 29: LOCALVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 30: NAMEDPARAMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 32: PUSHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 33: POPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 34: CLOSEDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 35: NTHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 36: PICKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 37: KEYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 38: ANTHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 39: APICKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 40: NULLIFYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 41: ASSIGNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 42: WHITESPACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 43: NEWATOMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 44: POWAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 45: APOWAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 46: TIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 47: ATIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 48: DIVDIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 49: ADIVDIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 50: DIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 51: ADIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 52: REMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 53: AREMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 54: PLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 55: APLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 56: UPLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 57: MINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 58: AMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 59: UMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 60: EQUALAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 61: NEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 62: LOGNOTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 63: BITNOTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 64: LTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 65: GTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 66: LEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 67: GEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 68: BITANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 69: ABITANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 70: BITXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 71: ABITXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 72: BITORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 73: ABITORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 74: LOGANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 75: LOGANDEXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 76: ALOGANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 77: ALOGANDEXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 78: LOGXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 79: ALOGXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 80: LOGORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 81: ALOGORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 82: LOGOREXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 83: ALOGOREXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 84: LSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 85: ALSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 86: RSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 87: ARSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 88: RANGEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
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
    case 54: return PLUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 57: return MINUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 94: return OPENSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 95: return PARAMSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

void bellLexer::UINTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::UFLOATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::UPITCHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::BTSYMBOLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3:  noParams = true; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::DQSYMBOLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4:  noParams = true; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::SQSYMBOLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5:  noParams = true; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::BACHNULLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6:  noParams = false; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BACHNILAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 7:  noParams = false; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::IFAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 8:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::THENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 9:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ELSEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 10:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::WHILEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 11:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::FORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 12:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DOAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 13:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::COLLECTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 14:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::FUNCTIONAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 15:  noParams = noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::INLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 16:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::INTINLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 17:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::RATINLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 18:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::FLOATINLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 19:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PITCHINLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 20:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::OUTLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 21:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::DIRINLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::DIROUTLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::GLOBALVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PATCHERVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 25:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::LOCALVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 26:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::NAMEDPARAMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 27:  noParams = true; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PUSHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 28:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::POPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 29:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::CLOSEDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 30:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::NTHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 31:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PICKAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 32:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::KEYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 33:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ANTHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 34:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::APICKAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 35:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NULLIFYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 36:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ASSIGNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 37:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::WHITESPACEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 38:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NEWATOMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 39:  noParams = true; noUnary = false; (*codeac)++;  break;

  default:
    break;
  }
}

void bellLexer::POWAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 40:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::APOWAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 41:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::TIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 42:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ATIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 43:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVDIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 44:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ADIVDIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 45:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 46:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ADIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 47:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::REMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 48:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::AREMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 49:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 50:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::APLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 51:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UPLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 52:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::MINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 53:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::AMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 54:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 55:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::EQUALAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 56:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 57:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGNOTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 58:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITNOTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 59:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 60:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::GTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 61:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 62:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::GEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 63:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 64:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ABITANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 65:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 66:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ABITXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 67:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 68:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ABITORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 69:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 70:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGANDEXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 71:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 72:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGANDEXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 73:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 74:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 75:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 76:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 77:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGOREXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 78:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGOREXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 79:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 80:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 81:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::RSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 82:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ARSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 83:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::RANGEAction(antlr4::RuleContext *context, size_t actionIndex) {
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
