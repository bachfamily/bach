%{
 typedef struct {
        int v[100];
        int n;
    } intarray;

#include "parsetest02.tab.h"


%}

%%

[0-9]+ { yylval.i = atoi(yytext); printf("---parsed %d\n", yylval.i); return NUMBER; }

"if" { return IF; }

"then" { return THEN; }

"else" { return ELSE; }

[a-z] { yylval.i = yytext[0] - 'a'; return VAR; }

"(" { return OPEN; }

")" { return CLOSED; }

":" { return NTH; }

"+" { return PLUS; }

"*" { return TIMES; }

";" { return NULLIFY; }

"=" { return ASSIGN; }


"\n" { return EOL; }

[ \t] { }

. { }

%%
