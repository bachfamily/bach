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
		UINT=1, UFLOAT=2, UPITCH=3, IF=4, THEN=5, ELSE=6, FOR=7, DO=8, FUNCTION=9, 
		INLET=10, GLOBALVAR=11, PATCHERVAR=12, LOCALVAR=13, NAMEDPARAM=14, PUSH=15, 
		POP=16, CLOSED=17, NTH=18, KEY=19, NULLIFY=20, ASSIGN=21, WHITESPACE=22, 
		NEWATOM=23, POW=24, TIMES=25, DIVDIV=26, DIV=27, PLUS=28, UPLUS=29, MINUS=30, 
		UMINUS=31, OPEN=32, PARAMS=33, ANYTHING=34;
	public static final int
		RULE_everything = 0, RULE_program = 1, RULE_sequence = 2, RULE_nullified = 3, 
		RULE_funcall = 4, RULE_item = 5, RULE_var = 6, RULE_lvalueSpecs = 7, RULE_lvalue = 8, 
		RULE_fakeLvalue = 9, RULE_expr = 10, RULE_eexpr = 11, RULE_assignment = 12, 
		RULE_conditional = 13, RULE_listEnd = 14, RULE_list = 15;
	private static String[] makeRuleNames() {
		return new String[] {
			"everything", "program", "sequence", "nullified", "funcall", "item", 
			"var", "lvalueSpecs", "lvalue", "fakeLvalue", "expr", "eexpr", "assignment", 
			"conditional", "listEnd", "list"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, "'if'", "'then'", "'else'", "'for'", "'do'", 
			null, null, null, null, null, null, "'['", "']'", "')'", "':'", "'.'", 
			"';'", "'='", null, null, "'**'", "'*'", "'//'", "'/'", null, "'+'", 
			null, "'-'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "UINT", "UFLOAT", "UPITCH", "IF", "THEN", "ELSE", "FOR", "DO", 
			"FUNCTION", "INLET", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "NAMEDPARAM", 
			"PUSH", "POP", "CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", "WHITESPACE", 
			"NEWATOM", "POW", "TIMES", "DIVDIV", "DIV", "PLUS", "UPLUS", "MINUS", 
			"UMINUS", "OPEN", "PARAMS", "ANYTHING"
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
				switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
				case 1:
					{
					setState(50);
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
			setState(55);
			list();
			setState(57); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(56);
					match(NULLIFY);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(59); 
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
		enterRule(_localctx, 8, RULE_funcall);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(61);
			match(FUNCTION);
			setState(62);
			match(PARAMS);
			setState(63);
			sequence();
			setState(64);
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
		enterRule(_localctx, 10, RULE_item);
		try {
			setState(79);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case UINT:
				_localctx = new ItemUintContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(66);
				match(UINT);
				}
				break;
			case UFLOAT:
				_localctx = new ItemUfloatContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(67);
				match(UFLOAT);
				}
				break;
			case UPITCH:
				_localctx = new ItemUpitchContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(68);
				match(UPITCH);
				}
				break;
			case INLET:
				_localctx = new ItemInletContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(69);
				match(INLET);
				}
				break;
			case OPEN:
				_localctx = new ItemSequenceContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(70);
				match(OPEN);
				setState(71);
				sequence();
				setState(72);
				match(CLOSED);
				}
				break;
			case PUSH:
				_localctx = new ItemSublistContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(74);
				match(PUSH);
				setState(75);
				sequence();
				setState(76);
				match(POP);
				}
				break;
			case FUNCTION:
				_localctx = new ItemFuncallContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(78);
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
		enterRule(_localctx, 12, RULE_var);
		try {
			setState(84);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LOCALVAR:
				_localctx = new VarLocalContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(81);
				match(LOCALVAR);
				}
				break;
			case PATCHERVAR:
				_localctx = new VarPatcherContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(82);
				match(PATCHERVAR);
				}
				break;
			case GLOBALVAR:
				_localctx = new VarGlobalContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(83);
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
		enterRule(_localctx, 14, RULE_lvalueSpecs);
		try {
			int _alt;
			setState(109);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				ending = false;
				setState(92); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(87);
						match(NTH);
						setState(90);
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
							setState(88);
							item();
							}
							break;
						case GLOBALVAR:
						case PATCHERVAR:
						case LOCALVAR:
							{
							setState(89);
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
					setState(94); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				ending = true;
				setState(104);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(97);
						match(NTH);
						setState(100);
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
							setState(98);
							item();
							}
							break;
						case GLOBALVAR:
						case PATCHERVAR:
						case LOCALVAR:
							{
							setState(99);
							var();
							}
							break;
						default:
							throw new NoViableAltException(this);
						}
						}
						} 
					}
					setState(106);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
				}
				{
				setState(107);
				match(NTH);
				{
				setState(108);
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
		enterRule(_localctx, 16, RULE_lvalue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(111);
			var();
			setState(113);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				{
				setState(112);
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
		enterRule(_localctx, 18, RULE_fakeLvalue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(115);
			item();
			setState(116);
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
		public List<TerminalNode> UPLUS() { return getTokens(bellParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(bellParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(bellParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(bellParser.UMINUS, i);
		}
		public ExprFakeLvalueContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprPlusMinusContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode PLUS() { return getToken(bellParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(bellParser.MINUS, 0); }
		public ExprPlusMinusContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprVarContext extends ExprContext {
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public List<TerminalNode> UPLUS() { return getTokens(bellParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(bellParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(bellParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(bellParser.UMINUS, i);
		}
		public ExprVarContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprPowContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode POW() { return getToken(bellParser.POW, 0); }
		public ExprPowContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprUnaryContext extends ExprContext {
		public ItemContext item() {
			return getRuleContext(ItemContext.class,0);
		}
		public List<TerminalNode> UPLUS() { return getTokens(bellParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(bellParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(bellParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(bellParser.UMINUS, i);
		}
		public ExprUnaryContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprTimesDivContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode TIMES() { return getToken(bellParser.TIMES, 0); }
		public TerminalNode DIV() { return getToken(bellParser.DIV, 0); }
		public TerminalNode DIVDIV() { return getToken(bellParser.DIVDIV, 0); }
		public ExprTimesDivContext(ExprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprLvalueContext extends ExprContext {
		public LvalueContext lvalue() {
			return getRuleContext(LvalueContext.class,0);
		}
		public List<TerminalNode> UPLUS() { return getTokens(bellParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(bellParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(bellParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(bellParser.UMINUS, i);
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
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(149);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				{
				_localctx = new ExprUnaryContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(122);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==UPLUS || _la==UMINUS) {
					{
					{
					setState(119);
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
					setState(124);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(125);
				item();
				}
				break;
			case 2:
				{
				_localctx = new ExprVarContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(129);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==UPLUS || _la==UMINUS) {
					{
					{
					setState(126);
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
					setState(131);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(132);
				var();
				}
				break;
			case 3:
				{
				_localctx = new ExprLvalueContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(133);
				if (!(!ending)) throw new FailedPredicateException(this, "!ending");
				setState(137);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==UPLUS || _la==UMINUS) {
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
					setState(139);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(140);
				lvalue();
				}
				break;
			case 4:
				{
				_localctx = new ExprFakeLvalueContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(141);
				if (!(!ending)) throw new FailedPredicateException(this, "!ending");
				setState(145);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==UPLUS || _la==UMINUS) {
					{
					{
					setState(142);
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
					setState(147);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(148);
				fakeLvalue();
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(162);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(160);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
					case 1:
						{
						_localctx = new ExprPowContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(151);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(152);
						match(POW);
						setState(153);
						expr(8);
						}
						break;
					case 2:
						{
						_localctx = new ExprTimesDivContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(154);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(155);
						((ExprTimesDivContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 234881024L) != 0)) ) {
							((ExprTimesDivContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(156);
						expr(5);
						}
						break;
					case 3:
						{
						_localctx = new ExprPlusMinusContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(157);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(158);
						((ExprPlusMinusContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==MINUS) ) {
							((ExprPlusMinusContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(159);
						expr(4);
						}
						break;
					}
					} 
				}
				setState(164);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
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
		public List<TerminalNode> UPLUS() { return getTokens(bellParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(bellParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(bellParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(bellParser.UMINUS, i);
		}
		public EexprLvalueContext(EexprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EexprTimesDivContext extends EexprContext {
		public Token op;
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ListEndContext listEnd() {
			return getRuleContext(ListEndContext.class,0);
		}
		public TerminalNode TIMES() { return getToken(bellParser.TIMES, 0); }
		public TerminalNode DIV() { return getToken(bellParser.DIV, 0); }
		public TerminalNode DIVDIV() { return getToken(bellParser.DIVDIV, 0); }
		public EexprTimesDivContext(EexprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EexprFakeLvalueContext extends EexprContext {
		public FakeLvalueContext fakeLvalue() {
			return getRuleContext(FakeLvalueContext.class,0);
		}
		public List<TerminalNode> UPLUS() { return getTokens(bellParser.UPLUS); }
		public TerminalNode UPLUS(int i) {
			return getToken(bellParser.UPLUS, i);
		}
		public List<TerminalNode> UMINUS() { return getTokens(bellParser.UMINUS); }
		public TerminalNode UMINUS(int i) {
			return getToken(bellParser.UMINUS, i);
		}
		public EexprFakeLvalueContext(EexprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EexprPlusMinusContext extends EexprContext {
		public Token op;
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ListEndContext listEnd() {
			return getRuleContext(ListEndContext.class,0);
		}
		public TerminalNode PLUS() { return getToken(bellParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(bellParser.MINUS, 0); }
		public EexprPlusMinusContext(EexprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EexprPowContext extends EexprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode POW() { return getToken(bellParser.POW, 0); }
		public ListEndContext listEnd() {
			return getRuleContext(ListEndContext.class,0);
		}
		public EexprPowContext(EexprContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EexprUnaryContext extends EexprContext {
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
		public EexprUnaryContext(EexprContext ctx) { copyFrom(ctx); }
	}

	public final EexprContext eexpr() throws RecognitionException {
		EexprContext _localctx = new EexprContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_eexpr);
		int _la;
		try {
			setState(200);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
			case 1:
				_localctx = new EexprPowContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(165);
				expr(0);
				setState(166);
				match(POW);
				setState(167);
				listEnd();
				}
				break;
			case 2:
				_localctx = new EexprUnaryContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(172);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==UPLUS || _la==UMINUS) {
					{
					{
					setState(169);
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
					setState(174);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(175);
				listEnd();
				}
				break;
			case 3:
				_localctx = new EexprTimesDivContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(176);
				expr(0);
				setState(177);
				((EexprTimesDivContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 234881024L) != 0)) ) {
					((EexprTimesDivContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(178);
				listEnd();
				}
				break;
			case 4:
				_localctx = new EexprPlusMinusContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(180);
				expr(0);
				setState(181);
				((EexprPlusMinusContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==PLUS || _la==MINUS) ) {
					((EexprPlusMinusContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(182);
				listEnd();
				}
				break;
			case 5:
				_localctx = new EexprLvalueContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(184);
				if (!(ending)) throw new FailedPredicateException(this, "ending");
				setState(188);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==UPLUS || _la==UMINUS) {
					{
					{
					setState(185);
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
					setState(190);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(191);
				lvalue();
				}
				break;
			case 6:
				_localctx = new EexprFakeLvalueContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(192);
				if (!(ending)) throw new FailedPredicateException(this, "ending");
				setState(196);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==UPLUS || _la==UMINUS) {
					{
					{
					setState(193);
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
					setState(198);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(199);
				fakeLvalue();
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
		enterRule(_localctx, 24, RULE_assignment);
		try {
			setState(210);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case GLOBALVAR:
			case PATCHERVAR:
			case LOCALVAR:
				_localctx = new TrueAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(202);
				lvalue();
				setState(203);
				match(ASSIGN);
				setState(204);
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
				setState(206);
				fakeLvalue();
				setState(207);
				match(ASSIGN);
				setState(208);
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
			setState(224);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
			case 1:
				_localctx = new IfthenContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(212);
				match(IF);
				setState(213);
				sequence();
				setState(214);
				match(THEN);
				setState(215);
				list();
				}
				break;
			case 2:
				_localctx = new IfthenelseContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(217);
				match(IF);
				setState(218);
				sequence();
				setState(219);
				match(THEN);
				setState(220);
				sequence();
				setState(221);
				match(ELSE);
				setState(222);
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
		public ListEndContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_listEnd; }
	}

	public final ListEndContext listEnd() throws RecognitionException {
		ListEndContext _localctx = new ListEndContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_listEnd);
		try {
			setState(228);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IF:
				enterOuterAlt(_localctx, 1);
				{
				setState(226);
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
				setState(227);
				assignment();
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
		enterRule(_localctx, 30, RULE_list);
		try {
			int _alt;
			setState(249);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,30,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(231); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(230);
						expr(0);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(233); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(238);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(235);
						expr(0);
						}
						} 
					}
					setState(240);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
				}
				setState(241);
				eexpr();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(245);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(242);
						expr(0);
						}
						} 
					}
					setState(247);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
				}
				setState(248);
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
		case 10:
			return expr_sempred((ExprContext)_localctx, predIndex);
		case 11:
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
			return precpred(_ctx, 7);
		case 3:
			return precpred(_ctx, 4);
		case 4:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean eexpr_sempred(EexprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 5:
			return ending;
		case 6:
			return ending;
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001\"\u00fc\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
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
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0003\u0005P\b\u0005\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0003\u0006U\b\u0006\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0003\u0007[\b\u0007\u0004\u0007]\b\u0007"+
		"\u000b\u0007\f\u0007^\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0003\u0007e\b\u0007\u0005\u0007g\b\u0007\n\u0007\f\u0007j\t\u0007\u0001"+
		"\u0007\u0001\u0007\u0003\u0007n\b\u0007\u0001\b\u0001\b\u0003\br\b\b\u0001"+
		"\t\u0001\t\u0001\t\u0001\n\u0001\n\u0005\ny\b\n\n\n\f\n|\t\n\u0001\n\u0001"+
		"\n\u0005\n\u0080\b\n\n\n\f\n\u0083\t\n\u0001\n\u0001\n\u0001\n\u0005\n"+
		"\u0088\b\n\n\n\f\n\u008b\t\n\u0001\n\u0001\n\u0001\n\u0005\n\u0090\b\n"+
		"\n\n\f\n\u0093\t\n\u0001\n\u0003\n\u0096\b\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0005\n\u00a1\b\n\n\n\f\n\u00a4"+
		"\t\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0005"+
		"\u000b\u00ab\b\u000b\n\u000b\f\u000b\u00ae\t\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0005\u000b\u00bb\b\u000b\n\u000b"+
		"\f\u000b\u00be\t\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0005\u000b"+
		"\u00c3\b\u000b\n\u000b\f\u000b\u00c6\t\u000b\u0001\u000b\u0003\u000b\u00c9"+
		"\b\u000b\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0003\f\u00d3\b\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0003\r\u00e1\b\r\u0001\u000e"+
		"\u0001\u000e\u0003\u000e\u00e5\b\u000e\u0001\u000f\u0004\u000f\u00e8\b"+
		"\u000f\u000b\u000f\f\u000f\u00e9\u0001\u000f\u0005\u000f\u00ed\b\u000f"+
		"\n\u000f\f\u000f\u00f0\t\u000f\u0001\u000f\u0001\u000f\u0005\u000f\u00f4"+
		"\b\u000f\n\u000f\f\u000f\u00f7\t\u000f\u0001\u000f\u0003\u000f\u00fa\b"+
		"\u000f\u0001\u000f\u0000\u0001\u0014\u0010\u0000\u0002\u0004\u0006\b\n"+
		"\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e\u0000\u0003\u0002"+
		"\u0000\u001d\u001d\u001f\u001f\u0001\u0000\u0019\u001b\u0002\u0000\u001c"+
		"\u001c\u001e\u001e\u011a\u0000 \u0001\u0000\u0000\u0000\u0002*\u0001\u0000"+
		"\u0000\u0000\u00045\u0001\u0000\u0000\u0000\u00067\u0001\u0000\u0000\u0000"+
		"\b=\u0001\u0000\u0000\u0000\nO\u0001\u0000\u0000\u0000\fT\u0001\u0000"+
		"\u0000\u0000\u000em\u0001\u0000\u0000\u0000\u0010o\u0001\u0000\u0000\u0000"+
		"\u0012s\u0001\u0000\u0000\u0000\u0014\u0095\u0001\u0000\u0000\u0000\u0016"+
		"\u00c8\u0001\u0000\u0000\u0000\u0018\u00d2\u0001\u0000\u0000\u0000\u001a"+
		"\u00e0\u0001\u0000\u0000\u0000\u001c\u00e4\u0001\u0000\u0000\u0000\u001e"+
		"\u00f9\u0001\u0000\u0000\u0000 !\u0003\u0002\u0001\u0000!\u0001\u0001"+
		"\u0000\u0000\u0000\"+\u0005\u0000\u0000\u0001#$\u0003\u0004\u0002\u0000"+
		"$%\u0005\u0000\u0000\u0001%+\u0001\u0000\u0000\u0000&\'\u0003\u0004\u0002"+
		"\u0000\'(\u0005\u000e\u0000\u0000(+\u0001\u0000\u0000\u0000)+\u0005\u000e"+
		"\u0000\u0000*\"\u0001\u0000\u0000\u0000*#\u0001\u0000\u0000\u0000*&\u0001"+
		"\u0000\u0000\u0000*)\u0001\u0000\u0000\u0000+\u0003\u0001\u0000\u0000"+
		"\u0000,6\u0003\u001e\u000f\u0000-/\u0003\u0006\u0003\u0000.-\u0001\u0000"+
		"\u0000\u0000/0\u0001\u0000\u0000\u00000.\u0001\u0000\u0000\u000001\u0001"+
		"\u0000\u0000\u000013\u0001\u0000\u0000\u000024\u0003\u001e\u000f\u0000"+
		"32\u0001\u0000\u0000\u000034\u0001\u0000\u0000\u000046\u0001\u0000\u0000"+
		"\u00005,\u0001\u0000\u0000\u00005.\u0001\u0000\u0000\u00006\u0005\u0001"+
		"\u0000\u0000\u000079\u0003\u001e\u000f\u00008:\u0005\u0014\u0000\u0000"+
		"98\u0001\u0000\u0000\u0000:;\u0001\u0000\u0000\u0000;9\u0001\u0000\u0000"+
		"\u0000;<\u0001\u0000\u0000\u0000<\u0007\u0001\u0000\u0000\u0000=>\u0005"+
		"\t\u0000\u0000>?\u0005!\u0000\u0000?@\u0003\u0004\u0002\u0000@A\u0005"+
		"\u0011\u0000\u0000A\t\u0001\u0000\u0000\u0000BP\u0005\u0001\u0000\u0000"+
		"CP\u0005\u0002\u0000\u0000DP\u0005\u0003\u0000\u0000EP\u0005\n\u0000\u0000"+
		"FG\u0005 \u0000\u0000GH\u0003\u0004\u0002\u0000HI\u0005\u0011\u0000\u0000"+
		"IP\u0001\u0000\u0000\u0000JK\u0005\u000f\u0000\u0000KL\u0003\u0004\u0002"+
		"\u0000LM\u0005\u0010\u0000\u0000MP\u0001\u0000\u0000\u0000NP\u0003\b\u0004"+
		"\u0000OB\u0001\u0000\u0000\u0000OC\u0001\u0000\u0000\u0000OD\u0001\u0000"+
		"\u0000\u0000OE\u0001\u0000\u0000\u0000OF\u0001\u0000\u0000\u0000OJ\u0001"+
		"\u0000\u0000\u0000ON\u0001\u0000\u0000\u0000P\u000b\u0001\u0000\u0000"+
		"\u0000QU\u0005\r\u0000\u0000RU\u0005\f\u0000\u0000SU\u0005\u000b\u0000"+
		"\u0000TQ\u0001\u0000\u0000\u0000TR\u0001\u0000\u0000\u0000TS\u0001\u0000"+
		"\u0000\u0000U\r\u0001\u0000\u0000\u0000V\\\u0006\u0007\uffff\uffff\u0000"+
		"WZ\u0005\u0012\u0000\u0000X[\u0003\n\u0005\u0000Y[\u0003\f\u0006\u0000"+
		"ZX\u0001\u0000\u0000\u0000ZY\u0001\u0000\u0000\u0000[]\u0001\u0000\u0000"+
		"\u0000\\W\u0001\u0000\u0000\u0000]^\u0001\u0000\u0000\u0000^\\\u0001\u0000"+
		"\u0000\u0000^_\u0001\u0000\u0000\u0000_n\u0001\u0000\u0000\u0000`h\u0006"+
		"\u0007\uffff\uffff\u0000ad\u0005\u0012\u0000\u0000be\u0003\n\u0005\u0000"+
		"ce\u0003\f\u0006\u0000db\u0001\u0000\u0000\u0000dc\u0001\u0000\u0000\u0000"+
		"eg\u0001\u0000\u0000\u0000fa\u0001\u0000\u0000\u0000gj\u0001\u0000\u0000"+
		"\u0000hf\u0001\u0000\u0000\u0000hi\u0001\u0000\u0000\u0000ik\u0001\u0000"+
		"\u0000\u0000jh\u0001\u0000\u0000\u0000kl\u0005\u0012\u0000\u0000ln\u0003"+
		"\u001a\r\u0000mV\u0001\u0000\u0000\u0000m`\u0001\u0000\u0000\u0000n\u000f"+
		"\u0001\u0000\u0000\u0000oq\u0003\f\u0006\u0000pr\u0003\u000e\u0007\u0000"+
		"qp\u0001\u0000\u0000\u0000qr\u0001\u0000\u0000\u0000r\u0011\u0001\u0000"+
		"\u0000\u0000st\u0003\n\u0005\u0000tu\u0003\u000e\u0007\u0000u\u0013\u0001"+
		"\u0000\u0000\u0000vz\u0006\n\uffff\uffff\u0000wy\u0007\u0000\u0000\u0000"+
		"xw\u0001\u0000\u0000\u0000y|\u0001\u0000\u0000\u0000zx\u0001\u0000\u0000"+
		"\u0000z{\u0001\u0000\u0000\u0000{}\u0001\u0000\u0000\u0000|z\u0001\u0000"+
		"\u0000\u0000}\u0096\u0003\n\u0005\u0000~\u0080\u0007\u0000\u0000\u0000"+
		"\u007f~\u0001\u0000\u0000\u0000\u0080\u0083\u0001\u0000\u0000\u0000\u0081"+
		"\u007f\u0001\u0000\u0000\u0000\u0081\u0082\u0001\u0000\u0000\u0000\u0082"+
		"\u0084\u0001\u0000\u0000\u0000\u0083\u0081\u0001\u0000\u0000\u0000\u0084"+
		"\u0096\u0003\f\u0006\u0000\u0085\u0089\u0004\n\u0000\u0000\u0086\u0088"+
		"\u0007\u0000\u0000\u0000\u0087\u0086\u0001\u0000\u0000\u0000\u0088\u008b"+
		"\u0001\u0000\u0000\u0000\u0089\u0087\u0001\u0000\u0000\u0000\u0089\u008a"+
		"\u0001\u0000\u0000\u0000\u008a\u008c\u0001\u0000\u0000\u0000\u008b\u0089"+
		"\u0001\u0000\u0000\u0000\u008c\u0096\u0003\u0010\b\u0000\u008d\u0091\u0004"+
		"\n\u0001\u0000\u008e\u0090\u0007\u0000\u0000\u0000\u008f\u008e\u0001\u0000"+
		"\u0000\u0000\u0090\u0093\u0001\u0000\u0000\u0000\u0091\u008f\u0001\u0000"+
		"\u0000\u0000\u0091\u0092\u0001\u0000\u0000\u0000\u0092\u0094\u0001\u0000"+
		"\u0000\u0000\u0093\u0091\u0001\u0000\u0000\u0000\u0094\u0096\u0003\u0012"+
		"\t\u0000\u0095v\u0001\u0000\u0000\u0000\u0095\u0081\u0001\u0000\u0000"+
		"\u0000\u0095\u0085\u0001\u0000\u0000\u0000\u0095\u008d\u0001\u0000\u0000"+
		"\u0000\u0096\u00a2\u0001\u0000\u0000\u0000\u0097\u0098\n\u0007\u0000\u0000"+
		"\u0098\u0099\u0005\u0018\u0000\u0000\u0099\u00a1\u0003\u0014\n\b\u009a"+
		"\u009b\n\u0004\u0000\u0000\u009b\u009c\u0007\u0001\u0000\u0000\u009c\u00a1"+
		"\u0003\u0014\n\u0005\u009d\u009e\n\u0003\u0000\u0000\u009e\u009f\u0007"+
		"\u0002\u0000\u0000\u009f\u00a1\u0003\u0014\n\u0004\u00a0\u0097\u0001\u0000"+
		"\u0000\u0000\u00a0\u009a\u0001\u0000\u0000\u0000\u00a0\u009d\u0001\u0000"+
		"\u0000\u0000\u00a1\u00a4\u0001\u0000\u0000\u0000\u00a2\u00a0\u0001\u0000"+
		"\u0000\u0000\u00a2\u00a3\u0001\u0000\u0000\u0000\u00a3\u0015\u0001\u0000"+
		"\u0000\u0000\u00a4\u00a2\u0001\u0000\u0000\u0000\u00a5\u00a6\u0003\u0014"+
		"\n\u0000\u00a6\u00a7\u0005\u0018\u0000\u0000\u00a7\u00a8\u0003\u001c\u000e"+
		"\u0000\u00a8\u00c9\u0001\u0000\u0000\u0000\u00a9\u00ab\u0007\u0000\u0000"+
		"\u0000\u00aa\u00a9\u0001\u0000\u0000\u0000\u00ab\u00ae\u0001\u0000\u0000"+
		"\u0000\u00ac\u00aa\u0001\u0000\u0000\u0000\u00ac\u00ad\u0001\u0000\u0000"+
		"\u0000\u00ad\u00af\u0001\u0000\u0000\u0000\u00ae\u00ac\u0001\u0000\u0000"+
		"\u0000\u00af\u00c9\u0003\u001c\u000e\u0000\u00b0\u00b1\u0003\u0014\n\u0000"+
		"\u00b1\u00b2\u0007\u0001\u0000\u0000\u00b2\u00b3\u0003\u001c\u000e\u0000"+
		"\u00b3\u00c9\u0001\u0000\u0000\u0000\u00b4\u00b5\u0003\u0014\n\u0000\u00b5"+
		"\u00b6\u0007\u0002\u0000\u0000\u00b6\u00b7\u0003\u001c\u000e\u0000\u00b7"+
		"\u00c9\u0001\u0000\u0000\u0000\u00b8\u00bc\u0004\u000b\u0005\u0000\u00b9"+
		"\u00bb\u0007\u0000\u0000\u0000\u00ba\u00b9\u0001\u0000\u0000\u0000\u00bb"+
		"\u00be\u0001\u0000\u0000\u0000\u00bc\u00ba\u0001\u0000\u0000\u0000\u00bc"+
		"\u00bd\u0001\u0000\u0000\u0000\u00bd\u00bf\u0001\u0000\u0000\u0000\u00be"+
		"\u00bc\u0001\u0000\u0000\u0000\u00bf\u00c9\u0003\u0010\b\u0000\u00c0\u00c4"+
		"\u0004\u000b\u0006\u0000\u00c1\u00c3\u0007\u0000\u0000\u0000\u00c2\u00c1"+
		"\u0001\u0000\u0000\u0000\u00c3\u00c6\u0001\u0000\u0000\u0000\u00c4\u00c2"+
		"\u0001\u0000\u0000\u0000\u00c4\u00c5\u0001\u0000\u0000\u0000\u00c5\u00c7"+
		"\u0001\u0000\u0000\u0000\u00c6\u00c4\u0001\u0000\u0000\u0000\u00c7\u00c9"+
		"\u0003\u0012\t\u0000\u00c8\u00a5\u0001\u0000\u0000\u0000\u00c8\u00ac\u0001"+
		"\u0000\u0000\u0000\u00c8\u00b0\u0001\u0000\u0000\u0000\u00c8\u00b4\u0001"+
		"\u0000\u0000\u0000\u00c8\u00b8\u0001\u0000\u0000\u0000\u00c8\u00c0\u0001"+
		"\u0000\u0000\u0000\u00c9\u0017\u0001\u0000\u0000\u0000\u00ca\u00cb\u0003"+
		"\u0010\b\u0000\u00cb\u00cc\u0005\u0015\u0000\u0000\u00cc\u00cd\u0003\u001e"+
		"\u000f\u0000\u00cd\u00d3\u0001\u0000\u0000\u0000\u00ce\u00cf\u0003\u0012"+
		"\t\u0000\u00cf\u00d0\u0005\u0015\u0000\u0000\u00d0\u00d1\u0003\u001e\u000f"+
		"\u0000\u00d1\u00d3\u0001\u0000\u0000\u0000\u00d2\u00ca\u0001\u0000\u0000"+
		"\u0000\u00d2\u00ce\u0001\u0000\u0000\u0000\u00d3\u0019\u0001\u0000\u0000"+
		"\u0000\u00d4\u00d5\u0005\u0004\u0000\u0000\u00d5\u00d6\u0003\u0004\u0002"+
		"\u0000\u00d6\u00d7\u0005\u0005\u0000\u0000\u00d7\u00d8\u0003\u001e\u000f"+
		"\u0000\u00d8\u00e1\u0001\u0000\u0000\u0000\u00d9\u00da\u0005\u0004\u0000"+
		"\u0000\u00da\u00db\u0003\u0004\u0002\u0000\u00db\u00dc\u0005\u0005\u0000"+
		"\u0000\u00dc\u00dd\u0003\u0004\u0002\u0000\u00dd\u00de\u0005\u0006\u0000"+
		"\u0000\u00de\u00df\u0003\u001e\u000f\u0000\u00df\u00e1\u0001\u0000\u0000"+
		"\u0000\u00e0\u00d4\u0001\u0000\u0000\u0000\u00e0\u00d9\u0001\u0000\u0000"+
		"\u0000\u00e1\u001b\u0001\u0000\u0000\u0000\u00e2\u00e5\u0003\u001a\r\u0000"+
		"\u00e3\u00e5\u0003\u0018\f\u0000\u00e4\u00e2\u0001\u0000\u0000\u0000\u00e4"+
		"\u00e3\u0001\u0000\u0000\u0000\u00e5\u001d\u0001\u0000\u0000\u0000\u00e6"+
		"\u00e8\u0003\u0014\n\u0000\u00e7\u00e6\u0001\u0000\u0000\u0000\u00e8\u00e9"+
		"\u0001\u0000\u0000\u0000\u00e9\u00e7\u0001\u0000\u0000\u0000\u00e9\u00ea"+
		"\u0001\u0000\u0000\u0000\u00ea\u00fa\u0001\u0000\u0000\u0000\u00eb\u00ed"+
		"\u0003\u0014\n\u0000\u00ec\u00eb\u0001\u0000\u0000\u0000\u00ed\u00f0\u0001"+
		"\u0000\u0000\u0000\u00ee\u00ec\u0001\u0000\u0000\u0000\u00ee\u00ef\u0001"+
		"\u0000\u0000\u0000\u00ef\u00f1\u0001\u0000\u0000\u0000\u00f0\u00ee\u0001"+
		"\u0000\u0000\u0000\u00f1\u00fa\u0003\u0016\u000b\u0000\u00f2\u00f4\u0003"+
		"\u0014\n\u0000\u00f3\u00f2\u0001\u0000\u0000\u0000\u00f4\u00f7\u0001\u0000"+
		"\u0000\u0000\u00f5\u00f3\u0001\u0000\u0000\u0000\u00f5\u00f6\u0001\u0000"+
		"\u0000\u0000\u00f6\u00f8\u0001\u0000\u0000\u0000\u00f7\u00f5\u0001\u0000"+
		"\u0000\u0000\u00f8\u00fa\u0003\u001c\u000e\u0000\u00f9\u00e7\u0001\u0000"+
		"\u0000\u0000\u00f9\u00ee\u0001\u0000\u0000\u0000\u00f9\u00f5\u0001\u0000"+
		"\u0000\u0000\u00fa\u001f\u0001\u0000\u0000\u0000\u001f*035;OTZ^dhmqz\u0081"+
		"\u0089\u0091\u0095\u00a0\u00a2\u00ac\u00bc\u00c4\u00c8\u00d2\u00e0\u00e4"+
		"\u00e9\u00ee\u00f5\u00f9";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}