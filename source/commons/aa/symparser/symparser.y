%define api.pure full
%name-prefix "symparser_"

%token <l> BACH_LONG
%token <d> BACH_DOUBLE
%token <r> BACH_RAT
%token <p> BACH_PITCH
%token <sym> BACH_SYMBOL
%token BACH_PUSH BACH_POP
%token BACH_NULL BACH_NIL

%debug

%{
	//#define BACH_MAX
	#ifdef BACH_MAX
    #include "symparser.h"
    #else
    #include <stdio.h>
    #define parserpost printf
    #endif
    
    #define YYSTACK_USE_ALLOCA 1

%}

%union {
	long l;
	double d;
	t_rational r;
	t_pitch p;
	t_symbol *sym;
}


%{
    #include "bach_symparser_tab.h"
    #include "bach_symparser_lex.h"

    int yylex(YYSTYPE *yylval_param, yyscan_t myscanner);
    int yyerror(yyscan_t myscanner, t_llll **ll, t_llll_stack *stack, long *depth, char *s);
    YY_BUFFER_STATE symparser_scan_string(yyscan_t myscanner, char *buf);
    void symparser_flush_and_delete_buffer(yyscan_t myscanner, YY_BUFFER_STATE bp);
%}


%lex-param {void *scanner}
%parse-param {void *scanner}

%parse-param {t_llll **ll}
%parse-param {t_llll_stack *stack}
%parse-param {long *depth}

%%

sequence: 
| sequence term
;

term: BACH_LONG {
	llll_appendlong(*ll, $1);
	parserpost("parse: BACH_LONG %ld", $1);
} | BACH_DOUBLE {
	llll_appenddouble(*ll, $1);
	parserpost("parse: BACH_DOUBLE %lf", $1);
} | BACH_RAT {
	llll_appendrat(*ll, $1);
	parserpost("parse: BACH_RAT %ld/%ld", $1.num(), $1.den());
} | BACH_PITCH {
	llll_appendpitch(*ll, $1);
	parserpost("parse: degree: %c%d+%d/%d", 
		t_BACH_PITCH::degree2name[$1.degree()], $1.octave(), $1.alter().num(), $1.alter().den());
} | BACH_SYMBOL {
	llll_appendsym(*ll, $1);
	parserpost("parse: BACH_SYMBOL %s", $1->s_name);
} | BACH_NULL {
    parserpost("parse: NULL");
} | BACH_NIL {
	llll_appendllll(*ll, llll_get());
    parserpost("parse: NIL");
} | BACH_PUSH {
	(*depth)++;
	t_llll *newll = llll_get();
	llll_appendllll(*ll, newll, 0, WHITENULL_llll);
	llll_stack_push(stack, *ll);
	*ll = newll;
	parserpost("parse: BACH_PUSH");
} | BACH_POP {
	(*depth)--;
	if (*depth > 0) {
		t_llll *parent = (t_llll *) llll_stack_pop(stack);
		if (parent->l_depth <= (*ll)->l_depth)
			parent->l_depth = 1 + (*ll)->l_depth;
		*ll = parent;
	} else
		YYERROR;
	parserpost("parse: BACH_POPPE");
}
 
%%

void t_symParser::parse(char *buf, t_llll **ll, t_llll_stack *stack, long *depth)
{
    YY_BUFFER_STATE bp;
 	bp = symparser_scan_string((yyscan_t) this, buf);
    symparser_parse((yyscan_t) this, ll, stack, depth);
    symparser_flush_and_delete_buffer((yyscan_t) this, bp);
    reset();
}

#ifndef BACH_MAX
int main(int argc, char **argv)
{
	int result = scrisp_parse("(1+2*3)*(4+5) ");

	printf("result: %d\n", result);
	return 0;
}
#endif

int yyerror(void *dummy, t_llll **ll, t_llll_stack *stack, long *depth, char *s)
{
	parserpost("error: %s\n", s);
	return 0;
}
