
// Generated from preprocLexer.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  preprocLexer : public antlr4::Lexer {
public:
  enum {
    DONTLOOKHERE = 1, WHITESPACE = 2, INCLUDE = 3, ANY = 4, CLOSE = 5, FILENAME = 6
  };

  enum {
    INCLUDE_MODE = 1
  };

  explicit preprocLexer(antlr4::CharStream *input);

  ~preprocLexer() override;


      bool noInclude;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void DONTLOOKHEREAction(antlr4::RuleContext *context, size_t actionIndex);
  void WHITESPACEAction(antlr4::RuleContext *context, size_t actionIndex);
  void ANYAction(antlr4::RuleContext *context, size_t actionIndex);
  void CLOSEAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool INCLUDESempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

};

