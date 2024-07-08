 
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
      "POW", "TIMES", "PLUS", "UPLUS", "MINUS", "UMINUS", "OPEN", "PARAMS"
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
      "", "'+'", "", "'-'"
    },
    std::vector<std::string>{
      "", "NUMBER", "IF", "THEN", "ELSE", "FOR", "DO", "FUNCTION", "VAR", 
      "PUSH", "POP", "CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", "EOL", 
      "WHITESPACE", "POW", "TIMES", "PLUS", "UPLUS", "MINUS", "UMINUS", 
      "OPEN", "PARAMS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,25,164,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,1,0,4,0,53,8,0,11,0,12,0,54,1,0,1,
  	0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,101,8,6,1,7,1,7,1,7,1,8,1,8,1,8,1,9,
  	1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,
  	14,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,
  	17,1,17,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,21,1,21,1,
  	21,1,21,1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,24,1,24,1,24,1,24,0,0,25,
  	1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,
  	29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,1,0,
  	3,1,0,48,57,1,0,97,122,3,0,1,1,9,9,32,32,166,0,1,1,0,0,0,0,3,1,0,0,0,
  	0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,
  	0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,
  	0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,
  	37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,
  	0,0,0,0,49,1,0,0,0,1,52,1,0,0,0,3,58,1,0,0,0,5,63,1,0,0,0,7,70,1,0,0,
  	0,9,77,1,0,0,0,11,83,1,0,0,0,13,100,1,0,0,0,15,102,1,0,0,0,17,105,1,0,
  	0,0,19,108,1,0,0,0,21,111,1,0,0,0,23,114,1,0,0,0,25,117,1,0,0,0,27,120,
  	1,0,0,0,29,123,1,0,0,0,31,126,1,0,0,0,33,129,1,0,0,0,35,134,1,0,0,0,37,
  	139,1,0,0,0,39,142,1,0,0,0,41,146,1,0,0,0,43,149,1,0,0,0,45,153,1,0,0,
  	0,47,156,1,0,0,0,49,160,1,0,0,0,51,53,7,0,0,0,52,51,1,0,0,0,53,54,1,0,
  	0,0,54,52,1,0,0,0,54,55,1,0,0,0,55,56,1,0,0,0,56,57,6,0,0,0,57,2,1,0,
  	0,0,58,59,5,105,0,0,59,60,5,102,0,0,60,61,1,0,0,0,61,62,6,1,1,0,62,4,
  	1,0,0,0,63,64,5,116,0,0,64,65,5,104,0,0,65,66,5,101,0,0,66,67,5,110,0,
  	0,67,68,1,0,0,0,68,69,6,2,2,0,69,6,1,0,0,0,70,71,5,101,0,0,71,72,5,108,
  	0,0,72,73,5,115,0,0,73,74,5,101,0,0,74,75,1,0,0,0,75,76,6,3,3,0,76,8,
  	1,0,0,0,77,78,5,102,0,0,78,79,5,111,0,0,79,80,5,114,0,0,80,81,1,0,0,0,
  	81,82,6,4,4,0,82,10,1,0,0,0,83,84,5,100,0,0,84,85,5,111,0,0,85,86,1,0,
  	0,0,86,87,6,5,5,0,87,12,1,0,0,0,88,89,5,115,0,0,89,90,5,105,0,0,90,101,
  	5,110,0,0,91,92,5,99,0,0,92,93,5,111,0,0,93,101,5,115,0,0,94,95,5,115,
  	0,0,95,96,5,113,0,0,96,97,5,114,0,0,97,98,5,116,0,0,98,99,1,0,0,0,99,
  	101,6,6,6,0,100,88,1,0,0,0,100,91,1,0,0,0,100,94,1,0,0,0,101,14,1,0,0,
  	0,102,103,7,1,0,0,103,104,6,7,7,0,104,16,1,0,0,0,105,106,5,91,0,0,106,
  	107,6,8,8,0,107,18,1,0,0,0,108,109,5,93,0,0,109,110,6,9,9,0,110,20,1,
  	0,0,0,111,112,5,41,0,0,112,113,6,10,10,0,113,22,1,0,0,0,114,115,5,58,
  	0,0,115,116,6,11,11,0,116,24,1,0,0,0,117,118,5,46,0,0,118,119,6,12,12,
  	0,119,26,1,0,0,0,120,121,5,59,0,0,121,122,6,13,13,0,122,28,1,0,0,0,123,
  	124,5,61,0,0,124,125,6,14,14,0,125,30,1,0,0,0,126,127,5,10,0,0,127,128,
  	6,15,15,0,128,32,1,0,0,0,129,130,7,2,0,0,130,131,6,16,16,0,131,132,1,
  	0,0,0,132,133,6,16,17,0,133,34,1,0,0,0,134,135,5,42,0,0,135,136,5,42,
  	0,0,136,137,1,0,0,0,137,138,6,17,18,0,138,36,1,0,0,0,139,140,5,42,0,0,
  	140,141,6,18,19,0,141,38,1,0,0,0,142,143,4,19,0,0,143,144,5,43,0,0,144,
  	145,6,19,20,0,145,40,1,0,0,0,146,147,5,43,0,0,147,148,6,20,21,0,148,42,
  	1,0,0,0,149,150,4,21,1,0,150,151,5,45,0,0,151,152,6,21,22,0,152,44,1,
  	0,0,0,153,154,5,45,0,0,154,155,6,22,23,0,155,46,1,0,0,0,156,157,4,23,
  	2,0,157,158,5,40,0,0,158,159,6,23,24,0,159,48,1,0,0,0,160,161,4,24,3,
  	0,161,162,5,40,0,0,162,163,6,24,25,0,163,50,1,0,0,0,3,0,54,100,26,1,0,
  	0,1,1,1,1,2,2,1,3,3,1,4,4,1,5,5,1,6,6,1,7,7,1,8,8,1,9,9,1,10,10,1,11,
  	11,1,12,12,1,13,13,1,14,14,1,15,15,1,16,16,0,1,0,1,17,17,1,18,18,1,19,
  	19,1,20,20,1,21,21,1,22,22,1,23,23,1,24,24
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
    case 19: PLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 20: UPLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 21: MINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 22: UMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 23: OPENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 24: PARAMSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool bellLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 19: return PLUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 21: return MINUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 23: return OPENSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 24: return PARAMSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

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

void bellLexer::PLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 19:  post("plus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UPLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 20:  post("uplus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::MINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 21:  post("minus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::UMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  post("uminus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::OPENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void bellLexer::PARAMSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  noParams = true; noUnary = false;  break;

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
