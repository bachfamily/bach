// Generated from /Users/aa/Documents/Max 8/Packages/bach/source/commons/bell/antlrparser/include.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class include extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		DONTLOOKHERE=1, INCLUDE=2, ANY=3, CLOSE=4, FILENAME=5;
	public static final int
		RULE_code = 0, RULE_transcribe = 1, RULE_include = 2;
	private static String[] makeRuleNames() {
		return new String[] {
			"code", "transcribe", "include"
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

	@Override
	public String getGrammarFileName() { return "include.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public include(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CodeContext extends ParserRuleContext {
		public List<TranscribeContext> transcribe() {
			return getRuleContexts(TranscribeContext.class);
		}
		public TranscribeContext transcribe(int i) {
			return getRuleContext(TranscribeContext.class,i);
		}
		public List<IncludeContext> include() {
			return getRuleContexts(IncludeContext.class);
		}
		public IncludeContext include(int i) {
			return getRuleContext(IncludeContext.class,i);
		}
		public CodeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_code; }
	}

	public final CodeContext code() throws RecognitionException {
		CodeContext _localctx = new CodeContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_code);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(10);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 14L) != 0)) {
				{
				setState(8);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case DONTLOOKHERE:
				case ANY:
					{
					setState(6);
					transcribe();
					}
					break;
				case INCLUDE:
					{
					setState(7);
					include();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(12);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TranscribeContext extends ParserRuleContext {
		public Token DONTLOOKHERE;
		public Token ANY;
		public TerminalNode DONTLOOKHERE() { return getToken(include.DONTLOOKHERE, 0); }
		public TerminalNode ANY() { return getToken(include.ANY, 0); }
		public TranscribeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_transcribe; }
	}

	public final TranscribeContext transcribe() throws RecognitionException {
		TranscribeContext _localctx = new TranscribeContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_transcribe);
		try {
			setState(17);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case DONTLOOKHERE:
				enterOuterAlt(_localctx, 1);
				{
				setState(13);
				((TranscribeContext)_localctx).DONTLOOKHERE = match(DONTLOOKHERE);
				 output += (((TranscribeContext)_localctx).DONTLOOKHERE!=null?((TranscribeContext)_localctx).DONTLOOKHERE.getText():null); 
				}
				break;
			case ANY:
				enterOuterAlt(_localctx, 2);
				{
				setState(15);
				((TranscribeContext)_localctx).ANY = match(ANY);
				 output += (((TranscribeContext)_localctx).ANY!=null?((TranscribeContext)_localctx).ANY.getText():null); 
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IncludeContext extends ParserRuleContext {
		public Token FILENAME;
		public TerminalNode INCLUDE() { return getToken(include.INCLUDE, 0); }
		public TerminalNode FILENAME() { return getToken(include.FILENAME, 0); }
		public TerminalNode CLOSE() { return getToken(include.CLOSE, 0); }
		public IncludeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_include; }
	}

	public final IncludeContext include() throws RecognitionException {
		IncludeContext _localctx = new IncludeContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_include);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(19);
			match(INCLUDE);
			setState(20);
			((IncludeContext)_localctx).FILENAME = match(FILENAME);
			setState(21);
			match(CLOSE);
			 output += '---should include' + (((IncludeContext)_localctx).FILENAME!=null?((IncludeContext)_localctx).FILENAME.getText():null) + '---' 
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\u0004\u0001\u0005\u0019\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001"+
		"\u0002\u0002\u0007\u0002\u0001\u0000\u0001\u0000\u0005\u0000\t\b\u0000"+
		"\n\u0000\f\u0000\f\t\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0003\u0001\u0012\b\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0000\u0000\u0003\u0000\u0002\u0004\u0000\u0000"+
		"\u0018\u0000\n\u0001\u0000\u0000\u0000\u0002\u0011\u0001\u0000\u0000\u0000"+
		"\u0004\u0013\u0001\u0000\u0000\u0000\u0006\t\u0003\u0002\u0001\u0000\u0007"+
		"\t\u0003\u0004\u0002\u0000\b\u0006\u0001\u0000\u0000\u0000\b\u0007\u0001"+
		"\u0000\u0000\u0000\t\f\u0001\u0000\u0000\u0000\n\b\u0001\u0000\u0000\u0000"+
		"\n\u000b\u0001\u0000\u0000\u0000\u000b\u0001\u0001\u0000\u0000\u0000\f"+
		"\n\u0001\u0000\u0000\u0000\r\u000e\u0005\u0001\u0000\u0000\u000e\u0012"+
		"\u0006\u0001\uffff\uffff\u0000\u000f\u0010\u0005\u0003\u0000\u0000\u0010"+
		"\u0012\u0006\u0001\uffff\uffff\u0000\u0011\r\u0001\u0000\u0000\u0000\u0011"+
		"\u000f\u0001\u0000\u0000\u0000\u0012\u0003\u0001\u0000\u0000\u0000\u0013"+
		"\u0014\u0005\u0002\u0000\u0000\u0014\u0015\u0005\u0005\u0000\u0000\u0015"+
		"\u0016\u0005\u0004\u0000\u0000\u0016\u0017\u0006\u0002\uffff\uffff\u0000"+
		"\u0017\u0005\u0001\u0000\u0000\u0000\u0003\b\n\u0011";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}