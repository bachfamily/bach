// Generated from /Users/aa/Documents/Max 8/Packages/bach/source/commons/bell/antlrparser/bell.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class bellParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, RANGE=2, UINT=3, UFLOAT=4, UPITCH=5, BTSYMBOL=6, DQSYMBOL=7, SQSYMBOL=8, 
		BACHNULL=9, BACHNIL=10, IF=11, THEN=12, ELSE=13, WHILE=14, FOR=15, DO=16, 
		COLLECT=17, INLET=18, INTINLET=19, RATINLET=20, FLOATINLET=21, PITCHINLET=22, 
		OUTLET=23, DIRINLET=24, DIROUTLET=25, BIF=26, OF=27, GLOBALVAR=28, PATCHERVAR=29, 
		LOCALVAR=30, NAMEDPARAM=31, PUSH=32, POP=33, CLOSED=34, NTH=35, PICK=36, 
		KEY=37, ANTH=38, APICK=39, NULLIFY=40, ASSIGN=41, WHITESPACE=42, NEWATOM=43, 
		POW=44, APOW=45, TIMES=46, ATIMES=47, DIVDIV=48, ADIVDIV=49, DIV=50, ADIV=51, 
		REM=52, AREM=53, PLUS=54, APLUS=55, UPLUS=56, MINUS=57, AMINUS=58, UMINUS=59, 
		EQUAL=60, NEQ=61, LOGNOT=62, BITNOT=63, LT=64, GT=65, LEQ=66, GEQ=67, 
		BITAND=68, ABITAND=69, BITXOR=70, ABITXOR=71, BITOR=72, ABITOR=73, LOGAND=74, 
		LOGANDEXT=75, ALOGAND=76, ALOGANDEXT=77, LOGXOR=78, ALOGXOR=79, LOGOR=80, 
		ALOGOR=81, LOGOREXT=82, ALOGOREXT=83, LSHIFT=84, ALSHIFT=85, RSHIFT=86, 
		ARSHIFT=87, REPEAT=88, AREPEAT=89, AAPPLY=90, ACONCAT=91, ARCONCAT=92, 
		OPEN=93, PARAMS=94, FUNDEF=95, LIFT=96, ELLIPSIS=97, ANYTHING=98;
	public static final int
		RULE_everything = 0, RULE_program = 1, RULE_funarg = 2, RULE_funargList = 3, 
		RULE_liftedargList = 4, RULE_fundef = 5, RULE_sequence = 6, RULE_nullified = 7, 
		RULE_whileloop = 8, RULE_argsByNameList = 9, RULE_argsByPositionList = 10, 
		RULE_simpleFuncall = 11, RULE_dataFlowItem = 12, RULE_funcall = 13, RULE_item = 14, 
		RULE_var = 15, RULE_lvalueSpecs = 16, RULE_lvalue = 17, RULE_fakeLvalue = 18, 
		RULE_listEnd = 19, RULE_expr = 20, RULE_assignment = 21, RULE_conditional = 22, 
		RULE_list = 23;
	private static String[] makeRuleNames() {
		return new String[] {
			"everything", "program", "funarg", "funargList", "liftedargList", "fundef", 
			"sequence", "nullified", "whileloop", "argsByNameList", "argsByPositionList", 
			"simpleFuncall", "dataFlowItem", "funcall", "item", "var", "lvalueSpecs", 
			"lvalue", "fakeLvalue", "listEnd", "expr", "assignment", "conditional", 
			"list"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "','", "'...'", null, null, null, null, null, null, "'null'", "'nil'", 
			"'if'", "'then'", "'else'", "'while'", "'for'", "'do'", "'collect'", 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, "'['", "']'", "')'", "':'", "'::'", "'.'", "':='", "'::='", 
			"';'", "'='", null, null, "'**'", "'**='", "'*'", "'*='", "'//'", "'//='", 
			"'/'", "'/='", null, null, null, "'+='", "'+'", null, "'-='", "'-'", 
			"'=='", "'!='", "'!'", "'~'", "'<'", "'>'", "'<='", "'>='", "'&'", "'&='", 
			"'^'", "'^='", "'|'", "'|='", "'&&'", "'&&&'", "'&&='", "'&&&='", "'^^'", 
			"'^^='", "'||'", "'||='", "'|||'", "'|||='", "'<<'", "'<<='", "'>>'", 
			"'>>='", "':*'", "':*='", "'.='", "'_='", "'!_='", null, null, "'->'", 
			"'-^'", "'<...>'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, "RANGE", "UINT", "UFLOAT", "UPITCH", "BTSYMBOL", "DQSYMBOL", 
			"SQSYMBOL", "BACHNULL", "BACHNIL", "IF", "THEN", "ELSE", "WHILE", "FOR", 
			"DO", "COLLECT", "INLET", "INTINLET", "RATINLET", "FLOATINLET", "PITCHINLET", 
			"OUTLET", "DIRINLET", "DIROUTLET", "BIF", "OF", "GLOBALVAR", "PATCHERVAR", 
			"LOCALVAR", "NAMEDPARAM", "PUSH", "POP", "CLOSED", "NTH", "PICK", "KEY", 
			"ANTH", "APICK", "NULLIFY", "ASSIGN", "WHITESPACE", "NEWATOM", "POW", 
			"APOW", "TIMES", "ATIMES", "DIVDIV", "ADIVDIV", "DIV", "ADIV", "REM", 
			"AREM", "PLUS", "APLUS", "UPLUS", "MINUS", "AMINUS", "UMINUS", "EQUAL", 
			"NEQ", "LOGNOT", "BITNOT", "LT", "GT", "LEQ", "GEQ", "BITAND", "ABITAND", 
			"BITXOR", "ABITXOR", "BITOR", "ABITOR", "LOGAND", "LOGANDEXT", "ALOGAND", 
			"ALOGANDEXT", "LOGXOR", "ALOGXOR", "LOGOR", "ALOGOR", "LOGOREXT", "ALOGOREXT", 
			"LSHIFT", "ALSHIFT", "RSHIFT", "ARSHIFT", "REPEAT", "AREPEAT", "AAPPLY", 
			"ACONCAT", "ARCONCAT", "OPEN", "PARAMS", "FUNDEF", "LIFT", "ELLIPSIS", 
			"ANYTHING"
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
	public String getGrammarFileName() { return "bell.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	 
	    
	    bool ending = false;


	public bellParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class EverythingContext extends ParserRuleContext {
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public EverythingContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_everything; }
	}

	public final EverythingContext everything() throws RecognitionException {
		EverythingContext _localctx = new EverythingContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_everything);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(48);
			program();
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
	public static class ProgramContext extends ParserRuleContext {
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	 
		public ProgramContext() { }
		public void copyFrom(ProgramContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ProgramSequenceContext extends ProgramContext {
		public SequenceContext sequence() {
			return getRuleContext(SequenceContext.class,0);
		}
		public TerminalNode EOF() { return getToken(bellParser.EOF, 0); }
		public ProgramSequenceContext(ProgramContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ProgramNamedparamContext extends ProgramContext {
		public TerminalNode NAMEDPARAM() { return getToken(bellParser.NAMEDPARAM, 0); }
		public ProgramNamedparamContext(ProgramContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ProgramEOFContext extends ProgramContext {
		public TerminalNode EOF() { return getToken(bellParser.EOF, 0); }
		public ProgramEOFContext(ProgramContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ProgramSequenceNamedparamContext extends ProgramContext {
		public SequenceContext sequence() {
			return getRuleContext(SequenceContext.class,0);
		}
		public TerminalNode NAMEDPARAM() { return getToken(bellParser.NAMEDPARAM, 0); }
		public ProgramSequenceNamedparamContext(ProgramContext ctx) { copyFrom(ctx); }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_program);
		try {
			setState(58);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				_localctx = new ProgramEOFContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(50);
				match(EOF);
				}
				break;
			case 2:
				_localctx = new ProgramSequenceContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(51);
				sequence();
				setState(52);
				match(EOF);
				}
				break;
			case 3:
				_localctx = new ProgramSequenceNamedparamContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(54);
				sequence();
				setState(55);
				match(NAMEDPARAM);
				}
				break;
			case 4:
				_localctx = new ProgramNamedparamContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(57);
				match(NAMEDPARAM);
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
	public static class FunargContext extends ParserRuleContext {
		public FunargContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funarg; }
	 
		public FunargContext() { }
		public void copyFrom(FunargContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FunargVarContext extends FunargContext {
		public TerminalNode LOCALVAR() { return getToken(bellParser.LOCALVAR, 0); }
		public TerminalNode ASSIGN() { return getToken(bellParser.ASSIGN, 0); }
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public FunargVarContext(FunargContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FunargEllipsisContext extends FunargContext {
		public TerminalNode ELLIPSIS() { return getToken(bellParser.ELLIPSIS, 0); }
		public FunargEllipsisContext(FunargContext ctx) { copyFrom(ctx); }
	}

	public final FunargContext funarg() throws RecognitionException {
		FunargContext _localctx = new FunargContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_funarg);
		int _la;
		try {
			setState(66);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LOCALVAR:
				_localctx = new FunargVarContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(60);
				match(LOCALVAR);
				setState(63);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ASSIGN) {
					{
					setState(61);
					match(ASSIGN);
					setState(62);
					list();
					}
				}

				}
				break;
			case ELLIPSIS:
				_localctx = new FunargEllipsisContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(65);
				match(ELLIPSIS);
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
	public static class FunargListContext extends ParserRuleContext {
		public List<FunargContext> funarg() {
			return getRuleContexts(FunargContext.class);
		}
		public FunargContext funarg(int i) {
			return getRuleContext(FunargContext.class,i);
		}
		public FunargListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funargList; }
	}

	public final FunargListContext funargList() throws RecognitionException {
		FunargListContext _localctx = new FunargListContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_funargList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(68);
			funarg();
			setState(73);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__0) {
				{
				{
				setState(69);
				match(T__0);
				setState(70);
				funarg();
				}
				}
				setState(75);
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
	public static class LiftedargListContext extends ParserRuleContext {
		public TerminalNode LIFT() { return getToken(bellParser.LIFT, 0); }
		public List<TerminalNode> LOCALVAR() { return getTokens(bellParser.LOCALVAR); }
		public TerminalNode LOCALVAR(int i) {
			return getToken(bellParser.LOCALVAR, i);
		}
		public LiftedargListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_liftedargList; }
	}

	public final LiftedargListContext liftedargList() throws RecognitionException {
		LiftedargListContext _localctx = new LiftedargListContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_liftedargList);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(76);
			match(LIFT);
			setState(81);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(77);
					match(LOCALVAR);
					setState(78);
					match(T__0);
					}
					} 
				}
				setState(83);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			}
			setState(84);
			match(LOCALVAR);
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
	public static class FundefContext extends ParserRuleContext {
		public FunargListContext funargList() {
			return getRuleContext(FunargListContext.class,0);
		}
		public TerminalNode FUNDEF() { return getToken(bellParser.FUNDEF, 0); }
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public LiftedargListContext liftedargList() {
			return getRuleContext(LiftedargListContext.class,0);
		}
		public FundefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fundef; }
	}

	public final FundefContext fundef() throws RecognitionException {
		FundefContext _localctx = new FundefContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_fundef);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(86);
			funargList();
			setState(88);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LIFT) {
				{
				setState(87);
				liftedargList();
				}
			}

			setState(90);
			match(FUNDEF);
			setState(91);
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
	public static class SequenceContext extends ParserRuleContext {
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public List<NullifiedContext> nullified() {
			return getRuleContexts(NullifiedContext.class);
		}
		public NullifiedContext nullified(int i) {
			return getRuleContext(NullifiedContext.class,i);
		}
		public SequenceContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sequence; }
	}

	public final SequenceContext sequence() throws RecognitionException {
		SequenceContext _localctx = new SequenceContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_sequence);
		int _la;
		try {
			int _alt;
			setState(102);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(93);
				list();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(95); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(94);
						nullified();
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(97); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(100);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & -3963167665643827208L) != 0) || _la==OPEN || _la==ELLIPSIS) {
					{
					setState(99);
					list();
					}
				}

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
	public static class NullifiedContext extends ParserRuleContext {
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public List<TerminalNode> NULLIFY() { return getTokens(bellParser.NULLIFY); }
		public TerminalNode NULLIFY(int i) {
			return getToken(bellParser.NULLIFY, i);
		}
		public NullifiedContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nullified; }
	}

	public final NullifiedContext nullified() throws RecognitionException {
		NullifiedContext _localctx = new NullifiedContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_nullified);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(104);
			list();
			setState(106); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(105);
				match(NULLIFY);
				}
				}
				setState(108); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==NULLIFY );
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
	public static class WhileloopContext extends ParserRuleContext {
		public Token kind;
		public TerminalNode WHILE() { return getToken(bellParser.WHILE, 0); }
		public SequenceContext sequence() {
			return getRuleContext(SequenceContext.class,0);
		}
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public TerminalNode DO() { return getToken(bellParser.DO, 0); }
		public TerminalNode COLLECT() { return getToken(bellParser.COLLECT, 0); }
		public WhileloopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileloop; }
	}

	public final WhileloopContext whileloop() throws RecognitionException {
		WhileloopContext _localctx = new WhileloopContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_whileloop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(110);
			match(WHILE);
			setState(111);
			sequence();
			setState(112);
			((WhileloopContext)_localctx).kind = _input.LT(1);
			_la = _input.LA(1);
			if ( !(_la==DO || _la==COLLECT) ) {
				((WhileloopContext)_localctx).kind = (Token)_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(113);
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
	public static class ArgsByNameListContext extends ParserRuleContext {
		public List<TerminalNode> NAMEDPARAM() { return getTokens(bellParser.NAMEDPARAM); }
		public TerminalNode NAMEDPARAM(int i) {
			return getToken(bellParser.NAMEDPARAM, i);
		}
		public List<SequenceContext> sequence() {
			return getRuleContexts(SequenceContext.class);
		}
		public SequenceContext sequence(int i) {
			return getRuleContext(SequenceContext.class,i);
		}
		public ArgsByNameListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argsByNameList; }
	}

	public final ArgsByNameListContext argsByNameList() throws RecognitionException {
		ArgsByNameListContext _localctx = new ArgsByNameListContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_argsByNameList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(115);
			match(NAMEDPARAM);
			setState(116);
			sequence();
			setState(124);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__0 || _la==NAMEDPARAM) {
				{
				{
				setState(118);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__0) {
					{
					setState(117);
					match(T__0);
					}
				}

				setState(120);
				match(NAMEDPARAM);
				setState(121);
				sequence();
				}
				}
				setState(126);
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
	public static class ArgsByPositionListContext extends ParserRuleContext {
		public List<SequenceContext> sequence() {
			return getRuleContexts(SequenceContext.class);
		}
		public SequenceContext sequence(int i) {
			return getRuleContext(SequenceContext.class,i);
		}
		public ArgsByPositionListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argsByPositionList; }
	}

	public final ArgsByPositionListContext argsByPositionList() throws RecognitionException {
		ArgsByPositionListContext _localctx = new ArgsByPositionListContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_argsByPositionList);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(127);
			sequence();
			setState(132);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(128);
					match(T__0);
					setState(129);
					sequence();
					}
					} 
				}
				setState(134);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
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
	public static class SimpleFuncallContext extends ParserRuleContext {
		public TerminalNode PARAMS() { return getToken(bellParser.PARAMS, 0); }
		public TerminalNode CLOSED() { return getToken(bellParser.CLOSED, 0); }
		public ItemContext item() {
			return getRuleContext(ItemContext.class,0);
		}
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public ArgsByPositionListContext argsByPositionList() {
			return getRuleContext(ArgsByPositionListContext.class,0);
		}
		public ArgsByNameListContext argsByNameList() {
			return getRuleContext(ArgsByNameListContext.class,0);
		}
		public SimpleFuncallContext simpleFuncall() {
			return getRuleContext(SimpleFuncallContext.class,0);
		}
		public SimpleFuncallContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simpleFuncall; }
	}

	public final SimpleFuncallContext simpleFuncall() throws RecognitionException {
		return simpleFuncall(0);
	}

	private SimpleFuncallContext simpleFuncall(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		SimpleFuncallContext _localctx = new SimpleFuncallContext(_ctx, _parentState);
		SimpleFuncallContext _prevctx = _localctx;
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_simpleFuncall, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(171);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				{
				setState(138);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case UINT:
				case UFLOAT:
				case UPITCH:
				case BTSYMBOL:
				case DQSYMBOL:
				case SQSYMBOL:
				case BACHNULL:
				case BACHNIL:
				case INLET:
				case INTINLET:
				case RATINLET:
				case FLOATINLET:
				case PITCHINLET:
				case DIRINLET:
				case BIF:
				case OF:
				case PUSH:
				case OPEN:
					{
					setState(136);
					item();
					}
					break;
				case GLOBALVAR:
				case PATCHERVAR:
				case LOCALVAR:
					{
					setState(137);
					var();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(140);
				match(PARAMS);
				setState(141);
				match(CLOSED);
				}
				break;
			case 2:
				{
				setState(145);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case UINT:
				case UFLOAT:
				case UPITCH:
				case BTSYMBOL:
				case DQSYMBOL:
				case SQSYMBOL:
				case BACHNULL:
				case BACHNIL:
				case INLET:
				case INTINLET:
				case RATINLET:
				case FLOATINLET:
				case PITCHINLET:
				case DIRINLET:
				case BIF:
				case OF:
				case PUSH:
				case OPEN:
					{
					setState(143);
					item();
					}
					break;
				case GLOBALVAR:
				case PATCHERVAR:
				case LOCALVAR:
					{
					setState(144);
					var();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(147);
				match(PARAMS);
				setState(148);
				argsByPositionList();
				setState(149);
				match(CLOSED);
				}
				break;
			case 3:
				{
				setState(153);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case UINT:
				case UFLOAT:
				case UPITCH:
				case BTSYMBOL:
				case DQSYMBOL:
				case SQSYMBOL:
				case BACHNULL:
				case BACHNIL:
				case INLET:
				case INTINLET:
				case RATINLET:
				case FLOATINLET:
				case PITCHINLET:
				case DIRINLET:
				case BIF:
				case OF:
				case PUSH:
				case OPEN:
					{
					setState(151);
					item();
					}
					break;
				case GLOBALVAR:
				case PATCHERVAR:
				case LOCALVAR:
					{
					setState(152);
					var();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(155);
				match(PARAMS);
				setState(156);
				argsByNameList();
				setState(157);
				match(CLOSED);
				}
				break;
			case 4:
				{
				setState(161);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case UINT:
				case UFLOAT:
				case UPITCH:
				case BTSYMBOL:
				case DQSYMBOL:
				case SQSYMBOL:
				case BACHNULL:
				case BACHNIL:
				case INLET:
				case INTINLET:
				case RATINLET:
				case FLOATINLET:
				case PITCHINLET:
				case DIRINLET:
				case BIF:
				case OF:
				case PUSH:
				case OPEN:
					{
					setState(159);
					item();
					}
					break;
				case GLOBALVAR:
				case PATCHERVAR:
				case LOCALVAR:
					{
					setState(160);
					var();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(163);
				match(PARAMS);
				setState(164);
				argsByPositionList();
				setState(166);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__0) {
					{
					setState(165);
					match(T__0);
					}
				}

				setState(168);
				argsByNameList();
				setState(169);
				match(CLOSED);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(197);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(195);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
					case 1:
						{
						_localctx = new SimpleFuncallContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_simpleFuncall);
						setState(173);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(174);
						match(PARAMS);
						setState(175);
						match(CLOSED);
						}
						break;
					case 2:
						{
						_localctx = new SimpleFuncallContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_simpleFuncall);
						setState(176);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(177);
						match(PARAMS);
						setState(178);
						argsByPositionList();
						setState(179);
						match(CLOSED);
						}
						break;
					case 3:
						{
						_localctx = new SimpleFuncallContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_simpleFuncall);
						setState(181);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(182);
						match(PARAMS);
						setState(183);
						argsByNameList();
						setState(184);
						match(CLOSED);
						}
						break;
					case 4:
						{
						_localctx = new SimpleFuncallContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_simpleFuncall);
						setState(186);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(187);
						match(PARAMS);
						setState(188);
						argsByPositionList();
						setState(190);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==T__0) {
							{
							setState(189);
							match(T__0);
							}
						}

						setState(192);
						argsByNameList();
						setState(193);
						match(CLOSED);
						}
						break;
					}
					} 
				}
				setState(199);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DataFlowItemContext extends ParserRuleContext {
		public ItemContext item() {
			return getRuleContext(ItemContext.class,0);
		}
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public SimpleFuncallContext simpleFuncall() {
			return getRuleContext(SimpleFuncallContext.class,0);
		}
		public DataFlowItemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_dataFlowItem; }
	}

	public final DataFlowItemContext dataFlowItem() throws RecognitionException {
		DataFlowItemContext _localctx = new DataFlowItemContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_dataFlowItem);
		try {
			setState(203);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(200);
				item();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(201);
				var();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(202);
				simpleFuncall(0);
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
		public List<SimpleFuncallContext> simpleFuncall() {
			return getRuleContexts(SimpleFuncallContext.class);
		}
		public SimpleFuncallContext simpleFuncall(int i) {
			return getRuleContext(SimpleFuncallContext.class,i);
		}
		public DataFlowItemContext dataFlowItem() {
			return getRuleContext(DataFlowItemContext.class,0);
		}
		public List<TerminalNode> KEY() { return getTokens(bellParser.KEY); }
		public TerminalNode KEY(int i) {
			return getToken(bellParser.KEY, i);
		}
		public FuncallContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcall; }
	}

	public final FuncallContext funcall() throws RecognitionException {
		FuncallContext _localctx = new FuncallContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_funcall);
		try {
			int _alt;
			setState(213);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,24,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(205);
				simpleFuncall(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(206);
				dataFlowItem();
				setState(209); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(207);
						match(KEY);
						setState(208);
						simpleFuncall(0);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(211); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
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
	public static class ItemUfloatContext extends ItemContext {
		public TerminalNode UFLOAT() { return getToken(bellParser.UFLOAT, 0); }
		public ItemUfloatContext(ItemContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemUintContext extends ItemContext {
		public TerminalNode UINT() { return getToken(bellParser.UINT, 0); }
		public ItemUintContext(ItemContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemBtSymbolContext extends ItemContext {
		public TerminalNode BTSYMBOL() { return getToken(bellParser.BTSYMBOL, 0); }
		public ItemBtSymbolContext(ItemContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemInletContext extends ItemContext {
		public Token type;
		public TerminalNode INLET() { return getToken(bellParser.INLET, 0); }
		public TerminalNode INTINLET() { return getToken(bellParser.INTINLET, 0); }
		public TerminalNode FLOATINLET() { return getToken(bellParser.FLOATINLET, 0); }
		public TerminalNode RATINLET() { return getToken(bellParser.RATINLET, 0); }
		public TerminalNode PITCHINLET() { return getToken(bellParser.PITCHINLET, 0); }
		public ItemInletContext(ItemContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemDirInletContext extends ItemContext {
		public TerminalNode DIRINLET() { return getToken(bellParser.DIRINLET, 0); }
		public ItemDirInletContext(ItemContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemBIFContext extends ItemContext {
		public TerminalNode BIF() { return getToken(bellParser.BIF, 0); }
		public ItemBIFContext(ItemContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemSequenceContext extends ItemContext {
		public TerminalNode OPEN() { return getToken(bellParser.OPEN, 0); }
		public SequenceContext sequence() {
			return getRuleContext(SequenceContext.class,0);
		}
		public TerminalNode CLOSED() { return getToken(bellParser.CLOSED, 0); }
		public ItemSequenceContext(ItemContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemSublistContext extends ItemContext {
		public TerminalNode PUSH() { return getToken(bellParser.PUSH, 0); }
		public SequenceContext sequence() {
			return getRuleContext(SequenceContext.class,0);
		}
		public TerminalNode POP() { return getToken(bellParser.POP, 0); }
		public ItemSublistContext(ItemContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemOFContext extends ItemContext {
		public TerminalNode OF() { return getToken(bellParser.OF, 0); }
		public ItemOFContext(ItemContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemNullContext extends ItemContext {
		public TerminalNode BACHNULL() { return getToken(bellParser.BACHNULL, 0); }
		public ItemNullContext(ItemContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemUpitchContext extends ItemContext {
		public TerminalNode UPITCH() { return getToken(bellParser.UPITCH, 0); }
		public ItemUpitchContext(ItemContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemNilContext extends ItemContext {
		public TerminalNode BACHNIL() { return getToken(bellParser.BACHNIL, 0); }
		public ItemNilContext(ItemContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemQSymbolContext extends ItemContext {
		public TerminalNode DQSYMBOL() { return getToken(bellParser.DQSYMBOL, 0); }
		public TerminalNode SQSYMBOL() { return getToken(bellParser.SQSYMBOL, 0); }
		public ItemQSymbolContext(ItemContext ctx) { copyFrom(ctx); }
	}

	public final ItemContext item() throws RecognitionException {
		ItemContext _localctx = new ItemContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_item);
		int _la;
		try {
			setState(234);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case UINT:
				_localctx = new ItemUintContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(215);
				match(UINT);
				}
				break;
			case UFLOAT:
				_localctx = new ItemUfloatContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(216);
				match(UFLOAT);
				}
				break;
			case UPITCH:
				_localctx = new ItemUpitchContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(217);
				match(UPITCH);
				}
				break;
			case BTSYMBOL:
				_localctx = new ItemBtSymbolContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(218);
				match(BTSYMBOL);
				}
				break;
			case DQSYMBOL:
			case SQSYMBOL:
				_localctx = new ItemQSymbolContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(219);
				_la = _input.LA(1);
				if ( !(_la==DQSYMBOL || _la==SQSYMBOL) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				break;
			case BIF:
				_localctx = new ItemBIFContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(220);
				match(BIF);
				}
				break;
			case OF:
				_localctx = new ItemOFContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(221);
				match(OF);
				}
				break;
			case INLET:
			case INTINLET:
			case RATINLET:
			case FLOATINLET:
			case PITCHINLET:
				_localctx = new ItemInletContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(222);
				((ItemInletContext)_localctx).type = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 8126464L) != 0)) ) {
					((ItemInletContext)_localctx).type = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				break;
			case DIRINLET:
				_localctx = new ItemDirInletContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(223);
				match(DIRINLET);
				}
				break;
			case BACHNULL:
				_localctx = new ItemNullContext(_localctx);
				enterOuterAlt(_localctx, 10);
				{
				setState(224);
				match(BACHNULL);
				}
				break;
			case BACHNIL:
				_localctx = new ItemNilContext(_localctx);
				enterOuterAlt(_localctx, 11);
				{
				setState(225);
				match(BACHNIL);
				}
				break;
			case OPEN:
				_localctx = new ItemSequenceContext(_localctx);
				enterOuterAlt(_localctx, 12);
				{
				setState(226);
				match(OPEN);
				setState(227);
				sequence();
				setState(228);
				match(CLOSED);
				}
				break;
			case PUSH:
				_localctx = new ItemSublistContext(_localctx);
				enterOuterAlt(_localctx, 13);
				{
				setState(230);
				match(PUSH);
				setState(231);
				sequence();
				setState(232);
				match(POP);
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
		public VarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var; }
	 
		public VarContext() { }
		public void copyFrom(VarContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VarLocalContext extends VarContext {
		public TerminalNode LOCALVAR() { return getToken(bellParser.LOCALVAR, 0); }
		public VarLocalContext(VarContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VarPatcherContext extends VarContext {
		public TerminalNode PATCHERVAR() { return getToken(bellParser.PATCHERVAR, 0); }
		public VarPatcherContext(VarContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VarGlobalContext extends VarContext {
		public TerminalNode GLOBALVAR() { return getToken(bellParser.GLOBALVAR, 0); }
		public VarGlobalContext(VarContext ctx) { copyFrom(ctx); }
	}

	public final VarContext var() throws RecognitionException {
		VarContext _localctx = new VarContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_var);
		try {
			setState(239);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LOCALVAR:
				_localctx = new VarLocalContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(236);
				match(LOCALVAR);
				}
				break;
			case PATCHERVAR:
				_localctx = new VarPatcherContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(237);
				match(PATCHERVAR);
				}
				break;
			case GLOBALVAR:
				_localctx = new VarGlobalContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(238);
				match(GLOBALVAR);
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
	public static class LvalueSpecsContext extends ParserRuleContext {
		public List<TerminalNode> NTH() { return getTokens(bellParser.NTH); }
		public TerminalNode NTH(int i) {
			return getToken(bellParser.NTH, i);
		}
		public List<TerminalNode> KEY() { return getTokens(bellParser.KEY); }
		public TerminalNode KEY(int i) {
			return getToken(bellParser.KEY, i);
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
		public ConditionalContext conditional() {
			return getRuleContext(ConditionalContext.class,0);
		}
		public LvalueSpecsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lvalueSpecs; }
	}

	public final LvalueSpecsContext lvalueSpecs() throws RecognitionException {
		LvalueSpecsContext _localctx = new LvalueSpecsContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_lvalueSpecs);
		int _la;
		try {
			int _alt;
			setState(264);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,31,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				ending = false;
				setState(247); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(242);
						_la = _input.LA(1);
						if ( !(_la==NTH || _la==KEY) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(245);
						_errHandler.sync(this);
						switch (_input.LA(1)) {
						case UINT:
						case UFLOAT:
						case UPITCH:
						case BTSYMBOL:
						case DQSYMBOL:
						case SQSYMBOL:
						case BACHNULL:
						case BACHNIL:
						case INLET:
						case INTINLET:
						case RATINLET:
						case FLOATINLET:
						case PITCHINLET:
						case DIRINLET:
						case BIF:
						case OF:
						case PUSH:
						case OPEN:
							{
							setState(243);
							item();
							}
							break;
						case GLOBALVAR:
						case PATCHERVAR:
						case LOCALVAR:
							{
							setState(244);
							var();
							}
							break;
						default:
							throw new NoViableAltException(this);
						}
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(249); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				ending = true;
				setState(259);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,30,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(252);
						_la = _input.LA(1);
						if ( !(_la==NTH || _la==KEY) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(255);
						_errHandler.sync(this);
						switch (_input.LA(1)) {
						case UINT:
						case UFLOAT:
						case UPITCH:
						case BTSYMBOL:
						case DQSYMBOL:
						case SQSYMBOL:
						case BACHNULL:
						case BACHNIL:
						case INLET:
						case INTINLET:
						case RATINLET:
						case FLOATINLET:
						case PITCHINLET:
						case DIRINLET:
						case BIF:
						case OF:
						case PUSH:
						case OPEN:
							{
							setState(253);
							item();
							}
							break;
						case GLOBALVAR:
						case PATCHERVAR:
						case LOCALVAR:
							{
							setState(254);
							var();
							}
							break;
						default:
							throw new NoViableAltException(this);
						}
						}
						} 
					}
					setState(261);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,30,_ctx);
				}
				{
				setState(262);
				_la = _input.LA(1);
				if ( !(_la==NTH || _la==KEY) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				{
				setState(263);
				conditional();
				}
				}
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
	}

	public final LvalueContext lvalue() throws RecognitionException {
		LvalueContext _localctx = new LvalueContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_lvalue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(266);
			var();
			setState(268);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,32,_ctx) ) {
			case 1:
				{
				setState(267);
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
	}

	public final FakeLvalueContext fakeLvalue() throws RecognitionException {
		FakeLvalueContext _localctx = new FakeLvalueContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_fakeLvalue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(270);
			item();
			setState(271);
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
	public static class ListEndContext extends ParserRuleContext {
		public ConditionalContext conditional() {
			return getRuleContext(ConditionalContext.class,0);
		}
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public WhileloopContext whileloop() {
			return getRuleContext(WhileloopContext.class,0);
		}
		public FundefContext fundef() {
			return getRuleContext(FundefContext.class,0);
		}
		public ListEndContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_listEnd; }
	}

	public final ListEndContext listEnd() throws RecognitionException {
		ListEndContext _localctx = new ListEndContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_listEnd);
		try {
			setState(277);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,33,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(273);
				conditional();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(274);
				assignment();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(275);
				whileloop();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(276);
				fundef();
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
	public static class ExprContext extends ParserRuleContext {
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	 
		public ExprContext() { }
		public void copyFrom(ExprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprFakeLvalueContext extends ExprContext {
		public FakeLvalueContext fakeLvalue() {
			return getRuleContext(FakeLvalueContext.class,0);
		}
		public ExprFakeLvalueContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprUPlusMinusContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<TerminalNode> UPLUS() { return getTokens(bellParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(bellParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(bellParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(bellParser.UMINUS, i);
		}
		public ExprUPlusMinusContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprSimpleContext extends ExprContext {
		public ItemContext item() {
			return getRuleContext(ItemContext.class,0);
		}
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public FuncallContext funcall() {
			return getRuleContext(FuncallContext.class,0);
		}
		public ListEndContext listEnd() {
			return getRuleContext(ListEndContext.class,0);
		}
		public ExprSimpleContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprNotContext extends ExprContext {
		public Token op;
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode LOGNOT() { return getToken(bellParser.LOGNOT, 0); }
		public TerminalNode BITNOT() { return getToken(bellParser.BITNOT, 0); }
		public ExprNotContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprBinaryContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode PICK() { return getToken(bellParser.PICK, 0); }
		public TerminalNode POW() { return getToken(bellParser.POW, 0); }
		public TerminalNode TIMES() { return getToken(bellParser.TIMES, 0); }
		public TerminalNode DIV() { return getToken(bellParser.DIV, 0); }
		public TerminalNode DIVDIV() { return getToken(bellParser.DIVDIV, 0); }
		public TerminalNode REM() { return getToken(bellParser.REM, 0); }
		public TerminalNode PLUS() { return getToken(bellParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(bellParser.MINUS, 0); }
		public TerminalNode LSHIFT() { return getToken(bellParser.LSHIFT, 0); }
		public TerminalNode RSHIFT() { return getToken(bellParser.RSHIFT, 0); }
		public TerminalNode RANGE() { return getToken(bellParser.RANGE, 0); }
		public TerminalNode REPEAT() { return getToken(bellParser.REPEAT, 0); }
		public TerminalNode EQUAL() { return getToken(bellParser.EQUAL, 0); }
		public TerminalNode NEQ() { return getToken(bellParser.NEQ, 0); }
		public TerminalNode LT() { return getToken(bellParser.LT, 0); }
		public TerminalNode GT() { return getToken(bellParser.GT, 0); }
		public TerminalNode LEQ() { return getToken(bellParser.LEQ, 0); }
		public TerminalNode GEQ() { return getToken(bellParser.GEQ, 0); }
		public TerminalNode BITAND() { return getToken(bellParser.BITAND, 0); }
		public TerminalNode BITXOR() { return getToken(bellParser.BITXOR, 0); }
		public TerminalNode BITOR() { return getToken(bellParser.BITOR, 0); }
		public TerminalNode LOGAND() { return getToken(bellParser.LOGAND, 0); }
		public TerminalNode LOGANDEXT() { return getToken(bellParser.LOGANDEXT, 0); }
		public TerminalNode LOGXOR() { return getToken(bellParser.LOGXOR, 0); }
		public TerminalNode LOGOR() { return getToken(bellParser.LOGOR, 0); }
		public TerminalNode LOGOREXT() { return getToken(bellParser.LOGOREXT, 0); }
		public ExprBinaryContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprLvalueContext extends ExprContext {
		public LvalueContext lvalue() {
			return getRuleContext(LvalueContext.class,0);
		}
		public ExprLvalueContext(ExprContext ctx) { copyFrom(ctx); }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 40;
		enterRecursionRule(_localctx, 40, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(296);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,36,_ctx) ) {
			case 1:
				{
				_localctx = new ExprSimpleContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(284);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,34,_ctx) ) {
				case 1:
					{
					setState(280);
					item();
					}
					break;
				case 2:
					{
					setState(281);
					var();
					}
					break;
				case 3:
					{
					setState(282);
					funcall();
					}
					break;
				case 4:
					{
					setState(283);
					listEnd();
					}
					break;
				}
				}
				break;
			case 2:
				{
				_localctx = new ExprLvalueContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(286);
				lvalue();
				}
				break;
			case 3:
				{
				_localctx = new ExprFakeLvalueContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(287);
				fakeLvalue();
				}
				break;
			case 4:
				{
				_localctx = new ExprUPlusMinusContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(289); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(288);
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
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(291); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,35,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(293);
				expr(15);
				}
				break;
			case 5:
				{
				_localctx = new ExprNotContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(294);
				((ExprNotContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==LOGNOT || _la==BITNOT) ) {
					((ExprNotContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(295);
				expr(1);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(345);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,38,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(343);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,37,_ctx) ) {
					case 1:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(298);
						if (!(precpred(_ctx, 17))) throw new FailedPredicateException(this, "precpred(_ctx, 17)");
						setState(299);
						match(PICK);
						setState(300);
						expr(18);
						}
						break;
					case 2:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(301);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(302);
						((ExprBinaryContext)_localctx).op = match(POW);
						setState(303);
						expr(16);
						}
						break;
					case 3:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(304);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(305);
						((ExprBinaryContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 5981343255101440L) != 0)) ) {
							((ExprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(306);
						expr(15);
						}
						break;
					case 4:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(307);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(308);
						((ExprBinaryContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==MINUS) ) {
							((ExprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(309);
						expr(14);
						}
						break;
					case 5:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(310);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(311);
						((ExprBinaryContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==LSHIFT || _la==RSHIFT) ) {
							((ExprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(312);
						expr(13);
						}
						break;
					case 6:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(313);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(314);
						((ExprBinaryContext)_localctx).op = match(RANGE);
						setState(315);
						expr(12);
						}
						break;
					case 7:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(316);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(317);
						((ExprBinaryContext)_localctx).op = match(REPEAT);
						setState(318);
						expr(11);
						}
						break;
					case 8:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(319);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(320);
						((ExprBinaryContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==EQUAL || _la==NEQ) ) {
							((ExprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(321);
						expr(10);
						}
						break;
					case 9:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(322);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(323);
						((ExprBinaryContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & 15L) != 0)) ) {
							((ExprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(324);
						expr(9);
						}
						break;
					case 10:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(325);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(326);
						((ExprBinaryContext)_localctx).op = match(BITAND);
						setState(327);
						expr(8);
						}
						break;
					case 11:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(328);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(329);
						((ExprBinaryContext)_localctx).op = match(BITXOR);
						setState(330);
						expr(7);
						}
						break;
					case 12:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(331);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(332);
						((ExprBinaryContext)_localctx).op = match(BITOR);
						setState(333);
						expr(6);
						}
						break;
					case 13:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(334);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(335);
						((ExprBinaryContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==LOGAND || _la==LOGANDEXT) ) {
							((ExprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(336);
						expr(5);
						}
						break;
					case 14:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(337);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(338);
						((ExprBinaryContext)_localctx).op = match(LOGXOR);
						setState(339);
						expr(4);
						}
						break;
					case 15:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(340);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(341);
						((ExprBinaryContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==LOGOR || _la==LOGOREXT) ) {
							((ExprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(342);
						expr(3);
						}
						break;
					}
					} 
				}
				setState(347);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,38,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class AssignmentContext extends ParserRuleContext {
		public AssignmentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignment; }
	 
		public AssignmentContext() { }
		public void copyFrom(AssignmentContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FakeAssignmentContext extends AssignmentContext {
		public Token op;
		public FakeLvalueContext fakeLvalue() {
			return getRuleContext(FakeLvalueContext.class,0);
		}
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(bellParser.ASSIGN, 0); }
		public TerminalNode APOW() { return getToken(bellParser.APOW, 0); }
		public TerminalNode ATIMES() { return getToken(bellParser.ATIMES, 0); }
		public TerminalNode ADIVDIV() { return getToken(bellParser.ADIVDIV, 0); }
		public TerminalNode ADIV() { return getToken(bellParser.ADIV, 0); }
		public TerminalNode AREM() { return getToken(bellParser.AREM, 0); }
		public TerminalNode APLUS() { return getToken(bellParser.APLUS, 0); }
		public TerminalNode AMINUS() { return getToken(bellParser.AMINUS, 0); }
		public TerminalNode ALOGAND() { return getToken(bellParser.ALOGAND, 0); }
		public TerminalNode ALOGANDEXT() { return getToken(bellParser.ALOGANDEXT, 0); }
		public TerminalNode ALOGXOR() { return getToken(bellParser.ALOGXOR, 0); }
		public TerminalNode ALOGOR() { return getToken(bellParser.ALOGOR, 0); }
		public TerminalNode ALOGOREXT() { return getToken(bellParser.ALOGOREXT, 0); }
		public TerminalNode ABITAND() { return getToken(bellParser.ABITAND, 0); }
		public TerminalNode ABITXOR() { return getToken(bellParser.ABITXOR, 0); }
		public TerminalNode ABITOR() { return getToken(bellParser.ABITOR, 0); }
		public TerminalNode ALSHIFT() { return getToken(bellParser.ALSHIFT, 0); }
		public TerminalNode ACONCAT() { return getToken(bellParser.ACONCAT, 0); }
		public TerminalNode ARCONCAT() { return getToken(bellParser.ARCONCAT, 0); }
		public TerminalNode ARSHIFT() { return getToken(bellParser.ARSHIFT, 0); }
		public FakeAssignmentContext(AssignmentContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DirOutletAssignmentContext extends AssignmentContext {
		public TerminalNode DIROUTLET() { return getToken(bellParser.DIROUTLET, 0); }
		public TerminalNode ASSIGN() { return getToken(bellParser.ASSIGN, 0); }
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public DirOutletAssignmentContext(AssignmentContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TrueAssignmentContext extends AssignmentContext {
		public Token op;
		public LvalueContext lvalue() {
			return getRuleContext(LvalueContext.class,0);
		}
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(bellParser.ASSIGN, 0); }
		public TerminalNode APOW() { return getToken(bellParser.APOW, 0); }
		public TerminalNode ATIMES() { return getToken(bellParser.ATIMES, 0); }
		public TerminalNode ADIVDIV() { return getToken(bellParser.ADIVDIV, 0); }
		public TerminalNode ADIV() { return getToken(bellParser.ADIV, 0); }
		public TerminalNode AREM() { return getToken(bellParser.AREM, 0); }
		public TerminalNode APLUS() { return getToken(bellParser.APLUS, 0); }
		public TerminalNode AMINUS() { return getToken(bellParser.AMINUS, 0); }
		public TerminalNode ALOGAND() { return getToken(bellParser.ALOGAND, 0); }
		public TerminalNode ALOGANDEXT() { return getToken(bellParser.ALOGANDEXT, 0); }
		public TerminalNode ALOGXOR() { return getToken(bellParser.ALOGXOR, 0); }
		public TerminalNode ALOGOR() { return getToken(bellParser.ALOGOR, 0); }
		public TerminalNode ALOGOREXT() { return getToken(bellParser.ALOGOREXT, 0); }
		public TerminalNode ABITAND() { return getToken(bellParser.ABITAND, 0); }
		public TerminalNode ABITXOR() { return getToken(bellParser.ABITXOR, 0); }
		public TerminalNode ABITOR() { return getToken(bellParser.ABITOR, 0); }
		public TerminalNode ALSHIFT() { return getToken(bellParser.ALSHIFT, 0); }
		public TerminalNode ARSHIFT() { return getToken(bellParser.ARSHIFT, 0); }
		public TerminalNode ACONCAT() { return getToken(bellParser.ACONCAT, 0); }
		public TerminalNode ARCONCAT() { return getToken(bellParser.ARCONCAT, 0); }
		public TerminalNode ANTH() { return getToken(bellParser.ANTH, 0); }
		public TrueAssignmentContext(AssignmentContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class OutletAssignmentContext extends AssignmentContext {
		public TerminalNode OUTLET() { return getToken(bellParser.OUTLET, 0); }
		public TerminalNode ASSIGN() { return getToken(bellParser.ASSIGN, 0); }
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public OutletAssignmentContext(AssignmentContext ctx) { copyFrom(ctx); }
	}

	public final AssignmentContext assignment() throws RecognitionException {
		AssignmentContext _localctx = new AssignmentContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_assignment);
		int _la;
		try {
			setState(362);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case GLOBALVAR:
			case PATCHERVAR:
			case LOCALVAR:
				_localctx = new TrueAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(348);
				lvalue();
				setState(349);
				((TrueAssignmentContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(((((_la - 38)) & ~0x3f) == 0 && ((1L << (_la - 38)) & 27772334426466953L) != 0)) ) {
					((TrueAssignmentContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(350);
				list();
				}
				break;
			case UINT:
			case UFLOAT:
			case UPITCH:
			case BTSYMBOL:
			case DQSYMBOL:
			case SQSYMBOL:
			case BACHNULL:
			case BACHNIL:
			case INLET:
			case INTINLET:
			case RATINLET:
			case FLOATINLET:
			case PITCHINLET:
			case DIRINLET:
			case BIF:
			case OF:
			case PUSH:
			case OPEN:
				_localctx = new FakeAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(352);
				fakeLvalue();
				setState(353);
				((FakeAssignmentContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(((((_la - 41)) & ~0x3f) == 0 && ((1L << (_la - 41)) & 3471541803308369L) != 0)) ) {
					((FakeAssignmentContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(354);
				list();
				}
				break;
			case OUTLET:
				_localctx = new OutletAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(356);
				match(OUTLET);
				setState(357);
				match(ASSIGN);
				setState(358);
				list();
				}
				break;
			case DIROUTLET:
				_localctx = new DirOutletAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(359);
				match(DIROUTLET);
				setState(360);
				match(ASSIGN);
				setState(361);
				list();
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
		public TerminalNode IF() { return getToken(bellParser.IF, 0); }
		public List<SequenceContext> sequence() {
			return getRuleContexts(SequenceContext.class);
		}
		public SequenceContext sequence(int i) {
			return getRuleContext(SequenceContext.class,i);
		}
		public TerminalNode THEN() { return getToken(bellParser.THEN, 0); }
		public TerminalNode ELSE() { return getToken(bellParser.ELSE, 0); }
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public IfthenelseContext(ConditionalContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class IfthenContext extends ConditionalContext {
		public TerminalNode IF() { return getToken(bellParser.IF, 0); }
		public SequenceContext sequence() {
			return getRuleContext(SequenceContext.class,0);
		}
		public TerminalNode THEN() { return getToken(bellParser.THEN, 0); }
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public IfthenContext(ConditionalContext ctx) { copyFrom(ctx); }
	}

	public final ConditionalContext conditional() throws RecognitionException {
		ConditionalContext _localctx = new ConditionalContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_conditional);
		try {
			setState(376);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,40,_ctx) ) {
			case 1:
				_localctx = new IfthenContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(364);
				match(IF);
				setState(365);
				sequence();
				setState(366);
				match(THEN);
				setState(367);
				list();
				}
				break;
			case 2:
				_localctx = new IfthenelseContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(369);
				match(IF);
				setState(370);
				sequence();
				setState(371);
				match(THEN);
				setState(372);
				sequence();
				setState(373);
				match(ELSE);
				setState(374);
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
	public static class ListContext extends ParserRuleContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_list; }
	}

	public final ListContext list() throws RecognitionException {
		ListContext _localctx = new ListContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_list);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(379); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(378);
					expr(0);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(381); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,41,_ctx);
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

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 11:
			return simpleFuncall_sempred((SimpleFuncallContext)_localctx, predIndex);
		case 20:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean simpleFuncall_sempred(SimpleFuncallContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 4);
		case 1:
			return precpred(_ctx, 3);
		case 2:
			return precpred(_ctx, 2);
		case 3:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 4:
			return precpred(_ctx, 17);
		case 5:
			return precpred(_ctx, 16);
		case 6:
			return precpred(_ctx, 14);
		case 7:
			return precpred(_ctx, 13);
		case 8:
			return precpred(_ctx, 12);
		case 9:
			return precpred(_ctx, 11);
		case 10:
			return precpred(_ctx, 10);
		case 11:
			return precpred(_ctx, 9);
		case 12:
			return precpred(_ctx, 8);
		case 13:
			return precpred(_ctx, 7);
		case 14:
			return precpred(_ctx, 6);
		case 15:
			return precpred(_ctx, 5);
		case 16:
			return precpred(_ctx, 4);
		case 17:
			return precpred(_ctx, 3);
		case 18:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001b\u0180\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0001\u0000\u0001\u0000"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0003\u0001;\b\u0001\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0003\u0002@\b\u0002\u0001\u0002\u0003\u0002C\b\u0002\u0001"+
		"\u0003\u0001\u0003\u0001\u0003\u0005\u0003H\b\u0003\n\u0003\f\u0003K\t"+
		"\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0005\u0004P\b\u0004\n\u0004"+
		"\f\u0004S\t\u0004\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0003"+
		"\u0005Y\b\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0006\u0001"+
		"\u0006\u0004\u0006`\b\u0006\u000b\u0006\f\u0006a\u0001\u0006\u0003\u0006"+
		"e\b\u0006\u0003\u0006g\b\u0006\u0001\u0007\u0001\u0007\u0004\u0007k\b"+
		"\u0007\u000b\u0007\f\u0007l\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\t\u0001\t\u0001\t\u0003\tw\b\t\u0001\t\u0001\t\u0005\t{\b\t\n\t\f\t~"+
		"\t\t\u0001\n\u0001\n\u0001\n\u0005\n\u0083\b\n\n\n\f\n\u0086\t\n\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u008b\b\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u0092\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003"+
		"\u000b\u009a\b\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0003\u000b\u00a2\b\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0003\u000b\u00a7\b\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003"+
		"\u000b\u00ac\b\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0003\u000b\u00bf\b\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0005"+
		"\u000b\u00c4\b\u000b\n\u000b\f\u000b\u00c7\t\u000b\u0001\f\u0001\f\u0001"+
		"\f\u0003\f\u00cc\b\f\u0001\r\u0001\r\u0001\r\u0001\r\u0004\r\u00d2\b\r"+
		"\u000b\r\f\r\u00d3\u0003\r\u00d6\b\r\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u00eb\b\u000e"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0003\u000f\u00f0\b\u000f\u0001\u0010"+
		"\u0001\u0010\u0001\u0010\u0001\u0010\u0003\u0010\u00f6\b\u0010\u0004\u0010"+
		"\u00f8\b\u0010\u000b\u0010\f\u0010\u00f9\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0003\u0010\u0100\b\u0010\u0005\u0010\u0102\b\u0010"+
		"\n\u0010\f\u0010\u0105\t\u0010\u0001\u0010\u0001\u0010\u0003\u0010\u0109"+
		"\b\u0010\u0001\u0011\u0001\u0011\u0003\u0011\u010d\b\u0011\u0001\u0012"+
		"\u0001\u0012\u0001\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0003\u0013\u0116\b\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0003\u0014\u011d\b\u0014\u0001\u0014\u0001\u0014\u0001\u0014"+
		"\u0004\u0014\u0122\b\u0014\u000b\u0014\f\u0014\u0123\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0003\u0014\u0129\b\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0005\u0014\u0158\b\u0014\n\u0014\f\u0014\u015b\t\u0014\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0003\u0015\u016b\b\u0015\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0003\u0016\u0179\b\u0016\u0001\u0017"+
		"\u0004\u0017\u017c\b\u0017\u000b\u0017\f\u0017\u017d\u0001\u0017\u0000"+
		"\u0002\u0016(\u0018\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014"+
		"\u0016\u0018\u001a\u001c\u001e \"$&(*,.\u0000\u000f\u0001\u0000\u0010"+
		"\u0011\u0001\u0000\u0007\b\u0001\u0000\u0012\u0016\u0002\u0000##%%\u0002"+
		"\u000088;;\u0001\u0000>?\u0004\u0000..002244\u0002\u00006699\u0002\u0000"+
		"TTVV\u0001\u0000<=\u0001\u0000@C\u0001\u0000JK\u0002\u0000PPRR\u0013\u0000"+
		"&&))--//11335577::EEGGIILMOOQQSSUUWW[\\\u0012\u0000))--//11335577::EE"+
		"GGIILMOOQQSSUUWW[\\\u01ba\u00000\u0001\u0000\u0000\u0000\u0002:\u0001"+
		"\u0000\u0000\u0000\u0004B\u0001\u0000\u0000\u0000\u0006D\u0001\u0000\u0000"+
		"\u0000\bL\u0001\u0000\u0000\u0000\nV\u0001\u0000\u0000\u0000\ff\u0001"+
		"\u0000\u0000\u0000\u000eh\u0001\u0000\u0000\u0000\u0010n\u0001\u0000\u0000"+
		"\u0000\u0012s\u0001\u0000\u0000\u0000\u0014\u007f\u0001\u0000\u0000\u0000"+
		"\u0016\u00ab\u0001\u0000\u0000\u0000\u0018\u00cb\u0001\u0000\u0000\u0000"+
		"\u001a\u00d5\u0001\u0000\u0000\u0000\u001c\u00ea\u0001\u0000\u0000\u0000"+
		"\u001e\u00ef\u0001\u0000\u0000\u0000 \u0108\u0001\u0000\u0000\u0000\""+
		"\u010a\u0001\u0000\u0000\u0000$\u010e\u0001\u0000\u0000\u0000&\u0115\u0001"+
		"\u0000\u0000\u0000(\u0128\u0001\u0000\u0000\u0000*\u016a\u0001\u0000\u0000"+
		"\u0000,\u0178\u0001\u0000\u0000\u0000.\u017b\u0001\u0000\u0000\u00000"+
		"1\u0003\u0002\u0001\u00001\u0001\u0001\u0000\u0000\u00002;\u0005\u0000"+
		"\u0000\u000134\u0003\f\u0006\u000045\u0005\u0000\u0000\u00015;\u0001\u0000"+
		"\u0000\u000067\u0003\f\u0006\u000078\u0005\u001f\u0000\u00008;\u0001\u0000"+
		"\u0000\u00009;\u0005\u001f\u0000\u0000:2\u0001\u0000\u0000\u0000:3\u0001"+
		"\u0000\u0000\u0000:6\u0001\u0000\u0000\u0000:9\u0001\u0000\u0000\u0000"+
		";\u0003\u0001\u0000\u0000\u0000<?\u0005\u001e\u0000\u0000=>\u0005)\u0000"+
		"\u0000>@\u0003.\u0017\u0000?=\u0001\u0000\u0000\u0000?@\u0001\u0000\u0000"+
		"\u0000@C\u0001\u0000\u0000\u0000AC\u0005a\u0000\u0000B<\u0001\u0000\u0000"+
		"\u0000BA\u0001\u0000\u0000\u0000C\u0005\u0001\u0000\u0000\u0000DI\u0003"+
		"\u0004\u0002\u0000EF\u0005\u0001\u0000\u0000FH\u0003\u0004\u0002\u0000"+
		"GE\u0001\u0000\u0000\u0000HK\u0001\u0000\u0000\u0000IG\u0001\u0000\u0000"+
		"\u0000IJ\u0001\u0000\u0000\u0000J\u0007\u0001\u0000\u0000\u0000KI\u0001"+
		"\u0000\u0000\u0000LQ\u0005`\u0000\u0000MN\u0005\u001e\u0000\u0000NP\u0005"+
		"\u0001\u0000\u0000OM\u0001\u0000\u0000\u0000PS\u0001\u0000\u0000\u0000"+
		"QO\u0001\u0000\u0000\u0000QR\u0001\u0000\u0000\u0000RT\u0001\u0000\u0000"+
		"\u0000SQ\u0001\u0000\u0000\u0000TU\u0005\u001e\u0000\u0000U\t\u0001\u0000"+
		"\u0000\u0000VX\u0003\u0006\u0003\u0000WY\u0003\b\u0004\u0000XW\u0001\u0000"+
		"\u0000\u0000XY\u0001\u0000\u0000\u0000YZ\u0001\u0000\u0000\u0000Z[\u0005"+
		"_\u0000\u0000[\\\u0003.\u0017\u0000\\\u000b\u0001\u0000\u0000\u0000]g"+
		"\u0003.\u0017\u0000^`\u0003\u000e\u0007\u0000_^\u0001\u0000\u0000\u0000"+
		"`a\u0001\u0000\u0000\u0000a_\u0001\u0000\u0000\u0000ab\u0001\u0000\u0000"+
		"\u0000bd\u0001\u0000\u0000\u0000ce\u0003.\u0017\u0000dc\u0001\u0000\u0000"+
		"\u0000de\u0001\u0000\u0000\u0000eg\u0001\u0000\u0000\u0000f]\u0001\u0000"+
		"\u0000\u0000f_\u0001\u0000\u0000\u0000g\r\u0001\u0000\u0000\u0000hj\u0003"+
		".\u0017\u0000ik\u0005(\u0000\u0000ji\u0001\u0000\u0000\u0000kl\u0001\u0000"+
		"\u0000\u0000lj\u0001\u0000\u0000\u0000lm\u0001\u0000\u0000\u0000m\u000f"+
		"\u0001\u0000\u0000\u0000no\u0005\u000e\u0000\u0000op\u0003\f\u0006\u0000"+
		"pq\u0007\u0000\u0000\u0000qr\u0003.\u0017\u0000r\u0011\u0001\u0000\u0000"+
		"\u0000st\u0005\u001f\u0000\u0000t|\u0003\f\u0006\u0000uw\u0005\u0001\u0000"+
		"\u0000vu\u0001\u0000\u0000\u0000vw\u0001\u0000\u0000\u0000wx\u0001\u0000"+
		"\u0000\u0000xy\u0005\u001f\u0000\u0000y{\u0003\f\u0006\u0000zv\u0001\u0000"+
		"\u0000\u0000{~\u0001\u0000\u0000\u0000|z\u0001\u0000\u0000\u0000|}\u0001"+
		"\u0000\u0000\u0000}\u0013\u0001\u0000\u0000\u0000~|\u0001\u0000\u0000"+
		"\u0000\u007f\u0084\u0003\f\u0006\u0000\u0080\u0081\u0005\u0001\u0000\u0000"+
		"\u0081\u0083\u0003\f\u0006\u0000\u0082\u0080\u0001\u0000\u0000\u0000\u0083"+
		"\u0086\u0001\u0000\u0000\u0000\u0084\u0082\u0001\u0000\u0000\u0000\u0084"+
		"\u0085\u0001\u0000\u0000\u0000\u0085\u0015\u0001\u0000\u0000\u0000\u0086"+
		"\u0084\u0001\u0000\u0000\u0000\u0087\u008a\u0006\u000b\uffff\uffff\u0000"+
		"\u0088\u008b\u0003\u001c\u000e\u0000\u0089\u008b\u0003\u001e\u000f\u0000"+
		"\u008a\u0088\u0001\u0000\u0000\u0000\u008a\u0089\u0001\u0000\u0000\u0000"+
		"\u008b\u008c\u0001\u0000\u0000\u0000\u008c\u008d\u0005^\u0000\u0000\u008d"+
		"\u008e\u0005\"\u0000\u0000\u008e\u00ac\u0001\u0000\u0000\u0000\u008f\u0092"+
		"\u0003\u001c\u000e\u0000\u0090\u0092\u0003\u001e\u000f\u0000\u0091\u008f"+
		"\u0001\u0000\u0000\u0000\u0091\u0090\u0001\u0000\u0000\u0000\u0092\u0093"+
		"\u0001\u0000\u0000\u0000\u0093\u0094\u0005^\u0000\u0000\u0094\u0095\u0003"+
		"\u0014\n\u0000\u0095\u0096\u0005\"\u0000\u0000\u0096\u00ac\u0001\u0000"+
		"\u0000\u0000\u0097\u009a\u0003\u001c\u000e\u0000\u0098\u009a\u0003\u001e"+
		"\u000f\u0000\u0099\u0097\u0001\u0000\u0000\u0000\u0099\u0098\u0001\u0000"+
		"\u0000\u0000\u009a\u009b\u0001\u0000\u0000\u0000\u009b\u009c\u0005^\u0000"+
		"\u0000\u009c\u009d\u0003\u0012\t\u0000\u009d\u009e\u0005\"\u0000\u0000"+
		"\u009e\u00ac\u0001\u0000\u0000\u0000\u009f\u00a2\u0003\u001c\u000e\u0000"+
		"\u00a0\u00a2\u0003\u001e\u000f\u0000\u00a1\u009f\u0001\u0000\u0000\u0000"+
		"\u00a1\u00a0\u0001\u0000\u0000\u0000\u00a2\u00a3\u0001\u0000\u0000\u0000"+
		"\u00a3\u00a4\u0005^\u0000\u0000\u00a4\u00a6\u0003\u0014\n\u0000\u00a5"+
		"\u00a7\u0005\u0001\u0000\u0000\u00a6\u00a5\u0001\u0000\u0000\u0000\u00a6"+
		"\u00a7\u0001\u0000\u0000\u0000\u00a7\u00a8\u0001\u0000\u0000\u0000\u00a8"+
		"\u00a9\u0003\u0012\t\u0000\u00a9\u00aa\u0005\"\u0000\u0000\u00aa\u00ac"+
		"\u0001\u0000\u0000\u0000\u00ab\u0087\u0001\u0000\u0000\u0000\u00ab\u0091"+
		"\u0001\u0000\u0000\u0000\u00ab\u0099\u0001\u0000\u0000\u0000\u00ab\u00a1"+
		"\u0001\u0000\u0000\u0000\u00ac\u00c5\u0001\u0000\u0000\u0000\u00ad\u00ae"+
		"\n\u0004\u0000\u0000\u00ae\u00af\u0005^\u0000\u0000\u00af\u00c4\u0005"+
		"\"\u0000\u0000\u00b0\u00b1\n\u0003\u0000\u0000\u00b1\u00b2\u0005^\u0000"+
		"\u0000\u00b2\u00b3\u0003\u0014\n\u0000\u00b3\u00b4\u0005\"\u0000\u0000"+
		"\u00b4\u00c4\u0001\u0000\u0000\u0000\u00b5\u00b6\n\u0002\u0000\u0000\u00b6"+
		"\u00b7\u0005^\u0000\u0000\u00b7\u00b8\u0003\u0012\t\u0000\u00b8\u00b9"+
		"\u0005\"\u0000\u0000\u00b9\u00c4\u0001\u0000\u0000\u0000\u00ba\u00bb\n"+
		"\u0001\u0000\u0000\u00bb\u00bc\u0005^\u0000\u0000\u00bc\u00be\u0003\u0014"+
		"\n\u0000\u00bd\u00bf\u0005\u0001\u0000\u0000\u00be\u00bd\u0001\u0000\u0000"+
		"\u0000\u00be\u00bf\u0001\u0000\u0000\u0000\u00bf\u00c0\u0001\u0000\u0000"+
		"\u0000\u00c0\u00c1\u0003\u0012\t\u0000\u00c1\u00c2\u0005\"\u0000\u0000"+
		"\u00c2\u00c4\u0001\u0000\u0000\u0000\u00c3\u00ad\u0001\u0000\u0000\u0000"+
		"\u00c3\u00b0\u0001\u0000\u0000\u0000\u00c3\u00b5\u0001\u0000\u0000\u0000"+
		"\u00c3\u00ba\u0001\u0000\u0000\u0000\u00c4\u00c7\u0001\u0000\u0000\u0000"+
		"\u00c5\u00c3\u0001\u0000\u0000\u0000\u00c5\u00c6\u0001\u0000\u0000\u0000"+
		"\u00c6\u0017\u0001\u0000\u0000\u0000\u00c7\u00c5\u0001\u0000\u0000\u0000"+
		"\u00c8\u00cc\u0003\u001c\u000e\u0000\u00c9\u00cc\u0003\u001e\u000f\u0000"+
		"\u00ca\u00cc\u0003\u0016\u000b\u0000\u00cb\u00c8\u0001\u0000\u0000\u0000"+
		"\u00cb\u00c9\u0001\u0000\u0000\u0000\u00cb\u00ca\u0001\u0000\u0000\u0000"+
		"\u00cc\u0019\u0001\u0000\u0000\u0000\u00cd\u00d6\u0003\u0016\u000b\u0000"+
		"\u00ce\u00d1\u0003\u0018\f\u0000\u00cf\u00d0\u0005%\u0000\u0000\u00d0"+
		"\u00d2\u0003\u0016\u000b\u0000\u00d1\u00cf\u0001\u0000\u0000\u0000\u00d2"+
		"\u00d3\u0001\u0000\u0000\u0000\u00d3\u00d1\u0001\u0000\u0000\u0000\u00d3"+
		"\u00d4\u0001\u0000\u0000\u0000\u00d4\u00d6\u0001\u0000\u0000\u0000\u00d5"+
		"\u00cd\u0001\u0000\u0000\u0000\u00d5\u00ce\u0001\u0000\u0000\u0000\u00d6"+
		"\u001b\u0001\u0000\u0000\u0000\u00d7\u00eb\u0005\u0003\u0000\u0000\u00d8"+
		"\u00eb\u0005\u0004\u0000\u0000\u00d9\u00eb\u0005\u0005\u0000\u0000\u00da"+
		"\u00eb\u0005\u0006\u0000\u0000\u00db\u00eb\u0007\u0001\u0000\u0000\u00dc"+
		"\u00eb\u0005\u001a\u0000\u0000\u00dd\u00eb\u0005\u001b\u0000\u0000\u00de"+
		"\u00eb\u0007\u0002\u0000\u0000\u00df\u00eb\u0005\u0018\u0000\u0000\u00e0"+
		"\u00eb\u0005\t\u0000\u0000\u00e1\u00eb\u0005\n\u0000\u0000\u00e2\u00e3"+
		"\u0005]\u0000\u0000\u00e3\u00e4\u0003\f\u0006\u0000\u00e4\u00e5\u0005"+
		"\"\u0000\u0000\u00e5\u00eb\u0001\u0000\u0000\u0000\u00e6\u00e7\u0005 "+
		"\u0000\u0000\u00e7\u00e8\u0003\f\u0006\u0000\u00e8\u00e9\u0005!\u0000"+
		"\u0000\u00e9\u00eb\u0001\u0000\u0000\u0000\u00ea\u00d7\u0001\u0000\u0000"+
		"\u0000\u00ea\u00d8\u0001\u0000\u0000\u0000\u00ea\u00d9\u0001\u0000\u0000"+
		"\u0000\u00ea\u00da\u0001\u0000\u0000\u0000\u00ea\u00db\u0001\u0000\u0000"+
		"\u0000\u00ea\u00dc\u0001\u0000\u0000\u0000\u00ea\u00dd\u0001\u0000\u0000"+
		"\u0000\u00ea\u00de\u0001\u0000\u0000\u0000\u00ea\u00df\u0001\u0000\u0000"+
		"\u0000\u00ea\u00e0\u0001\u0000\u0000\u0000\u00ea\u00e1\u0001\u0000\u0000"+
		"\u0000\u00ea\u00e2\u0001\u0000\u0000\u0000\u00ea\u00e6\u0001\u0000\u0000"+
		"\u0000\u00eb\u001d\u0001\u0000\u0000\u0000\u00ec\u00f0\u0005\u001e\u0000"+
		"\u0000\u00ed\u00f0\u0005\u001d\u0000\u0000\u00ee\u00f0\u0005\u001c\u0000"+
		"\u0000\u00ef\u00ec\u0001\u0000\u0000\u0000\u00ef\u00ed\u0001\u0000\u0000"+
		"\u0000\u00ef\u00ee\u0001\u0000\u0000\u0000\u00f0\u001f\u0001\u0000\u0000"+
		"\u0000\u00f1\u00f7\u0006\u0010\uffff\uffff\u0000\u00f2\u00f5\u0007\u0003"+
		"\u0000\u0000\u00f3\u00f6\u0003\u001c\u000e\u0000\u00f4\u00f6\u0003\u001e"+
		"\u000f\u0000\u00f5\u00f3\u0001\u0000\u0000\u0000\u00f5\u00f4\u0001\u0000"+
		"\u0000\u0000\u00f6\u00f8\u0001\u0000\u0000\u0000\u00f7\u00f2\u0001\u0000"+
		"\u0000\u0000\u00f8\u00f9\u0001\u0000\u0000\u0000\u00f9\u00f7\u0001\u0000"+
		"\u0000\u0000\u00f9\u00fa\u0001\u0000\u0000\u0000\u00fa\u0109\u0001\u0000"+
		"\u0000\u0000\u00fb\u0103\u0006\u0010\uffff\uffff\u0000\u00fc\u00ff\u0007"+
		"\u0003\u0000\u0000\u00fd\u0100\u0003\u001c\u000e\u0000\u00fe\u0100\u0003"+
		"\u001e\u000f\u0000\u00ff\u00fd\u0001\u0000\u0000\u0000\u00ff\u00fe\u0001"+
		"\u0000\u0000\u0000\u0100\u0102\u0001\u0000\u0000\u0000\u0101\u00fc\u0001"+
		"\u0000\u0000\u0000\u0102\u0105\u0001\u0000\u0000\u0000\u0103\u0101\u0001"+
		"\u0000\u0000\u0000\u0103\u0104\u0001\u0000\u0000\u0000\u0104\u0106\u0001"+
		"\u0000\u0000\u0000\u0105\u0103\u0001\u0000\u0000\u0000\u0106\u0107\u0007"+
		"\u0003\u0000\u0000\u0107\u0109\u0003,\u0016\u0000\u0108\u00f1\u0001\u0000"+
		"\u0000\u0000\u0108\u00fb\u0001\u0000\u0000\u0000\u0109!\u0001\u0000\u0000"+
		"\u0000\u010a\u010c\u0003\u001e\u000f\u0000\u010b\u010d\u0003 \u0010\u0000"+
		"\u010c\u010b\u0001\u0000\u0000\u0000\u010c\u010d\u0001\u0000\u0000\u0000"+
		"\u010d#\u0001\u0000\u0000\u0000\u010e\u010f\u0003\u001c\u000e\u0000\u010f"+
		"\u0110\u0003 \u0010\u0000\u0110%\u0001\u0000\u0000\u0000\u0111\u0116\u0003"+
		",\u0016\u0000\u0112\u0116\u0003*\u0015\u0000\u0113\u0116\u0003\u0010\b"+
		"\u0000\u0114\u0116\u0003\n\u0005\u0000\u0115\u0111\u0001\u0000\u0000\u0000"+
		"\u0115\u0112\u0001\u0000\u0000\u0000\u0115\u0113\u0001\u0000\u0000\u0000"+
		"\u0115\u0114\u0001\u0000\u0000\u0000\u0116\'\u0001\u0000\u0000\u0000\u0117"+
		"\u011c\u0006\u0014\uffff\uffff\u0000\u0118\u011d\u0003\u001c\u000e\u0000"+
		"\u0119\u011d\u0003\u001e\u000f\u0000\u011a\u011d\u0003\u001a\r\u0000\u011b"+
		"\u011d\u0003&\u0013\u0000\u011c\u0118\u0001\u0000\u0000\u0000\u011c\u0119"+
		"\u0001\u0000\u0000\u0000\u011c\u011a\u0001\u0000\u0000\u0000\u011c\u011b"+
		"\u0001\u0000\u0000\u0000\u011d\u0129\u0001\u0000\u0000\u0000\u011e\u0129"+
		"\u0003\"\u0011\u0000\u011f\u0129\u0003$\u0012\u0000\u0120\u0122\u0007"+
		"\u0004\u0000\u0000\u0121\u0120\u0001\u0000\u0000\u0000\u0122\u0123\u0001"+
		"\u0000\u0000\u0000\u0123\u0121\u0001\u0000\u0000\u0000\u0123\u0124\u0001"+
		"\u0000\u0000\u0000\u0124\u0125\u0001\u0000\u0000\u0000\u0125\u0129\u0003"+
		"(\u0014\u000f\u0126\u0127\u0007\u0005\u0000\u0000\u0127\u0129\u0003(\u0014"+
		"\u0001\u0128\u0117\u0001\u0000\u0000\u0000\u0128\u011e\u0001\u0000\u0000"+
		"\u0000\u0128\u011f\u0001\u0000\u0000\u0000\u0128\u0121\u0001\u0000\u0000"+
		"\u0000\u0128\u0126\u0001\u0000\u0000\u0000\u0129\u0159\u0001\u0000\u0000"+
		"\u0000\u012a\u012b\n\u0011\u0000\u0000\u012b\u012c\u0005$\u0000\u0000"+
		"\u012c\u0158\u0003(\u0014\u0012\u012d\u012e\n\u0010\u0000\u0000\u012e"+
		"\u012f\u0005,\u0000\u0000\u012f\u0158\u0003(\u0014\u0010\u0130\u0131\n"+
		"\u000e\u0000\u0000\u0131\u0132\u0007\u0006\u0000\u0000\u0132\u0158\u0003"+
		"(\u0014\u000f\u0133\u0134\n\r\u0000\u0000\u0134\u0135\u0007\u0007\u0000"+
		"\u0000\u0135\u0158\u0003(\u0014\u000e\u0136\u0137\n\f\u0000\u0000\u0137"+
		"\u0138\u0007\b\u0000\u0000\u0138\u0158\u0003(\u0014\r\u0139\u013a\n\u000b"+
		"\u0000\u0000\u013a\u013b\u0005\u0002\u0000\u0000\u013b\u0158\u0003(\u0014"+
		"\f\u013c\u013d\n\n\u0000\u0000\u013d\u013e\u0005X\u0000\u0000\u013e\u0158"+
		"\u0003(\u0014\u000b\u013f\u0140\n\t\u0000\u0000\u0140\u0141\u0007\t\u0000"+
		"\u0000\u0141\u0158\u0003(\u0014\n\u0142\u0143\n\b\u0000\u0000\u0143\u0144"+
		"\u0007\n\u0000\u0000\u0144\u0158\u0003(\u0014\t\u0145\u0146\n\u0007\u0000"+
		"\u0000\u0146\u0147\u0005D\u0000\u0000\u0147\u0158\u0003(\u0014\b\u0148"+
		"\u0149\n\u0006\u0000\u0000\u0149\u014a\u0005F\u0000\u0000\u014a\u0158"+
		"\u0003(\u0014\u0007\u014b\u014c\n\u0005\u0000\u0000\u014c\u014d\u0005"+
		"H\u0000\u0000\u014d\u0158\u0003(\u0014\u0006\u014e\u014f\n\u0004\u0000"+
		"\u0000\u014f\u0150\u0007\u000b\u0000\u0000\u0150\u0158\u0003(\u0014\u0005"+
		"\u0151\u0152\n\u0003\u0000\u0000\u0152\u0153\u0005N\u0000\u0000\u0153"+
		"\u0158\u0003(\u0014\u0004\u0154\u0155\n\u0002\u0000\u0000\u0155\u0156"+
		"\u0007\f\u0000\u0000\u0156\u0158\u0003(\u0014\u0003\u0157\u012a\u0001"+
		"\u0000\u0000\u0000\u0157\u012d\u0001\u0000\u0000\u0000\u0157\u0130\u0001"+
		"\u0000\u0000\u0000\u0157\u0133\u0001\u0000\u0000\u0000\u0157\u0136\u0001"+
		"\u0000\u0000\u0000\u0157\u0139\u0001\u0000\u0000\u0000\u0157\u013c\u0001"+
		"\u0000\u0000\u0000\u0157\u013f\u0001\u0000\u0000\u0000\u0157\u0142\u0001"+
		"\u0000\u0000\u0000\u0157\u0145\u0001\u0000\u0000\u0000\u0157\u0148\u0001"+
		"\u0000\u0000\u0000\u0157\u014b\u0001\u0000\u0000\u0000\u0157\u014e\u0001"+
		"\u0000\u0000\u0000\u0157\u0151\u0001\u0000\u0000\u0000\u0157\u0154\u0001"+
		"\u0000\u0000\u0000\u0158\u015b\u0001\u0000\u0000\u0000\u0159\u0157\u0001"+
		"\u0000\u0000\u0000\u0159\u015a\u0001\u0000\u0000\u0000\u015a)\u0001\u0000"+
		"\u0000\u0000\u015b\u0159\u0001\u0000\u0000\u0000\u015c\u015d\u0003\"\u0011"+
		"\u0000\u015d\u015e\u0007\r\u0000\u0000\u015e\u015f\u0003.\u0017\u0000"+
		"\u015f\u016b\u0001\u0000\u0000\u0000\u0160\u0161\u0003$\u0012\u0000\u0161"+
		"\u0162\u0007\u000e\u0000\u0000\u0162\u0163\u0003.\u0017\u0000\u0163\u016b"+
		"\u0001\u0000\u0000\u0000\u0164\u0165\u0005\u0017\u0000\u0000\u0165\u0166"+
		"\u0005)\u0000\u0000\u0166\u016b\u0003.\u0017\u0000\u0167\u0168\u0005\u0019"+
		"\u0000\u0000\u0168\u0169\u0005)\u0000\u0000\u0169\u016b\u0003.\u0017\u0000"+
		"\u016a\u015c\u0001\u0000\u0000\u0000\u016a\u0160\u0001\u0000\u0000\u0000"+
		"\u016a\u0164\u0001\u0000\u0000\u0000\u016a\u0167\u0001\u0000\u0000\u0000"+
		"\u016b+\u0001\u0000\u0000\u0000\u016c\u016d\u0005\u000b\u0000\u0000\u016d"+
		"\u016e\u0003\f\u0006\u0000\u016e\u016f\u0005\f\u0000\u0000\u016f\u0170"+
		"\u0003.\u0017\u0000\u0170\u0179\u0001\u0000\u0000\u0000\u0171\u0172\u0005"+
		"\u000b\u0000\u0000\u0172\u0173\u0003\f\u0006\u0000\u0173\u0174\u0005\f"+
		"\u0000\u0000\u0174\u0175\u0003\f\u0006\u0000\u0175\u0176\u0005\r\u0000"+
		"\u0000\u0176\u0177\u0003.\u0017\u0000\u0177\u0179\u0001\u0000\u0000\u0000"+
		"\u0178\u016c\u0001\u0000\u0000\u0000\u0178\u0171\u0001\u0000\u0000\u0000"+
		"\u0179-\u0001\u0000\u0000\u0000\u017a\u017c\u0003(\u0014\u0000\u017b\u017a"+
		"\u0001\u0000\u0000\u0000\u017c\u017d\u0001\u0000\u0000\u0000\u017d\u017b"+
		"\u0001\u0000\u0000\u0000\u017d\u017e\u0001\u0000\u0000\u0000\u017e/\u0001"+
		"\u0000\u0000\u0000*:?BIQXadflv|\u0084\u008a\u0091\u0099\u00a1\u00a6\u00ab"+
		"\u00be\u00c3\u00c5\u00cb\u00d3\u00d5\u00ea\u00ef\u00f5\u00f9\u00ff\u0103"+
		"\u0108\u010c\u0115\u011c\u0123\u0128\u0157\u0159\u016a\u0178\u017d";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}