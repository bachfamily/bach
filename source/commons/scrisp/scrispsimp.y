%{
    
    
	//#define BACH_MAX
	#ifdef BACH_MAX
    #include "llllobj.h"
    #include "ext_common.h"
    #include "ext_globalsymbol.h"
    #else
    #include <stdio.h>
    #define post printf
    #endif
    
    #include "scrispast.h"

    int yylex(void);
    int yyerror(t_astNode **ast, t_globalVarTable *gvt, long *maxvars, char *s);
    void scan_string(char *buf);
    void delete_buffer(void);
%}

%union {
    struct _astNode *n;
    int i;
    double d;
    t_symbol *sym;
    char *str;
    method bif;
}

%token <i> INT INLET
%token <d> DOUBLE
%token <sym> SYMBOL
%token <str> GLOBALVAR
%token <bif> BIF1
%token SEQ
%token IF THEN ELSE
%token ASSIGN
%token PLUS MINUS TIMES DIV
%token LOGOR LOGAND LOGOREXT LOGANDEXT
%token EQUAL LT GT LEQ GEQ NEQ
%token OPEN CLOSED
%token PUSH POP
%token STARTPARAMS ENDPARAMS
%token BACHNULL BACHNIL
%token EOL

%left LOGOR LOGOREXT
%left LOGAND LOGANDEXT
%left EQUAL LT GT LEQ GEQ NEQ
%left PLUS MINUS
%left TIMES DIV
%left IF THEN
%left ELSE
%right UPLUS UMINUS

%type <n> var term list assignment sequence program

%parse-param {t_astNode **ast}
%parse-param {t_globalVarTable *gvt}
%parse-param {long *maxvars}

%debug

%%

program: sequence {
    *ast = $1;
    post ("parse: program\n");
 }
 ;

sequence: assignment
 | sequence SEQ assignment {
    $$ = astNode3_new(eSeq, $1, $3, NULL);
    post("parse: seq\n");
 }
 ;

assignment: list
 | var ASSIGN assignment {
    $$ = astNode3_new(eAssign, $1, $3, NULL);
    post("parse: Assignment");
 }
 ;

list: term
 | list term {
    $$ = astNode3_new(eConcat, $1, $2, NULL);
    post("parse: cat\n");
 }
 ;

term: INT {
    t_llll *ll = llll_get();
    llll_appendlong(ll, $1);
    $$ = astNodeK_new(ll);
    post("parse: INT %ld", $1);
 }
 | DOUBLE {
     t_llll *ll = llll_get();
     llll_appenddouble(ll, $1);
     $$ = astNodeK_new(ll);
     post("parse: DOUBLE %lf", $1);
 }
 | SYMBOL {
     t_llll *ll = llll_get();
     llll_appendsym(ll, $1);
     $$ = astNodeK_new(ll);
     post("parse: SYMBOL %s", $1->s_name);
 }
 | BACHNULL {
     $$ = astNodeK_new(llll_get());
     post("parse: NULL");
 }
 | var
 | BACHNIL {
     t_llll *ll = llll_get();
     llll_appendllll(ll, llll_get());
     $$ = astNodeK_new(ll);
     post("parse: NIL");
 }
 | INLET {
     $$ = astNodeInlet_new($1);
     if ($1 > *maxvars)
        *maxvars = $1;
     post ("parse: INLET %ld", $1);
 }
 | UPLUS term {
     $$ = $2;
     post("parse: U+\n");
 }
 | UMINUS term {
     $$ = astNode3_new(eUMinus, $2, NULL, NULL);
     post("parse: U-\n");
 }
 | term PLUS term {
     $$ = astNode3_new(ePlus, $1, $3, NULL);
     post ("parse: +\n");
 }
 | term MINUS term {
     $$ = astNode3_new(eMinus, $1, $3, NULL);
     post ("parse: *\n");
 }
 | term TIMES term {
     $$ = astNode3_new(eTimes, $1, $3, NULL);
     post ("parse: -\n");
 }
 | term DIV term {
     $$ = astNode3_new(eDiv, $1, $3, NULL);
     post ("parse: /\n");
 }
 | term EQUAL term {
     $$ = astNode3_new(eEqual, $1, $3, NULL);
     post ("parse: ==\n");
 }
 | term NEQ term {
     $$ = astNode3_new(eNeq, $1, $3, NULL);
     post ("parse: !=\n");
 }
 | term LT term {
     $$ = astNode3_new(eLt, $1, $3, NULL);
     post ("parse: <\n");
 }
 | term GT term {
     $$ = astNode3_new(eGt, $1, $3, NULL);
     post ("parse: <\n");
 }
 | term LEQ term {
     $$ = astNode3_new(eLeq, $1, $3, NULL);
     post ("parse: <=\n");
 }
 | term GEQ term {
    $$ = astNode3_new(eGeq, $1, $3, NULL);
    post ("parse: >=\n");
 }
 | term LOGOR term {
     $$ = astNode3_new(eLogOr, $1, $3, NULL);
     post ("parse: ||\n");
 }
 | term LOGAND term {
     $$ = astNode3_new(eLogAnd, $1, $3, NULL);
     post ("parse: &&/\n");
 }
 | term LOGOREXT term {
    $$ = astNode3_new(eLogOrExtended, $1, $3, NULL);
    post ("parse: |||/\n");
 }
 | term LOGANDEXT term {
    $$ = astNode3_new(eLogAndExtended, $1, $3, NULL);
    post ("parse: &&&/\n");
 }
 | IF sequence THEN term {
     $$ = astNode3_new(eIfThenElse, $2, $4, NULL);
     post ("parse: if then\n");
 }
 | IF sequence THEN term ELSE term {
     $$ = astNode3_new(eIfThenElse, $2, $4, $6);
     post ("parse: if then else\n");
 }
 | OPEN sequence CLOSED {
     $$ = $2;
     post ("parse: []\n");
 }
 | PUSH sequence POP {
     $$ = astNode3_new(eWrap, $2, NULL, NULL);
     post("parse: ()\n");
 }
 | PUSH POP {
     t_llll *ll = llll_get();
     llll_appendllll(ll, llll_get());
     $$ = astNodeK_new(ll);
     post("parse: PushPop");
 }
 | BIF1 STARTPARAMS sequence ENDPARAMS {
     $$ = astNodeBif1_new($1, $3);
     post("parse: bif1\n");
 }
 ;

var: GLOBALVAR {
    $$ = astNodeGVar_new(gvt, $1);
    post ("parse: Global variable %s", $1);
}

%%

t_astNode *bisonparse(char *buf, t_globalVarTable *gvt, long *maxvars)
{
    t_astNode *ast = NULL;
 	scan_string(buf);
    post("--- BUILDING AST!\n");
    yyparse(&ast, gvt, maxvars);
    delete_buffer();
    return ast;
}

#ifndef BACH_MAX
int main(int argc, char **argv)
{
	int result = bisonparse("(1+2*3)*(4+5) ");

	printf("result: %d\n", result);
	return 0;
}
#endif

int yyerror(t_astNode **ast, t_globalVarTable *gvt, long *maxvars, char *s)
{
	printf("error: %s\n", s);
	return 0;
}
