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
		NUMBER=1, IF=2, THEN=3, ELSE=4, FOR=5, DO=6, FUNCTION=7, VAR=8, PUSH=9, 
		POP=10, CLOSED=11, NTH=12, KEY=13, NULLIFY=14, ASSIGN=15, EOL=16, WHITESPACE=17, 
		POW=18, TIMES=19, PLUS=20, UPLUS=21, MINUS=22, UMINUS=23, OPEN=24, PARAMS=25;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"NUMBER", "IF", "THEN", "ELSE", "FOR", "DO", "FUNCTION", "VAR", "PUSH", 
			"POP", "CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", 
			"POW", "TIMES", "PLUS", "UPLUS", "MINUS", "UMINUS", "OPEN", "PARAMS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, "'if'", "'then'", "'else'", "'for'", "'do'", null, null, 
			"'['", "']'", "')'", "':'", "'.'", "';'", "'='", "'\\n'", null, "'**'", 
			"'*'", null, "'+'", null, "'-'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "NUMBER", "IF", "THEN", "ELSE", "FOR", "DO", "FUNCTION", "VAR", 
			"PUSH", "POP", "CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", 
			"POW", "TIMES", "PLUS", "UPLUS", "MINUS", "UMINUS", "OPEN", "PARAMS"
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
	        post("\c", c);
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
			NUMBER_action((RuleContext)_localctx, actionIndex);
			break;
		case 1:
			IF_action((RuleContext)_localctx, actionIndex);
			break;
		case 2:
			THEN_action((RuleContext)_localctx, actionIndex);
			break;
		case 3:
			ELSE_action((RuleContext)_localctx, actionIndex);
			break;
		case 4:
			FOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 5:
			DO_action((RuleContext)_localctx, actionIndex);
			break;
		case 6:
			FUNCTION_action((RuleContext)_localctx, actionIndex);
			break;
		case 7:
			VAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 8:
			PUSH_action((RuleContext)_localctx, actionIndex);
			break;
		case 9:
			POP_action((RuleContext)_localctx, actionIndex);
			break;
		case 10:
			CLOSED_action((RuleContext)_localctx, actionIndex);
			break;
		case 11:
			NTH_action((RuleContext)_localctx, actionIndex);
			break;
		case 12:
			KEY_action((RuleContext)_localctx, actionIndex);
			break;
		case 13:
			NULLIFY_action((RuleContext)_localctx, actionIndex);
			break;
		case 14:
			ASSIGN_action((RuleContext)_localctx, actionIndex);
			break;
		case 15:
			EOL_action((RuleContext)_localctx, actionIndex);
			break;
		case 16:
			WHITESPACE_action((RuleContext)_localctx, actionIndex);
			break;
		case 17:
			POW_action((RuleContext)_localctx, actionIndex);
			break;
		case 18:
			TIMES_action((RuleContext)_localctx, actionIndex);
			break;
		case 19:
			PLUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 20:
			UPLUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 21:
			MINUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 22:
			UMINUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 23:
			OPEN_action((RuleContext)_localctx, actionIndex);
			break;
		case 24:
			PARAMS_action((RuleContext)_localctx, actionIndex);
			break;
		}
	}
	private void NUMBER_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 0:
			 std::cout << "number\n"; noParams = false; noUnary = true; 
			break;
		}
	}
	private void IF_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 1:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void THEN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 2:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ELSE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 3:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void FOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 4:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DO_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 5:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void FUNCTION_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 6:
			 noParams = noUnary = false; 
			break;
		}
	}
	private void VAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 7:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void PUSH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 8:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void POP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 9:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void CLOSED_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 10:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void NTH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 11:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void KEY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 12:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void NULLIFY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 13:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ASSIGN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 14:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void EOL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 15:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void WHITESPACE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 16:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void POW_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 17:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void TIMES_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 18:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PLUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 19:
			 post("plus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void UPLUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 20:
			 post("uplus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void MINUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 21:
			 post("minus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void UMINUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 22:
			 post("uminus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void OPEN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 23:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PARAMS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 24:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	@Override
	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 19:
			return PLUS_sempred((RuleContext)_localctx, predIndex);
		case 21:
			return MINUS_sempred((RuleContext)_localctx, predIndex);
		case 23:
			return OPEN_sempred((RuleContext)_localctx, predIndex);
		case 24:
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
		"\u0004\u0000\u0019\u00a4\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002"+
		"\u0001\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002"+
		"\u0004\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002"+
		"\u0007\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002"+
		"\u000b\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e"+
		"\u0002\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011"+
		"\u0002\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014"+
		"\u0002\u0015\u0007\u0015\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017"+
		"\u0002\u0018\u0007\u0018\u0001\u0000\u0004\u00005\b\u0000\u000b\u0000"+
		"\f\u00006\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0003\u0006e\b\u0006\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001\b\u0001\t\u0001\t\u0001"+
		"\t\u0001\n\u0001\n\u0001\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\f"+
		"\u0001\f\u0001\f\u0001\r\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0016\u0001\u0016\u0001"+
		"\u0016\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0018\u0001"+
		"\u0018\u0001\u0018\u0001\u0018\u0000\u0000\u0019\u0001\u0001\u0003\u0002"+
		"\u0005\u0003\u0007\u0004\t\u0005\u000b\u0006\r\u0007\u000f\b\u0011\t\u0013"+
		"\n\u0015\u000b\u0017\f\u0019\r\u001b\u000e\u001d\u000f\u001f\u0010!\u0011"+
		"#\u0012%\u0013\'\u0014)\u0015+\u0016-\u0017/\u00181\u0019\u0001\u0000"+
		"\u0003\u0001\u000009\u0001\u0000az\u0003\u0000\u0001\u0001\t\t  \u00a6"+
		"\u0000\u0001\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000"+
		"\u0000\u0005\u0001\u0000\u0000\u0000\u0000\u0007\u0001\u0000\u0000\u0000"+
		"\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b\u0001\u0000\u0000\u0000\u0000"+
		"\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001\u0000\u0000\u0000\u0000\u0011"+
		"\u0001\u0000\u0000\u0000\u0000\u0013\u0001\u0000\u0000\u0000\u0000\u0015"+
		"\u0001\u0000\u0000\u0000\u0000\u0017\u0001\u0000\u0000\u0000\u0000\u0019"+
		"\u0001\u0000\u0000\u0000\u0000\u001b\u0001\u0000\u0000\u0000\u0000\u001d"+
		"\u0001\u0000\u0000\u0000\u0000\u001f\u0001\u0000\u0000\u0000\u0000!\u0001"+
		"\u0000\u0000\u0000\u0000#\u0001\u0000\u0000\u0000\u0000%\u0001\u0000\u0000"+
		"\u0000\u0000\'\u0001\u0000\u0000\u0000\u0000)\u0001\u0000\u0000\u0000"+
		"\u0000+\u0001\u0000\u0000\u0000\u0000-\u0001\u0000\u0000\u0000\u0000/"+
		"\u0001\u0000\u0000\u0000\u00001\u0001\u0000\u0000\u0000\u00014\u0001\u0000"+
		"\u0000\u0000\u0003:\u0001\u0000\u0000\u0000\u0005?\u0001\u0000\u0000\u0000"+
		"\u0007F\u0001\u0000\u0000\u0000\tM\u0001\u0000\u0000\u0000\u000bS\u0001"+
		"\u0000\u0000\u0000\rd\u0001\u0000\u0000\u0000\u000ff\u0001\u0000\u0000"+
		"\u0000\u0011i\u0001\u0000\u0000\u0000\u0013l\u0001\u0000\u0000\u0000\u0015"+
		"o\u0001\u0000\u0000\u0000\u0017r\u0001\u0000\u0000\u0000\u0019u\u0001"+
		"\u0000\u0000\u0000\u001bx\u0001\u0000\u0000\u0000\u001d{\u0001\u0000\u0000"+
		"\u0000\u001f~\u0001\u0000\u0000\u0000!\u0081\u0001\u0000\u0000\u0000#"+
		"\u0086\u0001\u0000\u0000\u0000%\u008b\u0001\u0000\u0000\u0000\'\u008e"+
		"\u0001\u0000\u0000\u0000)\u0092\u0001\u0000\u0000\u0000+\u0095\u0001\u0000"+
		"\u0000\u0000-\u0099\u0001\u0000\u0000\u0000/\u009c\u0001\u0000\u0000\u0000"+
		"1\u00a0\u0001\u0000\u0000\u000035\u0007\u0000\u0000\u000043\u0001\u0000"+
		"\u0000\u000056\u0001\u0000\u0000\u000064\u0001\u0000\u0000\u000067\u0001"+
		"\u0000\u0000\u000078\u0001\u0000\u0000\u000089\u0006\u0000\u0000\u0000"+
		"9\u0002\u0001\u0000\u0000\u0000:;\u0005i\u0000\u0000;<\u0005f\u0000\u0000"+
		"<=\u0001\u0000\u0000\u0000=>\u0006\u0001\u0001\u0000>\u0004\u0001\u0000"+
		"\u0000\u0000?@\u0005t\u0000\u0000@A\u0005h\u0000\u0000AB\u0005e\u0000"+
		"\u0000BC\u0005n\u0000\u0000CD\u0001\u0000\u0000\u0000DE\u0006\u0002\u0002"+
		"\u0000E\u0006\u0001\u0000\u0000\u0000FG\u0005e\u0000\u0000GH\u0005l\u0000"+
		"\u0000HI\u0005s\u0000\u0000IJ\u0005e\u0000\u0000JK\u0001\u0000\u0000\u0000"+
		"KL\u0006\u0003\u0003\u0000L\b\u0001\u0000\u0000\u0000MN\u0005f\u0000\u0000"+
		"NO\u0005o\u0000\u0000OP\u0005r\u0000\u0000PQ\u0001\u0000\u0000\u0000Q"+
		"R\u0006\u0004\u0004\u0000R\n\u0001\u0000\u0000\u0000ST\u0005d\u0000\u0000"+
		"TU\u0005o\u0000\u0000UV\u0001\u0000\u0000\u0000VW\u0006\u0005\u0005\u0000"+
		"W\f\u0001\u0000\u0000\u0000XY\u0005s\u0000\u0000YZ\u0005i\u0000\u0000"+
		"Ze\u0005n\u0000\u0000[\\\u0005c\u0000\u0000\\]\u0005o\u0000\u0000]e\u0005"+
		"s\u0000\u0000^_\u0005s\u0000\u0000_`\u0005q\u0000\u0000`a\u0005r\u0000"+
		"\u0000ab\u0005t\u0000\u0000bc\u0001\u0000\u0000\u0000ce\u0006\u0006\u0006"+
		"\u0000dX\u0001\u0000\u0000\u0000d[\u0001\u0000\u0000\u0000d^\u0001\u0000"+
		"\u0000\u0000e\u000e\u0001\u0000\u0000\u0000fg\u0007\u0001\u0000\u0000"+
		"gh\u0006\u0007\u0007\u0000h\u0010\u0001\u0000\u0000\u0000ij\u0005[\u0000"+
		"\u0000jk\u0006\b\b\u0000k\u0012\u0001\u0000\u0000\u0000lm\u0005]\u0000"+
		"\u0000mn\u0006\t\t\u0000n\u0014\u0001\u0000\u0000\u0000op\u0005)\u0000"+
		"\u0000pq\u0006\n\n\u0000q\u0016\u0001\u0000\u0000\u0000rs\u0005:\u0000"+
		"\u0000st\u0006\u000b\u000b\u0000t\u0018\u0001\u0000\u0000\u0000uv\u0005"+
		".\u0000\u0000vw\u0006\f\f\u0000w\u001a\u0001\u0000\u0000\u0000xy\u0005"+
		";\u0000\u0000yz\u0006\r\r\u0000z\u001c\u0001\u0000\u0000\u0000{|\u0005"+
		"=\u0000\u0000|}\u0006\u000e\u000e\u0000}\u001e\u0001\u0000\u0000\u0000"+
		"~\u007f\u0005\n\u0000\u0000\u007f\u0080\u0006\u000f\u000f\u0000\u0080"+
		" \u0001\u0000\u0000\u0000\u0081\u0082\u0007\u0002\u0000\u0000\u0082\u0083"+
		"\u0006\u0010\u0010\u0000\u0083\u0084\u0001\u0000\u0000\u0000\u0084\u0085"+
		"\u0006\u0010\u0011\u0000\u0085\"\u0001\u0000\u0000\u0000\u0086\u0087\u0005"+
		"*\u0000\u0000\u0087\u0088\u0005*\u0000\u0000\u0088\u0089\u0001\u0000\u0000"+
		"\u0000\u0089\u008a\u0006\u0011\u0012\u0000\u008a$\u0001\u0000\u0000\u0000"+
		"\u008b\u008c\u0005*\u0000\u0000\u008c\u008d\u0006\u0012\u0013\u0000\u008d"+
		"&\u0001\u0000\u0000\u0000\u008e\u008f\u0004\u0013\u0000\u0000\u008f\u0090"+
		"\u0005+\u0000\u0000\u0090\u0091\u0006\u0013\u0014\u0000\u0091(\u0001\u0000"+
		"\u0000\u0000\u0092\u0093\u0005+\u0000\u0000\u0093\u0094\u0006\u0014\u0015"+
		"\u0000\u0094*\u0001\u0000\u0000\u0000\u0095\u0096\u0004\u0015\u0001\u0000"+
		"\u0096\u0097\u0005-\u0000\u0000\u0097\u0098\u0006\u0015\u0016\u0000\u0098"+
		",\u0001\u0000\u0000\u0000\u0099\u009a\u0005-\u0000\u0000\u009a\u009b\u0006"+
		"\u0016\u0017\u0000\u009b.\u0001\u0000\u0000\u0000\u009c\u009d\u0004\u0017"+
		"\u0002\u0000\u009d\u009e\u0005(\u0000\u0000\u009e\u009f\u0006\u0017\u0018"+
		"\u0000\u009f0\u0001\u0000\u0000\u0000\u00a0\u00a1\u0004\u0018\u0003\u0000"+
		"\u00a1\u00a2\u0005(\u0000\u0000\u00a2\u00a3\u0006\u0018\u0019\u0000\u00a3"+
		"2\u0001\u0000\u0000\u0000\u0003\u00006d\u001a\u0001\u0000\u0000\u0001"+
		"\u0001\u0001\u0001\u0002\u0002\u0001\u0003\u0003\u0001\u0004\u0004\u0001"+
		"\u0005\u0005\u0001\u0006\u0006\u0001\u0007\u0007\u0001\b\b\u0001\t\t\u0001"+
		"\n\n\u0001\u000b\u000b\u0001\f\f\u0001\r\r\u0001\u000e\u000e\u0001\u000f"+
		"\u000f\u0001\u0010\u0010\u0000\u0001\u0000\u0001\u0011\u0011\u0001\u0012"+
		"\u0012\u0001\u0013\u0013\u0001\u0014\u0014\u0001\u0015\u0015\u0001\u0016"+
		"\u0016\u0001\u0017\u0017\u0001\u0018\u0018";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}