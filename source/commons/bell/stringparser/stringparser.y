%{
    /*
     *  stringparser.y
     *
     * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
     *
     * This program is free software: you can redistribute it and/or modify it
     * under the terms of the GNU General Public License
     * as published by the Free Software Foundation,
     * either version 3 of the License, or (at your option) any later version.
     * This program is distributed in the hope that it will be useful,
     * but WITHOUT ANY WARRANTY; without even the implied warranty of
     * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
     * See the GNU General Public License for more details.
     * You should have received a copy of the GNU General Public License
     * along with this program.
     * If not, see <https://www.gnu.org/licenses/>.
     *
     */
%}

%define api.pure true
%define parse.error verbose
%token-table
%glr-parser
%name-prefix "stringparser_"

%{
    #ifdef CONFIGURATION_Development
    //#define code_dev_post post // UNCOMMENT THIS TO TURN ON VERBOSE PARSING
    #endif
    
    #ifndef code_dev_post
    #define code_dev_post(...) ((void) 0)
    #else
    #define YYDEBUG 1
    #endif
    
    //#define BACH_MAX
    #ifdef BACH_MAX
    #include "foundation/llllobj.h"
    #include "ext_common.h"
    #include "ext_globalsymbol.h"
    #else
    #include <stdio.h>
    #define code_dev_post printf
    #endif
    
    #include "bell/bach_codableobj.hpp"
    #include "bell/ast.hpp"
    #include "stringparser.h"
    
    extern t_bach *bach;


    %}

%union {
    astNode *n;
    astFunctionCall *fc;
    astLocalVar *lv;
    astPatcherVar *pv;
    astGlobalVar *gv;
    astVar *var;
    
    countedList<astNode *> *nl;
    countedList<symNodePair *> *snpl;
    countedList<funArg *> *funarglist;
    countedList<t_symbol *> *liftedarglist;
    countedList<forArg *> *fal;
    lvalueStepList *lvsl;
    symNodePair *snp;
    forArg *forarg;
    
    long l;
    t_rational r;
    double d;
    t_pitch p;
    t_symbol *sym;
}

%token <l> LONG_LITERAL INLET INTINLET RATINLET FLOATINLET PITCHINLET OUTLET DIRINLET DIROUTLET
%token <r> RAT_LITERAL
%token <d> DOUBLE_LITERAL
%token <p> PITCH_LITERAL
%token <sym> SYMBOL_LITERAL GLOBALVAR PATCHERVAR LOCALVAR NAMEDPARAM BIF OF
%token NULLIFY
%token IF_KW THEN_KW ELSE_KW
%token WHILE_KW DO_KW FOR_KW IN_KW COLLECT_KW
%token ASSIGN
%token PLUS MINUS TIMES DIV DIVDIV
%token APLUS
%token LOGOR LOGAND LOGOREXT LOGANDEXT
%token EQUAL LT GT LEQ GEQ NEQ
%token OPEN CLOSEDROUND
%token FUNDEF
%token PUSH POP
%token STARTPARAMS
%token COMMA
%token ELLIPSIS
%token BACHNULL BACHNIL
%token ARGCOUNT
%token EOL
%token UNRECOGNIZED

%nonassoc FUNDEF LIFT
%right ASSIGN APLUS AMINUS ATIMES APOWOP ADIV ADIVDIV AREM ABITAND ABITXOR ABITOR ALSHIFT ARSHIFT ALOGAND ALOGANDEXT ALOGXOR ALOGOR ALOGOREXT ANTHOP AAPPLY ACONCAT ARCONCAT
%left CONCAT
%left LOGOR LOGOREXT
%left LOGXOR
%left LOGAND LOGANDEXT
%left BITOR
%left BITXOR
%left BITAND
%left LT GT LEQ GEQ
%left EQUAL NEQ
%left REPEAT
%left RANGE
%left LSHIFT RSHIFT
%left PLUS MINUS
%left TIMES DIV DIVDIV REM
%right UPLUS
%right UMINUS
%right POWOP
%left NTHOP PICKOP APPLY ACCESS_UNWRAP
%nonassoc LVALUESTEPPARAMS
%nonassoc STARTPARAMS
%nonassoc IF_KW THEN_KW FOR_KW IN_KW AS_KW WITH_KW WHILE_KW DO_KW COLLECT_KW
%nonassoc ELSE_KW
%right LOGNOT BITNOT
%nonassoc KEEP UNKEEP INIT
%left NULLIFY


%type <n> term list exp assignment assign sequence program fundef forloop whileloop simpleList lvalueStepParams ifThenElse listEnd
%type <fc> funcall functionApplication
%type <nl> argsByPositionList
%type <snpl> argsByNameList
%type <funarglist> funargList
%type <liftedarglist> liftedargList
%type <fal> forargList
%type <lvsl> lvalueStepList
%type <var> var
%type <lv> localVar
%type <pv> patcherVar
%type <gv> globalVar
%type <snp> argByName
%type <forarg> forarg

%{
    #include "stringparser_tab_nolines.h"
    
    #define YY_HEADER_EXPORT_START_CONDITIONS
    #define YY_NO_UNISTD_H
    
    #include "stringparser_lex_nolines.h"
    

    
    int yylex(YYSTYPE *yylval_param, yyscan_t myscanner, struct _parseParams
    *params);
    
    int yyerror(yyscan_t myscanner,
    t_parseParams *params,
    const char *s);
    
    
    YY_BUFFER_STATE stringparser_scan_string(yyscan_t myscanner, const char *buf);
    void stringparser_flush_and_delete_buffer(yyscan_t myscanner, YY_BUFFER_STATE bp);
    
    void addVariableToScope(t_parseParams *params, t_symbol *name)
    {
        auto known = (*(params->localVariablesAuxMapStack))->find(name);
        if (known == (*(params->localVariablesAuxMapStack))->end()) { // yet unknown
            (**(params->localVariablesAuxMapStack))[name] = 1;
            
            if (params->liftedVariablesStack == params->liftedVariablesStackBase) {
                *(params->localVariablesStack) = new countedList<t_symbol *> (name, *(params->localVariablesStack)); // if we're at the main function level, then everything is lifted (as it can be set from the outside)
            } else {
                auto lifted = (*(params->liftedVariablesStack))->find(name);
                if (lifted == (*(params->liftedVariablesStack))->end()) { // not lifted
                    *(params->implicitArgumentsStack) = new countedList<funArg *>(new funArg(name), *(params->implicitArgumentsStack));
                } else { // old behavior: lifted
                    *(params->localVariablesStack) = new countedList<t_symbol *> (name, *(params->localVariablesStack));
                }
            }
        }
    }
%}

