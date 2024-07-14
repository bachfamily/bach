// Generated from /Users/aa/Documents/Max 8/Packages/bach/source/commons/bell/antlrparser/bell.g4 by ANTLR 4.13.1
 
#include "ext.h" 

import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class bellLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		UINT=1, UFLOAT=2, UPITCH=3, IF=4, THEN=5, ELSE=6, WHILE=7, FOR=8, DO=9, 
		COLLECT=10, FUNCTION=11, INLET=12, GLOBALVAR=13, PATCHERVAR=14, LOCALVAR=15, 
		NAMEDPARAM=16, PUSH=17, POP=18, CLOSED=19, NTH=20, PICK=21, KEY=22, NULLIFY=23, 
		ASSIGN=24, WHITESPACE=25, NEWATOM=26, POW=27, TIMES=28, DIVDIV=29, DIV=30, 
		PLUS=31, UPLUS=32, MINUS=33, UMINUS=34, REM=35, EQUAL=36, NEQ=37, LOGNOT=38, 
		BITNOT=39, LT=40, GT=41, LEQ=42, GEQ=43, BITAND=44, BITXOR=45, BITOR=46, 
		LOGAND=47, LOGANDEXT=48, LOGXOR=49, LOGOR=50, LOGOREXT=51, LSHIFT=52, 
		RSHIFT=53, RANGE=54, REPEAT=55, OPEN=56, PARAMS=57, ANYTHING=58;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"UINT", "UFLOAT", "UPITCH", "NOTENAME", "ACCIDENTAL", "RAT", "IF", "THEN", 
			"ELSE", "WHILE", "FOR", "DO", "COLLECT", "FUNCTION", "INLET", "GLOBALVAR", 
			"PATCHERVAR", "LOCALVAR", "NAMEDPARAM", "ID", "PUSH", "POP", "CLOSED", 
			"NTH", "PICK", "KEY", "NULLIFY", "ASSIGN", "WHITESPACE", "NEWATOM", "POW", 
			"TIMES", "DIVDIV", "DIV", "PLUS", "UPLUS", "MINUS", "UMINUS", "REM", 
			"EQUAL", "NEQ", "LOGNOT", "BITNOT", "LT", "GT", "LEQ", "GEQ", "BITAND", 
			"BITXOR", "BITOR", "LOGAND", "LOGANDEXT", "LOGXOR", "LOGOR", "LOGOREXT", 
			"LSHIFT", "RSHIFT", "RANGE", "REPEAT", "OPEN", "PARAMS", "ANYTHING"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, "'if'", "'then'", "'else'", "'while'", "'for'", 
			"'do'", "'collect'", null, null, null, null, null, null, "'['", "']'", 
			"')'", "':'", "'::'", "'.'", "';'", "'='", null, null, "'**'", "'*'", 
			"'//'", "'/'", null, "'+'", null, "'-'", "'%'", "'=='", "'!='", "'!'", 
			"'~'", "'<'", "'>'", "'<='", "'>='", "'&'", "'^'", "'|'", "'&&'", "'&&&'", 
			"'^^'", "'||'", "'|||'", "'<<'", "'>>'", "'...'", "':*'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "UINT", "UFLOAT", "UPITCH", "IF", "THEN", "ELSE", "WHILE", "FOR", 
			"DO", "COLLECT", "FUNCTION", "INLET", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", 
			"NAMEDPARAM", "PUSH", "POP", "CLOSED", "NTH", "PICK", "KEY", "NULLIFY", 
			"ASSIGN", "WHITESPACE", "NEWATOM", "POW", "TIMES", "DIVDIV", "DIV", "PLUS", 
			"UPLUS", "MINUS", "UMINUS", "REM", "EQUAL", "NEQ", "LOGNOT", "BITNOT", 
			"LT", "GT", "LEQ", "GEQ", "BITAND", "BITXOR", "BITOR", "LOGAND", "LOGANDEXT", 
			"LOGXOR", "LOGOR", "LOGOREXT", "LSHIFT", "RSHIFT", "RANGE", "REPEAT", 
			"OPEN", "PARAMS", "ANYTHING"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}



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


	public bellLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "bell.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	@Override
	public void action(RuleContext _localctx, int ruleIndex, int actionIndex) {
		switch (ruleIndex) {
		case 0:
			UINT_action((RuleContext)_localctx, actionIndex);
			break;
		case 1:
			UFLOAT_action((RuleContext)_localctx, actionIndex);
			break;
		case 2:
			UPITCH_action((RuleContext)_localctx, actionIndex);
			break;
		case 6:
			IF_action((RuleContext)_localctx, actionIndex);
			break;
		case 7:
			THEN_action((RuleContext)_localctx, actionIndex);
			break;
		case 8:
			ELSE_action((RuleContext)_localctx, actionIndex);
			break;
		case 9:
			WHILE_action((RuleContext)_localctx, actionIndex);
			break;
		case 10:
			FOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 11:
			DO_action((RuleContext)_localctx, actionIndex);
			break;
		case 12:
			COLLECT_action((RuleContext)_localctx, actionIndex);
			break;
		case 13:
			FUNCTION_action((RuleContext)_localctx, actionIndex);
			break;
		case 14:
			INLET_action((RuleContext)_localctx, actionIndex);
			break;
		case 15:
			GLOBALVAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 16:
			PATCHERVAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 17:
			LOCALVAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 18:
			NAMEDPARAM_action((RuleContext)_localctx, actionIndex);
			break;
		case 20:
			PUSH_action((RuleContext)_localctx, actionIndex);
			break;
		case 21:
			POP_action((RuleContext)_localctx, actionIndex);
			break;
		case 22:
			CLOSED_action((RuleContext)_localctx, actionIndex);
			break;
		case 23:
			NTH_action((RuleContext)_localctx, actionIndex);
			break;
		case 24:
			PICK_action((RuleContext)_localctx, actionIndex);
			break;
		case 25:
			KEY_action((RuleContext)_localctx, actionIndex);
			break;
		case 26:
			NULLIFY_action((RuleContext)_localctx, actionIndex);
			break;
		case 27:
			ASSIGN_action((RuleContext)_localctx, actionIndex);
			break;
		case 28:
			WHITESPACE_action((RuleContext)_localctx, actionIndex);
			break;
		case 29:
			NEWATOM_action((RuleContext)_localctx, actionIndex);
			break;
		case 30:
			POW_action((RuleContext)_localctx, actionIndex);
			break;
		case 31:
			TIMES_action((RuleContext)_localctx, actionIndex);
			break;
		case 32:
			DIVDIV_action((RuleContext)_localctx, actionIndex);
			break;
		case 33:
			DIV_action((RuleContext)_localctx, actionIndex);
			break;
		case 34:
			PLUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 35:
			UPLUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 36:
			MINUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 37:
			UMINUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 38:
			REM_action((RuleContext)_localctx, actionIndex);
			break;
		case 39:
			EQUAL_action((RuleContext)_localctx, actionIndex);
			break;
		case 40:
			NEQ_action((RuleContext)_localctx, actionIndex);
			break;
		case 41:
			LOGNOT_action((RuleContext)_localctx, actionIndex);
			break;
		case 42:
			BITNOT_action((RuleContext)_localctx, actionIndex);
			break;
		case 43:
			LT_action((RuleContext)_localctx, actionIndex);
			break;
		case 44:
			GT_action((RuleContext)_localctx, actionIndex);
			break;
		case 45:
			LEQ_action((RuleContext)_localctx, actionIndex);
			break;
		case 46:
			GEQ_action((RuleContext)_localctx, actionIndex);
			break;
		case 47:
			BITAND_action((RuleContext)_localctx, actionIndex);
			break;
		case 48:
			BITXOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 49:
			BITOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 50:
			LOGAND_action((RuleContext)_localctx, actionIndex);
			break;
		case 51:
			LOGANDEXT_action((RuleContext)_localctx, actionIndex);
			break;
		case 52:
			LOGXOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 53:
			LOGOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 54:
			LOGOREXT_action((RuleContext)_localctx, actionIndex);
			break;
		case 55:
			LSHIFT_action((RuleContext)_localctx, actionIndex);
			break;
		case 56:
			RSHIFT_action((RuleContext)_localctx, actionIndex);
			break;
		case 57:
			RANGE_action((RuleContext)_localctx, actionIndex);
			break;
		case 58:
			REPEAT_action((RuleContext)_localctx, actionIndex);
			break;
		case 59:
			OPEN_action((RuleContext)_localctx, actionIndex);
			break;
		case 60:
			PARAMS_action((RuleContext)_localctx, actionIndex);
			break;
		}
	}
	private void UINT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 0:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void UFLOAT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 1:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void UPITCH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 2:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void IF_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 3:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void THEN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 4:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ELSE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 5:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void WHILE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 6:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void FOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 7:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DO_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 8:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void COLLECT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 9:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void FUNCTION_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 10:
			 noParams = noUnary = false; 
			break;
		}
	}
	private void INLET_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 11:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void GLOBALVAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 12:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void PATCHERVAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 13:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void LOCALVAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 14:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void NAMEDPARAM_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 15:
			 noParams = true; noUnary = true; 
			break;
		}
	}
	private void PUSH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 16:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void POP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 17:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void CLOSED_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 18:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void NTH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 19:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PICK_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 20:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void KEY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 21:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void NULLIFY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 22:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ASSIGN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 23:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void WHITESPACE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 24:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void NEWATOM_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 25:
			 noParams = true; noUnary = false; (*codeac)++; 
			break;
		}
	}
	private void POW_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 26:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void TIMES_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 27:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DIVDIV_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 28:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DIV_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 29:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PLUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 30:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void UPLUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 31:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void MINUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 32:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void UMINUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 33:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void REM_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 34:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void EQUAL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 35:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void NEQ_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 36:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LOGNOT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 37:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void BITNOT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 38:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 39:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void GT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 40:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LEQ_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 41:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void GEQ_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 42:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void BITAND_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 43:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void BITXOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 44:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void BITOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 45:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LOGAND_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 46:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LOGANDEXT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 47:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LOGXOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 48:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LOGOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 49:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LOGOREXT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 50:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LSHIFT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 51:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void RSHIFT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 52:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void RANGE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 53:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void REPEAT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 54:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void OPEN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 55:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PARAMS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 56:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	@Override
	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 34:
			return PLUS_sempred((RuleContext)_localctx, predIndex);
		case 36:
			return MINUS_sempred((RuleContext)_localctx, predIndex);
		case 59:
			return OPEN_sempred((RuleContext)_localctx, predIndex);
		case 60:
			return PARAMS_sempred((RuleContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean PLUS_sempred(RuleContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return  notUnary() ;
		}
		return true;
	}
	private boolean MINUS_sempred(RuleContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return  notUnary() ;
		}
		return true;
	}
	private boolean OPEN_sempred(RuleContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return  noParams ;
		}
		return true;
	}
	private boolean PARAMS_sempred(RuleContext _localctx, int predIndex) {
		switch (predIndex) {
		case 3:
			return  !noParams ;
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0000:\u01ed\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002"+
		"\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002"+
		"\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002"+
		"\u0015\u0007\u0015\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002"+
		"\u0018\u0007\u0018\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002"+
		"\u001b\u0007\u001b\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d\u0002"+
		"\u001e\u0007\u001e\u0002\u001f\u0007\u001f\u0002 \u0007 \u0002!\u0007"+
		"!\u0002\"\u0007\"\u0002#\u0007#\u0002$\u0007$\u0002%\u0007%\u0002&\u0007"+
		"&\u0002\'\u0007\'\u0002(\u0007(\u0002)\u0007)\u0002*\u0007*\u0002+\u0007"+
		"+\u0002,\u0007,\u0002-\u0007-\u0002.\u0007.\u0002/\u0007/\u00020\u0007"+
		"0\u00021\u00071\u00022\u00072\u00023\u00073\u00024\u00074\u00025\u0007"+
		"5\u00026\u00076\u00027\u00077\u00028\u00078\u00029\u00079\u0002:\u0007"+
		":\u0002;\u0007;\u0002<\u0007<\u0002=\u0007=\u0001\u0000\u0004\u0000\u007f"+
		"\b\u0000\u000b\u0000\f\u0000\u0080\u0001\u0000\u0001\u0000\u0001\u0001"+
		"\u0005\u0001\u0086\b\u0001\n\u0001\f\u0001\u0089\t\u0001\u0001\u0001\u0001"+
		"\u0001\u0004\u0001\u008d\b\u0001\u000b\u0001\f\u0001\u008e\u0001\u0001"+
		"\u0004\u0001\u0092\b\u0001\u000b\u0001\f\u0001\u0093\u0001\u0001\u0003"+
		"\u0001\u0097\b\u0001\u0001\u0001\u0001\u0001\u0003\u0001\u009b\b\u0001"+
		"\u0001\u0001\u0004\u0001\u009e\b\u0001\u000b\u0001\f\u0001\u009f\u0003"+
		"\u0001\u00a2\b\u0001\u0001\u0001\u0004\u0001\u00a5\b\u0001\u000b\u0001"+
		"\f\u0001\u00a6\u0001\u0001\u0001\u0001\u0003\u0001\u00ab\b\u0001\u0001"+
		"\u0001\u0004\u0001\u00ae\b\u0001\u000b\u0001\f\u0001\u00af\u0003\u0001"+
		"\u00b2\b\u0001\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0003\u0002"+
		"\u00b8\b\u0002\u0001\u0002\u0005\u0002\u00bb\b\u0002\n\u0002\f\u0002\u00be"+
		"\t\u0002\u0001\u0002\u0001\u0002\u0005\u0002\u00c2\b\u0002\n\u0002\f\u0002"+
		"\u00c5\t\u0002\u0001\u0002\u0001\u0002\u0003\u0002\u00c9\b\u0002\u0001"+
		"\u0002\u0001\u0002\u0003\u0002\u00cd\b\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0003\u0003\u0003\u00d2\b\u0003\u0001\u0004\u0004\u0004\u00d5\b\u0004"+
		"\u000b\u0004\f\u0004\u00d6\u0001\u0005\u0001\u0005\u0001\u0005\u0005\u0005"+
		"\u00dc\b\u0005\n\u0005\f\u0005\u00df\t\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f"+
		"\u0001\f\u0001\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0003\r\u011f\b\r\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0004\u000e\u0124\b\u000e\u000b\u000e\f\u000e"+
		"\u0125\u0001\u000e\u0001\u000e\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001"+
		"\u0013\u0001\u0013\u0005\u0013\u013b\b\u0013\n\u0013\f\u0013\u013e\t\u0013"+
		"\u0001\u0013\u0003\u0013\u0141\b\u0013\u0001\u0014\u0001\u0014\u0001\u0014"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0001\u0018\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u001a"+
		"\u0001\u001a\u0001\u001a\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001c"+
		"\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001d\u0001\u001d"+
		"\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001e\u0001\u001e\u0001\u001e"+
		"\u0001\u001e\u0001\u001e\u0001\u001f\u0001\u001f\u0001\u001f\u0001 \u0001"+
		" \u0001 \u0001 \u0001 \u0001!\u0001!\u0001!\u0001\"\u0001\"\u0001\"\u0001"+
		"\"\u0001#\u0001#\u0001#\u0001$\u0001$\u0001$\u0001$\u0001%\u0001%\u0001"+
		"%\u0001&\u0001&\u0001&\u0001\'\u0001\'\u0001\'\u0001\'\u0001\'\u0001("+
		"\u0001(\u0001(\u0001(\u0001(\u0001)\u0001)\u0001)\u0001*\u0001*\u0001"+
		"*\u0001+\u0001+\u0001+\u0001,\u0001,\u0001,\u0001-\u0001-\u0001-\u0001"+
		"-\u0001-\u0001.\u0001.\u0001.\u0001.\u0001.\u0001/\u0001/\u0001/\u0001"+
		"0\u00010\u00010\u00011\u00011\u00011\u00012\u00012\u00012\u00012\u0001"+
		"2\u00013\u00013\u00013\u00013\u00013\u00013\u00014\u00014\u00014\u0001"+
		"4\u00014\u00015\u00015\u00015\u00015\u00015\u00016\u00016\u00016\u0001"+
		"6\u00016\u00016\u00017\u00017\u00017\u00017\u00017\u00018\u00018\u0001"+
		"8\u00018\u00018\u00019\u00019\u00019\u00019\u00019\u00019\u0001:\u0001"+
		":\u0001:\u0001:\u0001:\u0001;\u0001;\u0001;\u0001;\u0001<\u0001<\u0001"+
		"<\u0001<\u0001=\u0004=\u01ea\b=\u000b=\f=\u01eb\u0001\u01eb\u0000>\u0001"+
		"\u0001\u0003\u0002\u0005\u0003\u0007\u0000\t\u0000\u000b\u0000\r\u0004"+
		"\u000f\u0005\u0011\u0006\u0013\u0007\u0015\b\u0017\t\u0019\n\u001b\u000b"+
		"\u001d\f\u001f\r!\u000e#\u000f%\u0010\'\u0000)\u0011+\u0012-\u0013/\u0014"+
		"1\u00153\u00165\u00177\u00189\u0019;\u001a=\u001b?\u001cA\u001dC\u001e"+
		"E\u001fG I!K\"M#O$Q%S&U\'W(Y)[*]+_,a-c.e/g0i1k2m3o4q5s6u7w8y9{:\u0001"+
		"\u0000\u000b\u0001\u000009\u0002\u0000EEee\u0002\u0000++--\u0002\u0000"+
		"AGag\u0007\u0000##^^bbddqqvvxx\u0002\u0000llxx\u0002\u0000AZaz\u0004\u0000"+
		"09AZ__az\u0003\u000009AZaz\u0003\u0000\t\n\r\r  \u0001\u0000\u0001\u0001"+
		"\u0201\u0000\u0001\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000"+
		"\u0000\u0000\u0005\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000\u0000\u0000"+
		"\u0000\u000f\u0001\u0000\u0000\u0000\u0000\u0011\u0001\u0000\u0000\u0000"+
		"\u0000\u0013\u0001\u0000\u0000\u0000\u0000\u0015\u0001\u0000\u0000\u0000"+
		"\u0000\u0017\u0001\u0000\u0000\u0000\u0000\u0019\u0001\u0000\u0000\u0000"+
		"\u0000\u001b\u0001\u0000\u0000\u0000\u0000\u001d\u0001\u0000\u0000\u0000"+
		"\u0000\u001f\u0001\u0000\u0000\u0000\u0000!\u0001\u0000\u0000\u0000\u0000"+
		"#\u0001\u0000\u0000\u0000\u0000%\u0001\u0000\u0000\u0000\u0000)\u0001"+
		"\u0000\u0000\u0000\u0000+\u0001\u0000\u0000\u0000\u0000-\u0001\u0000\u0000"+
		"\u0000\u0000/\u0001\u0000\u0000\u0000\u00001\u0001\u0000\u0000\u0000\u0000"+
		"3\u0001\u0000\u0000\u0000\u00005\u0001\u0000\u0000\u0000\u00007\u0001"+
		"\u0000\u0000\u0000\u00009\u0001\u0000\u0000\u0000\u0000;\u0001\u0000\u0000"+
		"\u0000\u0000=\u0001\u0000\u0000\u0000\u0000?\u0001\u0000\u0000\u0000\u0000"+
		"A\u0001\u0000\u0000\u0000\u0000C\u0001\u0000\u0000\u0000\u0000E\u0001"+
		"\u0000\u0000\u0000\u0000G\u0001\u0000\u0000\u0000\u0000I\u0001\u0000\u0000"+
		"\u0000\u0000K\u0001\u0000\u0000\u0000\u0000M\u0001\u0000\u0000\u0000\u0000"+
		"O\u0001\u0000\u0000\u0000\u0000Q\u0001\u0000\u0000\u0000\u0000S\u0001"+
		"\u0000\u0000\u0000\u0000U\u0001\u0000\u0000\u0000\u0000W\u0001\u0000\u0000"+
		"\u0000\u0000Y\u0001\u0000\u0000\u0000\u0000[\u0001\u0000\u0000\u0000\u0000"+
		"]\u0001\u0000\u0000\u0000\u0000_\u0001\u0000\u0000\u0000\u0000a\u0001"+
		"\u0000\u0000\u0000\u0000c\u0001\u0000\u0000\u0000\u0000e\u0001\u0000\u0000"+
		"\u0000\u0000g\u0001\u0000\u0000\u0000\u0000i\u0001\u0000\u0000\u0000\u0000"+
		"k\u0001\u0000\u0000\u0000\u0000m\u0001\u0000\u0000\u0000\u0000o\u0001"+
		"\u0000\u0000\u0000\u0000q\u0001\u0000\u0000\u0000\u0000s\u0001\u0000\u0000"+
		"\u0000\u0000u\u0001\u0000\u0000\u0000\u0000w\u0001\u0000\u0000\u0000\u0000"+
		"y\u0001\u0000\u0000\u0000\u0000{\u0001\u0000\u0000\u0000\u0001~\u0001"+
		"\u0000\u0000\u0000\u0003\u00b1\u0001\u0000\u0000\u0000\u0005\u00b5\u0001"+
		"\u0000\u0000\u0000\u0007\u00d1\u0001\u0000\u0000\u0000\t\u00d4\u0001\u0000"+
		"\u0000\u0000\u000b\u00d8\u0001\u0000\u0000\u0000\r\u00e2\u0001\u0000\u0000"+
		"\u0000\u000f\u00e7\u0001\u0000\u0000\u0000\u0011\u00ee\u0001\u0000\u0000"+
		"\u0000\u0013\u00f5\u0001\u0000\u0000\u0000\u0015\u00fd\u0001\u0000\u0000"+
		"\u0000\u0017\u0103\u0001\u0000\u0000\u0000\u0019\u0108\u0001\u0000\u0000"+
		"\u0000\u001b\u011e\u0001\u0000\u0000\u0000\u001d\u0120\u0001\u0000\u0000"+
		"\u0000\u001f\u0129\u0001\u0000\u0000\u0000!\u012c\u0001\u0000\u0000\u0000"+
		"#\u0130\u0001\u0000\u0000\u0000%\u0134\u0001\u0000\u0000\u0000\'\u0138"+
		"\u0001\u0000\u0000\u0000)\u0142\u0001\u0000\u0000\u0000+\u0145\u0001\u0000"+
		"\u0000\u0000-\u0148\u0001\u0000\u0000\u0000/\u014b\u0001\u0000\u0000\u0000"+
		"1\u014e\u0001\u0000\u0000\u00003\u0153\u0001\u0000\u0000\u00005\u0156"+
		"\u0001\u0000\u0000\u00007\u0159\u0001\u0000\u0000\u00009\u015c\u0001\u0000"+
		"\u0000\u0000;\u0161\u0001\u0000\u0000\u0000=\u0166\u0001\u0000\u0000\u0000"+
		"?\u016b\u0001\u0000\u0000\u0000A\u016e\u0001\u0000\u0000\u0000C\u0173"+
		"\u0001\u0000\u0000\u0000E\u0176\u0001\u0000\u0000\u0000G\u017a\u0001\u0000"+
		"\u0000\u0000I\u017d\u0001\u0000\u0000\u0000K\u0181\u0001\u0000\u0000\u0000"+
		"M\u0184\u0001\u0000\u0000\u0000O\u0187\u0001\u0000\u0000\u0000Q\u018c"+
		"\u0001\u0000\u0000\u0000S\u0191\u0001\u0000\u0000\u0000U\u0194\u0001\u0000"+
		"\u0000\u0000W\u0197\u0001\u0000\u0000\u0000Y\u019a\u0001\u0000\u0000\u0000"+
		"[\u019d\u0001\u0000\u0000\u0000]\u01a2\u0001\u0000\u0000\u0000_\u01a7"+
		"\u0001\u0000\u0000\u0000a\u01aa\u0001\u0000\u0000\u0000c\u01ad\u0001\u0000"+
		"\u0000\u0000e\u01b0\u0001\u0000\u0000\u0000g\u01b5\u0001\u0000\u0000\u0000"+
		"i\u01bb\u0001\u0000\u0000\u0000k\u01c0\u0001\u0000\u0000\u0000m\u01c5"+
		"\u0001\u0000\u0000\u0000o\u01cb\u0001\u0000\u0000\u0000q\u01d0\u0001\u0000"+
		"\u0000\u0000s\u01d5\u0001\u0000\u0000\u0000u\u01db\u0001\u0000\u0000\u0000"+
		"w\u01e0\u0001\u0000\u0000\u0000y\u01e4\u0001\u0000\u0000\u0000{\u01e9"+
		"\u0001\u0000\u0000\u0000}\u007f\u0007\u0000\u0000\u0000~}\u0001\u0000"+
		"\u0000\u0000\u007f\u0080\u0001\u0000\u0000\u0000\u0080~\u0001\u0000\u0000"+
		"\u0000\u0080\u0081\u0001\u0000\u0000\u0000\u0081\u0082\u0001\u0000\u0000"+
		"\u0000\u0082\u0083\u0006\u0000\u0000\u0000\u0083\u0002\u0001\u0000\u0000"+
		"\u0000\u0084\u0086\u0007\u0000\u0000\u0000\u0085\u0084\u0001\u0000\u0000"+
		"\u0000\u0086\u0089\u0001\u0000\u0000\u0000\u0087\u0085\u0001\u0000\u0000"+
		"\u0000\u0087\u0088\u0001\u0000\u0000\u0000\u0088\u008a\u0001\u0000\u0000"+
		"\u0000\u0089\u0087\u0001\u0000\u0000\u0000\u008a\u008c\u0005.\u0000\u0000"+
		"\u008b\u008d\u0007\u0000\u0000\u0000\u008c\u008b\u0001\u0000\u0000\u0000"+
		"\u008d\u008e\u0001\u0000\u0000\u0000\u008e\u008c\u0001\u0000\u0000\u0000"+
		"\u008e\u008f\u0001\u0000\u0000\u0000\u008f\u0097\u0001\u0000\u0000\u0000"+
		"\u0090\u0092\u0007\u0000\u0000\u0000\u0091\u0090\u0001\u0000\u0000\u0000"+
		"\u0092\u0093\u0001\u0000\u0000\u0000\u0093\u0091\u0001\u0000\u0000\u0000"+
		"\u0093\u0094\u0001\u0000\u0000\u0000\u0094\u0095\u0001\u0000\u0000\u0000"+
		"\u0095\u0097\u0005.\u0000\u0000\u0096\u0087\u0001\u0000\u0000\u0000\u0096"+
		"\u0091\u0001\u0000\u0000\u0000\u0097\u00a1\u0001\u0000\u0000\u0000\u0098"+
		"\u009a\u0007\u0001\u0000\u0000\u0099\u009b\u0007\u0002\u0000\u0000\u009a"+
		"\u0099\u0001\u0000\u0000\u0000\u009a\u009b\u0001\u0000\u0000\u0000\u009b"+
		"\u009d\u0001\u0000\u0000\u0000\u009c\u009e\u0007\u0000\u0000\u0000\u009d"+
		"\u009c\u0001\u0000\u0000\u0000\u009e\u009f\u0001\u0000\u0000\u0000\u009f"+
		"\u009d\u0001\u0000\u0000\u0000\u009f\u00a0\u0001\u0000\u0000\u0000\u00a0"+
		"\u00a2\u0001\u0000\u0000\u0000\u00a1\u0098\u0001\u0000\u0000\u0000\u00a1"+
		"\u00a2\u0001\u0000\u0000\u0000\u00a2\u00b2\u0001\u0000\u0000\u0000\u00a3"+
		"\u00a5\u0007\u0000\u0000\u0000\u00a4\u00a3\u0001\u0000\u0000\u0000\u00a5"+
		"\u00a6\u0001\u0000\u0000\u0000\u00a6\u00a4\u0001\u0000\u0000\u0000\u00a6"+
		"\u00a7\u0001\u0000\u0000\u0000\u00a7\u00a8\u0001\u0000\u0000\u0000\u00a8"+
		"\u00aa\u0007\u0001\u0000\u0000\u00a9\u00ab\u0007\u0002\u0000\u0000\u00aa"+
		"\u00a9\u0001\u0000\u0000\u0000\u00aa\u00ab\u0001\u0000\u0000\u0000\u00ab"+
		"\u00ad\u0001\u0000\u0000\u0000\u00ac\u00ae\u0007\u0000\u0000\u0000\u00ad"+
		"\u00ac\u0001\u0000\u0000\u0000\u00ae\u00af\u0001\u0000\u0000\u0000\u00af"+
		"\u00ad\u0001\u0000\u0000\u0000\u00af\u00b0\u0001\u0000\u0000\u0000\u00b0"+
		"\u00b2\u0001\u0000\u0000\u0000\u00b1\u0096\u0001\u0000\u0000\u0000\u00b1"+
		"\u00a4\u0001\u0000\u0000\u0000\u00b2\u00b3\u0001\u0000\u0000\u0000\u00b3"+
		"\u00b4\u0006\u0001\u0001\u0000\u00b4\u0004\u0001\u0000\u0000\u0000\u00b5"+
		"\u00b7\u0003\u0007\u0003\u0000\u00b6\u00b8\u0003\t\u0004\u0000\u00b7\u00b6"+
		"\u0001\u0000\u0000\u0000\u00b7\u00b8\u0001\u0000\u0000\u0000\u00b8\u00bc"+
		"\u0001\u0000\u0000\u0000\u00b9\u00bb\u0007\u0002\u0000\u0000\u00ba\u00b9"+
		"\u0001\u0000\u0000\u0000\u00bb\u00be\u0001\u0000\u0000\u0000\u00bc\u00ba"+
		"\u0001\u0000\u0000\u0000\u00bc\u00bd\u0001\u0000\u0000\u0000\u00bd\u00bf"+
		"\u0001\u0000\u0000\u0000\u00be\u00bc\u0001\u0000\u0000\u0000\u00bf\u00cc"+
		"\u0003\u0001\u0000\u0000\u00c0\u00c2\u0007\u0002\u0000\u0000\u00c1\u00c0"+
		"\u0001\u0000\u0000\u0000\u00c2\u00c5\u0001\u0000\u0000\u0000\u00c3\u00c1"+
		"\u0001\u0000\u0000\u0000\u00c3\u00c4\u0001\u0000\u0000\u0000\u00c4\u00c8"+
		"\u0001\u0000\u0000\u0000\u00c5\u00c3\u0001\u0000\u0000\u0000\u00c6\u00c9"+
		"\u0003\u0001\u0000\u0000\u00c7\u00c9\u0003\u000b\u0005\u0000\u00c8\u00c6"+
		"\u0001\u0000\u0000\u0000\u00c8\u00c7\u0001\u0000\u0000\u0000\u00c9\u00ca"+
		"\u0001\u0000\u0000\u0000\u00ca\u00cb\u0005t\u0000\u0000\u00cb\u00cd\u0001"+
		"\u0000\u0000\u0000\u00cc\u00c3\u0001\u0000\u0000\u0000\u00cc\u00cd\u0001"+
		"\u0000\u0000\u0000\u00cd\u00ce\u0001\u0000\u0000\u0000\u00ce\u00cf\u0006"+
		"\u0002\u0002\u0000\u00cf\u0006\u0001\u0000\u0000\u0000\u00d0\u00d2\u0007"+
		"\u0003\u0000\u0000\u00d1\u00d0\u0001\u0000\u0000\u0000\u00d2\b\u0001\u0000"+
		"\u0000\u0000\u00d3\u00d5\u0007\u0004\u0000\u0000\u00d4\u00d3\u0001\u0000"+
		"\u0000\u0000\u00d5\u00d6\u0001\u0000\u0000\u0000\u00d6\u00d4\u0001\u0000"+
		"\u0000\u0000\u00d6\u00d7\u0001\u0000\u0000\u0000\u00d7\n\u0001\u0000\u0000"+
		"\u0000\u00d8\u00d9\u0003\u0001\u0000\u0000\u00d9\u00dd\u0005/\u0000\u0000"+
		"\u00da\u00dc\u0007\u0002\u0000\u0000\u00db\u00da\u0001\u0000\u0000\u0000"+
		"\u00dc\u00df\u0001\u0000\u0000\u0000\u00dd\u00db\u0001\u0000\u0000\u0000"+
		"\u00dd\u00de\u0001\u0000\u0000\u0000\u00de\u00e0\u0001\u0000\u0000\u0000"+
		"\u00df\u00dd\u0001\u0000\u0000\u0000\u00e0\u00e1\u0003\u0001\u0000\u0000"+
		"\u00e1\f\u0001\u0000\u0000\u0000\u00e2\u00e3\u0005i\u0000\u0000\u00e3"+
		"\u00e4\u0005f\u0000\u0000\u00e4\u00e5\u0001\u0000\u0000\u0000\u00e5\u00e6"+
		"\u0006\u0006\u0003\u0000\u00e6\u000e\u0001\u0000\u0000\u0000\u00e7\u00e8"+
		"\u0005t\u0000\u0000\u00e8\u00e9\u0005h\u0000\u0000\u00e9\u00ea\u0005e"+
		"\u0000\u0000\u00ea\u00eb\u0005n\u0000\u0000\u00eb\u00ec\u0001\u0000\u0000"+
		"\u0000\u00ec\u00ed\u0006\u0007\u0004\u0000\u00ed\u0010\u0001\u0000\u0000"+
		"\u0000\u00ee\u00ef\u0005e\u0000\u0000\u00ef\u00f0\u0005l\u0000\u0000\u00f0"+
		"\u00f1\u0005s\u0000\u0000\u00f1\u00f2\u0005e\u0000\u0000\u00f2\u00f3\u0001"+
		"\u0000\u0000\u0000\u00f3\u00f4\u0006\b\u0005\u0000\u00f4\u0012\u0001\u0000"+
		"\u0000\u0000\u00f5\u00f6\u0005w\u0000\u0000\u00f6\u00f7\u0005h\u0000\u0000"+
		"\u00f7\u00f8\u0005i\u0000\u0000\u00f8\u00f9\u0005l\u0000\u0000\u00f9\u00fa"+
		"\u0005e\u0000\u0000\u00fa\u00fb\u0001\u0000\u0000\u0000\u00fb\u00fc\u0006"+
		"\t\u0006\u0000\u00fc\u0014\u0001\u0000\u0000\u0000\u00fd\u00fe\u0005f"+
		"\u0000\u0000\u00fe\u00ff\u0005o\u0000\u0000\u00ff\u0100\u0005r\u0000\u0000"+
		"\u0100\u0101\u0001\u0000\u0000\u0000\u0101\u0102\u0006\n\u0007\u0000\u0102"+
		"\u0016\u0001\u0000\u0000\u0000\u0103\u0104\u0005d\u0000\u0000\u0104\u0105"+
		"\u0005o\u0000\u0000\u0105\u0106\u0001\u0000\u0000\u0000\u0106\u0107\u0006"+
		"\u000b\b\u0000\u0107\u0018\u0001\u0000\u0000\u0000\u0108\u0109\u0005c"+
		"\u0000\u0000\u0109\u010a\u0005o\u0000\u0000\u010a\u010b\u0005l\u0000\u0000"+
		"\u010b\u010c\u0005l\u0000\u0000\u010c\u010d\u0005e\u0000\u0000\u010d\u010e"+
		"\u0005c\u0000\u0000\u010e\u010f\u0005t\u0000\u0000\u010f\u0110\u0001\u0000"+
		"\u0000\u0000\u0110\u0111\u0006\f\t\u0000\u0111\u001a\u0001\u0000\u0000"+
		"\u0000\u0112\u0113\u0005s\u0000\u0000\u0113\u0114\u0005i\u0000\u0000\u0114"+
		"\u011f\u0005n\u0000\u0000\u0115\u0116\u0005c\u0000\u0000\u0116\u0117\u0005"+
		"o\u0000\u0000\u0117\u011f\u0005s\u0000\u0000\u0118\u0119\u0005s\u0000"+
		"\u0000\u0119\u011a\u0005q\u0000\u0000\u011a\u011b\u0005r\u0000\u0000\u011b"+
		"\u011c\u0005t\u0000\u0000\u011c\u011d\u0001\u0000\u0000\u0000\u011d\u011f"+
		"\u0006\r\n\u0000\u011e\u0112\u0001\u0000\u0000\u0000\u011e\u0115\u0001"+
		"\u0000\u0000\u0000\u011e\u0118\u0001\u0000\u0000\u0000\u011f\u001c\u0001"+
		"\u0000\u0000\u0000\u0120\u0121\u0005$\u0000\u0000\u0121\u0123\u0007\u0005"+
		"\u0000\u0000\u0122\u0124\u0007\u0000\u0000\u0000\u0123\u0122\u0001\u0000"+
		"\u0000\u0000\u0124\u0125\u0001\u0000\u0000\u0000\u0125\u0123\u0001\u0000"+
		"\u0000\u0000\u0125\u0126\u0001\u0000\u0000\u0000\u0126\u0127\u0001\u0000"+
		"\u0000\u0000\u0127\u0128\u0006\u000e\u000b\u0000\u0128\u001e\u0001\u0000"+
		"\u0000\u0000\u0129\u012a\u0003\'\u0013\u0000\u012a\u012b\u0006\u000f\f"+
		"\u0000\u012b \u0001\u0000\u0000\u0000\u012c\u012d\u0005#\u0000\u0000\u012d"+
		"\u012e\u0003\'\u0013\u0000\u012e\u012f\u0006\u0010\r\u0000\u012f\"\u0001"+
		"\u0000\u0000\u0000\u0130\u0131\u0005$\u0000\u0000\u0131\u0132\u0003\'"+
		"\u0013\u0000\u0132\u0133\u0006\u0011\u000e\u0000\u0133$\u0001\u0000\u0000"+
		"\u0000\u0134\u0135\u0005@\u0000\u0000\u0135\u0136\u0003\'\u0013\u0000"+
		"\u0136\u0137\u0006\u0012\u000f\u0000\u0137&\u0001\u0000\u0000\u0000\u0138"+
		"\u0140\u0007\u0006\u0000\u0000\u0139\u013b\u0007\u0007\u0000\u0000\u013a"+
		"\u0139\u0001\u0000\u0000\u0000\u013b\u013e\u0001\u0000\u0000\u0000\u013c"+
		"\u013a\u0001\u0000\u0000\u0000\u013c\u013d\u0001\u0000\u0000\u0000\u013d"+
		"\u013f\u0001\u0000\u0000\u0000\u013e\u013c\u0001\u0000\u0000\u0000\u013f"+
		"\u0141\u0007\b\u0000\u0000\u0140\u013c\u0001\u0000\u0000\u0000\u0140\u0141"+
		"\u0001\u0000\u0000\u0000\u0141(\u0001\u0000\u0000\u0000\u0142\u0143\u0005"+
		"[\u0000\u0000\u0143\u0144\u0006\u0014\u0010\u0000\u0144*\u0001\u0000\u0000"+
		"\u0000\u0145\u0146\u0005]\u0000\u0000\u0146\u0147\u0006\u0015\u0011\u0000"+
		"\u0147,\u0001\u0000\u0000\u0000\u0148\u0149\u0005)\u0000\u0000\u0149\u014a"+
		"\u0006\u0016\u0012\u0000\u014a.\u0001\u0000\u0000\u0000\u014b\u014c\u0005"+
		":\u0000\u0000\u014c\u014d\u0006\u0017\u0013\u0000\u014d0\u0001\u0000\u0000"+
		"\u0000\u014e\u014f\u0005:\u0000\u0000\u014f\u0150\u0005:\u0000\u0000\u0150"+
		"\u0151\u0001\u0000\u0000\u0000\u0151\u0152\u0006\u0018\u0014\u0000\u0152"+
		"2\u0001\u0000\u0000\u0000\u0153\u0154\u0005.\u0000\u0000\u0154\u0155\u0006"+
		"\u0019\u0015\u0000\u01554\u0001\u0000\u0000\u0000\u0156\u0157\u0005;\u0000"+
		"\u0000\u0157\u0158\u0006\u001a\u0016\u0000\u01586\u0001\u0000\u0000\u0000"+
		"\u0159\u015a\u0005=\u0000\u0000\u015a\u015b\u0006\u001b\u0017\u0000\u015b"+
		"8\u0001\u0000\u0000\u0000\u015c\u015d\u0007\t\u0000\u0000\u015d\u015e"+
		"\u0006\u001c\u0018\u0000\u015e\u015f\u0001\u0000\u0000\u0000\u015f\u0160"+
		"\u0006\u001c\u0019\u0000\u0160:\u0001\u0000\u0000\u0000\u0161\u0162\u0007"+
		"\n\u0000\u0000\u0162\u0163\u0006\u001d\u001a\u0000\u0163\u0164\u0001\u0000"+
		"\u0000\u0000\u0164\u0165\u0006\u001d\u0019\u0000\u0165<\u0001\u0000\u0000"+
		"\u0000\u0166\u0167\u0005*\u0000\u0000\u0167\u0168\u0005*\u0000\u0000\u0168"+
		"\u0169\u0001\u0000\u0000\u0000\u0169\u016a\u0006\u001e\u001b\u0000\u016a"+
		">\u0001\u0000\u0000\u0000\u016b\u016c\u0005*\u0000\u0000\u016c\u016d\u0006"+
		"\u001f\u001c\u0000\u016d@\u0001\u0000\u0000\u0000\u016e\u016f\u0005/\u0000"+
		"\u0000\u016f\u0170\u0005/\u0000\u0000\u0170\u0171\u0001\u0000\u0000\u0000"+
		"\u0171\u0172\u0006 \u001d\u0000\u0172B\u0001\u0000\u0000\u0000\u0173\u0174"+
		"\u0005/\u0000\u0000\u0174\u0175\u0006!\u001e\u0000\u0175D\u0001\u0000"+
		"\u0000\u0000\u0176\u0177\u0004\"\u0000\u0000\u0177\u0178\u0005+\u0000"+
		"\u0000\u0178\u0179\u0006\"\u001f\u0000\u0179F\u0001\u0000\u0000\u0000"+
		"\u017a\u017b\u0005+\u0000\u0000\u017b\u017c\u0006# \u0000\u017cH\u0001"+
		"\u0000\u0000\u0000\u017d\u017e\u0004$\u0001\u0000\u017e\u017f\u0005-\u0000"+
		"\u0000\u017f\u0180\u0006$!\u0000\u0180J\u0001\u0000\u0000\u0000\u0181"+
		"\u0182\u0005-\u0000\u0000\u0182\u0183\u0006%\"\u0000\u0183L\u0001\u0000"+
		"\u0000\u0000\u0184\u0185\u0005%\u0000\u0000\u0185\u0186\u0006&#\u0000"+
		"\u0186N\u0001\u0000\u0000\u0000\u0187\u0188\u0005=\u0000\u0000\u0188\u0189"+
		"\u0005=\u0000\u0000\u0189\u018a\u0001\u0000\u0000\u0000\u018a\u018b\u0006"+
		"\'$\u0000\u018bP\u0001\u0000\u0000\u0000\u018c\u018d\u0005!\u0000\u0000"+
		"\u018d\u018e\u0005=\u0000\u0000\u018e\u018f\u0001\u0000\u0000\u0000\u018f"+
		"\u0190\u0006(%\u0000\u0190R\u0001\u0000\u0000\u0000\u0191\u0192\u0005"+
		"!\u0000\u0000\u0192\u0193\u0006)&\u0000\u0193T\u0001\u0000\u0000\u0000"+
		"\u0194\u0195\u0005~\u0000\u0000\u0195\u0196\u0006*\'\u0000\u0196V\u0001"+
		"\u0000\u0000\u0000\u0197\u0198\u0005<\u0000\u0000\u0198\u0199\u0006+("+
		"\u0000\u0199X\u0001\u0000\u0000\u0000\u019a\u019b\u0005>\u0000\u0000\u019b"+
		"\u019c\u0006,)\u0000\u019cZ\u0001\u0000\u0000\u0000\u019d\u019e\u0005"+
		"<\u0000\u0000\u019e\u019f\u0005=\u0000\u0000\u019f\u01a0\u0001\u0000\u0000"+
		"\u0000\u01a0\u01a1\u0006-*\u0000\u01a1\\\u0001\u0000\u0000\u0000\u01a2"+
		"\u01a3\u0005>\u0000\u0000\u01a3\u01a4\u0005=\u0000\u0000\u01a4\u01a5\u0001"+
		"\u0000\u0000\u0000\u01a5\u01a6\u0006.+\u0000\u01a6^\u0001\u0000\u0000"+
		"\u0000\u01a7\u01a8\u0005&\u0000\u0000\u01a8\u01a9\u0006/,\u0000\u01a9"+
		"`\u0001\u0000\u0000\u0000\u01aa\u01ab\u0005^\u0000\u0000\u01ab\u01ac\u0006"+
		"0-\u0000\u01acb\u0001\u0000\u0000\u0000\u01ad\u01ae\u0005|\u0000\u0000"+
		"\u01ae\u01af\u00061.\u0000\u01afd\u0001\u0000\u0000\u0000\u01b0\u01b1"+
		"\u0005&\u0000\u0000\u01b1\u01b2\u0005&\u0000\u0000\u01b2\u01b3\u0001\u0000"+
		"\u0000\u0000\u01b3\u01b4\u00062/\u0000\u01b4f\u0001\u0000\u0000\u0000"+
		"\u01b5\u01b6\u0005&\u0000\u0000\u01b6\u01b7\u0005&\u0000\u0000\u01b7\u01b8"+
		"\u0005&\u0000\u0000\u01b8\u01b9\u0001\u0000\u0000\u0000\u01b9\u01ba\u0006"+
		"30\u0000\u01bah\u0001\u0000\u0000\u0000\u01bb\u01bc\u0005^\u0000\u0000"+
		"\u01bc\u01bd\u0005^\u0000\u0000\u01bd\u01be\u0001\u0000\u0000\u0000\u01be"+
		"\u01bf\u000641\u0000\u01bfj\u0001\u0000\u0000\u0000\u01c0\u01c1\u0005"+
		"|\u0000\u0000\u01c1\u01c2\u0005|\u0000\u0000\u01c2\u01c3\u0001\u0000\u0000"+
		"\u0000\u01c3\u01c4\u000652\u0000\u01c4l\u0001\u0000\u0000\u0000\u01c5"+
		"\u01c6\u0005|\u0000\u0000\u01c6\u01c7\u0005|\u0000\u0000\u01c7\u01c8\u0005"+
		"|\u0000\u0000\u01c8\u01c9\u0001\u0000\u0000\u0000\u01c9\u01ca\u000663"+
		"\u0000\u01can\u0001\u0000\u0000\u0000\u01cb\u01cc\u0005<\u0000\u0000\u01cc"+
		"\u01cd\u0005<\u0000\u0000\u01cd\u01ce\u0001\u0000\u0000\u0000\u01ce\u01cf"+
		"\u000674\u0000\u01cfp\u0001\u0000\u0000\u0000\u01d0\u01d1\u0005>\u0000"+
		"\u0000\u01d1\u01d2\u0005>\u0000\u0000\u01d2\u01d3\u0001\u0000\u0000\u0000"+
		"\u01d3\u01d4\u000685\u0000\u01d4r\u0001\u0000\u0000\u0000\u01d5\u01d6"+
		"\u0005.\u0000\u0000\u01d6\u01d7\u0005.\u0000\u0000\u01d7\u01d8\u0005."+
		"\u0000\u0000\u01d8\u01d9\u0001\u0000\u0000\u0000\u01d9\u01da\u000696\u0000"+
		"\u01dat\u0001\u0000\u0000\u0000\u01db\u01dc\u0005:\u0000\u0000\u01dc\u01dd"+
		"\u0005*\u0000\u0000\u01dd\u01de\u0001\u0000\u0000\u0000\u01de\u01df\u0006"+
		":7\u0000\u01dfv\u0001\u0000\u0000\u0000\u01e0\u01e1\u0004;\u0002\u0000"+
		"\u01e1\u01e2\u0005(\u0000\u0000\u01e2\u01e3\u0006;8\u0000\u01e3x\u0001"+
		"\u0000\u0000\u0000\u01e4\u01e5\u0004<\u0003\u0000\u01e5\u01e6\u0005(\u0000"+
		"\u0000\u01e6\u01e7\u0006<9\u0000\u01e7z\u0001\u0000\u0000\u0000\u01e8"+
		"\u01ea\t\u0000\u0000\u0000\u01e9\u01e8\u0001\u0000\u0000\u0000\u01ea\u01eb"+
		"\u0001\u0000\u0000\u0000\u01eb\u01ec\u0001\u0000\u0000\u0000\u01eb\u01e9"+
		"\u0001\u0000\u0000\u0000\u01ec|\u0001\u0000\u0000\u0000\u001a\u0000\u0080"+
		"\u0087\u008e\u0093\u0096\u009a\u009f\u00a1\u00a6\u00aa\u00af\u00b1\u00b7"+
		"\u00bc\u00c3\u00c8\u00cc\u00d1\u00d6\u00dd\u011e\u0125\u013c\u0140\u01eb"+
		":\u0001\u0000\u0000\u0001\u0001\u0001\u0001\u0002\u0002\u0001\u0006\u0003"+
		"\u0001\u0007\u0004\u0001\b\u0005\u0001\t\u0006\u0001\n\u0007\u0001\u000b"+
		"\b\u0001\f\t\u0001\r\n\u0001\u000e\u000b\u0001\u000f\f\u0001\u0010\r\u0001"+
		"\u0011\u000e\u0001\u0012\u000f\u0001\u0014\u0010\u0001\u0015\u0011\u0001"+
		"\u0016\u0012\u0001\u0017\u0013\u0001\u0018\u0014\u0001\u0019\u0015\u0001"+
		"\u001a\u0016\u0001\u001b\u0017\u0001\u001c\u0018\u0000\u0001\u0000\u0001"+
		"\u001d\u0019\u0001\u001e\u001a\u0001\u001f\u001b\u0001 \u001c\u0001!\u001d"+
		"\u0001\"\u001e\u0001#\u001f\u0001$ \u0001%!\u0001&\"\u0001\'#\u0001($"+
		"\u0001)%\u0001*&\u0001+\'\u0001,(\u0001-)\u0001.*\u0001/+\u00010,\u0001"+
		"1-\u00012.\u00013/\u000140\u000151\u000162\u000173\u000184\u000195\u0001"+
		":6\u0001;7\u0001<8";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}