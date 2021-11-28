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
%token TIMES
%token PLUS
%token NULLIFY
%token EOL
%right ASSIGN
%nonassoc IF THEN
%nonassoc ELSE

%type <a> program item value rvalue product sum simpleexpr chain
%type <a> sequence_ifthen sequence_nonifthen
%type <a> block_ifthen block_nonifthen block
%type <a> nullified_ifthen nullified_nonifthen
%type <a> nullifiable_nonifthen nullifiable
%type <a> assignment ifthenelse ifthen
%type <a> conditional
%type <a> sequence_end
%type <a> chainBricks
%type <r> lvalue fakelvalue lvalueBricks fakelvalueBricks

%%

program: /* */
| program block EOL {
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
| OPEN block CLOSED {
    $$ = $2;
}
; // produces evaluation


conditional: ifthen
| ifthenelse
;

lvalueBricks: VAR {
    printf("var %c\n", $1 + 'a');
    $$ = reference_new(vartable + $1, -1);
}
| lvalueBricks NTH item {
    printf("   : %d ", $3->v[0]);
    if ($1->pos < 0)
        $1->pos = ($3->v[0]) - 1;
    else
        $1->pos += $3->v[0];
    printf("  pos changed to %d\n", $1->pos);
    $$ = $1;
}
| lvalueBricks NTH VAR {
    printf("   : %d ", $3->a->v[0]);
    if ($1->pos < 0)
        $1->pos = ($3->a->v[0]) - 1;
    else
        $1->pos += $3->a->v[0];
    printf("  pos changed to %d\n", $1->pos);
    $$ = $1;
}
;

lvalue: lvalueBricks
| lvalueBricks conditional {
    printf("   : %d ", $2->v[0]);
    if ($1->pos < 0)
        $1->pos = ($2->v[0]) - 1;
    else
        $1->pos += $2->v[0];
    printf("  pos changed to %d\n", $1->pos);
    $$ = $1;
}
;



assignment: lvalue ASSIGN chain { // lvalue can be a simple variable
    if ($1->pos < 0) {
        intarray_copy($3, $1->a);
        $$ = $3;
    } else {
        int pos = $1->pos;
        $1->a->v[pos] = ($3->v)[0];
        if ($1->a->n <= pos) {
            $1->a->n = pos;
        }
        $$ = intarray_copy($1->a, NULL);
    }
}
;




rvalue: item
| lvalue {
    $$ = intarray_fromreference($1);
}
| conditional
| assignment
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


chainBricks: sum
| chainBricks sum {
    printf("chain ");
    $$ = intarray_chain($1, $2);
}
;

chain: chainBricks
| chainBricks assignment {
    $$ = intarray_chain($1, $2);
}
| chainBricks conditional {
  $$ = intarray_chain($1, $2);
}
;



ifthenelse: IF block THEN block_nonifthen ELSE chain {
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

ifthen: IF block THEN chain {
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



block: block_ifthen
| block_nonifthen
;

block_ifthen: sequence_ifthen
| ifthen
| sequence_nonifthen ifthen {
    printf("block ");
    $$ = intarray_chain($1, $2);
}
| sequence_ifthen ifthen {
    printf("block ");
    $$ = intarray_chain($1, $2);
}
;

block_nonifthen: sequence_nonifthen
| nullifiable_nonifthen
| sequence_nonifthen nullifiable_nonifthen {
  printf("block-nonif ");
  $$ = intarray_chain($1, $2);
}
| sequence_ifthen nullifiable_nonifthen {
  printf("block-nonif ");
  $$ = intarray_chain($1, $2);
}
;




nullifiable: nullifiable_nonifthen
| ifthen
;

nullifiable_nonifthen: chain
| assignment
| ifthenelse
;



nullified_ifthen: ifthen NULLIFY {
    printf("-----NULLIFY!\n");
    $$ = $1;
    $1->n = 0;
}
| nullified_ifthen NULLIFY
;

nullified_nonifthen: nullifiable_nonifthen NULLIFY {
    printf("-----NULLIFY!\n");
    $$ = $1;
    $1->n = 0;
}
| nullified_nonifthen NULLIFY
;



sequence_ifthen: nullified_ifthen
| sequence_ifthen nullified_ifthen {
    printf("sequence_ifthen ");
    $$ = intarray_chain($1, $2);
}
| sequence_nonifthen nullified_ifthen {
    printf("sequence_ifthen ");
    $$ = intarray_chain($1, $2);
}
;

sequence_nonifthen: nullified_nonifthen
| sequence_nonifthen nullified_nonifthen
| sequence_ifthen nullified_nonifthen
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
