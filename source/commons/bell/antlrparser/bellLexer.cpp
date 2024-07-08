 
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
      "NUMBER", "IF", "THEN", "ELSE", "FOR", "DO", "FUNCTION", "VAR", "PUSH", 
      "POP", "CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", 
      "POW", "TIMES", "DIVDIV", "DIV", "PLUS", "UPLUS", "MINUS", "UMINUS", 
      "OPEN", "PARAMS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "'if'", "'then'", "'else'", "'for'", "'do'", "", "", "'['", 
      "']'", "')'", "':'", "'.'", "';'", "'='", "'\\n'", "", "'**'", "'*'", 
      "'//'", "'/'", "", "'+'", "", "'-'"
    },
    std::vector<std::string>{
      "", "NUMBER", "IF", "THEN", "ELSE", "FOR", "DO", "FUNCTION", "VAR", 
      "PUSH", "POP", "CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", "EOL", 
      "WHITESPACE", "POW", "TIMES", "DIVDIV", "DIV", "PLUS", "UPLUS", "MINUS", 
      "UMINUS", "OPEN", "PARAMS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,27,176,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,1,0,4,0,57,8,0,
  	11,0,12,0,58,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,
  	5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,105,8,6,1,7,1,7,
  	1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,12,1,12,1,
  	12,1,13,1,13,1,13,1,14,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,
  	16,1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,
  	20,1,20,1,20,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,
  	24,1,24,1,24,1,25,1,25,1,25,1,25,1,26,1,26,1,26,1,26,0,0,27,1,1,3,2,5,
  	3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,
  	16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,
  	1,0,3,1,0,48,57,1,0,97,122,3,0,1,1,9,9,32,32,178,0,1,1,0,0,0,0,3,1,0,
  	0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,
  	1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,
  	0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,
  	0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,
  	1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,1,56,1,0,0,0,3,62,1,0,
  	0,0,5,67,1,0,0,0,7,74,1,0,0,0,9,81,1,0,0,0,11,87,1,0,0,0,13,104,1,0,0,
  	0,15,106,1,0,0,0,17,109,1,0,0,0,19,112,1,0,0,0,21,115,1,0,0,0,23,118,
  	1,0,0,0,25,121,1,0,0,0,27,124,1,0,0,0,29,127,1,0,0,0,31,130,1,0,0,0,33,
  	133,1,0,0,0,35,138,1,0,0,0,37,143,1,0,0,0,39,146,1,0,0,0,41,151,1,0,0,
  	0,43,154,1,0,0,0,45,158,1,0,0,0,47,161,1,0,0,0,49,165,1,0,0,0,51,168,
  	1,0,0,0,53,172,1,0,0,0,55,57,7,0,0,0,56,55,1,0,0,0,57,58,1,0,0,0,58,56,
  	1,0,0,0,58,59,1,0,0,0,59,60,1,0,0,0,60,61,6,0,0,0,61,2,1,0,0,0,62,63,
  	5,105,0,0,63,64,5,102,0,0,64,65,1,0,0,0,65,66,6,1,1,0,66,4,1,0,0,0,67,
  	68,5,116,0,0,68,69,5,104,0,0,69,70,5,101,0,0,70,71,5,110,0,0,71,72,1,
  	0,0,0,72,73,6,2,2,0,73,6,1,0,0,0,74,75,5,101,0,0,75,76,5,108,0,0,76,77,
  	5,115,0,0,77,78,5,101,0,0,78,79,1,0,0,0,79,80,6,3,3,0,80,8,1,0,0,0,81,
  	82,5,102,0,0,82,83,5,111,0,0,83,84,5,114,0,0,84,85,1,0,0,0,85,86,6,4,
  	4,0,86,10,1,0,0,0,87,88,5,100,0,0,88,89,5,111,0,0,89,90,1,0,0,0,90,91,
  	6,5,5,0,91,12,1,0,0,0,92,93,5,115,0,0,93,94,5,105,0,0,94,105,5,110,0,
  	0,95,96,5,99,0,0,96,97,5,111,0,0,97,105,5,115,0,0,98,99,5,115,0,0,99,
  	100,5,113,0,0,100,101,5,114,0,0,101,102,5,116,0,0,102,103,1,0,0,0,103,
  	105,6,6,6,0,104,92,1,0,0,0,104,95,1,0,0,0,104,98,1,0,0,0,105,14,1,0,0,
  	0,106,107,7,1,0,0,107,108,6,7,7,0,108,16,1,0,0,0,109,110,5,91,0,0,110,
  	111,6,8,8,0,111,18,1,0,0,0,112,113,5,93,0,0,113,114,6,9,9,0,114,20,1,
  	0,0,0,115,116,5,41,0,0,116,117,6,10,10,0,117,22,1,0,0,0,118,119,5,58,
  	0,0,119,120,6,11,11,0,120,24,1,0,0,0,121,122,5,46,0,0,122,123,6,12,12,
  	0,123,26,1,0,0,0,124,125,5,59,0,0,125,126,6,13,13,0,126,28,1,0,0,0,127,
  	128,5,61,0,0,128,129,6,14,14,0,129,30,1,0,0,0,130,131,5,10,0,0,131,132,
  	6,15,15,0,132,32,1,0,0,0,133,134,7,2,0,0,134,135,6,16,16,0,135,136,1,
  	0,0,0,136,137,6,16,17,0,137,34,1,0,0,0,138,139,5,42,0,0,139,140,5,42,
  	0,0,140,141,1,0,0,0,141,142,6,17,18,0,142,36,1,0,0,0,143,144,5,42,0,0,
  	144,145,6,18,19,0,145,38,1,0,0,0,146,147,5,47,0,0,147,148,5,47,0,0,148,
  	149,1,0,0,0,149,150,6,19,20,0,150,40,1,0,0,0,151,152,5,47,0,0,152,153,
  	6,20,21,0,153,42,1,0,0,0,154,155,4,21,0,0,155,156,5,43,0,0,156,157,6,
  	21,22,0,157,44,1,0,0,0,158,159,5,43,0,0,159,160,6,22,23,0,160,46,1,0,
  	0,0,161,162,4,23,1,0,162,163,5,45,0,0,163,164,6,23,24,0,164,48,1,0,0,
  	0,165,166,5,45,0,0,166,167,6,24,25,0,167,50,1,0,0,0,168,169,4,25,2,0,
  	169,170,5,40,0,0,170,171,6,25,26,0,171,52,1,0,0,0,172,173,4,26,3,0,173,
  	174,5,40,0,0,174,175,6,26,27,0,175,54,1,0,0,0,3,0,58,104,28,1,0,0,1,1,
  	1,1,2,2,1,3,3,1,4,4,1,5,5,1,6,6,1,7,7,1,8,8,1,9,9,1,10,10,1,11,11,1,12,
  	12,1,13,13,1,14,14,1,15,15,1,16,16,0,1,0,1,17,17,1,18,18,1,19,19,1,20,
  	20,1,21,21,1,22,22,1,23,23,1,24,24,1,25,25,1,26,26
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
    case 0: NUMBERAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 1: IFAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 2: THENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 3: ELSEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 4: FORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 5: DOAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 6: FUNCTIONAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 7: VARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 8: PUSHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 9: POPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 10: CLOSEDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 11: NTHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: KEYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: NULLIFYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: ASSIGNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: EOLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: WHITESPACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 17: POWAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 18: TIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 19: DIVDIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 20: DIVAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 21: PLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 22: UPLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 23: MINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 24: UMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 25: OPENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 26: PARAMSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool bellLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 21: return PLUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 23: return MINUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 25: return OPENSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 26: return PARAMSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

void bellLexer::NUMBERAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0:  std::cout << "number\n"; noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::IFAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::THENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ELSEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::FORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DOAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::FUNCTIONAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6:  noParams = noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::VARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 7:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::PUSHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 8:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::POPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 9:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::CLOSEDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 10:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void bellLexer::NTHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 11:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::KEYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 12:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::NULLIFYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 13:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::ASSIGNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 14:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::EOLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 15:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::WHITESPACEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 16:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::POWAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 17:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::TIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 18:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVDIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 19:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::DIVAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 20:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 21:  post("plus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UPLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  post("uplus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::MINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  post("minus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  post("uminus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::OPENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 25:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PARAMSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 26:  noParams = true; noUnary = false;  break;

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
