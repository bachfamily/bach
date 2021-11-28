%glr-parser
%{
    #include <stdio.h>
    #include <stdlib.h>

    typedef struct {
        int v[100];
        int n;
    } intarray;

    intarray* intarray_new() {
        return calloc(1, sizeof(intarray));
    }

    void intarray_print(intarray* a, char term) {
        int i;
        printf("( ");
        for (i = 0; i < a->n; i++) {
            printf("%d ", a->v[i]);
        }
        printf(") ");

        if (term) {
            printf("\n");
        }
    }

    intarray* intarray_chain(intarray* a1, intarray* a2) {
        intarray_print(a1, 0);
        intarray_print(a2, 0);
        printf(" = ");
        intarray* r = a1;
        int i;
        for (i = a1->n; i < a1->n + a2->n; i++) {
            a1->v[i] = a2->v[i - a1->n];
        }
        a1->n = i;
        intarray_print(a1, 1);
        free(a2);
        return r;
    }

    intarray* intarray_copy(intarray* from, intarray* to) {
        if (!to) {
            to = intarray_new();
        }
        to->n = from->n;
        for (int i = 0; i < from->n; i++) {
            to->v[i] = from->v[i];
        }
        return to;
    }

    int istrue(intarray* a) {
        return a->n != 0 && (a->n > 1 || a->v[0] != 0);
    }

    intarray vartable[26];

%}

%union {
    int i;
    intarray *a;
}

%token <i> NUMBER
%token <i> VAR
%token OPEN
%token CLOSED
%token NTH
%token TIMES
%token PLUS
%token NULLIFY
%token EOL
%token ASSIGN
%token IF THEN 

%nonassoc IFX
%nonassoc ELSE

%type <a> program item rvalue product sum simpleexpr chain sequence block 
%type <a> nullified assignment nullifiable ifthenelse ifthen conditional

%%

program: /* */
| program block EOL { 
    printf("result = ");
    intarray_print($2, 1);
    printf("end\n");
    free($1);
}
;

assignment: VAR ASSIGN chain {
    intarray_copy($3, vartable + $1);
    $$ = $3;
}
| VAR ASSIGN assignment {
    intarray_copy($3, vartable + $1);
    $$ = $3;
}
;

item: NUMBER {
    $$ = intarray_new();
    $$->n = 1;
    $$->v[0] = $1;
}
| OPEN block CLOSED {
    $$ = $2;
}
| VAR {
    $$ = intarray_copy(&vartable[$1], NULL);
}
; // produces evaluation

rvalue: item
;

product: rvalue
| product TIMES rvalue { 
    int i;
    $$ = intarray_new();
    $$->n = $1->n < $3->n ? $1->n : $3->n;
    for (i = 0; i < $$->n; i++) {
        $$->v[i] = $1->v[i] * $3->v[i];
    }
    intarray_print($1, 0);
    printf(" * ");
    intarray_print($3, 0);
    printf(" = ");
    intarray_print($$, 1);
    free($1);
    free($3);
}
;

sum: product
| sum PLUS product { 
    int i;
    $$ = intarray_new();
    $$->n = $1->n < $3->n ? $1->n : $3->n;
    for (i = 0; i < $$->n; i++) {
        $$->v[i] = $1->v[i] + $3->v[i];
    }
    intarray_print($1, 0);
    printf(" + ");
    intarray_print($3, 0);
    printf(" = ");
    intarray_print($$, 1);
    free($1);
    free($3);
}
;

simpleexpr: sum
;

chain: simpleexpr
| chain simpleexpr {
    printf("chain ");
    $$ = intarray_chain($1, $2);
}
;

ifthen: IF block THEN nullifiable {
    printf("if ");
    intarray_print($2, 0);
    printf("then ");
    intarray_print($4, 1);  
    if (istrue($2)) {
        free($2);
        $$ = $4;
    } else {
        free($4);
        free($2);
        $$ = intarray_new();
    }
}
;

ifthenelse: IF block THEN block ELSE nullifiable {
    printf("if ");
    intarray_print($2, 0);
    printf("then ");
    intarray_print($4, 0);
    printf("else ");
    intarray_print($6, 1);

    if (istrue($2)) {
        free($6);
        free($2);
        $$ = $4;
    } else {
        free($4);
        free($2);
        $$ = $6;
    }
}
;

conditional: ifthen %dprec 2
| ifthenelse %dprec 1
;

nullifiable: chain
| assignment
| conditional
;

nullified: nullifiable NULLIFY {
    printf("-----NULLIFY!\n");
    $$ = $1;
    $1->n = 0;
}
;

sequence: nullified
| sequence nullified {
    printf("sequence ");
    $$ = intarray_chain($1, $2);
}
;

block: sequence
| nullifiable
| sequence nullifiable {
    printf("block ");
    $$ = intarray_chain($1, $2);
}
;

%%

int main(int argc, char **argv)
{
    yyparse();
    return 0;
}

int yyerror(char *s)
{
    fprintf(stderr, "error: %s\n", s);
    return 0;
}
