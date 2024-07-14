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
		UINT=1, UFLOAT=2, UPITCH=3, BACHNULL=4, BACHNIL=5, IF=6, THEN=7, ELSE=8, 
		WHILE=9, FOR=10, DO=11, COLLECT=12, FUNCTION=13, INLET=14, GLOBALVAR=15, 
		PATCHERVAR=16, LOCALVAR=17, NAMEDPARAM=18, PUSH=19, POP=20, CLOSED=21, 
		NTH=22, PICK=23, KEY=24, ANTH=25, APICK=26, NULLIFY=27, ASSIGN=28, WHITESPACE=29, 
		NEWATOM=30, POW=31, APOW=32, TIMES=33, ATIMES=34, DIVDIV=35, ADIVDIV=36, 
		DIV=37, ADIV=38, REM=39, AREM=40, PLUS=41, APLUS=42, UPLUS=43, MINUS=44, 
		AMINUS=45, UMINUS=46, EQUAL=47, NEQ=48, LOGNOT=49, BITNOT=50, LT=51, GT=52, 
		LEQ=53, GEQ=54, BITAND=55, ABITAND=56, BITXOR=57, ABITXOR=58, BITOR=59, 
		ABITOR=60, LOGAND=61, LOGANDEXT=62, ALOGAND=63, ALOGANDEXT=64, LOGXOR=65, 
		ALOGXOR=66, LOGOR=67, ALOGOR=68, LOGOREXT=69, ALOGOREXT=70, LSHIFT=71, 
		ALSHIFT=72, RSHIFT=73, ARSHIFT=74, RANGE=75, REPEAT=76, AREPEAT=77, AAPPLY=78, 
		ACONCAT=79, ARCONCAT=80, OPEN=81, PARAMS=82, ANYTHING=83;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"UINT", "UFLOAT", "UPITCH", "NOTENAME", "ACCIDENTAL", "RAT", "BACHNULL", 
			"BACHNIL", "IF", "THEN", "ELSE", "WHILE", "FOR", "DO", "COLLECT", "FUNCTION", 
			"INLET", "GLOBALVAR", "PATCHERVAR", "LOCALVAR", "NAMEDPARAM", "ID", "PUSH", 
			"POP", "CLOSED", "NTH", "PICK", "KEY", "ANTH", "APICK", "NULLIFY", "ASSIGN", 
			"WHITESPACE", "NEWATOM", "POW", "APOW", "TIMES", "ATIMES", "DIVDIV", 
			"ADIVDIV", "DIV", "ADIV", "REM", "AREM", "PLUS", "APLUS", "UPLUS", "MINUS", 
			"AMINUS", "UMINUS", "EQUAL", "NEQ", "LOGNOT", "BITNOT", "LT", "GT", "LEQ", 
			"GEQ", "BITAND", "ABITAND", "BITXOR", "ABITXOR", "BITOR", "ABITOR", "LOGAND", 
			"LOGANDEXT", "ALOGAND", "ALOGANDEXT", "LOGXOR", "ALOGXOR", "LOGOR", "ALOGOR", 
			"LOGOREXT", "ALOGOREXT", "LSHIFT", "ALSHIFT", "RSHIFT", "ARSHIFT", "RANGE", 
			"REPEAT", "AREPEAT", "AAPPLY", "ACONCAT", "ARCONCAT", "OPEN", "PARAMS", 
			"ANYTHING"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, "'null'", "'nil'", "'if'", "'then'", "'else'", 
			"'while'", "'for'", "'do'", "'collect'", null, null, null, null, null, 
			null, "'['", "']'", "')'", "':'", "'::'", "'.'", "':='", "'::='", "';'", 
			"'='", null, null, "'**'", "'**='", "'*'", "'*='", "'//'", "'//='", "'/'", 
			"'/='", null, null, null, "'+='", "'+'", null, "'-='", "'-'", "'=='", 
			"'!='", "'!'", "'~'", "'<'", "'>'", "'<='", "'>='", "'&'", "'&='", "'^'", 
			"'^='", "'|'", "'|='", "'&&'", "'&&&'", "'&&='", "'&&&='", "'^^'", "'^^='", 
			"'||'", "'||='", "'|||'", "'|||='", "'<<'", "'<<='", "'>>'", "'>>='", 
			"'...'", "':*'", "':*='", "'.='", "'_='", "'!_='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "UINT", "UFLOAT", "UPITCH", "BACHNULL", "BACHNIL", "IF", "THEN", 
			"ELSE", "WHILE", "FOR", "DO", "COLLECT", "FUNCTION", "INLET", "GLOBALVAR", 
			"PATCHERVAR", "LOCALVAR", "NAMEDPARAM", "PUSH", "POP", "CLOSED", "NTH", 
			"PICK", "KEY", "ANTH", "APICK", "NULLIFY", "ASSIGN", "WHITESPACE", "NEWATOM", 
			"POW", "APOW", "TIMES", "ATIMES", "DIVDIV", "ADIVDIV", "DIV", "ADIV", 
			"REM", "AREM", "PLUS", "APLUS", "UPLUS", "MINUS", "AMINUS", "UMINUS", 
			"EQUAL", "NEQ", "LOGNOT", "BITNOT", "LT", "GT", "LEQ", "GEQ", "BITAND", 
			"ABITAND", "BITXOR", "ABITXOR", "BITOR", "ABITOR", "LOGAND", "LOGANDEXT", 
			"ALOGAND", "ALOGANDEXT", "LOGXOR", "ALOGXOR", "LOGOR", "ALOGOR", "LOGOREXT", 
			"ALOGOREXT", "LSHIFT", "ALSHIFT", "RSHIFT", "ARSHIFT", "RANGE", "REPEAT", 
			"AREPEAT", "AAPPLY", "ACONCAT", "ARCONCAT", "OPEN", "PARAMS", "ANYTHING"
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
	    long *codeac = 0;

	    bool followedBySpace() {
	        int c = _input->LA(2);
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
	        return noUnary || followedBySpace();
	    }

	    void setCodeac(long* c) { codeac = c; }

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
			UINT_action((RuleContext)_localctx, actionIndex);
			break;
		case 1:
			UFLOAT_action((RuleContext)_localctx, actionIndex);
			break;
		case 2:
			UPITCH_action((RuleContext)_localctx, actionIndex);
			break;
		case 6:
			BACHNULL_action((RuleContext)_localctx, actionIndex);
			break;
		case 7:
			BACHNIL_action((RuleContext)_localctx, actionIndex);
			break;
		case 8:
			IF_action((RuleContext)_localctx, actionIndex);
			break;
		case 9:
			THEN_action((RuleContext)_localctx, actionIndex);
			break;
		case 10:
			ELSE_action((RuleContext)_localctx, actionIndex);
			break;
		case 11:
			WHILE_action((RuleContext)_localctx, actionIndex);
			break;
		case 12:
			FOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 13:
			DO_action((RuleContext)_localctx, actionIndex);
			break;
		case 14:
			COLLECT_action((RuleContext)_localctx, actionIndex);
			break;
		case 15:
			FUNCTION_action((RuleContext)_localctx, actionIndex);
			break;
		case 16:
			INLET_action((RuleContext)_localctx, actionIndex);
			break;
		case 17:
			GLOBALVAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 18:
			PATCHERVAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 19:
			LOCALVAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 20:
			NAMEDPARAM_action((RuleContext)_localctx, actionIndex);
			break;
		case 22:
			PUSH_action((RuleContext)_localctx, actionIndex);
			break;
		case 23:
			POP_action((RuleContext)_localctx, actionIndex);
			break;
		case 24:
			CLOSED_action((RuleContext)_localctx, actionIndex);
			break;
		case 25:
			NTH_action((RuleContext)_localctx, actionIndex);
			break;
		case 26:
			PICK_action((RuleContext)_localctx, actionIndex);
			break;
		case 27:
			KEY_action((RuleContext)_localctx, actionIndex);
			break;
		case 28:
			ANTH_action((RuleContext)_localctx, actionIndex);
			break;
		case 29:
			APICK_action((RuleContext)_localctx, actionIndex);
			break;
		case 30:
			NULLIFY_action((RuleContext)_localctx, actionIndex);
			break;
		case 31:
			ASSIGN_action((RuleContext)_localctx, actionIndex);
			break;
		case 32:
			WHITESPACE_action((RuleContext)_localctx, actionIndex);
			break;
		case 33:
			NEWATOM_action((RuleContext)_localctx, actionIndex);
			break;
		case 34:
			POW_action((RuleContext)_localctx, actionIndex);
			break;
		case 35:
			APOW_action((RuleContext)_localctx, actionIndex);
			break;
		case 36:
			TIMES_action((RuleContext)_localctx, actionIndex);
			break;
		case 37:
			ATIMES_action((RuleContext)_localctx, actionIndex);
			break;
		case 38:
			DIVDIV_action((RuleContext)_localctx, actionIndex);
			break;
		case 39:
			ADIVDIV_action((RuleContext)_localctx, actionIndex);
			break;
		case 40:
			DIV_action((RuleContext)_localctx, actionIndex);
			break;
		case 41:
			ADIV_action((RuleContext)_localctx, actionIndex);
			break;
		case 42:
			REM_action((RuleContext)_localctx, actionIndex);
			break;
		case 43:
			AREM_action((RuleContext)_localctx, actionIndex);
			break;
		case 44:
			PLUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 45:
			APLUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 46:
			UPLUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 47:
			MINUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 48:
			AMINUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 49:
			UMINUS_action((RuleContext)_localctx, actionIndex);
			break;
		case 50:
			EQUAL_action((RuleContext)_localctx, actionIndex);
			break;
		case 51:
			NEQ_action((RuleContext)_localctx, actionIndex);
			break;
		case 52:
			LOGNOT_action((RuleContext)_localctx, actionIndex);
			break;
		case 53:
			BITNOT_action((RuleContext)_localctx, actionIndex);
			break;
		case 54:
			LT_action((RuleContext)_localctx, actionIndex);
			break;
		case 55:
			GT_action((RuleContext)_localctx, actionIndex);
			break;
		case 56:
			LEQ_action((RuleContext)_localctx, actionIndex);
			break;
		case 57:
			GEQ_action((RuleContext)_localctx, actionIndex);
			break;
		case 58:
			BITAND_action((RuleContext)_localctx, actionIndex);
			break;
		case 59:
			ABITAND_action((RuleContext)_localctx, actionIndex);
			break;
		case 60:
			BITXOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 61:
			ABITXOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 62:
			BITOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 63:
			ABITOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 64:
			LOGAND_action((RuleContext)_localctx, actionIndex);
			break;
		case 65:
			LOGANDEXT_action((RuleContext)_localctx, actionIndex);
			break;
		case 66:
			ALOGAND_action((RuleContext)_localctx, actionIndex);
			break;
		case 67:
			ALOGANDEXT_action((RuleContext)_localctx, actionIndex);
			break;
		case 68:
			LOGXOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 69:
			ALOGXOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 70:
			LOGOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 71:
			ALOGOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 72:
			LOGOREXT_action((RuleContext)_localctx, actionIndex);
			break;
		case 73:
			ALOGOREXT_action((RuleContext)_localctx, actionIndex);
			break;
		case 74:
			LSHIFT_action((RuleContext)_localctx, actionIndex);
			break;
		case 75:
			ALSHIFT_action((RuleContext)_localctx, actionIndex);
			break;
		case 76:
			RSHIFT_action((RuleContext)_localctx, actionIndex);
			break;
		case 77:
			ARSHIFT_action((RuleContext)_localctx, actionIndex);
			break;
		case 78:
			RANGE_action((RuleContext)_localctx, actionIndex);
			break;
		case 79:
			REPEAT_action((RuleContext)_localctx, actionIndex);
			break;
		case 80:
			AREPEAT_action((RuleContext)_localctx, actionIndex);
			break;
		case 81:
			AAPPLY_action((RuleContext)_localctx, actionIndex);
			break;
		case 82:
			ACONCAT_action((RuleContext)_localctx, actionIndex);
			break;
		case 83:
			ARCONCAT_action((RuleContext)_localctx, actionIndex);
			break;
		case 84:
			OPEN_action((RuleContext)_localctx, actionIndex);
			break;
		case 85:
			PARAMS_action((RuleContext)_localctx, actionIndex);
			break;
		}
	}
	private void UINT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 0:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void UFLOAT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 1:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void UPITCH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 2:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void BACHNULL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 3:
			 noParams = false; noUnary = false; 
			break;
		}
	}
	private void BACHNIL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 4:
			 noParams = false; noUnary = false; 
			break;
		}
	}
	private void IF_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 5:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void THEN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 6:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ELSE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 7:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void WHILE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 8:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void FOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 9:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DO_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 10:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void COLLECT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 11:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void FUNCTION_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 12:
			 noParams = noUnary = false; 
			break;
		}
	}
	private void INLET_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 13:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void GLOBALVAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 14:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void PATCHERVAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 15:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void LOCALVAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 16:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void NAMEDPARAM_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 17:
			 noParams = true; noUnary = true; 
			break;
		}
	}
	private void PUSH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 18:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void POP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 19:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void CLOSED_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 20:
			 noParams = false; noUnary = true; 
			break;
		}
	}
	private void NTH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 21:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PICK_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 22:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void KEY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 23:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ANTH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 24:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void APICK_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 25:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void NULLIFY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 26:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ASSIGN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 27:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void WHITESPACE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 28:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void NEWATOM_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 29:
			 noParams = true; noUnary = false; (*codeac)++; 
			break;
		}
	}
	private void POW_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 30:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void APOW_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 31:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void TIMES_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 32:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ATIMES_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 33:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DIVDIV_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 34:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ADIVDIV_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 35:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void DIV_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 36:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ADIV_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 37:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void REM_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 38:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void AREM_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 39:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PLUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 40:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void APLUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 41:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void UPLUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 42:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void MINUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 43:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void AMINUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 44:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void UMINUS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 45:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void EQUAL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 46:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void NEQ_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 47:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LOGNOT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 48:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void BITNOT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 49:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 50:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void GT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 51:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LEQ_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 52:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void GEQ_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 53:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void BITAND_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 54:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ABITAND_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 55:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void BITXOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 56:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ABITXOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 57:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void BITOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 58:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ABITOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 59:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LOGAND_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 60:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LOGANDEXT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 61:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ALOGAND_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 62:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ALOGANDEXT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 63:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LOGXOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 64:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ALOGXOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 65:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LOGOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 66:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ALOGOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 67:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LOGOREXT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 68:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ALOGOREXT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 69:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void LSHIFT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 70:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ALSHIFT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 71:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void RSHIFT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 72:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ARSHIFT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 73:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void RANGE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 74:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void REPEAT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 75:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void AREPEAT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 76:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void AAPPLY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 77:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ACONCAT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 78:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void ARCONCAT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 79:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void OPEN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 80:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	private void PARAMS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 81:
			 noParams = true; noUnary = false; 
			break;
		}
	}
	@Override
	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 44:
			return PLUS_sempred((RuleContext)_localctx, predIndex);
		case 47:
			return MINUS_sempred((RuleContext)_localctx, predIndex);
		case 84:
			return OPEN_sempred((RuleContext)_localctx, predIndex);
		case 85:
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
		"\u0004\u0000S\u02ab\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002"+
		"\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002"+
		"\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002"+
		"\u0015\u0007\u0015\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002"+
		"\u0018\u0007\u0018\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002"+
		"\u001b\u0007\u001b\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d\u0002"+
		"\u001e\u0007\u001e\u0002\u001f\u0007\u001f\u0002 \u0007 \u0002!\u0007"+
		"!\u0002\"\u0007\"\u0002#\u0007#\u0002$\u0007$\u0002%\u0007%\u0002&\u0007"+
		"&\u0002\'\u0007\'\u0002(\u0007(\u0002)\u0007)\u0002*\u0007*\u0002+\u0007"+
		"+\u0002,\u0007,\u0002-\u0007-\u0002.\u0007.\u0002/\u0007/\u00020\u0007"+
		"0\u00021\u00071\u00022\u00072\u00023\u00073\u00024\u00074\u00025\u0007"+
		"5\u00026\u00076\u00027\u00077\u00028\u00078\u00029\u00079\u0002:\u0007"+
		":\u0002;\u0007;\u0002<\u0007<\u0002=\u0007=\u0002>\u0007>\u0002?\u0007"+
		"?\u0002@\u0007@\u0002A\u0007A\u0002B\u0007B\u0002C\u0007C\u0002D\u0007"+
		"D\u0002E\u0007E\u0002F\u0007F\u0002G\u0007G\u0002H\u0007H\u0002I\u0007"+
		"I\u0002J\u0007J\u0002K\u0007K\u0002L\u0007L\u0002M\u0007M\u0002N\u0007"+
		"N\u0002O\u0007O\u0002P\u0007P\u0002Q\u0007Q\u0002R\u0007R\u0002S\u0007"+
		"S\u0002T\u0007T\u0002U\u0007U\u0002V\u0007V\u0001\u0000\u0004\u0000\u00b1"+
		"\b\u0000\u000b\u0000\f\u0000\u00b2\u0001\u0000\u0001\u0000\u0001\u0001"+
		"\u0005\u0001\u00b8\b\u0001\n\u0001\f\u0001\u00bb\t\u0001\u0001\u0001\u0001"+
		"\u0001\u0004\u0001\u00bf\b\u0001\u000b\u0001\f\u0001\u00c0\u0001\u0001"+
		"\u0004\u0001\u00c4\b\u0001\u000b\u0001\f\u0001\u00c5\u0001\u0001\u0003"+
		"\u0001\u00c9\b\u0001\u0001\u0001\u0001\u0001\u0003\u0001\u00cd\b\u0001"+
		"\u0001\u0001\u0004\u0001\u00d0\b\u0001\u000b\u0001\f\u0001\u00d1\u0003"+
		"\u0001\u00d4\b\u0001\u0001\u0001\u0004\u0001\u00d7\b\u0001\u000b\u0001"+
		"\f\u0001\u00d8\u0001\u0001\u0001\u0001\u0003\u0001\u00dd\b\u0001\u0001"+
		"\u0001\u0004\u0001\u00e0\b\u0001\u000b\u0001\f\u0001\u00e1\u0003\u0001"+
		"\u00e4\b\u0001\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0003\u0002"+
		"\u00ea\b\u0002\u0001\u0002\u0005\u0002\u00ed\b\u0002\n\u0002\f\u0002\u00f0"+
		"\t\u0002\u0001\u0002\u0001\u0002\u0005\u0002\u00f4\b\u0002\n\u0002\f\u0002"+
		"\u00f7\t\u0002\u0001\u0002\u0001\u0002\u0003\u0002\u00fb\b\u0002\u0001"+
		"\u0002\u0001\u0002\u0003\u0002\u00ff\b\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0003\u0003\u0003\u0104\b\u0003\u0001\u0004\u0004\u0004\u0107\b\u0004"+
		"\u000b\u0004\f\u0004\u0108\u0001\u0005\u0001\u0005\u0001\u0005\u0005\u0005"+
		"\u010e\b\u0005\n\u0005\f\u0005\u0111\t\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\t\u0001\t\u0001\t"+
		"\u0001\t\u0001\t\u0001\t\u0001\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0003\u000f\u015e\b\u000f\u0001\u0010"+
		"\u0001\u0010\u0001\u0010\u0004\u0010\u0163\b\u0010\u000b\u0010\f\u0010"+
		"\u0164\u0001\u0010\u0001\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0015\u0001\u0015\u0005\u0015\u017a\b\u0015\n\u0015\f\u0015\u017d\t\u0015"+
		"\u0001\u0015\u0003\u0015\u0180\b\u0015\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u001a\u0001\u001a\u0001\u001a"+
		"\u0001\u001a\u0001\u001a\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001c"+
		"\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001d\u0001\u001d"+
		"\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001e\u0001\u001e"+
		"\u0001\u001e\u0001\u001f\u0001\u001f\u0001\u001f\u0001 \u0001 \u0001 "+
		"\u0001 \u0001 \u0001!\u0001!\u0001!\u0001!\u0001!\u0001\"\u0001\"\u0001"+
		"\"\u0001\"\u0001\"\u0001#\u0001#\u0001#\u0001#\u0001#\u0001#\u0001$\u0001"+
		"$\u0001$\u0001%\u0001%\u0001%\u0001%\u0001%\u0001&\u0001&\u0001&\u0001"+
		"&\u0001&\u0001\'\u0001\'\u0001\'\u0001\'\u0001\'\u0001\'\u0001(\u0001"+
		"(\u0001(\u0001)\u0001)\u0001)\u0001)\u0001)\u0001*\u0001*\u0001*\u0001"+
		"+\u0001+\u0001+\u0001,\u0001,\u0001,\u0001,\u0001-\u0001-\u0001-\u0001"+
		"-\u0001-\u0001.\u0001.\u0001.\u0001/\u0001/\u0001/\u0001/\u00010\u0001"+
		"0\u00010\u00010\u00010\u00011\u00011\u00011\u00012\u00012\u00012\u0001"+
		"2\u00012\u00013\u00013\u00013\u00013\u00013\u00014\u00014\u00014\u0001"+
		"5\u00015\u00015\u00016\u00016\u00016\u00017\u00017\u00017\u00018\u0001"+
		"8\u00018\u00018\u00018\u00019\u00019\u00019\u00019\u00019\u0001:\u0001"+
		":\u0001:\u0001;\u0001;\u0001;\u0001;\u0001;\u0001<\u0001<\u0001<\u0001"+
		"=\u0001=\u0001=\u0001=\u0001=\u0001>\u0001>\u0001>\u0001?\u0001?\u0001"+
		"?\u0001?\u0001?\u0001@\u0001@\u0001@\u0001@\u0001@\u0001A\u0001A\u0001"+
		"A\u0001A\u0001A\u0001A\u0001B\u0001B\u0001B\u0001B\u0001B\u0001B\u0001"+
		"C\u0001C\u0001C\u0001C\u0001C\u0001C\u0001C\u0001D\u0001D\u0001D\u0001"+
		"D\u0001D\u0001E\u0001E\u0001E\u0001E\u0001E\u0001E\u0001F\u0001F\u0001"+
		"F\u0001F\u0001F\u0001G\u0001G\u0001G\u0001G\u0001G\u0001G\u0001H\u0001"+
		"H\u0001H\u0001H\u0001H\u0001H\u0001I\u0001I\u0001I\u0001I\u0001I\u0001"+
		"I\u0001I\u0001J\u0001J\u0001J\u0001J\u0001J\u0001K\u0001K\u0001K\u0001"+
		"K\u0001K\u0001K\u0001L\u0001L\u0001L\u0001L\u0001L\u0001M\u0001M\u0001"+
		"M\u0001M\u0001M\u0001M\u0001N\u0001N\u0001N\u0001N\u0001N\u0001N\u0001"+
		"O\u0001O\u0001O\u0001O\u0001O\u0001P\u0001P\u0001P\u0001P\u0001P\u0001"+
		"P\u0001Q\u0001Q\u0001Q\u0001Q\u0001Q\u0001R\u0001R\u0001R\u0001R\u0001"+
		"R\u0001S\u0001S\u0001S\u0001S\u0001S\u0001S\u0001T\u0001T\u0001T\u0001"+
		"T\u0001U\u0001U\u0001U\u0001U\u0001V\u0004V\u02a8\bV\u000bV\fV\u02a9\u0001"+
		"\u02a9\u0000W\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0000\t\u0000"+
		"\u000b\u0000\r\u0004\u000f\u0005\u0011\u0006\u0013\u0007\u0015\b\u0017"+
		"\t\u0019\n\u001b\u000b\u001d\f\u001f\r!\u000e#\u000f%\u0010\'\u0011)\u0012"+
		"+\u0000-\u0013/\u00141\u00153\u00165\u00177\u00189\u0019;\u001a=\u001b"+
		"?\u001cA\u001dC\u001eE\u001fG I!K\"M#O$Q%S&U\'W(Y)[*]+_,a-c.e/g0i1k2m"+
		"3o4q5s6u7w8y9{:};\u007f<\u0081=\u0083>\u0085?\u0087@\u0089A\u008bB\u008d"+
		"C\u008fD\u0091E\u0093F\u0095G\u0097H\u0099I\u009bJ\u009dK\u009fL\u00a1"+
		"M\u00a3N\u00a5O\u00a7P\u00a9Q\u00abR\u00adS\u0001\u0000\u000b\u0001\u0000"+
		"09\u0002\u0000EEee\u0002\u0000++--\u0002\u0000AGag\u0007\u0000##^^bbd"+
		"dqqvvxx\u0002\u0000llxx\u0002\u0000AZaz\u0004\u000009AZ__az\u0003\u0000"+
		"09AZaz\u0003\u0000\t\n\r\r  \u0001\u0000\u0001\u0001\u02bf\u0000\u0001"+
		"\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000\u0000\u0005"+
		"\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001"+
		"\u0000\u0000\u0000\u0000\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001"+
		"\u0000\u0000\u0000\u0000\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001"+
		"\u0000\u0000\u0000\u0000\u0019\u0001\u0000\u0000\u0000\u0000\u001b\u0001"+
		"\u0000\u0000\u0000\u0000\u001d\u0001\u0000\u0000\u0000\u0000\u001f\u0001"+
		"\u0000\u0000\u0000\u0000!\u0001\u0000\u0000\u0000\u0000#\u0001\u0000\u0000"+
		"\u0000\u0000%\u0001\u0000\u0000\u0000\u0000\'\u0001\u0000\u0000\u0000"+
		"\u0000)\u0001\u0000\u0000\u0000\u0000-\u0001\u0000\u0000\u0000\u0000/"+
		"\u0001\u0000\u0000\u0000\u00001\u0001\u0000\u0000\u0000\u00003\u0001\u0000"+
		"\u0000\u0000\u00005\u0001\u0000\u0000\u0000\u00007\u0001\u0000\u0000\u0000"+
		"\u00009\u0001\u0000\u0000\u0000\u0000;\u0001\u0000\u0000\u0000\u0000="+
		"\u0001\u0000\u0000\u0000\u0000?\u0001\u0000\u0000\u0000\u0000A\u0001\u0000"+
		"\u0000\u0000\u0000C\u0001\u0000\u0000\u0000\u0000E\u0001\u0000\u0000\u0000"+
		"\u0000G\u0001\u0000\u0000\u0000\u0000I\u0001\u0000\u0000\u0000\u0000K"+
		"\u0001\u0000\u0000\u0000\u0000M\u0001\u0000\u0000\u0000\u0000O\u0001\u0000"+
		"\u0000\u0000\u0000Q\u0001\u0000\u0000\u0000\u0000S\u0001\u0000\u0000\u0000"+
		"\u0000U\u0001\u0000\u0000\u0000\u0000W\u0001\u0000\u0000\u0000\u0000Y"+
		"\u0001\u0000\u0000\u0000\u0000[\u0001\u0000\u0000\u0000\u0000]\u0001\u0000"+
		"\u0000\u0000\u0000_\u0001\u0000\u0000\u0000\u0000a\u0001\u0000\u0000\u0000"+
		"\u0000c\u0001\u0000\u0000\u0000\u0000e\u0001\u0000\u0000\u0000\u0000g"+
		"\u0001\u0000\u0000\u0000\u0000i\u0001\u0000\u0000\u0000\u0000k\u0001\u0000"+
		"\u0000\u0000\u0000m\u0001\u0000\u0000\u0000\u0000o\u0001\u0000\u0000\u0000"+
		"\u0000q\u0001\u0000\u0000\u0000\u0000s\u0001\u0000\u0000\u0000\u0000u"+
		"\u0001\u0000\u0000\u0000\u0000w\u0001\u0000\u0000\u0000\u0000y\u0001\u0000"+
		"\u0000\u0000\u0000{\u0001\u0000\u0000\u0000\u0000}\u0001\u0000\u0000\u0000"+
		"\u0000\u007f\u0001\u0000\u0000\u0000\u0000\u0081\u0001\u0000\u0000\u0000"+
		"\u0000\u0083\u0001\u0000\u0000\u0000\u0000\u0085\u0001\u0000\u0000\u0000"+
		"\u0000\u0087\u0001\u0000\u0000\u0000\u0000\u0089\u0001\u0000\u0000\u0000"+
		"\u0000\u008b\u0001\u0000\u0000\u0000\u0000\u008d\u0001\u0000\u0000\u0000"+
		"\u0000\u008f\u0001\u0000\u0000\u0000\u0000\u0091\u0001\u0000\u0000\u0000"+
		"\u0000\u0093\u0001\u0000\u0000\u0000\u0000\u0095\u0001\u0000\u0000\u0000"+
		"\u0000\u0097\u0001\u0000\u0000\u0000\u0000\u0099\u0001\u0000\u0000\u0000"+
		"\u0000\u009b\u0001\u0000\u0000\u0000\u0000\u009d\u0001\u0000\u0000\u0000"+
		"\u0000\u009f\u0001\u0000\u0000\u0000\u0000\u00a1\u0001\u0000\u0000\u0000"+
		"\u0000\u00a3\u0001\u0000\u0000\u0000\u0000\u00a5\u0001\u0000\u0000\u0000"+
		"\u0000\u00a7\u0001\u0000\u0000\u0000\u0000\u00a9\u0001\u0000\u0000\u0000"+
		"\u0000\u00ab\u0001\u0000\u0000\u0000\u0000\u00ad\u0001\u0000\u0000\u0000"+
		"\u0001\u00b0\u0001\u0000\u0000\u0000\u0003\u00e3\u0001\u0000\u0000\u0000"+
		"\u0005\u00e7\u0001\u0000\u0000\u0000\u0007\u0103\u0001\u0000\u0000\u0000"+
		"\t\u0106\u0001\u0000\u0000\u0000\u000b\u010a\u0001\u0000\u0000\u0000\r"+
		"\u0114\u0001\u0000\u0000\u0000\u000f\u011b\u0001\u0000\u0000\u0000\u0011"+
		"\u0121\u0001\u0000\u0000\u0000\u0013\u0126\u0001\u0000\u0000\u0000\u0015"+
		"\u012d\u0001\u0000\u0000\u0000\u0017\u0134\u0001\u0000\u0000\u0000\u0019"+
		"\u013c\u0001\u0000\u0000\u0000\u001b\u0142\u0001\u0000\u0000\u0000\u001d"+
		"\u0147\u0001\u0000\u0000\u0000\u001f\u015d\u0001\u0000\u0000\u0000!\u015f"+
		"\u0001\u0000\u0000\u0000#\u0168\u0001\u0000\u0000\u0000%\u016b\u0001\u0000"+
		"\u0000\u0000\'\u016f\u0001\u0000\u0000\u0000)\u0173\u0001\u0000\u0000"+
		"\u0000+\u0177\u0001\u0000\u0000\u0000-\u0181\u0001\u0000\u0000\u0000/"+
		"\u0184\u0001\u0000\u0000\u00001\u0187\u0001\u0000\u0000\u00003\u018a\u0001"+
		"\u0000\u0000\u00005\u018d\u0001\u0000\u0000\u00007\u0192\u0001\u0000\u0000"+
		"\u00009\u0195\u0001\u0000\u0000\u0000;\u019a\u0001\u0000\u0000\u0000="+
		"\u01a0\u0001\u0000\u0000\u0000?\u01a3\u0001\u0000\u0000\u0000A\u01a6\u0001"+
		"\u0000\u0000\u0000C\u01ab\u0001\u0000\u0000\u0000E\u01b0\u0001\u0000\u0000"+
		"\u0000G\u01b5\u0001\u0000\u0000\u0000I\u01bb\u0001\u0000\u0000\u0000K"+
		"\u01be\u0001\u0000\u0000\u0000M\u01c3\u0001\u0000\u0000\u0000O\u01c8\u0001"+
		"\u0000\u0000\u0000Q\u01ce\u0001\u0000\u0000\u0000S\u01d1\u0001\u0000\u0000"+
		"\u0000U\u01d6\u0001\u0000\u0000\u0000W\u01d9\u0001\u0000\u0000\u0000Y"+
		"\u01dc\u0001\u0000\u0000\u0000[\u01e0\u0001\u0000\u0000\u0000]\u01e5\u0001"+
		"\u0000\u0000\u0000_\u01e8\u0001\u0000\u0000\u0000a\u01ec\u0001\u0000\u0000"+
		"\u0000c\u01f1\u0001\u0000\u0000\u0000e\u01f4\u0001\u0000\u0000\u0000g"+
		"\u01f9\u0001\u0000\u0000\u0000i\u01fe\u0001\u0000\u0000\u0000k\u0201\u0001"+
		"\u0000\u0000\u0000m\u0204\u0001\u0000\u0000\u0000o\u0207\u0001\u0000\u0000"+
		"\u0000q\u020a\u0001\u0000\u0000\u0000s\u020f\u0001\u0000\u0000\u0000u"+
		"\u0214\u0001\u0000\u0000\u0000w\u0217\u0001\u0000\u0000\u0000y\u021c\u0001"+
		"\u0000\u0000\u0000{\u021f\u0001\u0000\u0000\u0000}\u0224\u0001\u0000\u0000"+
		"\u0000\u007f\u0227\u0001\u0000\u0000\u0000\u0081\u022c\u0001\u0000\u0000"+
		"\u0000\u0083\u0231\u0001\u0000\u0000\u0000\u0085\u0237\u0001\u0000\u0000"+
		"\u0000\u0087\u023d\u0001\u0000\u0000\u0000\u0089\u0244\u0001\u0000\u0000"+
		"\u0000\u008b\u0249\u0001\u0000\u0000\u0000\u008d\u024f\u0001\u0000\u0000"+
		"\u0000\u008f\u0254\u0001\u0000\u0000\u0000\u0091\u025a\u0001\u0000\u0000"+
		"\u0000\u0093\u0260\u0001\u0000\u0000\u0000\u0095\u0267\u0001\u0000\u0000"+
		"\u0000\u0097\u026c\u0001\u0000\u0000\u0000\u0099\u0272\u0001\u0000\u0000"+
		"\u0000\u009b\u0277\u0001\u0000\u0000\u0000\u009d\u027d\u0001\u0000\u0000"+
		"\u0000\u009f\u0283\u0001\u0000\u0000\u0000\u00a1\u0288\u0001\u0000\u0000"+
		"\u0000\u00a3\u028e\u0001\u0000\u0000\u0000\u00a5\u0293\u0001\u0000\u0000"+
		"\u0000\u00a7\u0298\u0001\u0000\u0000\u0000\u00a9\u029e\u0001\u0000\u0000"+
		"\u0000\u00ab\u02a2\u0001\u0000\u0000\u0000\u00ad\u02a7\u0001\u0000\u0000"+
		"\u0000\u00af\u00b1\u0007\u0000\u0000\u0000\u00b0\u00af\u0001\u0000\u0000"+
		"\u0000\u00b1\u00b2\u0001\u0000\u0000\u0000\u00b2\u00b0\u0001\u0000\u0000"+
		"\u0000\u00b2\u00b3\u0001\u0000\u0000\u0000\u00b3\u00b4\u0001\u0000\u0000"+
		"\u0000\u00b4\u00b5\u0006\u0000\u0000\u0000\u00b5\u0002\u0001\u0000\u0000"+
		"\u0000\u00b6\u00b8\u0007\u0000\u0000\u0000\u00b7\u00b6\u0001\u0000\u0000"+
		"\u0000\u00b8\u00bb\u0001\u0000\u0000\u0000\u00b9\u00b7\u0001\u0000\u0000"+
		"\u0000\u00b9\u00ba\u0001\u0000\u0000\u0000\u00ba\u00bc\u0001\u0000\u0000"+
		"\u0000\u00bb\u00b9\u0001\u0000\u0000\u0000\u00bc\u00be\u0005.\u0000\u0000"+
		"\u00bd\u00bf\u0007\u0000\u0000\u0000\u00be\u00bd\u0001\u0000\u0000\u0000"+
		"\u00bf\u00c0\u0001\u0000\u0000\u0000\u00c0\u00be\u0001\u0000\u0000\u0000"+
		"\u00c0\u00c1\u0001\u0000\u0000\u0000\u00c1\u00c9\u0001\u0000\u0000\u0000"+
		"\u00c2\u00c4\u0007\u0000\u0000\u0000\u00c3\u00c2\u0001\u0000\u0000\u0000"+
		"\u00c4\u00c5\u0001\u0000\u0000\u0000\u00c5\u00c3\u0001\u0000\u0000\u0000"+
		"\u00c5\u00c6\u0001\u0000\u0000\u0000\u00c6\u00c7\u0001\u0000\u0000\u0000"+
		"\u00c7\u00c9\u0005.\u0000\u0000\u00c8\u00b9\u0001\u0000\u0000\u0000\u00c8"+
		"\u00c3\u0001\u0000\u0000\u0000\u00c9\u00d3\u0001\u0000\u0000\u0000\u00ca"+
		"\u00cc\u0007\u0001\u0000\u0000\u00cb\u00cd\u0007\u0002\u0000\u0000\u00cc"+
		"\u00cb\u0001\u0000\u0000\u0000\u00cc\u00cd\u0001\u0000\u0000\u0000\u00cd"+
		"\u00cf\u0001\u0000\u0000\u0000\u00ce\u00d0\u0007\u0000\u0000\u0000\u00cf"+
		"\u00ce\u0001\u0000\u0000\u0000\u00d0\u00d1\u0001\u0000\u0000\u0000\u00d1"+
		"\u00cf\u0001\u0000\u0000\u0000\u00d1\u00d2\u0001\u0000\u0000\u0000\u00d2"+
		"\u00d4\u0001\u0000\u0000\u0000\u00d3\u00ca\u0001\u0000\u0000\u0000\u00d3"+
		"\u00d4\u0001\u0000\u0000\u0000\u00d4\u00e4\u0001\u0000\u0000\u0000\u00d5"+
		"\u00d7\u0007\u0000\u0000\u0000\u00d6\u00d5\u0001\u0000\u0000\u0000\u00d7"+
		"\u00d8\u0001\u0000\u0000\u0000\u00d8\u00d6\u0001\u0000\u0000\u0000\u00d8"+
		"\u00d9\u0001\u0000\u0000\u0000\u00d9\u00da\u0001\u0000\u0000\u0000\u00da"+
		"\u00dc\u0007\u0001\u0000\u0000\u00db\u00dd\u0007\u0002\u0000\u0000\u00dc"+
		"\u00db\u0001\u0000\u0000\u0000\u00dc\u00dd\u0001\u0000\u0000\u0000\u00dd"+
		"\u00df\u0001\u0000\u0000\u0000\u00de\u00e0\u0007\u0000\u0000\u0000\u00df"+
		"\u00de\u0001\u0000\u0000\u0000\u00e0\u00e1\u0001\u0000\u0000\u0000\u00e1"+
		"\u00df\u0001\u0000\u0000\u0000\u00e1\u00e2\u0001\u0000\u0000\u0000\u00e2"+
		"\u00e4\u0001\u0000\u0000\u0000\u00e3\u00c8\u0001\u0000\u0000\u0000\u00e3"+
		"\u00d6\u0001\u0000\u0000\u0000\u00e4\u00e5\u0001\u0000\u0000\u0000\u00e5"+
		"\u00e6\u0006\u0001\u0001\u0000\u00e6\u0004\u0001\u0000\u0000\u0000\u00e7"+
		"\u00e9\u0003\u0007\u0003\u0000\u00e8\u00ea\u0003\t\u0004\u0000\u00e9\u00e8"+
		"\u0001\u0000\u0000\u0000\u00e9\u00ea\u0001\u0000\u0000\u0000\u00ea\u00ee"+
		"\u0001\u0000\u0000\u0000\u00eb\u00ed\u0007\u0002\u0000\u0000\u00ec\u00eb"+
		"\u0001\u0000\u0000\u0000\u00ed\u00f0\u0001\u0000\u0000\u0000\u00ee\u00ec"+
		"\u0001\u0000\u0000\u0000\u00ee\u00ef\u0001\u0000\u0000\u0000\u00ef\u00f1"+
		"\u0001\u0000\u0000\u0000\u00f0\u00ee\u0001\u0000\u0000\u0000\u00f1\u00fe"+
		"\u0003\u0001\u0000\u0000\u00f2\u00f4\u0007\u0002\u0000\u0000\u00f3\u00f2"+
		"\u0001\u0000\u0000\u0000\u00f4\u00f7\u0001\u0000\u0000\u0000\u00f5\u00f3"+
		"\u0001\u0000\u0000\u0000\u00f5\u00f6\u0001\u0000\u0000\u0000\u00f6\u00fa"+
		"\u0001\u0000\u0000\u0000\u00f7\u00f5\u0001\u0000\u0000\u0000\u00f8\u00fb"+
		"\u0003\u0001\u0000\u0000\u00f9\u00fb\u0003\u000b\u0005\u0000\u00fa\u00f8"+
		"\u0001\u0000\u0000\u0000\u00fa\u00f9\u0001\u0000\u0000\u0000\u00fb\u00fc"+
		"\u0001\u0000\u0000\u0000\u00fc\u00fd\u0005t\u0000\u0000\u00fd\u00ff\u0001"+
		"\u0000\u0000\u0000\u00fe\u00f5\u0001\u0000\u0000\u0000\u00fe\u00ff\u0001"+
		"\u0000\u0000\u0000\u00ff\u0100\u0001\u0000\u0000\u0000\u0100\u0101\u0006"+
		"\u0002\u0002\u0000\u0101\u0006\u0001\u0000\u0000\u0000\u0102\u0104\u0007"+
		"\u0003\u0000\u0000\u0103\u0102\u0001\u0000\u0000\u0000\u0104\b\u0001\u0000"+
		"\u0000\u0000\u0105\u0107\u0007\u0004\u0000\u0000\u0106\u0105\u0001\u0000"+
		"\u0000\u0000\u0107\u0108\u0001\u0000\u0000\u0000\u0108\u0106\u0001\u0000"+
		"\u0000\u0000\u0108\u0109\u0001\u0000\u0000\u0000\u0109\n\u0001\u0000\u0000"+
		"\u0000\u010a\u010b\u0003\u0001\u0000\u0000\u010b\u010f\u0005/\u0000\u0000"+
		"\u010c\u010e\u0007\u0002\u0000\u0000\u010d\u010c\u0001\u0000\u0000\u0000"+
		"\u010e\u0111\u0001\u0000\u0000\u0000\u010f\u010d\u0001\u0000\u0000\u0000"+
		"\u010f\u0110\u0001\u0000\u0000\u0000\u0110\u0112\u0001\u0000\u0000\u0000"+
		"\u0111\u010f\u0001\u0000\u0000\u0000\u0112\u0113\u0003\u0001\u0000\u0000"+
		"\u0113\f\u0001\u0000\u0000\u0000\u0114\u0115\u0005n\u0000\u0000\u0115"+
		"\u0116\u0005u\u0000\u0000\u0116\u0117\u0005l\u0000\u0000\u0117\u0118\u0005"+
		"l\u0000\u0000\u0118\u0119\u0001\u0000\u0000\u0000\u0119\u011a\u0006\u0006"+
		"\u0003\u0000\u011a\u000e\u0001\u0000\u0000\u0000\u011b\u011c\u0005n\u0000"+
		"\u0000\u011c\u011d\u0005i\u0000\u0000\u011d\u011e\u0005l\u0000\u0000\u011e"+
		"\u011f\u0001\u0000\u0000\u0000\u011f\u0120\u0006\u0007\u0004\u0000\u0120"+
		"\u0010\u0001\u0000\u0000\u0000\u0121\u0122\u0005i\u0000\u0000\u0122\u0123"+
		"\u0005f\u0000\u0000\u0123\u0124\u0001\u0000\u0000\u0000\u0124\u0125\u0006"+
		"\b\u0005\u0000\u0125\u0012\u0001\u0000\u0000\u0000\u0126\u0127\u0005t"+
		"\u0000\u0000\u0127\u0128\u0005h\u0000\u0000\u0128\u0129\u0005e\u0000\u0000"+
		"\u0129\u012a\u0005n\u0000\u0000\u012a\u012b\u0001\u0000\u0000\u0000\u012b"+
		"\u012c\u0006\t\u0006\u0000\u012c\u0014\u0001\u0000\u0000\u0000\u012d\u012e"+
		"\u0005e\u0000\u0000\u012e\u012f\u0005l\u0000\u0000\u012f\u0130\u0005s"+
		"\u0000\u0000\u0130\u0131\u0005e\u0000\u0000\u0131\u0132\u0001\u0000\u0000"+
		"\u0000\u0132\u0133\u0006\n\u0007\u0000\u0133\u0016\u0001\u0000\u0000\u0000"+
		"\u0134\u0135\u0005w\u0000\u0000\u0135\u0136\u0005h\u0000\u0000\u0136\u0137"+
		"\u0005i\u0000\u0000\u0137\u0138\u0005l\u0000\u0000\u0138\u0139\u0005e"+
		"\u0000\u0000\u0139\u013a\u0001\u0000\u0000\u0000\u013a\u013b\u0006\u000b"+
		"\b\u0000\u013b\u0018\u0001\u0000\u0000\u0000\u013c\u013d\u0005f\u0000"+
		"\u0000\u013d\u013e\u0005o\u0000\u0000\u013e\u013f\u0005r\u0000\u0000\u013f"+
		"\u0140\u0001\u0000\u0000\u0000\u0140\u0141\u0006\f\t\u0000\u0141\u001a"+
		"\u0001\u0000\u0000\u0000\u0142\u0143\u0005d\u0000\u0000\u0143\u0144\u0005"+
		"o\u0000\u0000\u0144\u0145\u0001\u0000\u0000\u0000\u0145\u0146\u0006\r"+
		"\n\u0000\u0146\u001c\u0001\u0000\u0000\u0000\u0147\u0148\u0005c\u0000"+
		"\u0000\u0148\u0149\u0005o\u0000\u0000\u0149\u014a\u0005l\u0000\u0000\u014a"+
		"\u014b\u0005l\u0000\u0000\u014b\u014c\u0005e\u0000\u0000\u014c\u014d\u0005"+
		"c\u0000\u0000\u014d\u014e\u0005t\u0000\u0000\u014e\u014f\u0001\u0000\u0000"+
		"\u0000\u014f\u0150\u0006\u000e\u000b\u0000\u0150\u001e\u0001\u0000\u0000"+
		"\u0000\u0151\u0152\u0005s\u0000\u0000\u0152\u0153\u0005i\u0000\u0000\u0153"+
		"\u015e\u0005n\u0000\u0000\u0154\u0155\u0005c\u0000\u0000\u0155\u0156\u0005"+
		"o\u0000\u0000\u0156\u015e\u0005s\u0000\u0000\u0157\u0158\u0005s\u0000"+
		"\u0000\u0158\u0159\u0005q\u0000\u0000\u0159\u015a\u0005r\u0000\u0000\u015a"+
		"\u015b\u0005t\u0000\u0000\u015b\u015c\u0001\u0000\u0000\u0000\u015c\u015e"+
		"\u0006\u000f\f\u0000\u015d\u0151\u0001\u0000\u0000\u0000\u015d\u0154\u0001"+
		"\u0000\u0000\u0000\u015d\u0157\u0001\u0000\u0000\u0000\u015e \u0001\u0000"+
		"\u0000\u0000\u015f\u0160\u0005$\u0000\u0000\u0160\u0162\u0007\u0005\u0000"+
		"\u0000\u0161\u0163\u0007\u0000\u0000\u0000\u0162\u0161\u0001\u0000\u0000"+
		"\u0000\u0163\u0164\u0001\u0000\u0000\u0000\u0164\u0162\u0001\u0000\u0000"+
		"\u0000\u0164\u0165\u0001\u0000\u0000\u0000\u0165\u0166\u0001\u0000\u0000"+
		"\u0000\u0166\u0167\u0006\u0010\r\u0000\u0167\"\u0001\u0000\u0000\u0000"+
		"\u0168\u0169\u0003+\u0015\u0000\u0169\u016a\u0006\u0011\u000e\u0000\u016a"+
		"$\u0001\u0000\u0000\u0000\u016b\u016c\u0005#\u0000\u0000\u016c\u016d\u0003"+
		"+\u0015\u0000\u016d\u016e\u0006\u0012\u000f\u0000\u016e&\u0001\u0000\u0000"+
		"\u0000\u016f\u0170\u0005$\u0000\u0000\u0170\u0171\u0003+\u0015\u0000\u0171"+
		"\u0172\u0006\u0013\u0010\u0000\u0172(\u0001\u0000\u0000\u0000\u0173\u0174"+
		"\u0005@\u0000\u0000\u0174\u0175\u0003+\u0015\u0000\u0175\u0176\u0006\u0014"+
		"\u0011\u0000\u0176*\u0001\u0000\u0000\u0000\u0177\u017f\u0007\u0006\u0000"+
		"\u0000\u0178\u017a\u0007\u0007\u0000\u0000\u0179\u0178\u0001\u0000\u0000"+
		"\u0000\u017a\u017d\u0001\u0000\u0000\u0000\u017b\u0179\u0001\u0000\u0000"+
		"\u0000\u017b\u017c\u0001\u0000\u0000\u0000\u017c\u017e\u0001\u0000\u0000"+
		"\u0000\u017d\u017b\u0001\u0000\u0000\u0000\u017e\u0180\u0007\b\u0000\u0000"+
		"\u017f\u017b\u0001\u0000\u0000\u0000\u017f\u0180\u0001\u0000\u0000\u0000"+
		"\u0180,\u0001\u0000\u0000\u0000\u0181\u0182\u0005[\u0000\u0000\u0182\u0183"+
		"\u0006\u0016\u0012\u0000\u0183.\u0001\u0000\u0000\u0000\u0184\u0185\u0005"+
		"]\u0000\u0000\u0185\u0186\u0006\u0017\u0013\u0000\u01860\u0001\u0000\u0000"+
		"\u0000\u0187\u0188\u0005)\u0000\u0000\u0188\u0189\u0006\u0018\u0014\u0000"+
		"\u01892\u0001\u0000\u0000\u0000\u018a\u018b\u0005:\u0000\u0000\u018b\u018c"+
		"\u0006\u0019\u0015\u0000\u018c4\u0001\u0000\u0000\u0000\u018d\u018e\u0005"+
		":\u0000\u0000\u018e\u018f\u0005:\u0000\u0000\u018f\u0190\u0001\u0000\u0000"+
		"\u0000\u0190\u0191\u0006\u001a\u0016\u0000\u01916\u0001\u0000\u0000\u0000"+
		"\u0192\u0193\u0005.\u0000\u0000\u0193\u0194\u0006\u001b\u0017\u0000\u0194"+
		"8\u0001\u0000\u0000\u0000\u0195\u0196\u0005:\u0000\u0000\u0196\u0197\u0005"+
		"=\u0000\u0000\u0197\u0198\u0001\u0000\u0000\u0000\u0198\u0199\u0006\u001c"+
		"\u0018\u0000\u0199:\u0001\u0000\u0000\u0000\u019a\u019b\u0005:\u0000\u0000"+
		"\u019b\u019c\u0005:\u0000\u0000\u019c\u019d\u0005=\u0000\u0000\u019d\u019e"+
		"\u0001\u0000\u0000\u0000\u019e\u019f\u0006\u001d\u0019\u0000\u019f<\u0001"+
		"\u0000\u0000\u0000\u01a0\u01a1\u0005;\u0000\u0000\u01a1\u01a2\u0006\u001e"+
		"\u001a\u0000\u01a2>\u0001\u0000\u0000\u0000\u01a3\u01a4\u0005=\u0000\u0000"+
		"\u01a4\u01a5\u0006\u001f\u001b\u0000\u01a5@\u0001\u0000\u0000\u0000\u01a6"+
		"\u01a7\u0007\t\u0000\u0000\u01a7\u01a8\u0006 \u001c\u0000\u01a8\u01a9"+
		"\u0001\u0000\u0000\u0000\u01a9\u01aa\u0006 \u001d\u0000\u01aaB\u0001\u0000"+
		"\u0000\u0000\u01ab\u01ac\u0007\n\u0000\u0000\u01ac\u01ad\u0006!\u001e"+
		"\u0000\u01ad\u01ae\u0001\u0000\u0000\u0000\u01ae\u01af\u0006!\u001d\u0000"+
		"\u01afD\u0001\u0000\u0000\u0000\u01b0\u01b1\u0005*\u0000\u0000\u01b1\u01b2"+
		"\u0005*\u0000\u0000\u01b2\u01b3\u0001\u0000\u0000\u0000\u01b3\u01b4\u0006"+
		"\"\u001f\u0000\u01b4F\u0001\u0000\u0000\u0000\u01b5\u01b6\u0005*\u0000"+
		"\u0000\u01b6\u01b7\u0005*\u0000\u0000\u01b7\u01b8\u0005=\u0000\u0000\u01b8"+
		"\u01b9\u0001\u0000\u0000\u0000\u01b9\u01ba\u0006# \u0000\u01baH\u0001"+
		"\u0000\u0000\u0000\u01bb\u01bc\u0005*\u0000\u0000\u01bc\u01bd\u0006$!"+
		"\u0000\u01bdJ\u0001\u0000\u0000\u0000\u01be\u01bf\u0005*\u0000\u0000\u01bf"+
		"\u01c0\u0005=\u0000\u0000\u01c0\u01c1\u0001\u0000\u0000\u0000\u01c1\u01c2"+
		"\u0006%\"\u0000\u01c2L\u0001\u0000\u0000\u0000\u01c3\u01c4\u0005/\u0000"+
		"\u0000\u01c4\u01c5\u0005/\u0000\u0000\u01c5\u01c6\u0001\u0000\u0000\u0000"+
		"\u01c6\u01c7\u0006&#\u0000\u01c7N\u0001\u0000\u0000\u0000\u01c8\u01c9"+
		"\u0005/\u0000\u0000\u01c9\u01ca\u0005/\u0000\u0000\u01ca\u01cb\u0005="+
		"\u0000\u0000\u01cb\u01cc\u0001\u0000\u0000\u0000\u01cc\u01cd\u0006\'$"+
		"\u0000\u01cdP\u0001\u0000\u0000\u0000\u01ce\u01cf\u0005/\u0000\u0000\u01cf"+
		"\u01d0\u0006(%\u0000\u01d0R\u0001\u0000\u0000\u0000\u01d1\u01d2\u0005"+
		"/\u0000\u0000\u01d2\u01d3\u0005=\u0000\u0000\u01d3\u01d4\u0001\u0000\u0000"+
		"\u0000\u01d4\u01d5\u0006)&\u0000\u01d5T\u0001\u0000\u0000\u0000\u01d6"+
		"\u01d7\u0005%\u0000\u0000\u01d7\u01d8\u0006*\'\u0000\u01d8V\u0001\u0000"+
		"\u0000\u0000\u01d9\u01da\u0005%\u0000\u0000\u01da\u01db\u0006+(\u0000"+
		"\u01dbX\u0001\u0000\u0000\u0000\u01dc\u01dd\u0004,\u0000\u0000\u01dd\u01de"+
		"\u0005+\u0000\u0000\u01de\u01df\u0006,)\u0000\u01dfZ\u0001\u0000\u0000"+
		"\u0000\u01e0\u01e1\u0005+\u0000\u0000\u01e1\u01e2\u0005=\u0000\u0000\u01e2"+
		"\u01e3\u0001\u0000\u0000\u0000\u01e3\u01e4\u0006-*\u0000\u01e4\\\u0001"+
		"\u0000\u0000\u0000\u01e5\u01e6\u0005+\u0000\u0000\u01e6\u01e7\u0006.+"+
		"\u0000\u01e7^\u0001\u0000\u0000\u0000\u01e8\u01e9\u0004/\u0001\u0000\u01e9"+
		"\u01ea\u0005-\u0000\u0000\u01ea\u01eb\u0006/,\u0000\u01eb`\u0001\u0000"+
		"\u0000\u0000\u01ec\u01ed\u0005-\u0000\u0000\u01ed\u01ee\u0005=\u0000\u0000"+
		"\u01ee\u01ef\u0001\u0000\u0000\u0000\u01ef\u01f0\u00060-\u0000\u01f0b"+
		"\u0001\u0000\u0000\u0000\u01f1\u01f2\u0005-\u0000\u0000\u01f2\u01f3\u0006"+
		"1.\u0000\u01f3d\u0001\u0000\u0000\u0000\u01f4\u01f5\u0005=\u0000\u0000"+
		"\u01f5\u01f6\u0005=\u0000\u0000\u01f6\u01f7\u0001\u0000\u0000\u0000\u01f7"+
		"\u01f8\u00062/\u0000\u01f8f\u0001\u0000\u0000\u0000\u01f9\u01fa\u0005"+
		"!\u0000\u0000\u01fa\u01fb\u0005=\u0000\u0000\u01fb\u01fc\u0001\u0000\u0000"+
		"\u0000\u01fc\u01fd\u000630\u0000\u01fdh\u0001\u0000\u0000\u0000\u01fe"+
		"\u01ff\u0005!\u0000\u0000\u01ff\u0200\u000641\u0000\u0200j\u0001\u0000"+
		"\u0000\u0000\u0201\u0202\u0005~\u0000\u0000\u0202\u0203\u000652\u0000"+
		"\u0203l\u0001\u0000\u0000\u0000\u0204\u0205\u0005<\u0000\u0000\u0205\u0206"+
		"\u000663\u0000\u0206n\u0001\u0000\u0000\u0000\u0207\u0208\u0005>\u0000"+
		"\u0000\u0208\u0209\u000674\u0000\u0209p\u0001\u0000\u0000\u0000\u020a"+
		"\u020b\u0005<\u0000\u0000\u020b\u020c\u0005=\u0000\u0000\u020c\u020d\u0001"+
		"\u0000\u0000\u0000\u020d\u020e\u000685\u0000\u020er\u0001\u0000\u0000"+
		"\u0000\u020f\u0210\u0005>\u0000\u0000\u0210\u0211\u0005=\u0000\u0000\u0211"+
		"\u0212\u0001\u0000\u0000\u0000\u0212\u0213\u000696\u0000\u0213t\u0001"+
		"\u0000\u0000\u0000\u0214\u0215\u0005&\u0000\u0000\u0215\u0216\u0006:7"+
		"\u0000\u0216v\u0001\u0000\u0000\u0000\u0217\u0218\u0005&\u0000\u0000\u0218"+
		"\u0219\u0005=\u0000\u0000\u0219\u021a\u0001\u0000\u0000\u0000\u021a\u021b"+
		"\u0006;8\u0000\u021bx\u0001\u0000\u0000\u0000\u021c\u021d\u0005^\u0000"+
		"\u0000\u021d\u021e\u0006<9\u0000\u021ez\u0001\u0000\u0000\u0000\u021f"+
		"\u0220\u0005^\u0000\u0000\u0220\u0221\u0005=\u0000\u0000\u0221\u0222\u0001"+
		"\u0000\u0000\u0000\u0222\u0223\u0006=:\u0000\u0223|\u0001\u0000\u0000"+
		"\u0000\u0224\u0225\u0005|\u0000\u0000\u0225\u0226\u0006>;\u0000\u0226"+
		"~\u0001\u0000\u0000\u0000\u0227\u0228\u0005|\u0000\u0000\u0228\u0229\u0005"+
		"=\u0000\u0000\u0229\u022a\u0001\u0000\u0000\u0000\u022a\u022b\u0006?<"+
		"\u0000\u022b\u0080\u0001\u0000\u0000\u0000\u022c\u022d\u0005&\u0000\u0000"+
		"\u022d\u022e\u0005&\u0000\u0000\u022e\u022f\u0001\u0000\u0000\u0000\u022f"+
		"\u0230\u0006@=\u0000\u0230\u0082\u0001\u0000\u0000\u0000\u0231\u0232\u0005"+
		"&\u0000\u0000\u0232\u0233\u0005&\u0000\u0000\u0233\u0234\u0005&\u0000"+
		"\u0000\u0234\u0235\u0001\u0000\u0000\u0000\u0235\u0236\u0006A>\u0000\u0236"+
		"\u0084\u0001\u0000\u0000\u0000\u0237\u0238\u0005&\u0000\u0000\u0238\u0239"+
		"\u0005&\u0000\u0000\u0239\u023a\u0005=\u0000\u0000\u023a\u023b\u0001\u0000"+
		"\u0000\u0000\u023b\u023c\u0006B?\u0000\u023c\u0086\u0001\u0000\u0000\u0000"+
		"\u023d\u023e\u0005&\u0000\u0000\u023e\u023f\u0005&\u0000\u0000\u023f\u0240"+
		"\u0005&\u0000\u0000\u0240\u0241\u0005=\u0000\u0000\u0241\u0242\u0001\u0000"+
		"\u0000\u0000\u0242\u0243\u0006C@\u0000\u0243\u0088\u0001\u0000\u0000\u0000"+
		"\u0244\u0245\u0005^\u0000\u0000\u0245\u0246\u0005^\u0000\u0000\u0246\u0247"+
		"\u0001\u0000\u0000\u0000\u0247\u0248\u0006DA\u0000\u0248\u008a\u0001\u0000"+
		"\u0000\u0000\u0249\u024a\u0005^\u0000\u0000\u024a\u024b\u0005^\u0000\u0000"+
		"\u024b\u024c\u0005=\u0000\u0000\u024c\u024d\u0001\u0000\u0000\u0000\u024d"+
		"\u024e\u0006EB\u0000\u024e\u008c\u0001\u0000\u0000\u0000\u024f\u0250\u0005"+
		"|\u0000\u0000\u0250\u0251\u0005|\u0000\u0000\u0251\u0252\u0001\u0000\u0000"+
		"\u0000\u0252\u0253\u0006FC\u0000\u0253\u008e\u0001\u0000\u0000\u0000\u0254"+
		"\u0255\u0005|\u0000\u0000\u0255\u0256\u0005|\u0000\u0000\u0256\u0257\u0005"+
		"=\u0000\u0000\u0257\u0258\u0001\u0000\u0000\u0000\u0258\u0259\u0006GD"+
		"\u0000\u0259\u0090\u0001\u0000\u0000\u0000\u025a\u025b\u0005|\u0000\u0000"+
		"\u025b\u025c\u0005|\u0000\u0000\u025c\u025d\u0005|\u0000\u0000\u025d\u025e"+
		"\u0001\u0000\u0000\u0000\u025e\u025f\u0006HE\u0000\u025f\u0092\u0001\u0000"+
		"\u0000\u0000\u0260\u0261\u0005|\u0000\u0000\u0261\u0262\u0005|\u0000\u0000"+
		"\u0262\u0263\u0005|\u0000\u0000\u0263\u0264\u0005=\u0000\u0000\u0264\u0265"+
		"\u0001\u0000\u0000\u0000\u0265\u0266\u0006IF\u0000\u0266\u0094\u0001\u0000"+
		"\u0000\u0000\u0267\u0268\u0005<\u0000\u0000\u0268\u0269\u0005<\u0000\u0000"+
		"\u0269\u026a\u0001\u0000\u0000\u0000\u026a\u026b\u0006JG\u0000\u026b\u0096"+
		"\u0001\u0000\u0000\u0000\u026c\u026d\u0005<\u0000\u0000\u026d\u026e\u0005"+
		"<\u0000\u0000\u026e\u026f\u0005=\u0000\u0000\u026f\u0270\u0001\u0000\u0000"+
		"\u0000\u0270\u0271\u0006KH\u0000\u0271\u0098\u0001\u0000\u0000\u0000\u0272"+
		"\u0273\u0005>\u0000\u0000\u0273\u0274\u0005>\u0000\u0000\u0274\u0275\u0001"+
		"\u0000\u0000\u0000\u0275\u0276\u0006LI\u0000\u0276\u009a\u0001\u0000\u0000"+
		"\u0000\u0277\u0278\u0005>\u0000\u0000\u0278\u0279\u0005>\u0000\u0000\u0279"+
		"\u027a\u0005=\u0000\u0000\u027a\u027b\u0001\u0000\u0000\u0000\u027b\u027c"+
		"\u0006MJ\u0000\u027c\u009c\u0001\u0000\u0000\u0000\u027d\u027e\u0005."+
		"\u0000\u0000\u027e\u027f\u0005.\u0000\u0000\u027f\u0280\u0005.\u0000\u0000"+
		"\u0280\u0281\u0001\u0000\u0000\u0000\u0281\u0282\u0006NK\u0000\u0282\u009e"+
		"\u0001\u0000\u0000\u0000\u0283\u0284\u0005:\u0000\u0000\u0284\u0285\u0005"+
		"*\u0000\u0000\u0285\u0286\u0001\u0000\u0000\u0000\u0286\u0287\u0006OL"+
		"\u0000\u0287\u00a0\u0001\u0000\u0000\u0000\u0288\u0289\u0005:\u0000\u0000"+
		"\u0289\u028a\u0005*\u0000\u0000\u028a\u028b\u0005=\u0000\u0000\u028b\u028c"+
		"\u0001\u0000\u0000\u0000\u028c\u028d\u0006PM\u0000\u028d\u00a2\u0001\u0000"+
		"\u0000\u0000\u028e\u028f\u0005.\u0000\u0000\u028f\u0290\u0005=\u0000\u0000"+
		"\u0290\u0291\u0001\u0000\u0000\u0000\u0291\u0292\u0006QN\u0000\u0292\u00a4"+
		"\u0001\u0000\u0000\u0000\u0293\u0294\u0005_\u0000\u0000\u0294\u0295\u0005"+
		"=\u0000\u0000\u0295\u0296\u0001\u0000\u0000\u0000\u0296\u0297\u0006RO"+
		"\u0000\u0297\u00a6\u0001\u0000\u0000\u0000\u0298\u0299\u0005!\u0000\u0000"+
		"\u0299\u029a\u0005_\u0000\u0000\u029a\u029b\u0005=\u0000\u0000\u029b\u029c"+
		"\u0001\u0000\u0000\u0000\u029c\u029d\u0006SP\u0000\u029d\u00a8\u0001\u0000"+
		"\u0000\u0000\u029e\u029f\u0004T\u0002\u0000\u029f\u02a0\u0005(\u0000\u0000"+
		"\u02a0\u02a1\u0006TQ\u0000\u02a1\u00aa\u0001\u0000\u0000\u0000\u02a2\u02a3"+
		"\u0004U\u0003\u0000\u02a3\u02a4\u0005(\u0000\u0000\u02a4\u02a5\u0006U"+
		"R\u0000\u02a5\u00ac\u0001\u0000\u0000\u0000\u02a6\u02a8\t\u0000\u0000"+
		"\u0000\u02a7\u02a6\u0001\u0000\u0000\u0000\u02a8\u02a9\u0001\u0000\u0000"+
		"\u0000\u02a9\u02aa\u0001\u0000\u0000\u0000\u02a9\u02a7\u0001\u0000\u0000"+
		"\u0000\u02aa\u00ae\u0001\u0000\u0000\u0000\u001a\u0000\u00b2\u00b9\u00c0"+
		"\u00c5\u00c8\u00cc\u00d1\u00d3\u00d8\u00dc\u00e1\u00e3\u00e9\u00ee\u00f5"+
		"\u00fa\u00fe\u0103\u0108\u010f\u015d\u0164\u017b\u017f\u02a9S\u0001\u0000"+
		"\u0000\u0001\u0001\u0001\u0001\u0002\u0002\u0001\u0006\u0003\u0001\u0007"+
		"\u0004\u0001\b\u0005\u0001\t\u0006\u0001\n\u0007\u0001\u000b\b\u0001\f"+
		"\t\u0001\r\n\u0001\u000e\u000b\u0001\u000f\f\u0001\u0010\r\u0001\u0011"+
		"\u000e\u0001\u0012\u000f\u0001\u0013\u0010\u0001\u0014\u0011\u0001\u0016"+
		"\u0012\u0001\u0017\u0013\u0001\u0018\u0014\u0001\u0019\u0015\u0001\u001a"+
		"\u0016\u0001\u001b\u0017\u0001\u001c\u0018\u0001\u001d\u0019\u0001\u001e"+
		"\u001a\u0001\u001f\u001b\u0001 \u001c\u0000\u0001\u0000\u0001!\u001d\u0001"+
		"\"\u001e\u0001#\u001f\u0001$ \u0001%!\u0001&\"\u0001\'#\u0001($\u0001"+
		")%\u0001*&\u0001+\'\u0001,(\u0001-)\u0001.*\u0001/+\u00010,\u00011-\u0001"+
		"2.\u00013/\u000140\u000151\u000162\u000173\u000184\u000195\u0001:6\u0001"+
		";7\u0001<8\u0001=9\u0001>:\u0001?;\u0001@<\u0001A=\u0001B>\u0001C?\u0001"+
		"D@\u0001EA\u0001FB\u0001GC\u0001HD\u0001IE\u0001JF\u0001KG\u0001LH\u0001"+
		"MI\u0001NJ\u0001OK\u0001PL\u0001QM\u0001RN\u0001SO\u0001TP\u0001UQ";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}