// Generated from /Users/aa/Documents/Max 8/Packages/bach/source/commons/parsers/antlrparser/parsetest.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class parsetestParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		NUMBER=1, IF=2, THEN=3, ELSE=4, FUNCTION=5, VAR=6, CLOSED=7, NTH=8, TIMES=9, 
		NULLIFY=10, ASSIGN=11, EOL=12, WHITESPACE=13, PLUS=14, UPLUS=15, MINUS=16, 
		UMINUS=17, OPEN=18, PARAMS=19;
	public static final int
		RULE_program = 0, RULE_sequence = 1, RULE_item = 2, RULE_var = 3, RULE_lvalueSpecs = 4, 
		RULE_lvalue = 5, RULE_fakeLvalue = 6, RULE_assignment = 7, RULE_reference = 8, 
		RULE_term = 9, RULE_expression = 10, RULE_list = 11, RULE_funcall = 12, 
		RULE_conditional = 13, RULE_nullify = 14;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "sequence", "item", "var", "lvalueSpecs", "lvalue", "fakeLvalue", 
			"assignment", "reference", "term", "expression", "list", "funcall", "conditional", 
			"nullify"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, "'if'", "'then'", "'else'", null, null, "')'", "':'", "'*'", 
			"';'", "'='", "'\\n'", null, null, "'+'", null, "'-'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "NUMBER", "IF", "THEN", "ELSE", "FUNCTION", "VAR", "CLOSED", "NTH", 
			"TIMES", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", "PLUS", "UPLUS", "MINUS", 
			"UMINUS", "OPEN", "PARAMS"
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
	public String getGrammarFileName() { return "parsetest.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public parsetestParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public SequenceContext sequence() {
			return getRuleContext(SequenceContext.class,0);
		}
		public TerminalNode EOF() { return getToken(parsetestParser.EOF, 0); }
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterProgram(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitProgram(this);
		}
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(30);
			sequence();
			setState(31);
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
	public static class SequenceContext extends ParserRuleContext {
		public List<ListContext> list() {
			return getRuleContexts(ListContext.class);
		}
		public ListContext list(int i) {
			return getRuleContext(ListContext.class,i);
		}
		public List<NullifyContext> nullify() {
			return getRuleContexts(NullifyContext.class);
		}
		public NullifyContext nullify(int i) {
			return getRuleContext(NullifyContext.class,i);
		}
		public SequenceContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sequence; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterSequence(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitSequence(this);
		}
	}

	public final SequenceContext sequence() throws RecognitionException {
		SequenceContext _localctx = new SequenceContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_sequence);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(37); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(33);
				list();
				setState(35);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==NULLIFY) {
					{
					setState(34);
					nullify();
					}
				}

				}
				}
				setState(39); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & 426086L) != 0) );
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
	public static class ItemContext extends ParserRuleContext {
		public ItemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_item; }
	 
		public ItemContext() { }
		public void copyFrom(ItemContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemNumberContext extends ItemContext {
		public TerminalNode NUMBER() { return getToken(parsetestParser.NUMBER, 0); }
		public ItemNumberContext(ItemContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterItemNumber(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitItemNumber(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemSequenceContext extends ItemContext {
		public TerminalNode OPEN() { return getToken(parsetestParser.OPEN, 0); }
		public SequenceContext sequence() {
			return getRuleContext(SequenceContext.class,0);
		}
		public TerminalNode CLOSED() { return getToken(parsetestParser.CLOSED, 0); }
		public ItemSequenceContext(ItemContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterItemSequence(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitItemSequence(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemFuncallContext extends ItemContext {
		public FuncallContext funcall() {
			return getRuleContext(FuncallContext.class,0);
		}
		public ItemFuncallContext(ItemContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterItemFuncall(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitItemFuncall(this);
		}
	}

	public final ItemContext item() throws RecognitionException {
		ItemContext _localctx = new ItemContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_item);
		try {
			setState(47);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUMBER:
				_localctx = new ItemNumberContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(41);
				match(NUMBER);
				}
				break;
			case OPEN:
				_localctx = new ItemSequenceContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(42);
				match(OPEN);
				setState(43);
				sequence();
				setState(44);
				match(CLOSED);
				}
				break;
			case FUNCTION:
			case UPLUS:
			case UMINUS:
				_localctx = new ItemFuncallContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(46);
				funcall();
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
	public static class VarContext extends ParserRuleContext {
		public TerminalNode VAR() { return getToken(parsetestParser.VAR, 0); }
		public VarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterVar(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitVar(this);
		}
	}

	public final VarContext var() throws RecognitionException {
		VarContext _localctx = new VarContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_var);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(49);
			match(VAR);
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
	public static class LvalueSpecsContext extends ParserRuleContext {
		public List<TerminalNode> NTH() { return getTokens(parsetestParser.NTH); }
		public TerminalNode NTH(int i) {
			return getToken(parsetestParser.NTH, i);
		}
		public List<ItemContext> item() {
			return getRuleContexts(ItemContext.class);
		}
		public ItemContext item(int i) {
			return getRuleContext(ItemContext.class,i);
		}
		public List<VarContext> var() {
			return getRuleContexts(VarContext.class);
		}
		public VarContext var(int i) {
			return getRuleContext(VarContext.class,i);
		}
		public List<ConditionalContext> conditional() {
			return getRuleContexts(ConditionalContext.class);
		}
		public ConditionalContext conditional(int i) {
			return getRuleContext(ConditionalContext.class,i);
		}
		public List<NullifyContext> nullify() {
			return getRuleContexts(NullifyContext.class);
		}
		public NullifyContext nullify(int i) {
			return getRuleContext(NullifyContext.class,i);
		}
		public LvalueSpecsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lvalueSpecs; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterLvalueSpecs(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitLvalueSpecs(this);
		}
	}

	public final LvalueSpecsContext lvalueSpecs() throws RecognitionException {
		LvalueSpecsContext _localctx = new LvalueSpecsContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_lvalueSpecs);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(60); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(52);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==NULLIFY) {
						{
						setState(51);
						nullify();
						}
					}

					setState(54);
					match(NTH);
					setState(58);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
					case 1:
						{
						setState(55);
						item();
						}
						break;
					case 2:
						{
						setState(56);
						var();
						}
						break;
					case 3:
						{
						setState(57);
						conditional();
						}
						break;
					}
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(62); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
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
	public static class LvalueContext extends ParserRuleContext {
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public LvalueSpecsContext lvalueSpecs() {
			return getRuleContext(LvalueSpecsContext.class,0);
		}
		public LvalueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lvalue; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterLvalue(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitLvalue(this);
		}
	}

	public final LvalueContext lvalue() throws RecognitionException {
		LvalueContext _localctx = new LvalueContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_lvalue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(64);
			var();
			setState(66);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				{
				setState(65);
				lvalueSpecs();
				}
				break;
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
	public static class FakeLvalueContext extends ParserRuleContext {
		public ItemContext item() {
			return getRuleContext(ItemContext.class,0);
		}
		public LvalueSpecsContext lvalueSpecs() {
			return getRuleContext(LvalueSpecsContext.class,0);
		}
		public FakeLvalueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fakeLvalue; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterFakeLvalue(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitFakeLvalue(this);
		}
	}

	public final FakeLvalueContext fakeLvalue() throws RecognitionException {
		FakeLvalueContext _localctx = new FakeLvalueContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_fakeLvalue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(68);
			item();
			setState(69);
			lvalueSpecs();
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
	public static class AssignmentContext extends ParserRuleContext {
		public TerminalNode ASSIGN() { return getToken(parsetestParser.ASSIGN, 0); }
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public LvalueContext lvalue() {
			return getRuleContext(LvalueContext.class,0);
		}
		public FakeLvalueContext fakeLvalue() {
			return getRuleContext(FakeLvalueContext.class,0);
		}
		public List<TerminalNode> UPLUS() { return getTokens(parsetestParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(parsetestParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(parsetestParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(parsetestParser.UMINUS, i);
		}
		public AssignmentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignment; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterAssignment(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitAssignment(this);
		}
	}

	public final AssignmentContext assignment() throws RecognitionException {
		AssignmentContext _localctx = new AssignmentContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_assignment);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(74);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(71);
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
				}
				setState(76);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			}
			setState(79);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case VAR:
				{
				setState(77);
				lvalue();
				}
				break;
			case NUMBER:
			case FUNCTION:
			case UPLUS:
			case UMINUS:
			case OPEN:
				{
				setState(78);
				fakeLvalue();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(81);
			match(ASSIGN);
			setState(82);
			list();
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
	public static class ReferenceContext extends ParserRuleContext {
		public LvalueContext lvalue() {
			return getRuleContext(LvalueContext.class,0);
		}
		public FakeLvalueContext fakeLvalue() {
			return getRuleContext(FakeLvalueContext.class,0);
		}
		public ReferenceContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_reference; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterReference(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitReference(this);
		}
	}

	public final ReferenceContext reference() throws RecognitionException {
		ReferenceContext _localctx = new ReferenceContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_reference);
		try {
			setState(86);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case VAR:
				enterOuterAlt(_localctx, 1);
				{
				setState(84);
				lvalue();
				}
				break;
			case NUMBER:
			case FUNCTION:
			case UPLUS:
			case UMINUS:
			case OPEN:
				enterOuterAlt(_localctx, 2);
				{
				setState(85);
				fakeLvalue();
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
	public static class TermContext extends ParserRuleContext {
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
	 
		public TermContext() { }
		public void copyFrom(TermContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemTermContext extends TermContext {
		public ItemContext item() {
			return getRuleContext(ItemContext.class,0);
		}
		public List<TerminalNode> UPLUS() { return getTokens(parsetestParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(parsetestParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(parsetestParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(parsetestParser.UMINUS, i);
		}
		public ItemTermContext(TermContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterItemTerm(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitItemTerm(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ReferenceTermContext extends TermContext {
		public ReferenceContext reference() {
			return getRuleContext(ReferenceContext.class,0);
		}
		public List<TerminalNode> UPLUS() { return getTokens(parsetestParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(parsetestParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(parsetestParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(parsetestParser.UMINUS, i);
		}
		public ReferenceTermContext(TermContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterReferenceTerm(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitReferenceTerm(this);
		}
	}

	public final TermContext term() throws RecognitionException {
		TermContext _localctx = new TermContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_term);
		int _la;
		try {
			int _alt;
			setState(102);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				_localctx = new ItemTermContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(91);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(88);
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
					}
					setState(93);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
				}
				setState(94);
				item();
				}
				break;
			case 2:
				_localctx = new ReferenceTermContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(98);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(95);
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
					}
					setState(100);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
				}
				setState(101);
				reference();
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
	public static class ExpressionContext extends ParserRuleContext {
		public List<TermContext> term() {
			return getRuleContexts(TermContext.class);
		}
		public TermContext term(int i) {
			return getRuleContext(TermContext.class,i);
		}
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public List<TerminalNode> PLUS() { return getTokens(parsetestParser.PLUS); }
		public TerminalNode PLUS(int i) {
			return getToken(parsetestParser.PLUS, i);
		}
		public List<TerminalNode> MINUS() { return getTokens(parsetestParser.MINUS); }
		public TerminalNode MINUS(int i) {
			return getToken(parsetestParser.MINUS, i);
		}
		public List<NullifyContext> nullify() {
			return getRuleContexts(NullifyContext.class);
		}
		public NullifyContext nullify(int i) {
			return getRuleContext(NullifyContext.class,i);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitExpression(this);
		}
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_expression);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(104);
			term();
			setState(112);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(106);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==NULLIFY) {
						{
						setState(105);
						nullify();
						}
					}

					setState(108);
					_la = _input.LA(1);
					if ( !(_la==PLUS || _la==MINUS) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					setState(109);
					term();
					}
					} 
				}
				setState(114);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			}
			setState(120);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				{
				setState(116);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==NULLIFY) {
					{
					setState(115);
					nullify();
					}
				}

				setState(118);
				_la = _input.LA(1);
				if ( !(_la==PLUS || _la==MINUS) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(119);
				assignment();
				}
				break;
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
	public static class ListContext extends ParserRuleContext {
		public ListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_list; }
	 
		public ListContext() { }
		public void copyFrom(ListContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ListOnlyConditionalContext extends ListContext {
		public ConditionalContext conditional() {
			return getRuleContext(ConditionalContext.class,0);
		}
		public ListOnlyConditionalContext(ListContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterListOnlyConditional(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitListOnlyConditional(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ListOnlyAssignmentContext extends ListContext {
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public ListOnlyAssignmentContext(ListContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterListOnlyAssignment(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitListOnlyAssignment(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ListOtherContext extends ListContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<LvalueContext> lvalue() {
			return getRuleContexts(LvalueContext.class);
		}
		public LvalueContext lvalue(int i) {
			return getRuleContext(LvalueContext.class,i);
		}
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public ConditionalContext conditional() {
			return getRuleContext(ConditionalContext.class,0);
		}
		public ListOtherContext(ListContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterListOther(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitListOther(this);
		}
	}

	public final ListContext list() throws RecognitionException {
		ListContext _localctx = new ListContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_list);
		try {
			int _alt;
			setState(134);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
			case 1:
				_localctx = new ListOtherContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(124); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						setState(124);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
						case 1:
							{
							setState(122);
							expression();
							}
							break;
						case 2:
							{
							setState(123);
							lvalue();
							}
							break;
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(126); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(130);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
				case 1:
					{
					setState(128);
					assignment();
					}
					break;
				case 2:
					{
					setState(129);
					conditional();
					}
					break;
				}
				}
				break;
			case 2:
				_localctx = new ListOnlyAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(132);
				assignment();
				}
				break;
			case 3:
				_localctx = new ListOnlyConditionalContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(133);
				conditional();
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
	public static class FuncallContext extends ParserRuleContext {
		public TerminalNode FUNCTION() { return getToken(parsetestParser.FUNCTION, 0); }
		public TerminalNode PARAMS() { return getToken(parsetestParser.PARAMS, 0); }
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public TerminalNode CLOSED() { return getToken(parsetestParser.CLOSED, 0); }
		public List<TerminalNode> UPLUS() { return getTokens(parsetestParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(parsetestParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(parsetestParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(parsetestParser.UMINUS, i);
		}
		public FuncallContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcall; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterFuncall(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitFuncall(this);
		}
	}

	public final FuncallContext funcall() throws RecognitionException {
		FuncallContext _localctx = new FuncallContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_funcall);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(139);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==UPLUS || _la==UMINUS) {
				{
				{
				setState(136);
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
				setState(141);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(142);
			match(FUNCTION);
			setState(143);
			match(PARAMS);
			setState(144);
			list();
			setState(145);
			match(CLOSED);
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
	public static class ConditionalContext extends ParserRuleContext {
		public ConditionalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_conditional; }
	 
		public ConditionalContext() { }
		public void copyFrom(ConditionalContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class IfthenelseContext extends ConditionalContext {
		public TerminalNode IF() { return getToken(parsetestParser.IF, 0); }
		public List<SequenceContext> sequence() {
			return getRuleContexts(SequenceContext.class);
		}
		public SequenceContext sequence(int i) {
			return getRuleContext(SequenceContext.class,i);
		}
		public TerminalNode THEN() { return getToken(parsetestParser.THEN, 0); }
		public TerminalNode ELSE() { return getToken(parsetestParser.ELSE, 0); }
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public List<TerminalNode> UPLUS() { return getTokens(parsetestParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(parsetestParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(parsetestParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(parsetestParser.UMINUS, i);
		}
		public IfthenelseContext(ConditionalContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterIfthenelse(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitIfthenelse(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class IfthenContext extends ConditionalContext {
		public TerminalNode IF() { return getToken(parsetestParser.IF, 0); }
		public SequenceContext sequence() {
			return getRuleContext(SequenceContext.class,0);
		}
		public TerminalNode THEN() { return getToken(parsetestParser.THEN, 0); }
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public List<TerminalNode> UPLUS() { return getTokens(parsetestParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(parsetestParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(parsetestParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(parsetestParser.UMINUS, i);
		}
		public IfthenContext(ConditionalContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterIfthen(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitIfthen(this);
		}
	}

	public final ConditionalContext conditional() throws RecognitionException {
		ConditionalContext _localctx = new ConditionalContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_conditional);
		int _la;
		try {
			setState(171);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,24,_ctx) ) {
			case 1:
				_localctx = new IfthenContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(150);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==UPLUS || _la==UMINUS) {
					{
					{
					setState(147);
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
					setState(152);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(153);
				match(IF);
				setState(154);
				sequence();
				setState(155);
				match(THEN);
				setState(156);
				list();
				}
				break;
			case 2:
				_localctx = new IfthenelseContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(161);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==UPLUS || _la==UMINUS) {
					{
					{
					setState(158);
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
					setState(163);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(164);
				match(IF);
				setState(165);
				sequence();
				setState(166);
				match(THEN);
				setState(167);
				sequence();
				setState(168);
				match(ELSE);
				setState(169);
				list();
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
	public static class NullifyContext extends ParserRuleContext {
		public TerminalNode NULLIFY() { return getToken(parsetestParser.NULLIFY, 0); }
		public NullifyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nullify; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).enterNullify(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof parsetestListener ) ((parsetestListener)listener).exitNullify(this);
		}
	}

	public final NullifyContext nullify() throws RecognitionException {
		NullifyContext _localctx = new NullifyContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_nullify);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(173);
			match(NULLIFY);
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
		"\u0004\u0001\u0013\u00b0\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001"+
		"\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004"+
		"\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007"+
		"\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b"+
		"\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0001\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0003\u0001$\b\u0001\u0004"+
		"\u0001&\b\u0001\u000b\u0001\f\u0001\'\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0003\u00020\b\u0002\u0001\u0003"+
		"\u0001\u0003\u0001\u0004\u0003\u00045\b\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0003\u0004;\b\u0004\u0004\u0004=\b\u0004\u000b"+
		"\u0004\f\u0004>\u0001\u0005\u0001\u0005\u0003\u0005C\b\u0005\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0007\u0005\u0007I\b\u0007\n\u0007\f\u0007"+
		"L\t\u0007\u0001\u0007\u0001\u0007\u0003\u0007P\b\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\b\u0001\b\u0003\bW\b\b\u0001\t\u0005\tZ\b\t\n"+
		"\t\f\t]\t\t\u0001\t\u0001\t\u0005\ta\b\t\n\t\f\td\t\t\u0001\t\u0003\t"+
		"g\b\t\u0001\n\u0001\n\u0003\nk\b\n\u0001\n\u0001\n\u0005\no\b\n\n\n\f"+
		"\nr\t\n\u0001\n\u0003\nu\b\n\u0001\n\u0001\n\u0003\ny\b\n\u0001\u000b"+
		"\u0001\u000b\u0004\u000b}\b\u000b\u000b\u000b\f\u000b~\u0001\u000b\u0001"+
		"\u000b\u0003\u000b\u0083\b\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u0087"+
		"\b\u000b\u0001\f\u0005\f\u008a\b\f\n\f\f\f\u008d\t\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\r\u0005\r\u0095\b\r\n\r\f\r\u0098\t\r\u0001\r"+
		"\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0005\r\u00a0\b\r\n\r\f\r\u00a3"+
		"\t\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0003\r\u00ac"+
		"\b\r\u0001\u000e\u0001\u000e\u0001\u000e\u0000\u0000\u000f\u0000\u0002"+
		"\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u0000"+
		"\u0002\u0002\u0000\u000f\u000f\u0011\u0011\u0002\u0000\u000e\u000e\u0010"+
		"\u0010\u00bd\u0000\u001e\u0001\u0000\u0000\u0000\u0002%\u0001\u0000\u0000"+
		"\u0000\u0004/\u0001\u0000\u0000\u0000\u00061\u0001\u0000\u0000\u0000\b"+
		"<\u0001\u0000\u0000\u0000\n@\u0001\u0000\u0000\u0000\fD\u0001\u0000\u0000"+
		"\u0000\u000eJ\u0001\u0000\u0000\u0000\u0010V\u0001\u0000\u0000\u0000\u0012"+
		"f\u0001\u0000\u0000\u0000\u0014h\u0001\u0000\u0000\u0000\u0016\u0086\u0001"+
		"\u0000\u0000\u0000\u0018\u008b\u0001\u0000\u0000\u0000\u001a\u00ab\u0001"+
		"\u0000\u0000\u0000\u001c\u00ad\u0001\u0000\u0000\u0000\u001e\u001f\u0003"+
		"\u0002\u0001\u0000\u001f \u0005\u0000\u0000\u0001 \u0001\u0001\u0000\u0000"+
		"\u0000!#\u0003\u0016\u000b\u0000\"$\u0003\u001c\u000e\u0000#\"\u0001\u0000"+
		"\u0000\u0000#$\u0001\u0000\u0000\u0000$&\u0001\u0000\u0000\u0000%!\u0001"+
		"\u0000\u0000\u0000&\'\u0001\u0000\u0000\u0000\'%\u0001\u0000\u0000\u0000"+
		"\'(\u0001\u0000\u0000\u0000(\u0003\u0001\u0000\u0000\u0000)0\u0005\u0001"+
		"\u0000\u0000*+\u0005\u0012\u0000\u0000+,\u0003\u0002\u0001\u0000,-\u0005"+
		"\u0007\u0000\u0000-0\u0001\u0000\u0000\u0000.0\u0003\u0018\f\u0000/)\u0001"+
		"\u0000\u0000\u0000/*\u0001\u0000\u0000\u0000/.\u0001\u0000\u0000\u0000"+
		"0\u0005\u0001\u0000\u0000\u000012\u0005\u0006\u0000\u00002\u0007\u0001"+
		"\u0000\u0000\u000035\u0003\u001c\u000e\u000043\u0001\u0000\u0000\u0000"+
		"45\u0001\u0000\u0000\u000056\u0001\u0000\u0000\u00006:\u0005\b\u0000\u0000"+
		"7;\u0003\u0004\u0002\u00008;\u0003\u0006\u0003\u00009;\u0003\u001a\r\u0000"+
		":7\u0001\u0000\u0000\u0000:8\u0001\u0000\u0000\u0000:9\u0001\u0000\u0000"+
		"\u0000;=\u0001\u0000\u0000\u0000<4\u0001\u0000\u0000\u0000=>\u0001\u0000"+
		"\u0000\u0000><\u0001\u0000\u0000\u0000>?\u0001\u0000\u0000\u0000?\t\u0001"+
		"\u0000\u0000\u0000@B\u0003\u0006\u0003\u0000AC\u0003\b\u0004\u0000BA\u0001"+
		"\u0000\u0000\u0000BC\u0001\u0000\u0000\u0000C\u000b\u0001\u0000\u0000"+
		"\u0000DE\u0003\u0004\u0002\u0000EF\u0003\b\u0004\u0000F\r\u0001\u0000"+
		"\u0000\u0000GI\u0007\u0000\u0000\u0000HG\u0001\u0000\u0000\u0000IL\u0001"+
		"\u0000\u0000\u0000JH\u0001\u0000\u0000\u0000JK\u0001\u0000\u0000\u0000"+
		"KO\u0001\u0000\u0000\u0000LJ\u0001\u0000\u0000\u0000MP\u0003\n\u0005\u0000"+
		"NP\u0003\f\u0006\u0000OM\u0001\u0000\u0000\u0000ON\u0001\u0000\u0000\u0000"+
		"PQ\u0001\u0000\u0000\u0000QR\u0005\u000b\u0000\u0000RS\u0003\u0016\u000b"+
		"\u0000S\u000f\u0001\u0000\u0000\u0000TW\u0003\n\u0005\u0000UW\u0003\f"+
		"\u0006\u0000VT\u0001\u0000\u0000\u0000VU\u0001\u0000\u0000\u0000W\u0011"+
		"\u0001\u0000\u0000\u0000XZ\u0007\u0000\u0000\u0000YX\u0001\u0000\u0000"+
		"\u0000Z]\u0001\u0000\u0000\u0000[Y\u0001\u0000\u0000\u0000[\\\u0001\u0000"+
		"\u0000\u0000\\^\u0001\u0000\u0000\u0000][\u0001\u0000\u0000\u0000^g\u0003"+
		"\u0004\u0002\u0000_a\u0007\u0000\u0000\u0000`_\u0001\u0000\u0000\u0000"+
		"ad\u0001\u0000\u0000\u0000b`\u0001\u0000\u0000\u0000bc\u0001\u0000\u0000"+
		"\u0000ce\u0001\u0000\u0000\u0000db\u0001\u0000\u0000\u0000eg\u0003\u0010"+
		"\b\u0000f[\u0001\u0000\u0000\u0000fb\u0001\u0000\u0000\u0000g\u0013\u0001"+
		"\u0000\u0000\u0000hp\u0003\u0012\t\u0000ik\u0003\u001c\u000e\u0000ji\u0001"+
		"\u0000\u0000\u0000jk\u0001\u0000\u0000\u0000kl\u0001\u0000\u0000\u0000"+
		"lm\u0007\u0001\u0000\u0000mo\u0003\u0012\t\u0000nj\u0001\u0000\u0000\u0000"+
		"or\u0001\u0000\u0000\u0000pn\u0001\u0000\u0000\u0000pq\u0001\u0000\u0000"+
		"\u0000qx\u0001\u0000\u0000\u0000rp\u0001\u0000\u0000\u0000su\u0003\u001c"+
		"\u000e\u0000ts\u0001\u0000\u0000\u0000tu\u0001\u0000\u0000\u0000uv\u0001"+
		"\u0000\u0000\u0000vw\u0007\u0001\u0000\u0000wy\u0003\u000e\u0007\u0000"+
		"xt\u0001\u0000\u0000\u0000xy\u0001\u0000\u0000\u0000y\u0015\u0001\u0000"+
		"\u0000\u0000z}\u0003\u0014\n\u0000{}\u0003\n\u0005\u0000|z\u0001\u0000"+
		"\u0000\u0000|{\u0001\u0000\u0000\u0000}~\u0001\u0000\u0000\u0000~|\u0001"+
		"\u0000\u0000\u0000~\u007f\u0001\u0000\u0000\u0000\u007f\u0082\u0001\u0000"+
		"\u0000\u0000\u0080\u0083\u0003\u000e\u0007\u0000\u0081\u0083\u0003\u001a"+
		"\r\u0000\u0082\u0080\u0001\u0000\u0000\u0000\u0082\u0081\u0001\u0000\u0000"+
		"\u0000\u0082\u0083\u0001\u0000\u0000\u0000\u0083\u0087\u0001\u0000\u0000"+
		"\u0000\u0084\u0087\u0003\u000e\u0007\u0000\u0085\u0087\u0003\u001a\r\u0000"+
		"\u0086|\u0001\u0000\u0000\u0000\u0086\u0084\u0001\u0000\u0000\u0000\u0086"+
		"\u0085\u0001\u0000\u0000\u0000\u0087\u0017\u0001\u0000\u0000\u0000\u0088"+
		"\u008a\u0007\u0000\u0000\u0000\u0089\u0088\u0001\u0000\u0000\u0000\u008a"+
		"\u008d\u0001\u0000\u0000\u0000\u008b\u0089\u0001\u0000\u0000\u0000\u008b"+
		"\u008c\u0001\u0000\u0000\u0000\u008c\u008e\u0001\u0000\u0000\u0000\u008d"+
		"\u008b\u0001\u0000\u0000\u0000\u008e\u008f\u0005\u0005\u0000\u0000\u008f"+
		"\u0090\u0005\u0013\u0000\u0000\u0090\u0091\u0003\u0016\u000b\u0000\u0091"+
		"\u0092\u0005\u0007\u0000\u0000\u0092\u0019\u0001\u0000\u0000\u0000\u0093"+
		"\u0095\u0007\u0000\u0000\u0000\u0094\u0093\u0001\u0000\u0000\u0000\u0095"+
		"\u0098\u0001\u0000\u0000\u0000\u0096\u0094\u0001\u0000\u0000\u0000\u0096"+
		"\u0097\u0001\u0000\u0000\u0000\u0097\u0099\u0001\u0000\u0000\u0000\u0098"+
		"\u0096\u0001\u0000\u0000\u0000\u0099\u009a\u0005\u0002\u0000\u0000\u009a"+
		"\u009b\u0003\u0002\u0001\u0000\u009b\u009c\u0005\u0003\u0000\u0000\u009c"+
		"\u009d\u0003\u0016\u000b\u0000\u009d\u00ac\u0001\u0000\u0000\u0000\u009e"+
		"\u00a0\u0007\u0000\u0000\u0000\u009f\u009e\u0001\u0000\u0000\u0000\u00a0"+
		"\u00a3\u0001\u0000\u0000\u0000\u00a1\u009f\u0001\u0000\u0000\u0000\u00a1"+
		"\u00a2\u0001\u0000\u0000\u0000\u00a2\u00a4\u0001\u0000\u0000\u0000\u00a3"+
		"\u00a1\u0001\u0000\u0000\u0000\u00a4\u00a5\u0005\u0002\u0000\u0000\u00a5"+
		"\u00a6\u0003\u0002\u0001\u0000\u00a6\u00a7\u0005\u0003\u0000\u0000\u00a7"+
		"\u00a8\u0003\u0002\u0001\u0000\u00a8\u00a9\u0005\u0004\u0000\u0000\u00a9"+
		"\u00aa\u0003\u0016\u000b\u0000\u00aa\u00ac\u0001\u0000\u0000\u0000\u00ab"+
		"\u0096\u0001\u0000\u0000\u0000\u00ab\u00a1\u0001\u0000\u0000\u0000\u00ac"+
		"\u001b\u0001\u0000\u0000\u0000\u00ad\u00ae\u0005\n\u0000\u0000\u00ae\u001d"+
		"\u0001\u0000\u0000\u0000\u0019#\'/4:>BJOV[bfjptx|~\u0082\u0086\u008b\u0096"+
		"\u00a1\u00ab";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}