 
#include "ext.h" 


// Generated from bell.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  bellLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, RANGE = 2, UINT = 3, UFLOAT = 4, UPITCH = 5, BTSYMBOL = 6, 
    DQSYMBOL = 7, SQSYMBOL = 8, EMPTYSYMBOL = 9, BACHNULL = 10, BACHNIL = 11, 
    IF = 12, THEN = 13, ELSE = 14, WHILE = 15, FOR = 16, IN = 17, AS = 18, 
    WITH = 19, DO = 20, COLLECT = 21, INLET = 22, INTINLET = 23, RATINLET = 24, 
    FLOATINLET = 25, PITCHINLET = 26, OUTLET = 27, DIRINLET = 28, DIROUTLET = 29, 
    BIF = 30, OF = 31, GLOBALVAR = 32, PATCHERVAR = 33, LOCALVAR = 34, NAMEDPARAM = 35, 
    KEEP = 36, UNKEEP = 37, INIT = 38, ARGCOUNT = 39, PUSH = 40, POP = 41, 
    CLOSED = 42, NTH = 43, PICK = 44, KEY = 45, ANTH = 46, APICK = 47, NULLIFY = 48, 
    ASSIGN = 49, WHITESPACE = 50, NEWATOM = 51, POW = 52, APOW = 53, TIMES = 54, 
    ATIMES = 55, DIVDIV = 56, ADIVDIV = 57, DIV = 58, ADIV = 59, REM = 60, 
    AREM = 61, PLUS = 62, APLUS = 63, UPLUS = 64, MINUS = 65, AMINUS = 66, 
    UMINUS = 67, EQUAL = 68, NEQ = 69, LOGNOT = 70, BITNOT = 71, LT = 72, 
    GT = 73, LEQ = 74, GEQ = 75, BITAND = 76, ABITAND = 77, BITXOR = 78, 
    ABITXOR = 79, BITOR = 80, ABITOR = 81, LOGAND = 82, LOGANDEXT = 83, 
    ALOGAND = 84, ALOGANDEXT = 85, LOGXOR = 86, ALOGXOR = 87, LOGOR = 88, 
    ALOGOR = 89, LOGOREXT = 90, ALOGOREXT = 91, LSHIFT = 92, ALSHIFT = 93, 
    RSHIFT = 94, ARSHIFT = 95, REPEAT = 96, AREPEAT = 97, AAPPLY = 98, ACONCAT = 99, 
    ARCONCAT = 100, OPEN = 101, PARAMS = 102, FUNDEF = 103, LIFT = 104, 
    ELLIPSIS = 105, BLOCKCOMMENT = 106, LINECOMMENT = 107, ANYTHING = 108
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