%parse-param {void *scanner}
%parse-param {struct _parseParams *params}

%lex-param {void *scanner}
%lex-param {struct _parseParams *params}

%initial-action {
    #ifdef YYDEBUG
    #if YYDEBUG == 1
    yydebug = 1;
    #endif
    #endif
}

%%

program: %empty {
    params->ast = new astConst(llll_get(), params->owner);
    *params->codeac = -1;
    code_dev_post ("parse: empty program\n");
}
| NAMEDPARAM {
    params->ast = new astConst(llll_get(), params->owner);
    *params->codeac = 0;
    code_dev_post ("parse: NAMEDPARAM: empty program\n");
    YYACCEPT;
}
| sequence {
    params->ast = $1;
    *params->codeac = -1;
    code_dev_post("codeac: %ld", *params->codeac);
    code_dev_post ("parse: sequence: program\n");
}
| sequence NAMEDPARAM {
    params->ast = $1;
    code_dev_post("codeac: %ld", *params->codeac);
    code_dev_post ("parse: sequence NAMEDPARAM: program\n");
    YYACCEPT;
}
 ;

sequence: list
| sequence list %prec CONCAT {
    $$ = new astConcat($1, $2, params->owner);
    code_dev_post("parse: cat\n");
}
| sequence NULLIFY {
    $$ = new astNullify($1, params->owner);
    code_dev_post ("parse: sequence NULLIFY: sequence\n");
}
;

ifThenElse : IF_KW sequence THEN_KW list {
    $$ = new astIfThenElse($2, $4, nullptr, params->owner);
    code_dev_post ("parse: if then\n");
}
| IF_KW sequence THEN_KW list ELSE_KW list {
    // ask JLG: this causes 26 r/r conflicts.
    // Putting
    // IF_KW sequence THEN_KW valueOrAssignment ELSE_KW valueOrAssignment
    // would silence the conflicts, but doesn't work the same.
    // The current version parses
    //  if 1==1 then $a := 1 ; $b := 2 else $a := 3 ; $a
    // as
    //  if 1==1 then [$a := 1 ; $b := 2] else $a := 3 ; $a
    // thus returning 1
    // The "fixed" version, on the other hand, only considers
    //  if 1==1 then $a := 1 ; $b := 2
    // and discards what follows, thus resulting in 2.
    // On the other hand, I don't want to be forced to write
    // IF_KW sequence THEN_KW sequence
    // in the previous rule.
    // How do I solve this?
    
    $$ = new astIfThenElse($2, $4, $6, params->owner);
    code_dev_post ("parse: if then else\n");
}

whileloop : WHILE_KW sequence DO_KW list {
    $$ = new astWhileLoop<E_LOOP_DO>($2, $4, params->owner);
    code_dev_post ("parse: while...do\n");
}
| WHILE_KW sequence COLLECT_KW list {
    $$ = new astWhileLoop<E_LOOP_COLLECT>($2, $4, params->owner);
    code_dev_post ("parse: while...collect\n");
}
;

forloop : FOR_KW forargList DO_KW list
{
    $$ = new astForLoop<E_LOOP_DO>($2, nullptr, nullptr, nullptr, $4, params->owner);
    code_dev_post ("parse: FOR_KW forargList DO_KW list\n");
}
| FOR_KW forargList WITH_KW argsByNameList DO_KW list
{
    $$ = new astForLoop<E_LOOP_DO>($2, nullptr, nullptr, $4, $6, params->owner);
    code_dev_post ("parse: forargList WITH_KW argsByNameList DO_KW list\n");
}
| FOR_KW forargList AS_KW sequence DO_KW list
{
    $$ = new astForLoop<E_LOOP_DO>($2, nullptr, $4, nullptr, $6, params->owner);
    code_dev_post ("parse: FOR_KW forargList AS_KW sequence DO_KW list\n");
}
| FOR_KW forargList AS_KW sequence WITH_KW argsByNameList DO_KW list
{
    $$ = new astForLoop<E_LOOP_DO>($2, nullptr, $4, $6, $8, params->owner);
    code_dev_post ("parse: forargList AS_KW sequence WITH_KW argsByNameList DO_KW list\n");
}
| FOR_KW forargList WITH_KW argsByNameList AS_KW sequence DO_KW list
{
    $$ = new astForLoop<E_LOOP_DO>($2, nullptr, $6, $4, $8, params->owner);
    code_dev_post ("parse: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence DO_KW list\n");
}
| FOR_KW forargList COLLECT_KW list
{
    $$ = new astForLoop<E_LOOP_COLLECT>($2, nullptr, nullptr, nullptr, $4, params->owner);
    code_dev_post ("parse: FOR_KW forargList COLLECT_KW list\n");
}
| FOR_KW forargList WITH_KW argsByNameList COLLECT_KW list
{
    $$ = new astForLoop<E_LOOP_COLLECT>($2, nullptr, nullptr, $4, $6, params->owner);
    code_dev_post ("parse: forargList WITH_KW argsByNameList COLLECT_KW list\n");
}
| FOR_KW forargList AS_KW sequence COLLECT_KW list
{
    $$ = new astForLoop<E_LOOP_COLLECT>($2, nullptr, $4, nullptr, $6, params->owner);
    code_dev_post ("parse: FOR_KW forargList AS_KW sequence COLLECT_KW list\n");
}
| FOR_KW forargList AS_KW sequence WITH_KW argsByNameList COLLECT_KW list
{
    $$ = new astForLoop<E_LOOP_COLLECT>($2, nullptr, $4, $6, $8, params->owner);
    code_dev_post ("parse: forargList AS_KW sequence WITH_KW argsByNameList COLLECT_KW list\n");
}
| FOR_KW forargList WITH_KW argsByNameList AS_KW sequence COLLECT_KW list
{
    $$ = new astForLoop<E_LOOP_COLLECT>($2, nullptr, $6, $4, $8, params->owner);
    code_dev_post ("parse: FOR_KW forargList WITH_KW argsByNameList AS_KW sequence COLLECT_KW list\n");
}
;

forargList : forarg {
    $$ = new countedList<forArg *>($1);
    code_dev_post ("parse: for iterator (first term)\n");
}
| forargList COMMA forarg {
    $$ = new countedList<forArg *>($3, $1);
    code_dev_post ("parse: for iterator (subsequent term)\n");
}
;

