 
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
      "UINT", "UFLOAT", "UPITCH", "NOTENAME", "ACCIDENTAL", "RAT", "BACHNULL", 
      "BACHNIL", "IF", "THEN", "ELSE", "WHILE", "FOR", "DO", "COLLECT", 
      "FUNCTION", "INLET", "INTINLET", "RATINLET", "FLOATINLET", "PITCHINLET", 
      "OUTLET", "DIRINLET", "DIROUTLET", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", 
      "NAMEDPARAM", "ID", "PUSH", "POP", "CLOSED", "NTH", "PICK", "KEY", 
      "ANTH", "APICK", "NULLIFY", "ASSIGN", "WHITESPACE", "NEWATOM", "POW", 
      "APOW", "TIMES", "ATIMES", "DIVDIV", "ADIVDIV", "DIV", "ADIV", "REM", 
      "AREM", "PLUS", "APLUS", "UPLUS", "MINUS", "AMINUS", "UMINUS", "EQUAL", 
      "NEQ", "LOGNOT", "BITNOT", "LT", "GT", "LEQ", "GEQ", "BITAND", "ABITAND", 
      "BITXOR", "ABITXOR", "BITOR", "ABITOR", "LOGAND", "LOGANDEXT", "ALOGAND", 
      "ALOGANDEXT", "LOGXOR", "ALOGXOR", "LOGOR", "ALOGOR", "LOGOREXT", 
      "ALOGOREXT", "LSHIFT", "ALSHIFT", "RSHIFT", "ARSHIFT", "RANGE", "REPEAT", 
      "AREPEAT", "AAPPLY", "ACONCAT", "ARCONCAT", "OPEN", "PARAMS", "ANYTHING"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "", "", "'null'", "'nil'", "'if'", "'then'", "'else'", "'while'", 
      "'for'", "'do'", "'collect'", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "'['", "']'", "')'", "':'", "'::'", "'.'", "':='", 
      "'::='", "';'", "'='", "", "", "'**'", "'**='", "'*'", "'*='", "'//'", 
      "'//='", "'/'", "'/='", "", "", "", "'+='", "'+'", "", "'-='", "'-'", 
      "'=='", "'!='", "'!'", "'~'", "'<'", "'>'", "'<='", "'>='", "'&'", 
      "'&='", "'^'", "'^='", "'|'", "'|='", "'&&'", "'&&&'", "'&&='", "'&&&='", 
      "'^^'", "'^^='", "'||'", "'||='", "'|||'", "'|||='", "'<<'", "'<<='", 
      "'>>'", "'>>='", "'...'", "':*'", "':*='", "'.='", "'_='", "'!_='"
    },
    std::vector<std::string>{
      "", "UINT", "UFLOAT", "UPITCH", "BACHNULL", "BACHNIL", "IF", "THEN", 
      "ELSE", "WHILE", "FOR", "DO", "COLLECT", "FUNCTION", "INLET", "INTINLET", 
      "RATINLET", "FLOATINLET", "PITCHINLET", "OUTLET", "DIRINLET", "DIROUTLET", 
      "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "NAMEDPARAM", "PUSH", "POP", 
      "CLOSED", "NTH", "PICK", "KEY", "ANTH", "APICK", "NULLIFY", "ASSIGN", 
      "WHITESPACE", "NEWATOM", "POW", "APOW", "TIMES", "ATIMES", "DIVDIV", 
      "ADIVDIV", "DIV", "ADIV", "REM", "AREM", "PLUS", "APLUS", "UPLUS", 
      "MINUS", "AMINUS", "UMINUS", "EQUAL", "NEQ", "LOGNOT", "BITNOT", "LT", 
      "GT", "LEQ", "GEQ", "BITAND", "ABITAND", "BITXOR", "ABITXOR", "BITOR", 
      "ABITOR", "LOGAND", "LOGANDEXT", "ALOGAND", "ALOGANDEXT", "LOGXOR", 
      "ALOGXOR", "LOGOR", "ALOGOR", "LOGOREXT", "ALOGOREXT", "LSHIFT", "ALSHIFT", 
      "RSHIFT", "ARSHIFT", "RANGE", "REPEAT", "AREPEAT", "AAPPLY", "ACONCAT", 
      "ARCONCAT", "OPEN", "PARAMS", "ANYTHING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,90,799,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
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
  	7,91,2,92,7,92,2,93,7,93,1,0,4,0,191,8,0,11,0,12,0,192,1,0,1,0,1,1,5,
  	1,198,8,1,10,1,12,1,201,9,1,1,1,1,1,4,1,205,8,1,11,1,12,1,206,1,1,4,1,
  	210,8,1,11,1,12,1,211,1,1,3,1,215,8,1,1,1,1,1,3,1,219,8,1,1,1,4,1,222,
  	8,1,11,1,12,1,223,3,1,226,8,1,1,1,4,1,229,8,1,11,1,12,1,230,1,1,1,1,3,
  	1,235,8,1,1,1,4,1,238,8,1,11,1,12,1,239,3,1,242,8,1,1,1,1,1,1,2,1,2,3,
  	2,248,8,2,1,2,5,2,251,8,2,10,2,12,2,254,9,2,1,2,1,2,5,2,258,8,2,10,2,
  	12,2,261,9,2,1,2,1,2,3,2,265,8,2,1,2,1,2,3,2,269,8,2,1,2,1,2,1,3,3,3,
  	274,8,3,1,4,4,4,277,8,4,11,4,12,4,278,1,5,1,5,1,5,5,5,284,8,5,10,5,12,
  	5,287,9,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,
  	10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,
  	12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,3,15,364,8,15,1,16,3,16,367,8,16,1,16,1,16,1,16,4,16,372,8,16,
  	11,16,12,16,373,1,16,1,16,1,17,3,17,379,8,17,1,17,1,17,1,17,1,17,4,17,
  	385,8,17,11,17,12,17,386,1,17,1,17,1,18,3,18,392,8,18,1,18,1,18,1,18,
  	1,18,4,18,398,8,18,11,18,12,18,399,1,18,1,18,1,19,3,19,405,8,19,1,19,
  	1,19,1,19,1,19,4,19,411,8,19,11,19,12,19,412,1,19,1,19,1,20,3,20,418,
  	8,20,1,20,1,20,1,20,1,20,4,20,424,8,20,11,20,12,20,425,1,20,1,20,1,21,
  	3,21,431,8,21,1,21,1,21,1,21,1,21,4,21,437,8,21,11,21,12,21,438,1,21,
  	1,21,1,22,3,22,444,8,22,1,22,1,22,1,22,1,22,1,22,4,22,451,8,22,11,22,
  	12,22,452,1,22,1,22,1,23,3,23,458,8,23,1,23,1,23,1,23,1,23,1,23,4,23,
  	465,8,23,11,23,12,23,466,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,25,
  	1,26,3,26,479,8,26,1,26,1,26,1,26,1,26,1,27,3,27,486,8,27,1,27,1,27,1,
  	27,1,27,1,28,1,28,5,28,494,8,28,10,28,12,28,497,9,28,1,28,3,28,500,8,
  	28,1,29,1,29,1,29,1,30,1,30,1,30,1,31,1,31,1,31,1,32,1,32,1,32,1,33,1,
  	33,1,33,1,33,1,33,1,34,1,34,1,34,1,35,1,35,1,35,1,35,1,35,1,36,1,36,1,
  	36,1,36,1,36,1,36,1,37,1,37,1,37,1,38,1,38,1,38,1,39,1,39,1,39,1,39,1,
  	39,1,40,1,40,1,40,1,40,1,40,1,41,1,41,1,41,1,41,1,41,1,42,1,42,1,42,1,
  	42,1,42,1,42,1,43,1,43,1,43,1,44,1,44,1,44,1,44,1,44,1,45,1,45,1,45,1,
  	45,1,45,1,46,1,46,1,46,1,46,1,46,1,46,1,47,1,47,1,47,1,48,1,48,1,48,1,
  	48,1,48,1,49,1,49,1,49,1,50,1,50,1,50,1,51,1,51,1,51,1,51,1,52,1,52,1,
  	52,1,52,1,52,1,53,1,53,1,53,1,54,1,54,1,54,1,54,1,55,1,55,1,55,1,55,1,
  	55,1,56,1,56,1,56,1,57,1,57,1,57,1,57,1,57,1,58,1,58,1,58,1,58,1,58,1,
  	59,1,59,1,59,1,60,1,60,1,60,1,61,1,61,1,61,1,62,1,62,1,62,1,63,1,63,1,
  	63,1,63,1,63,1,64,1,64,1,64,1,64,1,64,1,65,1,65,1,65,1,66,1,66,1,66,1,
  	66,1,66,1,67,1,67,1,67,1,68,1,68,1,68,1,68,1,68,1,69,1,69,1,69,1,70,1,
  	70,1,70,1,70,1,70,1,71,1,71,1,71,1,71,1,71,1,72,1,72,1,72,1,72,1,72,1,
  	72,1,73,1,73,1,73,1,73,1,73,1,73,1,74,1,74,1,74,1,74,1,74,1,74,1,74,1,
  	75,1,75,1,75,1,75,1,75,1,76,1,76,1,76,1,76,1,76,1,76,1,77,1,77,1,77,1,
  	77,1,77,1,78,1,78,1,78,1,78,1,78,1,78,1,79,1,79,1,79,1,79,1,79,1,79,1,
  	80,1,80,1,80,1,80,1,80,1,80,1,80,1,81,1,81,1,81,1,81,1,81,1,82,1,82,1,
  	82,1,82,1,82,1,82,1,83,1,83,1,83,1,83,1,83,1,84,1,84,1,84,1,84,1,84,1,
  	84,1,85,1,85,1,85,1,85,1,85,1,85,1,86,1,86,1,86,1,86,1,86,1,87,1,87,1,
  	87,1,87,1,87,1,87,1,88,1,88,1,88,1,88,1,88,1,89,1,89,1,89,1,89,1,89,1,
  	90,1,90,1,90,1,90,1,90,1,90,1,91,1,91,1,91,1,91,1,92,1,92,1,92,1,92,1,
  	93,4,93,796,8,93,11,93,12,93,797,1,797,0,94,1,1,3,2,5,3,7,0,9,0,11,0,
  	13,4,15,5,17,6,19,7,21,8,23,9,25,10,27,11,29,12,31,13,33,14,35,15,37,
  	16,39,17,41,18,43,19,45,20,47,21,49,22,51,23,53,24,55,25,57,0,59,26,61,
  	27,63,28,65,29,67,30,69,31,71,32,73,33,75,34,77,35,79,36,81,37,83,38,
  	85,39,87,40,89,41,91,42,93,43,95,44,97,45,99,46,101,47,103,48,105,49,
  	107,50,109,51,111,52,113,53,115,54,117,55,119,56,121,57,123,58,125,59,
  	127,60,129,61,131,62,133,63,135,64,137,65,139,66,141,67,143,68,145,69,
  	147,70,149,71,151,72,153,73,155,74,157,75,159,76,161,77,163,78,165,79,
  	167,80,169,81,171,82,173,83,175,84,177,85,179,86,181,87,183,88,185,89,
  	187,90,1,0,11,1,0,48,57,2,0,69,69,101,101,2,0,43,43,45,45,2,0,65,71,97,
  	103,7,0,35,35,94,94,98,98,100,100,113,113,118,118,120,120,2,0,108,108,
  	120,120,2,0,65,90,97,122,4,0,48,57,65,90,95,95,97,122,3,0,48,57,65,90,
  	97,122,3,0,9,10,13,13,32,32,1,0,1,1,836,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,
  	0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,
  	0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,
  	33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,
  	0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,
  	0,0,55,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,
  	67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,
  	0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,
  	0,0,89,1,0,0,0,0,91,1,0,0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,
  	99,1,0,0,0,0,101,1,0,0,0,0,103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,
  	109,1,0,0,0,0,111,1,0,0,0,0,113,1,0,0,0,0,115,1,0,0,0,0,117,1,0,0,0,0,
  	119,1,0,0,0,0,121,1,0,0,0,0,123,1,0,0,0,0,125,1,0,0,0,0,127,1,0,0,0,0,
  	129,1,0,0,0,0,131,1,0,0,0,0,133,1,0,0,0,0,135,1,0,0,0,0,137,1,0,0,0,0,
  	139,1,0,0,0,0,141,1,0,0,0,0,143,1,0,0,0,0,145,1,0,0,0,0,147,1,0,0,0,0,
  	149,1,0,0,0,0,151,1,0,0,0,0,153,1,0,0,0,0,155,1,0,0,0,0,157,1,0,0,0,0,
  	159,1,0,0,0,0,161,1,0,0,0,0,163,1,0,0,0,0,165,1,0,0,0,0,167,1,0,0,0,0,
  	169,1,0,0,0,0,171,1,0,0,0,0,173,1,0,0,0,0,175,1,0,0,0,0,177,1,0,0,0,0,
  	179,1,0,0,0,0,181,1,0,0,0,0,183,1,0,0,0,0,185,1,0,0,0,0,187,1,0,0,0,1,
  	190,1,0,0,0,3,241,1,0,0,0,5,245,1,0,0,0,7,273,1,0,0,0,9,276,1,0,0,0,11,
  	280,1,0,0,0,13,290,1,0,0,0,15,297,1,0,0,0,17,303,1,0,0,0,19,308,1,0,0,
  	0,21,315,1,0,0,0,23,322,1,0,0,0,25,330,1,0,0,0,27,336,1,0,0,0,29,341,
  	1,0,0,0,31,363,1,0,0,0,33,366,1,0,0,0,35,378,1,0,0,0,37,391,1,0,0,0,39,
  	404,1,0,0,0,41,417,1,0,0,0,43,430,1,0,0,0,45,443,1,0,0,0,47,457,1,0,0,
  	0,49,470,1,0,0,0,51,473,1,0,0,0,53,478,1,0,0,0,55,485,1,0,0,0,57,491,
  	1,0,0,0,59,501,1,0,0,0,61,504,1,0,0,0,63,507,1,0,0,0,65,510,1,0,0,0,67,
  	513,1,0,0,0,69,518,1,0,0,0,71,521,1,0,0,0,73,526,1,0,0,0,75,532,1,0,0,
  	0,77,535,1,0,0,0,79,538,1,0,0,0,81,543,1,0,0,0,83,548,1,0,0,0,85,553,
  	1,0,0,0,87,559,1,0,0,0,89,562,1,0,0,0,91,567,1,0,0,0,93,572,1,0,0,0,95,
  	578,1,0,0,0,97,581,1,0,0,0,99,586,1,0,0,0,101,589,1,0,0,0,103,592,1,0,
  	0,0,105,596,1,0,0,0,107,601,1,0,0,0,109,604,1,0,0,0,111,608,1,0,0,0,113,
  	613,1,0,0,0,115,616,1,0,0,0,117,621,1,0,0,0,119,626,1,0,0,0,121,629,1,
  	0,0,0,123,632,1,0,0,0,125,635,1,0,0,0,127,638,1,0,0,0,129,643,1,0,0,0,
  	131,648,1,0,0,0,133,651,1,0,0,0,135,656,1,0,0,0,137,659,1,0,0,0,139,664,
  	1,0,0,0,141,667,1,0,0,0,143,672,1,0,0,0,145,677,1,0,0,0,147,683,1,0,0,
  	0,149,689,1,0,0,0,151,696,1,0,0,0,153,701,1,0,0,0,155,707,1,0,0,0,157,
  	712,1,0,0,0,159,718,1,0,0,0,161,724,1,0,0,0,163,731,1,0,0,0,165,736,1,
  	0,0,0,167,742,1,0,0,0,169,747,1,0,0,0,171,753,1,0,0,0,173,759,1,0,0,0,
  	175,764,1,0,0,0,177,770,1,0,0,0,179,775,1,0,0,0,181,780,1,0,0,0,183,786,
  	1,0,0,0,185,790,1,0,0,0,187,795,1,0,0,0,189,191,7,0,0,0,190,189,1,0,0,
  	0,191,192,1,0,0,0,192,190,1,0,0,0,192,193,1,0,0,0,193,194,1,0,0,0,194,
  	195,6,0,0,0,195,2,1,0,0,0,196,198,7,0,0,0,197,196,1,0,0,0,198,201,1,0,
  	0,0,199,197,1,0,0,0,199,200,1,0,0,0,200,202,1,0,0,0,201,199,1,0,0,0,202,
  	204,5,46,0,0,203,205,7,0,0,0,204,203,1,0,0,0,205,206,1,0,0,0,206,204,
  	1,0,0,0,206,207,1,0,0,0,207,215,1,0,0,0,208,210,7,0,0,0,209,208,1,0,0,
  	0,210,211,1,0,0,0,211,209,1,0,0,0,211,212,1,0,0,0,212,213,1,0,0,0,213,
  	215,5,46,0,0,214,199,1,0,0,0,214,209,1,0,0,0,215,225,1,0,0,0,216,218,
  	7,1,0,0,217,219,7,2,0,0,218,217,1,0,0,0,218,219,1,0,0,0,219,221,1,0,0,
  	0,220,222,7,0,0,0,221,220,1,0,0,0,222,223,1,0,0,0,223,221,1,0,0,0,223,
  	224,1,0,0,0,224,226,1,0,0,0,225,216,1,0,0,0,225,226,1,0,0,0,226,242,1,
  	0,0,0,227,229,7,0,0,0,228,227,1,0,0,0,229,230,1,0,0,0,230,228,1,0,0,0,
  	230,231,1,0,0,0,231,232,1,0,0,0,232,234,7,1,0,0,233,235,7,2,0,0,234,233,
  	1,0,0,0,234,235,1,0,0,0,235,237,1,0,0,0,236,238,7,0,0,0,237,236,1,0,0,
  	0,238,239,1,0,0,0,239,237,1,0,0,0,239,240,1,0,0,0,240,242,1,0,0,0,241,
  	214,1,0,0,0,241,228,1,0,0,0,242,243,1,0,0,0,243,244,6,1,1,0,244,4,1,0,
  	0,0,245,247,3,7,3,0,246,248,3,9,4,0,247,246,1,0,0,0,247,248,1,0,0,0,248,
  	252,1,0,0,0,249,251,7,2,0,0,250,249,1,0,0,0,251,254,1,0,0,0,252,250,1,
  	0,0,0,252,253,1,0,0,0,253,255,1,0,0,0,254,252,1,0,0,0,255,268,3,1,0,0,
  	256,258,7,2,0,0,257,256,1,0,0,0,258,261,1,0,0,0,259,257,1,0,0,0,259,260,
  	1,0,0,0,260,264,1,0,0,0,261,259,1,0,0,0,262,265,3,1,0,0,263,265,3,11,
  	5,0,264,262,1,0,0,0,264,263,1,0,0,0,265,266,1,0,0,0,266,267,5,116,0,0,
  	267,269,1,0,0,0,268,259,1,0,0,0,268,269,1,0,0,0,269,270,1,0,0,0,270,271,
  	6,2,2,0,271,6,1,0,0,0,272,274,7,3,0,0,273,272,1,0,0,0,274,8,1,0,0,0,275,
  	277,7,4,0,0,276,275,1,0,0,0,277,278,1,0,0,0,278,276,1,0,0,0,278,279,1,
  	0,0,0,279,10,1,0,0,0,280,281,3,1,0,0,281,285,5,47,0,0,282,284,7,2,0,0,
  	283,282,1,0,0,0,284,287,1,0,0,0,285,283,1,0,0,0,285,286,1,0,0,0,286,288,
  	1,0,0,0,287,285,1,0,0,0,288,289,3,1,0,0,289,12,1,0,0,0,290,291,5,110,
  	0,0,291,292,5,117,0,0,292,293,5,108,0,0,293,294,5,108,0,0,294,295,1,0,
  	0,0,295,296,6,6,3,0,296,14,1,0,0,0,297,298,5,110,0,0,298,299,5,105,0,
  	0,299,300,5,108,0,0,300,301,1,0,0,0,301,302,6,7,4,0,302,16,1,0,0,0,303,
  	304,5,105,0,0,304,305,5,102,0,0,305,306,1,0,0,0,306,307,6,8,5,0,307,18,
  	1,0,0,0,308,309,5,116,0,0,309,310,5,104,0,0,310,311,5,101,0,0,311,312,
  	5,110,0,0,312,313,1,0,0,0,313,314,6,9,6,0,314,20,1,0,0,0,315,316,5,101,
  	0,0,316,317,5,108,0,0,317,318,5,115,0,0,318,319,5,101,0,0,319,320,1,0,
  	0,0,320,321,6,10,7,0,321,22,1,0,0,0,322,323,5,119,0,0,323,324,5,104,0,
  	0,324,325,5,105,0,0,325,326,5,108,0,0,326,327,5,101,0,0,327,328,1,0,0,
  	0,328,329,6,11,8,0,329,24,1,0,0,0,330,331,5,102,0,0,331,332,5,111,0,0,
  	332,333,5,114,0,0,333,334,1,0,0,0,334,335,6,12,9,0,335,26,1,0,0,0,336,
  	337,5,100,0,0,337,338,5,111,0,0,338,339,1,0,0,0,339,340,6,13,10,0,340,
  	28,1,0,0,0,341,342,5,99,0,0,342,343,5,111,0,0,343,344,5,108,0,0,344,345,
  	5,108,0,0,345,346,5,101,0,0,346,347,5,99,0,0,347,348,5,116,0,0,348,349,
  	1,0,0,0,349,350,6,14,11,0,350,30,1,0,0,0,351,352,5,115,0,0,352,353,5,
  	105,0,0,353,364,5,110,0,0,354,355,5,99,0,0,355,356,5,111,0,0,356,364,
  	5,115,0,0,357,358,5,115,0,0,358,359,5,113,0,0,359,360,5,114,0,0,360,361,
  	5,116,0,0,361,362,1,0,0,0,362,364,6,15,12,0,363,351,1,0,0,0,363,354,1,
  	0,0,0,363,357,1,0,0,0,364,32,1,0,0,0,365,367,5,92,0,0,366,365,1,0,0,0,
  	366,367,1,0,0,0,367,368,1,0,0,0,368,369,5,36,0,0,369,371,7,5,0,0,370,
  	372,7,0,0,0,371,370,1,0,0,0,372,373,1,0,0,0,373,371,1,0,0,0,373,374,1,
  	0,0,0,374,375,1,0,0,0,375,376,6,16,13,0,376,34,1,0,0,0,377,379,5,92,0,
  	0,378,377,1,0,0,0,378,379,1,0,0,0,379,380,1,0,0,0,380,381,5,36,0,0,381,
  	382,5,105,0,0,382,384,1,0,0,0,383,385,7,0,0,0,384,383,1,0,0,0,385,386,
  	1,0,0,0,386,384,1,0,0,0,386,387,1,0,0,0,387,388,1,0,0,0,388,389,6,17,
  	14,0,389,36,1,0,0,0,390,392,5,92,0,0,391,390,1,0,0,0,391,392,1,0,0,0,
  	392,393,1,0,0,0,393,394,5,36,0,0,394,395,5,114,0,0,395,397,1,0,0,0,396,
  	398,7,0,0,0,397,396,1,0,0,0,398,399,1,0,0,0,399,397,1,0,0,0,399,400,1,
  	0,0,0,400,401,1,0,0,0,401,402,6,18,15,0,402,38,1,0,0,0,403,405,5,92,0,
  	0,404,403,1,0,0,0,404,405,1,0,0,0,405,406,1,0,0,0,406,407,5,36,0,0,407,
  	408,5,102,0,0,408,410,1,0,0,0,409,411,7,0,0,0,410,409,1,0,0,0,411,412,
  	1,0,0,0,412,410,1,0,0,0,412,413,1,0,0,0,413,414,1,0,0,0,414,415,6,19,
  	16,0,415,40,1,0,0,0,416,418,5,92,0,0,417,416,1,0,0,0,417,418,1,0,0,0,
  	418,419,1,0,0,0,419,420,5,36,0,0,420,421,5,112,0,0,421,423,1,0,0,0,422,
  	424,7,0,0,0,423,422,1,0,0,0,424,425,1,0,0,0,425,423,1,0,0,0,425,426,1,
  	0,0,0,426,427,1,0,0,0,427,428,6,20,17,0,428,42,1,0,0,0,429,431,5,92,0,
  	0,430,429,1,0,0,0,430,431,1,0,0,0,431,432,1,0,0,0,432,433,5,36,0,0,433,
  	434,5,111,0,0,434,436,1,0,0,0,435,437,7,0,0,0,436,435,1,0,0,0,437,438,
  	1,0,0,0,438,436,1,0,0,0,438,439,1,0,0,0,439,440,1,0,0,0,440,441,6,21,
  	18,0,441,44,1,0,0,0,442,444,5,92,0,0,443,442,1,0,0,0,443,444,1,0,0,0,
  	444,445,1,0,0,0,445,446,5,36,0,0,446,447,5,100,0,0,447,448,5,120,0,0,
  	448,450,1,0,0,0,449,451,7,0,0,0,450,449,1,0,0,0,451,452,1,0,0,0,452,450,
  	1,0,0,0,452,453,1,0,0,0,453,454,1,0,0,0,454,455,6,22,19,0,455,46,1,0,
  	0,0,456,458,5,92,0,0,457,456,1,0,0,0,457,458,1,0,0,0,458,459,1,0,0,0,
  	459,460,5,36,0,0,460,461,5,100,0,0,461,462,5,111,0,0,462,464,1,0,0,0,
  	463,465,7,0,0,0,464,463,1,0,0,0,465,466,1,0,0,0,466,464,1,0,0,0,466,467,
  	1,0,0,0,467,468,1,0,0,0,468,469,6,23,20,0,469,48,1,0,0,0,470,471,3,57,
  	28,0,471,472,6,24,21,0,472,50,1,0,0,0,473,474,5,35,0,0,474,475,3,57,28,
  	0,475,476,6,25,22,0,476,52,1,0,0,0,477,479,5,92,0,0,478,477,1,0,0,0,478,
  	479,1,0,0,0,479,480,1,0,0,0,480,481,5,36,0,0,481,482,3,57,28,0,482,483,
  	6,26,23,0,483,54,1,0,0,0,484,486,5,92,0,0,485,484,1,0,0,0,485,486,1,0,
  	0,0,486,487,1,0,0,0,487,488,5,64,0,0,488,489,3,57,28,0,489,490,6,27,24,
  	0,490,56,1,0,0,0,491,499,7,6,0,0,492,494,7,7,0,0,493,492,1,0,0,0,494,
  	497,1,0,0,0,495,493,1,0,0,0,495,496,1,0,0,0,496,498,1,0,0,0,497,495,1,
  	0,0,0,498,500,7,8,0,0,499,495,1,0,0,0,499,500,1,0,0,0,500,58,1,0,0,0,
  	501,502,5,91,0,0,502,503,6,29,25,0,503,60,1,0,0,0,504,505,5,93,0,0,505,
  	506,6,30,26,0,506,62,1,0,0,0,507,508,5,41,0,0,508,509,6,31,27,0,509,64,
  	1,0,0,0,510,511,5,58,0,0,511,512,6,32,28,0,512,66,1,0,0,0,513,514,5,58,
  	0,0,514,515,5,58,0,0,515,516,1,0,0,0,516,517,6,33,29,0,517,68,1,0,0,0,
  	518,519,5,46,0,0,519,520,6,34,30,0,520,70,1,0,0,0,521,522,5,58,0,0,522,
  	523,5,61,0,0,523,524,1,0,0,0,524,525,6,35,31,0,525,72,1,0,0,0,526,527,
  	5,58,0,0,527,528,5,58,0,0,528,529,5,61,0,0,529,530,1,0,0,0,530,531,6,
  	36,32,0,531,74,1,0,0,0,532,533,5,59,0,0,533,534,6,37,33,0,534,76,1,0,
  	0,0,535,536,5,61,0,0,536,537,6,38,34,0,537,78,1,0,0,0,538,539,7,9,0,0,
  	539,540,6,39,35,0,540,541,1,0,0,0,541,542,6,39,36,0,542,80,1,0,0,0,543,
  	544,7,10,0,0,544,545,6,40,37,0,545,546,1,0,0,0,546,547,6,40,36,0,547,
  	82,1,0,0,0,548,549,5,42,0,0,549,550,5,42,0,0,550,551,1,0,0,0,551,552,
  	6,41,38,0,552,84,1,0,0,0,553,554,5,42,0,0,554,555,5,42,0,0,555,556,5,
  	61,0,0,556,557,1,0,0,0,557,558,6,42,39,0,558,86,1,0,0,0,559,560,5,42,
  	0,0,560,561,6,43,40,0,561,88,1,0,0,0,562,563,5,42,0,0,563,564,5,61,0,
  	0,564,565,1,0,0,0,565,566,6,44,41,0,566,90,1,0,0,0,567,568,5,47,0,0,568,
  	569,5,47,0,0,569,570,1,0,0,0,570,571,6,45,42,0,571,92,1,0,0,0,572,573,
  	5,47,0,0,573,574,5,47,0,0,574,575,5,61,0,0,575,576,1,0,0,0,576,577,6,
  	46,43,0,577,94,1,0,0,0,578,579,5,47,0,0,579,580,6,47,44,0,580,96,1,0,
  	0,0,581,582,5,47,0,0,582,583,5,61,0,0,583,584,1,0,0,0,584,585,6,48,45,
  	0,585,98,1,0,0,0,586,587,5,37,0,0,587,588,6,49,46,0,588,100,1,0,0,0,589,
  	590,5,37,0,0,590,591,6,50,47,0,591,102,1,0,0,0,592,593,4,51,0,0,593,594,
  	5,43,0,0,594,595,6,51,48,0,595,104,1,0,0,0,596,597,5,43,0,0,597,598,5,
  	61,0,0,598,599,1,0,0,0,599,600,6,52,49,0,600,106,1,0,0,0,601,602,5,43,
  	0,0,602,603,6,53,50,0,603,108,1,0,0,0,604,605,4,54,1,0,605,606,5,45,0,
  	0,606,607,6,54,51,0,607,110,1,0,0,0,608,609,5,45,0,0,609,610,5,61,0,0,
  	610,611,1,0,0,0,611,612,6,55,52,0,612,112,1,0,0,0,613,614,5,45,0,0,614,
  	615,6,56,53,0,615,114,1,0,0,0,616,617,5,61,0,0,617,618,5,61,0,0,618,619,
  	1,0,0,0,619,620,6,57,54,0,620,116,1,0,0,0,621,622,5,33,0,0,622,623,5,
  	61,0,0,623,624,1,0,0,0,624,625,6,58,55,0,625,118,1,0,0,0,626,627,5,33,
  	0,0,627,628,6,59,56,0,628,120,1,0,0,0,629,630,5,126,0,0,630,631,6,60,
  	57,0,631,122,1,0,0,0,632,633,5,60,0,0,633,634,6,61,58,0,634,124,1,0,0,
  	0,635,636,5,62,0,0,636,637,6,62,59,0,637,126,1,0,0,0,638,639,5,60,0,0,
  	639,640,5,61,0,0,640,641,1,0,0,0,641,642,6,63,60,0,642,128,1,0,0,0,643,
  	644,5,62,0,0,644,645,5,61,0,0,645,646,1,0,0,0,646,647,6,64,61,0,647,130,
  	1,0,0,0,648,649,5,38,0,0,649,650,6,65,62,0,650,132,1,0,0,0,651,652,5,
  	38,0,0,652,653,5,61,0,0,653,654,1,0,0,0,654,655,6,66,63,0,655,134,1,0,
  	0,0,656,657,5,94,0,0,657,658,6,67,64,0,658,136,1,0,0,0,659,660,5,94,0,
  	0,660,661,5,61,0,0,661,662,1,0,0,0,662,663,6,68,65,0,663,138,1,0,0,0,
  	664,665,5,124,0,0,665,666,6,69,66,0,666,140,1,0,0,0,667,668,5,124,0,0,
  	668,669,5,61,0,0,669,670,1,0,0,0,670,671,6,70,67,0,671,142,1,0,0,0,672,
  	673,5,38,0,0,673,674,5,38,0,0,674,675,1,0,0,0,675,676,6,71,68,0,676,144,
  	1,0,0,0,677,678,5,38,0,0,678,679,5,38,0,0,679,680,5,38,0,0,680,681,1,
  	0,0,0,681,682,6,72,69,0,682,146,1,0,0,0,683,684,5,38,0,0,684,685,5,38,
  	0,0,685,686,5,61,0,0,686,687,1,0,0,0,687,688,6,73,70,0,688,148,1,0,0,
  	0,689,690,5,38,0,0,690,691,5,38,0,0,691,692,5,38,0,0,692,693,5,61,0,0,
  	693,694,1,0,0,0,694,695,6,74,71,0,695,150,1,0,0,0,696,697,5,94,0,0,697,
  	698,5,94,0,0,698,699,1,0,0,0,699,700,6,75,72,0,700,152,1,0,0,0,701,702,
  	5,94,0,0,702,703,5,94,0,0,703,704,5,61,0,0,704,705,1,0,0,0,705,706,6,
  	76,73,0,706,154,1,0,0,0,707,708,5,124,0,0,708,709,5,124,0,0,709,710,1,
  	0,0,0,710,711,6,77,74,0,711,156,1,0,0,0,712,713,5,124,0,0,713,714,5,124,
  	0,0,714,715,5,61,0,0,715,716,1,0,0,0,716,717,6,78,75,0,717,158,1,0,0,
  	0,718,719,5,124,0,0,719,720,5,124,0,0,720,721,5,124,0,0,721,722,1,0,0,
  	0,722,723,6,79,76,0,723,160,1,0,0,0,724,725,5,124,0,0,725,726,5,124,0,
  	0,726,727,5,124,0,0,727,728,5,61,0,0,728,729,1,0,0,0,729,730,6,80,77,
  	0,730,162,1,0,0,0,731,732,5,60,0,0,732,733,5,60,0,0,733,734,1,0,0,0,734,
  	735,6,81,78,0,735,164,1,0,0,0,736,737,5,60,0,0,737,738,5,60,0,0,738,739,
  	5,61,0,0,739,740,1,0,0,0,740,741,6,82,79,0,741,166,1,0,0,0,742,743,5,
  	62,0,0,743,744,5,62,0,0,744,745,1,0,0,0,745,746,6,83,80,0,746,168,1,0,
  	0,0,747,748,5,62,0,0,748,749,5,62,0,0,749,750,5,61,0,0,750,751,1,0,0,
  	0,751,752,6,84,81,0,752,170,1,0,0,0,753,754,5,46,0,0,754,755,5,46,0,0,
  	755,756,5,46,0,0,756,757,1,0,0,0,757,758,6,85,82,0,758,172,1,0,0,0,759,
  	760,5,58,0,0,760,761,5,42,0,0,761,762,1,0,0,0,762,763,6,86,83,0,763,174,
  	1,0,0,0,764,765,5,58,0,0,765,766,5,42,0,0,766,767,5,61,0,0,767,768,1,
  	0,0,0,768,769,6,87,84,0,769,176,1,0,0,0,770,771,5,46,0,0,771,772,5,61,
  	0,0,772,773,1,0,0,0,773,774,6,88,85,0,774,178,1,0,0,0,775,776,5,95,0,
  	0,776,777,5,61,0,0,777,778,1,0,0,0,778,779,6,89,86,0,779,180,1,0,0,0,
  	780,781,5,33,0,0,781,782,5,95,0,0,782,783,5,61,0,0,783,784,1,0,0,0,784,
  	785,6,90,87,0,785,182,1,0,0,0,786,787,4,91,2,0,787,788,5,40,0,0,788,789,
  	6,91,88,0,789,184,1,0,0,0,790,791,4,92,3,0,791,792,5,40,0,0,792,793,6,
  	92,89,0,793,186,1,0,0,0,794,796,9,0,0,0,795,794,1,0,0,0,796,797,1,0,0,
  	0,797,798,1,0,0,0,797,795,1,0,0,0,798,188,1,0,0,0,43,0,192,199,206,211,
  	214,218,223,225,230,234,239,241,247,252,259,264,268,273,278,285,363,366,
  	373,378,386,391,399,404,412,417,425,430,438,443,452,457,466,478,485,495,
  	499,797,90,1,0,0,1,1,1,1,2,2,1,6,3,1,7,4,1,8,5,1,9,6,1,10,7,1,11,8,1,
  	12,9,1,13,10,1,14,11,1,15,12,1,16,13,1,17,14,1,18,15,1,19,16,1,20,17,
  	1,21,18,1,22,19,1,23,20,1,24,21,1,25,22,1,26,23,1,27,24,1,29,25,1,30,
  	26,1,31,27,1,32,28,1,33,29,1,34,30,1,35,31,1,36,32,1,37,33,1,38,34,1,
  	39,35,0,1,0,1,40,36,1,41,37,1,42,38,1,43,39,1,44,40,1,45,41,1,46,42,1,
  	47,43,1,48,44,1,49,45,1,50,46,1,51,47,1,52,48,1,53,49,1,54,50,1,55,51,
  	1,56,52,1,57,53,1,58,54,1,59,55,1,60,56,1,61,57,1,62,58,1,63,59,1,64,
  	60,1,65,61,1,66,62,1,67,63,1,68,64,1,69,65,1,70,66,1,71,67,1,72,68,1,
  	73,69,1,74,70,1,75,71,1,76,72,1,77,73,1,78,74,1,79,75,1,80,76,1,81,77,
  	1,82,78,1,83,79,1,84,80,1,85,81,1,86,82,1,87,83,1,88,84,1,89,85,1,90,
  	86,1,91,87,1,92,88
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
    case 6: BACHNULLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 7: BACHNILAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 8: IFAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 9: THENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 10: ELSEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 11: WHILEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: FORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: DOAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: COLLECTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: FUNCTIONAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: INLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 17: INTINLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 18: RATINLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 19: FLOATINLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 20: PITCHINLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 21: OUTLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 22: DIRINLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 23: DIROUTLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 24: GLOBALVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 25: PATCHERVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 26: LOCALVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 27: NAMEDPARAMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 29: PUSHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 30: POPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 31: CLOSEDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 32: NTHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 33: PICKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 34: KEYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 35: ANTHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 36: APICKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 37: NULLIFYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 38: ASSIGNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 39: WHITESPACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 40: NEWATOMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 41: POWAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 42: APOWAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 43: TIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 44: ATIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 45: DIVDIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 46: ADIVDIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 47: DIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 48: ADIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 49: REMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 50: AREMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 51: PLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 52: APLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 53: UPLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 54: MINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 55: AMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 56: UMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 57: EQUALAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 58: NEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 59: LOGNOTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 60: BITNOTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 61: LTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 62: GTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 63: LEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 64: GEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 65: BITANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 66: ABITANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 67: BITXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 68: ABITXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 69: BITORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 70: ABITORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 71: LOGANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 72: LOGANDEXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 73: ALOGANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 74: ALOGANDEXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 75: LOGXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 76: ALOGXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 77: LOGORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 78: ALOGORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 79: LOGOREXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 80: ALOGOREXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 81: LSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 82: ALSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 83: RSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 84: ARSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 85: RANGEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 86: REPEATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 87: AREPEATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 88: AAPPLYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 89: ACONCATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 90: ARCONCATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 91: OPENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 92: PARAMSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool bellLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 51: return PLUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 54: return MINUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 91: return OPENSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 92: return PARAMSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

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

void bellLexer::BACHNULLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3:  noParams = false; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BACHNILAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4:  noParams = false; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::IFAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::THENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ELSEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 7:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::WHILEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 8:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::FORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 9:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DOAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 10:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::COLLECTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 11:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::FUNCTIONAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 12:  noParams = noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::INLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 13:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::INTINLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 14:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::RATINLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 15:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::FLOATINLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 16:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PITCHINLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 17:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::OUTLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 18:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::DIRINLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 19:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::DIROUTLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 20:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::GLOBALVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 21:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PATCHERVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::LOCALVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::NAMEDPARAMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  noParams = true; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PUSHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 25:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::POPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 26:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::CLOSEDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 27:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::NTHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 28:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PICKAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 29:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::KEYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 30:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ANTHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 31:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::APICKAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 32:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NULLIFYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 33:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ASSIGNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 34:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::WHITESPACEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 35:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NEWATOMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 36:  noParams = true; noUnary = false; (*codeac)++;  break;

  default:
    break;
  }
}

void bellLexer::POWAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 37:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::APOWAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 38:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::TIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 39:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ATIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 40:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVDIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 41:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ADIVDIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 42:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 43:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ADIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 44:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::REMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 45:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::AREMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 46:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 47:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::APLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 48:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UPLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 49:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::MINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 50:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::AMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 51:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 52:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::EQUALAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 53:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 54:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGNOTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 55:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITNOTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 56:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 57:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::GTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 58:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 59:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::GEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 60:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 61:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ABITANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 62:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 63:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ABITXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 64:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 65:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ABITORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 66:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 67:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGANDEXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 68:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 69:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGANDEXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 70:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 71:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 72:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 73:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 74:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGOREXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 75:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGOREXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 76:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 77:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 78:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::RSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 79:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ARSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 80:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::RANGEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 81:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::REPEATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 82:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::AREPEATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 83:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::AAPPLYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 84:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ACONCATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 85:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ARCONCATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 86:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::OPENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 87:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PARAMSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 88:  noParams = true; noUnary = false;  break;

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
