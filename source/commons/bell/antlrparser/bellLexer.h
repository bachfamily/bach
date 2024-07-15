 
#include "ext.h" 


// Generated from bell.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  bellLexer : public antlr4::Lexer {
public:
  enum {
    UINT = 1, UFLOAT = 2, UPITCH = 3, BTSYMBOL = 4, DQSYMBOL = 5, SQSYMBOL = 6, 
    BACHNULL = 7, BACHNIL = 8, IF = 9, THEN = 10, ELSE = 11, WHILE = 12, 
    FOR = 13, DO = 14, COLLECT = 15, FUNCTION = 16, INLET = 17, INTINLET = 18, 
    RATINLET = 19, FLOATINLET = 20, PITCHINLET = 21, OUTLET = 22, DIRINLET = 23, 
    DIROUTLET = 24, GLOBALVAR = 25, PATCHERVAR = 26, LOCALVAR = 27, NAMEDPARAM = 28, 
    PUSH = 29, POP = 30, CLOSED = 31, NTH = 32, PICK = 33, KEY = 34, ANTH = 35, 
    APICK = 36, NULLIFY = 37, ASSIGN = 38, WHITESPACE = 39, NEWATOM = 40, 
    POW = 41, APOW = 42, TIMES = 43, ATIMES = 44, DIVDIV = 45, ADIVDIV = 46, 
    DIV = 47, ADIV = 48, REM = 49, AREM = 50, PLUS = 51, APLUS = 52, UPLUS = 53, 
    MINUS = 54, AMINUS = 55, UMINUS = 56, EQUAL = 57, NEQ = 58, LOGNOT = 59, 
    BITNOT = 60, LT = 61, GT = 62, LEQ = 63, GEQ = 64, BITAND = 65, ABITAND = 66, 
    BITXOR = 67, ABITXOR = 68, BITOR = 69, ABITOR = 70, LOGAND = 71, LOGANDEXT = 72, 
    ALOGAND = 73, ALOGANDEXT = 74, LOGXOR = 75, ALOGXOR = 76, LOGOR = 77, 
    ALOGOR = 78, LOGOREXT = 79, ALOGOREXT = 80, LSHIFT = 81, ALSHIFT = 82, 
    RSHIFT = 83, ARSHIFT = 84, RANGE = 85, REPEAT = 86, AREPEAT = 87, AAPPLY = 88, 
    ACONCAT = 89, ARCONCAT = 90, OPEN = 91, PARAMS = 92, ANYTHING = 93
  };

  explicit bellLexer(antlr4::CharStream *input);

  ~bellLexer() override;



      //// MEMBERS

      bool noParams = true;
      bool noUnary = false;
      long *codeac = 0;

      bool followedBySpace() {
          int c = _input->LA(2);
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
  void BTSYMBOLAction(antlr4::RuleContext *context, size_t actionIndex);
  void DQSYMBOLAction(antlr4::RuleContext *context, size_t actionIndex);
  void SQSYMBOLAction(antlr4::RuleContext *context, size_t actionIndex);
  void BACHNULLAction(antlr4::RuleContext *context, size_t actionIndex);
  void BACHNILAction(antlr4::RuleContext *context, size_t actionIndex);
  void IFAction(antlr4::RuleContext *context, size_t actionIndex);
  void THENAction(antlr4::RuleContext *context, size_t actionIndex);
  void ELSEAction(antlr4::RuleContext *context, size_t actionIndex);
  void WHILEAction(antlr4::RuleContext *context, size_t actionIndex);
  void FORAction(antlr4::RuleContext *context, size_t actionIndex);
  void DOAction(antlr4::RuleContext *context, size_t actionIndex);
  void COLLECTAction(antlr4::RuleContext *context, size_t actionIndex);
  void FUNCTIONAction(antlr4::RuleContext *context, size_t actionIndex);
  void INLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void INTINLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void RATINLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void FLOATINLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void PITCHINLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void OUTLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void DIRINLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void DIROUTLETAction(antlr4::RuleContext *context, size_t actionIndex);
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
  void ANTHAction(antlr4::RuleContext *context, size_t actionIndex);
  void APICKAction(antlr4::RuleContext *context, size_t actionIndex);
  void NULLIFYAction(antlr4::RuleContext *context, size_t actionIndex);
  void ASSIGNAction(antlr4::RuleContext *context, size_t actionIndex);
  void WHITESPACEAction(antlr4::RuleContext *context, size_t actionIndex);
  void NEWATOMAction(antlr4::RuleContext *context, size_t actionIndex);
  void POWAction(antlr4::RuleContext *context, size_t actionIndex);
  void APOWAction(antlr4::RuleContext *context, size_t actionIndex);
  void TIMESAction(antlr4::RuleContext *context, size_t actionIndex);
  void ATIMESAction(antlr4::RuleContext *context, size_t actionIndex);
  void DIVDIVAction(antlr4::RuleContext *context, size_t actionIndex);
  void ADIVDIVAction(antlr4::RuleContext *context, size_t actionIndex);
  void DIVAction(antlr4::RuleContext *context, size_t actionIndex);
  void ADIVAction(antlr4::RuleContext *context, size_t actionIndex);
  void REMAction(antlr4::RuleContext *context, size_t actionIndex);
  void AREMAction(antlr4::RuleContext *context, size_t actionIndex);
  void PLUSAction(antlr4::RuleContext *context, size_t actionIndex);
  void APLUSAction(antlr4::RuleContext *context, size_t actionIndex);
  void UPLUSAction(antlr4::RuleContext *context, size_t actionIndex);
  void MINUSAction(antlr4::RuleContext *context, size_t actionIndex);
  void AMINUSAction(antlr4::RuleContext *context, size_t actionIndex);
  void UMINUSAction(antlr4::RuleContext *context, size_t actionIndex);
  void EQUALAction(antlr4::RuleContext *context, size_t actionIndex);
  void NEQAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOGNOTAction(antlr4::RuleContext *context, size_t actionIndex);
  void BITNOTAction(antlr4::RuleContext *context, size_t actionIndex);
  void LTAction(antlr4::RuleContext *context, size_t actionIndex);
  void GTAction(antlr4::RuleContext *context, size_t actionIndex);
  void LEQAction(antlr4::RuleContext *context, size_t actionIndex);
  void GEQAction(antlr4::RuleContext *context, size_t actionIndex);
  void BITANDAction(antlr4::RuleContext *context, size_t actionIndex);
  void ABITANDAction(antlr4::RuleContext *context, size_t actionIndex);
  void BITXORAction(antlr4::RuleContext *context, size_t actionIndex);
  void ABITXORAction(antlr4::RuleContext *context, size_t actionIndex);
  void BITORAction(antlr4::RuleContext *context, size_t actionIndex);
  void ABITORAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOGANDAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOGANDEXTAction(antlr4::RuleContext *context, size_t actionIndex);
  void ALOGANDAction(antlr4::RuleContext *context, size_t actionIndex);
  void ALOGANDEXTAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOGXORAction(antlr4::RuleContext *context, size_t actionIndex);
  void ALOGXORAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOGORAction(antlr4::RuleContext *context, size_t actionIndex);
  void ALOGORAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOGOREXTAction(antlr4::RuleContext *context, size_t actionIndex);
  void ALOGOREXTAction(antlr4::RuleContext *context, size_t actionIndex);
  void LSHIFTAction(antlr4::RuleContext *context, size_t actionIndex);
  void ALSHIFTAction(antlr4::RuleContext *context, size_t actionIndex);
  void RSHIFTAction(antlr4::RuleContext *context, size_t actionIndex);
  void ARSHIFTAction(antlr4::RuleContext *context, size_t actionIndex);
  void RANGEAction(antlr4::RuleContext *context, size_t actionIndex);
  void REPEATAction(antlr4::RuleContext *context, size_t actionIndex);
  void AREPEATAction(antlr4::RuleContext *context, size_t actionIndex);
  void AAPPLYAction(antlr4::RuleContext *context, size_t actionIndex);
  void ACONCATAction(antlr4::RuleContext *context, size_t actionIndex);
  void ARCONCATAction(antlr4::RuleContext *context, size_t actionIndex);
  void OPENAction(antlr4::RuleContext *context, size_t actionIndex);
  void PARAMSAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool PLUSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool MINUSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool OPENSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool PARAMSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

};

