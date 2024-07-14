 
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
      "UINT", "UFLOAT", "UPITCH", "NOTENAME", "ACCIDENTAL", "RAT", "IF", 
      "THEN", "ELSE", "WHILE", "FOR", "DO", "COLLECT", "FUNCTION", "INLET", 
      "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "NAMEDPARAM", "ID", "PUSH", 
      "POP", "CLOSED", "NTH", "PICK", "KEY", "ANTH", "APICK", "AKEY", "NULLIFY", 
      "ASSIGN", "WHITESPACE", "NEWATOM", "POW", "APOW", "TIMES", "ATIMES", 
      "DIVDIV", "ADIVDIV", "DIV", "ADIV", "REM", "AREM", "PLUS", "APLUS", 
      "UPLUS", "MINUS", "AMINUS", "UMINUS", "EQUAL", "NEQ", "LOGNOT", "BITNOT", 
      "LT", "GT", "LEQ", "GEQ", "BITAND", "ABITAND", "BITXOR", "ABITXOR", 
      "BITOR", "ABITOR", "LOGAND", "LOGANDEXT", "ALOGAND", "ALOGANDEXT", 
      "LOGXOR", "ALOGXOR", "LOGOR", "ALOGOR", "LOGOREXT", "ALOGOREXT", "LSHIFT", 
      "ALSHIFT", "RSHIFT", "ARSHIFT", "RANGE", "REPEAT", "AREPEAT", "OPEN", 
      "PARAMS", "ANYTHING"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "", "", "'if'", "'then'", "'else'", "'while'", "'for'", "'do'", 
      "'collect'", "", "", "", "", "", "", "'['", "']'", "')'", "':'", "'::'", 
      "'.'", "':='", "'::='", "'.='", "';'", "'='", "", "", "'**'", "'**='", 
      "'*'", "'*='", "'//'", "'//='", "'/'", "'/='", "", "", "", "'+='", 
      "'+'", "", "'-='", "'-'", "'=='", "'!='", "'!'", "'~'", "'<'", "'>'", 
      "'<='", "'>='", "'&'", "'&='", "'^'", "'^='", "'|'", "'|='", "'&&'", 
      "'&&&'", "'&&='", "'&&&='", "'^^'", "'^^='", "'||'", "'||='", "'|||'", 
      "'|||='", "'<<'", "'<<='", "'>>'", "'>>='", "'...'", "':*'", "':*='"
    },
    std::vector<std::string>{
      "", "UINT", "UFLOAT", "UPITCH", "IF", "THEN", "ELSE", "WHILE", "FOR", 
      "DO", "COLLECT", "FUNCTION", "INLET", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", 
      "NAMEDPARAM", "PUSH", "POP", "CLOSED", "NTH", "PICK", "KEY", "ANTH", 
      "APICK", "AKEY", "NULLIFY", "ASSIGN", "WHITESPACE", "NEWATOM", "POW", 
      "APOW", "TIMES", "ATIMES", "DIVDIV", "ADIVDIV", "DIV", "ADIV", "REM", 
      "AREM", "PLUS", "APLUS", "UPLUS", "MINUS", "AMINUS", "UMINUS", "EQUAL", 
      "NEQ", "LOGNOT", "BITNOT", "LT", "GT", "LEQ", "GEQ", "BITAND", "ABITAND", 
      "BITXOR", "ABITXOR", "BITOR", "ABITOR", "LOGAND", "LOGANDEXT", "ALOGAND", 
      "ALOGANDEXT", "LOGXOR", "ALOGXOR", "LOGOR", "ALOGOR", "LOGOREXT", 
      "ALOGOREXT", "LSHIFT", "ALSHIFT", "RSHIFT", "ARSHIFT", "RANGE", "REPEAT", 
      "AREPEAT", "OPEN", "PARAMS", "ANYTHING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,79,651,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
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
  	7,77,2,78,7,78,2,79,7,79,2,80,7,80,2,81,7,81,2,82,7,82,1,0,4,0,169,8,
  	0,11,0,12,0,170,1,0,1,0,1,1,5,1,176,8,1,10,1,12,1,179,9,1,1,1,1,1,4,1,
  	183,8,1,11,1,12,1,184,1,1,4,1,188,8,1,11,1,12,1,189,1,1,3,1,193,8,1,1,
  	1,1,1,3,1,197,8,1,1,1,4,1,200,8,1,11,1,12,1,201,3,1,204,8,1,1,1,4,1,207,
  	8,1,11,1,12,1,208,1,1,1,1,3,1,213,8,1,1,1,4,1,216,8,1,11,1,12,1,217,3,
  	1,220,8,1,1,1,1,1,1,2,1,2,3,2,226,8,2,1,2,5,2,229,8,2,10,2,12,2,232,9,
  	2,1,2,1,2,5,2,236,8,2,10,2,12,2,239,9,2,1,2,1,2,3,2,243,8,2,1,2,1,2,3,
  	2,247,8,2,1,2,1,2,1,3,3,3,252,8,3,1,4,4,4,255,8,4,11,4,12,4,256,1,5,1,
  	5,1,5,5,5,262,8,5,10,5,12,5,265,9,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,
  	12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,329,8,13,1,14,1,14,1,14,4,
  	14,334,8,14,11,14,12,14,335,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,16,1,
  	16,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,19,1,19,5,19,357,8,19,10,
  	19,12,19,360,9,19,1,19,3,19,363,8,19,1,20,1,20,1,20,1,21,1,21,1,21,1,
  	22,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,25,1,
  	26,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,28,1,28,1,28,1,
  	28,1,28,1,29,1,29,1,29,1,30,1,30,1,30,1,31,1,31,1,31,1,31,1,31,1,32,1,
  	32,1,32,1,32,1,32,1,33,1,33,1,33,1,33,1,33,1,34,1,34,1,34,1,34,1,34,1,
  	34,1,35,1,35,1,35,1,36,1,36,1,36,1,36,1,36,1,37,1,37,1,37,1,37,1,37,1,
  	38,1,38,1,38,1,38,1,38,1,38,1,39,1,39,1,39,1,40,1,40,1,40,1,40,1,40,1,
  	41,1,41,1,41,1,42,1,42,1,42,1,43,1,43,1,43,1,43,1,44,1,44,1,44,1,44,1,
  	44,1,45,1,45,1,45,1,46,1,46,1,46,1,46,1,47,1,47,1,47,1,47,1,47,1,48,1,
  	48,1,48,1,49,1,49,1,49,1,49,1,49,1,50,1,50,1,50,1,50,1,50,1,51,1,51,1,
  	51,1,52,1,52,1,52,1,53,1,53,1,53,1,54,1,54,1,54,1,55,1,55,1,55,1,55,1,
  	55,1,56,1,56,1,56,1,56,1,56,1,57,1,57,1,57,1,58,1,58,1,58,1,58,1,58,1,
  	59,1,59,1,59,1,60,1,60,1,60,1,60,1,60,1,61,1,61,1,61,1,62,1,62,1,62,1,
  	62,1,62,1,63,1,63,1,63,1,63,1,63,1,64,1,64,1,64,1,64,1,64,1,64,1,65,1,
  	65,1,65,1,65,1,65,1,65,1,66,1,66,1,66,1,66,1,66,1,66,1,66,1,67,1,67,1,
  	67,1,67,1,67,1,68,1,68,1,68,1,68,1,68,1,68,1,69,1,69,1,69,1,69,1,69,1,
  	70,1,70,1,70,1,70,1,70,1,70,1,71,1,71,1,71,1,71,1,71,1,71,1,72,1,72,1,
  	72,1,72,1,72,1,72,1,72,1,73,1,73,1,73,1,73,1,73,1,74,1,74,1,74,1,74,1,
  	74,1,74,1,75,1,75,1,75,1,75,1,75,1,76,1,76,1,76,1,76,1,76,1,76,1,77,1,
  	77,1,77,1,77,1,77,1,77,1,78,1,78,1,78,1,78,1,78,1,79,1,79,1,79,1,79,1,
  	79,1,79,1,80,1,80,1,80,1,80,1,81,1,81,1,81,1,81,1,82,4,82,648,8,82,11,
  	82,12,82,649,1,649,0,83,1,1,3,2,5,3,7,0,9,0,11,0,13,4,15,5,17,6,19,7,
  	21,8,23,9,25,10,27,11,29,12,31,13,33,14,35,15,37,16,39,0,41,17,43,18,
  	45,19,47,20,49,21,51,22,53,23,55,24,57,25,59,26,61,27,63,28,65,29,67,
  	30,69,31,71,32,73,33,75,34,77,35,79,36,81,37,83,38,85,39,87,40,89,41,
  	91,42,93,43,95,44,97,45,99,46,101,47,103,48,105,49,107,50,109,51,111,
  	52,113,53,115,54,117,55,119,56,121,57,123,58,125,59,127,60,129,61,131,
  	62,133,63,135,64,137,65,139,66,141,67,143,68,145,69,147,70,149,71,151,
  	72,153,73,155,74,157,75,159,76,161,77,163,78,165,79,1,0,11,1,0,48,57,
  	2,0,69,69,101,101,2,0,43,43,45,45,2,0,65,71,97,103,7,0,35,35,94,94,98,
  	98,100,100,113,113,118,118,120,120,2,0,108,108,120,120,2,0,65,90,97,122,
  	4,0,48,57,65,90,95,95,97,122,3,0,48,57,65,90,97,122,3,0,9,10,13,13,32,
  	32,1,0,1,1,671,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,13,1,0,0,0,0,15,
  	1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,
  	0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,
  	0,37,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,
  	1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,
  	0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,
  	0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,
  	1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,
  	0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,0,
  	0,103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,0,111,1,0,0,0,
  	0,113,1,0,0,0,0,115,1,0,0,0,0,117,1,0,0,0,0,119,1,0,0,0,0,121,1,0,0,0,
  	0,123,1,0,0,0,0,125,1,0,0,0,0,127,1,0,0,0,0,129,1,0,0,0,0,131,1,0,0,0,
  	0,133,1,0,0,0,0,135,1,0,0,0,0,137,1,0,0,0,0,139,1,0,0,0,0,141,1,0,0,0,
  	0,143,1,0,0,0,0,145,1,0,0,0,0,147,1,0,0,0,0,149,1,0,0,0,0,151,1,0,0,0,
  	0,153,1,0,0,0,0,155,1,0,0,0,0,157,1,0,0,0,0,159,1,0,0,0,0,161,1,0,0,0,
  	0,163,1,0,0,0,0,165,1,0,0,0,1,168,1,0,0,0,3,219,1,0,0,0,5,223,1,0,0,0,
  	7,251,1,0,0,0,9,254,1,0,0,0,11,258,1,0,0,0,13,268,1,0,0,0,15,273,1,0,
  	0,0,17,280,1,0,0,0,19,287,1,0,0,0,21,295,1,0,0,0,23,301,1,0,0,0,25,306,
  	1,0,0,0,27,328,1,0,0,0,29,330,1,0,0,0,31,339,1,0,0,0,33,342,1,0,0,0,35,
  	346,1,0,0,0,37,350,1,0,0,0,39,354,1,0,0,0,41,364,1,0,0,0,43,367,1,0,0,
  	0,45,370,1,0,0,0,47,373,1,0,0,0,49,376,1,0,0,0,51,381,1,0,0,0,53,384,
  	1,0,0,0,55,389,1,0,0,0,57,395,1,0,0,0,59,400,1,0,0,0,61,403,1,0,0,0,63,
  	406,1,0,0,0,65,411,1,0,0,0,67,416,1,0,0,0,69,421,1,0,0,0,71,427,1,0,0,
  	0,73,430,1,0,0,0,75,435,1,0,0,0,77,440,1,0,0,0,79,446,1,0,0,0,81,449,
  	1,0,0,0,83,454,1,0,0,0,85,457,1,0,0,0,87,460,1,0,0,0,89,464,1,0,0,0,91,
  	469,1,0,0,0,93,472,1,0,0,0,95,476,1,0,0,0,97,481,1,0,0,0,99,484,1,0,0,
  	0,101,489,1,0,0,0,103,494,1,0,0,0,105,497,1,0,0,0,107,500,1,0,0,0,109,
  	503,1,0,0,0,111,506,1,0,0,0,113,511,1,0,0,0,115,516,1,0,0,0,117,519,1,
  	0,0,0,119,524,1,0,0,0,121,527,1,0,0,0,123,532,1,0,0,0,125,535,1,0,0,0,
  	127,540,1,0,0,0,129,545,1,0,0,0,131,551,1,0,0,0,133,557,1,0,0,0,135,564,
  	1,0,0,0,137,569,1,0,0,0,139,575,1,0,0,0,141,580,1,0,0,0,143,586,1,0,0,
  	0,145,592,1,0,0,0,147,599,1,0,0,0,149,604,1,0,0,0,151,610,1,0,0,0,153,
  	615,1,0,0,0,155,621,1,0,0,0,157,627,1,0,0,0,159,632,1,0,0,0,161,638,1,
  	0,0,0,163,642,1,0,0,0,165,647,1,0,0,0,167,169,7,0,0,0,168,167,1,0,0,0,
  	169,170,1,0,0,0,170,168,1,0,0,0,170,171,1,0,0,0,171,172,1,0,0,0,172,173,
  	6,0,0,0,173,2,1,0,0,0,174,176,7,0,0,0,175,174,1,0,0,0,176,179,1,0,0,0,
  	177,175,1,0,0,0,177,178,1,0,0,0,178,180,1,0,0,0,179,177,1,0,0,0,180,182,
  	5,46,0,0,181,183,7,0,0,0,182,181,1,0,0,0,183,184,1,0,0,0,184,182,1,0,
  	0,0,184,185,1,0,0,0,185,193,1,0,0,0,186,188,7,0,0,0,187,186,1,0,0,0,188,
  	189,1,0,0,0,189,187,1,0,0,0,189,190,1,0,0,0,190,191,1,0,0,0,191,193,5,
  	46,0,0,192,177,1,0,0,0,192,187,1,0,0,0,193,203,1,0,0,0,194,196,7,1,0,
  	0,195,197,7,2,0,0,196,195,1,0,0,0,196,197,1,0,0,0,197,199,1,0,0,0,198,
  	200,7,0,0,0,199,198,1,0,0,0,200,201,1,0,0,0,201,199,1,0,0,0,201,202,1,
  	0,0,0,202,204,1,0,0,0,203,194,1,0,0,0,203,204,1,0,0,0,204,220,1,0,0,0,
  	205,207,7,0,0,0,206,205,1,0,0,0,207,208,1,0,0,0,208,206,1,0,0,0,208,209,
  	1,0,0,0,209,210,1,0,0,0,210,212,7,1,0,0,211,213,7,2,0,0,212,211,1,0,0,
  	0,212,213,1,0,0,0,213,215,1,0,0,0,214,216,7,0,0,0,215,214,1,0,0,0,216,
  	217,1,0,0,0,217,215,1,0,0,0,217,218,1,0,0,0,218,220,1,0,0,0,219,192,1,
  	0,0,0,219,206,1,0,0,0,220,221,1,0,0,0,221,222,6,1,1,0,222,4,1,0,0,0,223,
  	225,3,7,3,0,224,226,3,9,4,0,225,224,1,0,0,0,225,226,1,0,0,0,226,230,1,
  	0,0,0,227,229,7,2,0,0,228,227,1,0,0,0,229,232,1,0,0,0,230,228,1,0,0,0,
  	230,231,1,0,0,0,231,233,1,0,0,0,232,230,1,0,0,0,233,246,3,1,0,0,234,236,
  	7,2,0,0,235,234,1,0,0,0,236,239,1,0,0,0,237,235,1,0,0,0,237,238,1,0,0,
  	0,238,242,1,0,0,0,239,237,1,0,0,0,240,243,3,1,0,0,241,243,3,11,5,0,242,
  	240,1,0,0,0,242,241,1,0,0,0,243,244,1,0,0,0,244,245,5,116,0,0,245,247,
  	1,0,0,0,246,237,1,0,0,0,246,247,1,0,0,0,247,248,1,0,0,0,248,249,6,2,2,
  	0,249,6,1,0,0,0,250,252,7,3,0,0,251,250,1,0,0,0,252,8,1,0,0,0,253,255,
  	7,4,0,0,254,253,1,0,0,0,255,256,1,0,0,0,256,254,1,0,0,0,256,257,1,0,0,
  	0,257,10,1,0,0,0,258,259,3,1,0,0,259,263,5,47,0,0,260,262,7,2,0,0,261,
  	260,1,0,0,0,262,265,1,0,0,0,263,261,1,0,0,0,263,264,1,0,0,0,264,266,1,
  	0,0,0,265,263,1,0,0,0,266,267,3,1,0,0,267,12,1,0,0,0,268,269,5,105,0,
  	0,269,270,5,102,0,0,270,271,1,0,0,0,271,272,6,6,3,0,272,14,1,0,0,0,273,
  	274,5,116,0,0,274,275,5,104,0,0,275,276,5,101,0,0,276,277,5,110,0,0,277,
  	278,1,0,0,0,278,279,6,7,4,0,279,16,1,0,0,0,280,281,5,101,0,0,281,282,
  	5,108,0,0,282,283,5,115,0,0,283,284,5,101,0,0,284,285,1,0,0,0,285,286,
  	6,8,5,0,286,18,1,0,0,0,287,288,5,119,0,0,288,289,5,104,0,0,289,290,5,
  	105,0,0,290,291,5,108,0,0,291,292,5,101,0,0,292,293,1,0,0,0,293,294,6,
  	9,6,0,294,20,1,0,0,0,295,296,5,102,0,0,296,297,5,111,0,0,297,298,5,114,
  	0,0,298,299,1,0,0,0,299,300,6,10,7,0,300,22,1,0,0,0,301,302,5,100,0,0,
  	302,303,5,111,0,0,303,304,1,0,0,0,304,305,6,11,8,0,305,24,1,0,0,0,306,
  	307,5,99,0,0,307,308,5,111,0,0,308,309,5,108,0,0,309,310,5,108,0,0,310,
  	311,5,101,0,0,311,312,5,99,0,0,312,313,5,116,0,0,313,314,1,0,0,0,314,
  	315,6,12,9,0,315,26,1,0,0,0,316,317,5,115,0,0,317,318,5,105,0,0,318,329,
  	5,110,0,0,319,320,5,99,0,0,320,321,5,111,0,0,321,329,5,115,0,0,322,323,
  	5,115,0,0,323,324,5,113,0,0,324,325,5,114,0,0,325,326,5,116,0,0,326,327,
  	1,0,0,0,327,329,6,13,10,0,328,316,1,0,0,0,328,319,1,0,0,0,328,322,1,0,
  	0,0,329,28,1,0,0,0,330,331,5,36,0,0,331,333,7,5,0,0,332,334,7,0,0,0,333,
  	332,1,0,0,0,334,335,1,0,0,0,335,333,1,0,0,0,335,336,1,0,0,0,336,337,1,
  	0,0,0,337,338,6,14,11,0,338,30,1,0,0,0,339,340,3,39,19,0,340,341,6,15,
  	12,0,341,32,1,0,0,0,342,343,5,35,0,0,343,344,3,39,19,0,344,345,6,16,13,
  	0,345,34,1,0,0,0,346,347,5,36,0,0,347,348,3,39,19,0,348,349,6,17,14,0,
  	349,36,1,0,0,0,350,351,5,64,0,0,351,352,3,39,19,0,352,353,6,18,15,0,353,
  	38,1,0,0,0,354,362,7,6,0,0,355,357,7,7,0,0,356,355,1,0,0,0,357,360,1,
  	0,0,0,358,356,1,0,0,0,358,359,1,0,0,0,359,361,1,0,0,0,360,358,1,0,0,0,
  	361,363,7,8,0,0,362,358,1,0,0,0,362,363,1,0,0,0,363,40,1,0,0,0,364,365,
  	5,91,0,0,365,366,6,20,16,0,366,42,1,0,0,0,367,368,5,93,0,0,368,369,6,
  	21,17,0,369,44,1,0,0,0,370,371,5,41,0,0,371,372,6,22,18,0,372,46,1,0,
  	0,0,373,374,5,58,0,0,374,375,6,23,19,0,375,48,1,0,0,0,376,377,5,58,0,
  	0,377,378,5,58,0,0,378,379,1,0,0,0,379,380,6,24,20,0,380,50,1,0,0,0,381,
  	382,5,46,0,0,382,383,6,25,21,0,383,52,1,0,0,0,384,385,5,58,0,0,385,386,
  	5,61,0,0,386,387,1,0,0,0,387,388,6,26,22,0,388,54,1,0,0,0,389,390,5,58,
  	0,0,390,391,5,58,0,0,391,392,5,61,0,0,392,393,1,0,0,0,393,394,6,27,23,
  	0,394,56,1,0,0,0,395,396,5,46,0,0,396,397,5,61,0,0,397,398,1,0,0,0,398,
  	399,6,28,24,0,399,58,1,0,0,0,400,401,5,59,0,0,401,402,6,29,25,0,402,60,
  	1,0,0,0,403,404,5,61,0,0,404,405,6,30,26,0,405,62,1,0,0,0,406,407,7,9,
  	0,0,407,408,6,31,27,0,408,409,1,0,0,0,409,410,6,31,28,0,410,64,1,0,0,
  	0,411,412,7,10,0,0,412,413,6,32,29,0,413,414,1,0,0,0,414,415,6,32,28,
  	0,415,66,1,0,0,0,416,417,5,42,0,0,417,418,5,42,0,0,418,419,1,0,0,0,419,
  	420,6,33,30,0,420,68,1,0,0,0,421,422,5,42,0,0,422,423,5,42,0,0,423,424,
  	5,61,0,0,424,425,1,0,0,0,425,426,6,34,31,0,426,70,1,0,0,0,427,428,5,42,
  	0,0,428,429,6,35,32,0,429,72,1,0,0,0,430,431,5,42,0,0,431,432,5,61,0,
  	0,432,433,1,0,0,0,433,434,6,36,33,0,434,74,1,0,0,0,435,436,5,47,0,0,436,
  	437,5,47,0,0,437,438,1,0,0,0,438,439,6,37,34,0,439,76,1,0,0,0,440,441,
  	5,47,0,0,441,442,5,47,0,0,442,443,5,61,0,0,443,444,1,0,0,0,444,445,6,
  	38,35,0,445,78,1,0,0,0,446,447,5,47,0,0,447,448,6,39,36,0,448,80,1,0,
  	0,0,449,450,5,47,0,0,450,451,5,61,0,0,451,452,1,0,0,0,452,453,6,40,37,
  	0,453,82,1,0,0,0,454,455,5,37,0,0,455,456,6,41,38,0,456,84,1,0,0,0,457,
  	458,5,37,0,0,458,459,6,42,39,0,459,86,1,0,0,0,460,461,4,43,0,0,461,462,
  	5,43,0,0,462,463,6,43,40,0,463,88,1,0,0,0,464,465,5,43,0,0,465,466,5,
  	61,0,0,466,467,1,0,0,0,467,468,6,44,41,0,468,90,1,0,0,0,469,470,5,43,
  	0,0,470,471,6,45,42,0,471,92,1,0,0,0,472,473,4,46,1,0,473,474,5,45,0,
  	0,474,475,6,46,43,0,475,94,1,0,0,0,476,477,5,45,0,0,477,478,5,61,0,0,
  	478,479,1,0,0,0,479,480,6,47,44,0,480,96,1,0,0,0,481,482,5,45,0,0,482,
  	483,6,48,45,0,483,98,1,0,0,0,484,485,5,61,0,0,485,486,5,61,0,0,486,487,
  	1,0,0,0,487,488,6,49,46,0,488,100,1,0,0,0,489,490,5,33,0,0,490,491,5,
  	61,0,0,491,492,1,0,0,0,492,493,6,50,47,0,493,102,1,0,0,0,494,495,5,33,
  	0,0,495,496,6,51,48,0,496,104,1,0,0,0,497,498,5,126,0,0,498,499,6,52,
  	49,0,499,106,1,0,0,0,500,501,5,60,0,0,501,502,6,53,50,0,502,108,1,0,0,
  	0,503,504,5,62,0,0,504,505,6,54,51,0,505,110,1,0,0,0,506,507,5,60,0,0,
  	507,508,5,61,0,0,508,509,1,0,0,0,509,510,6,55,52,0,510,112,1,0,0,0,511,
  	512,5,62,0,0,512,513,5,61,0,0,513,514,1,0,0,0,514,515,6,56,53,0,515,114,
  	1,0,0,0,516,517,5,38,0,0,517,518,6,57,54,0,518,116,1,0,0,0,519,520,5,
  	38,0,0,520,521,5,61,0,0,521,522,1,0,0,0,522,523,6,58,55,0,523,118,1,0,
  	0,0,524,525,5,94,0,0,525,526,6,59,56,0,526,120,1,0,0,0,527,528,5,94,0,
  	0,528,529,5,61,0,0,529,530,1,0,0,0,530,531,6,60,57,0,531,122,1,0,0,0,
  	532,533,5,124,0,0,533,534,6,61,58,0,534,124,1,0,0,0,535,536,5,124,0,0,
  	536,537,5,61,0,0,537,538,1,0,0,0,538,539,6,62,59,0,539,126,1,0,0,0,540,
  	541,5,38,0,0,541,542,5,38,0,0,542,543,1,0,0,0,543,544,6,63,60,0,544,128,
  	1,0,0,0,545,546,5,38,0,0,546,547,5,38,0,0,547,548,5,38,0,0,548,549,1,
  	0,0,0,549,550,6,64,61,0,550,130,1,0,0,0,551,552,5,38,0,0,552,553,5,38,
  	0,0,553,554,5,61,0,0,554,555,1,0,0,0,555,556,6,65,62,0,556,132,1,0,0,
  	0,557,558,5,38,0,0,558,559,5,38,0,0,559,560,5,38,0,0,560,561,5,61,0,0,
  	561,562,1,0,0,0,562,563,6,66,63,0,563,134,1,0,0,0,564,565,5,94,0,0,565,
  	566,5,94,0,0,566,567,1,0,0,0,567,568,6,67,64,0,568,136,1,0,0,0,569,570,
  	5,94,0,0,570,571,5,94,0,0,571,572,5,61,0,0,572,573,1,0,0,0,573,574,6,
  	68,65,0,574,138,1,0,0,0,575,576,5,124,0,0,576,577,5,124,0,0,577,578,1,
  	0,0,0,578,579,6,69,66,0,579,140,1,0,0,0,580,581,5,124,0,0,581,582,5,124,
  	0,0,582,583,5,61,0,0,583,584,1,0,0,0,584,585,6,70,67,0,585,142,1,0,0,
  	0,586,587,5,124,0,0,587,588,5,124,0,0,588,589,5,124,0,0,589,590,1,0,0,
  	0,590,591,6,71,68,0,591,144,1,0,0,0,592,593,5,124,0,0,593,594,5,124,0,
  	0,594,595,5,124,0,0,595,596,5,61,0,0,596,597,1,0,0,0,597,598,6,72,69,
  	0,598,146,1,0,0,0,599,600,5,60,0,0,600,601,5,60,0,0,601,602,1,0,0,0,602,
  	603,6,73,70,0,603,148,1,0,0,0,604,605,5,60,0,0,605,606,5,60,0,0,606,607,
  	5,61,0,0,607,608,1,0,0,0,608,609,6,74,71,0,609,150,1,0,0,0,610,611,5,
  	62,0,0,611,612,5,62,0,0,612,613,1,0,0,0,613,614,6,75,72,0,614,152,1,0,
  	0,0,615,616,5,62,0,0,616,617,5,62,0,0,617,618,5,61,0,0,618,619,1,0,0,
  	0,619,620,6,76,73,0,620,154,1,0,0,0,621,622,5,46,0,0,622,623,5,46,0,0,
  	623,624,5,46,0,0,624,625,1,0,0,0,625,626,6,77,74,0,626,156,1,0,0,0,627,
  	628,5,58,0,0,628,629,5,42,0,0,629,630,1,0,0,0,630,631,6,78,75,0,631,158,
  	1,0,0,0,632,633,5,58,0,0,633,634,5,42,0,0,634,635,5,61,0,0,635,636,1,
  	0,0,0,636,637,6,79,76,0,637,160,1,0,0,0,638,639,4,80,2,0,639,640,5,40,
  	0,0,640,641,6,80,77,0,641,162,1,0,0,0,642,643,4,81,3,0,643,644,5,40,0,
  	0,644,645,6,81,78,0,645,164,1,0,0,0,646,648,9,0,0,0,647,646,1,0,0,0,648,
  	649,1,0,0,0,649,650,1,0,0,0,649,647,1,0,0,0,650,166,1,0,0,0,26,0,170,
  	177,184,189,192,196,201,203,208,212,217,219,225,230,237,242,246,251,256,
  	263,328,335,358,362,649,79,1,0,0,1,1,1,1,2,2,1,6,3,1,7,4,1,8,5,1,9,6,
  	1,10,7,1,11,8,1,12,9,1,13,10,1,14,11,1,15,12,1,16,13,1,17,14,1,18,15,
  	1,20,16,1,21,17,1,22,18,1,23,19,1,24,20,1,25,21,1,26,22,1,27,23,1,28,
  	24,1,29,25,1,30,26,1,31,27,0,1,0,1,32,28,1,33,29,1,34,30,1,35,31,1,36,
  	32,1,37,33,1,38,34,1,39,35,1,40,36,1,41,37,1,42,38,1,43,39,1,44,40,1,
  	45,41,1,46,42,1,47,43,1,48,44,1,49,45,1,50,46,1,51,47,1,52,48,1,53,49,
  	1,54,50,1,55,51,1,56,52,1,57,53,1,58,54,1,59,55,1,60,56,1,61,57,1,62,
  	58,1,63,59,1,64,60,1,65,61,1,66,62,1,67,63,1,68,64,1,69,65,1,70,66,1,
  	71,67,1,72,68,1,73,69,1,74,70,1,75,71,1,76,72,1,77,73,1,78,74,1,79,75,
  	1,80,76,1,81,77
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
    case 6: IFAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 7: THENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 8: ELSEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 9: WHILEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 10: FORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 11: DOAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: COLLECTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: FUNCTIONAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: INLETAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: GLOBALVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: PATCHERVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 17: LOCALVARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 18: NAMEDPARAMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 20: PUSHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 21: POPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 22: CLOSEDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 23: NTHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 24: PICKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 25: KEYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 26: ANTHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 27: APICKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 28: AKEYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 29: NULLIFYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 30: ASSIGNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 31: WHITESPACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 32: NEWATOMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 33: POWAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 34: APOWAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 35: TIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 36: ATIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 37: DIVDIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 38: ADIVDIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 39: DIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 40: ADIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 41: REMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 42: AREMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 43: PLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 44: APLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 45: UPLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 46: MINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 47: AMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 48: UMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 49: EQUALAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 50: NEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 51: LOGNOTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 52: BITNOTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 53: LTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 54: GTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 55: LEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 56: GEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 57: BITANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 58: ABITANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 59: BITXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 60: ABITXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 61: BITORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 62: ABITORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 63: LOGANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 64: LOGANDEXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 65: ALOGANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 66: ALOGANDEXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 67: LOGXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 68: ALOGXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 69: LOGORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 70: ALOGORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 71: LOGOREXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 72: ALOGOREXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 73: LSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 74: ALSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 75: RSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 76: ARSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 77: RANGEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 78: REPEATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 79: AREPEATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 80: OPENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 81: PARAMSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool bellLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 43: return PLUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 46: return MINUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 80: return OPENSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 81: return PARAMSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

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

void bellLexer::IFAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::THENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ELSEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::WHILEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::FORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 7:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DOAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 8:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::COLLECTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 9:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::FUNCTIONAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 10:  noParams = noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::INLETAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 11:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::GLOBALVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 12:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PATCHERVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 13:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::LOCALVARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 14:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::NAMEDPARAMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 15:  noParams = true; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PUSHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 16:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::POPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 17:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::CLOSEDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 18:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::NTHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 19:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PICKAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 20:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::KEYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 21:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ANTHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::APICKAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::AKEYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NULLIFYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 25:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ASSIGNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 26:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::WHITESPACEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 27:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NEWATOMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 28:  noParams = true; noUnary = false; (*codeac)++;  break;

  default:
    break;
  }
}

void bellLexer::POWAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 29:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::APOWAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 30:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::TIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 31:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ATIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 32:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVDIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 33:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ADIVDIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 34:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 35:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ADIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 36:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::REMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 37:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::AREMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 38:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 39:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::APLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 40:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UPLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 41:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::MINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 42:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::AMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 43:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 44:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::EQUALAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 45:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 46:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGNOTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 47:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITNOTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 48:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 49:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::GTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 50:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 51:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::GEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 52:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 53:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ABITANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 54:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 55:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ABITXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 56:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 57:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ABITORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 58:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 59:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGANDEXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 60:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 61:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGANDEXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 62:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 63:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 64:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 65:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 66:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGOREXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 67:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALOGOREXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 68:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 69:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ALSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 70:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::RSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 71:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ARSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 72:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::RANGEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 73:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::REPEATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 74:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::AREPEATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 75:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::OPENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 76:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PARAMSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 77:  noParams = true; noUnary = false;  break;

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
