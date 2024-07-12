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
		UINT=1, UFLOAT=2, UPITCH=3, IF=4, THEN=5, ELSE=6, FOR=7, DO=8, FUNCTION=9, 
		INLET=10, GLOBALVAR=11, PATCHERVAR=12, LOCALVAR=13, PUSH=14, POP=15, CLOSED=16, 
		NTH=17, KEY=18, NULLIFY=19, ASSIGN=20, EOL=21, WHITESPACE=22, POW=23, 
		TIMES=24, DIVDIV=25, DIV=26, PLUS=27, UPLUS=28, MINUS=29, UMINUS=30, OPEN=31, 
		PARAMS=32;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"UINT", "UFLOAT", "UPITCH", "NOTENAME", "ACCIDENTAL", "RAT", "IF", "THEN", 
			"ELSE", "FOR", "DO", "FUNCTION", "INLET", "GLOBALVAR", "PATCHERVAR", 
			"LOCALVAR", "PUSH", "POP", "CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", 
			"EOL", "WHITESPACE", "POW", "TIMES", "DIVDIV", "DIV", "PLUS", "UPLUS", 
			"MINUS", "UMINUS", "OPEN", "PARAMS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, "'if'", "'then'", "'else'", "'for'", "'do'", 
			null, null, null, null, null, "'['", "']'", "')'", "':'", "'.'", "';'", 
			"'='", "'\\n'", null, "'**'", "'*'", "'//'", "'/'", null, "'+'", null, 
			"'-'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "UINT", "UFLOAT", "UPITCH", "IF", "THEN", "ELSE", "FOR", "DO", 
			"FUNCTION", "INLET", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "PUSH", "POP", 
			"CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", "POW", 
			"TIMES", "DIVDIV", "DIV", "PLUS", "UPLUS", "MINUS", "UMINUS", "OPEN", 
			"PARAMS"
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
	        post("noUnary %d\n", noUnary);
	        post("fbs %d\n", followedBySpace());
	        return noUnary || followedBySpace();
	    }

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
			FOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 10:
			DO_action((RuleContext)_localctx, actionIndex);
			break;
		case 11:
			FUNCTION_action((RuleContext)_localctx, actionIndex);
			break;
		case 12:
			INLET_action((RuleContext)_localctx, actionIndex);
			break;
		case 13:
			GLOBALVAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 14:
			PATCHERVAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 15:
			LOCALVAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 16:
			PUSH_action((RuleContext)_localctx, actionIndex);
			break;
		case 17:
			POP_action((RuleContext)_localctx, actionIndex);
			break;
		case 18:
			CLOSED_action((RuleContext)_localctx, actionIndex);
			break;
		case 19:
			NTH_action((RuleContext)_localctx, actionIndex);
			break;
		case 20:
			KEY_action((RuleContext)_localctx, actionIndex);
			break;
		case 21:
			NULLIFY_action((RuleContext)_localctx, actionIndex);
			break;
		case 22:
			ASSIGN_action((RuleContext)_localctx, actionIndex);
			break;
		case 23:
			EOL_action((RuleContext)_localctx, actionIndex);
			break;
		case 24:
			WHITESPACE_action((RuleContext)_localctx, actionIndex);
			break;
		case 25:
			POW_action((RuleContext)_localctx, actionIndex);
			break;
		case 26:
			TIMES_action((RuleContext)_localctx, actionIndex);
			break;
		case 27:
			DIVDIV_action((RuleContext)_localctx, actionIndex);
			break;
		case 28:
			DIV_action((RuleContext)_localctx, actionIndex);
			break;
		case 29:
			PLUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 30:
			UPLUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 31:
			MINUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 32:
			UMINUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 33:
			OPEN_action((RuleContext)_localctx, actionIndex);
			break;
		case 34:
			PARAMS_action((RuleContext)_localctx, actionIndex);
			break;
		}
	}
	private void UINT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 0:
			 std::cout << "UINT\n"; noParams = false; noUnary = true; 
			break;
		}
	}
	private void UFLOAT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 1:
			 std::cout << "UFLOAT\n"; noParams = false; noUnary = true; 
			break;
		}
	}
	private void UPITCH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 2:
			 std::cout << "PITCH\n"; noParams = false; noUnary = true; 
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
	private void FOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 6:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DO_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 7:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void FUNCTION_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 8:
			 noParams = noUnary = false; 
			break;
		}
	}
	private void INLET_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 9:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void GLOBALVAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 10:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void PATCHERVAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 11:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void LOCALVAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 12:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void PUSH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 13:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void POP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 14:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void CLOSED_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 15:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void NTH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 16:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void KEY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 17:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void NULLIFY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 18:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ASSIGN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 19:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void EOL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 20:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void WHITESPACE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 21:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void POW_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 22:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void TIMES_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 23:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DIVDIV_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 24:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DIV_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 25:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PLUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 26:
			 post("plus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void UPLUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 27:
			 post("uplus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void MINUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 28:
			 post("minus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void UMINUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 29:
			 post("uminus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void OPEN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 30:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PARAMS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 31:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	@Override
	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 29:
			return PLUS_sempred((RuleContext)_localctx, predIndex);
		case 31:
			return MINUS_sempred((RuleContext)_localctx, predIndex);
		case 33:
			return OPEN_sempred((RuleContext)_localctx, predIndex);
		case 34:
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
		"\u0004\u0000 \u014a\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
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
		"!\u0002\"\u0007\"\u0001\u0000\u0004\u0000I\b\u0000\u000b\u0000\f\u0000"+
		"J\u0001\u0000\u0001\u0000\u0001\u0001\u0005\u0001P\b\u0001\n\u0001\f\u0001"+
		"S\t\u0001\u0001\u0001\u0001\u0001\u0004\u0001W\b\u0001\u000b\u0001\f\u0001"+
		"X\u0001\u0001\u0004\u0001\\\b\u0001\u000b\u0001\f\u0001]\u0001\u0001\u0003"+
		"\u0001a\b\u0001\u0001\u0001\u0001\u0001\u0003\u0001e\b\u0001\u0001\u0001"+
		"\u0004\u0001h\b\u0001\u000b\u0001\f\u0001i\u0003\u0001l\b\u0001\u0001"+
		"\u0001\u0004\u0001o\b\u0001\u000b\u0001\f\u0001p\u0001\u0001\u0001\u0001"+
		"\u0003\u0001u\b\u0001\u0001\u0001\u0004\u0001x\b\u0001\u000b\u0001\f\u0001"+
		"y\u0003\u0001|\b\u0001\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002"+
		"\u0003\u0002\u0082\b\u0002\u0001\u0002\u0005\u0002\u0085\b\u0002\n\u0002"+
		"\f\u0002\u0088\t\u0002\u0001\u0002\u0001\u0002\u0005\u0002\u008c\b\u0002"+
		"\n\u0002\f\u0002\u008f\t\u0002\u0001\u0002\u0001\u0002\u0003\u0002\u0093"+
		"\b\u0002\u0001\u0002\u0001\u0002\u0003\u0002\u0097\b\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0003\u0003\u0003\u009c\b\u0003\u0001\u0004\u0004\u0004"+
		"\u009f\b\u0004\u000b\u0004\f\u0004\u00a0\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0005\u0005\u00a6\b\u0005\n\u0005\f\u0005\u00a9\t\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0003\u000b\u00d7\b\u000b\u0001\f\u0001\f\u0001\f\u0004\f"+
		"\u00dc\b\f\u000b\f\f\f\u00dd\u0001\f\u0001\f\u0001\r\u0001\r\u0005\r\u00e4"+
		"\b\r\n\r\f\r\u00e7\t\r\u0001\r\u0003\r\u00ea\b\r\u0001\r\u0001\r\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0005\u000e\u00f1\b\u000e\n\u000e\f\u000e"+
		"\u00f4\t\u000e\u0001\u000e\u0003\u000e\u00f7\b\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000f\u0001\u000f\u0001\u000f\u0005\u000f\u00fe\b\u000f\n"+
		"\u000f\f\u000f\u0101\t\u000f\u0001\u000f\u0003\u000f\u0104\b\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0017\u0001"+
		"\u0017\u0001\u0017\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001"+
		"\u0018\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001"+
		"\u001a\u0001\u001a\u0001\u001a\u0001\u001b\u0001\u001b\u0001\u001b\u0001"+
		"\u001b\u0001\u001b\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001d\u0001"+
		"\u001d\u0001\u001d\u0001\u001d\u0001\u001e\u0001\u001e\u0001\u001e\u0001"+
		"\u001f\u0001\u001f\u0001\u001f\u0001\u001f\u0001 \u0001 \u0001 \u0001"+
		"!\u0001!\u0001!\u0001!\u0001\"\u0001\"\u0001\"\u0001\"\u0000\u0000#\u0001"+
		"\u0001\u0003\u0002\u0005\u0003\u0007\u0000\t\u0000\u000b\u0000\r\u0004"+
		"\u000f\u0005\u0011\u0006\u0013\u0007\u0015\b\u0017\t\u0019\n\u001b\u000b"+
		"\u001d\f\u001f\r!\u000e#\u000f%\u0010\'\u0011)\u0012+\u0013-\u0014/\u0015"+
		"1\u00163\u00175\u00187\u00199\u001a;\u001b=\u001c?\u001dA\u001eC\u001f"+
		"E \u0001\u0000\n\u0001\u000009\u0002\u0000EEee\u0002\u0000++--\u0002\u0000"+
		"AGag\u0007\u0000##^^bbddqqvvxx\u0002\u0000llxx\u0002\u0000AZaz\u0004\u0000"+
		"09AZ__az\u0003\u000009AZaz\u0003\u0000\u0001\u0001\t\t  \u0162\u0000\u0001"+
		"\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000\u0000\u0005"+
		"\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001"+
		"\u0000\u0000\u0000\u0000\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001"+
		"\u0000\u0000\u0000\u0000\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001"+
		"\u0000\u0000\u0000\u0000\u0019\u0001\u0000\u0000\u0000\u0000\u001b\u0001"+
		"\u0000\u0000\u0000\u0000\u001d\u0001\u0000\u0000\u0000\u0000\u001f\u0001"+
		"\u0000\u0000\u0000\u0000!\u0001\u0000\u0000\u0000\u0000#\u0001\u0000\u0000"+
		"\u0000\u0000%\u0001\u0000\u0000\u0000\u0000\'\u0001\u0000\u0000\u0000"+
		"\u0000)\u0001\u0000\u0000\u0000\u0000+\u0001\u0000\u0000\u0000\u0000-"+
		"\u0001\u0000\u0000\u0000\u0000/\u0001\u0000\u0000\u0000\u00001\u0001\u0000"+
		"\u0000\u0000\u00003\u0001\u0000\u0000\u0000\u00005\u0001\u0000\u0000\u0000"+
		"\u00007\u0001\u0000\u0000\u0000\u00009\u0001\u0000\u0000\u0000\u0000;"+
		"\u0001\u0000\u0000\u0000\u0000=\u0001\u0000\u0000\u0000\u0000?\u0001\u0000"+
		"\u0000\u0000\u0000A\u0001\u0000\u0000\u0000\u0000C\u0001\u0000\u0000\u0000"+
		"\u0000E\u0001\u0000\u0000\u0000\u0001H\u0001\u0000\u0000\u0000\u0003{"+
		"\u0001\u0000\u0000\u0000\u0005\u007f\u0001\u0000\u0000\u0000\u0007\u009b"+
		"\u0001\u0000\u0000\u0000\t\u009e\u0001\u0000\u0000\u0000\u000b\u00a2\u0001"+
		"\u0000\u0000\u0000\r\u00ac\u0001\u0000\u0000\u0000\u000f\u00b1\u0001\u0000"+
		"\u0000\u0000\u0011\u00b8\u0001\u0000\u0000\u0000\u0013\u00bf\u0001\u0000"+
		"\u0000\u0000\u0015\u00c5\u0001\u0000\u0000\u0000\u0017\u00d6\u0001\u0000"+
		"\u0000\u0000\u0019\u00d8\u0001\u0000\u0000\u0000\u001b\u00e1\u0001\u0000"+
		"\u0000\u0000\u001d\u00ed\u0001\u0000\u0000\u0000\u001f\u00fa\u0001\u0000"+
		"\u0000\u0000!\u0107\u0001\u0000\u0000\u0000#\u010a\u0001\u0000\u0000\u0000"+
		"%\u010d\u0001\u0000\u0000\u0000\'\u0110\u0001\u0000\u0000\u0000)\u0113"+
		"\u0001\u0000\u0000\u0000+\u0116\u0001\u0000\u0000\u0000-\u0119\u0001\u0000"+
		"\u0000\u0000/\u011c\u0001\u0000\u0000\u00001\u011f\u0001\u0000\u0000\u0000"+
		"3\u0124\u0001\u0000\u0000\u00005\u0129\u0001\u0000\u0000\u00007\u012c"+
		"\u0001\u0000\u0000\u00009\u0131\u0001\u0000\u0000\u0000;\u0134\u0001\u0000"+
		"\u0000\u0000=\u0138\u0001\u0000\u0000\u0000?\u013b\u0001\u0000\u0000\u0000"+
		"A\u013f\u0001\u0000\u0000\u0000C\u0142\u0001\u0000\u0000\u0000E\u0146"+
		"\u0001\u0000\u0000\u0000GI\u0007\u0000\u0000\u0000HG\u0001\u0000\u0000"+
		"\u0000IJ\u0001\u0000\u0000\u0000JH\u0001\u0000\u0000\u0000JK\u0001\u0000"+
		"\u0000\u0000KL\u0001\u0000\u0000\u0000LM\u0006\u0000\u0000\u0000M\u0002"+
		"\u0001\u0000\u0000\u0000NP\u0007\u0000\u0000\u0000ON\u0001\u0000\u0000"+
		"\u0000PS\u0001\u0000\u0000\u0000QO\u0001\u0000\u0000\u0000QR\u0001\u0000"+
		"\u0000\u0000RT\u0001\u0000\u0000\u0000SQ\u0001\u0000\u0000\u0000TV\u0005"+
		".\u0000\u0000UW\u0007\u0000\u0000\u0000VU\u0001\u0000\u0000\u0000WX\u0001"+
		"\u0000\u0000\u0000XV\u0001\u0000\u0000\u0000XY\u0001\u0000\u0000\u0000"+
		"Ya\u0001\u0000\u0000\u0000Z\\\u0007\u0000\u0000\u0000[Z\u0001\u0000\u0000"+
		"\u0000\\]\u0001\u0000\u0000\u0000][\u0001\u0000\u0000\u0000]^\u0001\u0000"+
		"\u0000\u0000^_\u0001\u0000\u0000\u0000_a\u0005.\u0000\u0000`Q\u0001\u0000"+
		"\u0000\u0000`[\u0001\u0000\u0000\u0000ak\u0001\u0000\u0000\u0000bd\u0007"+
		"\u0001\u0000\u0000ce\u0007\u0002\u0000\u0000dc\u0001\u0000\u0000\u0000"+
		"de\u0001\u0000\u0000\u0000eg\u0001\u0000\u0000\u0000fh\u0007\u0000\u0000"+
		"\u0000gf\u0001\u0000\u0000\u0000hi\u0001\u0000\u0000\u0000ig\u0001\u0000"+
		"\u0000\u0000ij\u0001\u0000\u0000\u0000jl\u0001\u0000\u0000\u0000kb\u0001"+
		"\u0000\u0000\u0000kl\u0001\u0000\u0000\u0000l|\u0001\u0000\u0000\u0000"+
		"mo\u0007\u0000\u0000\u0000nm\u0001\u0000\u0000\u0000op\u0001\u0000\u0000"+
		"\u0000pn\u0001\u0000\u0000\u0000pq\u0001\u0000\u0000\u0000qr\u0001\u0000"+
		"\u0000\u0000rt\u0007\u0001\u0000\u0000su\u0007\u0002\u0000\u0000ts\u0001"+
		"\u0000\u0000\u0000tu\u0001\u0000\u0000\u0000uw\u0001\u0000\u0000\u0000"+
		"vx\u0007\u0000\u0000\u0000wv\u0001\u0000\u0000\u0000xy\u0001\u0000\u0000"+
		"\u0000yw\u0001\u0000\u0000\u0000yz\u0001\u0000\u0000\u0000z|\u0001\u0000"+
		"\u0000\u0000{`\u0001\u0000\u0000\u0000{n\u0001\u0000\u0000\u0000|}\u0001"+
		"\u0000\u0000\u0000}~\u0006\u0001\u0001\u0000~\u0004\u0001\u0000\u0000"+
		"\u0000\u007f\u0081\u0003\u0007\u0003\u0000\u0080\u0082\u0003\t\u0004\u0000"+
		"\u0081\u0080\u0001\u0000\u0000\u0000\u0081\u0082\u0001\u0000\u0000\u0000"+
		"\u0082\u0086\u0001\u0000\u0000\u0000\u0083\u0085\u0007\u0002\u0000\u0000"+
		"\u0084\u0083\u0001\u0000\u0000\u0000\u0085\u0088\u0001\u0000\u0000\u0000"+
		"\u0086\u0084\u0001\u0000\u0000\u0000\u0086\u0087\u0001\u0000\u0000\u0000"+
		"\u0087\u0089\u0001\u0000\u0000\u0000\u0088\u0086\u0001\u0000\u0000\u0000"+
		"\u0089\u0096\u0003\u0001\u0000\u0000\u008a\u008c\u0007\u0002\u0000\u0000"+
		"\u008b\u008a\u0001\u0000\u0000\u0000\u008c\u008f\u0001\u0000\u0000\u0000"+
		"\u008d\u008b\u0001\u0000\u0000\u0000\u008d\u008e\u0001\u0000\u0000\u0000"+
		"\u008e\u0092\u0001\u0000\u0000\u0000\u008f\u008d\u0001\u0000\u0000\u0000"+
		"\u0090\u0093\u0003\u0001\u0000\u0000\u0091\u0093\u0003\u000b\u0005\u0000"+
		"\u0092\u0090\u0001\u0000\u0000\u0000\u0092\u0091\u0001\u0000\u0000\u0000"+
		"\u0093\u0094\u0001\u0000\u0000\u0000\u0094\u0095\u0005t\u0000\u0000\u0095"+
		"\u0097\u0001\u0000\u0000\u0000\u0096\u008d\u0001\u0000\u0000\u0000\u0096"+
		"\u0097\u0001\u0000\u0000\u0000\u0097\u0098\u0001\u0000\u0000\u0000\u0098"+
		"\u0099\u0006\u0002\u0002\u0000\u0099\u0006\u0001\u0000\u0000\u0000\u009a"+
		"\u009c\u0007\u0003\u0000\u0000\u009b\u009a\u0001\u0000\u0000\u0000\u009c"+
		"\b\u0001\u0000\u0000\u0000\u009d\u009f\u0007\u0004\u0000\u0000\u009e\u009d"+
		"\u0001\u0000\u0000\u0000\u009f\u00a0\u0001\u0000\u0000\u0000\u00a0\u009e"+
		"\u0001\u0000\u0000\u0000\u00a0\u00a1\u0001\u0000\u0000\u0000\u00a1\n\u0001"+
		"\u0000\u0000\u0000\u00a2\u00a3\u0003\u0001\u0000\u0000\u00a3\u00a7\u0005"+
		"/\u0000\u0000\u00a4\u00a6\u0007\u0002\u0000\u0000\u00a5\u00a4\u0001\u0000"+
		"\u0000\u0000\u00a6\u00a9\u0001\u0000\u0000\u0000\u00a7\u00a5\u0001\u0000"+
		"\u0000\u0000\u00a7\u00a8\u0001\u0000\u0000\u0000\u00a8\u00aa\u0001\u0000"+
		"\u0000\u0000\u00a9\u00a7\u0001\u0000\u0000\u0000\u00aa\u00ab\u0003\u0001"+
		"\u0000\u0000\u00ab\f\u0001\u0000\u0000\u0000\u00ac\u00ad\u0005i\u0000"+
		"\u0000\u00ad\u00ae\u0005f\u0000\u0000\u00ae\u00af\u0001\u0000\u0000\u0000"+
		"\u00af\u00b0\u0006\u0006\u0003\u0000\u00b0\u000e\u0001\u0000\u0000\u0000"+
		"\u00b1\u00b2\u0005t\u0000\u0000\u00b2\u00b3\u0005h\u0000\u0000\u00b3\u00b4"+
		"\u0005e\u0000\u0000\u00b4\u00b5\u0005n\u0000\u0000\u00b5\u00b6\u0001\u0000"+
		"\u0000\u0000\u00b6\u00b7\u0006\u0007\u0004\u0000\u00b7\u0010\u0001\u0000"+
		"\u0000\u0000\u00b8\u00b9\u0005e\u0000\u0000\u00b9\u00ba\u0005l\u0000\u0000"+
		"\u00ba\u00bb\u0005s\u0000\u0000\u00bb\u00bc\u0005e\u0000\u0000\u00bc\u00bd"+
		"\u0001\u0000\u0000\u0000\u00bd\u00be\u0006\b\u0005\u0000\u00be\u0012\u0001"+
		"\u0000\u0000\u0000\u00bf\u00c0\u0005f\u0000\u0000\u00c0\u00c1\u0005o\u0000"+
		"\u0000\u00c1\u00c2\u0005r\u0000\u0000\u00c2\u00c3\u0001\u0000\u0000\u0000"+
		"\u00c3\u00c4\u0006\t\u0006\u0000\u00c4\u0014\u0001\u0000\u0000\u0000\u00c5"+
		"\u00c6\u0005d\u0000\u0000\u00c6\u00c7\u0005o\u0000\u0000\u00c7\u00c8\u0001"+
		"\u0000\u0000\u0000\u00c8\u00c9\u0006\n\u0007\u0000\u00c9\u0016\u0001\u0000"+
		"\u0000\u0000\u00ca\u00cb\u0005s\u0000\u0000\u00cb\u00cc\u0005i\u0000\u0000"+
		"\u00cc\u00d7\u0005n\u0000\u0000\u00cd\u00ce\u0005c\u0000\u0000\u00ce\u00cf"+
		"\u0005o\u0000\u0000\u00cf\u00d7\u0005s\u0000\u0000\u00d0\u00d1\u0005s"+
		"\u0000\u0000\u00d1\u00d2\u0005q\u0000\u0000\u00d2\u00d3\u0005r\u0000\u0000"+
		"\u00d3\u00d4\u0005t\u0000\u0000\u00d4\u00d5\u0001\u0000\u0000\u0000\u00d5"+
		"\u00d7\u0006\u000b\b\u0000\u00d6\u00ca\u0001\u0000\u0000\u0000\u00d6\u00cd"+
		"\u0001\u0000\u0000\u0000\u00d6\u00d0\u0001\u0000\u0000\u0000\u00d7\u0018"+
		"\u0001\u0000\u0000\u0000\u00d8\u00d9\u0005$\u0000\u0000\u00d9\u00db\u0007"+
		"\u0005\u0000\u0000\u00da\u00dc\u0007\u0000\u0000\u0000\u00db\u00da\u0001"+
		"\u0000\u0000\u0000\u00dc\u00dd\u0001\u0000\u0000\u0000\u00dd\u00db\u0001"+
		"\u0000\u0000\u0000\u00dd\u00de\u0001\u0000\u0000\u0000\u00de\u00df\u0001"+
		"\u0000\u0000\u0000\u00df\u00e0\u0006\f\t\u0000\u00e0\u001a\u0001\u0000"+
		"\u0000\u0000\u00e1\u00e9\u0007\u0006\u0000\u0000\u00e2\u00e4\u0007\u0007"+
		"\u0000\u0000\u00e3\u00e2\u0001\u0000\u0000\u0000\u00e4\u00e7\u0001\u0000"+
		"\u0000\u0000\u00e5\u00e3\u0001\u0000\u0000\u0000\u00e5\u00e6\u0001\u0000"+
		"\u0000\u0000\u00e6\u00e8\u0001\u0000\u0000\u0000\u00e7\u00e5\u0001\u0000"+
		"\u0000\u0000\u00e8\u00ea\u0007\b\u0000\u0000\u00e9\u00e5\u0001\u0000\u0000"+
		"\u0000\u00e9\u00ea\u0001\u0000\u0000\u0000\u00ea\u00eb\u0001\u0000\u0000"+
		"\u0000\u00eb\u00ec\u0006\r\n\u0000\u00ec\u001c\u0001\u0000\u0000\u0000"+
		"\u00ed\u00ee\u0005#\u0000\u0000\u00ee\u00f6\u0007\u0006\u0000\u0000\u00ef"+
		"\u00f1\u0007\u0007\u0000\u0000\u00f0\u00ef\u0001\u0000\u0000\u0000\u00f1"+
		"\u00f4\u0001\u0000\u0000\u0000\u00f2\u00f0\u0001\u0000\u0000\u0000\u00f2"+
		"\u00f3\u0001\u0000\u0000\u0000\u00f3\u00f5\u0001\u0000\u0000\u0000\u00f4"+
		"\u00f2\u0001\u0000\u0000\u0000\u00f5\u00f7\u0007\b\u0000\u0000\u00f6\u00f2"+
		"\u0001\u0000\u0000\u0000\u00f6\u00f7\u0001\u0000\u0000\u0000\u00f7\u00f8"+
		"\u0001\u0000\u0000\u0000\u00f8\u00f9\u0006\u000e\u000b\u0000\u00f9\u001e"+
		"\u0001\u0000\u0000\u0000\u00fa\u00fb\u0005$\u0000\u0000\u00fb\u0103\u0007"+
		"\u0006\u0000\u0000\u00fc\u00fe\u0007\u0007\u0000\u0000\u00fd\u00fc\u0001"+
		"\u0000\u0000\u0000\u00fe\u0101\u0001\u0000\u0000\u0000\u00ff\u00fd\u0001"+
		"\u0000\u0000\u0000\u00ff\u0100\u0001\u0000\u0000\u0000\u0100\u0102\u0001"+
		"\u0000\u0000\u0000\u0101\u00ff\u0001\u0000\u0000\u0000\u0102\u0104\u0007"+
		"\b\u0000\u0000\u0103\u00ff\u0001\u0000\u0000\u0000\u0103\u0104\u0001\u0000"+
		"\u0000\u0000\u0104\u0105\u0001\u0000\u0000\u0000\u0105\u0106\u0006\u000f"+
		"\f\u0000\u0106 \u0001\u0000\u0000\u0000\u0107\u0108\u0005[\u0000\u0000"+
		"\u0108\u0109\u0006\u0010\r\u0000\u0109\"\u0001\u0000\u0000\u0000\u010a"+
		"\u010b\u0005]\u0000\u0000\u010b\u010c\u0006\u0011\u000e\u0000\u010c$\u0001"+
		"\u0000\u0000\u0000\u010d\u010e\u0005)\u0000\u0000\u010e\u010f\u0006\u0012"+
		"\u000f\u0000\u010f&\u0001\u0000\u0000\u0000\u0110\u0111\u0005:\u0000\u0000"+
		"\u0111\u0112\u0006\u0013\u0010\u0000\u0112(\u0001\u0000\u0000\u0000\u0113"+
		"\u0114\u0005.\u0000\u0000\u0114\u0115\u0006\u0014\u0011\u0000\u0115*\u0001"+
		"\u0000\u0000\u0000\u0116\u0117\u0005;\u0000\u0000\u0117\u0118\u0006\u0015"+
		"\u0012\u0000\u0118,\u0001\u0000\u0000\u0000\u0119\u011a\u0005=\u0000\u0000"+
		"\u011a\u011b\u0006\u0016\u0013\u0000\u011b.\u0001\u0000\u0000\u0000\u011c"+
		"\u011d\u0005\n\u0000\u0000\u011d\u011e\u0006\u0017\u0014\u0000\u011e0"+
		"\u0001\u0000\u0000\u0000\u011f\u0120\u0007\t\u0000\u0000\u0120\u0121\u0006"+
		"\u0018\u0015\u0000\u0121\u0122\u0001\u0000\u0000\u0000\u0122\u0123\u0006"+
		"\u0018\u0016\u0000\u01232\u0001\u0000\u0000\u0000\u0124\u0125\u0005*\u0000"+
		"\u0000\u0125\u0126\u0005*\u0000\u0000\u0126\u0127\u0001\u0000\u0000\u0000"+
		"\u0127\u0128\u0006\u0019\u0017\u0000\u01284\u0001\u0000\u0000\u0000\u0129"+
		"\u012a\u0005*\u0000\u0000\u012a\u012b\u0006\u001a\u0018\u0000\u012b6\u0001"+
		"\u0000\u0000\u0000\u012c\u012d\u0005/\u0000\u0000\u012d\u012e\u0005/\u0000"+
		"\u0000\u012e\u012f\u0001\u0000\u0000\u0000\u012f\u0130\u0006\u001b\u0019"+
		"\u0000\u01308\u0001\u0000\u0000\u0000\u0131\u0132\u0005/\u0000\u0000\u0132"+
		"\u0133\u0006\u001c\u001a\u0000\u0133:\u0001\u0000\u0000\u0000\u0134\u0135"+
		"\u0004\u001d\u0000\u0000\u0135\u0136\u0005+\u0000\u0000\u0136\u0137\u0006"+
		"\u001d\u001b\u0000\u0137<\u0001\u0000\u0000\u0000\u0138\u0139\u0005+\u0000"+
		"\u0000\u0139\u013a\u0006\u001e\u001c\u0000\u013a>\u0001\u0000\u0000\u0000"+
		"\u013b\u013c\u0004\u001f\u0001\u0000\u013c\u013d\u0005-\u0000\u0000\u013d"+
		"\u013e\u0006\u001f\u001d\u0000\u013e@\u0001\u0000\u0000\u0000\u013f\u0140"+
		"\u0005-\u0000\u0000\u0140\u0141\u0006 \u001e\u0000\u0141B\u0001\u0000"+
		"\u0000\u0000\u0142\u0143\u0004!\u0002\u0000\u0143\u0144\u0005(\u0000\u0000"+
		"\u0144\u0145\u0006!\u001f\u0000\u0145D\u0001\u0000\u0000\u0000\u0146\u0147"+
		"\u0004\"\u0003\u0000\u0147\u0148\u0005(\u0000\u0000\u0148\u0149\u0006"+
		"\" \u0000\u0149F\u0001\u0000\u0000\u0000\u001d\u0000JQX]`dikpty{\u0081"+
		"\u0086\u008d\u0092\u0096\u009b\u00a0\u00a7\u00d6\u00dd\u00e5\u00e9\u00f2"+
		"\u00f6\u00ff\u0103!\u0001\u0000\u0000\u0001\u0001\u0001\u0001\u0002\u0002"+
		"\u0001\u0006\u0003\u0001\u0007\u0004\u0001\b\u0005\u0001\t\u0006\u0001"+
		"\n\u0007\u0001\u000b\b\u0001\f\t\u0001\r\n\u0001\u000e\u000b\u0001\u000f"+
		"\f\u0001\u0010\r\u0001\u0011\u000e\u0001\u0012\u000f\u0001\u0013\u0010"+
		"\u0001\u0014\u0011\u0001\u0015\u0012\u0001\u0016\u0013\u0001\u0017\u0014"+
		"\u0001\u0018\u0015\u0000\u0001\u0000\u0001\u0019\u0016\u0001\u001a\u0017"+
		"\u0001\u001b\u0018\u0001\u001c\u0019\u0001\u001d\u001a\u0001\u001e\u001b"+
		"\u0001\u001f\u001c\u0001 \u001d\u0001!\u001e\u0001\"\u001f";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}