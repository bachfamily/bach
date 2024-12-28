%{
    /*
     *  bisonparserV3.y
     *
     * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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
%name-prefix "bisonparserV3_"

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
    #include "bellparser_commons.h"

    extern t_bach *bach;


    %}

%union {
    astNode *astNodeValue;
    astFunctionCall *astFunctionCallValue;
    astLocalVar *astLocalVarValue;
    astPatcherVar *astPatcherVarValue;
    astGlobalVar *astGlobalVarValue;
    astVar *astVarValue;

    std::vector<funArg*> *funArgVector;
    std::vector<forArg*> *forArgVector;
    std::vector<t_localVar*> *localVarVector;
    std::vector<astNode*> *astNodeVector;
    std::vector<symNodePair*> *symNodePairVector;
    std::vector<int8_t> *int8Vector;
    
    lvalueStepList *lvalueStepListValue;
    symNodePair *symNodePairValue;
    forArg *forArgValue;
    funArg *funArgValue;
    lvalue *lvalueValue;
    fakeLvalue *fakeLvalueValue;
    lvalueSpecs *lvalueSpecsValue;
    
    long longValue;
    t_rational ratValue;
    double doubleValue;
    t_pitch pitchValue;
    t_symbol *symValue;
    char *textValue;
}

%token <longValue> LONG_LITERAL INLET INTINLET RATINLET FLOATINLET PITCHINLET OUTLET DIRINLET DIROUTLET JIPITCHBASE_START JIPITCHBASE_END
%token <ratValue> RAT_LITERAL
%token <doubleValue> DOUBLE_LITERAL
%token <pitchValue> PITCH_LITERAL
%token <symValue> SYMBOL_LITERAL GLOBALVAR PATCHERVAR LOCALVAR NAMEDPARAM BIF OF
%token <textValue> MAXFUNCTION
%token NULLIFY
%token IF_KW THEN_KW ELSE_KW
%token WHILE_KW DO_KW FOR_KW IN_KW COLLECT_KW
%token ASSIGN
%token PLUS MINUS TIMES DIV DIVDIV
%token APLUS
%token LOGOR LOGAND LOGOREXT LOGANDEXT
%token EQUAL LT GT LEQ GEQ NEQ
%token OPEN CLOSEDROUND
%token FUNDEF EMPTYFUNARGLIST
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
%left R T
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


%type <astNodeValue> program fundef list sequence nullified whileloop forloop itemOrVar lvalueSpecsItemForNth lvalueSpecsItemForDot dataflowHead lvalueSpecsUFinal lvalueSpecsFinal fakeLvalueHead assignment expr item conditional listEnd jiPitchBase
%type <astVarValue> var
%type <astFunctionCallValue> funcall simpleFuncall dataflowFuncall
%type <funArgValue> funarg
%type <funArgVector> funargList
%type <forArgVector> forargList
%type <localVarVector> liftedargList
%type <forArgValue> forarg
%type <symNodePairVector> argsByNameList
%type <astNodeVector> argsByPositionList listVector nullifiedSequence
%type <int8Vector> commaVector
%type <symNodePairValue> argByName
%type <longValue> sign
%type <astLocalVarValue> localVar
%type <astGlobalVarValue> globalVar
%type <astPatcherVarValue> patcherVar
%type <lvalueValue> lvalue
%type <fakeLvalueValue> fakeLvalue
%type <lvalueSpecsValue> lvalueSpecsNonFinalized lvalueSpecs


%{
    #include "bisonparserV3_tab_nolines.h"
    
    #define YY_HEADER_EXPORT_START_CONDITIONS
    #define YY_NO_UNISTD_H
    
    #include "bisonparserV3_lex_nolines.h"
    

    
    int yylex(YYSTYPE *yylval_param, yyscan_t myscanner, struct _parseParams
    *params);
    
    int yyerror(yyscan_t myscanner,
    t_parseParams *params,
    const char *s);
    
    
    YY_BUFFER_STATE bisonparserV3_scan_string(yyscan_t myscanner, const char *buf);
    void bisonparserV3_flush_and_delete_buffer(yyscan_t myscanner, YY_BUFFER_STATE bp);


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

    
// return astNode*
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


// returns funArg*
funarg: LOCALVAR {
    $$ = new funArg($1);
}
| LOCALVAR ASSIGN {
    *++(params->localVariablesStackV) = new std::vector<t_localVar>;
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
} list {
    $$ = new funArg($1, $4, *(params->localVariablesStackV));
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->localVariablesStackV);
    *(params->localVariablesStackV--) = nullptr;
}
| ELLIPSIS {
    $$ = new funArg(gensym("<...>"));
}
;




// returns std::vector<funArg*>*
funargList: {
    *++(params->localVariablesStackV) = new std::vector<t_localVar>;
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
} funarg {
    auto v = new std::vector<funArg*>;
    v->push_back($2);
    $$ = v;
}
| funargList COMMA funarg {
    $1->push_back($3);
    $$ = $1;
}
;


// returns std::vector<t_localVar*>
liftedargList : LIFT LOCALVAR {
    auto v = new std::vector<t_localVar*>;
    auto l = new t_localVar($2);
    v->push_back(l);
    $$ = v;
    code_dev_post ("parse: liftedargList (first term)\n");
}
| liftedargList COMMA LOCALVAR {
    auto l = new t_localVar($3);
    $1->push_back(l);
    $$ = $1;
    code_dev_post ("parse: liftedargList (subsequent term)\n");
}
;


// returns astNode*
fundef : funargList FUNDEF {
    params->fnDepth++;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    *++(params->argumentsStackV) = $1;
} list {
    t_function *fn = new t_userFunction(*(params->argumentsStackV), *(params->localVariablesStackV), $4, params->owner);
    params->funcs->insert(fn);
    $$ = new astConst(fn, params->owner);
    *(params->localVariablesStackV--) = nullptr;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->argumentsStackV);
    code_dev_post ("parse: user defined function funargList FUNDEF");
}
| EMPTYFUNARGLIST FUNDEF {
    ++(params->localVariablesStackV);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    params->fnDepth++;
    *++(params->argumentsStackV) = nullptr;
} list {
    t_function *fn = new t_userFunction(*(params->argumentsStackV), *(params->localVariablesStackV), $4, params->owner);
    params->funcs->insert(fn);
    $$ = new astConst(fn, params->owner);
    *(params->localVariablesStackV--) = nullptr;;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->argumentsStackV);
    code_dev_post ("parse: user defined function FUNDEF");
}
| funargList liftedargList FUNDEF {
    params->fnDepth++;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    for (auto v : *$2) {
        (*(params->liftedVariablesStack))->insert(v->getName());
    }
    *++(params->argumentsStackV) = $1;
} list {
    t_function *fn = new t_userFunction(*(params->argumentsStackV), *(params->localVariablesStackV), $5, params->owner);
    params->funcs->insert(fn);
    $$ = new astConst(fn, params->owner);
    *(params->localVariablesStackV--) = nullptr;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->argumentsStackV);
    code_dev_post ("parse: user defined function funargList liftedargList");
}
| EMPTYFUNARGLIST liftedargList FUNDEF {
    params->fnDepth++;
    ++(params->localVariablesStackV);
    *++(params->localVariablesAuxMapStack) = new std::unordered_map<t_symbol *, int>;
    *++(params->liftedVariablesStack) = new std::unordered_set<t_symbol *>;
    *++(params->argumentsStackV) = nullptr;
    for (auto v : *$2) {
        (*(params->liftedVariablesStack))->insert(v->getName());
    }
} list {
    t_function *fn = new t_userFunction(*++(params->argumentsStackV), *(params->localVariablesStackV), $5, params->owner);
    params->funcs->insert(fn);
    $$ = new astConst(fn, params->owner);
    *(params->localVariablesStackV--) = nullptr;;
    --(params->fnDepth);
    delete *(params->localVariablesAuxMapStack);
    *(params->localVariablesAuxMapStack--) = nullptr;
    delete *(params->liftedVariablesStack);
    *(params->liftedVariablesStack--) = nullptr;
    --(params->argumentsStackV);
    code_dev_post ("parse: user defined function liftedargList FUNDEF");
}
;


// returns std::vector<astNode*>*
listVector: expr %prec CONCAT {
    auto v = new std::vector<astNode*>;
    v->push_back($1);
    $$ = v;
} 
| listVector expr %prec CONCAT {
    $1->push_back($2);
    $$ = $1;
}
;


// returns astNode*
list: listVector {
    if ($1->size() == 1) {
        $$ = (*$1)[0];
        delete $1;
    } else {
        $$ = new astConcat($1, params->owner);
    }
}
| listEnd {
    
}
| listVector listEnd {
    $1->push_back($2);
    $$ = new astConcat($1, params->owner);
}
;

// returns astNode*
sequence: 
list
| nullifiedSequence {
    $$ = new astConcat($1, params->owner);
}
| nullifiedSequence list {
    $1->push_back($2);
    $$ = new astConcat($1, params->owner);
}
;


// returns astNode*
nullified: list NULLIFY {
    $$ = new astNullify($1, params->owner);
}
| nullified NULLIFY
;


// returns std::vector<astNode*>*
nullifiedSequence: nullified {
    auto v = new std::vector<astNode*>;
    v->push_back($1);
    $$ = v;
}
| nullifiedSequence nullified {
    $1->push_back($2);
    $$ = $1;
}
;


// returns astNode*
whileloop : WHILE_KW sequence DO_KW list {
    $$ = new astWhileLoop<E_LOOP_DO>($2, $4, params->owner);
    code_dev_post ("parse: while...do\n");
}
| WHILE_KW sequence COLLECT_KW list {
    $$ = new astWhileLoop<E_LOOP_COLLECT>($2, $4, params->owner);
    code_dev_post ("parse: while...collect\n");
}
;


// returns forArg*
forarg : LOCALVAR IN_KW sequence {
    $$ = new forArg($1, nullptr, $3);
    addVariableToScope<e_flexBisonV3>(params, $1);
    code_dev_post ("parse: for iterator with index");
}
| LOCALVAR LOCALVAR IN_KW sequence {
    addVariableToScope<e_flexBisonV3>(params, $1);
    addVariableToScope<e_flexBisonV3>(params, $2);
    $$ = new forArg($1, $2, $4);
    code_dev_post ("parse: for iterator with index and address");
}
;


// returns std::vector<forArg*>*
forargList : forarg {
    auto v = new std::vector<forArg*>;
    v->push_back($1);
    $$ = v;
    code_dev_post ("parse: for iterator (first term)\n");
}
| forargList COMMA forarg {
    $1->push_back($3);
    $$ = $1;
    code_dev_post ("parse: for iterator (subsequent term)\n");
}
;


// returns astNode*
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


// returns std::vector<astNode*>*
argsByPositionList : sequence {
    auto v = new std::vector<astNode*>;
    v->push_back($1);
    $$ = v;
    code_dev_post ("parse: argsByPositionList (first term)\n");
} %dprec 1
| argsByPositionList COMMA sequence {
    $1->push_back($3);
    $$ = $1;
    code_dev_post ("parse: argsByPositionList (subsequent term)\n");
} %dprec 2
;


// returns std::vector<symNodePair*>*
argsByNameList: argByName {
    auto v = new std::vector<symNodePair*>;
    v->push_back($1);
    $$ = v;code_dev_post ("parse: argsByNameList (first term)\n");
}
| argsByNameList COMMA argByName {
    $1->push_back($3);
    $$ = $1;
    code_dev_post ("parse: argsByNameList (subsequent term)\n");
}
| argsByNameList argByName {
    $1->push_back($2);
    $$ = $1;
    code_dev_post ("parse: argsByNameList (subsequent term)\n");
}
;


// returns symNodePair*
argByName : NAMEDPARAM sequence {
    $$ = new symNodePair($1, $2);
    code_dev_post ("parse: named parameter %s", $1->s_name);
}
;


// returns astNode*
itemOrVar : item
| var
;


// returns simpleFuncall*
simpleFuncall : itemOrVar STARTPARAMS CLOSEDROUND {
    $$ = new astFunctionCall($1, (std::vector<astNode*>*) nullptr, (std::vector<symNodePair*>*) nullptr, params->owner);
}
| itemOrVar STARTPARAMS argsByPositionList CLOSEDROUND {
    $$ = new astFunctionCall($1, $3, nullptr, params->owner);
}
| itemOrVar STARTPARAMS argsByNameList CLOSEDROUND {
    $$ = new astFunctionCall($1, nullptr, $3, params->owner);
}
| itemOrVar STARTPARAMS argsByPositionList COMMA argsByNameList CLOSEDROUND {
    $$ = new astFunctionCall($1, $3, $5, params->owner);
}
| itemOrVar STARTPARAMS argsByPositionList argsByNameList CLOSEDROUND {
    $$ = new astFunctionCall($1, $3, $4, params->owner);
}
| simpleFuncall STARTPARAMS CLOSEDROUND {
    $$ = new astFunctionCall($1, (std::vector<astNode*>*) nullptr, (std::vector<symNodePair*>*) nullptr, params->owner);
}
| simpleFuncall STARTPARAMS argsByPositionList CLOSEDROUND {
    $$ = new astFunctionCall($1, $3, nullptr, params->owner);
}
| simpleFuncall STARTPARAMS argsByNameList CLOSEDROUND {
    $$ = new astFunctionCall($1, nullptr, $3, params->owner);
}
| simpleFuncall STARTPARAMS argsByPositionList COMMA argsByNameList CLOSEDROUND {
    $$ = new astFunctionCall($1, $3, $5, params->owner);
}
| simpleFuncall STARTPARAMS argsByPositionList  argsByNameList CLOSEDROUND {
    $$ = new astFunctionCall($1, $3, $4, params->owner);
}
;


// returns long (1 / -1)
sign : UPLUS {
    $$ = 1;
} 
| UMINUS {
    $$ = -1;
}
| sign UPLUS {
    $$ = $1;
}
| sign UMINUS {
    $$ = -$1;
}
;


// returns astNode*
lvalueSpecsItemForDot : itemOrVar
| sign itemOrVar {
    if ($1 == -1) {
        $$ = new astOperatorUMinus($2, params->owner);
    } else {
        $$ = $2;
    }
}
;

// returns astNode*
lvalueSpecsItemForNth : lvalueSpecsItemForDot
| simpleFuncall
| sign simpleFuncall {
    if ($1 == -1) {
        $$ = new astOperatorUMinus($2, params->owner);
    } else {
        $$ = $2;
    }
}
;

// returns astNode*
dataflowHead : item
| simpleFuncall
| lvalue {
    astNode* n = $1->getVar();
    auto s = $1->getSpecs();
    if (s)
        n = s->toReadNode(n, params->owner);
    $$ = n;
}
| fakeLvalue {
    auto n = $1->getNode();
    auto s = $1->getSpecs();
    $$ = s->toReadNode(n, params->owner);
}
;


// returns astFunctionCall*
dataflowFuncall :
dataflowHead APPLY simpleFuncall {
    $3->addDataflowStyleArg($1);
    $$ = $3;
}
| dataflowFuncall APPLY simpleFuncall {
    $3->addDataflowStyleArg($1);
    $$ = $3;
}
;


// returns astFunctionCall*
funcall:
simpleFuncall
| dataflowFuncall
;


// returns astVar*
var: globalVar
| localVar
| patcherVar
;


// returns astLocalVar*
localVar: LOCALVAR {
    $$ = new astLocalVar($1, params->owner);
    addVariableToScope<e_flexBisonV3>(params, $1);
    code_dev_post ("parse: Local variable %s", $1->s_name);
}
| KEEP LOCALVAR {
    $$ = new astKeep($2, params->owner);
    addVariableToScope<e_flexBisonV3>(params, $2);
    code_dev_post ("parse: Keep local variable %s", $2->s_name);
}
| UNKEEP LOCALVAR {
    $$ = new astUnkeep($2, params->owner);
    addVariableToScope<e_flexBisonV3>(params, $2);
    code_dev_post ("parse: Unkeep local variable %s", $2->s_name);
}
;


// returns astNode*
globalVar: GLOBALVAR {
    astGlobalVar *v = new astGlobalVar(params->gvt, $1, params->owner);
    params->globalVariables->insert(v->getVar());
    $$ = v;
    code_dev_post ("parse: Global variable %s", $1->s_name);
}
;


// returns astNode*
patcherVar: PATCHERVAR {
    astPatcherVar *v = new astPatcherVar($1, params->owner);
    (*params->name2patcherVars)[$1].insert(v);
    $$ = v;
    code_dev_post ("parse: Patcher variable %s", $1->s_name);
}
;


// returns astNode*
lvalueSpecsUFinal :
conditional
| whileloop
| forloop
| fundef
//| funcall
;


// returns astNode*
lvalueSpecsFinal : lvalueSpecsUFinal
| sign lvalueSpecsUFinal {
    if ($1 == -1) {
        $$ = new astOperatorUMinus($2, params->owner);
    } else {
        $$ = $2;
    }
}
;


// returns lvalue*
lvalue: 
var {
    $$ = new lvalue($1, nullptr);
}
| var lvalueSpecs {
    $$ = new lvalue($1, $2);
}
;


// returns astNode*
fakeLvalueHead:
item
| funcall
;


// returns fakeLvalue*
fakeLvalue:
fakeLvalueHead lvalueSpecs {
    $$ = new fakeLvalue($1, $2);
}
;


// returns lvalueSpecs*
lvalueSpecsNonFinalized:
NTHOP lvalueSpecsItemForNth {
    auto s = new lvalueSpecs;
    auto step = new lvalueStep(lvalueStep::E_LV_NTH, $2);
    s->addStep(step);
    $$ = s;
}
| lvalueSpecs NTHOP lvalueSpecsItemForNth {
    auto step = new lvalueStep(lvalueStep::E_LV_NTH, $3);
    $1->addStep(step);
    $$ = $1;
}
| APPLY lvalueSpecsItemForDot {
    auto s = new lvalueSpecs;
    auto step = new lvalueStep(lvalueStep::E_LV_KEY, $2);
    s->addStep(step);
    $$ = s;
}
| lvalueSpecs APPLY lvalueSpecsItemForDot {
    auto step = new lvalueStep(lvalueStep::E_LV_KEY, $3);
    $1->addStep(step);
    $$ = $1;
}
;


// returns lvalueSpecs*
lvalueSpecs:
NTHOP lvalueSpecsFinal {
    auto s = new lvalueSpecs;
    auto step = new lvalueStep(lvalueStep::E_LV_NTH, $2);
    s->addStep(step);
    $$ = s;
}
| lvalueSpecsNonFinalized NTHOP lvalueSpecsFinal {
    auto step = new lvalueStep(lvalueStep::E_LV_NTH, $3);
    $1->addStep(step);
    $$ = $1;
}
| APPLY lvalueSpecsFinal {
    auto s = new lvalueSpecs;
    auto step = new lvalueStep(lvalueStep::E_LV_KEY, $2);
    s->addStep(step);
    $$ = s;
}
| lvalueSpecsNonFinalized APPLY lvalueSpecsFinal {
    auto step = new lvalueStep(lvalueStep::E_LV_KEY, $3);
    $1->addStep(step);
    $$ = $1;
}
| lvalueSpecsNonFinalized
;


// returns astNode*
listEnd: assignment %dprec 2
| whileloop
| forloop
| conditional
| fundef %dprec 1
;

// returns astNode*
expr :
item
| funcall
| lvalue {
    astNode* n = $1->getVar();
    auto s = $1->getSpecs();
    if (s)
        n = s->toReadNode(n, params->owner);
    $$ = n;
}
| fakeLvalue {
    auto n = $1->getNode();
    auto s = $1->getSpecs();
    $$ = s->toReadNode(n, params->owner);
}/*
| sign expr {
    if ($1 == -1)
        $$ = new astOperatorUMinus($2, params->owner);
    else
        $$ = $2;
    code_dev_post("parse: U-\n");
}*/
| UMINUS expr {
    $$ = new astOperatorUMinus($2, params->owner);
}
| UPLUS expr {
    $$ = $2;
}
| expr R {
    $$ = new astOperatorR($1, params->owner);
}
| expr T {
    $$ = new astOperatorT($1, params->owner);
}
| LOGNOT expr {
    $$ = new astLogNot($2, params->owner);
    code_dev_post("parse: !\n");
}
| BITNOT expr {
    $$ = new astOperatorBitNot($2, params->owner);
    code_dev_post("parse: ~\n");
}
| expr PLUS expr {
    $$ = new astOperatorPlus($1, $3, params->owner);
    code_dev_post ("parse: +\n");
}
| expr MINUS expr {
    $$ = new astOperatorMinus($1, $3, params->owner);
    code_dev_post ("parse: -\n");
}
| expr TIMES expr {
    $$ = new astOperatorTimes($1, $3, params->owner);
    code_dev_post ("parse: *\n");
}
| expr DIV expr {
    $$ = new astOperatorDiv($1, $3, params->owner);
    code_dev_post ("parse: /\n");
}
| expr DIVDIV expr {
    $$ = new astOperatorDivdiv($1, $3, params->owner);
    code_dev_post ("parse: //\n");
}
| expr REM expr {
    $$ = new astOperatorRemainder($1, $3, params->owner);
    code_dev_post ("parse: %\n");
}
| expr POWOP expr {
    $$ = new astOperatorPow($1, $3, params->owner);
    code_dev_post ("parse: **\n");
}
| expr BITAND expr {
    $$ = new astOperatorBitAnd($1, $3, params->owner);
    code_dev_post ("parse: &\n");
}
| expr BITXOR expr {
    $$ = new astOperatorBitXor($1, $3, params->owner);
    code_dev_post ("parse: ^\n");
}
| expr BITOR expr {
    $$ = new astOperatorBitOr($1, $3, params->owner);
    code_dev_post ("parse: |\n");
}
| expr LSHIFT expr {
    $$ = new astOperatorBitOr($1, $3, params->owner);
    code_dev_post ("parse: <<\n");
}
| expr RSHIFT expr {
    $$ = new astOperatorBitOr($1, $3, params->owner);
    code_dev_post ("parse: >>\n");
}
| expr EQUAL expr {
    $$ = new astComparatorEq($1, $3, params->owner);
    code_dev_post ("parse: ==\n");
}
| expr NEQ expr {
    $$ = new astComparatorNeq($1, $3, params->owner);
    code_dev_post ("parse: !=\n");
}
| expr LT expr {
    $$ = new astComparatorLt($1, $3, params->owner);
    code_dev_post ("parse: <\n");
}
| expr GT expr {
    $$ = new astComparatorGt($1, $3, params->owner);
    code_dev_post ("parse: <\n");
}
| expr LEQ expr {
    $$ = new astComparatorLeq($1, $3, params->owner);
    code_dev_post ("parse: <=\n");
}
| expr GEQ expr {
    $$ = new astComparatorGeq($1, $3, params->owner);
    code_dev_post ("parse: >=\n");
}
| expr LOGOR expr {
    $$ = new astSCOr($1, $3, params->owner);
    code_dev_post ("parse: ||\n");
}
| expr LOGAND expr {
    $$ = new astSCAnd($1, $3, params->owner);
    code_dev_post ("parse: &&\n");
}
| expr LOGXOR expr {
    $$ = new astLogXor($1, $3, params->owner);
    code_dev_post ("parse: &&\n");
}
| expr LOGOREXT expr {
    $$ = new astSCOrExt($1, $3, params->owner);
    code_dev_post ("parse: |||\n");
}
| expr LOGANDEXT expr {
    $$ = new astSCAndExt($1, $3, params->owner);
    code_dev_post ("parse: &&&\n");
}
| expr PICKOP expr {
    $$ = new astPickOp($1, $3, params->owner);
    code_dev_post ("parse: nthop\n");
}
| expr RANGE expr {
    $$ = new astRangeOp($1, $3, params->owner);
    code_dev_post ("parse: range\n");
}
| expr REPEAT expr {
    $$ = new astRepeatOp($1, $3, params->owner);
    code_dev_post ("parse: range\n");
}
| sign listEnd {
    if ($1 == -1)
        $$ = new astOperatorUMinus($2, params->owner);
    else
        $$ = $2;
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
| expr PLUS listEnd {
    $$ = new astOperatorPlus($1, $3, params->owner);
    code_dev_post ("parse: +\n");
}
| expr MINUS listEnd {
    $$ = new astOperatorMinus($1, $3, params->owner);
    code_dev_post ("parse: -\n");
}
| expr TIMES listEnd {
    $$ = new astOperatorTimes($1, $3, params->owner);
    code_dev_post ("parse: *\n");
}
| expr DIV listEnd {
    $$ = new astOperatorDiv($1, $3, params->owner);
    code_dev_post ("parse: /\n");
}
| expr DIVDIV listEnd {
    $$ = new astOperatorDivdiv($1, $3, params->owner);
    code_dev_post ("parse: //\n");
}
| expr REM listEnd {
    $$ = new astOperatorRemainder($1, $3, params->owner);
    code_dev_post ("parse: %\n");
}
| expr POWOP listEnd {
    $$ = new astOperatorPow($1, $3, params->owner);
    code_dev_post ("parse: **\n");
}
| expr BITAND listEnd {
    $$ = new astOperatorBitAnd($1, $3, params->owner);
    code_dev_post ("parse: &\n");
}
| expr BITXOR listEnd {
    $$ = new astOperatorBitXor($1, $3, params->owner);
    code_dev_post ("parse: ^\n");
}
| expr BITOR listEnd {
    $$ = new astOperatorBitOr($1, $3, params->owner);
    code_dev_post ("parse: |\n");
}
| expr LSHIFT listEnd {
    $$ = new astOperatorBitOr($1, $3, params->owner);
    code_dev_post ("parse: <<\n");
}
| expr RSHIFT listEnd {
    $$ = new astOperatorBitOr($1, $3, params->owner);
    code_dev_post ("parse: >>\n");
}
| expr EQUAL listEnd {
    $$ = new astComparatorEq($1, $3, params->owner);
    code_dev_post ("parse: ==\n");
}
| expr NEQ listEnd {
    $$ = new astComparatorNeq($1, $3, params->owner);
    code_dev_post ("parse: !=\n");
}
| expr LT listEnd {
    $$ = new astComparatorLt($1, $3, params->owner);
    code_dev_post ("parse: <\n");
}
| expr GT listEnd {
    $$ = new astComparatorGt($1, $3, params->owner);
    code_dev_post ("parse: <\n");
}
| expr LEQ listEnd {
    $$ = new astComparatorLeq($1, $3, params->owner);
    code_dev_post ("parse: <=\n");
}
| expr GEQ listEnd {
    $$ = new astComparatorGeq($1, $3, params->owner);
    code_dev_post ("parse: >=\n");
}
| expr LOGOR listEnd {
    $$ = new astSCOr($1, $3, params->owner);
    code_dev_post ("parse: ||\n");
}
| expr LOGAND listEnd {
    $$ = new astSCAnd($1, $3, params->owner);
    code_dev_post ("parse: &&\n");
}
| expr LOGXOR listEnd {
    $$ = new astLogXor($1, $3, params->owner);
    code_dev_post ("parse: &&\n");
}
| expr LOGOREXT listEnd {
    $$ = new astSCOrExt($1, $3, params->owner);
    code_dev_post ("parse: |||\n");
}
| expr LOGANDEXT listEnd {
    $$ = new astSCAndExt($1, $3, params->owner);
    code_dev_post ("parse: &&&\n");
}
| expr PICKOP listEnd {
    $$ = new astPickOp($1, $3, params->owner);
    code_dev_post ("parse: nthop\n");
}
| expr RANGE listEnd {
    $$ = new astRangeOp($1, $3, params->owner);
    code_dev_post ("parse: range\n");
}
| expr REPEAT listEnd {
    $$ = new astRepeatOp($1, $3, params->owner);
    code_dev_post ("parse: range\n");
}
;

// returns std::vector<int8_t*>
commaVector:
LONG_LITERAL {
    auto v = new std::vector<int8_t>;
    v->push_back($1);
    $$ = v;
    code_dev_post ("parse: commaVector: LONG_LITERAL\n");
}
| sign LONG_LITERAL {
    auto v = new std::vector<int8_t>;
    v->push_back($1 * $2);
    $$ = v;
    code_dev_post ("parse: commaVector: sign LONG_LITERAL\n");
}
| commaVector NTHOP LONG_LITERAL {
    $1->push_back($3);
    $$ = $1;
    code_dev_post ("parse: commaVector NTHOP  LONG_LITERAL\n");

}
| commaVector NTHOP sign LONG_LITERAL {
    $1->push_back($3 * $4);
    $$ = $1;
    code_dev_post ("parse: commaVector NTHOP sign LONG_LITERAL\n");
}
;

// returns astConst*
jiPitchBase:
JIPITCHBASE_START commaVector JIPITCHBASE_END {
    $$ = new astConst(t_pitch($1, *$2, $3));
    delete $2;
    code_dev_post ("parse: jiPitchBase\n");
}
;


// returns astNode*
item:
LONG_LITERAL {
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
| jiPitchBase
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
    $$ = new astFunctionCall(fnConst, params->owner);
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
| MAXFUNCTION {
    t_function *fn = new t_maxFunction(std::string($1));
    params->funcs->insert(fn);
    $$ = new astConst(fn, params->owner);
    code_dev_post("parse: Max function %s", $1);
}
;


// returns astNode*
assignment:
INIT LOCALVAR ASSIGN list {
    addVariableToScope<e_flexBisonV3>(params, $2);
    $$ = new astInit($2, $4, params->owner);
    code_dev_post("parse: INIT LOCALVAR ASSIGN list");
}
| lvalue ASSIGN list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astAssign($1->getVar(), $3, params->owner);
    else
        $$ = new astRichAssignment<E_RA_STANDARD>($1->getVar(), $3, s, params->owner);
}
| lvalue APOWOP list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astOperatorAPow($1->getVar(), $3, params->owner);
    else
        $$ = new astOperatorRAPow($1->getVar(), $3, s, params->owner);
}
| lvalue ATIMES list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astOperatorATimes($1->getVar(), $3, params->owner);
    else
        $$ = new astOperatorRATimes($1->getVar(), $3, s, params->owner);
}
| lvalue ADIVDIV list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astOperatorADivdiv($1->getVar(), $3, params->owner);
    else
        $$ = new astOperatorRADivdiv($1->getVar(), $3, s, params->owner);
}
| lvalue ADIV list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astOperatorADiv($1->getVar(), $3, params->owner);
    else
        $$ = new astOperatorRADiv($1->getVar(), $3, s, params->owner);
}
| lvalue AREM list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astOperatorARemainder($1->getVar(), $3, params->owner);
    else
        $$ = new astOperatorRARemainder($1->getVar(), $3, s, params->owner);
}
| lvalue APLUS list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astOperatorAPlus($1->getVar(), $3, params->owner);
    else
        $$ = new astOperatorRAPlus($1->getVar(), $3, s, params->owner);
}
| lvalue AMINUS list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astOperatorAMinus($1->getVar(), $3, params->owner);
    else
        $$ = new astOperatorRAMinus($1->getVar(), $3, s, params->owner);
}
| lvalue ALOGAND list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astSCAAnd($1->getVar(), $3, params->owner);
    else
        $$ = new astLogRASCAnd($1->getVar(), $3, s, params->owner);
}
| lvalue ALOGANDEXT list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astSCAAndExt($1->getVar(), $3, params->owner);
    else
        $$ = new astLogRASCAndExt($1->getVar(), $3, s, params->owner);
}
| lvalue ALOGXOR list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astLogAXor($1->getVar(), $3, params->owner);
    else
        $$ = new astLogRAXor($1->getVar(), $3, s, params->owner);
}
| lvalue ALOGOR list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astSCAOr($1->getVar(), $3, params->owner);
    else
        $$ = new astLogRASCOr($1->getVar(), $3, s, params->owner);
}
| lvalue ALOGOREXT list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astSCAOrExt($1->getVar(), $3, params->owner);
    else
        $$ = new astLogRASCOrExt($1->getVar(), $3, s, params->owner);
}
| lvalue ABITAND list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astOperatorABitAnd($1->getVar(), $3, params->owner);
    else
        $$ = new astOperatorRABitAnd($1->getVar(), $3, s, params->owner);
}
| lvalue ABITXOR list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astOperatorABitXor($1->getVar(), $3, params->owner);
    else
        $$ = new astOperatorRABitXor($1->getVar(), $3, s, params->owner);
}
| lvalue ABITOR list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astOperatorABitOr($1->getVar(), $3, params->owner);
    else
        $$ = new astOperatorRABitOr($1->getVar(), $3, s, params->owner);
}
| lvalue ALSHIFT list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astOperatorALShift($1->getVar(), $3, params->owner);
    else
        $$ = new astOperatorRALShift($1->getVar(), $3, s, params->owner);
}
| lvalue ARSHIFT list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astOperatorARShift($1->getVar(), $3, params->owner);
    else
        $$ = new astOperatorRARShift($1->getVar(), $3, s, params->owner);
}
| lvalue ACONCAT list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astConcatAssignOp($1->getVar(), $3, params->owner);
    else
        $$ = new astRAConcat($1->getVar(), $3, s, params->owner);
}
| lvalue ARCONCAT list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astRevConcatAssignOp($1->getVar(), $3, params->owner);
    else
        $$ = new astRARConcat($1->getVar(), $3, s, params->owner);
}
| lvalue ANTHOP list {
    if (auto s = $1->getSpecs(); s == nullptr)
        $$ = new astNthAssignOp($1->getVar(), $3, params->owner);
    else
        $$ = nullptr;
}

