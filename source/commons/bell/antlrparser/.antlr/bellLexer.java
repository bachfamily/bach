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
		UINT=1, UFLOAT=2, IF=3, THEN=4, ELSE=5, FOR=6, DO=7, FUNCTION=8, INLET=9, 
		GLOBALVAR=10, PATCHERVAR=11, LOCALVAR=12, PUSH=13, POP=14, CLOSED=15, 
		NTH=16, KEY=17, NULLIFY=18, ASSIGN=19, EOL=20, WHITESPACE=21, POW=22, 
		TIMES=23, DIVDIV=24, DIV=25, PLUS=26, UPLUS=27, MINUS=28, UMINUS=29, OPEN=30, 
		PARAMS=31;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"UINT", "UFLOAT", "IF", "THEN", "ELSE", "FOR", "DO", "FUNCTION", "INLET", 
			"GLOBALVAR", "PATCHERVAR", "LOCALVAR", "PUSH", "POP", "CLOSED", "NTH", 
			"KEY", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", "POW", "TIMES", "DIVDIV", 
			"DIV", "PLUS", "UPLUS", "MINUS", "UMINUS", "OPEN", "PARAMS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, "'if'", "'then'", "'else'", "'for'", "'do'", null, 
			null, null, null, null, "'['", "']'", "')'", "':'", "'.'", "';'", "'='", 
			"'\\n'", null, "'**'", "'*'", "'//'", "'/'", null, "'+'", null, "'-'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "UINT", "UFLOAT", "IF", "THEN", "ELSE", "FOR", "DO", "FUNCTION", 
			"INLET", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "PUSH", "POP", "CLOSED", 
			"NTH", "KEY", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", "POW", "TIMES", 
			"DIVDIV", "DIV", "PLUS", "UPLUS", "MINUS", "UMINUS", "OPEN", "PARAMS"
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
			IF_action((RuleContext)_localctx, actionIndex);
			break;
		case 3:
			THEN_action((RuleContext)_localctx, actionIndex);
			break;
		case 4:
			ELSE_action((RuleContext)_localctx, actionIndex);
			break;
		case 5:
			FOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 6:
			DO_action((RuleContext)_localctx, actionIndex);
			break;
		case 7:
			FUNCTION_action((RuleContext)_localctx, actionIndex);
			break;
		case 8:
			INLET_action((RuleContext)_localctx, actionIndex);
			break;
		case 9:
			GLOBALVAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 10:
			PATCHERVAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 11:
			LOCALVAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 12:
			PUSH_action((RuleContext)_localctx, actionIndex);
			break;
		case 13:
			POP_action((RuleContext)_localctx, actionIndex);
			break;
		case 14:
			CLOSED_action((RuleContext)_localctx, actionIndex);
			break;
		case 15:
			NTH_action((RuleContext)_localctx, actionIndex);
			break;
		case 16:
			KEY_action((RuleContext)_localctx, actionIndex);
			break;
		case 17:
			NULLIFY_action((RuleContext)_localctx, actionIndex);
			break;
		case 18:
			ASSIGN_action((RuleContext)_localctx, actionIndex);
			break;
		case 19:
			EOL_action((RuleContext)_localctx, actionIndex);
			break;
		case 20:
			WHITESPACE_action((RuleContext)_localctx, actionIndex);
			break;
		case 21:
			POW_action((RuleContext)_localctx, actionIndex);
			break;
		case 22:
			TIMES_action((RuleContext)_localctx, actionIndex);
			break;
		case 23:
			DIVDIV_action((RuleContext)_localctx, actionIndex);
			break;
		case 24:
			DIV_action((RuleContext)_localctx, actionIndex);
			break;
		case 25:
			PLUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 26:
			UPLUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 27:
			MINUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 28:
			UMINUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 29:
			OPEN_action((RuleContext)_localctx, actionIndex);
			break;
		case 30:
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
	private void IF_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 2:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void THEN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 3:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ELSE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 4:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void FOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 5:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DO_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 6:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void FUNCTION_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 7:
			 noParams = noUnary = false; 
			break;
		}
	}
	private void INLET_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 8:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void GLOBALVAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 9:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void PATCHERVAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 10:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void LOCALVAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 11:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void PUSH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 12:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void POP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 13:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void CLOSED_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 14:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void NTH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 15:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void KEY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 16:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void NULLIFY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 17:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ASSIGN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 18:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void EOL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 19:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void WHITESPACE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 20:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void POW_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 21:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void TIMES_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 22:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DIVDIV_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 23:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DIV_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 24:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PLUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 25:
			 post("plus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void UPLUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 26:
			 post("uplus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void MINUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 27:
			 post("minus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void UMINUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 28:
			 post("uminus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void OPEN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 29:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PARAMS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 30:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	@Override
	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 25:
			return PLUS_sempred((RuleContext)_localctx, predIndex);
		case 27:
			return MINUS_sempred((RuleContext)_localctx, predIndex);
		case 29:
			return OPEN_sempred((RuleContext)_localctx, predIndex);
		case 30:
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
		"\u0004\u0000\u001f\u0115\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002"+
		"\u0001\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002"+
		"\u0004\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002"+
		"\u0007\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002"+
		"\u000b\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e"+
		"\u0002\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011"+
		"\u0002\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014"+
		"\u0002\u0015\u0007\u0015\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017"+
		"\u0002\u0018\u0007\u0018\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a"+
		"\u0002\u001b\u0007\u001b\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d"+
		"\u0002\u001e\u0007\u001e\u0001\u0000\u0004\u0000A\b\u0000\u000b\u0000"+
		"\f\u0000B\u0001\u0000\u0001\u0000\u0001\u0001\u0005\u0001H\b\u0001\n\u0001"+
		"\f\u0001K\t\u0001\u0001\u0001\u0001\u0001\u0004\u0001O\b\u0001\u000b\u0001"+
		"\f\u0001P\u0001\u0001\u0004\u0001T\b\u0001\u000b\u0001\f\u0001U\u0001"+
		"\u0001\u0003\u0001Y\b\u0001\u0001\u0001\u0001\u0001\u0003\u0001]\b\u0001"+
		"\u0001\u0001\u0004\u0001`\b\u0001\u000b\u0001\f\u0001a\u0003\u0001d\b"+
		"\u0001\u0001\u0001\u0004\u0001g\b\u0001\u000b\u0001\f\u0001h\u0001\u0001"+
		"\u0001\u0001\u0003\u0001m\b\u0001\u0001\u0001\u0004\u0001p\b\u0001\u000b"+
		"\u0001\f\u0001q\u0003\u0001t\b\u0001\u0001\u0001\u0001\u0001\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0003\u0007"+
		"\u00a2\b\u0007\u0001\b\u0001\b\u0001\b\u0004\b\u00a7\b\b\u000b\b\f\b\u00a8"+
		"\u0001\b\u0001\b\u0001\t\u0001\t\u0005\t\u00af\b\t\n\t\f\t\u00b2\t\t\u0001"+
		"\t\u0003\t\u00b5\b\t\u0001\t\u0001\t\u0001\n\u0001\n\u0001\n\u0005\n\u00bc"+
		"\b\n\n\n\f\n\u00bf\t\n\u0001\n\u0003\n\u00c2\b\n\u0001\n\u0001\n\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0005\u000b\u00c9\b\u000b\n\u000b\f\u000b"+
		"\u00cc\t\u000b\u0001\u000b\u0003\u000b\u00cf\b\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\f\u0001\f\u0001\f\u0001\r\u0001\r\u0001\r\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0001"+
		"\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0018\u0001"+
		"\u0018\u0001\u0018\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001"+
		"\u001a\u0001\u001a\u0001\u001a\u0001\u001b\u0001\u001b\u0001\u001b\u0001"+
		"\u001b\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001d\u0001\u001d\u0001"+
		"\u001d\u0001\u001d\u0001\u001e\u0001\u001e\u0001\u001e\u0001\u001e\u0000"+
		"\u0000\u001f\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005\u000b"+
		"\u0006\r\u0007\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0019\r\u001b"+
		"\u000e\u001d\u000f\u001f\u0010!\u0011#\u0012%\u0013\'\u0014)\u0015+\u0016"+
		"-\u0017/\u00181\u00193\u001a5\u001b7\u001c9\u001d;\u001e=\u001f\u0001"+
		"\u0000\b\u0001\u000009\u0002\u0000EEee\u0002\u0000++--\u0002\u0000llx"+
		"x\u0002\u0000AZaz\u0004\u000009AZ__az\u0003\u000009AZaz\u0003\u0000\u0001"+
		"\u0001\t\t  \u0129\u0000\u0001\u0001\u0000\u0000\u0000\u0000\u0003\u0001"+
		"\u0000\u0000\u0000\u0000\u0005\u0001\u0000\u0000\u0000\u0000\u0007\u0001"+
		"\u0000\u0000\u0000\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b\u0001\u0000"+
		"\u0000\u0000\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001\u0000\u0000"+
		"\u0000\u0000\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001\u0000\u0000"+
		"\u0000\u0000\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001\u0000\u0000"+
		"\u0000\u0000\u0019\u0001\u0000\u0000\u0000\u0000\u001b\u0001\u0000\u0000"+
		"\u0000\u0000\u001d\u0001\u0000\u0000\u0000\u0000\u001f\u0001\u0000\u0000"+
		"\u0000\u0000!\u0001\u0000\u0000\u0000\u0000#\u0001\u0000\u0000\u0000\u0000"+
		"%\u0001\u0000\u0000\u0000\u0000\'\u0001\u0000\u0000\u0000\u0000)\u0001"+
		"\u0000\u0000\u0000\u0000+\u0001\u0000\u0000\u0000\u0000-\u0001\u0000\u0000"+
		"\u0000\u0000/\u0001\u0000\u0000\u0000\u00001\u0001\u0000\u0000\u0000\u0000"+
		"3\u0001\u0000\u0000\u0000\u00005\u0001\u0000\u0000\u0000\u00007\u0001"+
		"\u0000\u0000\u0000\u00009\u0001\u0000\u0000\u0000\u0000;\u0001\u0000\u0000"+
		"\u0000\u0000=\u0001\u0000\u0000\u0000\u0001@\u0001\u0000\u0000\u0000\u0003"+
		"s\u0001\u0000\u0000\u0000\u0005w\u0001\u0000\u0000\u0000\u0007|\u0001"+
		"\u0000\u0000\u0000\t\u0083\u0001\u0000\u0000\u0000\u000b\u008a\u0001\u0000"+
		"\u0000\u0000\r\u0090\u0001\u0000\u0000\u0000\u000f\u00a1\u0001\u0000\u0000"+
		"\u0000\u0011\u00a3\u0001\u0000\u0000\u0000\u0013\u00ac\u0001\u0000\u0000"+
		"\u0000\u0015\u00b8\u0001\u0000\u0000\u0000\u0017\u00c5\u0001\u0000\u0000"+
		"\u0000\u0019\u00d2\u0001\u0000\u0000\u0000\u001b\u00d5\u0001\u0000\u0000"+
		"\u0000\u001d\u00d8\u0001\u0000\u0000\u0000\u001f\u00db\u0001\u0000\u0000"+
		"\u0000!\u00de\u0001\u0000\u0000\u0000#\u00e1\u0001\u0000\u0000\u0000%"+
		"\u00e4\u0001\u0000\u0000\u0000\'\u00e7\u0001\u0000\u0000\u0000)\u00ea"+
		"\u0001\u0000\u0000\u0000+\u00ef\u0001\u0000\u0000\u0000-\u00f4\u0001\u0000"+
		"\u0000\u0000/\u00f7\u0001\u0000\u0000\u00001\u00fc\u0001\u0000\u0000\u0000"+
		"3\u00ff\u0001\u0000\u0000\u00005\u0103\u0001\u0000\u0000\u00007\u0106"+
		"\u0001\u0000\u0000\u00009\u010a\u0001\u0000\u0000\u0000;\u010d\u0001\u0000"+
		"\u0000\u0000=\u0111\u0001\u0000\u0000\u0000?A\u0007\u0000\u0000\u0000"+
		"@?\u0001\u0000\u0000\u0000AB\u0001\u0000\u0000\u0000B@\u0001\u0000\u0000"+
		"\u0000BC\u0001\u0000\u0000\u0000CD\u0001\u0000\u0000\u0000DE\u0006\u0000"+
		"\u0000\u0000E\u0002\u0001\u0000\u0000\u0000FH\u0007\u0000\u0000\u0000"+
		"GF\u0001\u0000\u0000\u0000HK\u0001\u0000\u0000\u0000IG\u0001\u0000\u0000"+
		"\u0000IJ\u0001\u0000\u0000\u0000JL\u0001\u0000\u0000\u0000KI\u0001\u0000"+
		"\u0000\u0000LN\u0005.\u0000\u0000MO\u0007\u0000\u0000\u0000NM\u0001\u0000"+
		"\u0000\u0000OP\u0001\u0000\u0000\u0000PN\u0001\u0000\u0000\u0000PQ\u0001"+
		"\u0000\u0000\u0000QY\u0001\u0000\u0000\u0000RT\u0007\u0000\u0000\u0000"+
		"SR\u0001\u0000\u0000\u0000TU\u0001\u0000\u0000\u0000US\u0001\u0000\u0000"+
		"\u0000UV\u0001\u0000\u0000\u0000VW\u0001\u0000\u0000\u0000WY\u0005.\u0000"+
		"\u0000XI\u0001\u0000\u0000\u0000XS\u0001\u0000\u0000\u0000Yc\u0001\u0000"+
		"\u0000\u0000Z\\\u0007\u0001\u0000\u0000[]\u0007\u0002\u0000\u0000\\[\u0001"+
		"\u0000\u0000\u0000\\]\u0001\u0000\u0000\u0000]_\u0001\u0000\u0000\u0000"+
		"^`\u0007\u0000\u0000\u0000_^\u0001\u0000\u0000\u0000`a\u0001\u0000\u0000"+
		"\u0000a_\u0001\u0000\u0000\u0000ab\u0001\u0000\u0000\u0000bd\u0001\u0000"+
		"\u0000\u0000cZ\u0001\u0000\u0000\u0000cd\u0001\u0000\u0000\u0000dt\u0001"+
		"\u0000\u0000\u0000eg\u0007\u0000\u0000\u0000fe\u0001\u0000\u0000\u0000"+
		"gh\u0001\u0000\u0000\u0000hf\u0001\u0000\u0000\u0000hi\u0001\u0000\u0000"+
		"\u0000ij\u0001\u0000\u0000\u0000jl\u0007\u0001\u0000\u0000km\u0007\u0002"+
		"\u0000\u0000lk\u0001\u0000\u0000\u0000lm\u0001\u0000\u0000\u0000mo\u0001"+
		"\u0000\u0000\u0000np\u0007\u0000\u0000\u0000on\u0001\u0000\u0000\u0000"+
		"pq\u0001\u0000\u0000\u0000qo\u0001\u0000\u0000\u0000qr\u0001\u0000\u0000"+
		"\u0000rt\u0001\u0000\u0000\u0000sX\u0001\u0000\u0000\u0000sf\u0001\u0000"+
		"\u0000\u0000tu\u0001\u0000\u0000\u0000uv\u0006\u0001\u0001\u0000v\u0004"+
		"\u0001\u0000\u0000\u0000wx\u0005i\u0000\u0000xy\u0005f\u0000\u0000yz\u0001"+
		"\u0000\u0000\u0000z{\u0006\u0002\u0002\u0000{\u0006\u0001\u0000\u0000"+
		"\u0000|}\u0005t\u0000\u0000}~\u0005h\u0000\u0000~\u007f\u0005e\u0000\u0000"+
		"\u007f\u0080\u0005n\u0000\u0000\u0080\u0081\u0001\u0000\u0000\u0000\u0081"+
		"\u0082\u0006\u0003\u0003\u0000\u0082\b\u0001\u0000\u0000\u0000\u0083\u0084"+
		"\u0005e\u0000\u0000\u0084\u0085\u0005l\u0000\u0000\u0085\u0086\u0005s"+
		"\u0000\u0000\u0086\u0087\u0005e\u0000\u0000\u0087\u0088\u0001\u0000\u0000"+
		"\u0000\u0088\u0089\u0006\u0004\u0004\u0000\u0089\n\u0001\u0000\u0000\u0000"+
		"\u008a\u008b\u0005f\u0000\u0000\u008b\u008c\u0005o\u0000\u0000\u008c\u008d"+
		"\u0005r\u0000\u0000\u008d\u008e\u0001\u0000\u0000\u0000\u008e\u008f\u0006"+
		"\u0005\u0005\u0000\u008f\f\u0001\u0000\u0000\u0000\u0090\u0091\u0005d"+
		"\u0000\u0000\u0091\u0092\u0005o\u0000\u0000\u0092\u0093\u0001\u0000\u0000"+
		"\u0000\u0093\u0094\u0006\u0006\u0006\u0000\u0094\u000e\u0001\u0000\u0000"+
		"\u0000\u0095\u0096\u0005s\u0000\u0000\u0096\u0097\u0005i\u0000\u0000\u0097"+
		"\u00a2\u0005n\u0000\u0000\u0098\u0099\u0005c\u0000\u0000\u0099\u009a\u0005"+
		"o\u0000\u0000\u009a\u00a2\u0005s\u0000\u0000\u009b\u009c\u0005s\u0000"+
		"\u0000\u009c\u009d\u0005q\u0000\u0000\u009d\u009e\u0005r\u0000\u0000\u009e"+
		"\u009f\u0005t\u0000\u0000\u009f\u00a0\u0001\u0000\u0000\u0000\u00a0\u00a2"+
		"\u0006\u0007\u0007\u0000\u00a1\u0095\u0001\u0000\u0000\u0000\u00a1\u0098"+
		"\u0001\u0000\u0000\u0000\u00a1\u009b\u0001\u0000\u0000\u0000\u00a2\u0010"+
		"\u0001\u0000\u0000\u0000\u00a3\u00a4\u0005$\u0000\u0000\u00a4\u00a6\u0007"+
		"\u0003\u0000\u0000\u00a5\u00a7\u0007\u0000\u0000\u0000\u00a6\u00a5\u0001"+
		"\u0000\u0000\u0000\u00a7\u00a8\u0001\u0000\u0000\u0000\u00a8\u00a6\u0001"+
		"\u0000\u0000\u0000\u00a8\u00a9\u0001\u0000\u0000\u0000\u00a9\u00aa\u0001"+
		"\u0000\u0000\u0000\u00aa\u00ab\u0006\b\b\u0000\u00ab\u0012\u0001\u0000"+
		"\u0000\u0000\u00ac\u00b4\u0007\u0004\u0000\u0000\u00ad\u00af\u0007\u0005"+
		"\u0000\u0000\u00ae\u00ad\u0001\u0000\u0000\u0000\u00af\u00b2\u0001\u0000"+
		"\u0000\u0000\u00b0\u00ae\u0001\u0000\u0000\u0000\u00b0\u00b1\u0001\u0000"+
		"\u0000\u0000\u00b1\u00b3\u0001\u0000\u0000\u0000\u00b2\u00b0\u0001\u0000"+
		"\u0000\u0000\u00b3\u00b5\u0007\u0006\u0000\u0000\u00b4\u00b0\u0001\u0000"+
		"\u0000\u0000\u00b4\u00b5\u0001\u0000\u0000\u0000\u00b5\u00b6\u0001\u0000"+
		"\u0000\u0000\u00b6\u00b7\u0006\t\t\u0000\u00b7\u0014\u0001\u0000\u0000"+
		"\u0000\u00b8\u00b9\u0005#\u0000\u0000\u00b9\u00c1\u0007\u0004\u0000\u0000"+
		"\u00ba\u00bc\u0007\u0005\u0000\u0000\u00bb\u00ba\u0001\u0000\u0000\u0000"+
		"\u00bc\u00bf\u0001\u0000\u0000\u0000\u00bd\u00bb\u0001\u0000\u0000\u0000"+
		"\u00bd\u00be\u0001\u0000\u0000\u0000\u00be\u00c0\u0001\u0000\u0000\u0000"+
		"\u00bf\u00bd\u0001\u0000\u0000\u0000\u00c0\u00c2\u0007\u0006\u0000\u0000"+
		"\u00c1\u00bd\u0001\u0000\u0000\u0000\u00c1\u00c2\u0001\u0000\u0000\u0000"+
		"\u00c2\u00c3\u0001\u0000\u0000\u0000\u00c3\u00c4\u0006\n\n\u0000\u00c4"+
		"\u0016\u0001\u0000\u0000\u0000\u00c5\u00c6\u0005$\u0000\u0000\u00c6\u00ce"+
		"\u0007\u0004\u0000\u0000\u00c7\u00c9\u0007\u0005\u0000\u0000\u00c8\u00c7"+
		"\u0001\u0000\u0000\u0000\u00c9\u00cc\u0001\u0000\u0000\u0000\u00ca\u00c8"+
		"\u0001\u0000\u0000\u0000\u00ca\u00cb\u0001\u0000\u0000\u0000\u00cb\u00cd"+
		"\u0001\u0000\u0000\u0000\u00cc\u00ca\u0001\u0000\u0000\u0000\u00cd\u00cf"+
		"\u0007\u0006\u0000\u0000\u00ce\u00ca\u0001\u0000\u0000\u0000\u00ce\u00cf"+
		"\u0001\u0000\u0000\u0000\u00cf\u00d0\u0001\u0000\u0000\u0000\u00d0\u00d1"+
		"\u0006\u000b\u000b\u0000\u00d1\u0018\u0001\u0000\u0000\u0000\u00d2\u00d3"+
		"\u0005[\u0000\u0000\u00d3\u00d4\u0006\f\f\u0000\u00d4\u001a\u0001\u0000"+
		"\u0000\u0000\u00d5\u00d6\u0005]\u0000\u0000\u00d6\u00d7\u0006\r\r\u0000"+
		"\u00d7\u001c\u0001\u0000\u0000\u0000\u00d8\u00d9\u0005)\u0000\u0000\u00d9"+
		"\u00da\u0006\u000e\u000e\u0000\u00da\u001e\u0001\u0000\u0000\u0000\u00db"+
		"\u00dc\u0005:\u0000\u0000\u00dc\u00dd\u0006\u000f\u000f\u0000\u00dd \u0001"+
		"\u0000\u0000\u0000\u00de\u00df\u0005.\u0000\u0000\u00df\u00e0\u0006\u0010"+
		"\u0010\u0000\u00e0\"\u0001\u0000\u0000\u0000\u00e1\u00e2\u0005;\u0000"+
		"\u0000\u00e2\u00e3\u0006\u0011\u0011\u0000\u00e3$\u0001\u0000\u0000\u0000"+
		"\u00e4\u00e5\u0005=\u0000\u0000\u00e5\u00e6\u0006\u0012\u0012\u0000\u00e6"+
		"&\u0001\u0000\u0000\u0000\u00e7\u00e8\u0005\n\u0000\u0000\u00e8\u00e9"+
		"\u0006\u0013\u0013\u0000\u00e9(\u0001\u0000\u0000\u0000\u00ea\u00eb\u0007"+
		"\u0007\u0000\u0000\u00eb\u00ec\u0006\u0014\u0014\u0000\u00ec\u00ed\u0001"+
		"\u0000\u0000\u0000\u00ed\u00ee\u0006\u0014\u0015\u0000\u00ee*\u0001\u0000"+
		"\u0000\u0000\u00ef\u00f0\u0005*\u0000\u0000\u00f0\u00f1\u0005*\u0000\u0000"+
		"\u00f1\u00f2\u0001\u0000\u0000\u0000\u00f2\u00f3\u0006\u0015\u0016\u0000"+
		"\u00f3,\u0001\u0000\u0000\u0000\u00f4\u00f5\u0005*\u0000\u0000\u00f5\u00f6"+
		"\u0006\u0016\u0017\u0000\u00f6.\u0001\u0000\u0000\u0000\u00f7\u00f8\u0005"+
		"/\u0000\u0000\u00f8\u00f9\u0005/\u0000\u0000\u00f9\u00fa\u0001\u0000\u0000"+
		"\u0000\u00fa\u00fb\u0006\u0017\u0018\u0000\u00fb0\u0001\u0000\u0000\u0000"+
		"\u00fc\u00fd\u0005/\u0000\u0000\u00fd\u00fe\u0006\u0018\u0019\u0000\u00fe"+
		"2\u0001\u0000\u0000\u0000\u00ff\u0100\u0004\u0019\u0000\u0000\u0100\u0101"+
		"\u0005+\u0000\u0000\u0101\u0102\u0006\u0019\u001a\u0000\u01024\u0001\u0000"+
		"\u0000\u0000\u0103\u0104\u0005+\u0000\u0000\u0104\u0105\u0006\u001a\u001b"+
		"\u0000\u01056\u0001\u0000\u0000\u0000\u0106\u0107\u0004\u001b\u0001\u0000"+
		"\u0107\u0108\u0005-\u0000\u0000\u0108\u0109\u0006\u001b\u001c\u0000\u0109"+
		"8\u0001\u0000\u0000\u0000\u010a\u010b\u0005-\u0000\u0000\u010b\u010c\u0006"+
		"\u001c\u001d\u0000\u010c:\u0001\u0000\u0000\u0000\u010d\u010e\u0004\u001d"+
		"\u0002\u0000\u010e\u010f\u0005(\u0000\u0000\u010f\u0110\u0006\u001d\u001e"+
		"\u0000\u0110<\u0001\u0000\u0000\u0000\u0111\u0112\u0004\u001e\u0003\u0000"+
		"\u0112\u0113\u0005(\u0000\u0000\u0113\u0114\u0006\u001e\u001f\u0000\u0114"+
		">\u0001\u0000\u0000\u0000\u0015\u0000BIPUX\\achlqs\u00a1\u00a8\u00b0\u00b4"+
		"\u00bd\u00c1\u00ca\u00ce \u0001\u0000\u0000\u0001\u0001\u0001\u0001\u0002"+
		"\u0002\u0001\u0003\u0003\u0001\u0004\u0004\u0001\u0005\u0005\u0001\u0006"+
		"\u0006\u0001\u0007\u0007\u0001\b\b\u0001\t\t\u0001\n\n\u0001\u000b\u000b"+
		"\u0001\f\f\u0001\r\r\u0001\u000e\u000e\u0001\u000f\u000f\u0001\u0010\u0010"+
		"\u0001\u0011\u0011\u0001\u0012\u0012\u0001\u0013\u0013\u0001\u0014\u0014"+
		"\u0000\u0001\u0000\u0001\u0015\u0015\u0001\u0016\u0016\u0001\u0017\u0017"+
		"\u0001\u0018\u0018\u0001\u0019\u0019\u0001\u001a\u001a\u0001\u001b\u001b"+
		"\u0001\u001c\u001c\u0001\u001d\u001d\u0001\u001e\u001e";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}