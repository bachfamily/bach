 
#include "ext.h" 


// Generated from bell.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  bellLexer : public antlr4::Lexer {
public:
  enum {
    UINT = 1, UFLOAT = 2, UPITCH = 3, IF = 4, THEN = 5, ELSE = 6, WHILE = 7, 
    FOR = 8, DO = 9, COLLECT = 10, FUNCTION = 11, INLET = 12, GLOBALVAR = 13, 
    PATCHERVAR = 14, LOCALVAR = 15, NAMEDPARAM = 16, PUSH = 17, POP = 18, 
    CLOSED = 19, NTH = 20, PICK = 21, KEY = 22, NULLIFY = 23, ASSIGN = 24, 
    WHITESPACE = 25, NEWATOM = 26, POW = 27, TIMES = 28, DIVDIV = 29, DIV = 30, 
    PLUS = 31, UPLUS = 32, MINUS = 33, UMINUS = 34, REM = 35, EQUAL = 36, 
    NEQ = 37, LOGNOT = 38, BITNOT = 39, LT = 40, GT = 41, LEQ = 42, GEQ = 43, 
    BITAND = 44, BITXOR = 45, BITOR = 46, LOGAND = 47, LOGANDEXT = 48, LOGXOR = 49, 
    LOGOR = 50, LOGOREXT = 51, LSHIFT = 52, RSHIFT = 53, RANGE = 54, REPEAT = 55, 
    OPEN = 56, PARAMS = 57, ANYTHING = 58
  };

  explicit bellLexer(antlr4::CharStream *input);

  ~bellLexer() override;



      //// MEMBERS

      bool noParams = true;
      bool noUnary = false;
      long *codeac = 0;

      bool followedBySpace() {
          int c = _input->LA(2);
          post("%c", c);
          switch (c) {
              case ' ':
              case '\x01':
              case '\t':
              case '\n':
              case '\r':
                  return true;
              default:
                  return false;
          }
      }

      bool notUnary() {
          return noUnary || followedBySpace();
      }

      void setCodeac(long* c) { codeac = c; }

      //// MEMBERS END


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
  void UINTAction(antlr4::RuleContext *context, size_t actionIndex);
  void UFLOATAction(antlr4::RuleContext *context, size_t actionIndex);
  void UPITCHAction(antlr4::RuleContext *context, size_t actionIndex);
  void IFAction(antlr4::RuleContext *context, size_t actionIndex);
  void THENAction(antlr4::RuleContext *context, size_t actionIndex);
  void ELSEAction(antlr4::RuleContext *context, size_t actionIndex);
  void WHILEAction(antlr4::RuleContext *context, size_t actionIndex);
  void FORAction(antlr4::RuleContext *context, size_t actionIndex);
  void DOAction(antlr4::RuleContext *context, size_t actionIndex);
  void COLLECTAction(antlr4::RuleContext *context, size_t actionIndex);
  void FUNCTIONAction(antlr4::RuleContext *context, size_t actionIndex);
  void INLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void GLOBALVARAction(antlr4::RuleContext *context, size_t actionIndex);
  void PATCHERVARAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOCALVARAction(antlr4::RuleContext *context, size_t actionIndex);
  void NAMEDPARAMAction(antlr4::RuleContext *context, size_t actionIndex);
  void PUSHAction(antlr4::RuleContext *context, size_t actionIndex);
  void POPAction(antlr4::RuleContext *context, size_t actionIndex);
  void CLOSEDAction(antlr4::RuleContext *context, size_t actionIndex);
  void NTHAction(antlr4::RuleContext *context, size_t actionIndex);
  void PICKAction(antlr4::RuleContext *context, size_t actionIndex);
  void KEYAction(antlr4::RuleContext *context, size_t actionIndex);
  void NULLIFYAction(antlr4::RuleContext *context, size_t actionIndex);
  void ASSIGNAction(antlr4::RuleContext *context, size_t actionIndex);
  void WHITESPACEAction(antlr4::RuleContext *context, size_t actionIndex);
  void NEWATOMAction(antlr4::RuleContext *context, size_t actionIndex);
  void POWAction(antlr4::RuleContext *context, size_t actionIndex);
  void TIMESAction(antlr4::RuleContext *context, size_t actionIndex);
  void DIVDIVAction(antlr4::RuleContext *context, size_t actionIndex);
  void DIVAction(antlr4::RuleContext *context, size_t actionIndex);
  void PLUSAction(antlr4::RuleContext *context, size_t actionIndex);
  void UPLUSAction(antlr4::RuleContext *context, size_t actionIndex);
  void MINUSAction(antlr4::RuleContext *context, size_t actionIndex);
  void UMINUSAction(antlr4::RuleContext *context, size_t actionIndex);
  void REMAction(antlr4::RuleContext *context, size_t actionIndex);
  void EQUALAction(antlr4::RuleContext *context, size_t actionIndex);
  void NEQAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOGNOTAction(antlr4::RuleContext *context, size_t actionIndex);
  void BITNOTAction(antlr4::RuleContext *context, size_t actionIndex);
  void LTAction(antlr4::RuleContext *context, size_t actionIndex);
  void GTAction(antlr4::RuleContext *context, size_t actionIndex);
  void LEQAction(antlr4::RuleContext *context, size_t actionIndex);
  void GEQAction(antlr4::RuleContext *context, size_t actionIndex);
  void BITANDAction(antlr4::RuleContext *context, size_t actionIndex);
  void BITXORAction(antlr4::RuleContext *context, size_t actionIndex);
  void BITORAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOGANDAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOGANDEXTAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOGXORAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOGORAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOGOREXTAction(antlr4::RuleContext *context, size_t actionIndex);
  void LSHIFTAction(antlr4::RuleContext *context, size_t actionIndex);
  void RSHIFTAction(antlr4::RuleContext *context, size_t actionIndex);
  void RANGEAction(antlr4::RuleContext *context, size_t actionIndex);
  void REPEATAction(antlr4::RuleContext *context, size_t actionIndex);
  void OPENAction(antlr4::RuleContext *context, size_t actionIndex);
  void PARAMSAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool PLUSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool MINUSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool OPENSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool PARAMSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

};

