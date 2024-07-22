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
		BACHNULL=9, BACHNIL=10, IF=11, THEN=12, ELSE=13, WHILE=14, FOR=15, IN=16, 
		AS=17, WITH=18, DO=19, COLLECT=20, INLET=21, INTINLET=22, RATINLET=23, 
		FLOATINLET=24, PITCHINLET=25, OUTLET=26, DIRINLET=27, DIROUTLET=28, BIF=29, 
		OF=30, GLOBALVAR=31, PATCHERVAR=32, LOCALVAR=33, NAMEDPARAM=34, KEEP=35, 
		UNKEEP=36, INIT=37, ARGCOUNT=38, PUSH=39, POP=40, CLOSED=41, NTH=42, PICK=43, 
		KEY=44, ANTH=45, APICK=46, NULLIFY=47, ASSIGN=48, WHITESPACE=49, NEWATOM=50, 
		POW=51, APOW=52, TIMES=53, ATIMES=54, DIVDIV=55, ADIVDIV=56, DIV=57, ADIV=58, 
		REM=59, AREM=60, PLUS=61, APLUS=62, UPLUS=63, MINUS=64, AMINUS=65, UMINUS=66, 
		EQUAL=67, NEQ=68, LOGNOT=69, BITNOT=70, LT=71, GT=72, LEQ=73, GEQ=74, 
		BITAND=75, ABITAND=76, BITXOR=77, ABITXOR=78, BITOR=79, ABITOR=80, LOGAND=81, 
		LOGANDEXT=82, ALOGAND=83, ALOGANDEXT=84, LOGXOR=85, ALOGXOR=86, LOGOR=87, 
		ALOGOR=88, LOGOREXT=89, ALOGOREXT=90, LSHIFT=91, ALSHIFT=92, RSHIFT=93, 
		ARSHIFT=94, REPEAT=95, AREPEAT=96, AAPPLY=97, ACONCAT=98, ARCONCAT=99, 
		OPEN=100, PARAMS=101, FUNDEF=102, LIFT=103, ELLIPSIS=104, ANYTHING=105;
	public static final int
		RULE_everything = 0, RULE_program = 1, RULE_funarg = 2, RULE_funargList = 3, 
		RULE_liftedargList = 4, RULE_fundef = 5, RULE_sequence = 6, RULE_nullified = 7, 
		RULE_whileloop = 8, RULE_forarg = 9, RULE_forargList = 10, RULE_forloop = 11, 
		RULE_argsByNameList = 12, RULE_argsByPositionList = 13, RULE_simpleFuncall = 14, 
		RULE_dataFlowAndLvalueSpecsUItem = 15, RULE_dataFlowAndLvalueSpecsItem = 16, 
		RULE_funcall = 17, RULE_var = 18, RULE_lvalueSpecsUFinal = 19, RULE_lvalueSpecsFinal = 20, 
		RULE_lvalueSpecs = 21, RULE_lvalue = 22, RULE_fakeLvalue = 23, RULE_listEnd = 24, 
		RULE_expr = 25, RULE_item = 26, RULE_assignment = 27, RULE_conditional = 28, 
		RULE_list = 29;
	private static String[] makeRuleNames() {
		return new String[] {
			"everything", "program", "funarg", "funargList", "liftedargList", "fundef", 
			"sequence", "nullified", "whileloop", "forarg", "forargList", "forloop", 
			"argsByNameList", "argsByPositionList", "simpleFuncall", "dataFlowAndLvalueSpecsUItem", 
			"dataFlowAndLvalueSpecsItem", "funcall", "var", "lvalueSpecsUFinal", 
			"lvalueSpecsFinal", "lvalueSpecs", "lvalue", "fakeLvalue", "listEnd", 
			"expr", "item", "assignment", "conditional", "list"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "','", "'...'", null, null, null, null, null, null, "'null'", "'nil'", 
			"'if'", "'then'", "'else'", "'while'", "'for'", "'in'", "'as'", "'with'", 
			"'do'", "'collect'", null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, "'keep'", "'unkeep'", "'init'", "'$argcount'", 
			"'['", "']'", "')'", "':'", "'::'", "'.'", "':='", "'::='", "';'", "'='", 
			null, null, "'**'", "'**='", "'*'", "'*='", "'//'", "'//='", "'/'", "'/='", 
			null, null, null, "'+='", "'+'", null, "'-='", "'-'", "'=='", "'!='", 
			"'!'", "'~'", "'<'", "'>'", "'<='", "'>='", "'&'", "'&='", "'^'", "'^='", 
			"'|'", "'|='", "'&&'", "'&&&'", "'&&='", "'&&&='", "'^^'", "'^^='", "'||'", 
			"'||='", "'|||'", "'|||='", "'<<'", "'<<='", "'>>'", "'>>='", "':*'", 
			"':*='", "'.='", "'_='", "'!_='", null, null, "'->'", "'-^'", "'<...>'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, "RANGE", "UINT", "UFLOAT", "UPITCH", "BTSYMBOL", "DQSYMBOL", 
			"SQSYMBOL", "BACHNULL", "BACHNIL", "IF", "THEN", "ELSE", "WHILE", "FOR", 
			"IN", "AS", "WITH", "DO", "COLLECT", "INLET", "INTINLET", "RATINLET", 
			"FLOATINLET", "PITCHINLET", "OUTLET", "DIRINLET", "DIROUTLET", "BIF", 
			"OF", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "NAMEDPARAM", "KEEP", "UNKEEP", 
			"INIT", "ARGCOUNT", "PUSH", "POP", "CLOSED", "NTH", "PICK", "KEY", "ANTH", 
			"APICK", "NULLIFY", "ASSIGN", "WHITESPACE", "NEWATOM", "POW", "APOW", 
			"TIMES", "ATIMES", "DIVDIV", "ADIVDIV", "DIV", "ADIV", "REM", "AREM", 
			"PLUS", "APLUS", "UPLUS", "MINUS", "AMINUS", "UMINUS", "EQUAL", "NEQ", 
			"LOGNOT", "BITNOT", "LT", "GT", "LEQ", "GEQ", "BITAND", "ABITAND", "BITXOR", 
			"ABITXOR", "BITOR", "ABITOR", "LOGAND", "LOGANDEXT", "ALOGAND", "ALOGANDEXT", 
			"LOGXOR", "ALOGXOR", "LOGOR", "ALOGOR", "LOGOREXT", "ALOGOREXT", "LSHIFT", 
			"ALSHIFT", "RSHIFT", "ARSHIFT", "REPEAT", "AREPEAT", "AAPPLY", "ACONCAT", 
			"ARCONCAT", "OPEN", "PARAMS", "FUNDEF", "LIFT", "ELLIPSIS", "ANYTHING"
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
			setState(60);
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
			setState(70);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				_localctx = new ProgramEOFContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(62);
				match(EOF);
				}
				break;
			case 2:
				_localctx = new ProgramSequenceContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(63);
				sequence();
				setState(64);
				match(EOF);
				}
				break;
			case 3:
				_localctx = new ProgramSequenceNamedparamContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(66);
				sequence();
				setState(67);
				match(NAMEDPARAM);
				}
				break;
			case 4:
				_localctx = new ProgramNamedparamContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(69);
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
			setState(78);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LOCALVAR:
				_localctx = new FunargVarContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(72);
				match(LOCALVAR);
				setState(75);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ASSIGN) {
					{
					setState(73);
					match(ASSIGN);
					setState(74);
					list();
					}
				}

				}
				break;
			case ELLIPSIS:
				_localctx = new FunargEllipsisContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(77);
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
			setState(80);
			funarg();
			setState(85);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__0) {
				{
				{
				setState(81);
				match(T__0);
				setState(82);
				funarg();
				}
				}
				setState(87);
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
			setState(88);
			match(LIFT);
			setState(93);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(89);
					match(LOCALVAR);
					setState(90);
					match(T__0);
					}
					} 
				}
				setState(95);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			}
			setState(96);
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
			setState(98);
			funargList();
			setState(100);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LIFT) {
				{
				setState(99);
				liftedargList();
				}
			}

			setState(102);
			match(FUNDEF);
			setState(103);
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
			setState(114);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(105);
				list();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(107); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(106);
						nullified();
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(109); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(112);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & -9223370954525061128L) != 0) || ((((_la - 66)) & ~0x3f) == 0 && ((1L << (_la - 66)) & 292057776153L) != 0)) {
					{
					setState(111);
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
			setState(116);
			list();
			setState(118); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(117);
				match(NULLIFY);
				}
				}
				setState(120); 
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
			setState(122);
			match(WHILE);
			setState(123);
			sequence();
			setState(124);
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
			setState(125);
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
	public static class ForargContext extends ParserRuleContext {
		public List<TerminalNode> LOCALVAR() { return getTokens(bellParser.LOCALVAR); }
		public TerminalNode LOCALVAR(int i) {
			return getToken(bellParser.LOCALVAR, i);
		}
		public TerminalNode IN() { return getToken(bellParser.IN, 0); }
		public SequenceContext sequence() {
			return getRuleContext(SequenceContext.class,0);
		}
		public ForargContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forarg; }
	}

	public final ForargContext forarg() throws RecognitionException {
		ForargContext _localctx = new ForargContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_forarg);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(127);
			match(LOCALVAR);
			{
			setState(129);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LOCALVAR) {
				{
				setState(128);
				match(LOCALVAR);
				}
			}

			}
			setState(131);
			match(IN);
			setState(132);
			sequence();
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
	public static class ForargListContext extends ParserRuleContext {
		public List<ForargContext> forarg() {
			return getRuleContexts(ForargContext.class);
		}
		public ForargContext forarg(int i) {
			return getRuleContext(ForargContext.class,i);
		}
		public ForargListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forargList; }
	}

	public final ForargListContext forargList() throws RecognitionException {
		ForargListContext _localctx = new ForargListContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_forargList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(134);
			forarg();
			setState(139);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__0) {
				{
				{
				setState(135);
				match(T__0);
				setState(136);
				forarg();
				}
				}
				setState(141);
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
	public static class ForloopContext extends ParserRuleContext {
		public Token kind;
		public TerminalNode FOR() { return getToken(bellParser.FOR, 0); }
		public ForargListContext forargList() {
			return getRuleContext(ForargListContext.class,0);
		}
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public TerminalNode DO() { return getToken(bellParser.DO, 0); }
		public TerminalNode COLLECT() { return getToken(bellParser.COLLECT, 0); }
		public TerminalNode AS() { return getToken(bellParser.AS, 0); }
		public SequenceContext sequence() {
			return getRuleContext(SequenceContext.class,0);
		}
		public TerminalNode WITH() { return getToken(bellParser.WITH, 0); }
		public ArgsByNameListContext argsByNameList() {
			return getRuleContext(ArgsByNameListContext.class,0);
		}
		public ForloopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forloop; }
	}

	public final ForloopContext forloop() throws RecognitionException {
		ForloopContext _localctx = new ForloopContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_forloop);
		int _la;
		try {
			setState(169);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(142);
				match(FOR);
				setState(143);
				forargList();
				setState(144);
				((ForloopContext)_localctx).kind = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==DO || _la==COLLECT) ) {
					((ForloopContext)_localctx).kind = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(145);
				list();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(147);
				match(FOR);
				setState(148);
				forargList();
				setState(149);
				match(AS);
				setState(150);
				sequence();
				setState(153);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WITH) {
					{
					setState(151);
					match(WITH);
					setState(152);
					argsByNameList();
					}
				}

				setState(155);
				((ForloopContext)_localctx).kind = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==DO || _la==COLLECT) ) {
					((ForloopContext)_localctx).kind = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(156);
				list();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(158);
				match(FOR);
				setState(159);
				forargList();
				setState(160);
				match(WITH);
				setState(161);
				argsByNameList();
				setState(164);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==AS) {
					{
					setState(162);
					match(AS);
					setState(163);
					sequence();
					}
				}

				setState(166);
				((ForloopContext)_localctx).kind = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==DO || _la==COLLECT) ) {
					((ForloopContext)_localctx).kind = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(167);
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
		enterRule(_localctx, 24, RULE_argsByNameList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(171);
			match(NAMEDPARAM);
			setState(172);
			sequence();
			setState(180);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__0 || _la==NAMEDPARAM) {
				{
				{
				setState(174);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__0) {
					{
					setState(173);
					match(T__0);
					}
				}

				setState(176);
				match(NAMEDPARAM);
				setState(177);
				sequence();
				}
				}
				setState(182);
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
		enterRule(_localctx, 26, RULE_argsByPositionList);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(183);
			sequence();
			setState(188);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(184);
					match(T__0);
					setState(185);
					sequence();
					}
					} 
				}
				setState(190);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
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
		int _startState = 28;
		enterRecursionRule(_localctx, 28, RULE_simpleFuncall, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(227);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
			case 1:
				{
				setState(194);
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
				case ARGCOUNT:
				case PUSH:
				case OPEN:
					{
					setState(192);
					item();
					}
					break;
				case GLOBALVAR:
				case PATCHERVAR:
				case LOCALVAR:
				case KEEP:
				case UNKEEP:
					{
					setState(193);
					var();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(196);
				match(PARAMS);
				setState(197);
				match(CLOSED);
				}
				break;
			case 2:
				{
				setState(201);
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
				case ARGCOUNT:
				case PUSH:
				case OPEN:
					{
					setState(199);
					item();
					}
					break;
				case GLOBALVAR:
				case PATCHERVAR:
				case LOCALVAR:
				case KEEP:
				case UNKEEP:
					{
					setState(200);
					var();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(203);
				match(PARAMS);
				setState(204);
				argsByPositionList();
				setState(205);
				match(CLOSED);
				}
				break;
			case 3:
				{
				setState(209);
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
				case ARGCOUNT:
				case PUSH:
				case OPEN:
					{
					setState(207);
					item();
					}
					break;
				case GLOBALVAR:
				case PATCHERVAR:
				case LOCALVAR:
				case KEEP:
				case UNKEEP:
					{
					setState(208);
					var();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(211);
				match(PARAMS);
				setState(212);
				argsByNameList();
				setState(213);
				match(CLOSED);
				}
				break;
			case 4:
				{
				setState(217);
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
				case ARGCOUNT:
				case PUSH:
				case OPEN:
					{
					setState(215);
					item();
					}
					break;
				case GLOBALVAR:
				case PATCHERVAR:
				case LOCALVAR:
				case KEEP:
				case UNKEEP:
					{
					setState(216);
					var();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(219);
				match(PARAMS);
				setState(220);
				argsByPositionList();
				setState(222);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__0) {
					{
					setState(221);
					match(T__0);
					}
				}

				setState(224);
				argsByNameList();
				setState(225);
				match(CLOSED);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(253);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(251);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
					case 1:
						{
						_localctx = new SimpleFuncallContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_simpleFuncall);
						setState(229);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(230);
						match(PARAMS);
						setState(231);
						match(CLOSED);
						}
						break;
					case 2:
						{
						_localctx = new SimpleFuncallContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_simpleFuncall);
						setState(232);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(233);
						match(PARAMS);
						setState(234);
						argsByPositionList();
						setState(235);
						match(CLOSED);
						}
						break;
					case 3:
						{
						_localctx = new SimpleFuncallContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_simpleFuncall);
						setState(237);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(238);
						match(PARAMS);
						setState(239);
						argsByNameList();
						setState(240);
						match(CLOSED);
						}
						break;
					case 4:
						{
						_localctx = new SimpleFuncallContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_simpleFuncall);
						setState(242);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(243);
						match(PARAMS);
						setState(244);
						argsByPositionList();
						setState(246);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==T__0) {
							{
							setState(245);
							match(T__0);
							}
						}

						setState(248);
						argsByNameList();
						setState(249);
						match(CLOSED);
						}
						break;
					}
					} 
				}
				setState(255);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
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
	public static class DataFlowAndLvalueSpecsUItemContext extends ParserRuleContext {
		public ItemContext item() {
			return getRuleContext(ItemContext.class,0);
		}
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public SimpleFuncallContext simpleFuncall() {
			return getRuleContext(SimpleFuncallContext.class,0);
		}
		public DataFlowAndLvalueSpecsUItemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_dataFlowAndLvalueSpecsUItem; }
	}

	public final DataFlowAndLvalueSpecsUItemContext dataFlowAndLvalueSpecsUItem() throws RecognitionException {
		DataFlowAndLvalueSpecsUItemContext _localctx = new DataFlowAndLvalueSpecsUItemContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_dataFlowAndLvalueSpecsUItem);
		try {
			setState(259);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,27,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(256);
				item();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(257);
				var();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(258);
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
	public static class DataFlowAndLvalueSpecsItemContext extends ParserRuleContext {
		public DataFlowAndLvalueSpecsUItemContext dataFlowAndLvalueSpecsUItem() {
			return getRuleContext(DataFlowAndLvalueSpecsUItemContext.class,0);
		}
		public List<TerminalNode> UPLUS() { return getTokens(bellParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(bellParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(bellParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(bellParser.UMINUS, i);
		}
		public DataFlowAndLvalueSpecsItemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_dataFlowAndLvalueSpecsItem; }
	}

	public final DataFlowAndLvalueSpecsItemContext dataFlowAndLvalueSpecsItem() throws RecognitionException {
		DataFlowAndLvalueSpecsItemContext _localctx = new DataFlowAndLvalueSpecsItemContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_dataFlowAndLvalueSpecsItem);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(264);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==UPLUS || _la==UMINUS) {
				{
				{
				setState(261);
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
				setState(266);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(267);
			dataFlowAndLvalueSpecsUItem();
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
		public DataFlowAndLvalueSpecsItemContext dataFlowAndLvalueSpecsItem() {
			return getRuleContext(DataFlowAndLvalueSpecsItemContext.class,0);
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
		enterRule(_localctx, 34, RULE_funcall);
		try {
			int _alt;
			setState(277);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,30,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(269);
				simpleFuncall(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(270);
				dataFlowAndLvalueSpecsItem();
				setState(273); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(271);
						match(KEY);
						setState(272);
						simpleFuncall(0);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(275); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
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
		public TerminalNode KEEP() { return getToken(bellParser.KEEP, 0); }
		public TerminalNode UNKEEP() { return getToken(bellParser.UNKEEP, 0); }
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
		enterRule(_localctx, 36, RULE_var);
		int _la;
		try {
			setState(285);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LOCALVAR:
			case KEEP:
			case UNKEEP:
				_localctx = new VarLocalContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(280);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==KEEP || _la==UNKEEP) {
					{
					setState(279);
					_la = _input.LA(1);
					if ( !(_la==KEEP || _la==UNKEEP) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
				}

				setState(282);
				match(LOCALVAR);
				}
				break;
			case PATCHERVAR:
				_localctx = new VarPatcherContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(283);
				match(PATCHERVAR);
				}
				break;
			case GLOBALVAR:
				_localctx = new VarGlobalContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(284);
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
	public static class LvalueSpecsUFinalContext extends ParserRuleContext {
		public ConditionalContext conditional() {
			return getRuleContext(ConditionalContext.class,0);
		}
		public WhileloopContext whileloop() {
			return getRuleContext(WhileloopContext.class,0);
		}
		public ForloopContext forloop() {
			return getRuleContext(ForloopContext.class,0);
		}
		public FundefContext fundef() {
			return getRuleContext(FundefContext.class,0);
		}
		public LvalueSpecsUFinalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lvalueSpecsUFinal; }
	}

	public final LvalueSpecsUFinalContext lvalueSpecsUFinal() throws RecognitionException {
		LvalueSpecsUFinalContext _localctx = new LvalueSpecsUFinalContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_lvalueSpecsUFinal);
		try {
			setState(291);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IF:
				enterOuterAlt(_localctx, 1);
				{
				setState(287);
				conditional();
				}
				break;
			case WHILE:
				enterOuterAlt(_localctx, 2);
				{
				setState(288);
				whileloop();
				}
				break;
			case FOR:
				enterOuterAlt(_localctx, 3);
				{
				setState(289);
				forloop();
				}
				break;
			case LOCALVAR:
			case ELLIPSIS:
				enterOuterAlt(_localctx, 4);
				{
				setState(290);
				fundef();
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
	public static class LvalueSpecsFinalContext extends ParserRuleContext {
		public LvalueSpecsUFinalContext lvalueSpecsUFinal() {
			return getRuleContext(LvalueSpecsUFinalContext.class,0);
		}
		public List<TerminalNode> UPLUS() { return getTokens(bellParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(bellParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(bellParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(bellParser.UMINUS, i);
		}
		public LvalueSpecsFinalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lvalueSpecsFinal; }
	}

	public final LvalueSpecsFinalContext lvalueSpecsFinal() throws RecognitionException {
		LvalueSpecsFinalContext _localctx = new LvalueSpecsFinalContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_lvalueSpecsFinal);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(296);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==UPLUS || _la==UMINUS) {
				{
				{
				setState(293);
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
				setState(298);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(299);
			lvalueSpecsUFinal();
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
		public List<DataFlowAndLvalueSpecsItemContext> dataFlowAndLvalueSpecsItem() {
			return getRuleContexts(DataFlowAndLvalueSpecsItemContext.class);
		}
		public DataFlowAndLvalueSpecsItemContext dataFlowAndLvalueSpecsItem(int i) {
			return getRuleContext(DataFlowAndLvalueSpecsItemContext.class,i);
		}
		public List<TerminalNode> NTH() { return getTokens(bellParser.NTH); }
		public TerminalNode NTH(int i) {
			return getToken(bellParser.NTH, i);
		}
		public List<TerminalNode> KEY() { return getTokens(bellParser.KEY); }
		public TerminalNode KEY(int i) {
			return getToken(bellParser.KEY, i);
		}
		public LvalueSpecsFinalContext lvalueSpecsFinal() {
			return getRuleContext(LvalueSpecsFinalContext.class,0);
		}
		public LvalueSpecsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lvalueSpecs; }
	}

	public final LvalueSpecsContext lvalueSpecs() throws RecognitionException {
		LvalueSpecsContext _localctx = new LvalueSpecsContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_lvalueSpecs);
		int _la;
		try {
			int _alt;
			setState(318);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,37,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				ending = false;
				setState(304); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(302);
						_la = _input.LA(1);
						if ( !(_la==NTH || _la==KEY) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(303);
						dataFlowAndLvalueSpecsItem();
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(306); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,35,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				ending = true;
				setState(313);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,36,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(309);
						_la = _input.LA(1);
						if ( !(_la==NTH || _la==KEY) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(310);
						dataFlowAndLvalueSpecsItem();
						}
						} 
					}
					setState(315);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,36,_ctx);
				}
				{
				setState(316);
				_la = _input.LA(1);
				if ( !(_la==NTH || _la==KEY) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(317);
				lvalueSpecsFinal();
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
		enterRule(_localctx, 44, RULE_lvalue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(320);
			var();
			setState(322);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,38,_ctx) ) {
			case 1:
				{
				setState(321);
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
		enterRule(_localctx, 46, RULE_fakeLvalue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(324);
			item();
			setState(325);
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
		public ForloopContext forloop() {
			return getRuleContext(ForloopContext.class,0);
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
		enterRule(_localctx, 48, RULE_listEnd);
		try {
			setState(332);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,39,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(327);
				conditional();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(328);
				assignment();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(329);
				whileloop();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(330);
				forloop();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(331);
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
		int _startState = 50;
		enterRecursionRule(_localctx, 50, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(351);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,42,_ctx) ) {
			case 1:
				{
				_localctx = new ExprSimpleContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(339);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,40,_ctx) ) {
				case 1:
					{
					setState(335);
					item();
					}
					break;
				case 2:
					{
					setState(336);
					var();
					}
					break;
				case 3:
					{
					setState(337);
					funcall();
					}
					break;
				case 4:
					{
					setState(338);
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
				setState(341);
				lvalue();
				}
				break;
			case 3:
				{
				_localctx = new ExprFakeLvalueContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(342);
				fakeLvalue();
				}
				break;
			case 4:
				{
				_localctx = new ExprUPlusMinusContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(344); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(343);
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
					setState(346); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,41,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(348);
				expr(15);
				}
				break;
			case 5:
				{
				_localctx = new ExprNotContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(349);
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
				setState(350);
				expr(1);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(400);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,44,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(398);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,43,_ctx) ) {
					case 1:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(353);
						if (!(precpred(_ctx, 17))) throw new FailedPredicateException(this, "precpred(_ctx, 17)");
						setState(354);
						match(PICK);
						setState(355);
						expr(18);
						}
						break;
					case 2:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(356);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(357);
						((ExprBinaryContext)_localctx).op = match(POW);
						setState(358);
						expr(16);
						}
						break;
					case 3:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(359);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(360);
						((ExprBinaryContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 765611936652984320L) != 0)) ) {
							((ExprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(361);
						expr(15);
						}
						break;
					case 4:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(362);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(363);
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
						setState(364);
						expr(14);
						}
						break;
					case 5:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(365);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(366);
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
						setState(367);
						expr(13);
						}
						break;
					case 6:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(368);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(369);
						((ExprBinaryContext)_localctx).op = match(RANGE);
						setState(370);
						expr(12);
						}
						break;
					case 7:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(371);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(372);
						((ExprBinaryContext)_localctx).op = match(REPEAT);
						setState(373);
						expr(11);
						}
						break;
					case 8:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(374);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(375);
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
						setState(376);
						expr(10);
						}
						break;
					case 9:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(377);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(378);
						((ExprBinaryContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(((((_la - 71)) & ~0x3f) == 0 && ((1L << (_la - 71)) & 15L) != 0)) ) {
							((ExprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(379);
						expr(9);
						}
						break;
					case 10:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(380);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(381);
						((ExprBinaryContext)_localctx).op = match(BITAND);
						setState(382);
						expr(8);
						}
						break;
					case 11:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(383);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(384);
						((ExprBinaryContext)_localctx).op = match(BITXOR);
						setState(385);
						expr(7);
						}
						break;
					case 12:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(386);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(387);
						((ExprBinaryContext)_localctx).op = match(BITOR);
						setState(388);
						expr(6);
						}
						break;
					case 13:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(389);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(390);
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
						setState(391);
						expr(5);
						}
						break;
					case 14:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(392);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(393);
						((ExprBinaryContext)_localctx).op = match(LOGXOR);
						setState(394);
						expr(4);
						}
						break;
					case 15:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(395);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(396);
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
						setState(397);
						expr(3);
						}
						break;
					}
					} 
				}
				setState(402);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,44,_ctx);
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
	public static class ItemArgcountContext extends ItemContext {
		public TerminalNode ARGCOUNT() { return getToken(bellParser.ARGCOUNT, 0); }
		public ItemArgcountContext(ItemContext ctx) { copyFrom(ctx); }
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
		enterRule(_localctx, 52, RULE_item);
		int _la;
		try {
			setState(423);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case UINT:
				_localctx = new ItemUintContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(403);
				match(UINT);
				}
				break;
			case UFLOAT:
				_localctx = new ItemUfloatContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(404);
				match(UFLOAT);
				}
				break;
			case UPITCH:
				_localctx = new ItemUpitchContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(405);
				match(UPITCH);
				}
				break;
			case BTSYMBOL:
				_localctx = new ItemBtSymbolContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(406);
				match(BTSYMBOL);
				}
				break;
			case DQSYMBOL:
			case SQSYMBOL:
				_localctx = new ItemQSymbolContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(407);
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
				setState(408);
				match(BIF);
				}
				break;
			case OF:
				_localctx = new ItemOFContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(409);
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
				setState(410);
				((ItemInletContext)_localctx).type = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 65011712L) != 0)) ) {
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
				setState(411);
				match(DIRINLET);
				}
				break;
			case ARGCOUNT:
				_localctx = new ItemArgcountContext(_localctx);
				enterOuterAlt(_localctx, 10);
				{
				setState(412);
				match(ARGCOUNT);
				}
				break;
			case BACHNULL:
				_localctx = new ItemNullContext(_localctx);
				enterOuterAlt(_localctx, 11);
				{
				setState(413);
				match(BACHNULL);
				}
				break;
			case BACHNIL:
				_localctx = new ItemNilContext(_localctx);
				enterOuterAlt(_localctx, 12);
				{
				setState(414);
				match(BACHNIL);
				}
				break;
			case OPEN:
				_localctx = new ItemSequenceContext(_localctx);
				enterOuterAlt(_localctx, 13);
				{
				setState(415);
				match(OPEN);
				setState(416);
				sequence();
				setState(417);
				match(CLOSED);
				}
				break;
			case PUSH:
				_localctx = new ItemSublistContext(_localctx);
				enterOuterAlt(_localctx, 14);
				{
				setState(419);
				match(PUSH);
				setState(420);
				sequence();
				setState(421);
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
	public static class InitAssignmentContext extends AssignmentContext {
		public TerminalNode INIT() { return getToken(bellParser.INIT, 0); }
		public TerminalNode LOCALVAR() { return getToken(bellParser.LOCALVAR, 0); }
		public TerminalNode ASSIGN() { return getToken(bellParser.ASSIGN, 0); }
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public InitAssignmentContext(AssignmentContext ctx) { copyFrom(ctx); }
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
		enterRule(_localctx, 54, RULE_assignment);
		int _la;
		try {
			setState(443);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INIT:
				_localctx = new InitAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(425);
				match(INIT);
				setState(426);
				match(LOCALVAR);
				setState(427);
				match(ASSIGN);
				setState(428);
				list();
				}
				break;
			case GLOBALVAR:
			case PATCHERVAR:
			case LOCALVAR:
			case KEEP:
			case UNKEEP:
				_localctx = new TrueAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(429);
				lvalue();
				setState(430);
				((TrueAssignmentContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(((((_la - 45)) & ~0x3f) == 0 && ((1L << (_la - 45)) & 27772334426466953L) != 0)) ) {
					((TrueAssignmentContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(431);
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
			case ARGCOUNT:
			case PUSH:
			case OPEN:
				_localctx = new FakeAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(433);
				fakeLvalue();
				setState(434);
				((FakeAssignmentContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(((((_la - 48)) & ~0x3f) == 0 && ((1L << (_la - 48)) & 3471541803308369L) != 0)) ) {
					((FakeAssignmentContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(435);
				list();
				}
				break;
			case OUTLET:
				_localctx = new OutletAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(437);
				match(OUTLET);
				setState(438);
				match(ASSIGN);
				setState(439);
				list();
				}
				break;
			case DIROUTLET:
				_localctx = new DirOutletAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(440);
				match(DIROUTLET);
				setState(441);
				match(ASSIGN);
				setState(442);
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
		enterRule(_localctx, 56, RULE_conditional);
		try {
			setState(457);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,47,_ctx) ) {
			case 1:
				_localctx = new IfthenContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(445);
				match(IF);
				setState(446);
				sequence();
				setState(447);
				match(THEN);
				setState(448);
				list();
				}
				break;
			case 2:
				_localctx = new IfthenelseContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(450);
				match(IF);
				setState(451);
				sequence();
				setState(452);
				match(THEN);
				setState(453);
				sequence();
				setState(454);
				match(ELSE);
				setState(455);
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
		enterRule(_localctx, 58, RULE_list);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(460); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(459);
					expr(0);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(462); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,48,_ctx);
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
		case 14:
			return simpleFuncall_sempred((SimpleFuncallContext)_localctx, predIndex);
		case 25:
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
		"\u0004\u0001i\u01d1\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018"+
		"\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002\u001b\u0007\u001b"+
		"\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d\u0001\u0000\u0001\u0000"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0003\u0001G\b\u0001\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0003\u0002L\b\u0002\u0001\u0002\u0003\u0002O\b\u0002\u0001"+
		"\u0003\u0001\u0003\u0001\u0003\u0005\u0003T\b\u0003\n\u0003\f\u0003W\t"+
		"\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0005\u0004\\\b\u0004\n\u0004"+
		"\f\u0004_\t\u0004\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0003"+
		"\u0005e\b\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0006\u0001"+
		"\u0006\u0004\u0006l\b\u0006\u000b\u0006\f\u0006m\u0001\u0006\u0003\u0006"+
		"q\b\u0006\u0003\u0006s\b\u0006\u0001\u0007\u0001\u0007\u0004\u0007w\b"+
		"\u0007\u000b\u0007\f\u0007x\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\t\u0001\t\u0003\t\u0082\b\t\u0001\t\u0001\t\u0001\t\u0001\n\u0001\n\u0001"+
		"\n\u0005\n\u008a\b\n\n\n\f\n\u008d\t\n\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0003\u000b\u009a\b\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0003\u000b\u00a5\b\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0003\u000b\u00aa\b\u000b\u0001\f\u0001\f\u0001\f\u0003\f\u00af\b\f\u0001"+
		"\f\u0001\f\u0005\f\u00b3\b\f\n\f\f\f\u00b6\t\f\u0001\r\u0001\r\u0001\r"+
		"\u0005\r\u00bb\b\r\n\r\f\r\u00be\t\r\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0003\u000e\u00c3\b\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0003\u000e\u00ca\b\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u00d2\b\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0003\u000e"+
		"\u00da\b\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u00df\b"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u00e4\b\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u00f7"+
		"\b\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0005\u000e\u00fc\b\u000e"+
		"\n\u000e\f\u000e\u00ff\t\u000e\u0001\u000f\u0001\u000f\u0001\u000f\u0003"+
		"\u000f\u0104\b\u000f\u0001\u0010\u0005\u0010\u0107\b\u0010\n\u0010\f\u0010"+
		"\u010a\t\u0010\u0001\u0010\u0001\u0010\u0001\u0011\u0001\u0011\u0001\u0011"+
		"\u0001\u0011\u0004\u0011\u0112\b\u0011\u000b\u0011\f\u0011\u0113\u0003"+
		"\u0011\u0116\b\u0011\u0001\u0012\u0003\u0012\u0119\b\u0012\u0001\u0012"+
		"\u0001\u0012\u0001\u0012\u0003\u0012\u011e\b\u0012\u0001\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0003\u0013\u0124\b\u0013\u0001\u0014\u0005\u0014"+
		"\u0127\b\u0014\n\u0014\f\u0014\u012a\t\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0004\u0015\u0131\b\u0015\u000b\u0015\f"+
		"\u0015\u0132\u0001\u0015\u0001\u0015\u0001\u0015\u0005\u0015\u0138\b\u0015"+
		"\n\u0015\f\u0015\u013b\t\u0015\u0001\u0015\u0001\u0015\u0003\u0015\u013f"+
		"\b\u0015\u0001\u0016\u0001\u0016\u0003\u0016\u0143\b\u0016\u0001\u0017"+
		"\u0001\u0017\u0001\u0017\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0003\u0018\u014d\b\u0018\u0001\u0019\u0001\u0019\u0001\u0019"+
		"\u0001\u0019\u0001\u0019\u0003\u0019\u0154\b\u0019\u0001\u0019\u0001\u0019"+
		"\u0001\u0019\u0004\u0019\u0159\b\u0019\u000b\u0019\f\u0019\u015a\u0001"+
		"\u0019\u0001\u0019\u0001\u0019\u0003\u0019\u0160\b\u0019\u0001\u0019\u0001"+
		"\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001"+
		"\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001"+
		"\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001"+
		"\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001"+
		"\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001"+
		"\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001"+
		"\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001"+
		"\u0019\u0001\u0019\u0005\u0019\u018f\b\u0019\n\u0019\f\u0019\u0192\t\u0019"+
		"\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a"+
		"\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a"+
		"\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a"+
		"\u0001\u001a\u0001\u001a\u0003\u001a\u01a8\b\u001a\u0001\u001b\u0001\u001b"+
		"\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b"+
		"\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b"+
		"\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0003\u001b\u01bc\b\u001b"+
		"\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001c"+
		"\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001c"+
		"\u0003\u001c\u01ca\b\u001c\u0001\u001d\u0004\u001d\u01cd\b\u001d\u000b"+
		"\u001d\f\u001d\u01ce\u0001\u001d\u0000\u0002\u001c2\u001e\u0000\u0002"+
		"\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e"+
		" \"$&(*,.02468:\u0000\u0010\u0001\u0000\u0013\u0014\u0002\u0000??BB\u0001"+
		"\u0000#$\u0002\u0000**,,\u0001\u0000EF\u0004\u0000557799;;\u0002\u0000"+
		"==@@\u0002\u0000[[]]\u0001\u0000CD\u0001\u0000GJ\u0001\u0000QR\u0002\u0000"+
		"WWYY\u0001\u0000\u0007\b\u0001\u0000\u0015\u0019\u0013\u0000--0044668"+
		"8::<<>>AALLNNPPSTVVXXZZ\\\\^^bc\u0012\u000000446688::<<>>AALLNNPPSTVV"+
		"XXZZ\\\\^^bc\u0212\u0000<\u0001\u0000\u0000\u0000\u0002F\u0001\u0000\u0000"+
		"\u0000\u0004N\u0001\u0000\u0000\u0000\u0006P\u0001\u0000\u0000\u0000\b"+
		"X\u0001\u0000\u0000\u0000\nb\u0001\u0000\u0000\u0000\fr\u0001\u0000\u0000"+
		"\u0000\u000et\u0001\u0000\u0000\u0000\u0010z\u0001\u0000\u0000\u0000\u0012"+
		"\u007f\u0001\u0000\u0000\u0000\u0014\u0086\u0001\u0000\u0000\u0000\u0016"+
		"\u00a9\u0001\u0000\u0000\u0000\u0018\u00ab\u0001\u0000\u0000\u0000\u001a"+
		"\u00b7\u0001\u0000\u0000\u0000\u001c\u00e3\u0001\u0000\u0000\u0000\u001e"+
		"\u0103\u0001\u0000\u0000\u0000 \u0108\u0001\u0000\u0000\u0000\"\u0115"+
		"\u0001\u0000\u0000\u0000$\u011d\u0001\u0000\u0000\u0000&\u0123\u0001\u0000"+
		"\u0000\u0000(\u0128\u0001\u0000\u0000\u0000*\u013e\u0001\u0000\u0000\u0000"+
		",\u0140\u0001\u0000\u0000\u0000.\u0144\u0001\u0000\u0000\u00000\u014c"+
		"\u0001\u0000\u0000\u00002\u015f\u0001\u0000\u0000\u00004\u01a7\u0001\u0000"+
		"\u0000\u00006\u01bb\u0001\u0000\u0000\u00008\u01c9\u0001\u0000\u0000\u0000"+
		":\u01cc\u0001\u0000\u0000\u0000<=\u0003\u0002\u0001\u0000=\u0001\u0001"+
		"\u0000\u0000\u0000>G\u0005\u0000\u0000\u0001?@\u0003\f\u0006\u0000@A\u0005"+
		"\u0000\u0000\u0001AG\u0001\u0000\u0000\u0000BC\u0003\f\u0006\u0000CD\u0005"+
		"\"\u0000\u0000DG\u0001\u0000\u0000\u0000EG\u0005\"\u0000\u0000F>\u0001"+
		"\u0000\u0000\u0000F?\u0001\u0000\u0000\u0000FB\u0001\u0000\u0000\u0000"+
		"FE\u0001\u0000\u0000\u0000G\u0003\u0001\u0000\u0000\u0000HK\u0005!\u0000"+
		"\u0000IJ\u00050\u0000\u0000JL\u0003:\u001d\u0000KI\u0001\u0000\u0000\u0000"+
		"KL\u0001\u0000\u0000\u0000LO\u0001\u0000\u0000\u0000MO\u0005h\u0000\u0000"+
		"NH\u0001\u0000\u0000\u0000NM\u0001\u0000\u0000\u0000O\u0005\u0001\u0000"+
		"\u0000\u0000PU\u0003\u0004\u0002\u0000QR\u0005\u0001\u0000\u0000RT\u0003"+
		"\u0004\u0002\u0000SQ\u0001\u0000\u0000\u0000TW\u0001\u0000\u0000\u0000"+
		"US\u0001\u0000\u0000\u0000UV\u0001\u0000\u0000\u0000V\u0007\u0001\u0000"+
		"\u0000\u0000WU\u0001\u0000\u0000\u0000X]\u0005g\u0000\u0000YZ\u0005!\u0000"+
		"\u0000Z\\\u0005\u0001\u0000\u0000[Y\u0001\u0000\u0000\u0000\\_\u0001\u0000"+
		"\u0000\u0000][\u0001\u0000\u0000\u0000]^\u0001\u0000\u0000\u0000^`\u0001"+
		"\u0000\u0000\u0000_]\u0001\u0000\u0000\u0000`a\u0005!\u0000\u0000a\t\u0001"+
		"\u0000\u0000\u0000bd\u0003\u0006\u0003\u0000ce\u0003\b\u0004\u0000dc\u0001"+
		"\u0000\u0000\u0000de\u0001\u0000\u0000\u0000ef\u0001\u0000\u0000\u0000"+
		"fg\u0005f\u0000\u0000gh\u0003:\u001d\u0000h\u000b\u0001\u0000\u0000\u0000"+
		"is\u0003:\u001d\u0000jl\u0003\u000e\u0007\u0000kj\u0001\u0000\u0000\u0000"+
		"lm\u0001\u0000\u0000\u0000mk\u0001\u0000\u0000\u0000mn\u0001\u0000\u0000"+
		"\u0000np\u0001\u0000\u0000\u0000oq\u0003:\u001d\u0000po\u0001\u0000\u0000"+
		"\u0000pq\u0001\u0000\u0000\u0000qs\u0001\u0000\u0000\u0000ri\u0001\u0000"+
		"\u0000\u0000rk\u0001\u0000\u0000\u0000s\r\u0001\u0000\u0000\u0000tv\u0003"+
		":\u001d\u0000uw\u0005/\u0000\u0000vu\u0001\u0000\u0000\u0000wx\u0001\u0000"+
		"\u0000\u0000xv\u0001\u0000\u0000\u0000xy\u0001\u0000\u0000\u0000y\u000f"+
		"\u0001\u0000\u0000\u0000z{\u0005\u000e\u0000\u0000{|\u0003\f\u0006\u0000"+
		"|}\u0007\u0000\u0000\u0000}~\u0003:\u001d\u0000~\u0011\u0001\u0000\u0000"+
		"\u0000\u007f\u0081\u0005!\u0000\u0000\u0080\u0082\u0005!\u0000\u0000\u0081"+
		"\u0080\u0001\u0000\u0000\u0000\u0081\u0082\u0001\u0000\u0000\u0000\u0082"+
		"\u0083\u0001\u0000\u0000\u0000\u0083\u0084\u0005\u0010\u0000\u0000\u0084"+
		"\u0085\u0003\f\u0006\u0000\u0085\u0013\u0001\u0000\u0000\u0000\u0086\u008b"+
		"\u0003\u0012\t\u0000\u0087\u0088\u0005\u0001\u0000\u0000\u0088\u008a\u0003"+
		"\u0012\t\u0000\u0089\u0087\u0001\u0000\u0000\u0000\u008a\u008d\u0001\u0000"+
		"\u0000\u0000\u008b\u0089\u0001\u0000\u0000\u0000\u008b\u008c\u0001\u0000"+
		"\u0000\u0000\u008c\u0015\u0001\u0000\u0000\u0000\u008d\u008b\u0001\u0000"+
		"\u0000\u0000\u008e\u008f\u0005\u000f\u0000\u0000\u008f\u0090\u0003\u0014"+
		"\n\u0000\u0090\u0091\u0007\u0000\u0000\u0000\u0091\u0092\u0003:\u001d"+
		"\u0000\u0092\u00aa\u0001\u0000\u0000\u0000\u0093\u0094\u0005\u000f\u0000"+
		"\u0000\u0094\u0095\u0003\u0014\n\u0000\u0095\u0096\u0005\u0011\u0000\u0000"+
		"\u0096\u0099\u0003\f\u0006\u0000\u0097\u0098\u0005\u0012\u0000\u0000\u0098"+
		"\u009a\u0003\u0018\f\u0000\u0099\u0097\u0001\u0000\u0000\u0000\u0099\u009a"+
		"\u0001\u0000\u0000\u0000\u009a\u009b\u0001\u0000\u0000\u0000\u009b\u009c"+
		"\u0007\u0000\u0000\u0000\u009c\u009d\u0003:\u001d\u0000\u009d\u00aa\u0001"+
		"\u0000\u0000\u0000\u009e\u009f\u0005\u000f\u0000\u0000\u009f\u00a0\u0003"+
		"\u0014\n\u0000\u00a0\u00a1\u0005\u0012\u0000\u0000\u00a1\u00a4\u0003\u0018"+
		"\f\u0000\u00a2\u00a3\u0005\u0011\u0000\u0000\u00a3\u00a5\u0003\f\u0006"+
		"\u0000\u00a4\u00a2\u0001\u0000\u0000\u0000\u00a4\u00a5\u0001\u0000\u0000"+
		"\u0000\u00a5\u00a6\u0001\u0000\u0000\u0000\u00a6\u00a7\u0007\u0000\u0000"+
		"\u0000\u00a7\u00a8\u0003:\u001d\u0000\u00a8\u00aa\u0001\u0000\u0000\u0000"+
		"\u00a9\u008e\u0001\u0000\u0000\u0000\u00a9\u0093\u0001\u0000\u0000\u0000"+
		"\u00a9\u009e\u0001\u0000\u0000\u0000\u00aa\u0017\u0001\u0000\u0000\u0000"+
		"\u00ab\u00ac\u0005\"\u0000\u0000\u00ac\u00b4\u0003\f\u0006\u0000\u00ad"+
		"\u00af\u0005\u0001\u0000\u0000\u00ae\u00ad\u0001\u0000\u0000\u0000\u00ae"+
		"\u00af\u0001\u0000\u0000\u0000\u00af\u00b0\u0001\u0000\u0000\u0000\u00b0"+
		"\u00b1\u0005\"\u0000\u0000\u00b1\u00b3\u0003\f\u0006\u0000\u00b2\u00ae"+
		"\u0001\u0000\u0000\u0000\u00b3\u00b6\u0001\u0000\u0000\u0000\u00b4\u00b2"+
		"\u0001\u0000\u0000\u0000\u00b4\u00b5\u0001\u0000\u0000\u0000\u00b5\u0019"+
		"\u0001\u0000\u0000\u0000\u00b6\u00b4\u0001\u0000\u0000\u0000\u00b7\u00bc"+
		"\u0003\f\u0006\u0000\u00b8\u00b9\u0005\u0001\u0000\u0000\u00b9\u00bb\u0003"+
		"\f\u0006\u0000\u00ba\u00b8\u0001\u0000\u0000\u0000\u00bb\u00be\u0001\u0000"+
		"\u0000\u0000\u00bc\u00ba\u0001\u0000\u0000\u0000\u00bc\u00bd\u0001\u0000"+
		"\u0000\u0000\u00bd\u001b\u0001\u0000\u0000\u0000\u00be\u00bc\u0001\u0000"+
		"\u0000\u0000\u00bf\u00c2\u0006\u000e\uffff\uffff\u0000\u00c0\u00c3\u0003"+
		"4\u001a\u0000\u00c1\u00c3\u0003$\u0012\u0000\u00c2\u00c0\u0001\u0000\u0000"+
		"\u0000\u00c2\u00c1\u0001\u0000\u0000\u0000\u00c3\u00c4\u0001\u0000\u0000"+
		"\u0000\u00c4\u00c5\u0005e\u0000\u0000\u00c5\u00c6\u0005)\u0000\u0000\u00c6"+
		"\u00e4\u0001\u0000\u0000\u0000\u00c7\u00ca\u00034\u001a\u0000\u00c8\u00ca"+
		"\u0003$\u0012\u0000\u00c9\u00c7\u0001\u0000\u0000\u0000\u00c9\u00c8\u0001"+
		"\u0000\u0000\u0000\u00ca\u00cb\u0001\u0000\u0000\u0000\u00cb\u00cc\u0005"+
		"e\u0000\u0000\u00cc\u00cd\u0003\u001a\r\u0000\u00cd\u00ce\u0005)\u0000"+
		"\u0000\u00ce\u00e4\u0001\u0000\u0000\u0000\u00cf\u00d2\u00034\u001a\u0000"+
		"\u00d0\u00d2\u0003$\u0012\u0000\u00d1\u00cf\u0001\u0000\u0000\u0000\u00d1"+
		"\u00d0\u0001\u0000\u0000\u0000\u00d2\u00d3\u0001\u0000\u0000\u0000\u00d3"+
		"\u00d4\u0005e\u0000\u0000\u00d4\u00d5\u0003\u0018\f\u0000\u00d5\u00d6"+
		"\u0005)\u0000\u0000\u00d6\u00e4\u0001\u0000\u0000\u0000\u00d7\u00da\u0003"+
		"4\u001a\u0000\u00d8\u00da\u0003$\u0012\u0000\u00d9\u00d7\u0001\u0000\u0000"+
		"\u0000\u00d9\u00d8\u0001\u0000\u0000\u0000\u00da\u00db\u0001\u0000\u0000"+
		"\u0000\u00db\u00dc\u0005e\u0000\u0000\u00dc\u00de\u0003\u001a\r\u0000"+
		"\u00dd\u00df\u0005\u0001\u0000\u0000\u00de\u00dd\u0001\u0000\u0000\u0000"+
		"\u00de\u00df\u0001\u0000\u0000\u0000\u00df\u00e0\u0001\u0000\u0000\u0000"+
		"\u00e0\u00e1\u0003\u0018\f\u0000\u00e1\u00e2\u0005)\u0000\u0000\u00e2"+
		"\u00e4\u0001\u0000\u0000\u0000\u00e3\u00bf\u0001\u0000\u0000\u0000\u00e3"+
		"\u00c9\u0001\u0000\u0000\u0000\u00e3\u00d1\u0001\u0000\u0000\u0000\u00e3"+
		"\u00d9\u0001\u0000\u0000\u0000\u00e4\u00fd\u0001\u0000\u0000\u0000\u00e5"+
		"\u00e6\n\u0004\u0000\u0000\u00e6\u00e7\u0005e\u0000\u0000\u00e7\u00fc"+
		"\u0005)\u0000\u0000\u00e8\u00e9\n\u0003\u0000\u0000\u00e9\u00ea\u0005"+
		"e\u0000\u0000\u00ea\u00eb\u0003\u001a\r\u0000\u00eb\u00ec\u0005)\u0000"+
		"\u0000\u00ec\u00fc\u0001\u0000\u0000\u0000\u00ed\u00ee\n\u0002\u0000\u0000"+
		"\u00ee\u00ef\u0005e\u0000\u0000\u00ef\u00f0\u0003\u0018\f\u0000\u00f0"+
		"\u00f1\u0005)\u0000\u0000\u00f1\u00fc\u0001\u0000\u0000\u0000\u00f2\u00f3"+
		"\n\u0001\u0000\u0000\u00f3\u00f4\u0005e\u0000\u0000\u00f4\u00f6\u0003"+
		"\u001a\r\u0000\u00f5\u00f7\u0005\u0001\u0000\u0000\u00f6\u00f5\u0001\u0000"+
		"\u0000\u0000\u00f6\u00f7\u0001\u0000\u0000\u0000\u00f7\u00f8\u0001\u0000"+
		"\u0000\u0000\u00f8\u00f9\u0003\u0018\f\u0000\u00f9\u00fa\u0005)\u0000"+
		"\u0000\u00fa\u00fc\u0001\u0000\u0000\u0000\u00fb\u00e5\u0001\u0000\u0000"+
		"\u0000\u00fb\u00e8\u0001\u0000\u0000\u0000\u00fb\u00ed\u0001\u0000\u0000"+
		"\u0000\u00fb\u00f2\u0001\u0000\u0000\u0000\u00fc\u00ff\u0001\u0000\u0000"+
		"\u0000\u00fd\u00fb\u0001\u0000\u0000\u0000\u00fd\u00fe\u0001\u0000\u0000"+
		"\u0000\u00fe\u001d\u0001\u0000\u0000\u0000\u00ff\u00fd\u0001\u0000\u0000"+
		"\u0000\u0100\u0104\u00034\u001a\u0000\u0101\u0104\u0003$\u0012\u0000\u0102"+
		"\u0104\u0003\u001c\u000e\u0000\u0103\u0100\u0001\u0000\u0000\u0000\u0103"+
		"\u0101\u0001\u0000\u0000\u0000\u0103\u0102\u0001\u0000\u0000\u0000\u0104"+
		"\u001f\u0001\u0000\u0000\u0000\u0105\u0107\u0007\u0001\u0000\u0000\u0106"+
		"\u0105\u0001\u0000\u0000\u0000\u0107\u010a\u0001\u0000\u0000\u0000\u0108"+
		"\u0106\u0001\u0000\u0000\u0000\u0108\u0109\u0001\u0000\u0000\u0000\u0109"+
		"\u010b\u0001\u0000\u0000\u0000\u010a\u0108\u0001\u0000\u0000\u0000\u010b"+
		"\u010c\u0003\u001e\u000f\u0000\u010c!\u0001\u0000\u0000\u0000\u010d\u0116"+
		"\u0003\u001c\u000e\u0000\u010e\u0111\u0003 \u0010\u0000\u010f\u0110\u0005"+
		",\u0000\u0000\u0110\u0112\u0003\u001c\u000e\u0000\u0111\u010f\u0001\u0000"+
		"\u0000\u0000\u0112\u0113\u0001\u0000\u0000\u0000\u0113\u0111\u0001\u0000"+
		"\u0000\u0000\u0113\u0114\u0001\u0000\u0000\u0000\u0114\u0116\u0001\u0000"+
		"\u0000\u0000\u0115\u010d\u0001\u0000\u0000\u0000\u0115\u010e\u0001\u0000"+
		"\u0000\u0000\u0116#\u0001\u0000\u0000\u0000\u0117\u0119\u0007\u0002\u0000"+
		"\u0000\u0118\u0117\u0001\u0000\u0000\u0000\u0118\u0119\u0001\u0000\u0000"+
		"\u0000\u0119\u011a\u0001\u0000\u0000\u0000\u011a\u011e\u0005!\u0000\u0000"+
		"\u011b\u011e\u0005 \u0000\u0000\u011c\u011e\u0005\u001f\u0000\u0000\u011d"+
		"\u0118\u0001\u0000\u0000\u0000\u011d\u011b\u0001\u0000\u0000\u0000\u011d"+
		"\u011c\u0001\u0000\u0000\u0000\u011e%\u0001\u0000\u0000\u0000\u011f\u0124"+
		"\u00038\u001c\u0000\u0120\u0124\u0003\u0010\b\u0000\u0121\u0124\u0003"+
		"\u0016\u000b\u0000\u0122\u0124\u0003\n\u0005\u0000\u0123\u011f\u0001\u0000"+
		"\u0000\u0000\u0123\u0120\u0001\u0000\u0000\u0000\u0123\u0121\u0001\u0000"+
		"\u0000\u0000\u0123\u0122\u0001\u0000\u0000\u0000\u0124\'\u0001\u0000\u0000"+
		"\u0000\u0125\u0127\u0007\u0001\u0000\u0000\u0126\u0125\u0001\u0000\u0000"+
		"\u0000\u0127\u012a\u0001\u0000\u0000\u0000\u0128\u0126\u0001\u0000\u0000"+
		"\u0000\u0128\u0129\u0001\u0000\u0000\u0000\u0129\u012b\u0001\u0000\u0000"+
		"\u0000\u012a\u0128\u0001\u0000\u0000\u0000\u012b\u012c\u0003&\u0013\u0000"+
		"\u012c)\u0001\u0000\u0000\u0000\u012d\u0130\u0006\u0015\uffff\uffff\u0000"+
		"\u012e\u012f\u0007\u0003\u0000\u0000\u012f\u0131\u0003 \u0010\u0000\u0130"+
		"\u012e\u0001\u0000\u0000\u0000\u0131\u0132\u0001\u0000\u0000\u0000\u0132"+
		"\u0130\u0001\u0000\u0000\u0000\u0132\u0133\u0001\u0000\u0000\u0000\u0133"+
		"\u013f\u0001\u0000\u0000\u0000\u0134\u0139\u0006\u0015\uffff\uffff\u0000"+
		"\u0135\u0136\u0007\u0003\u0000\u0000\u0136\u0138\u0003 \u0010\u0000\u0137"+
		"\u0135\u0001\u0000\u0000\u0000\u0138\u013b\u0001\u0000\u0000\u0000\u0139"+
		"\u0137\u0001\u0000\u0000\u0000\u0139\u013a\u0001\u0000\u0000\u0000\u013a"+
		"\u013c\u0001\u0000\u0000\u0000\u013b\u0139\u0001\u0000\u0000\u0000\u013c"+
		"\u013d\u0007\u0003\u0000\u0000\u013d\u013f\u0003(\u0014\u0000\u013e\u012d"+
		"\u0001\u0000\u0000\u0000\u013e\u0134\u0001\u0000\u0000\u0000\u013f+\u0001"+
		"\u0000\u0000\u0000\u0140\u0142\u0003$\u0012\u0000\u0141\u0143\u0003*\u0015"+
		"\u0000\u0142\u0141\u0001\u0000\u0000\u0000\u0142\u0143\u0001\u0000\u0000"+
		"\u0000\u0143-\u0001\u0000\u0000\u0000\u0144\u0145\u00034\u001a\u0000\u0145"+
		"\u0146\u0003*\u0015\u0000\u0146/\u0001\u0000\u0000\u0000\u0147\u014d\u0003"+
		"8\u001c\u0000\u0148\u014d\u00036\u001b\u0000\u0149\u014d\u0003\u0010\b"+
		"\u0000\u014a\u014d\u0003\u0016\u000b\u0000\u014b\u014d\u0003\n\u0005\u0000"+
		"\u014c\u0147\u0001\u0000\u0000\u0000\u014c\u0148\u0001\u0000\u0000\u0000"+
		"\u014c\u0149\u0001\u0000\u0000\u0000\u014c\u014a\u0001\u0000\u0000\u0000"+
		"\u014c\u014b\u0001\u0000\u0000\u0000\u014d1\u0001\u0000\u0000\u0000\u014e"+
		"\u0153\u0006\u0019\uffff\uffff\u0000\u014f\u0154\u00034\u001a\u0000\u0150"+
		"\u0154\u0003$\u0012\u0000\u0151\u0154\u0003\"\u0011\u0000\u0152\u0154"+
		"\u00030\u0018\u0000\u0153\u014f\u0001\u0000\u0000\u0000\u0153\u0150\u0001"+
		"\u0000\u0000\u0000\u0153\u0151\u0001\u0000\u0000\u0000\u0153\u0152\u0001"+
		"\u0000\u0000\u0000\u0154\u0160\u0001\u0000\u0000\u0000\u0155\u0160\u0003"+
		",\u0016\u0000\u0156\u0160\u0003.\u0017\u0000\u0157\u0159\u0007\u0001\u0000"+
		"\u0000\u0158\u0157\u0001\u0000\u0000\u0000\u0159\u015a\u0001\u0000\u0000"+
		"\u0000\u015a\u0158\u0001\u0000\u0000\u0000\u015a\u015b\u0001\u0000\u0000"+
		"\u0000\u015b\u015c\u0001\u0000\u0000\u0000\u015c\u0160\u00032\u0019\u000f"+
		"\u015d\u015e\u0007\u0004\u0000\u0000\u015e\u0160\u00032\u0019\u0001\u015f"+
		"\u014e\u0001\u0000\u0000\u0000\u015f\u0155\u0001\u0000\u0000\u0000\u015f"+
		"\u0156\u0001\u0000\u0000\u0000\u015f\u0158\u0001\u0000\u0000\u0000\u015f"+
		"\u015d\u0001\u0000\u0000\u0000\u0160\u0190\u0001\u0000\u0000\u0000\u0161"+
		"\u0162\n\u0011\u0000\u0000\u0162\u0163\u0005+\u0000\u0000\u0163\u018f"+
		"\u00032\u0019\u0012\u0164\u0165\n\u0010\u0000\u0000\u0165\u0166\u0005"+
		"3\u0000\u0000\u0166\u018f\u00032\u0019\u0010\u0167\u0168\n\u000e\u0000"+
		"\u0000\u0168\u0169\u0007\u0005\u0000\u0000\u0169\u018f\u00032\u0019\u000f"+
		"\u016a\u016b\n\r\u0000\u0000\u016b\u016c\u0007\u0006\u0000\u0000\u016c"+
		"\u018f\u00032\u0019\u000e\u016d\u016e\n\f\u0000\u0000\u016e\u016f\u0007"+
		"\u0007\u0000\u0000\u016f\u018f\u00032\u0019\r\u0170\u0171\n\u000b\u0000"+
		"\u0000\u0171\u0172\u0005\u0002\u0000\u0000\u0172\u018f\u00032\u0019\f"+
		"\u0173\u0174\n\n\u0000\u0000\u0174\u0175\u0005_\u0000\u0000\u0175\u018f"+
		"\u00032\u0019\u000b\u0176\u0177\n\t\u0000\u0000\u0177\u0178\u0007\b\u0000"+
		"\u0000\u0178\u018f\u00032\u0019\n\u0179\u017a\n\b\u0000\u0000\u017a\u017b"+
		"\u0007\t\u0000\u0000\u017b\u018f\u00032\u0019\t\u017c\u017d\n\u0007\u0000"+
		"\u0000\u017d\u017e\u0005K\u0000\u0000\u017e\u018f\u00032\u0019\b\u017f"+
		"\u0180\n\u0006\u0000\u0000\u0180\u0181\u0005M\u0000\u0000\u0181\u018f"+
		"\u00032\u0019\u0007\u0182\u0183\n\u0005\u0000\u0000\u0183\u0184\u0005"+
		"O\u0000\u0000\u0184\u018f\u00032\u0019\u0006\u0185\u0186\n\u0004\u0000"+
		"\u0000\u0186\u0187\u0007\n\u0000\u0000\u0187\u018f\u00032\u0019\u0005"+
		"\u0188\u0189\n\u0003\u0000\u0000\u0189\u018a\u0005U\u0000\u0000\u018a"+
		"\u018f\u00032\u0019\u0004\u018b\u018c\n\u0002\u0000\u0000\u018c\u018d"+
		"\u0007\u000b\u0000\u0000\u018d\u018f\u00032\u0019\u0003\u018e\u0161\u0001"+
		"\u0000\u0000\u0000\u018e\u0164\u0001\u0000\u0000\u0000\u018e\u0167\u0001"+
		"\u0000\u0000\u0000\u018e\u016a\u0001\u0000\u0000\u0000\u018e\u016d\u0001"+
		"\u0000\u0000\u0000\u018e\u0170\u0001\u0000\u0000\u0000\u018e\u0173\u0001"+
		"\u0000\u0000\u0000\u018e\u0176\u0001\u0000\u0000\u0000\u018e\u0179\u0001"+
		"\u0000\u0000\u0000\u018e\u017c\u0001\u0000\u0000\u0000\u018e\u017f\u0001"+
		"\u0000\u0000\u0000\u018e\u0182\u0001\u0000\u0000\u0000\u018e\u0185\u0001"+
		"\u0000\u0000\u0000\u018e\u0188\u0001\u0000\u0000\u0000\u018e\u018b\u0001"+
		"\u0000\u0000\u0000\u018f\u0192\u0001\u0000\u0000\u0000\u0190\u018e\u0001"+
		"\u0000\u0000\u0000\u0190\u0191\u0001\u0000\u0000\u0000\u01913\u0001\u0000"+
		"\u0000\u0000\u0192\u0190\u0001\u0000\u0000\u0000\u0193\u01a8\u0005\u0003"+
		"\u0000\u0000\u0194\u01a8\u0005\u0004\u0000\u0000\u0195\u01a8\u0005\u0005"+
		"\u0000\u0000\u0196\u01a8\u0005\u0006\u0000\u0000\u0197\u01a8\u0007\f\u0000"+
		"\u0000\u0198\u01a8\u0005\u001d\u0000\u0000\u0199\u01a8\u0005\u001e\u0000"+
		"\u0000\u019a\u01a8\u0007\r\u0000\u0000\u019b\u01a8\u0005\u001b\u0000\u0000"+
		"\u019c\u01a8\u0005&\u0000\u0000\u019d\u01a8\u0005\t\u0000\u0000\u019e"+
		"\u01a8\u0005\n\u0000\u0000\u019f\u01a0\u0005d\u0000\u0000\u01a0\u01a1"+
		"\u0003\f\u0006\u0000\u01a1\u01a2\u0005)\u0000\u0000\u01a2\u01a8\u0001"+
		"\u0000\u0000\u0000\u01a3\u01a4\u0005\'\u0000\u0000\u01a4\u01a5\u0003\f"+
		"\u0006\u0000\u01a5\u01a6\u0005(\u0000\u0000\u01a6\u01a8\u0001\u0000\u0000"+
		"\u0000\u01a7\u0193\u0001\u0000\u0000\u0000\u01a7\u0194\u0001\u0000\u0000"+
		"\u0000\u01a7\u0195\u0001\u0000\u0000\u0000\u01a7\u0196\u0001\u0000\u0000"+
		"\u0000\u01a7\u0197\u0001\u0000\u0000\u0000\u01a7\u0198\u0001\u0000\u0000"+
		"\u0000\u01a7\u0199\u0001\u0000\u0000\u0000\u01a7\u019a\u0001\u0000\u0000"+
		"\u0000\u01a7\u019b\u0001\u0000\u0000\u0000\u01a7\u019c\u0001\u0000\u0000"+
		"\u0000\u01a7\u019d\u0001\u0000\u0000\u0000\u01a7\u019e\u0001\u0000\u0000"+
		"\u0000\u01a7\u019f\u0001\u0000\u0000\u0000\u01a7\u01a3\u0001\u0000\u0000"+
		"\u0000\u01a85\u0001\u0000\u0000\u0000\u01a9\u01aa\u0005%\u0000\u0000\u01aa"+
		"\u01ab\u0005!\u0000\u0000\u01ab\u01ac\u00050\u0000\u0000\u01ac\u01bc\u0003"+
		":\u001d\u0000\u01ad\u01ae\u0003,\u0016\u0000\u01ae\u01af\u0007\u000e\u0000"+
		"\u0000\u01af\u01b0\u0003:\u001d\u0000\u01b0\u01bc\u0001\u0000\u0000\u0000"+
		"\u01b1\u01b2\u0003.\u0017\u0000\u01b2\u01b3\u0007\u000f\u0000\u0000\u01b3"+
		"\u01b4\u0003:\u001d\u0000\u01b4\u01bc\u0001\u0000\u0000\u0000\u01b5\u01b6"+
		"\u0005\u001a\u0000\u0000\u01b6\u01b7\u00050\u0000\u0000\u01b7\u01bc\u0003"+
		":\u001d\u0000\u01b8\u01b9\u0005\u001c\u0000\u0000\u01b9\u01ba\u00050\u0000"+
		"\u0000\u01ba\u01bc\u0003:\u001d\u0000\u01bb\u01a9\u0001\u0000\u0000\u0000"+
		"\u01bb\u01ad\u0001\u0000\u0000\u0000\u01bb\u01b1\u0001\u0000\u0000\u0000"+
		"\u01bb\u01b5\u0001\u0000\u0000\u0000\u01bb\u01b8\u0001\u0000\u0000\u0000"+
		"\u01bc7\u0001\u0000\u0000\u0000\u01bd\u01be\u0005\u000b\u0000\u0000\u01be"+
		"\u01bf\u0003\f\u0006\u0000\u01bf\u01c0\u0005\f\u0000\u0000\u01c0\u01c1"+
		"\u0003:\u001d\u0000\u01c1\u01ca\u0001\u0000\u0000\u0000\u01c2\u01c3\u0005"+
		"\u000b\u0000\u0000\u01c3\u01c4\u0003\f\u0006\u0000\u01c4\u01c5\u0005\f"+
		"\u0000\u0000\u01c5\u01c6\u0003\f\u0006\u0000\u01c6\u01c7\u0005\r\u0000"+
		"\u0000\u01c7\u01c8\u0003:\u001d\u0000\u01c8\u01ca\u0001\u0000\u0000\u0000"+
		"\u01c9\u01bd\u0001\u0000\u0000\u0000\u01c9\u01c2\u0001\u0000\u0000\u0000"+
		"\u01ca9\u0001\u0000\u0000\u0000\u01cb\u01cd\u00032\u0019\u0000\u01cc\u01cb"+
		"\u0001\u0000\u0000\u0000\u01cd\u01ce\u0001\u0000\u0000\u0000\u01ce\u01cc"+
		"\u0001\u0000\u0000\u0000\u01ce\u01cf\u0001\u0000\u0000\u0000\u01cf;\u0001"+
		"\u0000\u0000\u00001FKNU]dmprx\u0081\u008b\u0099\u00a4\u00a9\u00ae\u00b4"+
		"\u00bc\u00c2\u00c9\u00d1\u00d9\u00de\u00e3\u00f6\u00fb\u00fd\u0103\u0108"+
		"\u0113\u0115\u0118\u011d\u0123\u0128\u0132\u0139\u013e\u0142\u014c\u0153"+
		"\u015a\u015f\u018e\u0190\u01a7\u01bb\u01c9\u01ce";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}