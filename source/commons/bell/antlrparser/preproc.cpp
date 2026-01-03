
    #include "ext.h"
    #include "llll_commons.h"


// Generated from preproc.g4 by ANTLR 4.10.1


#include "preprocVisitor.h"

#include "preproc.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct PreprocStaticData final {
  PreprocStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PreprocStaticData(const PreprocStaticData&) = delete;
  PreprocStaticData(PreprocStaticData&&) = delete;
  PreprocStaticData& operator=(const PreprocStaticData&) = delete;
  PreprocStaticData& operator=(PreprocStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag preprocParserOnceFlag;
PreprocStaticData *preprocParserStaticData = nullptr;

void preprocParserInitialize() {
  assert(preprocParserStaticData == nullptr);
  auto staticData = std::make_unique<PreprocStaticData>(
    std::vector<std::string>{
      "code", "transcribe", "include"
    },
    std::vector<std::string>{
    },
    std::vector<std::string>{
      "", "DONTLOOKHERE", "WHITESPACE", "INCLUDE", "ANY", "CLOSE", "FILENAME"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,6,29,2,0,7,0,2,1,7,1,2,2,7,2,1,0,1,0,5,0,9,8,0,10,0,12,0,12,9,0,1,
  	0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,3,1,22,8,1,1,2,1,2,1,2,1,2,1,2,1,2,0,0,
  	3,0,2,4,0,0,29,0,10,1,0,0,0,2,21,1,0,0,0,4,23,1,0,0,0,6,9,3,2,1,0,7,9,
  	3,4,2,0,8,6,1,0,0,0,8,7,1,0,0,0,9,12,1,0,0,0,10,8,1,0,0,0,10,11,1,0,0,
  	0,11,13,1,0,0,0,12,10,1,0,0,0,13,14,5,0,0,1,14,1,1,0,0,0,15,16,5,1,0,
  	0,16,22,6,1,-1,0,17,18,5,4,0,0,18,22,6,1,-1,0,19,20,5,2,0,0,20,22,6,1,
  	-1,0,21,15,1,0,0,0,21,17,1,0,0,0,21,19,1,0,0,0,22,3,1,0,0,0,23,24,5,3,
  	0,0,24,25,5,6,0,0,25,26,5,5,0,0,26,27,6,2,-1,0,27,5,1,0,0,0,3,8,10,21
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  preprocParserStaticData = staticData.release();
}

}

preproc::preproc(TokenStream *input) : preproc(input, antlr4::atn::ParserATNSimulatorOptions()) {}

preproc::preproc(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  preproc::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *preprocParserStaticData->atn, preprocParserStaticData->decisionToDFA, preprocParserStaticData->sharedContextCache, options);
}

preproc::~preproc() {
  delete _interpreter;
}

const atn::ATN& preproc::getATN() const {
  return *preprocParserStaticData->atn;
}

std::string preproc::getGrammarFileName() const {
  return "preproc.g4";
}

const std::vector<std::string>& preproc::getRuleNames() const {
  return preprocParserStaticData->ruleNames;
}

const dfa::Vocabulary& preproc::getVocabulary() const {
  return preprocParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView preproc::getSerializedATN() const {
  return preprocParserStaticData->serializedATN;
}


//----------------- CodeContext ------------------------------------------------------------------

preproc::CodeContext::CodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* preproc::CodeContext::EOF() {
  return getToken(preproc::EOF, 0);
}

std::vector<preproc::TranscribeContext *> preproc::CodeContext::transcribe() {
  return getRuleContexts<preproc::TranscribeContext>();
}

preproc::TranscribeContext* preproc::CodeContext::transcribe(size_t i) {
  return getRuleContext<preproc::TranscribeContext>(i);
}

std::vector<preproc::IncludeContext *> preproc::CodeContext::include() {
  return getRuleContexts<preproc::IncludeContext>();
}

preproc::IncludeContext* preproc::CodeContext::include(size_t i) {
  return getRuleContext<preproc::IncludeContext>(i);
}


size_t preproc::CodeContext::getRuleIndex() const {
  return preproc::RuleCode;
}


std::any preproc::CodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<preprocVisitor*>(visitor))
    return parserVisitor->visitCode(this);
  else
    return visitor->visitChildren(this);
}

