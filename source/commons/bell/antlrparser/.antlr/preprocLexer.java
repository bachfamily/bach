// Generated from /Users/aa/Documents/Max 8/Packages/bach/source/commons/bell/antlrparser/preprocLexer.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class preprocLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		DONTLOOKHERE=1, WHITESPACE=2, INCLUDE=3, ANY=4, CLOSE=5, FILENAME=6;
	public static final int
		INCLUDE_MODE=1;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE", "INCLUDE_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"DONTLOOKHERE", "WHITESPACE", "INCLUDE", "ANY", "CLOSE", "FILENAME"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "DONTLOOKHERE", "WHITESPACE", "INCLUDE", "ANY", "CLOSE", "FILENAME"
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


	    bool noInclude;


	public preprocLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "preprocLexer.g4"; }

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
			DONTLOOKHERE_action((RuleContext)_localctx, actionIndex);
			break;
		case 1:
			WHITESPACE_action((RuleContext)_localctx, actionIndex);
			break;
		case 3:
			ANY_action((RuleContext)_localctx, actionIndex);
			break;
		case 4:
			CLOSE_action((RuleContext)_localctx, actionIndex);
			break;
		}
	}
	private void DONTLOOKHERE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 0:
			 noInclude = true; 
			break;
		}
	}
	private void WHITESPACE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 1:
			 noInclude = false; 
			break;
		}
	}
	private void ANY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 2:
			 noInclude = true; 
			break;
		}
	}
	private void CLOSE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 3:
			 noInclude = true; 
			break;
		}
	}
	@Override
	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 2:
			return INCLUDE_sempred((RuleContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean INCLUDE_sempred(RuleContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return  !noInclude ;
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0000\u0006w\u0006\uffff\uffff\u0006\uffff\uffff\u0002\u0000\u0007"+
		"\u0000\u0002\u0001\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007"+
		"\u0003\u0002\u0004\u0007\u0004\u0002\u0005\u0007\u0005\u0001\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0005\u0000\u0013\b\u0000\n\u0000\f\u0000"+
		"\u0016\t\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0005\u0000\u001e\b\u0000\n\u0000\f\u0000!\t\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0005\u0000-\b\u0000\n\u0000"+
		"\f\u00000\t\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0000\u0001\u0000\u0003\u00008\b\u0000\u0001\u0000\u0005\u0000;\b\u0000"+
		"\n\u0000\f\u0000>\t\u0000\u0001\u0000\u0003\u0000A\b\u0000\u0003\u0000"+
		"C\b\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0004\u0001H\b\u0001\u000b"+
		"\u0001\f\u0001I\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0005\u0002X\b\u0002\n\u0002\f\u0002[\t\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0003\u0004\u0003b\b"+
		"\u0003\u000b\u0003\f\u0003c\u0001\u0003\u0001\u0003\u0001\u0004\u0005"+
		"\u0004i\b\u0004\n\u0004\f\u0004l\t\u0004\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0005\u0004\u0005t\b\u0005\u000b"+
		"\u0005\f\u0005u\u0003.<c\u0000\u0006\u0002\u0001\u0004\u0002\u0006\u0003"+
		"\b\u0004\n\u0005\f\u0006\u0002\u0000\u0001\u0007\u0001\u0000\"\"\u0001"+
		"\u0000\\\\\u0001\u0000\'\'\u0001\u0001\n\n\u0004\u0000\u0001\u0001\t\n"+
		"\r\r  \u0003\u0000\u0001\u0001\t\t  \u0001\u0000))\u0086\u0000\u0002\u0001"+
		"\u0000\u0000\u0000\u0000\u0004\u0001\u0000\u0000\u0000\u0000\u0006\u0001"+
		"\u0000\u0000\u0000\u0000\b\u0001\u0000\u0000\u0000\u0001\n\u0001\u0000"+
		"\u0000\u0000\u0001\f\u0001\u0000\u0000\u0000\u0002B\u0001\u0000\u0000"+
		"\u0000\u0004G\u0001\u0000\u0000\u0000\u0006M\u0001\u0000\u0000\u0000\b"+
		"a\u0001\u0000\u0000\u0000\nj\u0001\u0000\u0000\u0000\fs\u0001\u0000\u0000"+
		"\u0000\u000e\u0014\u0005\"\u0000\u0000\u000f\u0010\u0005\\\u0000\u0000"+
		"\u0010\u0013\u0005\"\u0000\u0000\u0011\u0013\b\u0000\u0000\u0000\u0012"+
		"\u000f\u0001\u0000\u0000\u0000\u0012\u0011\u0001\u0000\u0000\u0000\u0013"+
		"\u0016\u0001\u0000\u0000\u0000\u0014\u0012\u0001\u0000\u0000\u0000\u0014"+
		"\u0015\u0001\u0000\u0000\u0000\u0015\u0017\u0001\u0000\u0000\u0000\u0016"+
		"\u0014\u0001\u0000\u0000\u0000\u0017\u0018\b\u0001\u0000\u0000\u0018C"+
		"\u0005\"\u0000\u0000\u0019\u001f\u0005\'\u0000\u0000\u001a\u001b\u0005"+
		"\\\u0000\u0000\u001b\u001e\u0005\'\u0000\u0000\u001c\u001e\b\u0002\u0000"+
		"\u0000\u001d\u001a\u0001\u0000\u0000\u0000\u001d\u001c\u0001\u0000\u0000"+
		"\u0000\u001e!\u0001\u0000\u0000\u0000\u001f\u001d\u0001\u0000\u0000\u0000"+
		"\u001f \u0001\u0000\u0000\u0000 \"\u0001\u0000\u0000\u0000!\u001f\u0001"+
		"\u0000\u0000\u0000\"#\b\u0001\u0000\u0000#C\u0005\'\u0000\u0000$%\u0005"+
		"\"\u0000\u0000%C\u0005\"\u0000\u0000&\'\u0005\'\u0000\u0000\'C\u0005\'"+
		"\u0000\u0000()\u0005#\u0000\u0000)*\u0005(\u0000\u0000*.\u0001\u0000\u0000"+
		"\u0000+-\t\u0000\u0000\u0000,+\u0001\u0000\u0000\u0000-0\u0001\u0000\u0000"+
		"\u0000./\u0001\u0000\u0000\u0000.,\u0001\u0000\u0000\u0000/1\u0001\u0000"+
		"\u0000\u00000.\u0001\u0000\u0000\u000012\u0005)\u0000\u00002C\u0005#\u0000"+
		"\u000034\u0005#\u0000\u000048\u0005#\u0000\u000056\u0005#\u0000\u0000"+
		"68\u0005!\u0000\u000073\u0001\u0000\u0000\u000075\u0001\u0000\u0000\u0000"+
		"8<\u0001\u0000\u0000\u00009;\t\u0000\u0000\u0000:9\u0001\u0000\u0000\u0000"+
		";>\u0001\u0000\u0000\u0000<=\u0001\u0000\u0000\u0000<:\u0001\u0000\u0000"+
		"\u0000=@\u0001\u0000\u0000\u0000><\u0001\u0000\u0000\u0000?A\u0007\u0003"+
		"\u0000\u0000@?\u0001\u0000\u0000\u0000AC\u0001\u0000\u0000\u0000B\u000e"+
		"\u0001\u0000\u0000\u0000B\u0019\u0001\u0000\u0000\u0000B$\u0001\u0000"+
		"\u0000\u0000B&\u0001\u0000\u0000\u0000B(\u0001\u0000\u0000\u0000B7\u0001"+
		"\u0000\u0000\u0000CD\u0001\u0000\u0000\u0000DE\u0006\u0000\u0000\u0000"+
		"E\u0003\u0001\u0000\u0000\u0000FH\u0007\u0004\u0000\u0000GF\u0001\u0000"+
		"\u0000\u0000HI\u0001\u0000\u0000\u0000IG\u0001\u0000\u0000\u0000IJ\u0001"+
		"\u0000\u0000\u0000JK\u0001\u0000\u0000\u0000KL\u0006\u0001\u0001\u0000"+
		"L\u0005\u0001\u0000\u0000\u0000MN\u0004\u0002\u0000\u0000NO\u0005i\u0000"+
		"\u0000OP\u0005n\u0000\u0000PQ\u0005c\u0000\u0000QR\u0005l\u0000\u0000"+
		"RS\u0005u\u0000\u0000ST\u0005d\u0000\u0000TU\u0005e\u0000\u0000UY\u0001"+
		"\u0000\u0000\u0000VX\u0007\u0005\u0000\u0000WV\u0001\u0000\u0000\u0000"+
		"X[\u0001\u0000\u0000\u0000YW\u0001\u0000\u0000\u0000YZ\u0001\u0000\u0000"+
		"\u0000Z\\\u0001\u0000\u0000\u0000[Y\u0001\u0000\u0000\u0000\\]\u0005("+
		"\u0000\u0000]^\u0001\u0000\u0000\u0000^_\u0006\u0002\u0002\u0000_\u0007"+
		"\u0001\u0000\u0000\u0000`b\t\u0000\u0000\u0000a`\u0001\u0000\u0000\u0000"+
		"bc\u0001\u0000\u0000\u0000cd\u0001\u0000\u0000\u0000ca\u0001\u0000\u0000"+
		"\u0000de\u0001\u0000\u0000\u0000ef\u0006\u0003\u0003\u0000f\t\u0001\u0000"+
		"\u0000\u0000gi\u0007\u0005\u0000\u0000hg\u0001\u0000\u0000\u0000il\u0001"+
		"\u0000\u0000\u0000jh\u0001\u0000\u0000\u0000jk\u0001\u0000\u0000\u0000"+
		"km\u0001\u0000\u0000\u0000lj\u0001\u0000\u0000\u0000mn\u0005)\u0000\u0000"+
		"no\u0006\u0004\u0004\u0000op\u0001\u0000\u0000\u0000pq\u0006\u0004\u0005"+
		"\u0000q\u000b\u0001\u0000\u0000\u0000rt\b\u0006\u0000\u0000sr\u0001\u0000"+
		"\u0000\u0000tu\u0001\u0000\u0000\u0000us\u0001\u0000\u0000\u0000uv\u0001"+
		"\u0000\u0000\u0000v\r\u0001\u0000\u0000\u0000\u0010\u0000\u0001\u0012"+
		"\u0014\u001d\u001f.7<@BIYcju\u0006\u0001\u0000\u0000\u0001\u0001\u0001"+
		"\u0002\u0001\u0000\u0001\u0003\u0002\u0001\u0004\u0003\u0002\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}