 
#include "ext.h" 


// Generated from bell.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  bellLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, RANGE = 2, UINT = 3, UFLOAT = 4, UPITCH = 5, BTSYMBOL = 6, 
    DQSYMBOL = 7, SQSYMBOL = 8, BACHNULL = 9, BACHNIL = 10, IF = 11, THEN = 12, 
    ELSE = 13, WHILE = 14, FOR = 15, IN = 16, AS = 17, WITH = 18, DO = 19, 
    COLLECT = 20, INLET = 21, INTINLET = 22, RATINLET = 23, FLOATINLET = 24, 
    PITCHINLET = 25, OUTLET = 26, DIRINLET = 27, DIROUTLET = 28, BIF = 29, 
    OF = 30, GLOBALVAR = 31, PATCHERVAR = 32, LOCALVAR = 33, NAMEDPARAM = 34, 
    KEEP = 35, UNKEEP = 36, INIT = 37, ARGCOUNT = 38, PUSH = 39, POP = 40, 
    CLOSED = 41, NTH = 42, PICK = 43, KEY = 44, ANTH = 45, APICK = 46, NULLIFY = 47, 
    ASSIGN = 48, WHITESPACE = 49, NEWATOM = 50, POW = 51, APOW = 52, TIMES = 53, 
    ATIMES = 54, DIVDIV = 55, ADIVDIV = 56, DIV = 57, ADIV = 58, REM = 59, 
    AREM = 60, PLUS = 61, APLUS = 62, UPLUS = 63, MINUS = 64, AMINUS = 65, 
    UMINUS = 66, EQUAL = 67, NEQ = 68, LOGNOT = 69, BITNOT = 70, LT = 71, 
    GT = 72, LEQ = 73, GEQ = 74, BITAND = 75, ABITAND = 76, BITXOR = 77, 
    ABITXOR = 78, BITOR = 79, ABITOR = 80, LOGAND = 81, LOGANDEXT = 82, 
    ALOGAND = 83, ALOGANDEXT = 84, LOGXOR = 85, ALOGXOR = 86, LOGOR = 87, 
    ALOGOR = 88, LOGOREXT = 89, ALOGOREXT = 90, LSHIFT = 91, ALSHIFT = 92, 
    RSHIFT = 93, ARSHIFT = 94, REPEAT = 95, AREPEAT = 96, AAPPLY = 97, ACONCAT = 98, 
    ARCONCAT = 99, OPEN = 100, PARAMS = 101, FUNDEF = 102, LIFT = 103, ELLIPSIS = 104, 
    ANYTHING = 105
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
  void INAction(antlr4::RuleContext *context, size_t actionIndex);
  void ASAction(antlr4::RuleContext *context, size_t actionIndex);
  void WITHAction(antlr4::RuleContext *context, size_t actionIndex);
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

