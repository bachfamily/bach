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
		COLLECT=17, FUNCTION=18, INLET=19, INTINLET=20, RATINLET=21, FLOATINLET=22, 
		PITCHINLET=23, OUTLET=24, DIRINLET=25, DIROUTLET=26, BIF=27, OF=28, GLOBALVAR=29, 
		PATCHERVAR=30, LOCALVAR=31, NAMEDPARAM=32, PUSH=33, POP=34, CLOSED=35, 
		NTH=36, PICK=37, KEY=38, ANTH=39, APICK=40, NULLIFY=41, ASSIGN=42, WHITESPACE=43, 
		NEWATOM=44, POW=45, APOW=46, TIMES=47, ATIMES=48, DIVDIV=49, ADIVDIV=50, 
		DIV=51, ADIV=52, REM=53, AREM=54, PLUS=55, APLUS=56, UPLUS=57, MINUS=58, 
		AMINUS=59, UMINUS=60, EQUAL=61, NEQ=62, LOGNOT=63, BITNOT=64, LT=65, GT=66, 
		LEQ=67, GEQ=68, BITAND=69, ABITAND=70, BITXOR=71, ABITXOR=72, BITOR=73, 
		ABITOR=74, LOGAND=75, LOGANDEXT=76, ALOGAND=77, ALOGANDEXT=78, LOGXOR=79, 
		ALOGXOR=80, LOGOR=81, ALOGOR=82, LOGOREXT=83, ALOGOREXT=84, LSHIFT=85, 
		ALSHIFT=86, RSHIFT=87, ARSHIFT=88, REPEAT=89, AREPEAT=90, AAPPLY=91, ACONCAT=92, 
		ARCONCAT=93, OPEN=94, PARAMS=95, ANYTHING=96;
	public static final int
		RULE_everything = 0, RULE_program = 1, RULE_sequence = 2, RULE_nullified = 3, 
		RULE_whileloop = 4, RULE_argsByNameList = 5, RULE_argsByPositionList = 6, 
		RULE_funcall = 7, RULE_item = 8, RULE_var = 9, RULE_lvalueSpecs = 10, 
		RULE_lvalue = 11, RULE_fakeLvalue = 12, RULE_expr = 13, RULE_assignment = 14, 
		RULE_conditional = 15, RULE_listEnd = 16, RULE_list = 17;
	private static String[] makeRuleNames() {
		return new String[] {
			"everything", "program", "sequence", "nullified", "whileloop", "argsByNameList", 
			"argsByPositionList", "funcall", "item", "var", "lvalueSpecs", "lvalue", 
			"fakeLvalue", "expr", "assignment", "conditional", "listEnd", "list"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "','", "'...'", null, null, null, null, null, null, "'null'", "'nil'", 
			"'if'", "'then'", "'else'", "'while'", "'for'", "'do'", "'collect'", 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, "'['", "']'", "')'", "':'", "'::'", "'.'", "':='", 
			"'::='", "';'", "'='", null, null, "'**'", "'**='", "'*'", "'*='", "'//'", 
			"'//='", "'/'", "'/='", null, null, null, "'+='", "'+'", null, "'-='", 
			"'-'", "'=='", "'!='", "'!'", "'~'", "'<'", "'>'", "'<='", "'>='", "'&'", 
			"'&='", "'^'", "'^='", "'|'", "'|='", "'&&'", "'&&&'", "'&&='", "'&&&='", 
			"'^^'", "'^^='", "'||'", "'||='", "'|||'", "'|||='", "'<<'", "'<<='", 
			"'>>'", "'>>='", "':*'", "':*='", "'.='", "'_='", "'!_='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, "RANGE", "UINT", "UFLOAT", "UPITCH", "BTSYMBOL", "DQSYMBOL", 
			"SQSYMBOL", "BACHNULL", "BACHNIL", "IF", "THEN", "ELSE", "WHILE", "FOR", 
			"DO", "COLLECT", "FUNCTION", "INLET", "INTINLET", "RATINLET", "FLOATINLET", 
			"PITCHINLET", "OUTLET", "DIRINLET", "DIROUTLET", "BIF", "OF", "GLOBALVAR", 
			"PATCHERVAR", "LOCALVAR", "NAMEDPARAM", "PUSH", "POP", "CLOSED", "NTH", 
			"PICK", "KEY", "ANTH", "APICK", "NULLIFY", "ASSIGN", "WHITESPACE", "NEWATOM", 
			"POW", "APOW", "TIMES", "ATIMES", "DIVDIV", "ADIVDIV", "DIV", "ADIV", 
			"REM", "AREM", "PLUS", "APLUS", "UPLUS", "MINUS", "AMINUS", "UMINUS", 
			"EQUAL", "NEQ", "LOGNOT", "BITNOT", "LT", "GT", "LEQ", "GEQ", "BITAND", 
			"ABITAND", "BITXOR", "ABITXOR", "BITOR", "ABITOR", "LOGAND", "LOGANDEXT", 
			"ALOGAND", "ALOGANDEXT", "LOGXOR", "ALOGXOR", "LOGOR", "ALOGOR", "LOGOREXT", 
			"ALOGOREXT", "LSHIFT", "ALSHIFT", "RSHIFT", "ARSHIFT", "REPEAT", "AREPEAT", 
			"AAPPLY", "ACONCAT", "ARCONCAT", "OPEN", "PARAMS", "ANYTHING"
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
			setState(36);
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
			setState(46);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				_localctx = new ProgramEOFContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(38);
				match(EOF);
				}
				break;
			case 2:
				_localctx = new ProgramSequenceContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(39);
				sequence();
				setState(40);
				match(EOF);
				}
				break;
			case 3:
				_localctx = new ProgramSequenceNamedparamContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(42);
				sequence();
				setState(43);
				match(NAMEDPARAM);
				}
				break;
			case 4:
				_localctx = new ProgramNamedparamContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(45);
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
		enterRule(_localctx, 4, RULE_sequence);
		int _la;
		try {
			int _alt;
			setState(57);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(48);
				list();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(50); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(49);
						nullified();
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(52); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(55);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & -7926335331287674888L) != 0) || _la==BITNOT || _la==OPEN) {
					{
					setState(54);
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
		enterRule(_localctx, 6, RULE_nullified);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(59);
			list();
			setState(61); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(60);
				match(NULLIFY);
				}
				}
				setState(63); 
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
		enterRule(_localctx, 8, RULE_whileloop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(65);
			match(WHILE);
			setState(66);
			sequence();
			setState(67);
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
			setState(68);
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
		enterRule(_localctx, 10, RULE_argsByNameList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(70);
			match(NAMEDPARAM);
			setState(71);
			sequence();
			setState(79);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__0 || _la==NAMEDPARAM) {
				{
				{
				setState(73);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__0) {
					{
					setState(72);
					match(T__0);
					}
				}

				setState(75);
				match(NAMEDPARAM);
				setState(76);
				sequence();
				}
				}
				setState(81);
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
		enterRule(_localctx, 12, RULE_argsByPositionList);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(82);
			sequence();
			setState(87);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(83);
					match(T__0);
					setState(84);
					sequence();
					}
					} 
				}
				setState(89);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
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
	public static class FuncallContext extends ParserRuleContext {
		public ItemContext item() {
			return getRuleContext(ItemContext.class,0);
		}
		public TerminalNode PARAMS() { return getToken(bellParser.PARAMS, 0); }
		public ArgsByPositionListContext argsByPositionList() {
			return getRuleContext(ArgsByPositionListContext.class,0);
		}
		public TerminalNode CLOSED() { return getToken(bellParser.CLOSED, 0); }
		public ArgsByNameListContext argsByNameList() {
			return getRuleContext(ArgsByNameListContext.class,0);
		}
		public FuncallContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcall; }
	}

	public final FuncallContext funcall() throws RecognitionException {
		FuncallContext _localctx = new FuncallContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_funcall);
		int _la;
		try {
			setState(109);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(90);
				item();
				setState(91);
				match(PARAMS);
				setState(92);
				argsByPositionList();
				setState(93);
				match(CLOSED);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(95);
				item();
				setState(96);
				match(PARAMS);
				setState(97);
				argsByNameList();
				setState(98);
				match(CLOSED);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(100);
				item();
				setState(101);
				match(PARAMS);
				setState(102);
				argsByPositionList();
				setState(104);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__0) {
					{
					setState(103);
					match(T__0);
					}
				}

				setState(106);
				argsByNameList();
				setState(107);
				match(CLOSED);
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
		enterRule(_localctx, 16, RULE_item);
		int _la;
		try {
			setState(130);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case UINT:
				_localctx = new ItemUintContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(111);
				match(UINT);
				}
				break;
			case UFLOAT:
				_localctx = new ItemUfloatContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(112);
				match(UFLOAT);
				}
				break;
			case UPITCH:
				_localctx = new ItemUpitchContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(113);
				match(UPITCH);
				}
				break;
			case BTSYMBOL:
				_localctx = new ItemBtSymbolContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(114);
				match(BTSYMBOL);
				}
				break;
			case DQSYMBOL:
			case SQSYMBOL:
				_localctx = new ItemQSymbolContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(115);
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
				setState(116);
				match(BIF);
				}
				break;
			case OF:
				_localctx = new ItemOFContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(117);
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
				setState(118);
				((ItemInletContext)_localctx).type = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 16252928L) != 0)) ) {
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
				setState(119);
				match(DIRINLET);
				}
				break;
			case BACHNULL:
				_localctx = new ItemNullContext(_localctx);
				enterOuterAlt(_localctx, 10);
				{
				setState(120);
				match(BACHNULL);
				}
				break;
			case BACHNIL:
				_localctx = new ItemNilContext(_localctx);
				enterOuterAlt(_localctx, 11);
				{
				setState(121);
				match(BACHNIL);
				}
				break;
			case OPEN:
				_localctx = new ItemSequenceContext(_localctx);
				enterOuterAlt(_localctx, 12);
				{
				setState(122);
				match(OPEN);
				setState(123);
				sequence();
				setState(124);
				match(CLOSED);
				}
				break;
			case PUSH:
				_localctx = new ItemSublistContext(_localctx);
				enterOuterAlt(_localctx, 13);
				{
				setState(126);
				match(PUSH);
				setState(127);
				sequence();
				setState(128);
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
		enterRule(_localctx, 18, RULE_var);
		try {
			setState(135);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LOCALVAR:
				_localctx = new VarLocalContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(132);
				match(LOCALVAR);
				}
				break;
			case PATCHERVAR:
				_localctx = new VarPatcherContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(133);
				match(PATCHERVAR);
				}
				break;
			case GLOBALVAR:
				_localctx = new VarGlobalContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(134);
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
		enterRule(_localctx, 20, RULE_lvalueSpecs);
		int _la;
		try {
			int _alt;
			setState(160);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				ending = false;
				setState(143); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(138);
						_la = _input.LA(1);
						if ( !(_la==NTH || _la==KEY) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(141);
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
							setState(139);
							item();
							}
							break;
						case GLOBALVAR:
						case PATCHERVAR:
						case LOCALVAR:
							{
							setState(140);
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
					setState(145); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				ending = true;
				setState(155);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(148);
						_la = _input.LA(1);
						if ( !(_la==NTH || _la==KEY) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(151);
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
							setState(149);
							item();
							}
							break;
						case GLOBALVAR:
						case PATCHERVAR:
						case LOCALVAR:
							{
							setState(150);
							var();
							}
							break;
						default:
							throw new NoViableAltException(this);
						}
						}
						} 
					}
					setState(157);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
				}
				{
				setState(158);
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
				setState(159);
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
		enterRule(_localctx, 22, RULE_lvalue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(162);
			var();
			setState(164);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				{
				setState(163);
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
		enterRule(_localctx, 24, RULE_fakeLvalue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(166);
			item();
			setState(167);
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
		int _startState = 26;
		enterRecursionRule(_localctx, 26, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(186);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
			case 1:
				{
				_localctx = new ExprSimpleContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(174);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
				case 1:
					{
					setState(170);
					item();
					}
					break;
				case 2:
					{
					setState(171);
					var();
					}
					break;
				case 3:
					{
					setState(172);
					funcall();
					}
					break;
				case 4:
					{
					setState(173);
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
				setState(176);
				lvalue();
				}
				break;
			case 3:
				{
				_localctx = new ExprFakeLvalueContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(177);
				fakeLvalue();
				}
				break;
			case 4:
				{
				_localctx = new ExprUPlusMinusContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(179); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(178);
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
					setState(181); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(183);
				expr(15);
				}
				break;
			case 5:
				{
				_localctx = new ExprNotContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(184);
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
				setState(185);
				expr(1);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(235);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(233);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,21,_ctx) ) {
					case 1:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(188);
						if (!(precpred(_ctx, 17))) throw new FailedPredicateException(this, "precpred(_ctx, 17)");
						setState(189);
						match(PICK);
						setState(190);
						expr(18);
						}
						break;
					case 2:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(191);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(192);
						((ExprBinaryContext)_localctx).op = match(POW);
						setState(193);
						expr(16);
						}
						break;
					case 3:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(194);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(195);
						((ExprBinaryContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 11962686510202880L) != 0)) ) {
							((ExprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(196);
						expr(15);
						}
						break;
					case 4:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(197);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(198);
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
						setState(199);
						expr(14);
						}
						break;
					case 5:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(200);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(201);
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
						setState(202);
						expr(13);
						}
						break;
					case 6:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(203);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(204);
						((ExprBinaryContext)_localctx).op = match(RANGE);
						setState(205);
						expr(12);
						}
						break;
					case 7:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(206);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(207);
						((ExprBinaryContext)_localctx).op = match(REPEAT);
						setState(208);
						expr(11);
						}
						break;
					case 8:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(209);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(210);
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
						setState(211);
						expr(10);
						}
						break;
					case 9:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(212);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(213);
						((ExprBinaryContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(((((_la - 65)) & ~0x3f) == 0 && ((1L << (_la - 65)) & 15L) != 0)) ) {
							((ExprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(214);
						expr(9);
						}
						break;
					case 10:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(215);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(216);
						((ExprBinaryContext)_localctx).op = match(BITAND);
						setState(217);
						expr(8);
						}
						break;
					case 11:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(218);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(219);
						((ExprBinaryContext)_localctx).op = match(BITXOR);
						setState(220);
						expr(7);
						}
						break;
					case 12:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(221);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(222);
						((ExprBinaryContext)_localctx).op = match(BITOR);
						setState(223);
						expr(6);
						}
						break;
					case 13:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(224);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(225);
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
						setState(226);
						expr(5);
						}
						break;
					case 14:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(227);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(228);
						((ExprBinaryContext)_localctx).op = match(LOGXOR);
						setState(229);
						expr(4);
						}
						break;
					case 15:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(230);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(231);
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
						setState(232);
						expr(3);
						}
						break;
					}
					} 
				}
				setState(237);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
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
		enterRule(_localctx, 28, RULE_assignment);
		int _la;
		try {
			setState(252);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case GLOBALVAR:
			case PATCHERVAR:
			case LOCALVAR:
				_localctx = new TrueAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(238);
				lvalue();
				setState(239);
				((TrueAssignmentContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(((((_la - 39)) & ~0x3f) == 0 && ((1L << (_la - 39)) & 27772334426466953L) != 0)) ) {
					((TrueAssignmentContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(240);
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
				setState(242);
				fakeLvalue();
				setState(243);
				((FakeAssignmentContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(((((_la - 42)) & ~0x3f) == 0 && ((1L << (_la - 42)) & 3471541803308369L) != 0)) ) {
					((FakeAssignmentContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(244);
				list();
				}
				break;
			case OUTLET:
				_localctx = new OutletAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(246);
				match(OUTLET);
				setState(247);
				match(ASSIGN);
				setState(248);
				list();
				}
				break;
			case DIROUTLET:
				_localctx = new DirOutletAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(249);
				match(DIROUTLET);
				setState(250);
				match(ASSIGN);
				setState(251);
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
		enterRule(_localctx, 30, RULE_conditional);
		try {
			setState(266);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,24,_ctx) ) {
			case 1:
				_localctx = new IfthenContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(254);
				match(IF);
				setState(255);
				sequence();
				setState(256);
				match(THEN);
				setState(257);
				list();
				}
				break;
			case 2:
				_localctx = new IfthenelseContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(259);
				match(IF);
				setState(260);
				sequence();
				setState(261);
				match(THEN);
				setState(262);
				sequence();
				setState(263);
				match(ELSE);
				setState(264);
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
		public ListEndContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_listEnd; }
	}

	public final ListEndContext listEnd() throws RecognitionException {
		ListEndContext _localctx = new ListEndContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_listEnd);
		try {
			setState(271);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IF:
				enterOuterAlt(_localctx, 1);
				{
				setState(268);
				conditional();
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
			case OUTLET:
			case DIRINLET:
			case DIROUTLET:
			case BIF:
			case OF:
			case GLOBALVAR:
			case PATCHERVAR:
			case LOCALVAR:
			case PUSH:
			case OPEN:
				enterOuterAlt(_localctx, 2);
				{
				setState(269);
				assignment();
				}
				break;
			case WHILE:
				enterOuterAlt(_localctx, 3);
				{
				setState(270);
				whileloop();
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
		enterRule(_localctx, 34, RULE_list);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(274); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(273);
					expr(0);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(276); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
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
		case 13:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 17);
		case 1:
			return precpred(_ctx, 16);
		case 2:
			return precpred(_ctx, 14);
		case 3:
			return precpred(_ctx, 13);
		case 4:
			return precpred(_ctx, 12);
		case 5:
			return precpred(_ctx, 11);
		case 6:
			return precpred(_ctx, 10);
		case 7:
			return precpred(_ctx, 9);
		case 8:
			return precpred(_ctx, 8);
		case 9:
			return precpred(_ctx, 7);
		case 10:
			return precpred(_ctx, 6);
		case 11:
			return precpred(_ctx, 5);
		case 12:
			return precpred(_ctx, 4);
		case 13:
			return precpred(_ctx, 3);
		case 14:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001`\u0117\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0001\u0000\u0001\u0000"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0003\u0001/\b\u0001\u0001\u0002\u0001\u0002"+
		"\u0004\u00023\b\u0002\u000b\u0002\f\u00024\u0001\u0002\u0003\u00028\b"+
		"\u0002\u0003\u0002:\b\u0002\u0001\u0003\u0001\u0003\u0004\u0003>\b\u0003"+
		"\u000b\u0003\f\u0003?\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0003\u0005J\b\u0005"+
		"\u0001\u0005\u0001\u0005\u0005\u0005N\b\u0005\n\u0005\f\u0005Q\t\u0005"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0005\u0006V\b\u0006\n\u0006\f\u0006"+
		"Y\t\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0003\u0007i\b\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0003\u0007n\b\u0007\u0001\b\u0001\b\u0001\b"+
		"\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0003\b\u0083"+
		"\b\b\u0001\t\u0001\t\u0001\t\u0003\t\u0088\b\t\u0001\n\u0001\n\u0001\n"+
		"\u0001\n\u0003\n\u008e\b\n\u0004\n\u0090\b\n\u000b\n\f\n\u0091\u0001\n"+
		"\u0001\n\u0001\n\u0001\n\u0003\n\u0098\b\n\u0005\n\u009a\b\n\n\n\f\n\u009d"+
		"\t\n\u0001\n\u0001\n\u0003\n\u00a1\b\n\u0001\u000b\u0001\u000b\u0003\u000b"+
		"\u00a5\b\u000b\u0001\f\u0001\f\u0001\f\u0001\r\u0001\r\u0001\r\u0001\r"+
		"\u0001\r\u0003\r\u00af\b\r\u0001\r\u0001\r\u0001\r\u0004\r\u00b4\b\r\u000b"+
		"\r\f\r\u00b5\u0001\r\u0001\r\u0001\r\u0003\r\u00bb\b\r\u0001\r\u0001\r"+
		"\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0005\r\u00ea"+
		"\b\r\n\r\f\r\u00ed\t\r\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u00fd\b\u000e"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0003\u000f\u010b\b\u000f\u0001\u0010\u0001\u0010\u0001\u0010\u0003\u0010"+
		"\u0110\b\u0010\u0001\u0011\u0004\u0011\u0113\b\u0011\u000b\u0011\f\u0011"+
		"\u0114\u0001\u0011\u0000\u0001\u001a\u0012\u0000\u0002\u0004\u0006\b\n"+
		"\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"\u0000\u000f"+
		"\u0001\u0000\u0010\u0011\u0001\u0000\u0007\b\u0001\u0000\u0013\u0017\u0002"+
		"\u0000$$&&\u0002\u000099<<\u0001\u0000?@\u0004\u0000//113355\u0002\u0000"+
		"77::\u0002\u0000UUWW\u0001\u0000=>\u0001\u0000AD\u0001\u0000KL\u0002\u0000"+
		"QQSS\u0013\u0000\'\'**..0022446688;;FFHHJJMNPPRRTTVVXX\\]\u0012\u0000"+
		"**..0022446688;;FFHHJJMNPPRRTTVVXX\\]\u0143\u0000$\u0001\u0000\u0000\u0000"+
		"\u0002.\u0001\u0000\u0000\u0000\u00049\u0001\u0000\u0000\u0000\u0006;"+
		"\u0001\u0000\u0000\u0000\bA\u0001\u0000\u0000\u0000\nF\u0001\u0000\u0000"+
		"\u0000\fR\u0001\u0000\u0000\u0000\u000em\u0001\u0000\u0000\u0000\u0010"+
		"\u0082\u0001\u0000\u0000\u0000\u0012\u0087\u0001\u0000\u0000\u0000\u0014"+
		"\u00a0\u0001\u0000\u0000\u0000\u0016\u00a2\u0001\u0000\u0000\u0000\u0018"+
		"\u00a6\u0001\u0000\u0000\u0000\u001a\u00ba\u0001\u0000\u0000\u0000\u001c"+
		"\u00fc\u0001\u0000\u0000\u0000\u001e\u010a\u0001\u0000\u0000\u0000 \u010f"+
		"\u0001\u0000\u0000\u0000\"\u0112\u0001\u0000\u0000\u0000$%\u0003\u0002"+
		"\u0001\u0000%\u0001\u0001\u0000\u0000\u0000&/\u0005\u0000\u0000\u0001"+
		"\'(\u0003\u0004\u0002\u0000()\u0005\u0000\u0000\u0001)/\u0001\u0000\u0000"+
		"\u0000*+\u0003\u0004\u0002\u0000+,\u0005 \u0000\u0000,/\u0001\u0000\u0000"+
		"\u0000-/\u0005 \u0000\u0000.&\u0001\u0000\u0000\u0000.\'\u0001\u0000\u0000"+
		"\u0000.*\u0001\u0000\u0000\u0000.-\u0001\u0000\u0000\u0000/\u0003\u0001"+
		"\u0000\u0000\u00000:\u0003\"\u0011\u000013\u0003\u0006\u0003\u000021\u0001"+
		"\u0000\u0000\u000034\u0001\u0000\u0000\u000042\u0001\u0000\u0000\u0000"+
		"45\u0001\u0000\u0000\u000057\u0001\u0000\u0000\u000068\u0003\"\u0011\u0000"+
		"76\u0001\u0000\u0000\u000078\u0001\u0000\u0000\u00008:\u0001\u0000\u0000"+
		"\u000090\u0001\u0000\u0000\u000092\u0001\u0000\u0000\u0000:\u0005\u0001"+
		"\u0000\u0000\u0000;=\u0003\"\u0011\u0000<>\u0005)\u0000\u0000=<\u0001"+
		"\u0000\u0000\u0000>?\u0001\u0000\u0000\u0000?=\u0001\u0000\u0000\u0000"+
		"?@\u0001\u0000\u0000\u0000@\u0007\u0001\u0000\u0000\u0000AB\u0005\u000e"+
		"\u0000\u0000BC\u0003\u0004\u0002\u0000CD\u0007\u0000\u0000\u0000DE\u0003"+
		"\"\u0011\u0000E\t\u0001\u0000\u0000\u0000FG\u0005 \u0000\u0000GO\u0003"+
		"\u0004\u0002\u0000HJ\u0005\u0001\u0000\u0000IH\u0001\u0000\u0000\u0000"+
		"IJ\u0001\u0000\u0000\u0000JK\u0001\u0000\u0000\u0000KL\u0005 \u0000\u0000"+
		"LN\u0003\u0004\u0002\u0000MI\u0001\u0000\u0000\u0000NQ\u0001\u0000\u0000"+
		"\u0000OM\u0001\u0000\u0000\u0000OP\u0001\u0000\u0000\u0000P\u000b\u0001"+
		"\u0000\u0000\u0000QO\u0001\u0000\u0000\u0000RW\u0003\u0004\u0002\u0000"+
		"ST\u0005\u0001\u0000\u0000TV\u0003\u0004\u0002\u0000US\u0001\u0000\u0000"+
		"\u0000VY\u0001\u0000\u0000\u0000WU\u0001\u0000\u0000\u0000WX\u0001\u0000"+
		"\u0000\u0000X\r\u0001\u0000\u0000\u0000YW\u0001\u0000\u0000\u0000Z[\u0003"+
		"\u0010\b\u0000[\\\u0005_\u0000\u0000\\]\u0003\f\u0006\u0000]^\u0005#\u0000"+
		"\u0000^n\u0001\u0000\u0000\u0000_`\u0003\u0010\b\u0000`a\u0005_\u0000"+
		"\u0000ab\u0003\n\u0005\u0000bc\u0005#\u0000\u0000cn\u0001\u0000\u0000"+
		"\u0000de\u0003\u0010\b\u0000ef\u0005_\u0000\u0000fh\u0003\f\u0006\u0000"+
		"gi\u0005\u0001\u0000\u0000hg\u0001\u0000\u0000\u0000hi\u0001\u0000\u0000"+
		"\u0000ij\u0001\u0000\u0000\u0000jk\u0003\n\u0005\u0000kl\u0005#\u0000"+
		"\u0000ln\u0001\u0000\u0000\u0000mZ\u0001\u0000\u0000\u0000m_\u0001\u0000"+
		"\u0000\u0000md\u0001\u0000\u0000\u0000n\u000f\u0001\u0000\u0000\u0000"+
		"o\u0083\u0005\u0003\u0000\u0000p\u0083\u0005\u0004\u0000\u0000q\u0083"+
		"\u0005\u0005\u0000\u0000r\u0083\u0005\u0006\u0000\u0000s\u0083\u0007\u0001"+
		"\u0000\u0000t\u0083\u0005\u001b\u0000\u0000u\u0083\u0005\u001c\u0000\u0000"+
		"v\u0083\u0007\u0002\u0000\u0000w\u0083\u0005\u0019\u0000\u0000x\u0083"+
		"\u0005\t\u0000\u0000y\u0083\u0005\n\u0000\u0000z{\u0005^\u0000\u0000{"+
		"|\u0003\u0004\u0002\u0000|}\u0005#\u0000\u0000}\u0083\u0001\u0000\u0000"+
		"\u0000~\u007f\u0005!\u0000\u0000\u007f\u0080\u0003\u0004\u0002\u0000\u0080"+
		"\u0081\u0005\"\u0000\u0000\u0081\u0083\u0001\u0000\u0000\u0000\u0082o"+
		"\u0001\u0000\u0000\u0000\u0082p\u0001\u0000\u0000\u0000\u0082q\u0001\u0000"+
		"\u0000\u0000\u0082r\u0001\u0000\u0000\u0000\u0082s\u0001\u0000\u0000\u0000"+
		"\u0082t\u0001\u0000\u0000\u0000\u0082u\u0001\u0000\u0000\u0000\u0082v"+
		"\u0001\u0000\u0000\u0000\u0082w\u0001\u0000\u0000\u0000\u0082x\u0001\u0000"+
		"\u0000\u0000\u0082y\u0001\u0000\u0000\u0000\u0082z\u0001\u0000\u0000\u0000"+
		"\u0082~\u0001\u0000\u0000\u0000\u0083\u0011\u0001\u0000\u0000\u0000\u0084"+
		"\u0088\u0005\u001f\u0000\u0000\u0085\u0088\u0005\u001e\u0000\u0000\u0086"+
		"\u0088\u0005\u001d\u0000\u0000\u0087\u0084\u0001\u0000\u0000\u0000\u0087"+
		"\u0085\u0001\u0000\u0000\u0000\u0087\u0086\u0001\u0000\u0000\u0000\u0088"+
		"\u0013\u0001\u0000\u0000\u0000\u0089\u008f\u0006\n\uffff\uffff\u0000\u008a"+
		"\u008d\u0007\u0003\u0000\u0000\u008b\u008e\u0003\u0010\b\u0000\u008c\u008e"+
		"\u0003\u0012\t\u0000\u008d\u008b\u0001\u0000\u0000\u0000\u008d\u008c\u0001"+
		"\u0000\u0000\u0000\u008e\u0090\u0001\u0000\u0000\u0000\u008f\u008a\u0001"+
		"\u0000\u0000\u0000\u0090\u0091\u0001\u0000\u0000\u0000\u0091\u008f\u0001"+
		"\u0000\u0000\u0000\u0091\u0092\u0001\u0000\u0000\u0000\u0092\u00a1\u0001"+
		"\u0000\u0000\u0000\u0093\u009b\u0006\n\uffff\uffff\u0000\u0094\u0097\u0007"+
		"\u0003\u0000\u0000\u0095\u0098\u0003\u0010\b\u0000\u0096\u0098\u0003\u0012"+
		"\t\u0000\u0097\u0095\u0001\u0000\u0000\u0000\u0097\u0096\u0001\u0000\u0000"+
		"\u0000\u0098\u009a\u0001\u0000\u0000\u0000\u0099\u0094\u0001\u0000\u0000"+
		"\u0000\u009a\u009d\u0001\u0000\u0000\u0000\u009b\u0099\u0001\u0000\u0000"+
		"\u0000\u009b\u009c\u0001\u0000\u0000\u0000\u009c\u009e\u0001\u0000\u0000"+
		"\u0000\u009d\u009b\u0001\u0000\u0000\u0000\u009e\u009f\u0007\u0003\u0000"+
		"\u0000\u009f\u00a1\u0003\u001e\u000f\u0000\u00a0\u0089\u0001\u0000\u0000"+
		"\u0000\u00a0\u0093\u0001\u0000\u0000\u0000\u00a1\u0015\u0001\u0000\u0000"+
		"\u0000\u00a2\u00a4\u0003\u0012\t\u0000\u00a3\u00a5\u0003\u0014\n\u0000"+
		"\u00a4\u00a3\u0001\u0000\u0000\u0000\u00a4\u00a5\u0001\u0000\u0000\u0000"+
		"\u00a5\u0017\u0001\u0000\u0000\u0000\u00a6\u00a7\u0003\u0010\b\u0000\u00a7"+
		"\u00a8\u0003\u0014\n\u0000\u00a8\u0019\u0001\u0000\u0000\u0000\u00a9\u00ae"+
		"\u0006\r\uffff\uffff\u0000\u00aa\u00af\u0003\u0010\b\u0000\u00ab\u00af"+
		"\u0003\u0012\t\u0000\u00ac\u00af\u0003\u000e\u0007\u0000\u00ad\u00af\u0003"+
		" \u0010\u0000\u00ae\u00aa\u0001\u0000\u0000\u0000\u00ae\u00ab\u0001\u0000"+
		"\u0000\u0000\u00ae\u00ac\u0001\u0000\u0000\u0000\u00ae\u00ad\u0001\u0000"+
		"\u0000\u0000\u00af\u00bb\u0001\u0000\u0000\u0000\u00b0\u00bb\u0003\u0016"+
		"\u000b\u0000\u00b1\u00bb\u0003\u0018\f\u0000\u00b2\u00b4\u0007\u0004\u0000"+
		"\u0000\u00b3\u00b2\u0001\u0000\u0000\u0000\u00b4\u00b5\u0001\u0000\u0000"+
		"\u0000\u00b5\u00b3\u0001\u0000\u0000\u0000\u00b5\u00b6\u0001\u0000\u0000"+
		"\u0000\u00b6\u00b7\u0001\u0000\u0000\u0000\u00b7\u00bb\u0003\u001a\r\u000f"+
		"\u00b8\u00b9\u0007\u0005\u0000\u0000\u00b9\u00bb\u0003\u001a\r\u0001\u00ba"+
		"\u00a9\u0001\u0000\u0000\u0000\u00ba\u00b0\u0001\u0000\u0000\u0000\u00ba"+
		"\u00b1\u0001\u0000\u0000\u0000\u00ba\u00b3\u0001\u0000\u0000\u0000\u00ba"+
		"\u00b8\u0001\u0000\u0000\u0000\u00bb\u00eb\u0001\u0000\u0000\u0000\u00bc"+
		"\u00bd\n\u0011\u0000\u0000\u00bd\u00be\u0005%\u0000\u0000\u00be\u00ea"+
		"\u0003\u001a\r\u0012\u00bf\u00c0\n\u0010\u0000\u0000\u00c0\u00c1\u0005"+
		"-\u0000\u0000\u00c1\u00ea\u0003\u001a\r\u0010\u00c2\u00c3\n\u000e\u0000"+
		"\u0000\u00c3\u00c4\u0007\u0006\u0000\u0000\u00c4\u00ea\u0003\u001a\r\u000f"+
		"\u00c5\u00c6\n\r\u0000\u0000\u00c6\u00c7\u0007\u0007\u0000\u0000\u00c7"+
		"\u00ea\u0003\u001a\r\u000e\u00c8\u00c9\n\f\u0000\u0000\u00c9\u00ca\u0007"+
		"\b\u0000\u0000\u00ca\u00ea\u0003\u001a\r\r\u00cb\u00cc\n\u000b\u0000\u0000"+
		"\u00cc\u00cd\u0005\u0002\u0000\u0000\u00cd\u00ea\u0003\u001a\r\f\u00ce"+
		"\u00cf\n\n\u0000\u0000\u00cf\u00d0\u0005Y\u0000\u0000\u00d0\u00ea\u0003"+
		"\u001a\r\u000b\u00d1\u00d2\n\t\u0000\u0000\u00d2\u00d3\u0007\t\u0000\u0000"+
		"\u00d3\u00ea\u0003\u001a\r\n\u00d4\u00d5\n\b\u0000\u0000\u00d5\u00d6\u0007"+
		"\n\u0000\u0000\u00d6\u00ea\u0003\u001a\r\t\u00d7\u00d8\n\u0007\u0000\u0000"+
		"\u00d8\u00d9\u0005E\u0000\u0000\u00d9\u00ea\u0003\u001a\r\b\u00da\u00db"+
		"\n\u0006\u0000\u0000\u00db\u00dc\u0005G\u0000\u0000\u00dc\u00ea\u0003"+
		"\u001a\r\u0007\u00dd\u00de\n\u0005\u0000\u0000\u00de\u00df\u0005I\u0000"+
		"\u0000\u00df\u00ea\u0003\u001a\r\u0006\u00e0\u00e1\n\u0004\u0000\u0000"+
		"\u00e1\u00e2\u0007\u000b\u0000\u0000\u00e2\u00ea\u0003\u001a\r\u0005\u00e3"+
		"\u00e4\n\u0003\u0000\u0000\u00e4\u00e5\u0005O\u0000\u0000\u00e5\u00ea"+
		"\u0003\u001a\r\u0004\u00e6\u00e7\n\u0002\u0000\u0000\u00e7\u00e8\u0007"+
		"\f\u0000\u0000\u00e8\u00ea\u0003\u001a\r\u0003\u00e9\u00bc\u0001\u0000"+
		"\u0000\u0000\u00e9\u00bf\u0001\u0000\u0000\u0000\u00e9\u00c2\u0001\u0000"+
		"\u0000\u0000\u00e9\u00c5\u0001\u0000\u0000\u0000\u00e9\u00c8\u0001\u0000"+
		"\u0000\u0000\u00e9\u00cb\u0001\u0000\u0000\u0000\u00e9\u00ce\u0001\u0000"+
		"\u0000\u0000\u00e9\u00d1\u0001\u0000\u0000\u0000\u00e9\u00d4\u0001\u0000"+
		"\u0000\u0000\u00e9\u00d7\u0001\u0000\u0000\u0000\u00e9\u00da\u0001\u0000"+
		"\u0000\u0000\u00e9\u00dd\u0001\u0000\u0000\u0000\u00e9\u00e0\u0001\u0000"+
		"\u0000\u0000\u00e9\u00e3\u0001\u0000\u0000\u0000\u00e9\u00e6\u0001\u0000"+
		"\u0000\u0000\u00ea\u00ed\u0001\u0000\u0000\u0000\u00eb\u00e9\u0001\u0000"+
		"\u0000\u0000\u00eb\u00ec\u0001\u0000\u0000\u0000\u00ec\u001b\u0001\u0000"+
		"\u0000\u0000\u00ed\u00eb\u0001\u0000\u0000\u0000\u00ee\u00ef\u0003\u0016"+
		"\u000b\u0000\u00ef\u00f0\u0007\r\u0000\u0000\u00f0\u00f1\u0003\"\u0011"+
		"\u0000\u00f1\u00fd\u0001\u0000\u0000\u0000\u00f2\u00f3\u0003\u0018\f\u0000"+
		"\u00f3\u00f4\u0007\u000e\u0000\u0000\u00f4\u00f5\u0003\"\u0011\u0000\u00f5"+
		"\u00fd\u0001\u0000\u0000\u0000\u00f6\u00f7\u0005\u0018\u0000\u0000\u00f7"+
		"\u00f8\u0005*\u0000\u0000\u00f8\u00fd\u0003\"\u0011\u0000\u00f9\u00fa"+
		"\u0005\u001a\u0000\u0000\u00fa\u00fb\u0005*\u0000\u0000\u00fb\u00fd\u0003"+
		"\"\u0011\u0000\u00fc\u00ee\u0001\u0000\u0000\u0000\u00fc\u00f2\u0001\u0000"+
		"\u0000\u0000\u00fc\u00f6\u0001\u0000\u0000\u0000\u00fc\u00f9\u0001\u0000"+
		"\u0000\u0000\u00fd\u001d\u0001\u0000\u0000\u0000\u00fe\u00ff\u0005\u000b"+
		"\u0000\u0000\u00ff\u0100\u0003\u0004\u0002\u0000\u0100\u0101\u0005\f\u0000"+
		"\u0000\u0101\u0102\u0003\"\u0011\u0000\u0102\u010b\u0001\u0000\u0000\u0000"+
		"\u0103\u0104\u0005\u000b\u0000\u0000\u0104\u0105\u0003\u0004\u0002\u0000"+
		"\u0105\u0106\u0005\f\u0000\u0000\u0106\u0107\u0003\u0004\u0002\u0000\u0107"+
		"\u0108\u0005\r\u0000\u0000\u0108\u0109\u0003\"\u0011\u0000\u0109\u010b"+
		"\u0001\u0000\u0000\u0000\u010a\u00fe\u0001\u0000\u0000\u0000\u010a\u0103"+
		"\u0001\u0000\u0000\u0000\u010b\u001f\u0001\u0000\u0000\u0000\u010c\u0110"+
		"\u0003\u001e\u000f\u0000\u010d\u0110\u0003\u001c\u000e\u0000\u010e\u0110"+
		"\u0003\b\u0004\u0000\u010f\u010c\u0001\u0000\u0000\u0000\u010f\u010d\u0001"+
		"\u0000\u0000\u0000\u010f\u010e\u0001\u0000\u0000\u0000\u0110!\u0001\u0000"+
		"\u0000\u0000\u0111\u0113\u0003\u001a\r\u0000\u0112\u0111\u0001\u0000\u0000"+
		"\u0000\u0113\u0114\u0001\u0000\u0000\u0000\u0114\u0112\u0001\u0000\u0000"+
		"\u0000\u0114\u0115\u0001\u0000\u0000\u0000\u0115#\u0001\u0000\u0000\u0000"+
		"\u001b.479?IOWhm\u0082\u0087\u008d\u0091\u0097\u009b\u00a0\u00a4\u00ae"+
		"\u00b5\u00ba\u00e9\u00eb\u00fc\u010a\u010f\u0114";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}