preproc::CodeContext* preproc::code() {
  CodeContext *_localctx = _tracker.createInstance<CodeContext>(_ctx, getState());
  enterRule(_localctx, 0, preproc::RuleCode);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(10);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << preproc::DONTLOOKHERE)
      | (1ULL << preproc::WHITESPACE)
      | (1ULL << preproc::INCLUDE)
      | (1ULL << preproc::ANY))) != 0)) {
      setState(8);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case preproc::DONTLOOKHERE:
        case preproc::WHITESPACE:
        case preproc::ANY: {
          setState(6);
          transcribe();
          break;
        }

        case preproc::INCLUDE: {
          setState(7);
          include();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(12);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(13);
    match(preproc::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TranscribeContext ------------------------------------------------------------------

preproc::TranscribeContext::TranscribeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* preproc::TranscribeContext::DONTLOOKHERE() {
  return getToken(preproc::DONTLOOKHERE, 0);
}

tree::TerminalNode* preproc::TranscribeContext::ANY() {
  return getToken(preproc::ANY, 0);
}

tree::TerminalNode* preproc::TranscribeContext::WHITESPACE() {
  return getToken(preproc::WHITESPACE, 0);
}


size_t preproc::TranscribeContext::getRuleIndex() const {
  return preproc::RuleTranscribe;
}


std::any preproc::TranscribeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<preprocVisitor*>(visitor))
    return parserVisitor->visitTranscribe(this);
  else
    return visitor->visitChildren(this);
}

preproc::TranscribeContext* preproc::transcribe() {
  TranscribeContext *_localctx = _tracker.createInstance<TranscribeContext>(_ctx, getState());
  enterRule(_localctx, 2, preproc::RuleTranscribe);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(21);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case preproc::DONTLOOKHERE: {
        enterOuterAlt(_localctx, 1);
        setState(15);
        antlrcpp::downCast<TranscribeContext *>(_localctx)->dontlookhereToken = match(preproc::DONTLOOKHERE);
         output += (antlrcpp::downCast<TranscribeContext *>(_localctx)->dontlookhereToken != nullptr ? antlrcpp::downCast<TranscribeContext *>(_localctx)->dontlookhereToken->getText() : ""); 
        break;
      }

      case preproc::ANY: {
        enterOuterAlt(_localctx, 2);
        setState(17);
        antlrcpp::downCast<TranscribeContext *>(_localctx)->anyToken = match(preproc::ANY);
         output += (antlrcpp::downCast<TranscribeContext *>(_localctx)->anyToken != nullptr ? antlrcpp::downCast<TranscribeContext *>(_localctx)->anyToken->getText() : ""); 
        break;
      }

      case preproc::WHITESPACE: {
        enterOuterAlt(_localctx, 3);
        setState(19);
        antlrcpp::downCast<TranscribeContext *>(_localctx)->whitespaceToken = match(preproc::WHITESPACE);
         output += (antlrcpp::downCast<TranscribeContext *>(_localctx)->whitespaceToken != nullptr ? antlrcpp::downCast<TranscribeContext *>(_localctx)->whitespaceToken->getText() : ""); 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeContext ------------------------------------------------------------------

preproc::IncludeContext::IncludeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* preproc::IncludeContext::INCLUDE() {
  return getToken(preproc::INCLUDE, 0);
}

tree::TerminalNode* preproc::IncludeContext::FILENAME() {
  return getToken(preproc::FILENAME, 0);
}

tree::TerminalNode* preproc::IncludeContext::CLOSE() {
  return getToken(preproc::CLOSE, 0);
}


size_t preproc::IncludeContext::getRuleIndex() const {
  return preproc::RuleInclude;
}


std::any preproc::IncludeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<preprocVisitor*>(visitor))
    return parserVisitor->visitInclude(this);
  else
    return visitor->visitChildren(this);
}

preproc::IncludeContext* preproc::include() {
  IncludeContext *_localctx = _tracker.createInstance<IncludeContext>(_ctx, getState());
  enterRule(_localctx, 4, preproc::RuleInclude);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(23);
    match(preproc::INCLUDE);
    setState(24);
    antlrcpp::downCast<IncludeContext *>(_localctx)->filenameToken = match(preproc::FILENAME);
    setState(25);
    match(preproc::CLOSE);
     
        t_fourcc filetype[] = {'TEXT', 'BELL'};
        t_fourcc outtype;
        char *filename = (char *) bach_newptr(MAX_PATH_CHARS + 1);
        short path;
        auto s = (antlrcpp::downCast<IncludeContext *>(_localctx)->filenameToken != nullptr ? antlrcpp::downCast<IncludeContext *>(_localctx)->filenameToken->getText() : "");
        strncpy_zero(filename, s.c_str(), MAX_PATH_CHARS);    // must copy symbol before calling locatefile_extended
        if (locatefile_extended(filename, &path, &outtype, filetype, 2)) { // non-zero: not found
            object_error(nullptr, "include(%s): file not found", s.c_str());
        } else {
            t_filehandle fh;
            if (path_opensysfile(filename, path, &fh, READ_PERM)) {
                object_error(nullptr, "error opening %s", filename);
                error = true;
            } else {
                // allocate some empty memory to receive text
                char **texthandle = sysmem_newhandle(0);
                sysfile_readtextfile(fh, texthandle, 0, TEXT_NULL_TERMINATE); 
                size_t size = sysmem_handlesize(texthandle);
                //post("the file has %ld characters", size);
                sysfile_close(fh);
                output += *texthandle;
                if (!isspace(output.back()))
                    output += ' ';
                sysmem_freehandle(texthandle);
                included = true;
            }  
        } 

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void preproc::initialize() {
  std::call_once(preprocParserOnceFlag, preprocParserInitialize);
}