forarg : LOCALVAR IN_KW sequence {
    $$ = new forArg($1, nullptr, $3);
    addVariableToScope(params, $1);
    code_dev_post ("parse: for iterator with index");
}
| LOCALVAR LOCALVAR IN_KW sequence {
    addVariableToScope(params, $1);
    addVariableToScope(params, $2);
    $$ = new forArg($1, $2, $4);
    code_dev_post ("parse: for iterator with index and address");
}
;

fundef : funargList FUNDEF {
    params->fnDepth++;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    *++(params->implicitArgumentsStack) = $1;
} list {
    t_function *fn = new t_userFunction(*(params->implicitArgumentsStack), *(params->localVariablesStack), $4, params->owner);
    $$ = new astConst(fn, params->owner);
    *(params->localVariablesStack--) = nullptr;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->implicitArgumentsStack);
    code_dev_post ("parse: user defined function");
}
| FUNDEF {
    ++(params->localVariablesStack);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    params->fnDepth++;
    *++(params->implicitArgumentsStack) = nullptr;
} list {
    t_function *fn = new t_userFunction(*(params->implicitArgumentsStack), *(params->localVariablesStack), $3, params->owner);
    $$ = new astConst(fn, params->owner);
    *(params->localVariablesStack--) = nullptr;;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->implicitArgumentsStack);
    code_dev_post ("parse: user defined function");
}
| funargList liftedargList FUNDEF {
    params->fnDepth++;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    for (countedList<t_symbol *> *v = $2->getHead();
         v;
         v = v->getNext()) {
             (*(params->liftedVariablesStack))->insert(v->getItem());
    }
    *++(params->implicitArgumentsStack) = $1;
} list {
    t_function *fn = new t_userFunction(*(params->implicitArgumentsStack), *(params->localVariablesStack), $5, params->owner);
    $$ = new astConst(fn, params->owner);
    *(params->localVariablesStack--) = nullptr;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->implicitArgumentsStack);
    code_dev_post ("parse: user defined function");
}
| liftedargList FUNDEF {
    params->fnDepth++;
    ++(params->localVariablesStack);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    *++(params->implicitArgumentsStack);
    for (countedList<t_symbol *> *v = $1->getHead();
         v;
         v = v->getNext()) {
        (*(params->liftedVariablesStack))->insert(v->getItem());
    }
    *++(params->implicitArgumentsStack) = nullptr;

} list {
    t_function *fn = new t_userFunction(*++(params->implicitArgumentsStack), *(params->localVariablesStack), $4, params->owner);
    $$ = new astConst(fn, params->owner);
    *(params->localVariablesStack--) = nullptr;;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->implicitArgumentsStack);
    code_dev_post ("parse: user defined function");
}
;

funargList : LOCALVAR {
    ++(params->localVariablesStack);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    $$ = new countedList<funArg *>(new funArg($1));
    (**(params->localVariablesAuxMapStack))[$1] = 1;
    code_dev_post ("parse: funargList (first term, no default)\n");
}
| ELLIPSIS {
    ++(params->localVariablesStack);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    $$ = new countedList<funArg *>(new funArg(gensym("<...>")));
    code_dev_post ("parse: ELLIPSIS");
} %dprec 1
| LOCALVAR ASSIGN {
    // two levels are pushed:
    // one for the function, whose definition is beginning here,
    // and one for the parameter default, which is in an outer scope
    params->localVariablesStack += 2;
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    (**(params->localVariablesAuxMapStack))[$1] = 1;
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
} list {
    $$ = new countedList<funArg *>(new funArg($1, $4, *(params->localVariablesStack)));
    delete *(params->localVariablesAuxMapStack);
    
    // this pops the parameter default level
    *(params->localVariablesAuxMapStack--) = nullptr;
    *(params->localVariablesStack--) = nullptr;
    code_dev_post ("parse: funargList (first term, with default)\n");
} %dprec 2
| funargList COMMA LOCALVAR {
    $$ = new countedList<funArg *>(new funArg($3), $1);
    (**(params->localVariablesAuxMapStack))[$3] = 1;
    code_dev_post ("parse: funargList (subsequent term, no default)\n");
}
| funargList COMMA ELLIPSIS {
    $$ = new countedList<funArg *>(new funArg(gensym("<...>")), $1);
    code_dev_post ("parse: funargList (subsequent term, no default)\n");
}
| funargList COMMA LOCALVAR ASSIGN {
    (**(params->localVariablesAuxMapStack))[$3] = 1;
    ++(params->localVariablesStack);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
} list {
    $$ = new countedList<funArg *>(new funArg($3, $6, *(params->localVariablesStack)), $1);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    *(params->localVariablesStack--) = nullptr;
    code_dev_post ("parse: funargList (subsequent term, with default)\n");
}
;

liftedargList : LIFT LOCALVAR {
    $$ = new countedList<t_symbol *>($2);
    code_dev_post ("parse: liftedargList (first term)\n");
}
| liftedargList COMMA LOCALVAR {
    $$ = new countedList<t_symbol *>($3, $1);
    code_dev_post ("parse: liftedargList (subsequent term)\n");
}
;

functionApplication : funcall %dprec 2
| exp APPLY funcall
{
    $3->addOopStyleArg($1);
    code_dev_post ("parse: term APPLY funcall");
    $$ = $3;
} %dprec 1

funcall : term STARTPARAMS argsByPositionList CLOSEDROUND {
    $$ = new astFunctionCall($1, $3, nullptr, params->owner);
    delete $3;
    code_dev_post ("parse: function call with args by position");
}
| term STARTPARAMS argsByNameList CLOSEDROUND {
    $$ = new astFunctionCall($1, nullptr, $3, params->owner);
    delete $3;
    code_dev_post ("parse: function call with args by name");
}
| term STARTPARAMS argsByPositionList COMMA argsByNameList CLOSEDROUND {
    $$ = new astFunctionCall($1, $3, $5, params->owner);
    delete $3;
    delete $5;
    code_dev_post ("parse: function call with args by position and by name");
}
| term STARTPARAMS argsByPositionList argsByNameList CLOSEDROUND {
    $$ = new astFunctionCall($1, $3, $4, params->owner);
    delete $3;
    delete $4;
    code_dev_post ("parse: function call with args by position and by name");
}
| term STARTPARAMS CLOSEDROUND {
    $$ = new astFunctionCall($1, nullptr, nullptr, params->owner);
    code_dev_post ("parse: function call with no args");
}
;

