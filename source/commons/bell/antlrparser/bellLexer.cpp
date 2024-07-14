 
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
      "POP", "CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", "WHITESPACE", 
      "NEWATOM", "POW", "TIMES", "DIVDIV", "DIV", "PLUS", "UPLUS", "MINUS", 
      "UMINUS", "OPEN", "PARAMS", "ANYTHING"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "", "", "'if'", "'then'", "'else'", "'while'", "'for'", "'do'", 
      "'collect'", "", "", "", "", "", "", "'['", "']'", "')'", "':'", "'.'", 
      "';'", "'='", "", "", "'**'", "'*'", "'//'", "'/'", "", "'+'", "", 
      "'-'"
    },
    std::vector<std::string>{
      "", "UINT", "UFLOAT", "UPITCH", "IF", "THEN", "ELSE", "WHILE", "FOR", 
      "DO", "COLLECT", "FUNCTION", "INLET", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", 
      "NAMEDPARAM", "PUSH", "POP", "CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", 
      "WHITESPACE", "NEWATOM", "POW", "TIMES", "DIVDIV", "DIV", "PLUS", 
      "UPLUS", "MINUS", "UMINUS", "OPEN", "PARAMS", "ANYTHING"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,36,352,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,1,0,4,0,83,8,0,11,0,12,0,
  	84,1,0,1,0,1,1,5,1,90,8,1,10,1,12,1,93,9,1,1,1,1,1,4,1,97,8,1,11,1,12,
  	1,98,1,1,4,1,102,8,1,11,1,12,1,103,1,1,3,1,107,8,1,1,1,1,1,3,1,111,8,
  	1,1,1,4,1,114,8,1,11,1,12,1,115,3,1,118,8,1,1,1,4,1,121,8,1,11,1,12,1,
  	122,1,1,1,1,3,1,127,8,1,1,1,4,1,130,8,1,11,1,12,1,131,3,1,134,8,1,1,1,
  	1,1,1,2,1,2,3,2,140,8,2,1,2,5,2,143,8,2,10,2,12,2,146,9,2,1,2,1,2,5,2,
  	150,8,2,10,2,12,2,153,9,2,1,2,1,2,3,2,157,8,2,1,2,1,2,3,2,161,8,2,1,2,
  	1,2,1,3,3,3,166,8,3,1,4,4,4,169,8,4,11,4,12,4,170,1,5,1,5,1,5,5,5,176,
  	8,5,10,5,12,5,179,9,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,
  	12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,3,13,243,8,13,1,14,1,14,1,14,4,14,248,8,14,11,
  	14,12,14,249,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,17,1,17,1,
  	17,1,17,1,18,1,18,1,18,1,18,1,19,1,19,5,19,271,8,19,10,19,12,19,274,9,
  	19,1,19,3,19,277,8,19,1,20,1,20,1,20,1,21,1,21,1,21,1,22,1,22,1,22,1,
  	23,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,26,1,27,1,27,1,
  	27,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,30,1,
  	30,1,30,1,31,1,31,1,31,1,31,1,31,1,32,1,32,1,32,1,33,1,33,1,33,1,33,1,
  	34,1,34,1,34,1,35,1,35,1,35,1,35,1,36,1,36,1,36,1,37,1,37,1,37,1,37,1,
  	38,1,38,1,38,1,38,1,39,4,39,349,8,39,11,39,12,39,350,1,350,0,40,1,1,3,
  	2,5,3,7,0,9,0,11,0,13,4,15,5,17,6,19,7,21,8,23,9,25,10,27,11,29,12,31,
  	13,33,14,35,15,37,16,39,0,41,17,43,18,45,19,47,20,49,21,51,22,53,23,55,
  	24,57,25,59,26,61,27,63,28,65,29,67,30,69,31,71,32,73,33,75,34,77,35,
  	79,36,1,0,11,1,0,48,57,2,0,69,69,101,101,2,0,43,43,45,45,2,0,65,71,97,
  	103,7,0,35,35,94,94,98,98,100,100,113,113,118,118,120,120,2,0,108,108,
  	120,120,2,0,65,90,97,122,4,0,48,57,65,90,95,95,97,122,3,0,48,57,65,90,
  	97,122,3,0,9,10,13,13,32,32,1,0,1,1,372,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,
  	0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,
  	0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,
  	33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,
  	0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,
  	0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,
  	67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,
  	0,0,0,0,79,1,0,0,0,1,82,1,0,0,0,3,133,1,0,0,0,5,137,1,0,0,0,7,165,1,0,
  	0,0,9,168,1,0,0,0,11,172,1,0,0,0,13,182,1,0,0,0,15,187,1,0,0,0,17,194,
  	1,0,0,0,19,201,1,0,0,0,21,209,1,0,0,0,23,215,1,0,0,0,25,220,1,0,0,0,27,
  	242,1,0,0,0,29,244,1,0,0,0,31,253,1,0,0,0,33,256,1,0,0,0,35,260,1,0,0,
  	0,37,264,1,0,0,0,39,268,1,0,0,0,41,278,1,0,0,0,43,281,1,0,0,0,45,284,
  	1,0,0,0,47,287,1,0,0,0,49,290,1,0,0,0,51,293,1,0,0,0,53,296,1,0,0,0,55,
  	299,1,0,0,0,57,304,1,0,0,0,59,309,1,0,0,0,61,314,1,0,0,0,63,317,1,0,0,
  	0,65,322,1,0,0,0,67,325,1,0,0,0,69,329,1,0,0,0,71,332,1,0,0,0,73,336,
  	1,0,0,0,75,339,1,0,0,0,77,343,1,0,0,0,79,348,1,0,0,0,81,83,7,0,0,0,82,
  	81,1,0,0,0,83,84,1,0,0,0,84,82,1,0,0,0,84,85,1,0,0,0,85,86,1,0,0,0,86,
  	87,6,0,0,0,87,2,1,0,0,0,88,90,7,0,0,0,89,88,1,0,0,0,90,93,1,0,0,0,91,
  	89,1,0,0,0,91,92,1,0,0,0,92,94,1,0,0,0,93,91,1,0,0,0,94,96,5,46,0,0,95,
  	97,7,0,0,0,96,95,1,0,0,0,97,98,1,0,0,0,98,96,1,0,0,0,98,99,1,0,0,0,99,
  	107,1,0,0,0,100,102,7,0,0,0,101,100,1,0,0,0,102,103,1,0,0,0,103,101,1,
  	0,0,0,103,104,1,0,0,0,104,105,1,0,0,0,105,107,5,46,0,0,106,91,1,0,0,0,
  	106,101,1,0,0,0,107,117,1,0,0,0,108,110,7,1,0,0,109,111,7,2,0,0,110,109,
  	1,0,0,0,110,111,1,0,0,0,111,113,1,0,0,0,112,114,7,0,0,0,113,112,1,0,0,
  	0,114,115,1,0,0,0,115,113,1,0,0,0,115,116,1,0,0,0,116,118,1,0,0,0,117,
  	108,1,0,0,0,117,118,1,0,0,0,118,134,1,0,0,0,119,121,7,0,0,0,120,119,1,
  	0,0,0,121,122,1,0,0,0,122,120,1,0,0,0,122,123,1,0,0,0,123,124,1,0,0,0,
  	124,126,7,1,0,0,125,127,7,2,0,0,126,125,1,0,0,0,126,127,1,0,0,0,127,129,
  	1,0,0,0,128,130,7,0,0,0,129,128,1,0,0,0,130,131,1,0,0,0,131,129,1,0,0,
  	0,131,132,1,0,0,0,132,134,1,0,0,0,133,106,1,0,0,0,133,120,1,0,0,0,134,
  	135,1,0,0,0,135,136,6,1,1,0,136,4,1,0,0,0,137,139,3,7,3,0,138,140,3,9,
  	4,0,139,138,1,0,0,0,139,140,1,0,0,0,140,144,1,0,0,0,141,143,7,2,0,0,142,
  	141,1,0,0,0,143,146,1,0,0,0,144,142,1,0,0,0,144,145,1,0,0,0,145,147,1,
  	0,0,0,146,144,1,0,0,0,147,160,3,1,0,0,148,150,7,2,0,0,149,148,1,0,0,0,
  	150,153,1,0,0,0,151,149,1,0,0,0,151,152,1,0,0,0,152,156,1,0,0,0,153,151,
  	1,0,0,0,154,157,3,1,0,0,155,157,3,11,5,0,156,154,1,0,0,0,156,155,1,0,
  	0,0,157,158,1,0,0,0,158,159,5,116,0,0,159,161,1,0,0,0,160,151,1,0,0,0,
  	160,161,1,0,0,0,161,162,1,0,0,0,162,163,6,2,2,0,163,6,1,0,0,0,164,166,
  	7,3,0,0,165,164,1,0,0,0,166,8,1,0,0,0,167,169,7,4,0,0,168,167,1,0,0,0,
  	169,170,1,0,0,0,170,168,1,0,0,0,170,171,1,0,0,0,171,10,1,0,0,0,172,173,
  	3,1,0,0,173,177,5,47,0,0,174,176,7,2,0,0,175,174,1,0,0,0,176,179,1,0,
  	0,0,177,175,1,0,0,0,177,178,1,0,0,0,178,180,1,0,0,0,179,177,1,0,0,0,180,
  	181,3,1,0,0,181,12,1,0,0,0,182,183,5,105,0,0,183,184,5,102,0,0,184,185,
  	1,0,0,0,185,186,6,6,3,0,186,14,1,0,0,0,187,188,5,116,0,0,188,189,5,104,
  	0,0,189,190,5,101,0,0,190,191,5,110,0,0,191,192,1,0,0,0,192,193,6,7,4,
  	0,193,16,1,0,0,0,194,195,5,101,0,0,195,196,5,108,0,0,196,197,5,115,0,
  	0,197,198,5,101,0,0,198,199,1,0,0,0,199,200,6,8,5,0,200,18,1,0,0,0,201,
  	202,5,119,0,0,202,203,5,104,0,0,203,204,5,105,0,0,204,205,5,108,0,0,205,
  	206,5,101,0,0,206,207,1,0,0,0,207,208,6,9,6,0,208,20,1,0,0,0,209,210,
  	5,102,0,0,210,211,5,111,0,0,211,212,5,114,0,0,212,213,1,0,0,0,213,214,
  	6,10,7,0,214,22,1,0,0,0,215,216,5,100,0,0,216,217,5,111,0,0,217,218,1,
  	0,0,0,218,219,6,11,8,0,219,24,1,0,0,0,220,221,5,99,0,0,221,222,5,111,
  	0,0,222,223,5,108,0,0,223,224,5,108,0,0,224,225,5,101,0,0,225,226,5,99,
  	0,0,226,227,5,116,0,0,227,228,1,0,0,0,228,229,6,12,9,0,229,26,1,0,0,0,
  	230,231,5,115,0,0,231,232,5,105,0,0,232,243,5,110,0,0,233,234,5,99,0,
  	0,234,235,5,111,0,0,235,243,5,115,0,0,236,237,5,115,0,0,237,238,5,113,
  	0,0,238,239,5,114,0,0,239,240,5,116,0,0,240,241,1,0,0,0,241,243,6,13,
  	10,0,242,230,1,0,0,0,242,233,1,0,0,0,242,236,1,0,0,0,243,28,1,0,0,0,244,
  	245,5,36,0,0,245,247,7,5,0,0,246,248,7,0,0,0,247,246,1,0,0,0,248,249,
  	1,0,0,0,249,247,1,0,0,0,249,250,1,0,0,0,250,251,1,0,0,0,251,252,6,14,
  	11,0,252,30,1,0,0,0,253,254,3,39,19,0,254,255,6,15,12,0,255,32,1,0,0,
  	0,256,257,5,35,0,0,257,258,3,39,19,0,258,259,6,16,13,0,259,34,1,0,0,0,
  	260,261,5,36,0,0,261,262,3,39,19,0,262,263,6,17,14,0,263,36,1,0,0,0,264,
  	265,5,64,0,0,265,266,3,39,19,0,266,267,6,18,15,0,267,38,1,0,0,0,268,276,
  	7,6,0,0,269,271,7,7,0,0,270,269,1,0,0,0,271,274,1,0,0,0,272,270,1,0,0,
  	0,272,273,1,0,0,0,273,275,1,0,0,0,274,272,1,0,0,0,275,277,7,8,0,0,276,
  	272,1,0,0,0,276,277,1,0,0,0,277,40,1,0,0,0,278,279,5,91,0,0,279,280,6,
  	20,16,0,280,42,1,0,0,0,281,282,5,93,0,0,282,283,6,21,17,0,283,44,1,0,
  	0,0,284,285,5,41,0,0,285,286,6,22,18,0,286,46,1,0,0,0,287,288,5,58,0,
  	0,288,289,6,23,19,0,289,48,1,0,0,0,290,291,5,46,0,0,291,292,6,24,20,0,
  	292,50,1,0,0,0,293,294,5,59,0,0,294,295,6,25,21,0,295,52,1,0,0,0,296,
  	297,5,61,0,0,297,298,6,26,22,0,298,54,1,0,0,0,299,300,7,9,0,0,300,301,
  	6,27,23,0,301,302,1,0,0,0,302,303,6,27,24,0,303,56,1,0,0,0,304,305,7,
  	10,0,0,305,306,6,28,25,0,306,307,1,0,0,0,307,308,6,28,24,0,308,58,1,0,
  	0,0,309,310,5,42,0,0,310,311,5,42,0,0,311,312,1,0,0,0,312,313,6,29,26,
  	0,313,60,1,0,0,0,314,315,5,42,0,0,315,316,6,30,27,0,316,62,1,0,0,0,317,
  	318,5,47,0,0,318,319,5,47,0,0,319,320,1,0,0,0,320,321,6,31,28,0,321,64,
  	1,0,0,0,322,323,5,47,0,0,323,324,6,32,29,0,324,66,1,0,0,0,325,326,4,33,
  	0,0,326,327,5,43,0,0,327,328,6,33,30,0,328,68,1,0,0,0,329,330,5,43,0,
  	0,330,331,6,34,31,0,331,70,1,0,0,0,332,333,4,35,1,0,333,334,5,45,0,0,
  	334,335,6,35,32,0,335,72,1,0,0,0,336,337,5,45,0,0,337,338,6,36,33,0,338,
  	74,1,0,0,0,339,340,4,37,2,0,340,341,5,40,0,0,341,342,6,37,34,0,342,76,
  	1,0,0,0,343,344,4,38,3,0,344,345,5,40,0,0,345,346,6,38,35,0,346,78,1,
  	0,0,0,347,349,9,0,0,0,348,347,1,0,0,0,349,350,1,0,0,0,350,351,1,0,0,0,
  	350,348,1,0,0,0,351,80,1,0,0,0,26,0,84,91,98,103,106,110,115,117,122,
  	126,131,133,139,144,151,156,160,165,170,177,242,249,272,276,350,36,1,
  	0,0,1,1,1,1,2,2,1,6,3,1,7,4,1,8,5,1,9,6,1,10,7,1,11,8,1,12,9,1,13,10,
  	1,14,11,1,15,12,1,16,13,1,17,14,1,18,15,1,20,16,1,21,17,1,22,18,1,23,
  	19,1,24,20,1,25,21,1,26,22,1,27,23,0,1,0,1,28,24,1,29,25,1,30,26,1,31,
  	27,1,32,28,1,33,29,1,34,30,1,35,31,1,36,32,1,37,33,1,38,34
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
    case 24: KEYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 25: NULLIFYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 26: ASSIGNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 27: WHITESPACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 28: NEWATOMAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 29: POWAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 30: TIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 31: DIVDIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 32: DIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 33: PLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 34: UPLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 35: MINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 36: UMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 37: OPENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 38: PARAMSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool bellLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 33: return PLUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 35: return MINUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 37: return OPENSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 38: return PARAMSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

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

void bellLexer::KEYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 20:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NULLIFYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 21:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ASSIGNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::WHITESPACEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NEWATOMAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  noParams = true; noUnary = false; (*codeac)++;  break;

  default:
    break;
  }
}

void bellLexer::POWAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 25:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::TIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 26:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVDIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 27:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 28:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 29:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UPLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 30:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::MINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 31:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 32:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::OPENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 33:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PARAMSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 34:  noParams = true; noUnary = false;  break;

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
