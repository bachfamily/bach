// Generated from /Users/aa/Documents/Max 8/Packages/bach/source/commons/bell/antlrparser/bell.g4 by ANTLR 4.13.1
 
#include "ext.h" 

import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class bellLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		NUMBER=1, IF=2, THEN=3, ELSE=4, FOR=5, DO=6, FUNCTION=7, VAR=8, PUSH=9, 
		POP=10, CLOSED=11, NTH=12, KEY=13, NULLIFY=14, ASSIGN=15, EOL=16, WHITESPACE=17, 
		POW=18, TIMES=19, DIVDIV=20, DIV=21, PLUS=22, UPLUS=23, MINUS=24, UMINUS=25, 
		OPEN=26, PARAMS=27;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"NUMBER", "IF", "THEN", "ELSE", "FOR", "DO", "FUNCTION", "VAR", "PUSH", 
			"POP", "CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", 
			"POW", "TIMES", "DIVDIV", "DIV", "PLUS", "UPLUS", "MINUS", "UMINUS", 
			"OPEN", "PARAMS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, "'if'", "'then'", "'else'", "'for'", "'do'", null, null, 
			"'['", "']'", "')'", "':'", "'.'", "';'", "'='", "'\\n'", null, "'**'", 
			"'*'", "'//'", "'/'", null, "'+'", null, "'-'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "NUMBER", "IF", "THEN", "ELSE", "FOR", "DO", "FUNCTION", "VAR", 
			"PUSH", "POP", "CLOSED", "NTH", "KEY", "NULLIFY", "ASSIGN", "EOL", "WHITESPACE", 
			"POW", "TIMES", "DIVDIV", "DIV", "PLUS", "UPLUS", "MINUS", "UMINUS", 
			"OPEN", "PARAMS"
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



	    //// MEMBERS

	    bool noParams = true;
	    bool noUnary = false;
	    
	    bool followedBySpace() {
	        int c = _input->LA(2);
	        post("\c", c);
	        switch (c) {
	            case ' ':
	            case '\x01':
	            case '\t':
	            case '\n':
	            case '\r':
	                return true;
	            default:
	                return false;
	        }
	    }

	    bool notUnary() {
	        post("noUnary %d\n", noUnary);
	        post("fbs %d\n", followedBySpace());
	        return noUnary || followedBySpace();
	    }

	    //// MEMBERS END


	public bellLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "bell.g4"; }

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

	@Override
	public void action(RuleContext _localctx, int ruleIndex, int actionIndex) {
		switch (ruleIndex) {
		case 0:
			NUMBER_action((RuleContext)_localctx, actionIndex);
			break;
		case 1:
			IF_action((RuleContext)_localctx, actionIndex);
			break;
		case 2:
			THEN_action((RuleContext)_localctx, actionIndex);
			break;
		case 3:
			ELSE_action((RuleContext)_localctx, actionIndex);
			break;
		case 4:
			FOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 5:
			DO_action((RuleContext)_localctx, actionIndex);
			break;
		case 6:
			FUNCTION_action((RuleContext)_localctx, actionIndex);
			break;
		case 7:
			VAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 8:
			PUSH_action((RuleContext)_localctx, actionIndex);
			break;
		case 9:
			POP_action((RuleContext)_localctx, actionIndex);
			break;
		case 10:
			CLOSED_action((RuleContext)_localctx, actionIndex);
			break;
		case 11:
			NTH_action((RuleContext)_localctx, actionIndex);
			break;
		case 12:
			KEY_action((RuleContext)_localctx, actionIndex);
			break;
		case 13:
			NULLIFY_action((RuleContext)_localctx, actionIndex);
			break;
		case 14:
			ASSIGN_action((RuleContext)_localctx, actionIndex);
			break;
		case 15:
			EOL_action((RuleContext)_localctx, actionIndex);
			break;
		case 16:
			WHITESPACE_action((RuleContext)_localctx, actionIndex);
			break;
		case 17:
			POW_action((RuleContext)_localctx, actionIndex);
			break;
		case 18:
			TIMES_action((RuleContext)_localctx, actionIndex);
			break;
		case 19:
			DIVDIV_action((RuleContext)_localctx, actionIndex);
			break;
		case 20:
			DIV_action((RuleContext)_localctx, actionIndex);
			break;
		case 21:
			PLUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 22:
			UPLUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 23:
			MINUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 24:
			UMINUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 25:
			OPEN_action((RuleContext)_localctx, actionIndex);
			break;
		case 26:
			PARAMS_action((RuleContext)_localctx, actionIndex);
			break;
		}
	}
	private void NUMBER_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 0:
			 std::cout << "number\n"; noParams = false; noUnary = true; 
			break;
		}
	}
	private void IF_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 1:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void THEN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 2:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ELSE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 3:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void FOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 4:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DO_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 5:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void FUNCTION_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 6:
			 noParams = noUnary = false; 
			break;
		}
	}
	private void VAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 7:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void PUSH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 8:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void POP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 9:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void CLOSED_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 10:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void NTH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 11:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void KEY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 12:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void NULLIFY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 13:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ASSIGN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 14:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void EOL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 15:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void WHITESPACE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 16:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void POW_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 17:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void TIMES_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 18:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DIVDIV_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 19:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DIV_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 20:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PLUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 21:
			 post("plus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void UPLUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 22:
			 post("uplus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void MINUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 23:
			 post("minus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void UMINUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 24:
			 post("uminus!\n"); noParams = true; noUnary = false; 
			break;
		}
	}
	private void OPEN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 25:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PARAMS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 26:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	@Override
	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 21:
			return PLUS_sempred((RuleContext)_localctx, predIndex);
		case 23:
			return MINUS_sempred((RuleContext)_localctx, predIndex);
		case 25:
			return OPEN_sempred((RuleContext)_localctx, predIndex);
		case 26:
			return PARAMS_sempred((RuleContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean PLUS_sempred(RuleContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return  notUnary() ;
		}
		return true;
	}
	private boolean MINUS_sempred(RuleContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return  notUnary() ;
		}
		return true;
	}
	private boolean OPEN_sempred(RuleContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return  noParams ;
		}
		return true;
	}
	private boolean PARAMS_sempred(RuleContext _localctx, int predIndex) {
		switch (predIndex) {
		case 3:
			return  !noParams ;
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0000\u001b\u00b0\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002"+
		"\u0001\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002"+
		"\u0004\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002"+
		"\u0007\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002"+
		"\u000b\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e"+
		"\u0002\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011"+
		"\u0002\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014"+
		"\u0002\u0015\u0007\u0015\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017"+
		"\u0002\u0018\u0007\u0018\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a"+
		"\u0001\u0000\u0004\u00009\b\u0000\u000b\u0000\f\u0000:\u0001\u0000\u0001"+
		"\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001"+
		"\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0003\u0006i\b\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\b\u0001\b\u0001\b\u0001\t\u0001\t\u0001\t\u0001\n\u0001\n\u0001\n\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\f\u0001\f\u0001\f\u0001\r\u0001\r"+
		"\u0001\r\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0017\u0001"+
		"\u0017\u0001\u0017\u0001\u0017\u0001\u0018\u0001\u0018\u0001\u0018\u0001"+
		"\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u001a\u0001\u001a\u0001"+
		"\u001a\u0001\u001a\u0000\u0000\u001b\u0001\u0001\u0003\u0002\u0005\u0003"+
		"\u0007\u0004\t\u0005\u000b\u0006\r\u0007\u000f\b\u0011\t\u0013\n\u0015"+
		"\u000b\u0017\f\u0019\r\u001b\u000e\u001d\u000f\u001f\u0010!\u0011#\u0012"+
		"%\u0013\'\u0014)\u0015+\u0016-\u0017/\u00181\u00193\u001a5\u001b\u0001"+
		"\u0000\u0003\u0001\u000009\u0001\u0000az\u0003\u0000\u0001\u0001\t\t "+
		" \u00b2\u0000\u0001\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000"+
		"\u0000\u0000\u0005\u0001\u0000\u0000\u0000\u0000\u0007\u0001\u0000\u0000"+
		"\u0000\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b\u0001\u0000\u0000\u0000"+
		"\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001\u0000\u0000\u0000\u0000"+
		"\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001\u0000\u0000\u0000\u0000"+
		"\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001\u0000\u0000\u0000\u0000"+
		"\u0019\u0001\u0000\u0000\u0000\u0000\u001b\u0001\u0000\u0000\u0000\u0000"+
		"\u001d\u0001\u0000\u0000\u0000\u0000\u001f\u0001\u0000\u0000\u0000\u0000"+
		"!\u0001\u0000\u0000\u0000\u0000#\u0001\u0000\u0000\u0000\u0000%\u0001"+
		"\u0000\u0000\u0000\u0000\'\u0001\u0000\u0000\u0000\u0000)\u0001\u0000"+
		"\u0000\u0000\u0000+\u0001\u0000\u0000\u0000\u0000-\u0001\u0000\u0000\u0000"+
		"\u0000/\u0001\u0000\u0000\u0000\u00001\u0001\u0000\u0000\u0000\u00003"+
		"\u0001\u0000\u0000\u0000\u00005\u0001\u0000\u0000\u0000\u00018\u0001\u0000"+
		"\u0000\u0000\u0003>\u0001\u0000\u0000\u0000\u0005C\u0001\u0000\u0000\u0000"+
		"\u0007J\u0001\u0000\u0000\u0000\tQ\u0001\u0000\u0000\u0000\u000bW\u0001"+
		"\u0000\u0000\u0000\rh\u0001\u0000\u0000\u0000\u000fj\u0001\u0000\u0000"+
		"\u0000\u0011m\u0001\u0000\u0000\u0000\u0013p\u0001\u0000\u0000\u0000\u0015"+
		"s\u0001\u0000\u0000\u0000\u0017v\u0001\u0000\u0000\u0000\u0019y\u0001"+
		"\u0000\u0000\u0000\u001b|\u0001\u0000\u0000\u0000\u001d\u007f\u0001\u0000"+
		"\u0000\u0000\u001f\u0082\u0001\u0000\u0000\u0000!\u0085\u0001\u0000\u0000"+
		"\u0000#\u008a\u0001\u0000\u0000\u0000%\u008f\u0001\u0000\u0000\u0000\'"+
		"\u0092\u0001\u0000\u0000\u0000)\u0097\u0001\u0000\u0000\u0000+\u009a\u0001"+
		"\u0000\u0000\u0000-\u009e\u0001\u0000\u0000\u0000/\u00a1\u0001\u0000\u0000"+
		"\u00001\u00a5\u0001\u0000\u0000\u00003\u00a8\u0001\u0000\u0000\u00005"+
		"\u00ac\u0001\u0000\u0000\u000079\u0007\u0000\u0000\u000087\u0001\u0000"+
		"\u0000\u00009:\u0001\u0000\u0000\u0000:8\u0001\u0000\u0000\u0000:;\u0001"+
		"\u0000\u0000\u0000;<\u0001\u0000\u0000\u0000<=\u0006\u0000\u0000\u0000"+
		"=\u0002\u0001\u0000\u0000\u0000>?\u0005i\u0000\u0000?@\u0005f\u0000\u0000"+
		"@A\u0001\u0000\u0000\u0000AB\u0006\u0001\u0001\u0000B\u0004\u0001\u0000"+
		"\u0000\u0000CD\u0005t\u0000\u0000DE\u0005h\u0000\u0000EF\u0005e\u0000"+
		"\u0000FG\u0005n\u0000\u0000GH\u0001\u0000\u0000\u0000HI\u0006\u0002\u0002"+
		"\u0000I\u0006\u0001\u0000\u0000\u0000JK\u0005e\u0000\u0000KL\u0005l\u0000"+
		"\u0000LM\u0005s\u0000\u0000MN\u0005e\u0000\u0000NO\u0001\u0000\u0000\u0000"+
		"OP\u0006\u0003\u0003\u0000P\b\u0001\u0000\u0000\u0000QR\u0005f\u0000\u0000"+
		"RS\u0005o\u0000\u0000ST\u0005r\u0000\u0000TU\u0001\u0000\u0000\u0000U"+
		"V\u0006\u0004\u0004\u0000V\n\u0001\u0000\u0000\u0000WX\u0005d\u0000\u0000"+
		"XY\u0005o\u0000\u0000YZ\u0001\u0000\u0000\u0000Z[\u0006\u0005\u0005\u0000"+
		"[\f\u0001\u0000\u0000\u0000\\]\u0005s\u0000\u0000]^\u0005i\u0000\u0000"+
		"^i\u0005n\u0000\u0000_`\u0005c\u0000\u0000`a\u0005o\u0000\u0000ai\u0005"+
		"s\u0000\u0000bc\u0005s\u0000\u0000cd\u0005q\u0000\u0000de\u0005r\u0000"+
		"\u0000ef\u0005t\u0000\u0000fg\u0001\u0000\u0000\u0000gi\u0006\u0006\u0006"+
		"\u0000h\\\u0001\u0000\u0000\u0000h_\u0001\u0000\u0000\u0000hb\u0001\u0000"+
		"\u0000\u0000i\u000e\u0001\u0000\u0000\u0000jk\u0007\u0001\u0000\u0000"+
		"kl\u0006\u0007\u0007\u0000l\u0010\u0001\u0000\u0000\u0000mn\u0005[\u0000"+
		"\u0000no\u0006\b\b\u0000o\u0012\u0001\u0000\u0000\u0000pq\u0005]\u0000"+
		"\u0000qr\u0006\t\t\u0000r\u0014\u0001\u0000\u0000\u0000st\u0005)\u0000"+
		"\u0000tu\u0006\n\n\u0000u\u0016\u0001\u0000\u0000\u0000vw\u0005:\u0000"+
		"\u0000wx\u0006\u000b\u000b\u0000x\u0018\u0001\u0000\u0000\u0000yz\u0005"+
		".\u0000\u0000z{\u0006\f\f\u0000{\u001a\u0001\u0000\u0000\u0000|}\u0005"+
		";\u0000\u0000}~\u0006\r\r\u0000~\u001c\u0001\u0000\u0000\u0000\u007f\u0080"+
		"\u0005=\u0000\u0000\u0080\u0081\u0006\u000e\u000e\u0000\u0081\u001e\u0001"+
		"\u0000\u0000\u0000\u0082\u0083\u0005\n\u0000\u0000\u0083\u0084\u0006\u000f"+
		"\u000f\u0000\u0084 \u0001\u0000\u0000\u0000\u0085\u0086\u0007\u0002\u0000"+
		"\u0000\u0086\u0087\u0006\u0010\u0010\u0000\u0087\u0088\u0001\u0000\u0000"+
		"\u0000\u0088\u0089\u0006\u0010\u0011\u0000\u0089\"\u0001\u0000\u0000\u0000"+
		"\u008a\u008b\u0005*\u0000\u0000\u008b\u008c\u0005*\u0000\u0000\u008c\u008d"+
		"\u0001\u0000\u0000\u0000\u008d\u008e\u0006\u0011\u0012\u0000\u008e$\u0001"+
		"\u0000\u0000\u0000\u008f\u0090\u0005*\u0000\u0000\u0090\u0091\u0006\u0012"+
		"\u0013\u0000\u0091&\u0001\u0000\u0000\u0000\u0092\u0093\u0005/\u0000\u0000"+
		"\u0093\u0094\u0005/\u0000\u0000\u0094\u0095\u0001\u0000\u0000\u0000\u0095"+
		"\u0096\u0006\u0013\u0014\u0000\u0096(\u0001\u0000\u0000\u0000\u0097\u0098"+
		"\u0005/\u0000\u0000\u0098\u0099\u0006\u0014\u0015\u0000\u0099*\u0001\u0000"+
		"\u0000\u0000\u009a\u009b\u0004\u0015\u0000\u0000\u009b\u009c\u0005+\u0000"+
		"\u0000\u009c\u009d\u0006\u0015\u0016\u0000\u009d,\u0001\u0000\u0000\u0000"+
		"\u009e\u009f\u0005+\u0000\u0000\u009f\u00a0\u0006\u0016\u0017\u0000\u00a0"+
		".\u0001\u0000\u0000\u0000\u00a1\u00a2\u0004\u0017\u0001\u0000\u00a2\u00a3"+
		"\u0005-\u0000\u0000\u00a3\u00a4\u0006\u0017\u0018\u0000\u00a40\u0001\u0000"+
		"\u0000\u0000\u00a5\u00a6\u0005-\u0000\u0000\u00a6\u00a7\u0006\u0018\u0019"+
		"\u0000\u00a72\u0001\u0000\u0000\u0000\u00a8\u00a9\u0004\u0019\u0002\u0000"+
		"\u00a9\u00aa\u0005(\u0000\u0000\u00aa\u00ab\u0006\u0019\u001a\u0000\u00ab"+
		"4\u0001\u0000\u0000\u0000\u00ac\u00ad\u0004\u001a\u0003\u0000\u00ad\u00ae"+
		"\u0005(\u0000\u0000\u00ae\u00af\u0006\u001a\u001b\u0000\u00af6\u0001\u0000"+
		"\u0000\u0000\u0003\u0000:h\u001c\u0001\u0000\u0000\u0001\u0001\u0001\u0001"+
		"\u0002\u0002\u0001\u0003\u0003\u0001\u0004\u0004\u0001\u0005\u0005\u0001"+
		"\u0006\u0006\u0001\u0007\u0007\u0001\b\b\u0001\t\t\u0001\n\n\u0001\u000b"+
		"\u000b\u0001\f\f\u0001\r\r\u0001\u000e\u000e\u0001\u000f\u000f\u0001\u0010"+
		"\u0010\u0000\u0001\u0000\u0001\u0011\u0011\u0001\u0012\u0012\u0001\u0013"+
		"\u0013\u0001\u0014\u0014\u0001\u0015\u0015\u0001\u0016\u0016\u0001\u0017"+
		"\u0017\u0001\u0018\u0018\u0001\u0019\u0019\u0001\u001a\u001a";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}