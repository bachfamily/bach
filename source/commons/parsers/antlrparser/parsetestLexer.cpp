
// Generated from parsetest.g4 by ANTLR 4.10.1


#include "parsetestLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ParsetestLexerStaticData final {
  ParsetestLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ParsetestLexerStaticData(const ParsetestLexerStaticData&) = delete;
  ParsetestLexerStaticData(ParsetestLexerStaticData&&) = delete;
  ParsetestLexerStaticData& operator=(const ParsetestLexerStaticData&) = delete;
  ParsetestLexerStaticData& operator=(ParsetestLexerStaticData&&) = delete;

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

std::once_flag parsetestlexerLexerOnceFlag;
ParsetestLexerStaticData *parsetestlexerLexerStaticData = nullptr;

void parsetestlexerLexerInitialize() {
  assert(parsetestlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<ParsetestLexerStaticData>(
    std::vector<std::string>{
      "NUMBER", "IF", "THEN", "ELSE", "FUNCTION", "VAR", "CLOSED", "NTH", 
      "TIMES", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", "PLUS", "UPLUS", 
      "MINUS", "UMINUS", "OPEN", "PARAMS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "'if'", "'then'", "'else'", "", "", "')'", "':'", "'*'", "';'", 
      "'='", "'\\n'", "", "", "'+'", "", "'-'"
    },
    std::vector<std::string>{
      "", "NUMBER", "IF", "THEN", "ELSE", "FUNCTION", "VAR", "CLOSED", "NTH", 
      "TIMES", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", "PLUS", "UPLUS", 
      "MINUS", "UMINUS", "OPEN", "PARAMS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,19,127,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,4,0,41,8,0,11,0,12,0,
  	42,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,
  	78,8,4,1,5,1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,
  	10,1,10,1,10,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,
  	13,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,17,1,17,1,17,1,
  	17,1,18,1,18,1,18,1,18,0,0,19,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,
  	19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,1,0,3,1,0,
  	48,57,1,0,97,122,2,0,9,9,32,32,129,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,
  	0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,
  	1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,
  	0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,
  	1,40,1,0,0,0,3,46,1,0,0,0,5,51,1,0,0,0,7,58,1,0,0,0,9,77,1,0,0,0,11,79,
  	1,0,0,0,13,82,1,0,0,0,15,85,1,0,0,0,17,88,1,0,0,0,19,91,1,0,0,0,21,94,
  	1,0,0,0,23,97,1,0,0,0,25,100,1,0,0,0,27,105,1,0,0,0,29,109,1,0,0,0,31,
  	112,1,0,0,0,33,116,1,0,0,0,35,119,1,0,0,0,37,123,1,0,0,0,39,41,7,0,0,
  	0,40,39,1,0,0,0,41,42,1,0,0,0,42,40,1,0,0,0,42,43,1,0,0,0,43,44,1,0,0,
  	0,44,45,6,0,0,0,45,2,1,0,0,0,46,47,5,105,0,0,47,48,5,102,0,0,48,49,1,
  	0,0,0,49,50,6,1,1,0,50,4,1,0,0,0,51,52,5,116,0,0,52,53,5,104,0,0,53,54,
  	5,101,0,0,54,55,5,110,0,0,55,56,1,0,0,0,56,57,6,2,2,0,57,6,1,0,0,0,58,
  	59,5,101,0,0,59,60,5,108,0,0,60,61,5,115,0,0,61,62,5,101,0,0,62,63,1,
  	0,0,0,63,64,6,3,3,0,64,8,1,0,0,0,65,66,5,115,0,0,66,67,5,105,0,0,67,78,
  	5,110,0,0,68,69,5,99,0,0,69,70,5,111,0,0,70,78,5,115,0,0,71,72,5,115,
  	0,0,72,73,5,113,0,0,73,74,5,114,0,0,74,75,5,116,0,0,75,76,1,0,0,0,76,
  	78,6,4,4,0,77,65,1,0,0,0,77,68,1,0,0,0,77,71,1,0,0,0,78,10,1,0,0,0,79,
  	80,7,1,0,0,80,81,6,5,5,0,81,12,1,0,0,0,82,83,5,41,0,0,83,84,6,6,6,0,84,
  	14,1,0,0,0,85,86,5,58,0,0,86,87,6,7,7,0,87,16,1,0,0,0,88,89,5,42,0,0,
  	89,90,6,8,8,0,90,18,1,0,0,0,91,92,5,59,0,0,92,93,6,9,9,0,93,20,1,0,0,
  	0,94,95,5,61,0,0,95,96,6,10,10,0,96,22,1,0,0,0,97,98,5,10,0,0,98,99,6,
  	11,11,0,99,24,1,0,0,0,100,101,7,2,0,0,101,102,6,12,12,0,102,103,1,0,0,
  	0,103,104,6,12,13,0,104,26,1,0,0,0,105,106,4,13,0,0,106,107,5,43,0,0,
  	107,108,6,13,14,0,108,28,1,0,0,0,109,110,5,43,0,0,110,111,6,14,15,0,111,
  	30,1,0,0,0,112,113,4,15,1,0,113,114,5,45,0,0,114,115,6,15,16,0,115,32,
  	1,0,0,0,116,117,5,45,0,0,117,118,6,16,17,0,118,34,1,0,0,0,119,120,4,17,
  	2,0,120,121,5,40,0,0,121,122,6,17,18,0,122,36,1,0,0,0,123,124,4,18,3,
  	0,124,125,5,40,0,0,125,126,6,18,19,0,126,38,1,0,0,0,3,0,42,77,20,1,0,
  	0,1,1,1,1,2,2,1,3,3,1,4,4,1,5,5,1,6,6,1,7,7,1,8,8,1,9,9,1,10,10,1,11,
  	11,1,12,12,0,1,0,1,13,13,1,14,14,1,15,15,1,16,16,1,17,17,1,18,18
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  parsetestlexerLexerStaticData = staticData.release();
}

}

parsetestLexer::parsetestLexer(CharStream *input) : Lexer(input) {
  parsetestLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *parsetestlexerLexerStaticData->atn, parsetestlexerLexerStaticData->decisionToDFA, parsetestlexerLexerStaticData->sharedContextCache);
}

parsetestLexer::~parsetestLexer() {
  delete _interpreter;
}

std::string parsetestLexer::getGrammarFileName() const {
  return "parsetest.g4";
}

const std::vector<std::string>& parsetestLexer::getRuleNames() const {
  return parsetestlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& parsetestLexer::getChannelNames() const {
  return parsetestlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& parsetestLexer::getModeNames() const {
  return parsetestlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& parsetestLexer::getVocabulary() const {
  return parsetestlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView parsetestLexer::getSerializedATN() const {
  return parsetestlexerLexerStaticData->serializedATN;
}

const atn::ATN& parsetestLexer::getATN() const {
  return *parsetestlexerLexerStaticData->atn;
}


void parsetestLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 0: NUMBERAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 1: IFAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 2: THENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 3: ELSEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 4: FUNCTIONAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 5: VARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 6: CLOSEDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 7: NTHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 8: TIMESAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 9: NULLIFYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 10: ASSIGNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 11: EOLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: WHITESPACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: PLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: UPLUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: MINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: UMINUSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 17: OPENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 18: PARAMSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool parsetestLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 13: return PLUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 15: return MINUSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 17: return OPENSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);
    case 18: return PARAMSSempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

void parsetestLexer::NUMBERAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0:  std::cout << "number\n"; noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void parsetestLexer::IFAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void parsetestLexer::THENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void parsetestLexer::ELSEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void parsetestLexer::FUNCTIONAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4:  noParams = noUnary = false;  break;

  default:
    break;
  }
}

void parsetestLexer::VARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void parsetestLexer::CLOSEDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6:  noParams = false; noUnary = true;  break;

  default:
    break;
  }
}

void parsetestLexer::NTHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 7:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void parsetestLexer::TIMESAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 8:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void parsetestLexer::NULLIFYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 9:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void parsetestLexer::ASSIGNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 10:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void parsetestLexer::EOLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 11:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void parsetestLexer::WHITESPACEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 12:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void parsetestLexer::PLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 13:  printf("plus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void parsetestLexer::UPLUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 14:  printf("uplus!\n"); noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void parsetestLexer::MINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 15:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void parsetestLexer::UMINUSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 16:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void parsetestLexer::OPENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 17:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}

void parsetestLexer::PARAMSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 18:  noParams = true; noUnary = false;  break;

  default:
    break;
  }
}


bool parsetestLexer::PLUSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return  notUnary() ;

  default:
    break;
  }
  return true;
}

bool parsetestLexer::MINUSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return  notUnary() ;

  default:
    break;
  }
  return true;
}

bool parsetestLexer::OPENSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return  noParams ;

  default:
    break;
  }
  return true;
}

bool parsetestLexer::PARAMSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return  !noParams ;

  default:
    break;
  }
  return true;
}


void parsetestLexer::initialize() {
  std::call_once(parsetestlexerLexerOnceFlag, parsetestlexerLexerInitialize);
}
