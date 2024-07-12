// Generated from /Users/aa/Documents/Max 8/Packages/bach/source/commons/bell/antlrparser/pitch.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class pitchParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, UINT=3, NOTENAME=4, ACCIDENTAL=5, UPLUS=6, UMINUS=7;
	public static final int
		RULE_pch = 0, RULE_dev = 1, RULE_urat = 2;
	private static String[] makeRuleNames() {
		return new String[] {
			"pch", "dev", "urat"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'t'", "'/'", null, null, null, "'+'", "'-'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, "UINT", "NOTENAME", "ACCIDENTAL", "UPLUS", "UMINUS"
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
	public String getGrammarFileName() { return "pitch.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public pitchParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class PchContext extends ParserRuleContext {
		public TerminalNode NOTENAME() { return getToken(pitchParser.NOTENAME, 0); }
		public TerminalNode UINT() { return getToken(pitchParser.UINT, 0); }
		public TerminalNode EOF() { return getToken(pitchParser.EOF, 0); }
		public TerminalNode ACCIDENTAL() { return getToken(pitchParser.ACCIDENTAL, 0); }
		public DevContext dev() {
			return getRuleContext(DevContext.class,0);
		}
		public List<TerminalNode> UPLUS() { return getTokens(pitchParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(pitchParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(pitchParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(pitchParser.UMINUS, i);
		}
		public PchContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pch; }
	}

	public final PchContext pch() throws RecognitionException {
		PchContext _localctx = new PchContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_pch);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(6);
			match(NOTENAME);
			setState(8);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ACCIDENTAL) {
				{
				setState(7);
				match(ACCIDENTAL);
				}
			}

			setState(13);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==UPLUS || _la==UMINUS) {
				{
				{
				setState(10);
				_la = _input.LA(1);
				if ( !(_la==UPLUS || _la==UMINUS) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				}
				setState(15);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(16);
			match(UINT);
			setState(18);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 200L) != 0)) {
				{
				setState(17);
				dev();
				}
			}

			setState(20);
			match(EOF);
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
	public static class DevContext extends ParserRuleContext {
		public DevContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_dev; }
	 
		public DevContext() { }
		public void copyFrom(DevContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DevIntContext extends DevContext {
		public TerminalNode UINT() { return getToken(pitchParser.UINT, 0); }
		public List<TerminalNode> UPLUS() { return getTokens(pitchParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(pitchParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(pitchParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(pitchParser.UMINUS, i);
		}
		public DevIntContext(DevContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DevRatContext extends DevContext {
		public UratContext urat() {
			return getRuleContext(UratContext.class,0);
		}
		public List<TerminalNode> UPLUS() { return getTokens(pitchParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(pitchParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(pitchParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(pitchParser.UMINUS, i);
		}
		public DevRatContext(DevContext ctx) { copyFrom(ctx); }
	}

	public final DevContext dev() throws RecognitionException {
		DevContext _localctx = new DevContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_dev);
		int _la;
		try {
			setState(41);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				_localctx = new DevIntContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(25);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==UPLUS || _la==UMINUS) {
					{
					{
					setState(22);
					_la = _input.LA(1);
					if ( !(_la==UPLUS || _la==UMINUS) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
					}
					setState(27);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(28);
				match(UINT);
				}
				setState(30);
				match(T__0);
				}
				break;
			case 2:
				_localctx = new DevRatContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(34);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==UPLUS || _la==UMINUS) {
					{
					{
					setState(31);
					_la = _input.LA(1);
					if ( !(_la==UPLUS || _la==UMINUS) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
					}
					setState(36);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(37);
				urat();
				}
				setState(39);
				match(T__0);
				}
				break;
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
	public static class UratContext extends ParserRuleContext {
		public List<TerminalNode> UINT() { return getTokens(pitchParser.UINT); }
		public TerminalNode UINT(int i) {
			return getToken(pitchParser.UINT, i);
		}
		public List<TerminalNode> UPLUS() { return getTokens(pitchParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(pitchParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(pitchParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(pitchParser.UMINUS, i);
		}
		public UratContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_urat; }
	}

	public final UratContext urat() throws RecognitionException {
		UratContext _localctx = new UratContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_urat);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(43);
			match(UINT);
			setState(44);
			match(T__1);
			setState(48);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==UPLUS || _la==UMINUS) {
				{
				{
				setState(45);
				_la = _input.LA(1);
				if ( !(_la==UPLUS || _la==UMINUS) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				}
				setState(50);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(51);
			match(UINT);
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
		"\u0004\u0001\u00076\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0001\u0000\u0001\u0000\u0003\u0000\t\b\u0000\u0001"+
		"\u0000\u0005\u0000\f\b\u0000\n\u0000\f\u0000\u000f\t\u0000\u0001\u0000"+
		"\u0001\u0000\u0003\u0000\u0013\b\u0000\u0001\u0000\u0001\u0000\u0001\u0001"+
		"\u0005\u0001\u0018\b\u0001\n\u0001\f\u0001\u001b\t\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0005\u0001!\b\u0001\n\u0001\f\u0001$\t"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0003\u0001*\b"+
		"\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0005\u0002/\b\u0002\n\u0002"+
		"\f\u00022\t\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0000\u0000\u0003"+
		"\u0000\u0002\u0004\u0000\u0001\u0001\u0000\u0006\u00079\u0000\u0006\u0001"+
		"\u0000\u0000\u0000\u0002)\u0001\u0000\u0000\u0000\u0004+\u0001\u0000\u0000"+
		"\u0000\u0006\b\u0005\u0004\u0000\u0000\u0007\t\u0005\u0005\u0000\u0000"+
		"\b\u0007\u0001\u0000\u0000\u0000\b\t\u0001\u0000\u0000\u0000\t\r\u0001"+
		"\u0000\u0000\u0000\n\f\u0007\u0000\u0000\u0000\u000b\n\u0001\u0000\u0000"+
		"\u0000\f\u000f\u0001\u0000\u0000\u0000\r\u000b\u0001\u0000\u0000\u0000"+
		"\r\u000e\u0001\u0000\u0000\u0000\u000e\u0010\u0001\u0000\u0000\u0000\u000f"+
		"\r\u0001\u0000\u0000\u0000\u0010\u0012\u0005\u0003\u0000\u0000\u0011\u0013"+
		"\u0003\u0002\u0001\u0000\u0012\u0011\u0001\u0000\u0000\u0000\u0012\u0013"+
		"\u0001\u0000\u0000\u0000\u0013\u0014\u0001\u0000\u0000\u0000\u0014\u0015"+
		"\u0005\u0000\u0000\u0001\u0015\u0001\u0001\u0000\u0000\u0000\u0016\u0018"+
		"\u0007\u0000\u0000\u0000\u0017\u0016\u0001\u0000\u0000\u0000\u0018\u001b"+
		"\u0001\u0000\u0000\u0000\u0019\u0017\u0001\u0000\u0000\u0000\u0019\u001a"+
		"\u0001\u0000\u0000\u0000\u001a\u001c\u0001\u0000\u0000\u0000\u001b\u0019"+
		"\u0001\u0000\u0000\u0000\u001c\u001d\u0005\u0003\u0000\u0000\u001d\u001e"+
		"\u0001\u0000\u0000\u0000\u001e*\u0005\u0001\u0000\u0000\u001f!\u0007\u0000"+
		"\u0000\u0000 \u001f\u0001\u0000\u0000\u0000!$\u0001\u0000\u0000\u0000"+
		"\" \u0001\u0000\u0000\u0000\"#\u0001\u0000\u0000\u0000#%\u0001\u0000\u0000"+
		"\u0000$\"\u0001\u0000\u0000\u0000%&\u0003\u0004\u0002\u0000&\'\u0001\u0000"+
		"\u0000\u0000\'(\u0005\u0001\u0000\u0000(*\u0001\u0000\u0000\u0000)\u0019"+
		"\u0001\u0000\u0000\u0000)\"\u0001\u0000\u0000\u0000*\u0003\u0001\u0000"+
		"\u0000\u0000+,\u0005\u0003\u0000\u0000,0\u0005\u0002\u0000\u0000-/\u0007"+
		"\u0000\u0000\u0000.-\u0001\u0000\u0000\u0000/2\u0001\u0000\u0000\u0000"+
		"0.\u0001\u0000\u0000\u000001\u0001\u0000\u0000\u000013\u0001\u0000\u0000"+
		"\u000020\u0001\u0000\u0000\u000034\u0005\u0003\u0000\u00004\u0005\u0001"+
		"\u0000\u0000\u0000\u0007\b\r\u0012\u0019\")0";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}