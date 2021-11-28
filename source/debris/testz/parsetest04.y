%glr-parser
%{
    #include <stdio.h>
    #include <stdlib.h>

    typedef struct {
        int v[1000];
        int n;
    } intarray;

    typedef struct {
        intarray* a;
        int pos;
    } reference;

    reference* reference_new(intarray* a, int pos) {
        reference* r = malloc(sizeof(intarray));
        r->pos = pos;
        r->a = a;
        return r;
    }

    intarray* intarray_new(void) {
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

    intarray* intarray_fromreference(reference* r) {
        intarray* res;
        if (r->pos < 0) {
            res = intarray_copy(r->a, NULL);
        } else {
            res = intarray_new();
            res->v[0] = r->a->v[r->pos];
            res->n = 1;
        }
        free(r);
        return res;
    }

    int istrue(intarray* a) {
        return a->n != 0 && (a->n > 1 || a->v[0] != 0);
    }

    intarray vartable[26];

%}

%union {
    int i;
    intarray *a;
    reference *r;
}

%token <i> NUMBER
%token <i> VAR
%token OPEN
%token CLOSED
%token NTH
%left TIMES
%token PLUS
%token NULLIFY
%token EOL
%token ASSIGN
%nonassoc IF THEN
%nonassoc ELSE

%type <a> program item value rvalue product sum simpleexpr chain
%type <a> sequence_ifthen sequence_other
%type <a> block_ifthen block_other block
%type <a> nullified_ifthen nullified_other
%type <a> nullifiable_other nullifiable
%type <a> assignment ifthenelse ifthen
%type <r> lvalue fakelvalue

%%

program: /* */
| program ifthen EOL {
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
| OPEN ifthen CLOSED {
    $$ = $2;
}
; // produces evaluation

value: item
;


rvalue: item
;

product: rvalue
| product TIMES ifthen {
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

ifthen: product
| IF ifthen THEN ifthen {
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
