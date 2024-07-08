// Generated from /Users/aa/Documents/Max 8/Packages/bach/source/commons/bell/antlrparser/bell.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class parsetestLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		NUMBER=1, IF=2, THEN=3, ELSE=4, FUNCTION=5, VAR=6, PUSH=7, POP=8, CLOSED=9, 
		NTH=10, TIMES=11, NULLIFY=12, ASSIGN=13, EOL=14, WHITESPACE=15, PLUS=16, 
		UPLUS=17, MINUS=18, UMINUS=19, OPEN=20, PARAMS=21;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"NUMBER", "IF", "THEN", "ELSE", "FUNCTION", "VAR", "PUSH", "POP", "CLOSED", 
			"NTH", "TIMES", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", "PLUS", "UPLUS", 
			"MINUS", "UMINUS", "OPEN", "PARAMS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, "'if'", "'then'", "'else'", null, null, "'['", "']'", "')'", 
			"':'", "'*'", "';'", "'='", "'\\n'", null, null, "'+'", null, "'-'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "NUMBER", "IF", "THEN", "ELSE", "FUNCTION", "VAR", "PUSH", "POP", 
			"CLOSED", "NTH", "TIMES", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", "PLUS", 
			"UPLUS", "MINUS", "UMINUS", "OPEN", "PARAMS"
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
	        switch (c) { 
	            case ' ':
	                return true;
	            default:
	                return false;
	        }
	    }

	    bool notUnary() {
	        return noUnary || followedBySpace();
	    }

	    //// MEMBERS END


	public parsetestLexer(CharStream input) {
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
			FUNCTION_action((RuleContext)_localctx, actionIndex);
			break;
		case 5:
			VAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 6:
			PUSH_action((RuleContext)_localctx, actionIndex);
			break;
		case 7:
			POP_action((RuleContext)_localctx, actionIndex);
			break;
		case 8:
			CLOSED_action((RuleContext)_localctx, actionIndex);
			break;
		case 9:
			NTH_action((RuleContext)_localctx, actionIndex);
			break;
		case 10:
			TIMES_action((RuleContext)_localctx, actionIndex);
			break;
		case 11:
			NULLIFY_action((RuleContext)_localctx, actionIndex);
			break;
		case 12:
			ASSIGN_action((RuleContext)_localctx, actionIndex);
			break;
		case 13:
			EOL_action((RuleContext)_localctx, actionIndex);
			break;
		case 14:
			WHITESPACE_action((RuleContext)_localctx, actionIndex);
			break;
		case 15:
			PLUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 16:
			UPLUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 17:
			MINUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 18:
			UMINUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 19:
			OPEN_action((RuleContext)_localctx, actionIndex);
			break;
		case 20:
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
	private void FUNCTION_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 4:
			 noParams = noUnary = false; 
			break;
		}
	}
	private void VAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 5:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void PUSH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 6:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void POP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 7:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void CLOSED_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 8:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void NTH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 9:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void TIMES_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 10:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void NULLIFY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 11:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ASSIGN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 12:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void EOL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 13:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void WHITESPACE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 14:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PLUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 15:
			 printf("plus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void UPLUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 16:
			 printf("uplus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void MINUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 17:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void UMINUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 18:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void OPEN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 19:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PARAMS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 20:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	@Override
	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 15:
			return PLUS_sempred((RuleContext)_localctx, predIndex);
		case 17:
			return MINUS_sempred((RuleContext)_localctx, predIndex);
		case 19:
			return OPEN_sempred((RuleContext)_localctx, predIndex);
		case 20:
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
		"\u0004\u0000\u0015\u0089\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002"+
		"\u0001\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002"+
		"\u0004\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002"+
		"\u0007\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002"+
		"\u000b\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e"+
		"\u0002\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011"+
		"\u0002\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014"+
		"\u0001\u0000\u0004\u0000-\b\u0000\u000b\u0000\f\u0000.\u0001\u0000\u0001"+
		"\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001"+
		"\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0003\u0004R\b\u0004\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\b\u0001\b\u0001\b\u0001\t\u0001\t\u0001\t\u0001\n\u0001\n"+
		"\u0001\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\f\u0001\f\u0001\f\u0001"+
		"\r\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0000\u0000\u0015"+
		"\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005\u000b\u0006\r"+
		"\u0007\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0019\r\u001b\u000e"+
		"\u001d\u000f\u001f\u0010!\u0011#\u0012%\u0013\'\u0014)\u0015\u0001\u0000"+
		"\u0003\u0001\u000009\u0001\u0000az\u0002\u0000\t\t  \u008b\u0000\u0001"+
		"\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000\u0000\u0005"+
		"\u0001\u0000\u0000\u0000\u0000\u0007\u0001\u0000\u0000\u0000\u0000\t\u0001"+
		"\u0000\u0000\u0000\u0000\u000b\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000"+
		"\u0000\u0000\u0000\u000f\u0001\u0000\u0000\u0000\u0000\u0011\u0001\u0000"+
		"\u0000\u0000\u0000\u0013\u0001\u0000\u0000\u0000\u0000\u0015\u0001\u0000"+
		"\u0000\u0000\u0000\u0017\u0001\u0000\u0000\u0000\u0000\u0019\u0001\u0000"+
		"\u0000\u0000\u0000\u001b\u0001\u0000\u0000\u0000\u0000\u001d\u0001\u0000"+
		"\u0000\u0000\u0000\u001f\u0001\u0000\u0000\u0000\u0000!\u0001\u0000\u0000"+
		"\u0000\u0000#\u0001\u0000\u0000\u0000\u0000%\u0001\u0000\u0000\u0000\u0000"+
		"\'\u0001\u0000\u0000\u0000\u0000)\u0001\u0000\u0000\u0000\u0001,\u0001"+
		"\u0000\u0000\u0000\u00032\u0001\u0000\u0000\u0000\u00057\u0001\u0000\u0000"+
		"\u0000\u0007>\u0001\u0000\u0000\u0000\tQ\u0001\u0000\u0000\u0000\u000b"+
		"S\u0001\u0000\u0000\u0000\rV\u0001\u0000\u0000\u0000\u000fY\u0001\u0000"+
		"\u0000\u0000\u0011\\\u0001\u0000\u0000\u0000\u0013_\u0001\u0000\u0000"+
		"\u0000\u0015b\u0001\u0000\u0000\u0000\u0017e\u0001\u0000\u0000\u0000\u0019"+
		"h\u0001\u0000\u0000\u0000\u001bk\u0001\u0000\u0000\u0000\u001dn\u0001"+
		"\u0000\u0000\u0000\u001fs\u0001\u0000\u0000\u0000!w\u0001\u0000\u0000"+
		"\u0000#z\u0001\u0000\u0000\u0000%~\u0001\u0000\u0000\u0000\'\u0081\u0001"+
		"\u0000\u0000\u0000)\u0085\u0001\u0000\u0000\u0000+-\u0007\u0000\u0000"+
		"\u0000,+\u0001\u0000\u0000\u0000-.\u0001\u0000\u0000\u0000.,\u0001\u0000"+
		"\u0000\u0000./\u0001\u0000\u0000\u0000/0\u0001\u0000\u0000\u000001\u0006"+
		"\u0000\u0000\u00001\u0002\u0001\u0000\u0000\u000023\u0005i\u0000\u0000"+
		"34\u0005f\u0000\u000045\u0001\u0000\u0000\u000056\u0006\u0001\u0001\u0000"+
		"6\u0004\u0001\u0000\u0000\u000078\u0005t\u0000\u000089\u0005h\u0000\u0000"+
		"9:\u0005e\u0000\u0000:;\u0005n\u0000\u0000;<\u0001\u0000\u0000\u0000<"+
		"=\u0006\u0002\u0002\u0000=\u0006\u0001\u0000\u0000\u0000>?\u0005e\u0000"+
		"\u0000?@\u0005l\u0000\u0000@A\u0005s\u0000\u0000AB\u0005e\u0000\u0000"+
		"BC\u0001\u0000\u0000\u0000CD\u0006\u0003\u0003\u0000D\b\u0001\u0000\u0000"+
		"\u0000EF\u0005s\u0000\u0000FG\u0005i\u0000\u0000GR\u0005n\u0000\u0000"+
		"HI\u0005c\u0000\u0000IJ\u0005o\u0000\u0000JR\u0005s\u0000\u0000KL\u0005"+
		"s\u0000\u0000LM\u0005q\u0000\u0000MN\u0005r\u0000\u0000NO\u0005t\u0000"+
		"\u0000OP\u0001\u0000\u0000\u0000PR\u0006\u0004\u0004\u0000QE\u0001\u0000"+
		"\u0000\u0000QH\u0001\u0000\u0000\u0000QK\u0001\u0000\u0000\u0000R\n\u0001"+
		"\u0000\u0000\u0000ST\u0007\u0001\u0000\u0000TU\u0006\u0005\u0005\u0000"+
		"U\f\u0001\u0000\u0000\u0000VW\u0005[\u0000\u0000WX\u0006\u0006\u0006\u0000"+
		"X\u000e\u0001\u0000\u0000\u0000YZ\u0005]\u0000\u0000Z[\u0006\u0007\u0007"+
		"\u0000[\u0010\u0001\u0000\u0000\u0000\\]\u0005)\u0000\u0000]^\u0006\b"+
		"\b\u0000^\u0012\u0001\u0000\u0000\u0000_`\u0005:\u0000\u0000`a\u0006\t"+
		"\t\u0000a\u0014\u0001\u0000\u0000\u0000bc\u0005*\u0000\u0000cd\u0006\n"+
		"\n\u0000d\u0016\u0001\u0000\u0000\u0000ef\u0005;\u0000\u0000fg\u0006\u000b"+
		"\u000b\u0000g\u0018\u0001\u0000\u0000\u0000hi\u0005=\u0000\u0000ij\u0006"+
		"\f\f\u0000j\u001a\u0001\u0000\u0000\u0000kl\u0005\n\u0000\u0000lm\u0006"+
		"\r\r\u0000m\u001c\u0001\u0000\u0000\u0000no\u0007\u0002\u0000\u0000op"+
		"\u0006\u000e\u000e\u0000pq\u0001\u0000\u0000\u0000qr\u0006\u000e\u000f"+
		"\u0000r\u001e\u0001\u0000\u0000\u0000st\u0004\u000f\u0000\u0000tu\u0005"+
		"+\u0000\u0000uv\u0006\u000f\u0010\u0000v \u0001\u0000\u0000\u0000wx\u0005"+
		"+\u0000\u0000xy\u0006\u0010\u0011\u0000y\"\u0001\u0000\u0000\u0000z{\u0004"+
		"\u0011\u0001\u0000{|\u0005-\u0000\u0000|}\u0006\u0011\u0012\u0000}$\u0001"+
		"\u0000\u0000\u0000~\u007f\u0005-\u0000\u0000\u007f\u0080\u0006\u0012\u0013"+
		"\u0000\u0080&\u0001\u0000\u0000\u0000\u0081\u0082\u0004\u0013\u0002\u0000"+
		"\u0082\u0083\u0005(\u0000\u0000\u0083\u0084\u0006\u0013\u0014\u0000\u0084"+
		"(\u0001\u0000\u0000\u0000\u0085\u0086\u0004\u0014\u0003\u0000\u0086\u0087"+
		"\u0005(\u0000\u0000\u0087\u0088\u0006\u0014\u0015\u0000\u0088*\u0001\u0000"+
		"\u0000\u0000\u0003\u0000.Q\u0016\u0001\u0000\u0000\u0001\u0001\u0001\u0001"+
		"\u0002\u0002\u0001\u0003\u0003\u0001\u0004\u0004\u0001\u0005\u0005\u0001"+
		"\u0006\u0006\u0001\u0007\u0007\u0001\b\b\u0001\t\t\u0001\n\n\u0001\u000b"+
		"\u000b\u0001\f\f\u0001\r\r\u0001\u000e\u000e\u0000\u0001\u0000\u0001\u000f"+
		"\u000f\u0001\u0010\u0010\u0001\u0011\u0011\u0001\u0012\u0012\u0001\u0013"+
		"\u0013\u0001\u0014\u0014";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}