 
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
      "POP", "CLOSED", "NTH", "PICK", "KEY", "NULLIFY", "ASSIGN", "WHITESPACE", 
      "NEWATOM", "POW", "TIMES", "DIVDIV", "DIV", "PLUS", "UPLUS", "MINUS", 
      "UMINUS", "REM", "EQUAL", "NEQ", "LOGNOT", "BITNOT", "LT", "GT", "LEQ", 
      "GEQ", "BITAND", "BITXOR", "BITOR", "LOGAND", "LOGANDEXT", "LOGXOR", 
      "LOGOR", "LOGOREXT", "LSHIFT", "RSHIFT", "RANGE", "REPEAT", "OPEN", 
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
      "'.'", "';'", "'='", "", "", "'**'", "'*'", "'//'", "'/'", "", "'+'", 
      "", "'-'", "'%'", "'=='", "'!='", "'!'", "'~'", "'<'", "'>'", "'<='", 
      "'>='", "'&'", "'^'", "'|'", "'&&'", "'&&&'", "'^^'", "'||'", "'|||'", 
      "'<<'", "'>>'", "'...'", "':*'"
    },
    std::vector<std::string>{
      "", "UINT", "UFLOAT", "UPITCH", "IF", "THEN", "ELSE", "WHILE", "FOR", 
      "DO", "COLLECT", "FUNCTION", "INLET", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", 
      "NAMEDPARAM", "PUSH", "POP", "CLOSED", "NTH", "PICK", "KEY", "NULLIFY", 
      "ASSIGN", "WHITESPACE", "NEWATOM", "POW", "TIMES", "DIVDIV", "DIV", 
      "PLUS", "UPLUS", "MINUS", "UMINUS", "REM", "EQUAL", "NEQ", "LOGNOT", 
      "BITNOT", "LT", "GT", "LEQ", "GEQ", "BITAND", "BITXOR", "BITOR", "LOGAND", 
      "LOGANDEXT", "LOGXOR", "LOGOR", "LOGOREXT", "LSHIFT", "RSHIFT", "RANGE", 
      "REPEAT", "OPEN", "PARAMS", "ANYTHING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,58,493,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,1,0,4,0,127,8,
  	0,11,0,12,0,128,1,0,1,0,1,1,5,1,134,8,1,10,1,12,1,137,9,1,1,1,1,1,4,1,
  	141,8,1,11,1,12,1,142,1,1,4,1,146,8,1,11,1,12,1,147,1,1,3,1,151,8,1,1,
  	1,1,1,3,1,155,8,1,1,1,4,1,158,8,1,11,1,12,1,159,3,1,162,8,1,1,1,4,1,165,
  	8,1,11,1,12,1,166,1,1,1,1,3,1,171,8,1,1,1,4,1,174,8,1,11,1,12,1,175,3,
  	1,178,8,1,1,1,1,1,1,2,1,2,3,2,184,8,2,1,2,5,2,187,8,2,10,2,12,2,190,9,
  	2,1,2,1,2,5,2,194,8,2,10,2,12,2,197,9,2,1,2,1,2,3,2,201,8,2,1,2,1,2,3,
  	2,205,8,2,1,2,1,2,1,3,3,3,210,8,3,1,4,4,4,213,8,4,11,4,12,4,214,1,5,1,
  	5,1,5,5,5,220,8,5,10,5,12,5,223,9,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,
  	12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,287,8,13,1,14,1,14,1,14,4,
  	14,292,8,14,11,14,12,14,293,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,16,1,
  	16,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,19,1,19,5,19,315,8,19,10,
  	19,12,19,318,9,19,1,19,3,19,321,8,19,1,20,1,20,1,20,1,21,1,21,1,21,1,
  	22,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,25,1,
  	26,1,26,1,26,1,27,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,29,1,29,1,29,1,
  	29,1,29,1,30,1,30,1,30,1,30,1,30,1,31,1,31,1,31,1,32,1,32,1,32,1,32,1,
  	32,1,33,1,33,1,33,1,34,1,34,1,34,1,34,1,35,1,35,1,35,1,36,1,36,1,36,1,
  	36,1,37,1,37,1,37,1,38,1,38,1,38,1,39,1,39,1,39,1,39,1,39,1,40,1,40,1,
  	40,1,40,1,40,1,41,1,41,1,41,1,42,1,42,1,42,1,43,1,43,1,43,1,44,1,44,1,
  	44,1,45,1,45,1,45,1,45,1,45,1,46,1,46,1,46,1,46,1,46,1,47,1,47,1,47,1,
  	48,1,48,1,48,1,49,1,49,1,49,1,50,1,50,1,50,1,50,1,50,1,51,1,51,1,51,1,
  	51,1,51,1,51,1,52,1,52,1,52,1,52,1,52,1,53,1,53,1,53,1,53,1,53,1,54,1,
  	54,1,54,1,54,1,54,1,54,1,55,1,55,1,55,1,55,1,55,1,56,1,56,1,56,1,56,1,
  	56,1,57,1,57,1,57,1,57,1,57,1,57,1,58,1,58,1,58,1,58,1,58,1,59,1,59,1,
  	59,1,59,1,60,1,60,1,60,1,60,1,61,4,61,490,8,61,11,61,12,61,491,1,491,
  	0,62,1,1,3,2,5,3,7,0,9,0,11,0,13,4,15,5,17,6,19,7,21,8,23,9,25,10,27,
  	11,29,12,31,13,33,14,35,15,37,16,39,0,41,17,43,18,45,19,47,20,49,21,51,
  	22,53,23,55,24,57,25,59,26,61,27,63,28,65,29,67,30,69,31,71,32,73,33,
  	75,34,77,35,79,36,81,37,83,38,85,39,87,40,89,41,91,42,93,43,95,44,97,
  	45,99,46,101,47,103,48,105,49,107,50,109,51,111,52,113,53,115,54,117,
  	55,119,56,121,57,123,58,1,0,11,1,0,48,57,2,0,69,69,101,101,2,0,43,43,
  	45,45,2,0,65,71,97,103,7,0,35,35,94,94,98,98,100,100,113,113,118,118,
  	120,120,2,0,108,108,120,120,2,0,65,90,97,122,4,0,48,57,65,90,95,95,97,
  	122,3,0,48,57,65,90,97,122,3,0,9,10,13,13,32,32,1,0,1,1,513,0,1,1,0,0,
  	0,0,3,1,0,0,0,0,5,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,
  	1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,
  	0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,41,1,0,0,0,
  	0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,
  	1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,
  	0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,
  	0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,
  	1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,0,0,0,93,1,0,0,0,0,95,1,0,
  	0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,0,0,103,1,0,0,0,0,105,1,0,0,
  	0,0,107,1,0,0,0,0,109,1,0,0,0,0,111,1,0,0,0,0,113,1,0,0,0,0,115,1,0,0,
  	0,0,117,1,0,0,0,0,119,1,0,0,0,0,121,1,0,0,0,0,123,1,0,0,0,1,126,1,0,0,
  	0,3,177,1,0,0,0,5,181,1,0,0,0,7,209,1,0,0,0,9,212,1,0,0,0,11,216,1,0,
  	0,0,13,226,1,0,0,0,15,231,1,0,0,0,17,238,1,0,0,0,19,245,1,0,0,0,21,253,
  	1,0,0,0,23,259,1,0,0,0,25,264,1,0,0,0,27,286,1,0,0,0,29,288,1,0,0,0,31,
  	297,1,0,0,0,33,300,1,0,0,0,35,304,1,0,0,0,37,308,1,0,0,0,39,312,1,0,0,
  	0,41,322,1,0,0,0,43,325,1,0,0,0,45,328,1,0,0,0,47,331,1,0,0,0,49,334,
  	1,0,0,0,51,339,1,0,0,0,53,342,1,0,0,0,55,345,1,0,0,0,57,348,1,0,0,0,59,
  	353,1,0,0,0,61,358,1,0,0,0,63,363,1,0,0,0,65,366,1,0,0,0,67,371,1,0,0,
  	0,69,374,1,0,0,0,71,378,1,0,0,0,73,381,1,0,0,0,75,385,1,0,0,0,77,388,
  	1,0,0,0,79,391,1,0,0,0,81,396,1,0,0,0,83,401,1,0,0,0,85,404,1,0,0,0,87,
  	407,1,0,0,0,89,410,1,0,0,0,91,413,1,0,0,0,93,418,1,0,0,0,95,423,1,0,0,
  	0,97,426,1,0,0,0,99,429,1,0,0,0,101,432,1,0,0,0,103,437,1,0,0,0,105,443,
  	1,0,0,0,107,448,1,0,0,0,109,453,1,0,0,0,111,459,1,0,0,0,113,464,1,0,0,
  	0,115,469,1,0,0,0,117,475,1,0,0,0,119,480,1,0,0,0,121,484,1,0,0,0,123,
  	489,1,0,0,0,125,127,7,0,0,0,126,125,1,0,0,0,127,128,1,0,0,0,128,126,1,
  	0,0,0,128,129,1,0,0,0,129,130,1,0,0,0,130,131,6,0,0,0,131,2,1,0,0,0,132,
  	134,7,0,0,0,133,132,1,0,0,0,134,137,1,0,0,0,135,133,1,0,0,0,135,136,1,
  	0,0,0,136,138,1,0,0,0,137,135,1,0,0,0,138,140,5,46,0,0,139,141,7,0,0,
  	0,140,139,1,0,0,0,141,142,1,0,0,0,142,140,1,0,0,0,142,143,1,0,0,0,143,
  	151,1,0,0,0,144,146,7,0,0,0,145,144,1,0,0,0,146,147,1,0,0,0,147,145,1,
  	0,0,0,147,148,1,0,0,0,148,149,1,0,0,0,149,151,5,46,0,0,150,135,1,0,0,
  	0,150,145,1,0,0,0,151,161,1,0,0,0,152,154,7,1,0,0,153,155,7,2,0,0,154,
  	153,1,0,0,0,154,155,1,0,0,0,155,157,1,0,0,0,156,158,7,0,0,0,157,156,1,
  	0,0,0,158,159,1,0,0,0,159,157,1,0,0,0,159,160,1,0,0,0,160,162,1,0,0,0,
  	161,152,1,0,0,0,161,162,1,0,0,0,162,178,1,0,0,0,163,165,7,0,0,0,164,163,
  	1,0,0,0,165,166,1,0,0,0,166,164,1,0,0,0,166,167,1,0,0,0,167,168,1,0,0,
  	0,168,170,7,1,0,0,169,171,7,2,0,0,170,169,1,0,0,0,170,171,1,0,0,0,171,
  	173,1,0,0,0,172,174,7,0,0,0,173,172,1,0,0,0,174,175,1,0,0,0,175,173,1,
  	0,0,0,175,176,1,0,0,0,176,178,1,0,0,0,177,150,1,0,0,0,177,164,1,0,0,0,
  	178,179,1,0,0,0,179,180,6,1,1,0,180,4,1,0,0,0,181,183,3,7,3,0,182,184,
  	3,9,4,0,183,182,1,0,0,0,183,184,1,0,0,0,184,188,1,0,0,0,185,187,7,2,0,
  	0,186,185,1,0,0,0,187,190,1,0,0,0,188,186,1,0,0,0,188,189,1,0,0,0,189,
  	191,1,0,0,0,190,188,1,0,0,0,191,204,3,1,0,0,192,194,7,2,0,0,193,192,1,
  	0,0,0,194,197,1,0,0,0,195,193,1,0,0,0,195,196,1,0,0,0,196,200,1,0,0,0,
  	197,195,1,0,0,0,198,201,3,1,0,0,199,201,3,11,5,0,200,198,1,0,0,0,200,
  	199,1,0,0,0,201,202,1,0,0,0,202,203,5,116,0,0,203,205,1,0,0,0,204,195,
  	1,0,0,0,204,205,1,0,0,0,205,206,1,0,0,0,206,207,6,2,2,0,207,6,1,0,0,0,
  	208,210,7,3,0,0,209,208,1,0,0,0,210,8,1,0,0,0,211,213,7,4,0,0,212,211,
  	1,0,0,0,213,214,1,0,0,0,214,212,1,0,0,0,214,215,1,0,0,0,215,10,1,0,0,
  	0,216,217,3,1,0,0,217,221,5,47,0,0,218,220,7,2,0,0,219,218,1,0,0,0,220,
  	223,1,0,0,0,221,219,1,0,0,0,221,222,1,0,0,0,222,224,1,0,0,0,223,221,1,
  	0,0,0,224,225,3,1,0,0,225,12,1,0,0,0,226,227,5,105,0,0,227,228,5,102,
  	0,0,228,229,1,0,0,0,229,230,6,6,3,0,230,14,1,0,0,0,231,232,5,116,0,0,
  	232,233,5,104,0,0,233,234,5,101,0,0,234,235,5,110,0,0,235,236,1,0,0,0,
  	236,237,6,7,4,0,237,16,1,0,0,0,238,239,5,101,0,0,239,240,5,108,0,0,240,
  	241,5,115,0,0,241,242,5,101,0,0,242,243,1,0,0,0,243,244,6,8,5,0,244,18,
  	1,0,0,0,245,246,5,119,0,0,246,247,5,104,0,0,247,248,5,105,0,0,248,249,
  	5,108,0,0,249,250,5,101,0,0,250,251,1,0,0,0,251,252,6,9,6,0,252,20,1,
  	0,0,0,253,254,5,102,0,0,254,255,5,111,0,0,255,256,5,114,0,0,256,257,1,
  	0,0,0,257,258,6,10,7,0,258,22,1,0,0,0,259,260,5,100,0,0,260,261,5,111,
  	0,0,261,262,1,0,0,0,262,263,6,11,8,0,263,24,1,0,0,0,264,265,5,99,0,0,
  	265,266,5,111,0,0,266,267,5,108,0,0,267,268,5,108,0,0,268,269,5,101,0,
  	0,269,270,5,99,0,0,270,271,5,116,0,0,271,272,1,0,0,0,272,273,6,12,9,0,
  	273,26,1,0,0,0,274,275,5,115,0,0,275,276,5,105,0,0,276,287,5,110,0,0,
  	277,278,5,99,0,0,278,279,5,111,0,0,279,287,5,115,0,0,280,281,5,115,0,
  	0,281,282,5,113,0,0,282,283,5,114,0,0,283,284,5,116,0,0,284,285,1,0,0,
  	0,285,287,6,13,10,0,286,274,1,0,0,0,286,277,1,0,0,0,286,280,1,0,0,0,287,
  	28,1,0,0,0,288,289,5,36,0,0,289,291,7,5,0,0,290,292,7,0,0,0,291,290,1,
  	0,0,0,292,293,1,0,0,0,293,291,1,0,0,0,293,294,1,0,0,0,294,295,1,0,0,0,
  	295,296,6,14,11,0,296,30,1,0,0,0,297,298,3,39,19,0,298,299,6,15,12,0,
  	299,32,1,0,0,0,300,301,5,35,0,0,301,302,3,39,19,0,302,303,6,16,13,0,303,
  	34,1,0,0,0,304,305,5,36,0,0,305,306,3,39,19,0,306,307,6,17,14,0,307,36,
  	1,0,0,0,308,309,5,64,0,0,309,310,3,39,19,0,310,311,6,18,15,0,311,38,1,
  	0,0,0,312,320,7,6,0,0,313,315,7,7,0,0,314,313,1,0,0,0,315,318,1,0,0,0,
  	316,314,1,0,0,0,316,317,1,0,0,0,317,319,1,0,0,0,318,316,1,0,0,0,319,321,
  	7,8,0,0,320,316,1,0,0,0,320,321,1,0,0,0,321,40,1,0,0,0,322,323,5,91,0,
  	0,323,324,6,20,16,0,324,42,1,0,0,0,325,326,5,93,0,0,326,327,6,21,17,0,
  	327,44,1,0,0,0,328,329,5,41,0,0,329,330,6,22,18,0,330,46,1,0,0,0,331,
  	332,5,58,0,0,332,333,6,23,19,0,333,48,1,0,0,0,334,335,5,58,0,0,335,336,
  	5,58,0,0,336,337,1,0,0,0,337,338,6,24,20,0,338,50,1,0,0,0,339,340,5,46,
  	0,0,340,341,6,25,21,0,341,52,1,0,0,0,342,343,5,59,0,0,343,344,6,26,22,
  	0,344,54,1,0,0,0,345,346,5,61,0,0,346,347,6,27,23,0,347,56,1,0,0,0,348,
  	349,7,9,0,0,349,350,6,28,24,0,350,351,1,0,0,0,351,352,6,28,25,0,352,58,
  	1,0,0,0,353,354,7,10,0,0,354,355,6,29,26,0,355,356,1,0,0,0,356,357,6,
  	29,25,0,357,60,1,0,0,0,358,359,5,42,0,0,359,360,5,42,0,0,360,361,1,0,
  	0,0,361,362,6,30,27,0,362,62,1,0,0,0,363,364,5,42,0,0,364,365,6,31,28,
  	0,365,64,1,0,0,0,366,367,5,47,0,0,367,368,5,47,0,0,368,369,1,0,0,0,369,
  	370,6,32,29,0,370,66,1,0,0,0,371,372,5,47,0,0,372,373,6,33,30,0,373,68,
  	1,0,0,0,374,375,4,34,0,0,375,376,5,43,0,0,376,377,6,34,31,0,377,70,1,
  	0,0,0,378,379,5,43,0,0,379,380,6,35,32,0,380,72,1,0,0,0,381,382,4,36,
  	1,0,382,383,5,45,0,0,383,384,6,36,33,0,384,74,1,0,0,0,385,386,5,45,0,
  	0,386,387,6,37,34,0,387,76,1,0,0,0,388,389,5,37,0,0,389,390,6,38,35,0,
  	390,78,1,0,0,0,391,392,5,61,0,0,392,393,5,61,0,0,393,394,1,0,0,0,394,
  	395,6,39,36,0,395,80,1,0,0,0,396,397,5,33,0,0,397,398,5,61,0,0,398,399,
  	1,0,0,0,399,400,6,40,37,0,400,82,1,0,0,0,401,402,5,33,0,0,402,403,6,41,
  	38,0,403,84,1,0,0,0,404,405,5,126,0,0,405,406,6,42,39,0,406,86,1,0,0,
  	0,407,408,5,60,0,0,408,409,6,43,40,0,409,88,1,0,0,0,410,411,5,62,0,0,
  	411,412,6,44,41,0,412,90,1,0,0,0,413,414,5,60,0,0,414,415,5,61,0,0,415,
  	416,1,0,0,0,416,417,6,45,42,0,417,92,1,0,0,0,418,419,5,62,0,0,419,420,
  	5,61,0,0,420,421,1,0,0,0,421,422,6,46,43,0,422,94,1,0,0,0,423,424,5,38,
  	0,0,424,425,6,47,44,0,425,96,1,0,0,0,426,427,5,94,0,0,427,428,6,48,45,
  	0,428,98,1,0,0,0,429,430,5,124,0,0,430,431,6,49,46,0,431,100,1,0,0,0,
  	432,433,5,38,0,0,433,434,5,38,0,0,434,435,1,0,0,0,435,436,6,50,47,0,436,
  	102,1,0,0,0,437,438,5,38,0,0,438,439,5,38,0,0,439,440,5,38,0,0,440,441,
  	1,0,0,0,441,442,6,51,48,0,442,104,1,0,0,0,443,444,5,94,0,0,444,445,5,
  	94,0,0,445,446,1,0,0,0,446,447,6,52,49,0,447,106,1,0,0,0,448,449,5,124,
  	0,0,449,450,5,124,0,0,450,451,1,0,0,0,451,452,6,53,50,0,452,108,1,0,0,
  	0,453,454,5,124,0,0,454,455,5,124,0,0,455,456,5,124,0,0,456,457,1,0,0,
  	0,457,458,6,54,51,0,458,110,1,0,0,0,459,460,5,60,0,0,460,461,5,60,0,0,
  	461,462,1,0,0,0,462,463,6,55,52,0,463,112,1,0,0,0,464,465,5,62,0,0,465,
  	466,5,62,0,0,466,467,1,0,0,0,467,468,6,56,53,0,468,114,1,0,0,0,469,470,
  	5,46,0,0,470,471,5,46,0,0,471,472,5,46,0,0,472,473,1,0,0,0,473,474,6,
  	57,54,0,474,116,1,0,0,0,475,476,5,58,0,0,476,477,5,42,0,0,477,478,1,0,
  	0,0,478,479,6,58,55,0,479,118,1,0,0,0,480,481,4,59,2,0,481,482,5,40,0,
  	0,482,483,6,59,56,0,483,120,1,0,0,0,484,485,4,60,3,0,485,486,5,40,0,0,
  	486,487,6,60,57,0,487,122,1,0,0,0,488,490,9,0,0,0,489,488,1,0,0,0,490,
  	491,1,0,0,0,491,492,1,0,0,0,491,489,1,0,0,0,492,124,1,0,0,0,26,0,128,
  	135,142,147,150,154,159,161,166,170,175,177,183,188,195,200,204,209,214,
  	221,286,293,316,320,491,58,1,0,0,1,1,1,1,2,2,1,6,3,1,7,4,1,8,5,1,9,6,
  	1,10,7,1,11,8,1,12,9,1,13,10,1,14,11,1,15,12,1,16,13,1,17,14,1,18,15,
  	1,20,16,1,21,17,1,22,18,1,23,19,1,24,20,1,25,21,1,26,22,1,27,23,1,28,
  	24,0,1,0,1,29,25,1,30,26,1,31,27,1,32,28,1,33,29,1,34,30,1,35,31,1,36,
  	32,1,37,33,1,38,34,1,39,35,1,40,36,1,41,37,1,42,38,1,43,39,1,44,40,1,
  	45,41,1,46,42,1,47,43,1,48,44,1,49,45,1,50,46,1,51,47,1,52,48,1,53,49,
  	1,54,50,1,55,51,1,56,52,1,57,53,1,58,54,1,59,55,1,60,56
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
    case 26: NULLIFYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 27: ASSIGNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 28: WHITESPACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 29: NEWATOMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 30: POWAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 31: TIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 32: DIVDIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 33: DIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 34: PLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 35: UPLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 36: MINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 37: UMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 38: REMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 39: EQUALAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 40: NEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 41: LOGNOTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 42: BITNOTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 43: LTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 44: GTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 45: LEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 46: GEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 47: BITANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 48: BITXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 49: BITORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 50: LOGANDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 51: LOGANDEXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 52: LOGXORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 53: LOGORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 54: LOGOREXTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 55: LSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 56: RSHIFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 57: RANGEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 58: REPEATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 59: OPENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 60: PARAMSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool bellLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 34: return PLUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 36: return MINUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 59: return OPENSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 60: return PARAMSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

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

void bellLexer::NULLIFYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ASSIGNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::WHITESPACEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NEWATOMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 25:  noParams = true; noUnary = false; (*codeac)++;  break;

  default:
    break;
  }
}

void bellLexer::POWAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 26:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::TIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 27:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVDIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 28:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 29:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 30:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UPLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 31:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::MINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 32:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 33:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::REMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 34:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::EQUALAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 35:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 36:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGNOTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 37:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITNOTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 38:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 39:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::GTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 40:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 41:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::GEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 42:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 43:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 44:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::BITORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 45:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGANDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 46:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGANDEXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 47:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGXORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 48:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 49:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LOGOREXTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 50:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::LSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 51:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::RSHIFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 52:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::RANGEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 53:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::REPEATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 54:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::OPENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 55:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PARAMSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 56:  noParams = true; noUnary = false;  break;

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
