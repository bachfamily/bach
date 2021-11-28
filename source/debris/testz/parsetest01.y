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
%}

%union {
    int i;
    intarray *a;
}

%token <i> NUMBER
%token OPEN
%token CLOSED
%token NTH
%token TIMES
%token PLUS
%token NULLIFY
%token EOL


%type <a> program item rvalue product sum simpleexpr chain clause

%%

program: /* */
| program clause EOL { 
    printf("result = ");
    intarray_print($2, 1);
    printf("end\n");
    free($1);
}
;

item: NUMBER {
    $$ = intarray_new();
    $$->n = 1;
    $$->v[0] = $1;
}
| clause
| OPEN clause CLOSED {
    $$ = $2;
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
    intarray_print($1, 0);
    intarray_print($2, 0);
    printf(" = ");
    $$ = $1;
    int i;
    for (i = $1->n; i < $1->n + $2->n; i++) {
        $1->v[i] = $2->v[i - $1->n];
    }
    $1->n = i;
    intarray_print($1, 1);
    free($2);
}
;

clause: chain
| chain NULLIFY {
    printf("-----NULLIFY!\n");
    $$ = $1;
    $1->n = 0;
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
