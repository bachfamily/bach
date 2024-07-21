 
#include "ext.h" 


// Generated from bell.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  bellLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, RANGE = 2, UINT = 3, UFLOAT = 4, UPITCH = 5, BTSYMBOL = 6, 
    DQSYMBOL = 7, SQSYMBOL = 8, BACHNULL = 9, BACHNIL = 10, IF = 11, THEN = 12, 
    ELSE = 13, WHILE = 14, FOR = 15, DO = 16, COLLECT = 17, INLET = 18, 
    INTINLET = 19, RATINLET = 20, FLOATINLET = 21, PITCHINLET = 22, OUTLET = 23, 
    DIRINLET = 24, DIROUTLET = 25, BIF = 26, OF = 27, GLOBALVAR = 28, PATCHERVAR = 29, 
    LOCALVAR = 30, NAMEDPARAM = 31, KEEP = 32, UNKEEP = 33, INIT = 34, ARGCOUNT = 35, 
    PUSH = 36, POP = 37, CLOSED = 38, NTH = 39, PICK = 40, KEY = 41, ANTH = 42, 
    APICK = 43, NULLIFY = 44, ASSIGN = 45, WHITESPACE = 46, NEWATOM = 47, 
    POW = 48, APOW = 49, TIMES = 50, ATIMES = 51, DIVDIV = 52, ADIVDIV = 53, 
    DIV = 54, ADIV = 55, REM = 56, AREM = 57, PLUS = 58, APLUS = 59, UPLUS = 60, 
    MINUS = 61, AMINUS = 62, UMINUS = 63, EQUAL = 64, NEQ = 65, LOGNOT = 66, 
    BITNOT = 67, LT = 68, GT = 69, LEQ = 70, GEQ = 71, BITAND = 72, ABITAND = 73, 
    BITXOR = 74, ABITXOR = 75, BITOR = 76, ABITOR = 77, LOGAND = 78, LOGANDEXT = 79, 
    ALOGAND = 80, ALOGANDEXT = 81, LOGXOR = 82, ALOGXOR = 83, LOGOR = 84, 
    ALOGOR = 85, LOGOREXT = 86, ALOGOREXT = 87, LSHIFT = 88, ALSHIFT = 89, 
    RSHIFT = 90, ARSHIFT = 91, REPEAT = 92, AREPEAT = 93, AAPPLY = 94, ACONCAT = 95, 
    ARCONCAT = 96, OPEN = 97, PARAMS = 98, FUNDEF = 99, LIFT = 100, ELLIPSIS = 101, 
    ANYTHING = 102
  };

  explicit bellLexer(antlr4::CharStream *input);

  ~bellLexer() override;



      //// MEMBERS

      bool noParams = true;
      bool noUnary = false;
      long *codeac = 0;

      bool followedBySpace() {
          size_t c = _input->LA(2);
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

      bool notUintRange() {
          int i = 2;
          size_t c;

          do {
              c = _input->LA(i);
                if ((c < '0' || c > '9') && c != '.')
                  return true;
              i++;
          } while (c != '.');

          if (_input->LA(i) == '.' && _input->LA(i+1) == '.' && _input->LA(i+2) != '.')
              return false;
          else
              return true;
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
  void RANGEAction(antlr4::RuleContext *context, size_t actionIndex);
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
  void INLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void INTINLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void RATINLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void FLOATINLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void PITCHINLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void OUTLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void DIRINLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void DIROUTLETAction(antlr4::RuleContext *context, size_t actionIndex);
  void BIFAction(antlr4::RuleContext *context, size_t actionIndex);
  void OFAction(antlr4::RuleContext *context, size_t actionIndex);
  void GLOBALVARAction(antlr4::RuleContext *context, size_t actionIndex);
  void PATCHERVARAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOCALVARAction(antlr4::RuleContext *context, size_t actionIndex);
  void NAMEDPARAMAction(antlr4::RuleContext *context, size_t actionIndex);
  void KEEPAction(antlr4::RuleContext *context, size_t actionIndex);
  void UNKEEPAction(antlr4::RuleContext *context, size_t actionIndex);
  void INITAction(antlr4::RuleContext *context, size_t actionIndex);
  void ARGCOUNTAction(antlr4::RuleContext *context, size_t actionIndex);
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
  void REPEATAction(antlr4::RuleContext *context, size_t actionIndex);
  void AREPEATAction(antlr4::RuleContext *context, size_t actionIndex);
  void AAPPLYAction(antlr4::RuleContext *context, size_t actionIndex);
  void ACONCATAction(antlr4::RuleContext *context, size_t actionIndex);
  void ARCONCATAction(antlr4::RuleContext *context, size_t actionIndex);
  void OPENAction(antlr4::RuleContext *context, size_t actionIndex);
  void PARAMSAction(antlr4::RuleContext *context, size_t actionIndex);
  void FUNDEFAction(antlr4::RuleContext *context, size_t actionIndex);
  void LIFTAction(antlr4::RuleContext *context, size_t actionIndex);
  void ELLIPSISAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool UFLOATSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool PLUSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool MINUSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool OPENSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool PARAMSSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

};

