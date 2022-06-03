//
//  stringparser.h
//  code_strparser
//
//  Created by Andrea Agostini on 18/10/2018.
//

#ifndef stringparser_h
#define stringparser_h

#include "bell/fileid.hpp"

#include <unordered_map>
#include <unordered_set>

typedef struct _parseParams {
    astNode *ast;
    t_globalVariableTable *gvt;
    countedList<t_localVar> *localVariablesStackBase[256] { };
    countedList<t_localVar> **localVariablesStack;
    std::unordered_map<t_symbol *, int> *localVariablesAuxMapStackBase[256] { };
    std::unordered_map<t_symbol *, int> **localVariablesAuxMapStack;
    std::unordered_set<t_symbol *> *liftedVariablesStackBase[256] { };
    std::unordered_set<t_symbol *> **liftedVariablesStack;
    countedList<class funArg *> *argumentsStackBase[256] { };
    countedList<class funArg *> **argumentsStack;
    
    std::unordered_map<t_symbol*, std::unordered_set<astPatcherVar*>>* name2patcherVars;
    std::unordered_set<t_globalVariable*> *globalVariables;
    
    t_atom_long fnDepth;
    t_atom_long *dataInlets;
    t_atom_long *dataOutlets;
    t_atom_long *directInlets;
    t_atom_long *directOutlets;
    long *codeac;
    std::unordered_map<std::string, t_function *> *bifs;
    std::unordered_set<t_function *> *funcs;
    t_ofTable *ofTable;
    t_codableobj *owner;
} t_parseParams;


struct t_lexparams {
    struct t_bufstack *bufstack;
    struct t_bufstack *this_bs;
    fileidSet files;
    int state;
    int line;
    
    t_lexparams();
    virtual ~t_lexparams();

    int setState(int s);
    
    int getState();
};

struct t_tokenNames {
    const std::string original;
    const std::string replacement;
};

static t_tokenNames tokenNames[] = {
    
    { "LONG_LITERAL", "integer literal" },
    { "INLET", "inlet" },
    { "INTINLET", "integer inlet" },
    { "RATINLET", "rational inlet" },
    { "FLOATINLET", "float inlet" },
    { "PITCHINLET", "pitch inlet" },
    { "OUTLET", "outlet" },
    { "DIRINLET", "direct inlet" },
    { "DIROUTLET", "direct outlet"},
    { "RAT_LITERAL", "rational literal"},
    { "DOUBLE_LITERAL", "float literal" },
    { "PITCH_LITERAL", "pitch literal" },
    { "SYMBOL_LITERAL", "symbol literal" },
    { "GLOBALVAR", "global variable" },
    { "PATCHERVAR", "patcher variable" },
    { "LOCALVAR", "local variable" },
    { "NAMEDPARAM", "named parameter" },
    { "BIF", "built-in function" },
    { "OF", "built-in function" },
    { "SEQ", "semicolon" },
    { "IF_KW", "if keyword" },
    { "THEN_KW", "then keyword" },
    { "ELSE_KW", "else keyword" },
    { "WHILE_KW", "while keyword" },
    { "DO_KW", "do keyword" },
    { "FOR_KW", "for keyword" },
    { "IN_KW", "in keyword" },
    { "COLLECT_KW", "collect keyword" },
    { "ASSIGN", "assignment"},
    { "PLUS", "+ operator" },
    { "MINUS", "- operator" },
    { "TIMES", "* operator" },
    { "DIV", "/ operator" },
    { "DIVDIV", "// operator" },
    { "APLUS", "+= operator" },
    { "LOGOR", "|| operator" },
    { "LOGAND", "&& operator" },
    { "LOGOREXT", "||| operator" },
    { "LOGANDEXT", "&&& operator" },
    { "EQUAL", "== operator" },
    { "LT", "< operator" },
    { "GT", "> operator" },
    { "LEQ", "<= operator" },
    { "GEQ", ">= operator" },
    { "NEQ", "!= operator" },
    { "OPEN", "open parenthesis" },
    { "CLOSEDROUND", "closed parenthesis" },
    { "FUNDEF", "-> operator" },
    { "PUSH", "open square bracket" },
    { "POP", "closed square bracket" },
    { "STARTPARAMS", "open parenthesis for function argument list" },
    { "COMMA", "comma" },
    { "ELLIPSIS", "<...> specifier" },
    { "BACHNULL", "null keyword" },
    { "BACHNIL", "nil keyword" },
    { "ARGCOUNT", "$argcount pseudovariable" },
    { "EOL", "end of line" },
    { "UNRECOGNIZED", "unrecognized character" },
    { "LIFT", "-^ specifier" },
    { "AMINUS", "-= operator" },
    { "ATIMES", "*= operator" },
    { "APOWOP", "**= operator" },
    { "ADIV", "/= operator" },
    { "ADIVDIV", "//= operator" },
    { "AREM", "%= operator" },
    { "ABITAND", "& operator" },
    { "ABITXOR", "^ operator" },
    { "ABITOR", "| operator" },
    { "ALSHIFT", "<<= operator" },
    { "ARSHIFT", ">>= operator" },
    { "ALOGAND", "&&= operator" },
    { "ALOGANDEXT", "&&&= operator" },
    { "ALOGXOR", "^^= operator" },
    { "ALOGOR", "||= operator" },
    { "ALOGOREXT", "|||= operator" },
    { "ANTHOP", ":= operator" },
    { "AAPPLY", ".= operator" },
    { "ACONCAT", "_= operator" },
    { "ARCONCAT", "=_ operator" },
    { "CONCAT", "_ operator" },
    { "LOGXOR", "^^ operator" },
    { "BITOR", "| operator" },
    { "BITXOR", "^ operator" },
    { "BITAND", "& operator" },
    { "REPEAT", ":* operator" },
    { "RANGE", "... operator" },
    { "LSHIFT", "<< operator" },
    { "RSHIFT", ">> operator" },
    { "REM", "% operator" },
    { "NTHOP", ": operator" },
    { "PICKOP", ":: operator" },
    { "APPLY", ". operator" },
    { "AS_KW", "as keyword" },
    { "WITH_KW", "with keyword" },
    { "UPLUS", "unary + operator" },
    { "LOGNOT", "! operator" },
    { "BITNOT", "~ operator" },
    { "UMINUS", "unary - operator" },
    { "POWOP", "** operator" },
    { "KEEP", "keep keyword" },
    { "UNKEEP", "unkeep keyword" },
    { "INIT", "init keyword" }
    /*
    "$accept", "program",
    "sequence", "ifThenElse", "whileloop", "forloop", "forargList", "forarg",
    "fundef", "$@1", "$@2", "$@3", "$@4", "funargList", "$@5", "$@6",
    "liftedargList", "functionApplication", "funcall", "argsByPositionList",
    "argsByNameList", "argByName", "list", "listEnd", "simpleList",
    "assignment", "assign", "lvalueStepList", "lvalueStepParams", "exp",
    "term", "var", "globalVar", "patcherVar", "localVar"*/
};

#endif /* stringparser_h */