| fakeLvalue ASSIGN list {
    $$ = new astRichEdit<E_RA_STANDARD>($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue APOWOP list {
    $$ = new astOperatorREPow($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue ATIMES list {
    $$ = new astOperatorRETimes($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue ADIVDIV list {
    $$ = new astOperatorREDivdiv($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue ADIV list {
    $$ = new astOperatorREDiv($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue AREM list {
    $$ = new astOperatorRERemainder($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue APLUS list {
    $$ = new astOperatorREPlus($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue AMINUS list {
    $$ = new astOperatorREMinus($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue ALOGAND list {
    $$ = new astLogRESCAnd($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue ALOGANDEXT list {
    $$ = new astLogRESCAndExt($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue ALOGXOR list {
    $$ = new astLogREXor($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue ALOGOR list {
    $$ = new astLogRESCOr($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue ALOGOREXT list {
    $$ = new astLogRESCOrExt($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue ABITAND list {
    $$ = new astOperatorREBitAnd($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue ABITXOR list {
    $$ = new astOperatorREBitXor($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue ABITOR list {
    $$ = new astOperatorREBitOr($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue ALSHIFT list {
    $$ = new astOperatorRELShift($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue ARSHIFT list {
    $$ = new astOperatorRERShift($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue ACONCAT list {
    $$ = new astREConcat($1->getNode(), $3, $1->getSpecs(), params->owner);
}
| fakeLvalue ARCONCAT list {
    $$ = new astRERConcat($1->getNode(), $3, $1->getSpecs(), params->owner);
}

| lvalue AAPPLY funcall {
    if (auto s = $1->getSpecs(); s == nullptr) {
        $3->addDataflowStyleArg($1->getVar());
        $$ = new astAssign($1->getVar(), $3, params->owner);
    } else {
        auto v = $1->getVar();
        $3->addDataflowStyleArg(new astConst(params->owner));
        $$ = new astRichAccessApplyOp<astRichAssignment<E_RA_SHORTCIRCUIT>>(v, $3, s, params->owner);
    }
    code_dev_post("parse: lvalue AAPPLY funcall");
}

| fakeLvalue AAPPLY funcall {
    auto n = $1->getNode();
    auto s = $1->getSpecs();
    $3->addDataflowStyleArg(new astConst(params->owner));
    $$ = new astRichAccessApplyOp<astRichEdit<E_RA_SHORTCIRCUIT>>(n, $3, s, params->owner);
    code_dev_post("parse: fakeLvalue AAPPLY funcall");
}

| OUTLET ASSIGN list {
    if (params->dataOutlets && $1 > *(params->dataOutlets))
        *(params->dataOutlets) = $1;
    auto fnConst = new astConst((*(params->bifs))["outlet"], params->owner);


    auto numConst = new astConst($1, params->owner);
    auto v = new std::vector<astNode*>;
    v->push_back(numConst);
    v->push_back($3);
    $$ = new astFunctionCall(fnConst, v, nullptr, params->owner);
    code_dev_post("parse: OUTLET ASSIGN list");
}

| DIROUTLET ASSIGN list {
    if (params->directOutlets && $1 > *(params->directOutlets))
        *(params->directOutlets) = $1;
    auto fnConst = new astConst((*(params->ofTable))["directout"], params->owner);
    auto v = new std::vector<astNode*>;
    v->push_back(new astConst($1, params->owner));
    v->push_back($3);
    $$ = new astFunctionCall(fnConst, v, nullptr, params->owner);
    code_dev_post("parse: DIROUTLET ASSIGN list");
}
;



// returns astNode*
conditional : IF_KW sequence THEN_KW list {
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



%%

t_mainFunction *codableobj_parse_buffer_v3(t_codableobj *x, long *codeac, t_atom_long *dataInlets, t_atom_long *dataOutlets, t_atom_long *directInlets, t_atom_long *directOutlets)
{
    yyscan_t myscanner;
    
    t_lexparams lexparams;
    
    bisonparserV3_lex_init_extra(&lexparams, &myscanner);
    bisonparserV3_scan_string(myscanner, x->c_text);
    
    t_parseParams params;
    params.ast = NULL;
    params.fnDepth = 0;
    params.localVariablesStack = params.localVariablesStackBase;
    params.localVariablesStackBase[0] = nullptr;
    params.localVariablesStackBaseV[0] = new std::vector<t_localVar>;
    params.localVariablesStackV = params.localVariablesStackBaseV;
    params.localVariablesAuxMapStack = params.localVariablesAuxMapStackBase;
    params.localVariablesAuxMapStack[0] = new std::unordered_map<t_symbol *, int>;
    params.liftedVariablesStack = params.liftedVariablesStackBase;
    params.argumentsStack = params.argumentsStackBase;
    params.argumentsStackBase[0] = nullptr;
    params.argumentsStackBaseV[0] = new std::vector<funArg*>;
    params.argumentsStackV = params.argumentsStackBaseV;
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
    params.funcs = new std::unordered_set<t_function*>;
    
    code_dev_post("--- BUILDING AST!\n");
    bisonparserV3_parse(myscanner, &params);
    
    for (int i = 0; i < 256; i++) {
        if (params.localVariablesAuxMapStack[i] == nullptr)
            break;
        delete params.localVariablesAuxMapStack[i];
    }
    
    bisonparserV3_lex_destroy(myscanner);
    
    code_dev_post("first attribute at %ld", *params.codeac);
    
    if (params.ast) {
        t_mainFunction *mainFunction = new t_mainFunction(
            params.ast,
            params.localVariablesStackBaseV[0],
            params.globalVariables,
            params.name2patcherVars,
            params.funcs,
            x
        );
        codableobj_clear_included_filewatchers(x);
        codableobj_add_included_filewatchers(x, &lexparams.files);
        return mainFunction;
    } else {
        object_error((t_object *) x, "Syntax errors present — couldn't parse code");
        delete params.name2patcherVars;
        delete params.globalVariables;
        for (t_function* f: *params.funcs)
            f->decrease();
        delete params.funcs;
        return nullptr;
    }
}


