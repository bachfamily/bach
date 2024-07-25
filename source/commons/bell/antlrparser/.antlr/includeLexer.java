// Generated from /Users/aa/Documents/Max 8/Packages/bach/source/commons/bell/antlrparser/includeLexer.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class includeLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		DONTLOOKHERE=1, INCLUDE=2, ANY=3, CLOSE=4, FILENAME=5;
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
			"DONTLOOKHERE", "INCLUDE", "ANY", "CLOSE", "FILENAME"
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
			null, "DONTLOOKHERE", "INCLUDE", "ANY", "CLOSE", "FILENAME"
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


	public includeLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "includeLexer.g4"; }

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

	public static final String _serializedATN =
		"\u0004\u0000\u0005h\u0006\uffff\uffff\u0006\uffff\uffff\u0002\u0000\u0007"+
		"\u0000\u0002\u0001\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007"+
		"\u0003\u0002\u0004\u0007\u0004\u0001\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0000\u0005\u0000\u0011\b\u0000\n\u0000\f\u0000\u0014\t\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0005\u0000"+
		"\u001c\b\u0000\n\u0000\f\u0000\u001f\t\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0000\u0001\u0000\u0005\u0000+\b\u0000\n\u0000\f\u0000.\t\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0003"+
		"\u00006\b\u0000\u0001\u0000\u0005\u00009\b\u0000\n\u0000\f\u0000<\t\u0000"+
		"\u0001\u0000\u0003\u0000?\b\u0000\u0003\u0000A\b\u0000\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0005\u0001L\b\u0001\n\u0001\f\u0001O\t\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0002\u0004\u0002V\b"+
		"\u0002\u000b\u0002\f\u0002W\u0001\u0003\u0005\u0003[\b\u0003\n\u0003\f"+
		"\u0003^\t\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001"+
		"\u0004\u0004\u0004e\b\u0004\u000b\u0004\f\u0004f\u0004,:Wf\u0000\u0005"+
		"\u0002\u0001\u0004\u0002\u0006\u0003\b\u0004\n\u0005\u0002\u0000\u0001"+
		"\u0005\u0001\u0000\"\"\u0001\u0000\\\\\u0001\u0000\'\'\u0001\u0001\n\n"+
		"\u0003\u0000\u0001\u0001\t\t  v\u0000\u0002\u0001\u0000\u0000\u0000\u0000"+
		"\u0004\u0001\u0000\u0000\u0000\u0000\u0006\u0001\u0000\u0000\u0000\u0001"+
		"\b\u0001\u0000\u0000\u0000\u0001\n\u0001\u0000\u0000\u0000\u0002@\u0001"+
		"\u0000\u0000\u0000\u0004B\u0001\u0000\u0000\u0000\u0006U\u0001\u0000\u0000"+
		"\u0000\b\\\u0001\u0000\u0000\u0000\nd\u0001\u0000\u0000\u0000\f\u0012"+
		"\u0005\"\u0000\u0000\r\u000e\u0005\\\u0000\u0000\u000e\u0011\u0005\"\u0000"+
		"\u0000\u000f\u0011\b\u0000\u0000\u0000\u0010\r\u0001\u0000\u0000\u0000"+
		"\u0010\u000f\u0001\u0000\u0000\u0000\u0011\u0014\u0001\u0000\u0000\u0000"+
		"\u0012\u0010\u0001\u0000\u0000\u0000\u0012\u0013\u0001\u0000\u0000\u0000"+
		"\u0013\u0015\u0001\u0000\u0000\u0000\u0014\u0012\u0001\u0000\u0000\u0000"+
		"\u0015\u0016\b\u0001\u0000\u0000\u0016A\u0005\"\u0000\u0000\u0017\u001d"+
		"\u0005\'\u0000\u0000\u0018\u0019\u0005\\\u0000\u0000\u0019\u001c\u0005"+
		"\'\u0000\u0000\u001a\u001c\b\u0002\u0000\u0000\u001b\u0018\u0001\u0000"+
		"\u0000\u0000\u001b\u001a\u0001\u0000\u0000\u0000\u001c\u001f\u0001\u0000"+
		"\u0000\u0000\u001d\u001b\u0001\u0000\u0000\u0000\u001d\u001e\u0001\u0000"+
		"\u0000\u0000\u001e \u0001\u0000\u0000\u0000\u001f\u001d\u0001\u0000\u0000"+
		"\u0000 !\b\u0001\u0000\u0000!A\u0005\'\u0000\u0000\"#\u0005\"\u0000\u0000"+
		"#A\u0005\"\u0000\u0000$%\u0005\'\u0000\u0000%A\u0005\'\u0000\u0000&\'"+
		"\u0005#\u0000\u0000\'(\u0005(\u0000\u0000(,\u0001\u0000\u0000\u0000)+"+
		"\t\u0000\u0000\u0000*)\u0001\u0000\u0000\u0000+.\u0001\u0000\u0000\u0000"+
		",-\u0001\u0000\u0000\u0000,*\u0001\u0000\u0000\u0000-/\u0001\u0000\u0000"+
		"\u0000.,\u0001\u0000\u0000\u0000/0\u0005#\u0000\u00000A\u0005)\u0000\u0000"+
		"12\u0005#\u0000\u000026\u0005#\u0000\u000034\u0005#\u0000\u000046\u0005"+
		"!\u0000\u000051\u0001\u0000\u0000\u000053\u0001\u0000\u0000\u00006:\u0001"+
		"\u0000\u0000\u000079\t\u0000\u0000\u000087\u0001\u0000\u0000\u00009<\u0001"+
		"\u0000\u0000\u0000:;\u0001\u0000\u0000\u0000:8\u0001\u0000\u0000\u0000"+
		";>\u0001\u0000\u0000\u0000<:\u0001\u0000\u0000\u0000=?\u0007\u0003\u0000"+
		"\u0000>=\u0001\u0000\u0000\u0000?A\u0001\u0000\u0000\u0000@\f\u0001\u0000"+
		"\u0000\u0000@\u0017\u0001\u0000\u0000\u0000@\"\u0001\u0000\u0000\u0000"+
		"@$\u0001\u0000\u0000\u0000@&\u0001\u0000\u0000\u0000@5\u0001\u0000\u0000"+
		"\u0000A\u0003\u0001\u0000\u0000\u0000BC\u0005i\u0000\u0000CD\u0005n\u0000"+
		"\u0000DE\u0005c\u0000\u0000EF\u0005l\u0000\u0000FG\u0005u\u0000\u0000"+
		"GH\u0005d\u0000\u0000HI\u0005e\u0000\u0000IM\u0001\u0000\u0000\u0000J"+
		"L\u0007\u0004\u0000\u0000KJ\u0001\u0000\u0000\u0000LO\u0001\u0000\u0000"+
		"\u0000MK\u0001\u0000\u0000\u0000MN\u0001\u0000\u0000\u0000NP\u0001\u0000"+
		"\u0000\u0000OM\u0001\u0000\u0000\u0000PQ\u0005(\u0000\u0000QR\u0001\u0000"+
		"\u0000\u0000RS\u0006\u0001\u0000\u0000S\u0005\u0001\u0000\u0000\u0000"+
		"TV\t\u0000\u0000\u0000UT\u0001\u0000\u0000\u0000VW\u0001\u0000\u0000\u0000"+
		"WX\u0001\u0000\u0000\u0000WU\u0001\u0000\u0000\u0000X\u0007\u0001\u0000"+
		"\u0000\u0000Y[\u0007\u0004\u0000\u0000ZY\u0001\u0000\u0000\u0000[^\u0001"+
		"\u0000\u0000\u0000\\Z\u0001\u0000\u0000\u0000\\]\u0001\u0000\u0000\u0000"+
		"]_\u0001\u0000\u0000\u0000^\\\u0001\u0000\u0000\u0000_`\u0005)\u0000\u0000"+
		"`a\u0001\u0000\u0000\u0000ab\u0006\u0003\u0001\u0000b\t\u0001\u0000\u0000"+
		"\u0000ce\t\u0000\u0000\u0000dc\u0001\u0000\u0000\u0000ef\u0001\u0000\u0000"+
		"\u0000fg\u0001\u0000\u0000\u0000fd\u0001\u0000\u0000\u0000g\u000b\u0001"+
		"\u0000\u0000\u0000\u000f\u0000\u0001\u0010\u0012\u001b\u001d,5:>@MW\\"+
		"f\u0002\u0002\u0001\u0000\u0002\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}