argsByPositionList : sequence {
    $$ = new countedList<astNode *>($1);
    code_dev_post ("parse: argsByPositionList (first term)\n");
} %dprec 1
| argsByPositionList COMMA sequence {
    $$ = new countedList<astNode *>($3, $1);
    code_dev_post ("parse: argsByPositionList (subsequent term)\n");
} %dprec 2
;

argsByNameList : argByName {
    $$ = new countedList<symNodePair *>($1);
    code_dev_post ("parse: argsByNameList (first term)\n");
}
| argsByNameList COMMA argByName {
    $$ = new countedList<symNodePair *>($3, $1);
    code_dev_post ("parse: argsByNameList (subsequent term)\n");
}
| argsByNameList argByName {
    $$ = new countedList<symNodePair *>($2, $1);
    code_dev_post ("parse: argsByNameList (subsequent term)\n");
}
;

argByName : NAMEDPARAM sequence {
    $$ = new symNodePair($1, $2);
    code_dev_post ("parse: named parameter %s", $1->s_name);
}

list: listEnd %prec CONCAT %dprec 2
| simpleList %prec CONCAT %dprec 1
| simpleList listEnd %prec CONCAT {
    $$ = new astConcat($1, $2, params->owner);
    code_dev_post("parse: cat\n");
}
;

listEnd: assignment %dprec 2
| whileloop
| forloop
| ifThenElse
| fundef %dprec 1
;

simpleList: exp %prec CONCAT
| simpleList exp %prec CONCAT {
    $$ = new astConcat($1, $2, params->owner);
    code_dev_post("parse: cat\n");
}
;

assignment: assign
| OUTLET ASSIGN list {
    if (params->dataOutlets && $1 > *(params->dataOutlets))
        *(params->dataOutlets) = $1;
    auto fnConst = new astConst((*(params->bifs))["outlet"], params->owner);


    auto numConst = new astConst($1, params->owner);
    auto tempList = new countedList<astNode *>(numConst);
    tempList = new countedList<astNode *>($3, tempList);
    $$ = new astFunctionCall(fnConst, tempList, nullptr, params->owner);
    code_dev_post("parse: OUTLET ASSIGN list");
}
| DIROUTLET ASSIGN list {
    if (params->directOutlets && $1 > *(params->directOutlets))
        *(params->directOutlets) = $1;
    auto fnConst = new astConst((*(params->ofTable))["directout"], params->owner);
    auto tempList = new countedList<astNode *>(new astConst($1, params->owner));
    tempList = new countedList<astNode *>($3, tempList);
    $$ = new astFunctionCall(fnConst, tempList, nullptr, params->owner);
    code_dev_post("parse: DIROUTLET ASSIGN list");
}
;

