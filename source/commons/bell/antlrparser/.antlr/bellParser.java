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
		UINT=1, UFLOAT=2, UPITCH=3, IF=4, THEN=5, ELSE=6, WHILE=7, FOR=8, DO=9, 
		COLLECT=10, FUNCTION=11, INLET=12, GLOBALVAR=13, PATCHERVAR=14, LOCALVAR=15, 
		NAMEDPARAM=16, PUSH=17, POP=18, CLOSED=19, NTH=20, PICK=21, KEY=22, NULLIFY=23, 
		ASSIGN=24, WHITESPACE=25, NEWATOM=26, POW=27, TIMES=28, DIVDIV=29, DIV=30, 
		PLUS=31, UPLUS=32, MINUS=33, UMINUS=34, REM=35, EQUAL=36, NEQ=37, LOGNOT=38, 
		BITNOT=39, LT=40, GT=41, LEQ=42, GEQ=43, BITAND=44, BITXOR=45, BITOR=46, 
		LOGAND=47, LOGANDEXT=48, LOGXOR=49, LOGOR=50, LOGOREXT=51, LSHIFT=52, 
		RSHIFT=53, RANGE=54, REPEAT=55, OPEN=56, PARAMS=57, ANYTHING=58;
	public static final int
		RULE_everything = 0, RULE_program = 1, RULE_sequence = 2, RULE_nullified = 3, 
		RULE_whileloop = 4, RULE_funcall = 5, RULE_item = 6, RULE_var = 7, RULE_lvalueSpecs = 8, 
		RULE_lvalue = 9, RULE_fakeLvalue = 10, RULE_expr = 11, RULE_assignment = 12, 
		RULE_conditional = 13, RULE_listEnd = 14, RULE_list = 15;
	private static String[] makeRuleNames() {
		return new String[] {
			"everything", "program", "sequence", "nullified", "whileloop", "funcall", 
			"item", "var", "lvalueSpecs", "lvalue", "fakeLvalue", "expr", "assignment", 
			"conditional", "listEnd", "list"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, "'if'", "'then'", "'else'", "'while'", "'for'", 
			"'do'", "'collect'", null, null, null, null, null, null, "'['", "']'", 
			"')'", "':'", "'::'", "'.'", "';'", "'='", null, null, "'**'", "'*'", 
			"'//'", "'/'", null, "'+'", null, "'-'", "'%'", "'=='", "'!='", "'!'", 
			"'~'", "'<'", "'>'", "'<='", "'>='", "'&'", "'^'", "'|'", "'&&'", "'&&&'", 
			"'^^'", "'||'", "'|||'", "'<<'", "'>>'", "'...'", "':*'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "UINT", "UFLOAT", "UPITCH", "IF", "THEN", "ELSE", "WHILE", "FOR", 
			"DO", "COLLECT", "FUNCTION", "INLET", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", 
			"NAMEDPARAM", "PUSH", "POP", "CLOSED", "NTH", "PICK", "KEY", "NULLIFY", 
			"ASSIGN", "WHITESPACE", "NEWATOM", "POW", "TIMES", "DIVDIV", "DIV", "PLUS", 
			"UPLUS", "MINUS", "UMINUS", "REM", "EQUAL", "NEQ", "LOGNOT", "BITNOT", 
			"LT", "GT", "LEQ", "GEQ", "BITAND", "BITXOR", "BITOR", "LOGAND", "LOGANDEXT", 
			"LOGXOR", "LOGOR", "LOGOREXT", "LSHIFT", "RSHIFT", "RANGE", "REPEAT", 
			"OPEN", "PARAMS", "ANYTHING"
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
			setState(32);
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
			setState(42);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				_localctx = new ProgramEOFContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(34);
				match(EOF);
				}
				break;
			case 2:
				_localctx = new ProgramSequenceContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(35);
				sequence();
				setState(36);
				match(EOF);
				}
				break;
			case 3:
				_localctx = new ProgramSequenceNamedparamContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(38);
				sequence();
				setState(39);
				match(NAMEDPARAM);
				}
				break;
			case 4:
				_localctx = new ProgramNamedparamContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(41);
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
			setState(53);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(44);
				list();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(46); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(45);
						nullified();
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(48); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(51);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 72058440146679966L) != 0)) {
					{
					setState(50);
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
			setState(55);
			list();
			setState(57); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(56);
				match(NULLIFY);
				}
				}
				setState(59); 
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
			setState(61);
			match(WHILE);
			setState(62);
			sequence();
			setState(63);
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
			setState(64);
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
	public static class FuncallContext extends ParserRuleContext {
		public TerminalNode FUNCTION() { return getToken(bellParser.FUNCTION, 0); }
		public TerminalNode PARAMS() { return getToken(bellParser.PARAMS, 0); }
		public SequenceContext sequence() {
			return getRuleContext(SequenceContext.class,0);
		}
		public TerminalNode CLOSED() { return getToken(bellParser.CLOSED, 0); }
		public FuncallContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcall; }
	}

	public final FuncallContext funcall() throws RecognitionException {
		FuncallContext _localctx = new FuncallContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_funcall);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(66);
			match(FUNCTION);
			setState(67);
			match(PARAMS);
			setState(68);
			sequence();
			setState(69);
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
	public static class ItemSequenceContext extends ItemContext {
		public TerminalNode OPEN() { return getToken(bellParser.OPEN, 0); }
		public SequenceContext sequence() {
			return getRuleContext(SequenceContext.class,0);
		}
		public TerminalNode CLOSED() { return getToken(bellParser.CLOSED, 0); }
		public ItemSequenceContext(ItemContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemUintContext extends ItemContext {
		public TerminalNode UINT() { return getToken(bellParser.UINT, 0); }
		public ItemUintContext(ItemContext ctx) { copyFrom(ctx); }
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
	public static class ItemInletContext extends ItemContext {
		public TerminalNode INLET() { return getToken(bellParser.INLET, 0); }
		public ItemInletContext(ItemContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemFuncallContext extends ItemContext {
		public FuncallContext funcall() {
			return getRuleContext(FuncallContext.class,0);
		}
		public ItemFuncallContext(ItemContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ItemUpitchContext extends ItemContext {
		public TerminalNode UPITCH() { return getToken(bellParser.UPITCH, 0); }
		public ItemUpitchContext(ItemContext ctx) { copyFrom(ctx); }
	}

	public final ItemContext item() throws RecognitionException {
		ItemContext _localctx = new ItemContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_item);
		try {
			setState(84);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case UINT:
				_localctx = new ItemUintContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(71);
				match(UINT);
				}
				break;
			case UFLOAT:
				_localctx = new ItemUfloatContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(72);
				match(UFLOAT);
				}
				break;
			case UPITCH:
				_localctx = new ItemUpitchContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(73);
				match(UPITCH);
				}
				break;
			case INLET:
				_localctx = new ItemInletContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(74);
				match(INLET);
				}
				break;
			case OPEN:
				_localctx = new ItemSequenceContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(75);
				match(OPEN);
				setState(76);
				sequence();
				setState(77);
				match(CLOSED);
				}
				break;
			case PUSH:
				_localctx = new ItemSublistContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(79);
				match(PUSH);
				setState(80);
				sequence();
				setState(81);
				match(POP);
				}
				break;
			case FUNCTION:
				_localctx = new ItemFuncallContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(83);
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
		enterRule(_localctx, 14, RULE_var);
		try {
			setState(89);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LOCALVAR:
				_localctx = new VarLocalContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(86);
				match(LOCALVAR);
				}
				break;
			case PATCHERVAR:
				_localctx = new VarPatcherContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(87);
				match(PATCHERVAR);
				}
				break;
			case GLOBALVAR:
				_localctx = new VarGlobalContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(88);
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
		enterRule(_localctx, 16, RULE_lvalueSpecs);
		try {
			int _alt;
			setState(114);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				ending = false;
				setState(97); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(92);
						match(NTH);
						setState(95);
						_errHandler.sync(this);
						switch (_input.LA(1)) {
						case UINT:
						case UFLOAT:
						case UPITCH:
						case FUNCTION:
						case INLET:
						case PUSH:
						case OPEN:
							{
							setState(93);
							item();
							}
							break;
						case GLOBALVAR:
						case PATCHERVAR:
						case LOCALVAR:
							{
							setState(94);
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
					setState(99); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				ending = true;
				setState(109);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(102);
						match(NTH);
						setState(105);
						_errHandler.sync(this);
						switch (_input.LA(1)) {
						case UINT:
						case UFLOAT:
						case UPITCH:
						case FUNCTION:
						case INLET:
						case PUSH:
						case OPEN:
							{
							setState(103);
							item();
							}
							break;
						case GLOBALVAR:
						case PATCHERVAR:
						case LOCALVAR:
							{
							setState(104);
							var();
							}
							break;
						default:
							throw new NoViableAltException(this);
						}
						}
						} 
					}
					setState(111);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
				}
				{
				setState(112);
				match(NTH);
				{
				setState(113);
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
		enterRule(_localctx, 18, RULE_lvalue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(116);
			var();
			setState(118);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				{
				setState(117);
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
		enterRule(_localctx, 20, RULE_fakeLvalue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(120);
			item();
			setState(121);
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
		public ListEndContext listEnd() {
			return getRuleContext(ListEndContext.class,0);
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
		public ListEndContext listEnd() {
			return getRuleContext(ListEndContext.class,0);
		}
		public ExprSimpleContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprNotContext extends ExprContext {
		public Token op;
		public TerminalNode LOGNOT() { return getToken(bellParser.LOGNOT, 0); }
		public TerminalNode BITNOT() { return getToken(bellParser.BITNOT, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ListEndContext listEnd() {
			return getRuleContext(ListEndContext.class,0);
		}
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
		public ListEndContext listEnd() {
			return getRuleContext(ListEndContext.class,0);
		}
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
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(145);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				{
				_localctx = new ExprSimpleContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(127);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
				case 1:
					{
					setState(124);
					item();
					}
					break;
				case 2:
					{
					setState(125);
					var();
					}
					break;
				case 3:
					{
					setState(126);
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
				setState(129);
				lvalue();
				}
				break;
			case 3:
				{
				_localctx = new ExprFakeLvalueContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(130);
				fakeLvalue();
				}
				break;
			case 4:
				{
				_localctx = new ExprUPlusMinusContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(132); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(131);
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
					setState(134); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(138);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
				case 1:
					{
					setState(136);
					expr(0);
					}
					break;
				case 2:
					{
					setState(137);
					listEnd();
					}
					break;
				}
				}
				break;
			case 5:
				{
				_localctx = new ExprNotContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(140);
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
				setState(143);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
				case 1:
					{
					setState(141);
					expr(0);
					}
					break;
				case 2:
					{
					setState(142);
					listEnd();
					}
					break;
				}
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(239);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,34,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(237);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,33,_ctx) ) {
					case 1:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(147);
						if (!(precpred(_ctx, 17))) throw new FailedPredicateException(this, "precpred(_ctx, 17)");
						setState(148);
						match(PICK);
						setState(151);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
						case 1:
							{
							setState(149);
							expr(0);
							}
							break;
						case 2:
							{
							setState(150);
							listEnd();
							}
							break;
						}
						}
						break;
					case 2:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(153);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(154);
						((ExprBinaryContext)_localctx).op = match(POW);
						setState(157);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
						case 1:
							{
							setState(155);
							expr(0);
							}
							break;
						case 2:
							{
							setState(156);
							listEnd();
							}
							break;
						}
						}
						break;
					case 3:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(159);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(160);
						((ExprBinaryContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 36238786560L) != 0)) ) {
							((ExprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(163);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
						case 1:
							{
							setState(161);
							expr(0);
							}
							break;
						case 2:
							{
							setState(162);
							listEnd();
							}
							break;
						}
						}
						break;
					case 4:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(165);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(166);
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
						setState(169);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,21,_ctx) ) {
						case 1:
							{
							setState(167);
							expr(0);
							}
							break;
						case 2:
							{
							setState(168);
							listEnd();
							}
							break;
						}
						}
						break;
					case 5:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(171);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(172);
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
						setState(175);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
						case 1:
							{
							setState(173);
							expr(0);
							}
							break;
						case 2:
							{
							setState(174);
							listEnd();
							}
							break;
						}
						}
						break;
					case 6:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(177);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(178);
						((ExprBinaryContext)_localctx).op = match(RANGE);
						setState(181);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
						case 1:
							{
							setState(179);
							expr(0);
							}
							break;
						case 2:
							{
							setState(180);
							listEnd();
							}
							break;
						}
						}
						break;
					case 7:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(183);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(184);
						((ExprBinaryContext)_localctx).op = match(REPEAT);
						setState(187);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,24,_ctx) ) {
						case 1:
							{
							setState(185);
							expr(0);
							}
							break;
						case 2:
							{
							setState(186);
							listEnd();
							}
							break;
						}
						}
						break;
					case 8:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(189);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(190);
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
						setState(193);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
						case 1:
							{
							setState(191);
							expr(0);
							}
							break;
						case 2:
							{
							setState(192);
							listEnd();
							}
							break;
						}
						}
						break;
					case 9:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(195);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(196);
						((ExprBinaryContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 16492674416640L) != 0)) ) {
							((ExprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(199);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,26,_ctx) ) {
						case 1:
							{
							setState(197);
							expr(0);
							}
							break;
						case 2:
							{
							setState(198);
							listEnd();
							}
							break;
						}
						}
						break;
					case 10:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(201);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(202);
						((ExprBinaryContext)_localctx).op = match(BITAND);
						setState(205);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,27,_ctx) ) {
						case 1:
							{
							setState(203);
							expr(0);
							}
							break;
						case 2:
							{
							setState(204);
							listEnd();
							}
							break;
						}
						}
						break;
					case 11:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(207);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(208);
						((ExprBinaryContext)_localctx).op = match(BITXOR);
						setState(211);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,28,_ctx) ) {
						case 1:
							{
							setState(209);
							expr(0);
							}
							break;
						case 2:
							{
							setState(210);
							listEnd();
							}
							break;
						}
						}
						break;
					case 12:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(213);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(214);
						((ExprBinaryContext)_localctx).op = match(BITOR);
						setState(217);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,29,_ctx) ) {
						case 1:
							{
							setState(215);
							expr(0);
							}
							break;
						case 2:
							{
							setState(216);
							listEnd();
							}
							break;
						}
						}
						break;
					case 13:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(219);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(220);
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
						setState(223);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,30,_ctx) ) {
						case 1:
							{
							setState(221);
							expr(0);
							}
							break;
						case 2:
							{
							setState(222);
							listEnd();
							}
							break;
						}
						}
						break;
					case 14:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(225);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(226);
						((ExprBinaryContext)_localctx).op = match(LOGXOR);
						setState(229);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,31,_ctx) ) {
						case 1:
							{
							setState(227);
							expr(0);
							}
							break;
						case 2:
							{
							setState(228);
							listEnd();
							}
							break;
						}
						}
						break;
					case 15:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(231);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(232);
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
						setState(235);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,32,_ctx) ) {
						case 1:
							{
							setState(233);
							expr(0);
							}
							break;
						case 2:
							{
							setState(234);
							listEnd();
							}
							break;
						}
						}
						break;
					}
					} 
				}
				setState(241);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,34,_ctx);
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
		public FakeLvalueContext fakeLvalue() {
			return getRuleContext(FakeLvalueContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(bellParser.ASSIGN, 0); }
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public FakeAssignmentContext(AssignmentContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TrueAssignmentContext extends AssignmentContext {
		public LvalueContext lvalue() {
			return getRuleContext(LvalueContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(bellParser.ASSIGN, 0); }
		public ListContext list() {
			return getRuleContext(ListContext.class,0);
		}
		public TrueAssignmentContext(AssignmentContext ctx) { copyFrom(ctx); }
	}

	public final AssignmentContext assignment() throws RecognitionException {
		AssignmentContext _localctx = new AssignmentContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_assignment);
		try {
			setState(250);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case GLOBALVAR:
			case PATCHERVAR:
			case LOCALVAR:
				_localctx = new TrueAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(242);
				lvalue();
				setState(243);
				match(ASSIGN);
				setState(244);
				list();
				}
				break;
			case UINT:
			case UFLOAT:
			case UPITCH:
			case FUNCTION:
			case INLET:
			case PUSH:
			case OPEN:
				_localctx = new FakeAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(246);
				fakeLvalue();
				setState(247);
				match(ASSIGN);
				setState(248);
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
		enterRule(_localctx, 26, RULE_conditional);
		try {
			setState(264);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,36,_ctx) ) {
			case 1:
				_localctx = new IfthenContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(252);
				match(IF);
				setState(253);
				sequence();
				setState(254);
				match(THEN);
				setState(255);
				list();
				}
				break;
			case 2:
				_localctx = new IfthenelseContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(257);
				match(IF);
				setState(258);
				sequence();
				setState(259);
				match(THEN);
				setState(260);
				sequence();
				setState(261);
				match(ELSE);
				setState(262);
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
		enterRule(_localctx, 28, RULE_listEnd);
		try {
			setState(269);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IF:
				enterOuterAlt(_localctx, 1);
				{
				setState(266);
				conditional();
				}
				break;
			case UINT:
			case UFLOAT:
			case UPITCH:
			case FUNCTION:
			case INLET:
			case GLOBALVAR:
			case PATCHERVAR:
			case LOCALVAR:
			case PUSH:
			case OPEN:
				enterOuterAlt(_localctx, 2);
				{
				setState(267);
				assignment();
				}
				break;
			case WHILE:
				enterOuterAlt(_localctx, 3);
				{
				setState(268);
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
		enterRule(_localctx, 30, RULE_list);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(272); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(271);
					expr(0);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(274); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,38,_ctx);
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
		"\u0004\u0001:\u0115\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0003\u0001+\b\u0001"+
		"\u0001\u0002\u0001\u0002\u0004\u0002/\b\u0002\u000b\u0002\f\u00020\u0001"+
		"\u0002\u0003\u00024\b\u0002\u0003\u00026\b\u0002\u0001\u0003\u0001\u0003"+
		"\u0004\u0003:\b\u0003\u000b\u0003\f\u0003;\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0003\u0006U\b\u0006\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0003\u0007Z\b\u0007\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0003\b`\b\b\u0004\bb\b\b\u000b\b\f\bc\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0003\bj\b\b\u0005\bl\b\b\n\b\f\bo\t\b\u0001\b\u0001\b\u0003\bs\b\b"+
		"\u0001\t\u0001\t\u0003\tw\b\t\u0001\n\u0001\n\u0001\n\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u0080\b\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0004\u000b\u0085\b\u000b\u000b\u000b\f\u000b\u0086"+
		"\u0001\u000b\u0001\u000b\u0003\u000b\u008b\b\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0003\u000b\u0090\b\u000b\u0003\u000b\u0092\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u0098\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u009e\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00a4\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00aa\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00b0\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00b6\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00bc\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00c2\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00c8\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00ce\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00d4\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00da\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00e0\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00e6\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00ec\b\u000b\u0005"+
		"\u000b\u00ee\b\u000b\n\u000b\f\u000b\u00f1\t\u000b\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0003\f\u00fb\b\f\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0003\r\u0109\b\r\u0001\u000e\u0001\u000e\u0001\u000e\u0003"+
		"\u000e\u010e\b\u000e\u0001\u000f\u0004\u000f\u0111\b\u000f\u000b\u000f"+
		"\f\u000f\u0112\u0001\u000f\u0000\u0001\u0016\u0010\u0000\u0002\u0004\u0006"+
		"\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e\u0000\n\u0001"+
		"\u0000\t\n\u0002\u0000  \"\"\u0001\u0000&\'\u0002\u0000\u001c\u001e##"+
		"\u0002\u0000\u001f\u001f!!\u0001\u000045\u0001\u0000$%\u0001\u0000(+\u0001"+
		"\u0000/0\u0001\u000023\u0145\u0000 \u0001\u0000\u0000\u0000\u0002*\u0001"+
		"\u0000\u0000\u0000\u00045\u0001\u0000\u0000\u0000\u00067\u0001\u0000\u0000"+
		"\u0000\b=\u0001\u0000\u0000\u0000\nB\u0001\u0000\u0000\u0000\fT\u0001"+
		"\u0000\u0000\u0000\u000eY\u0001\u0000\u0000\u0000\u0010r\u0001\u0000\u0000"+
		"\u0000\u0012t\u0001\u0000\u0000\u0000\u0014x\u0001\u0000\u0000\u0000\u0016"+
		"\u0091\u0001\u0000\u0000\u0000\u0018\u00fa\u0001\u0000\u0000\u0000\u001a"+
		"\u0108\u0001\u0000\u0000\u0000\u001c\u010d\u0001\u0000\u0000\u0000\u001e"+
		"\u0110\u0001\u0000\u0000\u0000 !\u0003\u0002\u0001\u0000!\u0001\u0001"+
		"\u0000\u0000\u0000\"+\u0005\u0000\u0000\u0001#$\u0003\u0004\u0002\u0000"+
		"$%\u0005\u0000\u0000\u0001%+\u0001\u0000\u0000\u0000&\'\u0003\u0004\u0002"+
		"\u0000\'(\u0005\u0010\u0000\u0000(+\u0001\u0000\u0000\u0000)+\u0005\u0010"+
		"\u0000\u0000*\"\u0001\u0000\u0000\u0000*#\u0001\u0000\u0000\u0000*&\u0001"+
		"\u0000\u0000\u0000*)\u0001\u0000\u0000\u0000+\u0003\u0001\u0000\u0000"+
		"\u0000,6\u0003\u001e\u000f\u0000-/\u0003\u0006\u0003\u0000.-\u0001\u0000"+
		"\u0000\u0000/0\u0001\u0000\u0000\u00000.\u0001\u0000\u0000\u000001\u0001"+
		"\u0000\u0000\u000013\u0001\u0000\u0000\u000024\u0003\u001e\u000f\u0000"+
		"32\u0001\u0000\u0000\u000034\u0001\u0000\u0000\u000046\u0001\u0000\u0000"+
		"\u00005,\u0001\u0000\u0000\u00005.\u0001\u0000\u0000\u00006\u0005\u0001"+
		"\u0000\u0000\u000079\u0003\u001e\u000f\u00008:\u0005\u0017\u0000\u0000"+
		"98\u0001\u0000\u0000\u0000:;\u0001\u0000\u0000\u0000;9\u0001\u0000\u0000"+
		"\u0000;<\u0001\u0000\u0000\u0000<\u0007\u0001\u0000\u0000\u0000=>\u0005"+
		"\u0007\u0000\u0000>?\u0003\u0004\u0002\u0000?@\u0007\u0000\u0000\u0000"+
		"@A\u0003\u001e\u000f\u0000A\t\u0001\u0000\u0000\u0000BC\u0005\u000b\u0000"+
		"\u0000CD\u00059\u0000\u0000DE\u0003\u0004\u0002\u0000EF\u0005\u0013\u0000"+
		"\u0000F\u000b\u0001\u0000\u0000\u0000GU\u0005\u0001\u0000\u0000HU\u0005"+
		"\u0002\u0000\u0000IU\u0005\u0003\u0000\u0000JU\u0005\f\u0000\u0000KL\u0005"+
		"8\u0000\u0000LM\u0003\u0004\u0002\u0000MN\u0005\u0013\u0000\u0000NU\u0001"+
		"\u0000\u0000\u0000OP\u0005\u0011\u0000\u0000PQ\u0003\u0004\u0002\u0000"+
		"QR\u0005\u0012\u0000\u0000RU\u0001\u0000\u0000\u0000SU\u0003\n\u0005\u0000"+
		"TG\u0001\u0000\u0000\u0000TH\u0001\u0000\u0000\u0000TI\u0001\u0000\u0000"+
		"\u0000TJ\u0001\u0000\u0000\u0000TK\u0001\u0000\u0000\u0000TO\u0001\u0000"+
		"\u0000\u0000TS\u0001\u0000\u0000\u0000U\r\u0001\u0000\u0000\u0000VZ\u0005"+
		"\u000f\u0000\u0000WZ\u0005\u000e\u0000\u0000XZ\u0005\r\u0000\u0000YV\u0001"+
		"\u0000\u0000\u0000YW\u0001\u0000\u0000\u0000YX\u0001\u0000\u0000\u0000"+
		"Z\u000f\u0001\u0000\u0000\u0000[a\u0006\b\uffff\uffff\u0000\\_\u0005\u0014"+
		"\u0000\u0000]`\u0003\f\u0006\u0000^`\u0003\u000e\u0007\u0000_]\u0001\u0000"+
		"\u0000\u0000_^\u0001\u0000\u0000\u0000`b\u0001\u0000\u0000\u0000a\\\u0001"+
		"\u0000\u0000\u0000bc\u0001\u0000\u0000\u0000ca\u0001\u0000\u0000\u0000"+
		"cd\u0001\u0000\u0000\u0000ds\u0001\u0000\u0000\u0000em\u0006\b\uffff\uffff"+
		"\u0000fi\u0005\u0014\u0000\u0000gj\u0003\f\u0006\u0000hj\u0003\u000e\u0007"+
		"\u0000ig\u0001\u0000\u0000\u0000ih\u0001\u0000\u0000\u0000jl\u0001\u0000"+
		"\u0000\u0000kf\u0001\u0000\u0000\u0000lo\u0001\u0000\u0000\u0000mk\u0001"+
		"\u0000\u0000\u0000mn\u0001\u0000\u0000\u0000np\u0001\u0000\u0000\u0000"+
		"om\u0001\u0000\u0000\u0000pq\u0005\u0014\u0000\u0000qs\u0003\u001a\r\u0000"+
		"r[\u0001\u0000\u0000\u0000re\u0001\u0000\u0000\u0000s\u0011\u0001\u0000"+
		"\u0000\u0000tv\u0003\u000e\u0007\u0000uw\u0003\u0010\b\u0000vu\u0001\u0000"+
		"\u0000\u0000vw\u0001\u0000\u0000\u0000w\u0013\u0001\u0000\u0000\u0000"+
		"xy\u0003\f\u0006\u0000yz\u0003\u0010\b\u0000z\u0015\u0001\u0000\u0000"+
		"\u0000{\u007f\u0006\u000b\uffff\uffff\u0000|\u0080\u0003\f\u0006\u0000"+
		"}\u0080\u0003\u000e\u0007\u0000~\u0080\u0003\u001c\u000e\u0000\u007f|"+
		"\u0001\u0000\u0000\u0000\u007f}\u0001\u0000\u0000\u0000\u007f~\u0001\u0000"+
		"\u0000\u0000\u0080\u0092\u0001\u0000\u0000\u0000\u0081\u0092\u0003\u0012"+
		"\t\u0000\u0082\u0092\u0003\u0014\n\u0000\u0083\u0085\u0007\u0001\u0000"+
		"\u0000\u0084\u0083\u0001\u0000\u0000\u0000\u0085\u0086\u0001\u0000\u0000"+
		"\u0000\u0086\u0084\u0001\u0000\u0000\u0000\u0086\u0087\u0001\u0000\u0000"+
		"\u0000\u0087\u008a\u0001\u0000\u0000\u0000\u0088\u008b\u0003\u0016\u000b"+
		"\u0000\u0089\u008b\u0003\u001c\u000e\u0000\u008a\u0088\u0001\u0000\u0000"+
		"\u0000\u008a\u0089\u0001\u0000\u0000\u0000\u008b\u0092\u0001\u0000\u0000"+
		"\u0000\u008c\u008f\u0007\u0002\u0000\u0000\u008d\u0090\u0003\u0016\u000b"+
		"\u0000\u008e\u0090\u0003\u001c\u000e\u0000\u008f\u008d\u0001\u0000\u0000"+
		"\u0000\u008f\u008e\u0001\u0000\u0000\u0000\u0090\u0092\u0001\u0000\u0000"+
		"\u0000\u0091{\u0001\u0000\u0000\u0000\u0091\u0081\u0001\u0000\u0000\u0000"+
		"\u0091\u0082\u0001\u0000\u0000\u0000\u0091\u0084\u0001\u0000\u0000\u0000"+
		"\u0091\u008c\u0001\u0000\u0000\u0000\u0092\u00ef\u0001\u0000\u0000\u0000"+
		"\u0093\u0094\n\u0011\u0000\u0000\u0094\u0097\u0005\u0015\u0000\u0000\u0095"+
		"\u0098\u0003\u0016\u000b\u0000\u0096\u0098\u0003\u001c\u000e\u0000\u0097"+
		"\u0095\u0001\u0000\u0000\u0000\u0097\u0096\u0001\u0000\u0000\u0000\u0098"+
		"\u00ee\u0001\u0000\u0000\u0000\u0099\u009a\n\u0010\u0000\u0000\u009a\u009d"+
		"\u0005\u001b\u0000\u0000\u009b\u009e\u0003\u0016\u000b\u0000\u009c\u009e"+
		"\u0003\u001c\u000e\u0000\u009d\u009b\u0001\u0000\u0000\u0000\u009d\u009c"+
		"\u0001\u0000\u0000\u0000\u009e\u00ee\u0001\u0000\u0000\u0000\u009f\u00a0"+
		"\n\u000e\u0000\u0000\u00a0\u00a3\u0007\u0003\u0000\u0000\u00a1\u00a4\u0003"+
		"\u0016\u000b\u0000\u00a2\u00a4\u0003\u001c\u000e\u0000\u00a3\u00a1\u0001"+
		"\u0000\u0000\u0000\u00a3\u00a2\u0001\u0000\u0000\u0000\u00a4\u00ee\u0001"+
		"\u0000\u0000\u0000\u00a5\u00a6\n\r\u0000\u0000\u00a6\u00a9\u0007\u0004"+
		"\u0000\u0000\u00a7\u00aa\u0003\u0016\u000b\u0000\u00a8\u00aa\u0003\u001c"+
		"\u000e\u0000\u00a9\u00a7\u0001\u0000\u0000\u0000\u00a9\u00a8\u0001\u0000"+
		"\u0000\u0000\u00aa\u00ee\u0001\u0000\u0000\u0000\u00ab\u00ac\n\f\u0000"+
		"\u0000\u00ac\u00af\u0007\u0005\u0000\u0000\u00ad\u00b0\u0003\u0016\u000b"+
		"\u0000\u00ae\u00b0\u0003\u001c\u000e\u0000\u00af\u00ad\u0001\u0000\u0000"+
		"\u0000\u00af\u00ae\u0001\u0000\u0000\u0000\u00b0\u00ee\u0001\u0000\u0000"+
		"\u0000\u00b1\u00b2\n\u000b\u0000\u0000\u00b2\u00b5\u00056\u0000\u0000"+
		"\u00b3\u00b6\u0003\u0016\u000b\u0000\u00b4\u00b6\u0003\u001c\u000e\u0000"+
		"\u00b5\u00b3\u0001\u0000\u0000\u0000\u00b5\u00b4\u0001\u0000\u0000\u0000"+
		"\u00b6\u00ee\u0001\u0000\u0000\u0000\u00b7\u00b8\n\n\u0000\u0000\u00b8"+
		"\u00bb\u00057\u0000\u0000\u00b9\u00bc\u0003\u0016\u000b\u0000\u00ba\u00bc"+
		"\u0003\u001c\u000e\u0000\u00bb\u00b9\u0001\u0000\u0000\u0000\u00bb\u00ba"+
		"\u0001\u0000\u0000\u0000\u00bc\u00ee\u0001\u0000\u0000\u0000\u00bd\u00be"+
		"\n\t\u0000\u0000\u00be\u00c1\u0007\u0006\u0000\u0000\u00bf\u00c2\u0003"+
		"\u0016\u000b\u0000\u00c0\u00c2\u0003\u001c\u000e\u0000\u00c1\u00bf\u0001"+
		"\u0000\u0000\u0000\u00c1\u00c0\u0001\u0000\u0000\u0000\u00c2\u00ee\u0001"+
		"\u0000\u0000\u0000\u00c3\u00c4\n\b\u0000\u0000\u00c4\u00c7\u0007\u0007"+
		"\u0000\u0000\u00c5\u00c8\u0003\u0016\u000b\u0000\u00c6\u00c8\u0003\u001c"+
		"\u000e\u0000\u00c7\u00c5\u0001\u0000\u0000\u0000\u00c7\u00c6\u0001\u0000"+
		"\u0000\u0000\u00c8\u00ee\u0001\u0000\u0000\u0000\u00c9\u00ca\n\u0007\u0000"+
		"\u0000\u00ca\u00cd\u0005,\u0000\u0000\u00cb\u00ce\u0003\u0016\u000b\u0000"+
		"\u00cc\u00ce\u0003\u001c\u000e\u0000\u00cd\u00cb\u0001\u0000\u0000\u0000"+
		"\u00cd\u00cc\u0001\u0000\u0000\u0000\u00ce\u00ee\u0001\u0000\u0000\u0000"+
		"\u00cf\u00d0\n\u0006\u0000\u0000\u00d0\u00d3\u0005-\u0000\u0000\u00d1"+
		"\u00d4\u0003\u0016\u000b\u0000\u00d2\u00d4\u0003\u001c\u000e\u0000\u00d3"+
		"\u00d1\u0001\u0000\u0000\u0000\u00d3\u00d2\u0001\u0000\u0000\u0000\u00d4"+
		"\u00ee\u0001\u0000\u0000\u0000\u00d5\u00d6\n\u0005\u0000\u0000\u00d6\u00d9"+
		"\u0005.\u0000\u0000\u00d7\u00da\u0003\u0016\u000b\u0000\u00d8\u00da\u0003"+
		"\u001c\u000e\u0000\u00d9\u00d7\u0001\u0000\u0000\u0000\u00d9\u00d8\u0001"+
		"\u0000\u0000\u0000\u00da\u00ee\u0001\u0000\u0000\u0000\u00db\u00dc\n\u0004"+
		"\u0000\u0000\u00dc\u00df\u0007\b\u0000\u0000\u00dd\u00e0\u0003\u0016\u000b"+
		"\u0000\u00de\u00e0\u0003\u001c\u000e\u0000\u00df\u00dd\u0001\u0000\u0000"+
		"\u0000\u00df\u00de\u0001\u0000\u0000\u0000\u00e0\u00ee\u0001\u0000\u0000"+
		"\u0000\u00e1\u00e2\n\u0003\u0000\u0000\u00e2\u00e5\u00051\u0000\u0000"+
		"\u00e3\u00e6\u0003\u0016\u000b\u0000\u00e4\u00e6\u0003\u001c\u000e\u0000"+
		"\u00e5\u00e3\u0001\u0000\u0000\u0000\u00e5\u00e4\u0001\u0000\u0000\u0000"+
		"\u00e6\u00ee\u0001\u0000\u0000\u0000\u00e7\u00e8\n\u0002\u0000\u0000\u00e8"+
		"\u00eb\u0007\t\u0000\u0000\u00e9\u00ec\u0003\u0016\u000b\u0000\u00ea\u00ec"+
		"\u0003\u001c\u000e\u0000\u00eb\u00e9\u0001\u0000\u0000\u0000\u00eb\u00ea"+
		"\u0001\u0000\u0000\u0000\u00ec\u00ee\u0001\u0000\u0000\u0000\u00ed\u0093"+
		"\u0001\u0000\u0000\u0000\u00ed\u0099\u0001\u0000\u0000\u0000\u00ed\u009f"+
		"\u0001\u0000\u0000\u0000\u00ed\u00a5\u0001\u0000\u0000\u0000\u00ed\u00ab"+
		"\u0001\u0000\u0000\u0000\u00ed\u00b1\u0001\u0000\u0000\u0000\u00ed\u00b7"+
		"\u0001\u0000\u0000\u0000\u00ed\u00bd\u0001\u0000\u0000\u0000\u00ed\u00c3"+
		"\u0001\u0000\u0000\u0000\u00ed\u00c9\u0001\u0000\u0000\u0000\u00ed\u00cf"+
		"\u0001\u0000\u0000\u0000\u00ed\u00d5\u0001\u0000\u0000\u0000\u00ed\u00db"+
		"\u0001\u0000\u0000\u0000\u00ed\u00e1\u0001\u0000\u0000\u0000\u00ed\u00e7"+
		"\u0001\u0000\u0000\u0000\u00ee\u00f1\u0001\u0000\u0000\u0000\u00ef\u00ed"+
		"\u0001\u0000\u0000\u0000\u00ef\u00f0\u0001\u0000\u0000\u0000\u00f0\u0017"+
		"\u0001\u0000\u0000\u0000\u00f1\u00ef\u0001\u0000\u0000\u0000\u00f2\u00f3"+
		"\u0003\u0012\t\u0000\u00f3\u00f4\u0005\u0018\u0000\u0000\u00f4\u00f5\u0003"+
		"\u001e\u000f\u0000\u00f5\u00fb\u0001\u0000\u0000\u0000\u00f6\u00f7\u0003"+
		"\u0014\n\u0000\u00f7\u00f8\u0005\u0018\u0000\u0000\u00f8\u00f9\u0003\u001e"+
		"\u000f\u0000\u00f9\u00fb\u0001\u0000\u0000\u0000\u00fa\u00f2\u0001\u0000"+
		"\u0000\u0000\u00fa\u00f6\u0001\u0000\u0000\u0000\u00fb\u0019\u0001\u0000"+
		"\u0000\u0000\u00fc\u00fd\u0005\u0004\u0000\u0000\u00fd\u00fe\u0003\u0004"+
		"\u0002\u0000\u00fe\u00ff\u0005\u0005\u0000\u0000\u00ff\u0100\u0003\u001e"+
		"\u000f\u0000\u0100\u0109\u0001\u0000\u0000\u0000\u0101\u0102\u0005\u0004"+
		"\u0000\u0000\u0102\u0103\u0003\u0004\u0002\u0000\u0103\u0104\u0005\u0005"+
		"\u0000\u0000\u0104\u0105\u0003\u0004\u0002\u0000\u0105\u0106\u0005\u0006"+
		"\u0000\u0000\u0106\u0107\u0003\u001e\u000f\u0000\u0107\u0109\u0001\u0000"+
		"\u0000\u0000\u0108\u00fc\u0001\u0000\u0000\u0000\u0108\u0101\u0001\u0000"+
		"\u0000\u0000\u0109\u001b\u0001\u0000\u0000\u0000\u010a\u010e\u0003\u001a"+
		"\r\u0000\u010b\u010e\u0003\u0018\f\u0000\u010c\u010e\u0003\b\u0004\u0000"+
		"\u010d\u010a\u0001\u0000\u0000\u0000\u010d\u010b\u0001\u0000\u0000\u0000"+
		"\u010d\u010c\u0001\u0000\u0000\u0000\u010e\u001d\u0001\u0000\u0000\u0000"+
		"\u010f\u0111\u0003\u0016\u000b\u0000\u0110\u010f\u0001\u0000\u0000\u0000"+
		"\u0111\u0112\u0001\u0000\u0000\u0000\u0112\u0110\u0001\u0000\u0000\u0000"+
		"\u0112\u0113\u0001\u0000\u0000\u0000\u0113\u001f\u0001\u0000\u0000\u0000"+
		"\'*035;TY_cimrv\u007f\u0086\u008a\u008f\u0091\u0097\u009d\u00a3\u00a9"+
		"\u00af\u00b5\u00bb\u00c1\u00c7\u00cd\u00d3\u00d9\u00df\u00e5\u00eb\u00ed"+
		"\u00ef\u00fa\u0108\u010d\u0112";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}