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
		RULE_lvalue = 9, RULE_fakeLvalue = 10, RULE_expr = 11, RULE_eexpr = 12, 
		RULE_assignment = 13, RULE_conditional = 14, RULE_listEnd = 15, RULE_list = 16;
	private static String[] makeRuleNames() {
		return new String[] {
			"everything", "program", "sequence", "nullified", "whileloop", "funcall", 
			"item", "var", "lvalueSpecs", "lvalue", "fakeLvalue", "expr", "eexpr", 
			"assignment", "conditional", "listEnd", "list"
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
			setState(34);
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
			setState(44);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				_localctx = new ProgramEOFContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(36);
				match(EOF);
				}
				break;
			case 2:
				_localctx = new ProgramSequenceContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(37);
				sequence();
				setState(38);
				match(EOF);
				}
				break;
			case 3:
				_localctx = new ProgramSequenceNamedparamContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(40);
				sequence();
				setState(41);
				match(NAMEDPARAM);
				}
				break;
			case 4:
				_localctx = new ProgramNamedparamContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(43);
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
		try {
			int _alt;
			setState(55);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(46);
				list();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(48); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(47);
						nullified();
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(50); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(53);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
				case 1:
					{
					setState(52);
					list();
					}
					break;
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
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(57);
			list();
			setState(59); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(58);
					match(NULLIFY);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(61); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
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
			setState(63);
			match(WHILE);
			setState(64);
			sequence();
			setState(65);
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
			setState(66);
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
			setState(68);
			match(FUNCTION);
			setState(69);
			match(PARAMS);
			setState(70);
			sequence();
			setState(71);
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
			setState(86);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case UINT:
				_localctx = new ItemUintContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(73);
				match(UINT);
				}
				break;
			case UFLOAT:
				_localctx = new ItemUfloatContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(74);
				match(UFLOAT);
				}
				break;
			case UPITCH:
				_localctx = new ItemUpitchContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(75);
				match(UPITCH);
				}
				break;
			case INLET:
				_localctx = new ItemInletContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(76);
				match(INLET);
				}
				break;
			case OPEN:
				_localctx = new ItemSequenceContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(77);
				match(OPEN);
				setState(78);
				sequence();
				setState(79);
				match(CLOSED);
				}
				break;
			case PUSH:
				_localctx = new ItemSublistContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(81);
				match(PUSH);
				setState(82);
				sequence();
				setState(83);
				match(POP);
				}
				break;
			case FUNCTION:
				_localctx = new ItemFuncallContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(85);
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
			setState(91);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LOCALVAR:
				_localctx = new VarLocalContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(88);
				match(LOCALVAR);
				}
				break;
			case PATCHERVAR:
				_localctx = new VarPatcherContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(89);
				match(PATCHERVAR);
				}
				break;
			case GLOBALVAR:
				_localctx = new VarGlobalContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(90);
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
			setState(116);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				ending = false;
				setState(99); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(94);
						match(NTH);
						setState(97);
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
							setState(95);
							item();
							}
							break;
						case GLOBALVAR:
						case PATCHERVAR:
						case LOCALVAR:
							{
							setState(96);
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
					setState(101); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				ending = true;
				setState(111);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(104);
						match(NTH);
						setState(107);
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
							setState(105);
							item();
							}
							break;
						case GLOBALVAR:
						case PATCHERVAR:
						case LOCALVAR:
							{
							setState(106);
							var();
							}
							break;
						default:
							throw new NoViableAltException(this);
						}
						}
						} 
					}
					setState(113);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
				}
				{
				setState(114);
				match(NTH);
				{
				setState(115);
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
			setState(118);
			var();
			setState(120);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				{
				setState(119);
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
			setState(122);
			item();
			setState(123);
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
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(142);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				{
				_localctx = new ExprSimpleContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(128);
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
					setState(126);
					item();
					}
					break;
				case GLOBALVAR:
				case PATCHERVAR:
				case LOCALVAR:
					{
					setState(127);
					var();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				break;
			case 2:
				{
				_localctx = new ExprLvalueContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(130);
				if (!(!ending)) throw new FailedPredicateException(this, "!ending");
				setState(131);
				lvalue();
				}
				break;
			case 3:
				{
				_localctx = new ExprFakeLvalueContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(132);
				if (!(!ending)) throw new FailedPredicateException(this, "!ending");
				setState(133);
				fakeLvalue();
				}
				break;
			case 4:
				{
				_localctx = new ExprUPlusMinusContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(135); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(134);
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
					setState(137); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(139);
				expr(15);
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
				setState(141);
				expr(1);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(191);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(189);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
					case 1:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(144);
						if (!(precpred(_ctx, 17))) throw new FailedPredicateException(this, "precpred(_ctx, 17)");
						setState(145);
						match(PICK);
						setState(146);
						expr(18);
						}
						break;
					case 2:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(147);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(148);
						((ExprBinaryContext)_localctx).op = match(POW);
						setState(149);
						expr(16);
						}
						break;
					case 3:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(150);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(151);
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
						setState(152);
						expr(15);
						}
						break;
					case 4:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(153);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(154);
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
						setState(155);
						expr(14);
						}
						break;
					case 5:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(156);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(157);
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
						setState(158);
						expr(13);
						}
						break;
					case 6:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(159);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(160);
						((ExprBinaryContext)_localctx).op = match(RANGE);
						setState(161);
						expr(12);
						}
						break;
					case 7:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(162);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(163);
						((ExprBinaryContext)_localctx).op = match(REPEAT);
						setState(164);
						expr(11);
						}
						break;
					case 8:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(165);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(166);
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
						setState(167);
						expr(10);
						}
						break;
					case 9:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(168);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(169);
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
						setState(170);
						expr(9);
						}
						break;
					case 10:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(171);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(172);
						((ExprBinaryContext)_localctx).op = match(BITAND);
						setState(173);
						expr(8);
						}
						break;
					case 11:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(174);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(175);
						((ExprBinaryContext)_localctx).op = match(BITXOR);
						setState(176);
						expr(7);
						}
						break;
					case 12:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(177);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(178);
						((ExprBinaryContext)_localctx).op = match(BITOR);
						setState(179);
						expr(6);
						}
						break;
					case 13:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(180);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(181);
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
						setState(182);
						expr(5);
						}
						break;
					case 14:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(183);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(184);
						((ExprBinaryContext)_localctx).op = match(LOGXOR);
						setState(185);
						expr(4);
						}
						break;
					case 15:
						{
						_localctx = new ExprBinaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(186);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(187);
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
						setState(188);
						expr(3);
						}
						break;
					}
					} 
				}
				setState(193);
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
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class EexprContext extends ParserRuleContext {
		public EexprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_eexpr; }
	 
		public EexprContext() { }
		public void copyFrom(EexprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EexprLvalueContext extends EexprContext {
		public LvalueContext lvalue() {
			return getRuleContext(LvalueContext.class,0);
		}
		public EexprLvalueContext(EexprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EexprBinaryContext extends EexprContext {
		public Token op;
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ListEndContext listEnd() {
			return getRuleContext(ListEndContext.class,0);
		}
		public TerminalNode POW() { return getToken(bellParser.POW, 0); }
		public TerminalNode TIMES() { return getToken(bellParser.TIMES, 0); }
		public TerminalNode DIV() { return getToken(bellParser.DIV, 0); }
		public TerminalNode DIVDIV() { return getToken(bellParser.DIVDIV, 0); }
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
		public EexprBinaryContext(EexprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EexprNotContext extends EexprContext {
		public Token op;
		public EexprContext eexpr() {
			return getRuleContext(EexprContext.class,0);
		}
		public TerminalNode LOGNOT() { return getToken(bellParser.LOGNOT, 0); }
		public TerminalNode BITNOT() { return getToken(bellParser.BITNOT, 0); }
		public EexprNotContext(EexprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EexprFakeLvalueContext extends EexprContext {
		public FakeLvalueContext fakeLvalue() {
			return getRuleContext(FakeLvalueContext.class,0);
		}
		public EexprFakeLvalueContext(EexprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EexprUPlusMinusContext extends EexprContext {
		public EexprContext eexpr() {
			return getRuleContext(EexprContext.class,0);
		}
		public List<TerminalNode> UPLUS() { return getTokens(bellParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(bellParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(bellParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(bellParser.UMINUS, i);
		}
		public EexprUPlusMinusContext(EexprContext ctx) { copyFrom(ctx); }
	}

	public final EexprContext eexpr() throws RecognitionException {
		EexprContext _localctx = new EexprContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_eexpr);
		int _la;
		try {
			int _alt;
			setState(262);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
			case 1:
				_localctx = new EexprLvalueContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(194);
				if (!(ending)) throw new FailedPredicateException(this, "ending");
				setState(195);
				lvalue();
				}
				break;
			case 2:
				_localctx = new EexprFakeLvalueContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(196);
				if (!(ending)) throw new FailedPredicateException(this, "ending");
				setState(197);
				fakeLvalue();
				}
				break;
			case 3:
				_localctx = new EexprBinaryContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(198);
				expr(0);
				setState(199);
				((EexprBinaryContext)_localctx).op = match(POW);
				setState(200);
				listEnd();
				}
				break;
			case 4:
				_localctx = new EexprUPlusMinusContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(203); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(202);
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
					setState(205); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(207);
				eexpr();
				}
				break;
			case 5:
				_localctx = new EexprBinaryContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(208);
				expr(0);
				setState(209);
				((EexprBinaryContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 1879048192L) != 0)) ) {
					((EexprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(210);
				listEnd();
				}
				break;
			case 6:
				_localctx = new EexprBinaryContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(212);
				expr(0);
				setState(213);
				((EexprBinaryContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==PLUS || _la==MINUS) ) {
					((EexprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(214);
				listEnd();
				}
				break;
			case 7:
				_localctx = new EexprBinaryContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(216);
				expr(0);
				setState(217);
				((EexprBinaryContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==LSHIFT || _la==RSHIFT) ) {
					((EexprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(218);
				listEnd();
				}
				break;
			case 8:
				_localctx = new EexprBinaryContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(220);
				expr(0);
				setState(221);
				((EexprBinaryContext)_localctx).op = match(RANGE);
				setState(222);
				listEnd();
				}
				break;
			case 9:
				_localctx = new EexprBinaryContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(224);
				expr(0);
				setState(225);
				((EexprBinaryContext)_localctx).op = match(REPEAT);
				setState(226);
				listEnd();
				}
				break;
			case 10:
				_localctx = new EexprBinaryContext(_localctx);
				enterOuterAlt(_localctx, 10);
				{
				setState(228);
				expr(0);
				setState(229);
				((EexprBinaryContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==EQUAL || _la==NEQ) ) {
					((EexprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(230);
				listEnd();
				}
				break;
			case 11:
				_localctx = new EexprBinaryContext(_localctx);
				enterOuterAlt(_localctx, 11);
				{
				setState(232);
				expr(0);
				setState(233);
				((EexprBinaryContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 16492674416640L) != 0)) ) {
					((EexprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(234);
				listEnd();
				}
				break;
			case 12:
				_localctx = new EexprBinaryContext(_localctx);
				enterOuterAlt(_localctx, 12);
				{
				setState(236);
				expr(0);
				setState(237);
				((EexprBinaryContext)_localctx).op = match(BITAND);
				setState(238);
				listEnd();
				}
				break;
			case 13:
				_localctx = new EexprBinaryContext(_localctx);
				enterOuterAlt(_localctx, 13);
				{
				setState(240);
				expr(0);
				setState(241);
				((EexprBinaryContext)_localctx).op = match(BITXOR);
				setState(242);
				listEnd();
				}
				break;
			case 14:
				_localctx = new EexprBinaryContext(_localctx);
				enterOuterAlt(_localctx, 14);
				{
				setState(244);
				expr(0);
				setState(245);
				((EexprBinaryContext)_localctx).op = match(BITOR);
				setState(246);
				listEnd();
				}
				break;
			case 15:
				_localctx = new EexprBinaryContext(_localctx);
				enterOuterAlt(_localctx, 15);
				{
				setState(248);
				expr(0);
				setState(249);
				((EexprBinaryContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==LOGAND || _la==LOGANDEXT) ) {
					((EexprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(250);
				listEnd();
				}
				break;
			case 16:
				_localctx = new EexprBinaryContext(_localctx);
				enterOuterAlt(_localctx, 16);
				{
				setState(252);
				expr(0);
				setState(253);
				((EexprBinaryContext)_localctx).op = match(LOGXOR);
				setState(254);
				listEnd();
				}
				break;
			case 17:
				_localctx = new EexprBinaryContext(_localctx);
				enterOuterAlt(_localctx, 17);
				{
				setState(256);
				expr(0);
				setState(257);
				((EexprBinaryContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==LOGOR || _la==LOGOREXT) ) {
					((EexprBinaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(258);
				listEnd();
				}
				break;
			case 18:
				_localctx = new EexprNotContext(_localctx);
				enterOuterAlt(_localctx, 18);
				{
				setState(260);
				((EexprNotContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==LOGNOT || _la==BITNOT) ) {
					((EexprNotContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(261);
				eexpr();
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
		enterRule(_localctx, 26, RULE_assignment);
		try {
			setState(272);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case GLOBALVAR:
			case PATCHERVAR:
			case LOCALVAR:
				_localctx = new TrueAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(264);
				lvalue();
				setState(265);
				match(ASSIGN);
				setState(266);
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
				setState(268);
				fakeLvalue();
				setState(269);
				match(ASSIGN);
				setState(270);
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
		enterRule(_localctx, 28, RULE_conditional);
		try {
			setState(286);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,21,_ctx) ) {
			case 1:
				_localctx = new IfthenContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(274);
				match(IF);
				setState(275);
				sequence();
				setState(276);
				match(THEN);
				setState(277);
				list();
				}
				break;
			case 2:
				_localctx = new IfthenelseContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(279);
				match(IF);
				setState(280);
				sequence();
				setState(281);
				match(THEN);
				setState(282);
				sequence();
				setState(283);
				match(ELSE);
				setState(284);
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
		enterRule(_localctx, 30, RULE_listEnd);
		try {
			setState(291);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IF:
				enterOuterAlt(_localctx, 1);
				{
				setState(288);
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
				setState(289);
				assignment();
				}
				break;
			case WHILE:
				enterOuterAlt(_localctx, 3);
				{
				setState(290);
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
		public EexprContext eexpr() {
			return getRuleContext(EexprContext.class,0);
		}
		public ListEndContext listEnd() {
			return getRuleContext(ListEndContext.class,0);
		}
		public ListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_list; }
	}

	public final ListContext list() throws RecognitionException {
		ListContext _localctx = new ListContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_list);
		try {
			int _alt;
			setState(312);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,26,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(294); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(293);
						expr(0);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(296); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(301);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,24,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(298);
						expr(0);
						}
						} 
					}
					setState(303);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,24,_ctx);
				}
				setState(304);
				eexpr();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(308);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(305);
						expr(0);
						}
						} 
					}
					setState(310);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
				}
				setState(311);
				listEnd();
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

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 11:
			return expr_sempred((ExprContext)_localctx, predIndex);
		case 12:
			return eexpr_sempred((EexprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return !ending;
		case 1:
			return !ending;
		case 2:
			return precpred(_ctx, 17);
		case 3:
			return precpred(_ctx, 16);
		case 4:
			return precpred(_ctx, 14);
		case 5:
			return precpred(_ctx, 13);
		case 6:
			return precpred(_ctx, 12);
		case 7:
			return precpred(_ctx, 11);
		case 8:
			return precpred(_ctx, 10);
		case 9:
			return precpred(_ctx, 9);
		case 10:
			return precpred(_ctx, 8);
		case 11:
			return precpred(_ctx, 7);
		case 12:
			return precpred(_ctx, 6);
		case 13:
			return precpred(_ctx, 5);
		case 14:
			return precpred(_ctx, 4);
		case 15:
			return precpred(_ctx, 3);
		case 16:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean eexpr_sempred(EexprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 17:
			return ending;
		case 18:
			return ending;
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001:\u013b\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0003\u0001-\b\u0001\u0001\u0002\u0001\u0002\u0004\u00021\b\u0002\u000b"+
		"\u0002\f\u00022\u0001\u0002\u0003\u00026\b\u0002\u0003\u00028\b\u0002"+
		"\u0001\u0003\u0001\u0003\u0004\u0003<\b\u0003\u000b\u0003\f\u0003=\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0003\u0006W\b"+
		"\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0003\u0007\\\b\u0007\u0001"+
		"\b\u0001\b\u0001\b\u0001\b\u0003\bb\b\b\u0004\bd\b\b\u000b\b\f\be\u0001"+
		"\b\u0001\b\u0001\b\u0001\b\u0003\bl\b\b\u0005\bn\b\b\n\b\f\bq\t\b\u0001"+
		"\b\u0001\b\u0003\bu\b\b\u0001\t\u0001\t\u0003\ty\b\t\u0001\n\u0001\n\u0001"+
		"\n\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u0081\b\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0004\u000b\u0088"+
		"\b\u000b\u000b\u000b\f\u000b\u0089\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0003\u000b\u008f\b\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0005\u000b"+
		"\u00be\b\u000b\n\u000b\f\u000b\u00c1\t\u000b\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0004\f\u00cc\b\f\u000b\f\f"+
		"\f\u00cd\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0003\f\u0107\b\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0003\r\u0111\b\r\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u011f\b\u000e\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0003\u000f\u0124\b\u000f\u0001\u0010\u0004"+
		"\u0010\u0127\b\u0010\u000b\u0010\f\u0010\u0128\u0001\u0010\u0005\u0010"+
		"\u012c\b\u0010\n\u0010\f\u0010\u012f\t\u0010\u0001\u0010\u0001\u0010\u0005"+
		"\u0010\u0133\b\u0010\n\u0010\f\u0010\u0136\t\u0010\u0001\u0010\u0003\u0010"+
		"\u0139\b\u0010\u0001\u0010\u0000\u0001\u0016\u0011\u0000\u0002\u0004\u0006"+
		"\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \u0000\u000b"+
		"\u0001\u0000\t\n\u0002\u0000  \"\"\u0001\u0000&\'\u0002\u0000\u001c\u001e"+
		"##\u0002\u0000\u001f\u001f!!\u0001\u000045\u0001\u0000$%\u0001\u0000("+
		"+\u0001\u0000/0\u0001\u000023\u0001\u0000\u001c\u001e\u016e\u0000\"\u0001"+
		"\u0000\u0000\u0000\u0002,\u0001\u0000\u0000\u0000\u00047\u0001\u0000\u0000"+
		"\u0000\u00069\u0001\u0000\u0000\u0000\b?\u0001\u0000\u0000\u0000\nD\u0001"+
		"\u0000\u0000\u0000\fV\u0001\u0000\u0000\u0000\u000e[\u0001\u0000\u0000"+
		"\u0000\u0010t\u0001\u0000\u0000\u0000\u0012v\u0001\u0000\u0000\u0000\u0014"+
		"z\u0001\u0000\u0000\u0000\u0016\u008e\u0001\u0000\u0000\u0000\u0018\u0106"+
		"\u0001\u0000\u0000\u0000\u001a\u0110\u0001\u0000\u0000\u0000\u001c\u011e"+
		"\u0001\u0000\u0000\u0000\u001e\u0123\u0001\u0000\u0000\u0000 \u0138\u0001"+
		"\u0000\u0000\u0000\"#\u0003\u0002\u0001\u0000#\u0001\u0001\u0000\u0000"+
		"\u0000$-\u0005\u0000\u0000\u0001%&\u0003\u0004\u0002\u0000&\'\u0005\u0000"+
		"\u0000\u0001\'-\u0001\u0000\u0000\u0000()\u0003\u0004\u0002\u0000)*\u0005"+
		"\u0010\u0000\u0000*-\u0001\u0000\u0000\u0000+-\u0005\u0010\u0000\u0000"+
		",$\u0001\u0000\u0000\u0000,%\u0001\u0000\u0000\u0000,(\u0001\u0000\u0000"+
		"\u0000,+\u0001\u0000\u0000\u0000-\u0003\u0001\u0000\u0000\u0000.8\u0003"+
		" \u0010\u0000/1\u0003\u0006\u0003\u00000/\u0001\u0000\u0000\u000012\u0001"+
		"\u0000\u0000\u000020\u0001\u0000\u0000\u000023\u0001\u0000\u0000\u0000"+
		"35\u0001\u0000\u0000\u000046\u0003 \u0010\u000054\u0001\u0000\u0000\u0000"+
		"56\u0001\u0000\u0000\u000068\u0001\u0000\u0000\u00007.\u0001\u0000\u0000"+
		"\u000070\u0001\u0000\u0000\u00008\u0005\u0001\u0000\u0000\u00009;\u0003"+
		" \u0010\u0000:<\u0005\u0017\u0000\u0000;:\u0001\u0000\u0000\u0000<=\u0001"+
		"\u0000\u0000\u0000=;\u0001\u0000\u0000\u0000=>\u0001\u0000\u0000\u0000"+
		">\u0007\u0001\u0000\u0000\u0000?@\u0005\u0007\u0000\u0000@A\u0003\u0004"+
		"\u0002\u0000AB\u0007\u0000\u0000\u0000BC\u0003 \u0010\u0000C\t\u0001\u0000"+
		"\u0000\u0000DE\u0005\u000b\u0000\u0000EF\u00059\u0000\u0000FG\u0003\u0004"+
		"\u0002\u0000GH\u0005\u0013\u0000\u0000H\u000b\u0001\u0000\u0000\u0000"+
		"IW\u0005\u0001\u0000\u0000JW\u0005\u0002\u0000\u0000KW\u0005\u0003\u0000"+
		"\u0000LW\u0005\f\u0000\u0000MN\u00058\u0000\u0000NO\u0003\u0004\u0002"+
		"\u0000OP\u0005\u0013\u0000\u0000PW\u0001\u0000\u0000\u0000QR\u0005\u0011"+
		"\u0000\u0000RS\u0003\u0004\u0002\u0000ST\u0005\u0012\u0000\u0000TW\u0001"+
		"\u0000\u0000\u0000UW\u0003\n\u0005\u0000VI\u0001\u0000\u0000\u0000VJ\u0001"+
		"\u0000\u0000\u0000VK\u0001\u0000\u0000\u0000VL\u0001\u0000\u0000\u0000"+
		"VM\u0001\u0000\u0000\u0000VQ\u0001\u0000\u0000\u0000VU\u0001\u0000\u0000"+
		"\u0000W\r\u0001\u0000\u0000\u0000X\\\u0005\u000f\u0000\u0000Y\\\u0005"+
		"\u000e\u0000\u0000Z\\\u0005\r\u0000\u0000[X\u0001\u0000\u0000\u0000[Y"+
		"\u0001\u0000\u0000\u0000[Z\u0001\u0000\u0000\u0000\\\u000f\u0001\u0000"+
		"\u0000\u0000]c\u0006\b\uffff\uffff\u0000^a\u0005\u0014\u0000\u0000_b\u0003"+
		"\f\u0006\u0000`b\u0003\u000e\u0007\u0000a_\u0001\u0000\u0000\u0000a`\u0001"+
		"\u0000\u0000\u0000bd\u0001\u0000\u0000\u0000c^\u0001\u0000\u0000\u0000"+
		"de\u0001\u0000\u0000\u0000ec\u0001\u0000\u0000\u0000ef\u0001\u0000\u0000"+
		"\u0000fu\u0001\u0000\u0000\u0000go\u0006\b\uffff\uffff\u0000hk\u0005\u0014"+
		"\u0000\u0000il\u0003\f\u0006\u0000jl\u0003\u000e\u0007\u0000ki\u0001\u0000"+
		"\u0000\u0000kj\u0001\u0000\u0000\u0000ln\u0001\u0000\u0000\u0000mh\u0001"+
		"\u0000\u0000\u0000nq\u0001\u0000\u0000\u0000om\u0001\u0000\u0000\u0000"+
		"op\u0001\u0000\u0000\u0000pr\u0001\u0000\u0000\u0000qo\u0001\u0000\u0000"+
		"\u0000rs\u0005\u0014\u0000\u0000su\u0003\u001c\u000e\u0000t]\u0001\u0000"+
		"\u0000\u0000tg\u0001\u0000\u0000\u0000u\u0011\u0001\u0000\u0000\u0000"+
		"vx\u0003\u000e\u0007\u0000wy\u0003\u0010\b\u0000xw\u0001\u0000\u0000\u0000"+
		"xy\u0001\u0000\u0000\u0000y\u0013\u0001\u0000\u0000\u0000z{\u0003\f\u0006"+
		"\u0000{|\u0003\u0010\b\u0000|\u0015\u0001\u0000\u0000\u0000}\u0080\u0006"+
		"\u000b\uffff\uffff\u0000~\u0081\u0003\f\u0006\u0000\u007f\u0081\u0003"+
		"\u000e\u0007\u0000\u0080~\u0001\u0000\u0000\u0000\u0080\u007f\u0001\u0000"+
		"\u0000\u0000\u0081\u008f\u0001\u0000\u0000\u0000\u0082\u0083\u0004\u000b"+
		"\u0000\u0000\u0083\u008f\u0003\u0012\t\u0000\u0084\u0085\u0004\u000b\u0001"+
		"\u0000\u0085\u008f\u0003\u0014\n\u0000\u0086\u0088\u0007\u0001\u0000\u0000"+
		"\u0087\u0086\u0001\u0000\u0000\u0000\u0088\u0089\u0001\u0000\u0000\u0000"+
		"\u0089\u0087\u0001\u0000\u0000\u0000\u0089\u008a\u0001\u0000\u0000\u0000"+
		"\u008a\u008b\u0001\u0000\u0000\u0000\u008b\u008f\u0003\u0016\u000b\u000f"+
		"\u008c\u008d\u0007\u0002\u0000\u0000\u008d\u008f\u0003\u0016\u000b\u0001"+
		"\u008e}\u0001\u0000\u0000\u0000\u008e\u0082\u0001\u0000\u0000\u0000\u008e"+
		"\u0084\u0001\u0000\u0000\u0000\u008e\u0087\u0001\u0000\u0000\u0000\u008e"+
		"\u008c\u0001\u0000\u0000\u0000\u008f\u00bf\u0001\u0000\u0000\u0000\u0090"+
		"\u0091\n\u0011\u0000\u0000\u0091\u0092\u0005\u0015\u0000\u0000\u0092\u00be"+
		"\u0003\u0016\u000b\u0012\u0093\u0094\n\u0010\u0000\u0000\u0094\u0095\u0005"+
		"\u001b\u0000\u0000\u0095\u00be\u0003\u0016\u000b\u0010\u0096\u0097\n\u000e"+
		"\u0000\u0000\u0097\u0098\u0007\u0003\u0000\u0000\u0098\u00be\u0003\u0016"+
		"\u000b\u000f\u0099\u009a\n\r\u0000\u0000\u009a\u009b\u0007\u0004\u0000"+
		"\u0000\u009b\u00be\u0003\u0016\u000b\u000e\u009c\u009d\n\f\u0000\u0000"+
		"\u009d\u009e\u0007\u0005\u0000\u0000\u009e\u00be\u0003\u0016\u000b\r\u009f"+
		"\u00a0\n\u000b\u0000\u0000\u00a0\u00a1\u00056\u0000\u0000\u00a1\u00be"+
		"\u0003\u0016\u000b\f\u00a2\u00a3\n\n\u0000\u0000\u00a3\u00a4\u00057\u0000"+
		"\u0000\u00a4\u00be\u0003\u0016\u000b\u000b\u00a5\u00a6\n\t\u0000\u0000"+
		"\u00a6\u00a7\u0007\u0006\u0000\u0000\u00a7\u00be\u0003\u0016\u000b\n\u00a8"+
		"\u00a9\n\b\u0000\u0000\u00a9\u00aa\u0007\u0007\u0000\u0000\u00aa\u00be"+
		"\u0003\u0016\u000b\t\u00ab\u00ac\n\u0007\u0000\u0000\u00ac\u00ad\u0005"+
		",\u0000\u0000\u00ad\u00be\u0003\u0016\u000b\b\u00ae\u00af\n\u0006\u0000"+
		"\u0000\u00af\u00b0\u0005-\u0000\u0000\u00b0\u00be\u0003\u0016\u000b\u0007"+
		"\u00b1\u00b2\n\u0005\u0000\u0000\u00b2\u00b3\u0005.\u0000\u0000\u00b3"+
		"\u00be\u0003\u0016\u000b\u0006\u00b4\u00b5\n\u0004\u0000\u0000\u00b5\u00b6"+
		"\u0007\b\u0000\u0000\u00b6\u00be\u0003\u0016\u000b\u0005\u00b7\u00b8\n"+
		"\u0003\u0000\u0000\u00b8\u00b9\u00051\u0000\u0000\u00b9\u00be\u0003\u0016"+
		"\u000b\u0004\u00ba\u00bb\n\u0002\u0000\u0000\u00bb\u00bc\u0007\t\u0000"+
		"\u0000\u00bc\u00be\u0003\u0016\u000b\u0003\u00bd\u0090\u0001\u0000\u0000"+
		"\u0000\u00bd\u0093\u0001\u0000\u0000\u0000\u00bd\u0096\u0001\u0000\u0000"+
		"\u0000\u00bd\u0099\u0001\u0000\u0000\u0000\u00bd\u009c\u0001\u0000\u0000"+
		"\u0000\u00bd\u009f\u0001\u0000\u0000\u0000\u00bd\u00a2\u0001\u0000\u0000"+
		"\u0000\u00bd\u00a5\u0001\u0000\u0000\u0000\u00bd\u00a8\u0001\u0000\u0000"+
		"\u0000\u00bd\u00ab\u0001\u0000\u0000\u0000\u00bd\u00ae\u0001\u0000\u0000"+
		"\u0000\u00bd\u00b1\u0001\u0000\u0000\u0000\u00bd\u00b4\u0001\u0000\u0000"+
		"\u0000\u00bd\u00b7\u0001\u0000\u0000\u0000\u00bd\u00ba\u0001\u0000\u0000"+
		"\u0000\u00be\u00c1\u0001\u0000\u0000\u0000\u00bf\u00bd\u0001\u0000\u0000"+
		"\u0000\u00bf\u00c0\u0001\u0000\u0000\u0000\u00c0\u0017\u0001\u0000\u0000"+
		"\u0000\u00c1\u00bf\u0001\u0000\u0000\u0000\u00c2\u00c3\u0004\f\u0011\u0000"+
		"\u00c3\u0107\u0003\u0012\t\u0000\u00c4\u00c5\u0004\f\u0012\u0000\u00c5"+
		"\u0107\u0003\u0014\n\u0000\u00c6\u00c7\u0003\u0016\u000b\u0000\u00c7\u00c8"+
		"\u0005\u001b\u0000\u0000\u00c8\u00c9\u0003\u001e\u000f\u0000\u00c9\u0107"+
		"\u0001\u0000\u0000\u0000\u00ca\u00cc\u0007\u0001\u0000\u0000\u00cb\u00ca"+
		"\u0001\u0000\u0000\u0000\u00cc\u00cd\u0001\u0000\u0000\u0000\u00cd\u00cb"+
		"\u0001\u0000\u0000\u0000\u00cd\u00ce\u0001\u0000\u0000\u0000\u00ce\u00cf"+
		"\u0001\u0000\u0000\u0000\u00cf\u0107\u0003\u0018\f\u0000\u00d0\u00d1\u0003"+
		"\u0016\u000b\u0000\u00d1\u00d2\u0007\n\u0000\u0000\u00d2\u00d3\u0003\u001e"+
		"\u000f\u0000\u00d3\u0107\u0001\u0000\u0000\u0000\u00d4\u00d5\u0003\u0016"+
		"\u000b\u0000\u00d5\u00d6\u0007\u0004\u0000\u0000\u00d6\u00d7\u0003\u001e"+
		"\u000f\u0000\u00d7\u0107\u0001\u0000\u0000\u0000\u00d8\u00d9\u0003\u0016"+
		"\u000b\u0000\u00d9\u00da\u0007\u0005\u0000\u0000\u00da\u00db\u0003\u001e"+
		"\u000f\u0000\u00db\u0107\u0001\u0000\u0000\u0000\u00dc\u00dd\u0003\u0016"+
		"\u000b\u0000\u00dd\u00de\u00056\u0000\u0000\u00de\u00df\u0003\u001e\u000f"+
		"\u0000\u00df\u0107\u0001\u0000\u0000\u0000\u00e0\u00e1\u0003\u0016\u000b"+
		"\u0000\u00e1\u00e2\u00057\u0000\u0000\u00e2\u00e3\u0003\u001e\u000f\u0000"+
		"\u00e3\u0107\u0001\u0000\u0000\u0000\u00e4\u00e5\u0003\u0016\u000b\u0000"+
		"\u00e5\u00e6\u0007\u0006\u0000\u0000\u00e6\u00e7\u0003\u001e\u000f\u0000"+
		"\u00e7\u0107\u0001\u0000\u0000\u0000\u00e8\u00e9\u0003\u0016\u000b\u0000"+
		"\u00e9\u00ea\u0007\u0007\u0000\u0000\u00ea\u00eb\u0003\u001e\u000f\u0000"+
		"\u00eb\u0107\u0001\u0000\u0000\u0000\u00ec\u00ed\u0003\u0016\u000b\u0000"+
		"\u00ed\u00ee\u0005,\u0000\u0000\u00ee\u00ef\u0003\u001e\u000f\u0000\u00ef"+
		"\u0107\u0001\u0000\u0000\u0000\u00f0\u00f1\u0003\u0016\u000b\u0000\u00f1"+
		"\u00f2\u0005-\u0000\u0000\u00f2\u00f3\u0003\u001e\u000f\u0000\u00f3\u0107"+
		"\u0001\u0000\u0000\u0000\u00f4\u00f5\u0003\u0016\u000b\u0000\u00f5\u00f6"+
		"\u0005.\u0000\u0000\u00f6\u00f7\u0003\u001e\u000f\u0000\u00f7\u0107\u0001"+
		"\u0000\u0000\u0000\u00f8\u00f9\u0003\u0016\u000b\u0000\u00f9\u00fa\u0007"+
		"\b\u0000\u0000\u00fa\u00fb\u0003\u001e\u000f\u0000\u00fb\u0107\u0001\u0000"+
		"\u0000\u0000\u00fc\u00fd\u0003\u0016\u000b\u0000\u00fd\u00fe\u00051\u0000"+
		"\u0000\u00fe\u00ff\u0003\u001e\u000f\u0000\u00ff\u0107\u0001\u0000\u0000"+
		"\u0000\u0100\u0101\u0003\u0016\u000b\u0000\u0101\u0102\u0007\t\u0000\u0000"+
		"\u0102\u0103\u0003\u001e\u000f\u0000\u0103\u0107\u0001\u0000\u0000\u0000"+
		"\u0104\u0105\u0007\u0002\u0000\u0000\u0105\u0107\u0003\u0018\f\u0000\u0106"+
		"\u00c2\u0001\u0000\u0000\u0000\u0106\u00c4\u0001\u0000\u0000\u0000\u0106"+
		"\u00c6\u0001\u0000\u0000\u0000\u0106\u00cb\u0001\u0000\u0000\u0000\u0106"+
		"\u00d0\u0001\u0000\u0000\u0000\u0106\u00d4\u0001\u0000\u0000\u0000\u0106"+
		"\u00d8\u0001\u0000\u0000\u0000\u0106\u00dc\u0001\u0000\u0000\u0000\u0106"+
		"\u00e0\u0001\u0000\u0000\u0000\u0106\u00e4\u0001\u0000\u0000\u0000\u0106"+
		"\u00e8\u0001\u0000\u0000\u0000\u0106\u00ec\u0001\u0000\u0000\u0000\u0106"+
		"\u00f0\u0001\u0000\u0000\u0000\u0106\u00f4\u0001\u0000\u0000\u0000\u0106"+
		"\u00f8\u0001\u0000\u0000\u0000\u0106\u00fc\u0001\u0000\u0000\u0000\u0106"+
		"\u0100\u0001\u0000\u0000\u0000\u0106\u0104\u0001\u0000\u0000\u0000\u0107"+
		"\u0019\u0001\u0000\u0000\u0000\u0108\u0109\u0003\u0012\t\u0000\u0109\u010a"+
		"\u0005\u0018\u0000\u0000\u010a\u010b\u0003 \u0010\u0000\u010b\u0111\u0001"+
		"\u0000\u0000\u0000\u010c\u010d\u0003\u0014\n\u0000\u010d\u010e\u0005\u0018"+
		"\u0000\u0000\u010e\u010f\u0003 \u0010\u0000\u010f\u0111\u0001\u0000\u0000"+
		"\u0000\u0110\u0108\u0001\u0000\u0000\u0000\u0110\u010c\u0001\u0000\u0000"+
		"\u0000\u0111\u001b\u0001\u0000\u0000\u0000\u0112\u0113\u0005\u0004\u0000"+
		"\u0000\u0113\u0114\u0003\u0004\u0002\u0000\u0114\u0115\u0005\u0005\u0000"+
		"\u0000\u0115\u0116\u0003 \u0010\u0000\u0116\u011f\u0001\u0000\u0000\u0000"+
		"\u0117\u0118\u0005\u0004\u0000\u0000\u0118\u0119\u0003\u0004\u0002\u0000"+
		"\u0119\u011a\u0005\u0005\u0000\u0000\u011a\u011b\u0003\u0004\u0002\u0000"+
		"\u011b\u011c\u0005\u0006\u0000\u0000\u011c\u011d\u0003 \u0010\u0000\u011d"+
		"\u011f\u0001\u0000\u0000\u0000\u011e\u0112\u0001\u0000\u0000\u0000\u011e"+
		"\u0117\u0001\u0000\u0000\u0000\u011f\u001d\u0001\u0000\u0000\u0000\u0120"+
		"\u0124\u0003\u001c\u000e\u0000\u0121\u0124\u0003\u001a\r\u0000\u0122\u0124"+
		"\u0003\b\u0004\u0000\u0123\u0120\u0001\u0000\u0000\u0000\u0123\u0121\u0001"+
		"\u0000\u0000\u0000\u0123\u0122\u0001\u0000\u0000\u0000\u0124\u001f\u0001"+
		"\u0000\u0000\u0000\u0125\u0127\u0003\u0016\u000b\u0000\u0126\u0125\u0001"+
		"\u0000\u0000\u0000\u0127\u0128\u0001\u0000\u0000\u0000\u0128\u0126\u0001"+
		"\u0000\u0000\u0000\u0128\u0129\u0001\u0000\u0000\u0000\u0129\u0139\u0001"+
		"\u0000\u0000\u0000\u012a\u012c\u0003\u0016\u000b\u0000\u012b\u012a\u0001"+
		"\u0000\u0000\u0000\u012c\u012f\u0001\u0000\u0000\u0000\u012d\u012b\u0001"+
		"\u0000\u0000\u0000\u012d\u012e\u0001\u0000\u0000\u0000\u012e\u0130\u0001"+
		"\u0000\u0000\u0000\u012f\u012d\u0001\u0000\u0000\u0000\u0130\u0139\u0003"+
		"\u0018\f\u0000\u0131\u0133\u0003\u0016\u000b\u0000\u0132\u0131\u0001\u0000"+
		"\u0000\u0000\u0133\u0136\u0001\u0000\u0000\u0000\u0134\u0132\u0001\u0000"+
		"\u0000\u0000\u0134\u0135\u0001\u0000\u0000\u0000\u0135\u0137\u0001\u0000"+
		"\u0000\u0000\u0136\u0134\u0001\u0000\u0000\u0000\u0137\u0139\u0003\u001e"+
		"\u000f\u0000\u0138\u0126\u0001\u0000\u0000\u0000\u0138\u012d\u0001\u0000"+
		"\u0000\u0000\u0138\u0134\u0001\u0000\u0000\u0000\u0139!\u0001\u0000\u0000"+
		"\u0000\u001b,257=V[aekotx\u0080\u0089\u008e\u00bd\u00bf\u00cd\u0106\u0110"+
		"\u011e\u0123\u0128\u012d\u0134\u0138";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}