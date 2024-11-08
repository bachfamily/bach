 
#include "ext.h" 


// Generated from bell.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  bellLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, RANGE = 2, UINT = 3, UFLOAT = 4, ETPITCHBASE = 5, JIPITCHBASE = 6, 
    JIPITCHCOMMAS = 7, T = 8, R = 9, K_PI = 10, BTSYMBOL = 11, DQSYMBOL = 12, 
    SQSYMBOL = 13, EMPTYSYMBOL = 14, BACHNULL = 15, BACHNIL = 16, IF = 17, 
    THEN = 18, ELSE = 19, WHILE = 20, FOR = 21, IN = 22, AS = 23, WITH = 24, 
    DO = 25, COLLECT = 26, INLET = 27, INTINLET = 28, RATINLET = 29, FLOATINLET = 30, 
    PITCHINLET = 31, OUTLET = 32, DIRINLET = 33, DIROUTLET = 34, BIF = 35, 
    OF = 36, ARGCOUNT = 37, KEEP = 38, UNKEEP = 39, INIT = 40, GLOBALVAR = 41, 
    PATCHERVAR = 42, LOCALVAR = 43, NAMEDPARAM = 44, VOID = 45, PUSH = 46, 
    POP = 47, CLOSED = 48, NTH = 49, PICK = 50, KEY = 51, ANTH = 52, APICK = 53, 
    NULLIFY = 54, ASSIGN = 55, WHITESPACE = 56, NEWATOM = 57, POW = 58, 
    APOW = 59, TIMES = 60, ATIMES = 61, DIVDIV = 62, ADIVDIV = 63, DIV = 64, 
    ADIV = 65, REM = 66, AREM = 67, PLUS = 68, APLUS = 69, UPLUS = 70, MINUS = 71, 
    AMINUS = 72, UMINUS = 73, EQUAL = 74, NEQ = 75, LOGNOT = 76, BITNOT = 77, 
    LT = 78, GT = 79, LEQ = 80, GEQ = 81, BITAND = 82, ABITAND = 83, BITXOR = 84, 
    ABITXOR = 85, BITOR = 86, ABITOR = 87, LOGAND = 88, LOGANDEXT = 89, 
    ALOGAND = 90, ALOGANDEXT = 91, LOGXOR = 92, ALOGXOR = 93, LOGOR = 94, 
    ALOGOR = 95, LOGOREXT = 96, ALOGOREXT = 97, LSHIFT = 98, ALSHIFT = 99, 
    RSHIFT = 100, ARSHIFT = 101, REPEAT = 102, AREPEAT = 103, AAPPLY = 104, 
    ACONCAT = 105, ARCONCAT = 106, OPEN = 107, PARAMS = 108, FUNDEF = 109, 
    LIFT = 110, ELLIPSIS = 111, BLOCKCOMMENT = 112, LINECOMMENT = 113, ANYTHING = 114
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
  void ETPITCHBASEAction(antlr4::RuleContext *context, size_t actionIndex);
  void JIPITCHBASEAction(antlr4::RuleContext *context, size_t actionIndex);
  void JIPITCHCOMMASAction(antlr4::RuleContext *context, size_t actionIndex);
  void TAction(antlr4::RuleContext *context, size_t actionIndex);
  void RAction(antlr4::RuleContext *context, size_t actionIndex);
  void K_PIAction(antlr4::RuleContext *context, size_t actionIndex);
  void BTSYMBOLAction(antlr4::RuleContext *context, size_t actionIndex);
  void DQSYMBOLAction(antlr4::RuleContext *context, size_t actionIndex);
  void SQSYMBOLAction(antlr4::RuleContext *context, size_t actionIndex);
  void EMPTYSYMBOLAction(antlr4::RuleContext *context, size_t actionIndex);
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
  void ARGCOUNTAction(antlr4::RuleContext *context, size_t actionIndex);
  void KEEPAction(antlr4::RuleContext *context, size_t actionIndex);
  void UNKEEPAction(antlr4::RuleContext *context, size_t actionIndex);
  void INITAction(antlr4::RuleContext *context, size_t actionIndex);
  void GLOBALVARAction(antlr4::RuleContext *context, size_t actionIndex);
  void PATCHERVARAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOCALVARAction(antlr4::RuleContext *context, size_t actionIndex);
  void NAMEDPARAMAction(antlr4::RuleContext *context, size_t actionIndex);
  void VOIDAction(antlr4::RuleContext *context, size_t actionIndex);
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