assign : var ASSIGN list {
    $$ = new astAssign($1, $3, params->owner);
    code_dev_post("parse: var ASSIGN list");
}
| INIT LOCALVAR ASSIGN list {
    addVariableToScope(params, $2);
    $$ = new astInit($2, $4, params->owner);
    code_dev_post("parse: INIT LOCALVAR ASSIGN list");
}
| var lvalueStepList ASSIGN list {
    $$ = new astRichAssignment<E_RA_STANDARD>($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ASSIGN list");
}
| var APLUS list {
    $$ = new astOperatorAPlus($1, $3, params->owner);
    code_dev_post("parse: var APLUS list");
}
| var lvalueStepList APLUS list {
    $$ = new astOperatorRAPlus($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList APLUS list");
}
| var AMINUS list {
    $$ = new astOperatorAMinus($1, $3, params->owner);
    code_dev_post("parse: var AMINUS list");
}
| var lvalueStepList AMINUS list {
    $$ = new astOperatorRAMinus($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList AMINUS list");
}
| var ATIMES list {
    $$ = new astOperatorATimes($1, $3, params->owner);
    code_dev_post("parse: var ATIMES list");
}
| var lvalueStepList ATIMES list {
    $$ = new astOperatorRATimes($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ATIMES list");
}
| var APOWOP list {
    $$ = new astOperatorAPow($1, $3, params->owner);
    code_dev_post("parse: var APOWOP list");
}
| var lvalueStepList APOWOP list {
    $$ = new astOperatorRAPow($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList APOWOP list");
}
| var ADIV list {
    $$ = new astOperatorADiv($1, $3, params->owner);
    code_dev_post("parse: var ADIV list");
}
| var lvalueStepList ADIV list {
    $$ = new astOperatorRADiv($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ADIV list");
}
| var ADIVDIV list {
    $$ = new astOperatorADivdiv($1, $3, params->owner);
    code_dev_post("parse: var ADIVDIV list");
}
| var lvalueStepList ADIVDIV list {
    $$ = new astOperatorRADivdiv($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ADIVDIV list");
}
| var AREM list {
    $$ = new astOperatorARemainder($1, $3, params->owner);
    code_dev_post("parse: var AREM list");
}
| var lvalueStepList AREM list {
    $$ = new astOperatorRARemainder($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList AREM list");
}
| var ABITAND list {
    $$ = new astOperatorABitAnd($1, $3, params->owner);
    code_dev_post("parse: var ABITAND list");
}
| var lvalueStepList ABITAND list {
    $$ = new astOperatorRABitAnd($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ABITAND list");
}
| var ABITXOR list {
    $$ = new astOperatorABitXor($1, $3, params->owner);
    code_dev_post("parse: var ABITXOR list");
}
| var lvalueStepList ABITXOR list {
    $$ = new astOperatorRABitXor($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ABITXOR list");
}
| var ABITOR list {
    $$ = new astOperatorABitOr($1, $3, params->owner);
    code_dev_post("parse: localVar ABITOR list");
}
| var lvalueStepList ABITOR list {
    $$ = new astOperatorRABitOr($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ABITOR list");
}
| var ALSHIFT list {
    $$ = new astOperatorALShift($1, $3, params->owner);
    code_dev_post("parse: var ALSHIFT list");
}
| var lvalueStepList ALSHIFT list {
    $$ = new astOperatorRALShift($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ALSHIFT list");
}
| var ARSHIFT list {
    $$ = new astOperatorARShift($1, $3, params->owner);
    code_dev_post("parse: var ARSHIFT list");
}
| var lvalueStepList ARSHIFT list {
    $$ = new astOperatorRARShift($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ARSHIFT list");
}
| var ALOGAND list {
    $$ = new astSCAAnd($1, $3, params->owner);
    code_dev_post("parse: var ALOGAND list");
}
| var lvalueStepList ALOGAND list {
    $$ = new astLogRASCAnd($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ALOGAND list");
}
| var ALOGANDEXT list {
    $$ = new astSCAAndExt($1, $3, params->owner);
    code_dev_post("parse: var ALOGANDEXT list");
}
| var lvalueStepList ALOGANDEXT list {
    $$ = new astSCRichAccessAndExt<astRichAssignment<E_RA_SHORTCIRCUIT>>($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ALOGANDEXT list");
}
| var ALOGXOR list {
    $$ = new astLogAXor($1, $3, params->owner);
    code_dev_post("parse: var ALOGXOR list");
}
| var lvalueStepList ALOGXOR list {
    $$ = new astLogRAXor($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ALOGXOR list");
}
| var ALOGOR list {
    $$ = new astSCAOr($1, $3, params->owner);
    code_dev_post("parse: var ALOGOR list");
}
| var lvalueStepList ALOGOR list {
    $$ = new astLogRASCOr($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ALOGOR list");
}
| var ALOGOREXT list {
    $$ = new astSCAOrExt($1, $3, params->owner);
    code_dev_post("parse: var ALOGOREXT list");
}
| var lvalueStepList ALOGOREXT list {
    $$ = new astSCRichAccessOrExt<astRichAssignment<E_RA_SHORTCIRCUIT>>($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ALOGOREXT list");
}
| var ANTHOP list {
    $$ = new astNthAssignOp($1, $3, params->owner);
    code_dev_post ("parse: var ANTHOP list op\n");
}
| var lvalueStepList ANTHOP list {
    $$ = new astRichAccessNthOp<astRichAssignment<E_RA_STANDARD>>($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ANTHOP list");
}
| var ACONCAT list {
    $$ = new astConcatAssignOp($1, $3, params->owner);
    code_dev_post ("parse: var ACONCAT list op\n");
}
| var lvalueStepList ACONCAT list {
    $$ = new astRichAccessConcatOp<astRichAssignment<E_RA_STANDARD>>($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ACONCAT list");
}
| var ARCONCAT list {
    $$ = new astRevConcatAssignOp($1, $3, params->owner);
    code_dev_post ("parse: var ARCONCAT list op\n");
}
| var lvalueStepList ARCONCAT list {
    $$ = new astRichAccessRConcatOp<astRichAssignment<E_RA_STANDARD>>($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ARCONCAT list");
}
| localVar AAPPLY funcall {
    $3->addOopStyleArg($1);
    $$ = new astAssign(new astLocalVar($1), $3, params->owner);
    code_dev_post ("parse: localVar AAPPLY funcall");
}
| patcherVar AAPPLY funcall {
    $3->addOopStyleArg($1);
    astPatcherVar *v = new astPatcherVar($1);
    (*params->name2patcherVars)[v->getName()].insert(v);
    $$ = new astAssign(v, $3, params->owner);
    code_dev_post ("parse: patcherVar AAPPLY funcall");
}
| globalVar AAPPLY funcall {
    $3->addOopStyleArg($1);
    $$ = new astAssign(new astGlobalVar($1), $3, params->owner);
    code_dev_post ("parse: globalVar AAPPLY funcall");
}
| var lvalueStepList AAPPLY funcall {
    $4->addOopStyleArg(new astConst(params->owner));
    $$ = new astRichAccessApplyOp<astRichAssignment<E_RA_SHORTCIRCUIT>>($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList AAPPLY list");
}
;


lvalueStepList: NTHOP lvalueStepParams {
    $$ = new lvalueStepList(new lvalueStep(lvalueStep::E_LV_NTH, $2));
    code_dev_post ("parse: lvalueStepList (NTH first term)");
}
| APPLY lvalueStepParams {
    $$ = new lvalueStepList(new lvalueStep(lvalueStep::E_LV_KEY, $2));
    code_dev_post ("parse: lvalueStepList (KEY first term)");
}
| lvalueStepList NTHOP lvalueStepParams {
    $$ = new lvalueStepList(new lvalueStep(lvalueStep::E_LV_NTH, $3), $1);
    code_dev_post ("parse: lvalueStepList (NTH subsequent term)");
}
| lvalueStepList APPLY lvalueStepParams {
    $$ = new lvalueStepList(new lvalueStep(lvalueStep::E_LV_KEY, $3), $1);
    code_dev_post ("parse: lvalueStepList (KEY subsequent term)");
}
;


lvalueStepParams: exp %prec LVALUESTEPPARAMS
| lvalueStepParams exp %prec LVALUESTEPPARAMS {
    $$ = new astConcat($1, $2, params->owner);
    code_dev_post("parse: cat\n");
}
;

exp: term %dprec 2
| UPLUS listEnd { $$ = $2; }
| UMINUS listEnd {
    $$ = new astOperatorUMinus($2, params->owner);
    code_dev_post("parse: U-\n");
}
| LOGNOT listEnd {
    $$ = new astLogNot($2, params->owner);
    code_dev_post("parse: !\n");
}
| BITNOT listEnd {
    $$ = new astOperatorBitNot($2, params->owner);
    code_dev_post("parse: ~\n");
}
| exp PLUS listEnd {
    $$ = new astOperatorPlus($1, $3, params->owner);
    code_dev_post ("parse: +\n");
}
| exp MINUS listEnd {
    $$ = new astOperatorMinus($1, $3, params->owner);
    code_dev_post ("parse: -\n");
}
| exp TIMES listEnd {
    $$ = new astOperatorTimes($1, $3, params->owner);
    code_dev_post ("parse: *\n");
}
| exp DIV listEnd {
    $$ = new astOperatorDiv($1, $3, params->owner);
    code_dev_post ("parse: /\n");
}
| exp DIVDIV listEnd {
    $$ = new astOperatorDivdiv($1, $3, params->owner);
    code_dev_post ("parse: //\n");
}
| exp REM listEnd {
    $$ = new astOperatorRemainder($1, $3, params->owner);
    code_dev_post ("parse: %\n");
}
| exp POWOP listEnd {
    $$ = new astOperatorPow($1, $3, params->owner);
    code_dev_post ("parse: **\n");
}
| exp BITAND listEnd {
    $$ = new astOperatorBitAnd($1, $3, params->owner);
    code_dev_post ("parse: &\n");
}
| exp BITXOR listEnd {
    $$ = new astOperatorBitXor($1, $3, params->owner);
    code_dev_post ("parse: ^\n");
}
| exp BITOR listEnd {
    $$ = new astOperatorBitOr($1, $3, params->owner);
    code_dev_post ("parse: |\n");
}
| exp LSHIFT listEnd {
    $$ = new astOperatorBitOr($1, $3, params->owner);
    code_dev_post ("parse: <<\n");
}
| exp RSHIFT listEnd {
    $$ = new astOperatorBitOr($1, $3, params->owner);
    code_dev_post ("parse: >>\n");
}
| exp EQUAL listEnd {
    $$ = new astComparatorEq($1, $3, params->owner);
    code_dev_post ("parse: ==\n");
}
| exp NEQ listEnd {
    $$ = new astComparatorNeq($1, $3, params->owner);
    code_dev_post ("parse: !=\n");
}
| exp LT listEnd {
    $$ = new astComparatorLt($1, $3, params->owner);
    code_dev_post ("parse: <\n");
}
| exp GT listEnd {
    $$ = new astComparatorGt($1, $3, params->owner);
    code_dev_post ("parse: <\n");
}
| exp LEQ listEnd {
    $$ = new astComparatorLeq($1, $3, params->owner);
    code_dev_post ("parse: <=\n");
}
| exp GEQ listEnd {
    $$ = new astComparatorGeq($1, $3, params->owner);
    code_dev_post ("parse: >=\n");
}
| exp LOGOR listEnd {
    $$ = new astSCOr($1, $3, params->owner);
    code_dev_post ("parse: ||\n");
}
| exp LOGAND listEnd {
    $$ = new astSCAnd($1, $3, params->owner);
    code_dev_post ("parse: &&\n");
}
| exp LOGXOR listEnd {
    $$ = new astLogXor($1, $3, params->owner);
    code_dev_post ("parse: &&\n");
}
| exp LOGOREXT listEnd {
    $$ = new astSCOrExt($1, $3, params->owner);
    code_dev_post ("parse: |||\n");
}
| exp LOGANDEXT listEnd {
    $$ = new astSCAndExt($1, $3, params->owner);
    code_dev_post ("parse: &&&\n");
}
| exp NTHOP listEnd {
    $$ = new astNthOp($1, $3, params->owner);
    code_dev_post ("parse: nthop (exp NTHOP listEnd)\n");
}
| exp PICKOP listEnd {
    $$ = new astPickOp($1, $3, params->owner);
    code_dev_post ("parse: nthop\n");
}
| exp RANGE listEnd {
    $$ = new astRangeOp($1, $3, params->owner);
    code_dev_post ("parse: range\n");
}
| exp REPEAT listEnd {
    $$ = new astRepeatOp($1, $3, params->owner);
    code_dev_post ("parse: range\n");
}
| exp APPLY listEnd %dprec 1 {
    $$ = new astKeyOp<e_keyOpStandard>($1, $3, params->owner);
    code_dev_post ("parse: access\n");
}
| exp ACCESS_UNWRAP listEnd {
    $$ = new astKeyOp<e_keyOpUnwrapping>($1, $3, params->owner);
    code_dev_post ("parse: access\n");
}

| UPLUS exp { $$ = $2; }
| UMINUS exp {
    $$ = new astOperatorUMinus($2, params->owner);
    code_dev_post("parse: U-\n");
}
| LOGNOT exp {
    $$ = new astLogNot($2, params->owner);
    code_dev_post("parse: !\n");
}
| BITNOT exp {
    $$ = new astOperatorBitNot($2, params->owner);
    code_dev_post("parse: ~\n");
}
| exp PLUS exp {
    $$ = new astOperatorPlus($1, $3, params->owner);
    code_dev_post ("parse: +\n");
}
| exp MINUS exp {
    $$ = new astOperatorMinus($1, $3, params->owner);
    code_dev_post ("parse: -\n");
}
| exp TIMES exp {
    $$ = new astOperatorTimes($1, $3, params->owner);
    code_dev_post ("parse: *\n");
}
| exp DIV exp {
    $$ = new astOperatorDiv($1, $3, params->owner);
    code_dev_post ("parse: /\n");
}
| exp DIVDIV exp {
    $$ = new astOperatorDivdiv($1, $3, params->owner);
    code_dev_post ("parse: //\n");
}
| exp REM exp {
    $$ = new astOperatorRemainder($1, $3, params->owner);
    code_dev_post ("parse: %\n");
}
| exp POWOP exp {
    $$ = new astOperatorPow($1, $3, params->owner);
    code_dev_post ("parse: **\n");
}
| exp BITAND exp {
    $$ = new astOperatorBitAnd($1, $3, params->owner);
    code_dev_post ("parse: &\n");
}
| exp BITXOR exp {
    $$ = new astOperatorBitXor($1, $3, params->owner);
    code_dev_post ("parse: ^\n");
}
| exp BITOR exp {
    $$ = new astOperatorBitOr($1, $3, params->owner);
    code_dev_post ("parse: |\n");
}
| exp LSHIFT exp {
    $$ = new astOperatorBitOr($1, $3, params->owner);
    code_dev_post ("parse: <<\n");
}
| exp RSHIFT exp {
    $$ = new astOperatorBitOr($1, $3, params->owner);
    code_dev_post ("parse: >>\n");
}
| exp EQUAL exp {
    $$ = new astComparatorEq($1, $3, params->owner);
    code_dev_post ("parse: ==\n");
}
| exp NEQ exp {
    $$ = new astComparatorNeq($1, $3, params->owner);
    code_dev_post ("parse: !=\n");
}
| exp LT exp {
    $$ = new astComparatorLt($1, $3, params->owner);
    code_dev_post ("parse: <\n");
}
| exp GT exp {
    $$ = new astComparatorGt($1, $3, params->owner);
    code_dev_post ("parse: <\n");
}
| exp LEQ exp {
    $$ = new astComparatorLeq($1, $3, params->owner);
    code_dev_post ("parse: <=\n");
}
| exp GEQ exp {
    $$ = new astComparatorGeq($1, $3, params->owner);
    code_dev_post ("parse: >=\n");
}
| exp LOGOR exp {
    $$ = new astSCOr($1, $3, params->owner);
    code_dev_post ("parse: ||\n");
}
| exp LOGAND exp {
    $$ = new astSCAnd($1, $3, params->owner);
    code_dev_post ("parse: &&\n");
}
| exp LOGXOR exp {
    $$ = new astLogXor($1, $3, params->owner);
    code_dev_post ("parse: &&\n");
}
| exp LOGOREXT exp {
    $$ = new astSCOrExt($1, $3, params->owner);
    code_dev_post ("parse: |||\n");
}
| exp LOGANDEXT exp {
    $$ = new astSCAndExt($1, $3, params->owner);
    code_dev_post ("parse: &&&\n");
}
| exp NTHOP exp {
    $$ = new astNthOp($1, $3, params->owner);
    code_dev_post ("parse: nthop (exp NTHOP exp)\n");
}
| exp PICKOP exp {
    $$ = new astPickOp($1, $3, params->owner);
    code_dev_post ("parse: nthop\n");
}
| exp RANGE exp {
    $$ = new astRangeOp($1, $3, params->owner);
    code_dev_post ("parse: range\n");
}
| exp REPEAT exp {
    $$ = new astRepeatOp($1, $3, params->owner);
    code_dev_post ("parse: range\n");
}
| exp APPLY exp {
    $$ = new astKeyOp<e_keyOpStandard>($1, $3, params->owner);
    code_dev_post ("parse: access\n");
} %dprec 1
| exp ACCESS_UNWRAP exp {
    $$ = new astKeyOp<e_keyOpUnwrapping>($1, $3, params->owner);
    code_dev_post ("parse: access_unwrap\n");
} %dprec 1

| term lvalueStepList ASSIGN list %dprec 2 {
    $$ = new astRichEdit<E_RA_STANDARD>($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ASSIGN list");
}
| term lvalueStepList APLUS list %dprec 2 {
    $$ = new astOperatorREPlus($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList APLUS list");
}
| term lvalueStepList AMINUS list %dprec 2 {
    $$ = new astOperatorREMinus($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList AMINUS list");
}
| term lvalueStepList ATIMES list %dprec 2 {
    $$ = new astOperatorRETimes($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ATIMES list");
}
| term lvalueStepList APOWOP list %dprec 2 {
    $$ = new astOperatorREPow($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList APOWOP list");
}
| term lvalueStepList ADIV list %dprec 2 {
    $$ = new astOperatorREDiv($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ADIV list");
}
| term lvalueStepList ADIVDIV list %dprec 2 {
    $$ = new astOperatorREDivdiv($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ADIVDIV list");
}
| term lvalueStepList AREM list %dprec 2 {
    $$ = new astOperatorRERemainder($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList AREM list");
}
| term lvalueStepList ABITAND list %dprec 2 {
    $$ = new astOperatorREBitAnd($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ABITAND list");
}
| term lvalueStepList ABITXOR list %dprec 2 {
    $$ = new astOperatorREBitXor($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ABITXOR list");
}
| term lvalueStepList ABITOR list %dprec 2 {
    $$ = new astOperatorREBitOr($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ABITOR list");
}
| term lvalueStepList ALSHIFT list %dprec 2 {
    $$ = new astOperatorRELShift($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ALSHIFT list");
}
| term lvalueStepList ARSHIFT list %dprec 2 {
    $$ = new astOperatorRERShift($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ARSHIFT list");
}
| term lvalueStepList ALOGAND list %dprec 2 {
    $$ = new astLogRESCAnd($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ALOGAND list");
}
| term lvalueStepList ALOGANDEXT list %dprec 2 {
    $$ = new astSCRichAccessAndExt<astRichEdit<E_RA_SHORTCIRCUIT>>($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ALOGANDEXT list");
}
| term lvalueStepList ALOGXOR list %dprec 2 {
    $$ = new astLogREXor($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ALOGXOR list");
}
| term lvalueStepList ALOGOR list %dprec 2 {
    $$ = new astLogRESCOr($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ALOGOR list");
}
| term lvalueStepList ALOGOREXT list %dprec 2 {
    $$ = new astSCRichAccessOrExt<astRichEdit<E_RA_SHORTCIRCUIT>>($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ALOGOREXT list");
}
| term lvalueStepList ANTHOP list %dprec 2 {
    $$ = new astRichAccessNthOp<astRichEdit<E_RA_STANDARD>>($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ANTHOP list");
}
| term lvalueStepList ACONCAT list %dprec 2 {
    $$ = new astRichAccessConcatOp<astRichEdit<E_RA_STANDARD>>($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ACONCAT list");
}
| term lvalueStepList ARCONCAT list %dprec 2 {
    $$ = new astRichAccessRConcatOp<astRichEdit<E_RA_STANDARD>>($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList ARCONCAT list");
}
| term lvalueStepList AAPPLY funcall %dprec 2 {
    $4->addOopStyleArg(new astConst(params->owner));
    $$ = new astRichAccessApplyOp<astRichEdit<E_RA_SHORTCIRCUIT>>($1, $4, $2, params->owner);
    code_dev_post("parse: var lvalueStepList AAPPLY list");
}
;

term: LONG_LITERAL {
    $$ = new astConst($1, params->owner);
    code_dev_post("parse: INT %ld", $1);
}
| RAT_LITERAL {
    $$ = new astConst($1, params->owner);
    code_dev_post("parse: RAT_LITERAL %ld/%ld", $1.num(), $1.den());
}
| DOUBLE_LITERAL {
    $$ = new astConst($1, params->owner);
    code_dev_post("parse: DOUBLE_LITERAL %lf", $1);
}
| PITCH_LITERAL {
    $$ = new astConst($1, params->owner);
    code_dev_post("parse: PITCH_LITERAL %s", $1.toSym()->s_name);
}
| SYMBOL_LITERAL {
    $$ = new astConst($1, params->owner);
    code_dev_post("parse: SYMBOL_LITERAL %s", $1->s_name);
}
| BACHNULL {
    $$ = new astConst(llll_get(), params->owner);
    code_dev_post("parse: NULL");
}
| ARGCOUNT {
    auto fnConst = new astConst((*(params->bifs))["$argcount"], params->owner);
    $$ = new astFunctionCall(fnConst, nullptr, nullptr, params->owner);
    code_dev_post("parse: ARGCOUNT");
}
| BACHNIL {
    t_llll *ll = llll_get();
    llll_appendllll(ll, llll_get());
    $$ = new astConst(ll, params->owner);
    code_dev_post("parse: NIL");
}
| INLET {
    if (params->dataInlets && params->fnDepth == 0 && $1 > *(params->dataInlets))
        *(params->dataInlets) = $1;
    $$ = new astInlet($1, params->owner);
    code_dev_post ("parse: INLET %ld", $1);
}
| INTINLET {
    if (params->dataInlets && params->fnDepth == 0 && $1 > *(params->dataInlets))
    *(params->dataInlets) = $1;
    $$ = new astConvInlet<hatom_fn_int>($1, params->owner);
    code_dev_post ("parse: INTINLET %ld", $1);
}
| RATINLET {
    if (params->dataInlets && params->fnDepth == 0 && $1 > *(params->dataInlets))
    *(params->dataInlets) = $1;
    $$ = new astConvInlet<hatom_fn_rat>($1, params->owner);
    code_dev_post ("parse: RATINLET %ld", $1);
}
| FLOATINLET {
    if (params->dataInlets && params->fnDepth == 0 && $1 > *(params->dataInlets))
    *(params->dataInlets) = $1;
    $$ = new astConvInlet<hatom_fn_float>($1, params->owner);
    code_dev_post ("parse: FLOATINLET %ld", $1);
}
| PITCHINLET {
    if (params->dataInlets && params->fnDepth == 0 && $1 > *(params->dataInlets))
    *(params->dataInlets) = $1;
    $$ = new astConvInlet<hatom_fn_pitch>($1, params->owner);
    code_dev_post ("parse: PITCHINLET %ld", $1);
}
| DIRINLET {
    if (params->directInlets && $1 > *(params->directInlets))
        *(params->directInlets) = $1;
    auto fnConst = new astConst((*(params->ofTable))["directin"], params->owner);
    auto numConst = new astConst($1, params->owner);
    auto tempList = new countedList<astNode *>(numConst);
    $$ = new astFunctionCall(fnConst, tempList, nullptr, params->owner);
    code_dev_post("parse: DIRINLET");
}
| OPEN sequence CLOSEDROUND {
    $$ = $2;
    code_dev_post ("parse: []\n");
}
| OPEN CLOSEDROUND {
    $$ = new astConst(llll_get(), params->owner);
}
| PUSH sequence POP {
    $$ = new astWrap($2, params->owner);
    code_dev_post("parse: []\n");
}
| PUSH POP {
    t_llll *ll = llll_get();
    llll_appendllll(ll, llll_get());
    $$ = new astConst(ll, params->owner);
    code_dev_post("parse: PushPop");
}
| BIF {
    t_function *fn = (*(params->bifs))[$1->s_name];
    $$ = new astConst(fn, params->owner);
    code_dev_post("parse: bif %s", $1->s_name);
}
| OF {
    t_function *fn = (*(params->ofTable))[$1->s_name];
    $$ = new astConst(fn, params->owner);
    code_dev_post("parse: owned function %s", $1->s_name);
}
| var
| functionApplication
;

var: globalVar
| localVar
| patcherVar
;

globalVar: GLOBALVAR {
    astGlobalVar *v = new astGlobalVar(params->gvt, $1, params->owner);
    params->globalVariables->insert(v->getVar());
    $$ = v;
    code_dev_post ("parse: Global variable %s", $1->s_name);
}
;

patcherVar: PATCHERVAR {
    astPatcherVar *v = new astPatcherVar($1, params->owner);
    (*params->name2patcherVars)[$1].insert(v);
    $$ = v;
    code_dev_post ("parse: Patcher variable %s", $1->s_name);
}
;

localVar: LOCALVAR {
    $$ = new astLocalVar($1, params->owner);
    addVariableToScope(params, $1);
    code_dev_post ("parse: Local variable %s", $1->s_name);
}
| KEEP LOCALVAR {
    $$ = new astKeep($2, params->owner);
    addVariableToScope(params, $2);
    code_dev_post ("parse: Keep local variable %s", $2->s_name);
}
| UNKEEP LOCALVAR {
    $$ = new astUnkeep($2, params->owner);
    addVariableToScope(params, $2);
    code_dev_post ("parse: Unkeep local variable %s", $2->s_name);
}
;



%%

t_mainFunction *codableobj_parse_buffer(t_codableobj *x, long *codeac, t_atom_long *dataInlets, t_atom_long *dataOutlets, t_atom_long *directInlets, t_atom_long *directOutlets)
{
    yyscan_t myscanner;
    
    t_lexparams lexparams;
    
    stringparser_lex_init_extra(&lexparams, &myscanner);
    stringparser_scan_string(myscanner, x->c_text);
    
    t_parseParams params;
    params.ast = NULL;
    params.fnDepth = 0;
    params.localVariablesStack = params.localVariablesStackBase;
    params.localVariablesAuxMapStack = params.localVariablesAuxMapStackBase;
    params.localVariablesAuxMapStack[0] = new std::unordered_map<t_symbol *, int>;
    params.liftedVariablesStack = params.liftedVariablesStackBase;
    params.implicitArgumentsStack = params.implicitArgumentsStackBase;
    params.gvt = bach->b_gvt;
    params.bifs = bach->b_bifTable;
    params.codeac = codeac;
    *params.codeac = 0;
    params.dataInlets = dataInlets;
    params.dataOutlets = dataOutlets;
    params.directInlets = directInlets;
    params.directOutlets = directOutlets;
    params.owner = x;
    params.ofTable = x->c_ofTable;
    params.name2patcherVars = new pvMap;
    params.globalVariables = new std::unordered_set<t_globalVariable*>;
    
    code_dev_post("--- BUILDING AST!\n");
    stringparser_parse(myscanner, &params);
    
    for (int i = 0; i < 256; i++) {
        if (params.localVariablesAuxMapStack[i] == nullptr)
            break;
        delete params.localVariablesAuxMapStack[i];
    }
    
    stringparser_lex_destroy(myscanner);
    
    code_dev_post("first attribute at %ld", *params.codeac);
    
    if (params.ast) {
        t_mainFunction *mainFunction = new t_mainFunction(
            params.ast,
            params.localVariablesStackBase[0],
            params.globalVariables,
            params.name2patcherVars,
            x
        );
        codableobj_clear_included_filewatchers(x);
        codableobj_add_included_filewatchers(x, &lexparams.files);
        return mainFunction;
    } else {
        object_error((t_object *) x, "Syntax errors present — couldn't parse code");
        return nullptr;
    }
}


